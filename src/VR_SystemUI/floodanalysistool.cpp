//
//#include "vrmine/vr_systemui/floodanalysistool.h"
//#include "vrmine/vr_core/geodatatype.h"
//
//using namespace VirtualMine::Scene;
//
//namespace VirtualMine
//{
//	namespace SystemUI
//	{
//		CFloodAnalysisTool::CFloodAnalysisTool()
//			:ref_mpGeoSpatialControl(NULL),mWaterColor(Ogre::ColourValue(0,0,0.7)),
//			mWaterHeight(-200),mUseFloodAnalysis(false),mShowWaterSurface(true),mUseFloatEffect(true)
//		{
//			this->mpWaterSurfaceObject = NULL;
//			mLanewayMaterialNames.push_back("laneway_default");
//			mLanewayMaterialNames.push_back("laneway_gongzigang");
//			mLanewayMaterialNames.push_back("laneway_hongzhuan");
//			mLanewayMaterialNames.push_back("laneway_liaoshi");
//			mLanewayMaterialNames.push_back("laneway_maopen");
//			mLanewayMaterialNames.push_back("laneway_penjiang");
//			this->mRefercencerY = 453;
//		}
//
//		bool CFloodAnalysisTool::getWaterSurfaceState()
//		{
//			//return this->mShowWaterSurface;
//			if (this->mpWaterSurfaceObject)
//			{
//				
//				if (this->mpWaterSurfaceObject->getRectFlood())
//				{
//					bool vis = this->mpWaterSurfaceObject->getVisible();
//					this->mShowWaterSurface = vis;
//					mpWaterSurfaceObject->setVisible(this->mShowWaterSurface);
//					return vis;
//				}
//				return false;
//				
//			}
//		}
//		void CFloodAnalysisTool::setWaterSurfaceState(const bool& showWaterSurface)
//		{
//			this->mShowWaterSurface = showWaterSurface;
//			if (this->mpWaterSurfaceObject)
//			{
//				
//				
//				this->mpWaterSurfaceObject->setVisible(mShowWaterSurface);
//			
//			}
//		}
//
//		VirtualMine::Arithmetic::CRectFlood_MeshCreator* CFloodAnalysisTool::getWaterSurface()
//		{
//			return this->mpWaterSurfaceObject;
//		}
//		bool CFloodAnalysisTool::getUseFloatEffect()
//		{
//			return this->mUseFloatEffect;
//		}
//		void CFloodAnalysisTool::setUseFloatEffect(const bool& useFloatEffect)
//		{
//			this->mUseFloatEffect = useFloatEffect;
//			Ogre::String matName("VRMine/WaterSurface");
//			Ogre::MaterialPtr waterSurfaceMaterial = ::Ogre::MaterialManager::getSingletonPtr()->getByName(matName,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
//			if (!waterSurfaceMaterial.isNull())
//			{
//				Ogre::TextureUnitState* pTexUnite = waterSurfaceMaterial->getTechnique(0)->getPass(0)->getTextureUnitState(0);
//				if (pTexUnite)
//				{
//					if (useFloatEffect)
//					{
//						pTexUnite->setScrollAnimation(0.05,0.05);
//					}
//					else
//					{
//						pTexUnite->setScrollAnimation(0,0);
//					}
//					
//					waterSurfaceMaterial->load();
//				}
//				
//			}
//		}
//		
//		CFloodAnalysisTool::~CFloodAnalysisTool()
//		{
//		
//		}
//
//		void CFloodAnalysisTool::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl)
//		{
//			this->ref_mpGeoSpatialControl= ref_pGeoSpatialControl;
//		}
//
//		void CFloodAnalysisTool::setWaterColor(const Ogre::ColourValue& color)
//		{
//			this->mWaterColor = color;
//			for (int i = 0; i < this->mLanewayMaterialNames.size();++i)
//			{
//				Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingletonPtr()->getByName(this->mLanewayMaterialNames.at(i),VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
//				if (!mat.isNull())
//				{
//					Ogre::GpuProgramParametersSharedPtr gpSp = mat->getTechnique(0)->getPass(0)->getFragmentProgramParameters();
//					gpSp->setNamedConstant("waterColor",color);
//					mat->load();
//				}
//			}
//			
//		}
//		   
//		void CFloodAnalysisTool::setLanewayCtl(const Ogre::Vector3& camPos)
//		{
//			for (int i = 0; i < this->mLanewayMaterialNames.size();++i)
//			{
//				Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingletonPtr()->getByName(this->mLanewayMaterialNames.at(i),VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
//				if (!mat.isNull())
//				{
//					Ogre::GpuProgramParametersSharedPtr gpSp = mat->getTechnique(0)->getPass(0)->getFragmentProgramParameters();
//					gpSp->setNamedConstant("camPos",camPos);
//					mat->load();
//				}
//			}
//		}
//
//		void CFloodAnalysisTool::createWaterSurface()
//		{
//			if (this->mpWaterSurfaceObject == NULL)
//			{
//
//				
//#if 0 plane
//				Ogre::Plane shadowPlane(Ogre::Vector3::UNIT_Y,0);
//				//Ogre::Plane plane()
//  
//				Ogre::MeshManager::getSingleton().createPlane("waterSurface",
//					VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP,shadowPlane,6000,3000,2,2,true,1,5,5,Ogre::Vector3::UNIT_Z);
//				
//				this->mpWaterSurfaceObject = this->ref_mpGeoSpatialControl->getGeoSceneManager()->createEntity("waterSurfaceEntity", "waterSurface");
//
//				//暂时绑定 空对象
//				VirtualMine::Core::CBaseObject* object = new VirtualMine::Core::CBaseObject();
//				Ogre::Any any((VirtualMine::Core::CBaseObject*)object);
//				this->mpWaterSurfaceObject->setUserAny(any);
//
//				Ogre::String matName("VRMine/WaterSurface");
//				this->mpWaterSurfaceObject->setMaterialName(matName,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
//				Ogre::MaterialPtr waterSurfaceMaterial = ::Ogre::MaterialManager::getSingletonPtr()->getByName(matName,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
//				if (!waterSurfaceMaterial->isLoaded())
//				{
//					waterSurfaceMaterial->getTechnique(0)->getPass(0)->setCullingMode(Ogre::CULL_NONE);
//					waterSurfaceMaterial->load();
//				}
//				this->mpWaterSurfaceObject->setCastShadows(false);
//				this->ref_mpGeoSpatialControl->getGeoSceneManager()->getRootSceneNode()->createChildSceneNode()->attachObject(this->mpWaterSurfaceObject);
//				this->mpWaterSurfaceObject->getParentNode()->setPosition(1000,this->mWaterHeight,0);
//
//
//#endif
//
//
//#if 1 rect
//
//				this->mpWaterSurfaceObject = new VirtualMine::Arithmetic::CRectFlood_MeshCreator();
//
//				this->mpWaterSurfaceObject->setSceneManager(this->ref_mpGeoSpatialControl->getGeoSceneManager());
//
//				Ogre::AxisAlignedBox box ;
//
//				if (this->ref_mpGeoSpatialControl)
//				{
//					if (this->ref_mpGeoSpatialControl->getScene())
//					{
//						if (this->ref_mpGeoSpatialControl->getScene()->getDemLayer())
//						{					
//							box = this->ref_mpGeoSpatialControl->getScene()->getDemLayer()->getBoundingBox();
//						}
//					}
//				
//				}
//			
//				Ogre::Vector3 minVec = box.getMinimum();
//				Ogre::Vector3 maxVec = box.getMaximum();
//
//				////水面下降n米
//				/*minVec.y = minVec.y - 200; 
//				maxVec.y = maxVec.y - 200;*/
//				minVec.y =  -200; 
//				maxVec.y =  -200;
//					
//				double heighty = -200;
//                minVec.y = heighty;
//				maxVec.y = heighty;
//
//
//				if (minVec == maxVec)
//				{
//					this->mpWaterSurfaceObject->createRect(Ogre::Vector3(100,100,100),Ogre::Vector3(200,100,300));
//					
//
//				}
//				else
//				{
//					this->mpWaterSurfaceObject->createRect(minVec,maxVec);
//				}
//
//				this->mpWaterSurfaceObject->attachRect();
//
//
//
//				this->mpWaterSurfaceObject->setRectHeight(heighty);
//
//				this->setWaterHeight(heighty);
//
//
//#endif
//
//
//
//			}
//		/*	bool visible = (this->mUseFloodAnalysis && this->mShowWaterSurface);
//			this->mpWaterSurfaceObject->setVisible(visible);*/
//
//			//this->mpWaterSurfaceObject->setVisible(true);
//		}
//
//		void CFloodAnalysisTool::setWaterHeight(const float& waterHeight)
//		{
//#if 0 
//			this->mWaterHeight = waterHeight;
//			for (int i = 0; i < this->mLanewayMaterialNames.size();++i)
//			{
//				Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingletonPtr()->getByName(this->mLanewayMaterialNames.at(i),VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
//				if (!mat.isNull())
//				{
//					Ogre::GpuProgramParametersSharedPtr gpSp = mat->getTechnique(0)->getPass(0)->getFragmentProgramParameters();
//
//					gpSp->setNamedConstant("waterHeight",this->mWaterHeight);
//						
//					gpSp->setNamedConstant("referenceY",this->mRefercencerY);
//				}
//			}
//			if (this->mpWaterSurfaceObject && this->mShowWaterSurface)
//			{
//				this->mpWaterSurfaceObject->setVisible(this->mShowWaterSurface);
//				this->mpWaterSurfaceObject->getParentNode()->setPosition(0,this->mWaterHeight,0);
//			}
//
//#endif
//
//#if 1
//			this->mRefercencerY = VirtualMine::SpatialInterface::IScene::ReferenceCenter.y;
//			this->mWaterHeight = waterHeight;
//			this->mpWaterSurfaceObject->setRectHeight(waterHeight);
//
//			for (int i = 0; i < this->mLanewayMaterialNames.size();++i)
//			{
//				Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingletonPtr()->getByName(this->mLanewayMaterialNames.at(i),VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
//				if (!mat.isNull())
//				{
//					Ogre::GpuProgramParametersSharedPtr gpSp = mat->getTechnique(0)->getPass(0)->getFragmentProgramParameters();
//
//					gpSp->setNamedConstant("waterHeight",this->mWaterHeight);
//
//					//gpSp->setNamedConstant("referenceY",this->mRefercencerY);
//				}
//			}
//			if (this->mpWaterSurfaceObject && this->mShowWaterSurface)
//			{
//				//this->mpWaterSurfaceObject->setVisible(this->mShowWaterSurface);
//				//this->mpWaterSurfaceObject->setVisible(true);
//				//this->mpWaterSurfaceObject->getParentNode()->setPosition(0,this->mWaterHeight,0);
//				if (this->mpWaterSurfaceObject->getRectNode())
//				{
//					//Ogre::Vector3 pos = this->mpWaterSurfaceObject->getRectNode()->getPosition();
//					this->mpWaterSurfaceObject->getRectNode()->setPosition(0,this->mWaterHeight,0);
//				}
//
//				
//				
//			}
//#endif
//		}
//
//		Ogre::ColourValue CFloodAnalysisTool::getWaterColor()
//		{
//			return this->mWaterColor;
//		}
//
//		float CFloodAnalysisTool::getWaterHeight()
//		{
//			return this->mWaterHeight;
//		}
//
//		void CFloodAnalysisTool::setUseFloodAnalysis(const bool& useFloodAnalysis)
//		{
//			this->mUseFloodAnalysis = useFloodAnalysis;
//			Ogre::Real floodMode = -1;
//			if (this->getUseFloodAnalysis())
//			{
//				floodMode = 1;
//			}
//			for (int i = 0; i < this->mLanewayMaterialNames.size();++i)
//			{
//				Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingletonPtr()->getByName(this->mLanewayMaterialNames.at(i),VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
//				if (!mat.isNull())
//				{
//					Ogre::GpuProgramParametersSharedPtr gpSp = mat->getTechnique(0)->getPass(0)->getFragmentProgramParameters();
//					gpSp->setNamedConstant("floodMode",floodMode);
//				}
//			}
//			this->createWaterSurface();
//		}
//		
//		bool CFloodAnalysisTool::getUseFloodAnalysis()
//		{
//			return this->mUseFloodAnalysis;
//		}
//		
//		//void CRaySelectedTool::mouseReleaseEvent(const int& x ,const int& y , const int& button)
//		//{
//		//	if (button == 1 && !this->mIsMouseDrag)
//		//	{
//		//		Ogre::Vector3 intersectPoint(Ogre::Vector3::ZERO);
//		//		Ogre::RaySceneQueryResultEntry resultObject;
//		//		this->ref_mpGeoSpatialControl->getGeoSceneManager()->rayQuery(x,y,intersectPoint,resultObject);
//		//		if (this->ref_mpGeoSpatialControl)
//		//		{
//		//			this->ref_mpGeoSpatialControl->afterRayQuery(resultObject);
//		//		}
//		//		//if (resultObject.movable != NULL)
//		//		//{
//		//		//	//resultObject.movable->setUserAny()
//		//		//	
//		//		//	CGeoUserData* pUserData = resultObject.movable->getUserAny().get<CGeoUserData*>();
//		//		//	if (pUserData != NULL)
//		//		//	{
//		//		//		pUserData->setSelected(true);
//		//		//	}
//		//		//}
//		//	}
//		//}
//		//
//		//void CRaySelectedTool::mousePressEvent(const int& x ,const int& y , const int& button)
//		//{
//		//	
//		//}
//		//
//		//void CRaySelectedTool::mouseDoubleClickEvent(const int& x ,const int& y , const int& button)
//		//{
//		//
//		//}
//	
//		//void CRaySelectedTool::mouseMoveEvent(const int& x ,const int& y, const int& button)
//		//{
//		//
//		//}
//		//
//		//void CRaySelectedTool::wheelEvent(const int& x ,const int& y , const int& delta)
//		//{
//		//
//		//}
//		//
//		//void CRaySelectedTool::keyPressEvent(const int& key)
//		//{
//		//
//		//}
//		//
//		//bool CRaySelectedTool::handleEvent(VirtualMine::Core::CEvent* evt)
//		//{
//		//	CEvent::Type type = evt->type();
//		//	switch(type)
//		//	{
//		//	case CEvent::MouseButtonPress:
//		//		{
//		//			break;
//		//		}
//		//	case CEvent::MouseButtonRelease:
//		//		{
//		//			CMouseEvent* pMouseEvent = dynamic_cast<CMouseEvent*>(evt);
//		//			this->mousePressEvent(pMouseEvent->getX(),pMouseEvent->getY(),pMouseEvent->getButton());
//		//			evt->accept();
//		//			break;
//		//		}
//		//	case CEvent::MouseMove:
//		//		{
//		//			break;	
//		//		}
//		//	default:
//		//		break;
//		//	}
//		//	return evt->isAccepted();
//		//}
//	
//	}
//}












//////////////////////////////////////////////////////




#if 0
#include "vrmine/vr_systemui/floodanalysistool.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_arithmetic/arithmetic/rectflood_meshcreator.h"
using namespace VirtualMine::Scene;

namespace VirtualMine
{
	namespace SystemUI
	{
		CFloodAnalysisTool::CFloodAnalysisTool()
			:ref_mpGeoSpatialControl(NULL),mWaterColor(Ogre::ColourValue(0,0,0.7)),
			mWaterHeight(-200),mUseFloodAnalysis(false),mShowWaterSurface(true),mUseFloatEffect(true)
		{
			this->mpWaterSurfaceObject = NULL;
			mLanewayMaterialNames.push_back("laneway_default");
			mLanewayMaterialNames.push_back("laneway_gongzigang");
			mLanewayMaterialNames.push_back("laneway_hongzhuan");
			mLanewayMaterialNames.push_back("laneway_liaoshi");
			mLanewayMaterialNames.push_back("laneway_maopen");
			mLanewayMaterialNames.push_back("laneway_penjiang");
		}

		bool CFloodAnalysisTool::getWaterSurfaceState()
		{
			return this->mShowWaterSurface;
		}
		void CFloodAnalysisTool::setWaterSurfaceState(const bool& showWaterSurface)
		{
			this->mShowWaterSurface = showWaterSurface;
			if (this->mpWaterSurfaceObject)
			{
				this->mpWaterSurfaceObject->setVisible(this->mShowWaterSurface);
			}
		}
		bool CFloodAnalysisTool::getUseFloatEffect()
		{
			return this->mUseFloatEffect;
		}
		void CFloodAnalysisTool::setUseFloatEffect(const bool& useFloatEffect)
		{
			this->mUseFloatEffect = useFloatEffect;
			Ogre::String matName("VRMine/WaterSurface");
			Ogre::MaterialPtr waterSurfaceMaterial = ::Ogre::MaterialManager::getSingletonPtr()->getByName(matName,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			if (!waterSurfaceMaterial.isNull())
			{
				Ogre::TextureUnitState* pTexUnite = waterSurfaceMaterial->getTechnique(0)->getPass(0)->getTextureUnitState(0);
				if (pTexUnite)
				{
					if (useFloatEffect)
					{
						pTexUnite->setScrollAnimation(0.05,0.05);
					}
					else
					{
						pTexUnite->setScrollAnimation(0,0);
					}

					waterSurfaceMaterial->load();
				}

			}
		}

		CFloodAnalysisTool::~CFloodAnalysisTool()
		{

		}

		void CFloodAnalysisTool::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl)
		{
			this->ref_mpGeoSpatialControl= ref_pGeoSpatialControl;
		}

		void CFloodAnalysisTool::setWaterColor(const Ogre::ColourValue& color)
		{
			this->mWaterColor = color;
			for (int i = 0; i < this->mLanewayMaterialNames.size();++i)
			{
				Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingletonPtr()->getByName(this->mLanewayMaterialNames.at(i),VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				if (!mat.isNull())
				{
					Ogre::GpuProgramParametersSharedPtr gpSp = mat->getTechnique(0)->getPass(0)->getFragmentProgramParameters();
					gpSp->setNamedConstant("waterColor",color);
					mat->load();
				}
			}

		}

		void CFloodAnalysisTool::setLanewayCtl(const Ogre::Vector3& camPos)
		{
			for (int i = 0; i < this->mLanewayMaterialNames.size();++i)
			{
				Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingletonPtr()->getByName(this->mLanewayMaterialNames.at(i),VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				if (!mat.isNull())
				{
					Ogre::GpuProgramParametersSharedPtr gpSp = mat->getTechnique(0)->getPass(0)->getFragmentProgramParameters();
					gpSp->setNamedConstant("camPos",camPos);
					mat->load();
				}
			}
		}

		void CFloodAnalysisTool::createWaterSurface()
		{
			if (this->mpWaterSurfaceObject == NULL)
			{
				/*Ogre::Plane shadowPlane(Ogre::Vector3::UNIT_Y,0);
				Ogre::MeshManager::getSingleton().createPlane("waterSurface",
				VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP,shadowPlane,6000,3000,2,2,true,1,5,5,Ogre::Vector3::UNIT_Z);

				this->mpWaterSurfaceObject = this->ref_mpGeoSpatialControl->getGeoSceneManager()->createEntity("waterSurfaceEntity", "waterSurface");*/

				//暂时绑定 空对象
				/*	VirtualMine::Core::CBaseObject* object = new VirtualMine::Core::CBaseObject();
				Ogre::Any any((VirtualMine::Core::CBaseObject*)object);
				this->mpWaterSurfaceObject->setUserAny(any);

				Ogre::String matName("VRMine/WaterSurface");
				this->mpWaterSurfaceObject->setMaterialName(matName,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				Ogre::MaterialPtr waterSurfaceMaterial = ::Ogre::MaterialManager::getSingletonPtr()->getByName(matName,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				if (!waterSurfaceMaterial->isLoaded())
				{
				waterSurfaceMaterial->getTechnique(0)->getPass(0)->setCullingMode(Ogre::CULL_NONE);
				waterSurfaceMaterial->load();
				}
				this->mpWaterSurfaceObject->setCastShadows(false);
				this->ref_mpGeoSpatialControl->getGeoSceneManager()->getRootSceneNode()->createChildSceneNode()->attachObject(this->mpWaterSurfaceObject);
				this->mpWaterSurfaceObject->getParentNode()->setPosition(1000,this->mWaterHeight,0);
				}
				bool visible = (this->mUseFloodAnalysis && this->mShowWaterSurface);
				this->mpWaterSurfaceObject->setVisible(visible);*/

				this->mpWaterSurfaceObject = new VirtualMine::Arithmetic::CRectFlood_MeshCreator();

				this->mpWaterSurfaceObject->setSceneManager(this->ref_mpGeoSpatialControl->getGeoSceneManager());

				this->mpWaterSurfaceObject->createRect(Ogre::Vector3(100,100,100),Ogre::Vector3(200,100,300));
				
				this->mpWaterSurfaceObject->attachRect();


			}


		}

		void CFloodAnalysisTool::setWaterHeight(const float& waterHeight)
		{
			this->mWaterHeight = waterHeight;
			for (int i = 0; i < this->mLanewayMaterialNames.size();++i)
			{
				Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingletonPtr()->getByName(this->mLanewayMaterialNames.at(i),VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				if (!mat.isNull())
				{
					Ogre::GpuProgramParametersSharedPtr gpSp = mat->getTechnique(0)->getPass(0)->getFragmentProgramParameters();

					gpSp->setNamedConstant("waterHeight",this->mWaterHeight);
				}
			}
		if (this->mpWaterSurfaceObject && this->mShowWaterSurface)
			{
				this->mpWaterSurfaceObject->setVisible(this->mShowWaterSurface);
				this->mpWaterSurfaceObject->setVisible(true);
				//this->mpWaterSurfaceObject->getParentNode()->setPosition(0,this->mWaterHeight,0);
			    this->mpWaterSurfaceObject->getRectNode()->setPosition(0,this->mWaterHeight,0);
			}
		}

		Ogre::ColourValue CFloodAnalysisTool::getWaterColor()
		{
			return this->mWaterColor;
		}

		float CFloodAnalysisTool::getWaterHeight()
		{
			return this->mWaterHeight;
		}

		void CFloodAnalysisTool::setUseFloodAnalysis(const bool& useFloodAnalysis)
		{
			this->mUseFloodAnalysis = useFloodAnalysis;
			Ogre::Real floodMode = -1;
			if (this->getUseFloodAnalysis())
			{
				floodMode = 1;
			}
			for (int i = 0; i < this->mLanewayMaterialNames.size();++i)
			{
				Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingletonPtr()->getByName(this->mLanewayMaterialNames.at(i),VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				if (!mat.isNull())
				{
					Ogre::GpuProgramParametersSharedPtr gpSp = mat->getTechnique(0)->getPass(0)->getFragmentProgramParameters();
					gpSp->setNamedConstant("floodMode",floodMode);
				}
			}
			this->createWaterSurface();
		}

		bool CFloodAnalysisTool::getUseFloodAnalysis()
		{
			return this->mUseFloodAnalysis;
		}

		//void CRaySelectedTool::mouseReleaseEvent(const int& x ,const int& y , const int& button)
		//{
		//	if (button == 1 && !this->mIsMouseDrag)
		//	{
		//		Ogre::Vector3 intersectPoint(Ogre::Vector3::ZERO);
		//		Ogre::RaySceneQueryResultEntry resultObject;
		//		this->ref_mpGeoSpatialControl->getGeoSceneManager()->rayQuery(x,y,intersectPoint,resultObject);
		//		if (this->ref_mpGeoSpatialControl)
		//		{
		//			this->ref_mpGeoSpatialControl->afterRayQuery(resultObject);
		//		}
		//		//if (resultObject.movable != NULL)
		//		//{
		//		//	//resultObject.movable->setUserAny()
		//		//	
		//		//	CGeoUserData* pUserData = resultObject.movable->getUserAny().get<CGeoUserData*>();
		//		//	if (pUserData != NULL)
		//		//	{
		//		//		pUserData->setSelected(true);
		//		//	}
		//		//}
		//	}
		//}
		//
		//void CRaySelectedTool::mousePressEvent(const int& x ,const int& y , const int& button)
		//{
		//	
		//}
		//
		//void CRaySelectedTool::mouseDoubleClickEvent(const int& x ,const int& y , const int& button)
		//{
		//
		//}

		//void CRaySelectedTool::mouseMoveEvent(const int& x ,const int& y, const int& button)
		//{
		//
		//}
		//
		//void CRaySelectedTool::wheelEvent(const int& x ,const int& y , const int& delta)
		//{
		//
		//}
		//
		//void CRaySelectedTool::keyPressEvent(const int& key)
		//{
		//
		//}
		//
		//bool CRaySelectedTool::handleEvent(VirtualMine::Core::CEvent* evt)
		//{
		//	CEvent::Type type = evt->type();
		//	switch(type)
		//	{
		//	case CEvent::MouseButtonPress:
		//		{
		//			break;
		//		}
		//	case CEvent::MouseButtonRelease:
		//		{
		//			CMouseEvent* pMouseEvent = dynamic_cast<CMouseEvent*>(evt);
		//			this->mousePressEvent(pMouseEvent->getX(),pMouseEvent->getY(),pMouseEvent->getButton());
		//			evt->accept();
		//			break;
		//		}
		//	case CEvent::MouseMove:
		//		{
		//			break;	
		//		}
		//	default:
		//		break;
		//	}
		//	return evt->isAccepted();
		//}


	}
}


#endif




#include "vrmine/vr_systemui/floodanalysistool.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_arithmetic/arithmetic/rectflood_meshcreator.h"
using namespace VirtualMine::Scene;

namespace VirtualMine
{
	namespace SystemUI
	{
		CFloodAnalysisTool::CFloodAnalysisTool()
			:ref_mpGeoSpatialControl(NULL),mWaterColor(Ogre::ColourValue(0,0,0.7)),
			mWaterHeight(-200),mUseFloodAnalysis(false),mShowWaterSurface(true),mUseFloatEffect(true)
		{
			this->mpWaterSurfaceObject = NULL;
			mLanewayMaterialNames.push_back("laneway_default");
			mLanewayMaterialNames.push_back("laneway_gongzigang");
			mLanewayMaterialNames.push_back("laneway_hongzhuan");
			mLanewayMaterialNames.push_back("laneway_liaoshi");
			mLanewayMaterialNames.push_back("laneway_maopen");
			mLanewayMaterialNames.push_back("laneway_penjiang");
		   
		}

		bool CFloodAnalysisTool::getWaterSurfaceState()
		{
			return this->mShowWaterSurface;
		}
		void CFloodAnalysisTool::setWaterSurfaceState(const bool& showWaterSurface)
		{
			this->mShowWaterSurface = showWaterSurface;
			if (this->mpWaterSurfaceObject)
			{
				this->mpWaterSurfaceObject->setVisible(this->mShowWaterSurface);
			}
		}
		bool CFloodAnalysisTool::getUseFloatEffect()
		{
			return this->mUseFloatEffect;
		}
		void CFloodAnalysisTool::setUseFloatEffect(const bool& useFloatEffect)
		{
			this->mUseFloatEffect = useFloatEffect;
			Ogre::String matName("VRMine/WaterSurface");
			Ogre::MaterialPtr waterSurfaceMaterial = ::Ogre::MaterialManager::getSingletonPtr()->getByName(matName,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			if (!waterSurfaceMaterial.isNull())
			{
				Ogre::TextureUnitState* pTexUnite = waterSurfaceMaterial->getTechnique(0)->getPass(0)->getTextureUnitState(0);
				if (pTexUnite)
				{
					if (useFloatEffect)
					{
						pTexUnite->setScrollAnimation(0.05,0.05);
					}
					else
					{
						pTexUnite->setScrollAnimation(0,0);
					}

					waterSurfaceMaterial->load();
				}

			}
		}

		CFloodAnalysisTool::~CFloodAnalysisTool()
		{

		}

		void CFloodAnalysisTool::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl)
		{
			this->ref_mpGeoSpatialControl= ref_pGeoSpatialControl;
		}

		void CFloodAnalysisTool::setWaterColor(const Ogre::ColourValue& color)
		{
			this->mWaterColor = color;
			for (int i = 0; i < this->mLanewayMaterialNames.size();++i)
			{
				Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingletonPtr()->getByName(this->mLanewayMaterialNames.at(i),VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				if (!mat.isNull())
				{
					Ogre::GpuProgramParametersSharedPtr gpSp = mat->getTechnique(0)->getPass(0)->getFragmentProgramParameters();
					gpSp->setNamedConstant("waterColor",color);
					mat->load();
				}
			}

		}

		void CFloodAnalysisTool::setLanewayCtl(const Ogre::Vector3& camPos)
		{
			for (int i = 0; i < this->mLanewayMaterialNames.size();++i)
			{
				Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingletonPtr()->getByName(this->mLanewayMaterialNames.at(i),VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				if (!mat.isNull())
				{
					Ogre::GpuProgramParametersSharedPtr gpSp = mat->getTechnique(0)->getPass(0)->getFragmentProgramParameters();
					gpSp->setNamedConstant("camPos",camPos);
					mat->load();
				}
			}
		}

		void CFloodAnalysisTool::createWaterSurface()
		{
						

		}

		void CFloodAnalysisTool::createSurface()
		{
			this->mShowWaterSurface = false;
			if (this->mpWaterSurfaceObject == NULL)
			{

#if 0 plane

				Ogre::Plane shadowPlane(Ogre::Vector3::UNIT_Y,0);
				Ogre::MeshManager::getSingleton().createPlane("waterSurface",
					VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP,shadowPlane,6000,3000,2,2,true,1,5,5,Ogre::Vector3::UNIT_Z);

				this->mpWaterSurfaceObject = this->ref_mpGeoSpatialControl->getGeoSceneManager()->createEntity("waterSurfaceEntity", "waterSurface");

				//暂时绑定 空对象
				VirtualMine::Core::CBaseObject* object = new VirtualMine::Core::CBaseObject();
				Ogre::Any any((VirtualMine::Core::CBaseObject*)object);
				this->mpWaterSurfaceObject->setUserAny(any);

				Ogre::String matName("VRMine/WaterSurface");
				this->mpWaterSurfaceObject->setMaterialName(matName,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				Ogre::MaterialPtr waterSurfaceMaterial = ::Ogre::MaterialManager::getSingletonPtr()->getByName(matName,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				if (!waterSurfaceMaterial->isLoaded())
				{
					waterSurfaceMaterial->getTechnique(0)->getPass(0)->setCullingMode(Ogre::CULL_NONE);
					waterSurfaceMaterial->load();
				}
				this->mpWaterSurfaceObject->setCastShadows(false);
				this->ref_mpGeoSpatialControl->getGeoSceneManager()->getRootSceneNode()->createChildSceneNode()->attachObject(this->mpWaterSurfaceObject);
				this->mpWaterSurfaceObject->getParentNode()->setPosition(1000,this->mWaterHeight,0);
			}
			bool visible = (this->mUseFloodAnalysis && this->mShowWaterSurface);
			this->mpWaterSurfaceObject->setVisible(visible);




#endif

#if 1 rect

				this->mpWaterSurfaceObject = new VirtualMine::Arithmetic::CRectFlood_MeshCreator();

				this->mpWaterSurfaceObject->setSceneManager(this->ref_mpGeoSpatialControl->getGeoSceneManager());

				Ogre::AxisAlignedBox box ;

				if (this->ref_mpGeoSpatialControl)
				{
					if (this->ref_mpGeoSpatialControl->getScene())
					{
						if (this->ref_mpGeoSpatialControl->getScene()->getDemLayer())
						{					
							box = this->ref_mpGeoSpatialControl->getScene()->getDemLayer()->getBoundingBox();
						}
					}

				}

				Ogre::Vector3 minVec = box.getMinimum();
				Ogre::Vector3 maxVec = box.getMaximum();

				////水面下降n米
				/*minVec.y = minVec.y - 200; 
				maxVec.y = maxVec.y - 200;*/
				minVec.y =  -200; 
				maxVec.y =  -200;

				double heighty = -200;
				minVec.y = heighty;
				maxVec.y = heighty;


				if (minVec == maxVec)
				{
					this->mpWaterSurfaceObject->createRect(Ogre::Vector3(100,100,100),Ogre::Vector3(200,100,300));


				}
				else
				{
					this->mpWaterSurfaceObject->createRect(minVec,maxVec);
				}

				this->mpWaterSurfaceObject->attachRect();

				this->mpWaterSurfaceObject->getRectNode()->setVisible(false);

				this->mWaterHeight = heighty;
				
		}

		this->mShowWaterSurface = true;
		this->mNextShowSurface = true;
#endif

	

		///////隐藏or消失
		//if (!this->mShowWaterSurface)		
		//{
		//	
		//	this->setWaterHeight(-800);
		//	this->mpWaterSurfaceObject->getRectNode()->detachObject("Flood");
		//	//this->mpWaterSurfaceObject->getRectNode()->detachAllObjects();

		//	//this->ref_mpGeoSpatialControl->getGeoSceneManager()->destroySceneNode(this->mpWaterSurfaceObject->getRectNode());

		//	//////不能删么
		//	//delete	this->mpWaterSurfaceObject;
		//	//         this->mpWaterSurfaceObject = NULL;        
		//}
		//   else
		//{
		//	if (this->mpWaterSurfaceObject->getWaterSurface())
		//	{
		//		this->mpWaterSurfaceObject->getRectNode()->attachObject(this->mpWaterSurfaceObject->getWaterSurface());

		//	}


		//}
	}

	void CFloodAnalysisTool::visibleSurface()
	{
		if (this->mNextShowSurface)
		{
			 this->mNextShowSurface = false;
			 this->mShowWaterSurface = true;
			this->mpWaterSurfaceObject->getRectNode()->setVisible(true);
		   this->setWaterHeight(this->mWaterHeight);
		}
		else
		{
			this->mShowWaterSurface = false;
			this->mNextShowSurface = true;
			//this->setWaterHeight(-800);
			this->mpWaterSurfaceObject->getRectNode()->setVisible(false);
			
		}
	}

	void CFloodAnalysisTool::setWaterHeight(const float& waterHeight)
	{
		this->mWaterHeight = waterHeight;
		for (int i = 0; i < this->mLanewayMaterialNames.size();++i)
		{
			Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingletonPtr()->getByName(this->mLanewayMaterialNames.at(i),VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			if (!mat.isNull())
			{
				Ogre::GpuProgramParametersSharedPtr gpSp = mat->getTechnique(0)->getPass(0)->getFragmentProgramParameters();

				gpSp->setNamedConstant("waterHeight",this->mWaterHeight);
			}
		}
		if (this->mpWaterSurfaceObject && this->mShowWaterSurface)
		{
			//this->mpWaterSurfaceObject->setVisible(this->mShowWaterSurface);
			this->mpWaterSurfaceObject->setVisible(true);
			//this->mpWaterSurfaceObject->getParentNode()->setPosition(0,this->mWaterHeight,0);
			this->mpWaterSurfaceObject->getRectNode()->setPosition(0,this->mWaterHeight,0);
			
		}
		
	}

		Ogre::ColourValue CFloodAnalysisTool::getWaterColor()
		{
			return this->mWaterColor;
		}

		float CFloodAnalysisTool::getWaterHeight()
		{
			return this->mWaterHeight;
		}

		void CFloodAnalysisTool::setUseFloodAnalysis(const bool& useFloodAnalysis)
		{
			this->mUseFloodAnalysis = useFloodAnalysis;
			Ogre::Real floodMode = -1;
			if (this->getUseFloodAnalysis())
			{
				floodMode = 1;
			}
			for (int i = 0; i < this->mLanewayMaterialNames.size();++i)
			{
				Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingletonPtr()->getByName(this->mLanewayMaterialNames.at(i),VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				if (!mat.isNull())
				{
					Ogre::GpuProgramParametersSharedPtr gpSp = mat->getTechnique(0)->getPass(0)->getFragmentProgramParameters();
					gpSp->setNamedConstant("floodMode",floodMode);
				}
			}

			//this->createWaterSurface();
			this->visibleSurface();
		}

		bool CFloodAnalysisTool::getUseFloodAnalysis()
		{
			return this->mUseFloodAnalysis;
		}

		//void CRaySelectedTool::mouseReleaseEvent(const int& x ,const int& y , const int& button)
		//{
		//	if (button == 1 && !this->mIsMouseDrag)
		//	{
		//		Ogre::Vector3 intersectPoint(Ogre::Vector3::ZERO);
		//		Ogre::RaySceneQueryResultEntry resultObject;
		//		this->ref_mpGeoSpatialControl->getGeoSceneManager()->rayQuery(x,y,intersectPoint,resultObject);
		//		if (this->ref_mpGeoSpatialControl)
		//		{
		//			this->ref_mpGeoSpatialControl->afterRayQuery(resultObject);
		//		}
		//		//if (resultObject.movable != NULL)
		//		//{
		//		//	//resultObject.movable->setUserAny()
		//		//	
		//		//	CGeoUserData* pUserData = resultObject.movable->getUserAny().get<CGeoUserData*>();
		//		//	if (pUserData != NULL)
		//		//	{
		//		//		pUserData->setSelected(true);
		//		//	}
		//		//}
		//	}
		//}
		//
		//void CRaySelectedTool::mousePressEvent(const int& x ,const int& y , const int& button)
		//{
		//	
		//}
		//
		//void CRaySelectedTool::mouseDoubleClickEvent(const int& x ,const int& y , const int& button)
		//{
		//
		//}

		//void CRaySelectedTool::mouseMoveEvent(const int& x ,const int& y, const int& button)
		//{
		//
		//}
		//
		//void CRaySelectedTool::wheelEvent(const int& x ,const int& y , const int& delta)
		//{
		//
		//}
		//
		//void CRaySelectedTool::keyPressEvent(const int& key)
		//{
		//
		//}
		//
		//bool CRaySelectedTool::handleEvent(VirtualMine::Core::CEvent* evt)
		//{
		//	CEvent::Type type = evt->type();
		//	switch(type)
		//	{
		//	case CEvent::MouseButtonPress:
		//		{
		//			break;
		//		}
		//	case CEvent::MouseButtonRelease:
		//		{
		//			CMouseEvent* pMouseEvent = dynamic_cast<CMouseEvent*>(evt);
		//			this->mousePressEvent(pMouseEvent->getX(),pMouseEvent->getY(),pMouseEvent->getButton());
		//			evt->accept();
		//			break;
		//		}
		//	case CEvent::MouseMove:
		//		{
		//			break;	
		//		}
		//	default:
		//		break;
		//	}
		//	return evt->isAccepted();
		//}


	}
}

