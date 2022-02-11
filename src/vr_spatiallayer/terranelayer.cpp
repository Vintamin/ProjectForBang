

#include "vrmine\vr_spatiallayer\demlayer.h"
#include "vrmine/vr_spatiallayer/terranelayer.h"
#include "vrmine/vr_databaseengine/database/ifeature.h"
#include "vrmine/vr_spatialinterface/igeoobject.h"
#include "vrmine/vr_spatialrender/spatialrender/terranerenderobject.h"
#include <list>
#include "vrmine/vr_utility/objecttransformer.h"
#include "vrmine/vr_spatialobject/mine/terraneobject.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_spatialobject/geoproperty/terraneproperty.h"
#include "vrmine/vr_geometry/geometry/terrane.h"
#include "vrmine/vr_style/style/terranestyle.h"
#include "vrmine/vr_spatialrender/baserender/moveabletext.h"

using namespace VirtualMine::Database;
using namespace VirtualMine::Base;
using namespace VirtualMine::SpatialRender;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::GeoProperty;
using namespace VirtualMine::Style;
using namespace VirtualMine::Mine;
using namespace VirtualMine::Geometry;

namespace VirtualMine
{
    namespace SpatialLayer
    {

		CTerraneLayer::CTerraneLayer()
		{
			this->mType = VirtualMine::Core::GeoDataType::GDT_TERRANE;
		}

		CTerraneLayer::~CTerraneLayer()
		{
		}

		void CTerraneLayer::update()
		{
		
		}

		void CTerraneLayer::initialise()
		{
			//assert(this->ref_mpDataSet);
 			if (NULL == this->ref_mpDataSet)
				return;
			this->ref_mpGeoSceneManager = this->getScene()->getGeoSceneManager();
	
#if 0
			CDemLayer* pDemLayer = dynamic_cast<CDemLayer*>(this->ref_mpGeoSpatialScene->getDemLayer());
			if (!pDemLayer)
			{
				return;
			}
#endif
			CTerraneRenderableObject* pRenderableObject(NULL);
			int featureCount = this->ref_mpDataSet->getCount();//需要数据库引擎提供接口
			for (int i = 0 ; i < featureCount; ++i)
			{
				IFeature* pFeature = this->ref_mpDataSet->getFeature(i);
				VirtualMine::SpatialInterface::IGeoObject* pGeoObject = new VirtualMine::Mine::CTerraneObject();
				pGeoObject->fromFeature(pFeature);
				
#if 1
				
				CTerraneGeometry* terraneGeometry = dynamic_cast<CTerraneGeometry*>(pGeoObject->getGeometry());
			

#endif
#if 0  岩层字体

				////根据name写字体
				  
			     std::string name = pFeature->getFieldName();
				Ogre::String lanewayName = name;
				pGeoObject->setName(lanewayName);
				Ogre::Vector3 centerPoint;
				Ogre::String firstChar = lanewayName.substr(0,2);
				{
					VirtualMine::Geometry::CPoint point =  terraneGeometry->getPoint(5049);										
					centerPoint = Ogre::Vector3(point.getX(),point.getY(),point.getZ()*(-1));				
					if (name == "砂岩")
					{
						centerPoint.y += 15; 
					}
					else if(name == "灰岩")
					{
						centerPoint.y -= 15;
					}

					//////////////////////////////////////////////////////////////////////////
					int iWLen = MultiByteToWideChar( CP_ACP, 0, lanewayName.c_str(), lanewayName.size(), 0, 0 ); // 计算转换后宽字符串的长度。（不包含字符串结束符）  
					wchar_t *lpwsz = new wchar_t [iWLen + 1];  
					MultiByteToWideChar( CP_ACP, 0, lanewayName.c_str(), lanewayName.size(), lpwsz, iWLen ); // 正式转换。  
					lpwsz[iWLen] = L'\0';   
					Ogre::DisplayString disName(lpwsz);

					//////////////////////////////////////////////////////////////////////////
					VirtualMine::BaseRender::MovableText* pText = new VirtualMine::BaseRender::MovableText(lanewayName,
						Ogre::DisplayString(disName),Ogre::String("SimHei"),10,Ogre::ColourValue(1,0.843,0,1));

					pText->setTextAlignment(VirtualMine::BaseRender::MovableText::H_CENTER,VirtualMine::BaseRender::MovableText::V_CENTER);

					if (this->ref_mpGeoSceneManager)
					{
						Ogre::SceneNode* node = this->ref_mpGeoSceneManager->getRootSceneNode()->createChildSceneNode();
					    node->setPosition(centerPoint.x,centerPoint.y,centerPoint.z);
						node->attachObject(pText);
						this->mTextNodes.push_back(node);
					}
					if (this->mTextNodes.size() > 0)
					{
						this->mNeedLabel = true;
					}
				}


				//this->mpCameraListener->ref_mpObject = pText;
#endif  


				if(NULL == pRenderableObject)
				{
					pRenderableObject = new  CTerraneRenderableObject();
					pRenderableObject->setGeoSceneManager(this->ref_mpGeoSceneManager);
				}
				pRenderableObject->addGeoObject(pGeoObject);
			}
			if (pRenderableObject)
			{
				if(NULL != this->mpRenderableObject)
				{
					this->mpRenderableObject->deRender();
					SAFE_DELETE(this->mpRenderableObject);
				}
				pRenderableObject->build();
				pRenderableObject->setNode(this->ref_mpGeoSceneManager->createSceneNode());
				this->mpRenderableObject = pRenderableObject;
			}
			CSceneLayer::initialise();
		}

		void CTerraneLayer::notifyUpdate()
		{
			
		}

        void CTerraneLayer::setFrameMode(bool isFrameMode)
		{
			Ogre::MaterialPtr material = Ogre::MaterialManager::getSingletonPtr()->getByName("pureMaterial",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

			if (!material.isNull())
			{
				Ogre::Pass* pass = material->getTechnique(0)->getPass(0);
				pass->setCullingMode(Ogre::CULL_NONE);
				pass->setPolygonMode(Ogre::PM_WIREFRAME);
				material->load();
			}

			if	(this->mpRenderableObject == NULL) return;
			CTerraneRenderableObject* terraneRenderObject = dynamic_cast<CTerraneRenderableObject*>(this->mpRenderableObject);
			if (terraneRenderObject == NULL)
			{
				return;
			}
			int objectCount = terraneRenderObject->getGeoObjectCount();
			for (int i = 0; i<objectCount; ++i)
			{
				CTerraneObject* terraneObject = dynamic_cast<CTerraneObject*>(terraneRenderObject->getGeoObject(i));
				CTerraneProperty* terranePro = dynamic_cast<CTerraneProperty*>(terraneObject->getGeoProperty());
				CTerraneStyle* terraneStyle = dynamic_cast<CTerraneStyle*>(terraneObject->getStyle());
				//CLaneWayLineGeometry* lanewayGeometry = dynamic_cast<CLaneWayLineGeometry*>(lanewayObject->getGeometry());
				//CLanewayStyle* lanewayStyle = dynamic_cast<CLanewayStyle*>(lanewayObject->getStyle());

				Ogre::ManualObject* renderObject = this->ref_mpGeoSceneManager->getManualObject(terranePro->getName());
				int count = renderObject->getNumSections();
				if (isFrameMode)
				{
					for (int j = 0; j< count; ++j)
					{
						renderObject->getSection(j)->setMaterialName("pureMaterial");
					}
				}
				else
				{
					for (int j = 0; j< count; ++j)
					{
						renderObject->getSection(j)->setMaterialName(terranePro->getName());
					}
				}

			}
		}
    }
}
