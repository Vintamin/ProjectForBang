#include "vrmine\vr_scenecontrol\widget.h"
#include "OGRE\OgreVector3.h"
#include "vrmine\vr_mathenine\mathengine\mathcalculator.h"
#include "ogre/OgreFont.h"
#include "ogre/OgreFontManager.h"
#include "OGRE/OgrePanelOverlayElement.h"
#include "vrmine/vr_scenecontrol/geospatialcontrol.h"

using namespace VirtualMine::SpatialInterface;
using namespace Ogre;

#define  ElementSize 113

namespace VirtualMine
{
	namespace Scene
	{

		class CWidget_Private
		{
		public:
			CWidget_Private()
			{
				this->mName = "unamed";
				this->mMaterialName = "unamedMat";
				this->mPosition = Ogre::Vector3::ZERO;
				this->mSize = Ogre::Vector3::ZERO;
				this->mVisible = true;
				this->ref_mpParent = NULL;
			}

			~CWidget_Private()
			{
				if (this->mChildren.size() > 0)
				{
					for (int i =0 ;i < this->mChildren.size();++i)
					{
						IWidget* pWidget = this->mChildren[i];
						if (pWidget)
						{
							delete pWidget;
						}
					}
					this->mChildren.clear();
				}
			}

		public:
			std::string mName;
			std::string mMaterialName;
			Ogre::Vector3 mPosition;
			Ogre::Vector3 mSize;
			bool mVisible;
			IWidget* ref_mpParent;
			std::vector<IWidget*> mChildren;
			CGeoSpatialControl* ref_mpSceneControl;
		};

		CWidget::CWidget()
			:mpPrivate(new CWidget_Private())
		{
		
		}

		CWidget::CWidget(CGeoSpatialControl* ref_pSceneControl)
			:mpPrivate(new CWidget_Private())
		{
			this->mpPrivate->ref_mpSceneControl = ref_pSceneControl;
		}


		CWidget::~CWidget()
		{

		}

		std::string CWidget::getName()
		{
			return this->mpPrivate->mName;
		}

		void CWidget::setName(const std::string& name)
		{
			this->mpPrivate->mName = name;
		}

		Ogre::Vector3 CWidget::getPosition()
		{
			return this->mpPrivate->mPosition;
		}

		void CWidget::setPosition(const Ogre::Vector3& position)
		{
			this->mpPrivate->mPosition = position;
		}

		Ogre::Vector3 CWidget::getSize()
		{
			return this->mpPrivate->mSize;
		}

		void CWidget::setSize(const Ogre::Vector3& size)
		{
			this->mpPrivate->mSize = size;
		}
		std::string CWidget::getMaterialName()
		{
			return this->mpPrivate->mMaterialName;
		}
		void CWidget::setMaterialName(const std::string& materialName)
		{
			this->mpPrivate->mMaterialName = materialName;
		}
		bool CWidget::getVisible()
		{
			return this->mpPrivate->mVisible;
		}
		void CWidget::setVisible(const bool& value)
		{
			this->mpPrivate->mVisible = value;
		}
		IWidget* CWidget::getParentWidget()
		{
			return this->mpPrivate->ref_mpParent;
		}
		void CWidget::setParentWidget(IWidget* pParentWidget)
		{
			this->mpPrivate->ref_mpParent= pParentWidget;
		}
		std::vector<IWidget*>& CWidget::getChildWidget()
		{
			return this->mpPrivate->mChildren;
		}
		bool CWidget::addChildWidget(IWidget* pChildWidget)
		{
			this->mpPrivate->mChildren.push_back(pChildWidget);
			return true;
		}
		bool CWidget::removeChildWidget(IWidget* pChildWidget)
		{
			//需要实现
			return false;
		}
		void CWidget::initialise()
		{
			if (this->mpPrivate->mChildren.size() > 0)
			{
				for (size_t i = 0; i < this->mpPrivate->mChildren.size();++i)
				{
					this->mpPrivate->mChildren[i]->initialise();
				}
			}
		}
		void CWidget::draw()
		{
			if (this->mpPrivate->mChildren.size() > 0)
			{
				for (size_t i = 0; i < this->mpPrivate->mChildren.size();++i)
				{
					this->mpPrivate->mChildren[i]->draw();
				}
			}
		}
		void CWidget::notifyUpdate()
		{
			if (this->mpPrivate->mChildren.size() > 0)
			{
				for (size_t i = 0; i < this->mpPrivate->mChildren.size();++i)
				{
					this->mpPrivate->mChildren[i]->notifyUpdate();
				}
			}
		}

		bool CWidget::handleEvent(VirtualMine::Core::CEvent* evt)
		{
			bool r = false;
			if (this->mpPrivate->mChildren.size() > 0)
			{
				for (size_t i = 0; i < this->mpPrivate->mChildren.size();++i)
				{
					r |=this->mpPrivate->mChildren[i]->handleEvent(evt);
				}
			}
			return r;
		}

		CGeoSpatialControl* CWidget::getSceneControl()
		{
			return this->mpPrivate->ref_mpSceneControl;
		}

		class CCompassWidget_Private
		{
		public:
			CCompassWidget_Private()
			{
				mpCompassOverlay = NULL;
				mpCompass_silderOverlay = NULL;
				mpCompass_upOverlay = NULL;
				mpCompass_downOverlay = NULL;
				mpCompass_leftOverlay = NULL;
				mpCompass_rightOverlay = NULL;
				mpOutTextOverlay = NULL;
				mpOutTextElement = NULL;
				mpCompusOverlayElement = NULL;
				mpCompassTexUnit = NULL;
			}

			~CCompassWidget_Private()
			{

			}

		public:
			//////new ui
			Ogre::Overlay* mpCompassOverlay;
			Ogre::Overlay* mpCompass_silderOverlay;
			Ogre::Overlay* mpCompass_upOverlay;
			Ogre::Overlay* mpCompass_downOverlay;
			Ogre::Overlay* mpCompass_leftOverlay;
			Ogre::Overlay* mpCompass_rightOverlay;
			///输出框
			Ogre::Overlay* mpOutTextOverlay;
			Ogre::OverlayElement* mpOutTextElement;
			PanelOverlayElement* mpCompusOverlayElement;
			Ogre::TextureUnitState* mpCompassTexUnit;
		};

		CCompassWidget::CCompassWidget(CGeoSpatialControl* ref_pSceneControl)
			:CWidget(ref_pSceneControl),mpPrivate(new CCompassWidget_Private())
		{

		}

		CCompassWidget::~CCompassWidget()
		{

		}


		void CCompassWidget::initialise()
		{

			#pragma region 加载导航  
			Ogre::OverlayElement* compassPic =Ogre:: OverlayManager::getSingleton().createOverlayElement("Panel","compassPic");

			compassPic->setParameter("metrics_mode","pixels");
			compassPic->setParameter("left","32");
			compassPic->setParameter("top","19");
			compassPic->setParameter("width","69");
			compassPic->setParameter("height","258");
			compassPic->setMaterialName("compass");

			this->mpPrivate->mpCompassOverlay =Ogre::OverlayManager::getSingleton().create("Overlay");
			this->mpPrivate->mpCompassOverlay->add2D((Ogre::OverlayContainer*)compassPic);
			this->mpPrivate->mpCompassOverlay->show();

			Ogre::OverlayElement* compass_silderPic=Ogre::OverlayManager::getSingleton().createOverlayElement("Panel","compass_slider");
			compass_silderPic->setParameter("metrics_mode","pixels");
			//compass_silderPic->setLeft(this->mpRenderWindow->getWidth()-150);
			compass_silderPic->setParameter("left","56");
			compass_silderPic->setParameter("top","169");
			compass_silderPic->setParameter("width","22");
			compass_silderPic->setParameter("height","17");
			compass_silderPic->setMaterialName("compass_slider");

			this->mpPrivate->mpCompass_silderOverlay= Ogre::OverlayManager::getSingleton().create("compass_silderOverlay");
			this->mpPrivate->mpCompass_silderOverlay->add2D((Ogre::OverlayContainer*)compass_silderPic);
			this->mpPrivate->mpCompass_silderOverlay->show();

			#pragma endregion


			#pragma region 加载compass_up、down、left、right 并设置不显示

			//compass_up
			Ogre::OverlayElement* compass_up=Ogre::OverlayManager::getSingleton().createOverlayElement("Panel","compass_up");
			compass_up->setParameter("metrics_mode","pixels");
			compass_up->setParameter("left","61");
			compass_up->setParameter("top","38");
			compass_up->setParameter("width","14");
			compass_up->setParameter("height","14");
			compass_up->setMaterialName("compass_up");

			this->mpPrivate->mpCompass_upOverlay = Ogre::OverlayManager::getSingleton().create("compass_upOverlay");
			this->mpPrivate->mpCompass_upOverlay->add2D((Ogre::OverlayContainer*)compass_up);


			//compass_down
			Ogre::OverlayElement* compass_down=Ogre::OverlayManager::getSingleton().createOverlayElement("Panel","compass_down");
			compass_down->setParameter("metrics_mode","pixels");
			compass_down->setParameter("left","61");
			compass_down->setParameter("top","63");
			compass_down->setParameter("width","14");
			compass_down->setParameter("height","14");
			compass_down->setMaterialName("compass_down");

			this->mpPrivate->mpCompass_downOverlay = Ogre::OverlayManager::getSingleton().create("compass_downOverlay");
			this->mpPrivate->mpCompass_downOverlay->add2D((Ogre::OverlayContainer*)compass_down);


			//compass_left
			Ogre::OverlayElement* compass_left=Ogre::OverlayManager::getSingleton().createOverlayElement("Panel","compass_left");
			compass_left->setParameter("metrics_mode","pixels");
			compass_left->setParameter("left","47");
			compass_left->setParameter("top","50");
			compass_left->setParameter("width","14");
			compass_left->setParameter("height","14");
			compass_left->setMaterialName("compass_left");

			this->mpPrivate->mpCompass_leftOverlay = Ogre::OverlayManager::getSingleton().create("compass_leftOverlay");
			this->mpPrivate->mpCompass_leftOverlay->add2D((Ogre::OverlayContainer*)compass_left);


			//compass_right
			Ogre::OverlayElement* compass_right=Ogre::OverlayManager::getSingleton().createOverlayElement("Panel","compass_right");
			compass_right->setParameter("metrics_mode","pixels");
			compass_right->setParameter("left","71");
			compass_right->setParameter("top","50");
			compass_right->setParameter("width","14");
			compass_right->setParameter("height","14");
			compass_right->setMaterialName("compass_right");

			this->mpPrivate->mpCompass_rightOverlay = Ogre::OverlayManager::getSingleton().create("compass_rightOverlay");
			this->mpPrivate->mpCompass_rightOverlay->add2D((Ogre::OverlayContainer*)compass_right);



			//outText

			Ogre::FontManager::getSingleton().getByName("MyFont")->load();

			this->mpPrivate->mpOutTextElement = Ogre::OverlayManager::getSingleton().createOverlayElement("TextArea","outTxt");
			//outTextElement->setParameter("metrics_mode","pixels");
			this->mpPrivate->mpOutTextElement->setMetricsMode(Ogre::GuiMetricsMode::GMM_PIXELS);
			this->mpPrivate->mpOutTextElement->setDimensions(1.0, 1.0);

			this->mpPrivate->mpOutTextElement->setParameter("left","0.001");
			this->mpPrivate->mpOutTextElement->setParameter("top","560");

			this->mpPrivate->mpOutTextElement->setParameter("width","1500");
			this->mpPrivate->mpOutTextElement->setParameter("height","16");
			//outTextElement->setPosition(100,100);
			this->mpPrivate->mpOutTextElement->setParameter("font_name","MyFont");
			this->mpPrivate->mpOutTextElement->setParameter("char_height", "16");
			this->mpPrivate->mpOutTextElement->setParameter("horz_align", "left");

			//	outTextElement->setMaterialName("outTxt");

			//DisplayString str;
			//   str.append("X:  , Y:  , Z:  ");
			////outTextElement->setCaption("X:  ,Y:  ,Z:  ");
			//outTextElement->setCaption(str);
			this->mpPrivate->mpOutTextElement->setColour(Ogre::ColourValue(0.5,0,0));

			this->mpPrivate->mpOutTextOverlay = Ogre::OverlayManager::getSingleton().create("outTextOverlay");
			this->mpPrivate->mpOutTextOverlay->add2D((Ogre::OverlayContainer*)this->mpPrivate->mpOutTextElement);
			this->mpPrivate->mpOutTextOverlay->show();

			#pragma endregion

			std::string compusName("compusName");
			std::string compusElementName("compusElementName");

			Ogre::Overlay* compusOverlay = OverlayManager::getSingleton().create(compusName);
			this->mpPrivate->mpCompusOverlayElement = (PanelOverlayElement*)(OverlayManager::getSingleton().createOverlayElement("Panel",compusElementName));
			this->mpPrivate->mpCompusOverlayElement->setHeight(ElementSize);
			this->mpPrivate->mpCompusOverlayElement->setWidth(ElementSize);
			this->mpPrivate->mpCompusOverlayElement->setMetricsMode(GMM_PIXELS);

			this->mpPrivate->mpCompusOverlayElement->setTop(0);
			this->mpPrivate->mpCompusOverlayElement->setLeft(10);

			//this->mpPrivate->mpCompusOverlayElement->setMaterialName("compassMaterial.material");
			/*	this->mpPrivate->mpCompusOverlayElement->setTop(300);
			this->mpPrivate->mpCompusOverlayElement->setLeft(300);*/


			//this->mpPrivate->mpCompusOverlayElement->setPosition(300,300);
			//this->mpPrivate->mpCompusOverlayElement->setMetricsMode(GMM_RELATIVE);

			int  cx   =  GetSystemMetrics( SM_CXFULLSCREEN );
			int  cy   =  GetSystemMetrics( SM_CYFULLSCREEN );
			Ogre::Real lef = this->getSceneControl()->getRenderWindow()->getWidth();
			//this->mpPrivate->mpCompusOverlayElement->setLeft(0.5);
			//this->mpPrivate->mpCompusOverlayElement->setPosition(cx-150,cy -150);


			//this->mpPrivate->mpCompusOverlayElement->setParameter("horz_align", "left"); 

			if (this->getSceneControl()->getRenderWindow()->getWidth() > 200)
			{
				this->mpPrivate->mpCompusOverlayElement->setLeft(this->getSceneControl()->getRenderWindow()->getWidth() - 150);
			}
			this->mpPrivate->mpCompusOverlayElement->setCaption(Ogre::DisplayString("adb"));

			compusOverlay->add2D(this->mpPrivate->mpCompusOverlayElement);
			compusOverlay->show();

			//compusOverlay->


#if 1

			MaterialPtr matPtr = MaterialManager::getSingletonPtr()->create(compusElementName,Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
			Pass* pass = matPtr->getTechnique(0)->getPass(0);
			pass->setLightingEnabled(false);
			pass->setSceneBlending(SBT_TRANSPARENT_ALPHA);
			Ogre::String texName("compusTexture");

			Ogre::Image image;
			//image.load("mousepoint.png",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
			image.load("compus.png",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

			TexturePtr texPtr = TextureManager::getSingletonPtr()->create(texName,Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
			if (!texPtr.isNull())
			{
				texPtr->loadImage(image);
				this->mpPrivate->mpCompassTexUnit = pass->createTextureUnitState(texName,0);
				this->mpPrivate->mpCompassTexUnit->setTextureCoordSet(0);
				//pTexUnit->s

				//this->mpPrivate->mCameraDirection.y = 0;

				float anglefloat = 0;//VirtualMine::MathEngine::CMathCalculator::CalculateAngleOfTwoVector(this->mpPrivate->mCameraDirection,Ogre::Vector3(0,0,-1));

				//float anglefloat = this->mpPrivate->mCameraDirection.angleBetween(Ogre::Vector3::UNIT_Z).valueDegrees();

				this->mpPrivate->mpCompassTexUnit->setTextureRotate(Ogre::Radian(-anglefloat));

				this->mpPrivate->mpCompassTexUnit->setColourOperation(LBO_REPLACE);
				this->mpPrivate->mpCompassTexUnit->setTextureFiltering(FO_LINEAR,FO_LINEAR,FO_LINEAR);
				this->mpPrivate->mpCompusOverlayElement->setMaterialName(matPtr->getName());
				this->mpPrivate->mpCompusOverlayElement->setUV(0,0,1,1);
				this->mpPrivate->mpCompusOverlayElement->setHorizontalAlignment(GHA_LEFT);
				this->mpPrivate->mpCompusOverlayElement->setVerticalAlignment(GVA_TOP);
			}


#endif
		}

		bool CCompassWidget::handleEvent(VirtualMine::Core::CEvent* evt)
		{
			bool r = false;

			return r;
		}

		void CCompassWidget::mouseReleaseEvent(const int& x ,const int& y , const int& button)
		{
			
		}

		void CCompassWidget::mousePressEvent(const int& x ,const int& y , const int& button)
		{
			
		}
		
		void CCompassWidget::mouseDoubleClickEvent(const int& x ,const int& y , const int& button)
		{
			
		}

		void CCompassWidget::mouseMoveEvent(const int& x ,const int& y, const int& button)
		{

		}

	}
}