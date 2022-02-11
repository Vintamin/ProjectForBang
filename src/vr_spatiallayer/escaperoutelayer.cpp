#include "vrmine/vr_spatiallayer/escaperoutelayer.h"
#include "vrmine/vr_databaseengine/database/ifeature.h"
#include "vrmine/vr_spatialinterface/igeoobject.h"
#include <list>
#include "vrmine/vr_utility/objecttransformer.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_spatialrender/lanewaypiperender/pipeline.h"
#include "bang/escaperoutefeature.h"
#include "vrmine/vr_scenecontrol/geospatialcontrol.h"
#include "vrmine/vr_spatialengine/geoscenecamera.h"

#include "vrmine/vr_spatialrender/spatialrender/lanewayrenderableobject.h"
#include "vrmine/vr_spatialobject/mine/lanwayobject.h"
#include "vrmine/vr_spatialobject/mine/flagobject.h"
#include "vrmine/vr_style/style/lanewaystyle.h"
#include "vrmine/vr_geometry/geometry/laneway.h"
#include "vrmine/vr_databaseengine/database/lanewayfeature.h"
#include "vrmine/vr_spatialrender/baserender/moveabletext.h"

#include "vrmine/vr_sqlitedatabase/sqlitedatabase/sqlitedatabase.h"
#include "bang/bangsqlitedatabase.h"

using namespace VirtualMine::Database;
using namespace VirtualMine::SQLiteDatabase;
using namespace VirtualMine::Base;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::SpatialRender;
using namespace VirtualMine::BaseRender;
using namespace VirtualMine::Bang_Database;
using namespace VirtualMine::Geometry;
using namespace VirtualMine::Style;



namespace VirtualMine
{
	namespace SpatialLayer
	{

		CEscapeRouteLayer::CEscapeRouteLayer()
		{
			this->mType = VirtualMine::Core::GeoDataType::GDT_ESCAPEROUTE;
		}

		CEscapeRouteLayer::~CEscapeRouteLayer()
		{

		}

		void CEscapeRouteLayer::update()
		{

		}

		void CEscapeRouteLayer::initialise()
		{
			//assert(this->ref_mpDataSet);

			if (NULL == this->ref_mpDataSet)
				return;
			this->ref_mpGeoSceneManager = this->getScene()->getGeoSceneManager();
			int featureCount = this->ref_mpDataSet->getCount();//需要数据库引擎提供接口
			                    
			int proID;
			IFeature* pFeature = this->ref_mpDataSet->getFeature(0);
			VirtualMine::Bang_Database::CEscapeRouteFeature* escapeRouteFeature = dynamic_cast<VirtualMine::Bang_Database::CEscapeRouteFeature*>(pFeature);			
			int escapeRouteProjectID = escapeRouteFeature->getFieldProjectID();
			proID = escapeRouteProjectID;




			CLanewayRenderableObject* pRenderableObject(NULL);

			IDataset* laneDatset = dynamic_cast<CBangSqliteDatabase*>(this->ref_mpDatabase)->getDatasetByProjectID(VirtualMine::Core::GeoDataType::GDT_LANWAY,proID);
			int laneSize =	laneDatset->getCount();
			for (int i = 0 ; i < laneSize; ++i)
			{
				IFeature* pFeature = laneDatset->getFeature(i);
				VirtualMine::SpatialInterface::IGeoObject* pGeoObject = new VirtualMine::Mine::CLaneWayObject();
				pGeoObject->fromFeature(pFeature);	


#if 1 ////////////////////////巷道字体

				////根据name写字体
				void* data =  pFeature->getPropertySet()->getFields().at(1).getVarient().data();
				char* name = (char*)data;
				Ogre::String lanewayName = name;
				pGeoObject->setName(lanewayName);
				Ogre::String firstChar = lanewayName.substr(0,2);
				if (firstChar != "巷" || firstChar == "巷" ) 
				{
					int count = dynamic_cast<CLaneWayLineGeometry*>(pGeoObject->getGeometry())->getNodesCount();											
					Ogre::Vector3 centerPoint =  dynamic_cast<CLaneWayLineGeometry*>(pGeoObject->getGeometry())->getNode(count/2)->getPosition();						
					centerPoint.y += 15; 

					//Ogre::UTFString str(L"abx");

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
						Ogre::SceneNode* node = this->ref_mpGeoSceneManager->getRootSceneNode()->createChildSceneNode(centerPoint);
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
					pRenderableObject = new  CLanewayRenderableObject();
				{
					pRenderableObject->setGeoSceneManager(this->ref_mpGeoSceneManager);
					pRenderableObject->addGeoObject(pGeoObject);
				}


				this->mGeoObjects.push_back(pGeoObject);
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

#if  1 警戒小旗	

			for (int i = 0 ; i < featureCount; ++i)
			{
				IFeature* pFeature = this->ref_mpDataSet->getFeature(i);

				VirtualMine::Bang_Database::CEscapeRouteFeature* escapeRouteFeature = dynamic_cast<VirtualMine::Bang_Database::CEscapeRouteFeature*>(pFeature);
				double PosX = escapeRouteFeature->getFieldPositionX();
				double PosY = escapeRouteFeature->getFieldPositionY();
				double PosZ = escapeRouteFeature->getFieldPositionZ();

				Ogre::Vector3 escapeRoutePoint(PosX,PosY,PosZ);
				escapeRoutePoint.z = escapeRoutePoint.z * (-1);
				int escapeRoutePointID = escapeRouteFeature->getFieldPointID();
				int escapeRouteProjectID = escapeRouteFeature->getFieldProjectID();

				std::string name = Ogre::StringConverter::toString(i);
				name = "flag" + name;
				double heightDirt = 4;
				Ogre::Vector3 referencePos = Ogre::Vector3::ZERO;
				float size = 20;
				Ogre::Vector3 rightBottomPoint(referencePos.x + size,referencePos.y,referencePos.z);
				Ogre::Vector3 rightTopPoint(referencePos.x + size,referencePos.y + size * 2,referencePos.z);
				Ogre::Vector3 leftBottomPoint(referencePos.x - size,referencePos.y,referencePos.z);
				Ogre::Vector3 leftTopPoint(referencePos.x - size,referencePos.y + size * 2,referencePos.z);


				Ogre::String flagMaterial = "flagMaterial";
				Ogre::MaterialPtr material = Ogre::MaterialManager::getSingletonPtr()->getByName(flagMaterial,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);

				if (!material.isNull())
				{
					Ogre::Pass* pass = material->getTechnique(0)->getPass(0);		
					pass->setCullingMode(Ogre::CULL_NONE);		
					/*Ogre::Pass* pass2 = material->getTechnique(0)->createPass();
					pass2->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);
					pass2->setCullingMode(Ogre::CULL_NONE);
					Ogre::TextureUnitState* unitestate = new Ogre::TextureUnitState(pass2);
					pass2->addTextureUnitState(unitestate);*/
					material->load();
				}
				Ogre::ManualObject* escapeRoutePointManualObj = this->ref_mpGeoSceneManager->createManualObject("escapeRoutePointManualObj_" + name);
				escapeRoutePointManualObj->setRenderQueueGroup(90);
				//Ogre::SceneNode* pFlagSceneNode = this->ref_mpGeoSceneManager->getRootSceneNode()->createChildSceneNode("flagNode" + name);

				escapeRoutePointManualObj->begin(flagMaterial,Ogre::RenderOperation::OT_TRIANGLE_LIST,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);

				escapeRoutePointManualObj->position(rightBottomPoint);
				escapeRoutePointManualObj->textureCoord(0,0);
				escapeRoutePointManualObj->position(rightTopPoint);
				escapeRoutePointManualObj->textureCoord(0,1);
				escapeRoutePointManualObj->position(leftTopPoint);
				escapeRoutePointManualObj->textureCoord(1,1);
				escapeRoutePointManualObj->position(leftTopPoint);
				escapeRoutePointManualObj->textureCoord(1,1);
				escapeRoutePointManualObj->position(leftBottomPoint);
				escapeRoutePointManualObj->textureCoord(1,0);
				escapeRoutePointManualObj->position(rightBottomPoint);
				escapeRoutePointManualObj->textureCoord(0,0);

				escapeRoutePointManualObj->triangle(0,1,2);
				escapeRoutePointManualObj->triangle(3,4,5);

				/*		if (i == 2)
				{
				static_cast<VirtualMine::SpatialEngine::CGeoSceneCamera*>(this->getGeoSceneManager()->getCamera(VirtualMine::SpatialEngine::CGeoSceneCamera::DEFAULT_CAMERA_NAME))->setPosition(leftBottomPoint);
				static_cast<VirtualMine::SpatialEngine::CGeoSceneCamera*>(this->getGeoSceneManager()->getCamera(VirtualMine::SpatialEngine::CGeoSceneCamera::DEFAULT_CAMERA_NAME))->setDirection(Ogre::Vector3(0,0,-1));

				}*/
				escapeRoutePointManualObj->end();

				VirtualMine::SpatialInterface::CGeoExtentionData* data = new VirtualMine::SpatialInterface::CGeoExtentionData(this->ref_mpGeoSceneManager);
				data->setExtentionData(escapeRoutePointManualObj);
				data->setSceneManager(this->ref_mpGeoSceneManager);

				VirtualMine::Mine::CFlagObject* flagobject = new VirtualMine::Mine::CFlagObject(VirtualMine::Core::GeoDataType::GDT_ESCAPEROUTE);
				Ogre::Any any((VirtualMine::Core::CBaseObject*)flagobject);
				escapeRoutePointManualObj->setUserAny(any);
				data->setOwnerObject(flagobject);
				//dynamic_cast<CLanewayRenderableObject*>(this->mpRenderableObject)->addGeoExtentionData(data);
				//this->mTextNodes
				//暂时用场景根节点创建字节点，之后再修改
				Ogre::SceneNode* pFlagNode = this->ref_mpGeoSceneManager->getRootSceneNode()->createChildSceneNode();
				pFlagNode->setPosition(Ogre::Vector3(escapeRoutePoint.x,
					escapeRoutePoint.y + heightDirt,
					escapeRoutePoint.z));
				pFlagNode->attachObject(escapeRoutePointManualObj);
				this->mTextNodes.push_back(pFlagNode);

			}

#endif	



			CSceneLayer::initialise();
			this->notifyUpdate();

		}

		void CEscapeRouteLayer::notifyUpdate()
		{
			CLanewayRenderableObject* pRenderObject = dynamic_cast< CLanewayRenderableObject*>(this->mpRenderableObject);
			if (!pRenderObject)
			{
				return;
			}
			if (mTextNodes.size() > 0)
			{
				Ogre::Vector3 camPos = ((VirtualMine::SpatialEngine::CGeoSceneManager*)this->ref_mpGeoSceneManager)->getDefaultCamera()->getPosition();
				std::vector<Ogre::SceneNode*>::iterator itr = this->mTextNodes.begin();
				std::vector<Ogre::SceneNode*>::iterator itrEnd = this->mTextNodes.end();

				while (itr != itrEnd)
				{
					Ogre::Real distance = (*itr)->getPosition().distance(camPos);
					Ogre::Real scale = distance * ((VirtualMine::SpatialEngine::CGeoSceneManager*)this->ref_mpGeoSceneManager)->getDefaultCamera()->getPixelDisplayRatio();
					(*itr)->setScale(scale,scale,scale);
					++itr;
				}
			}
		}

		void CEscapeRouteLayer::setFrameMode(bool isFrameMode)
		{
			//Ogre::MaterialPtr material = Ogre::MaterialManager::getSingletonPtr()->getByName("pureMaterial",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

			//if (!material.isNull())
			//{
			//	Ogre::Pass* pass = material->getTechnique(0)->getPass(0);
			//	pass->setCullingMode(Ogre::CULL_NONE);
			//	pass->setPolygonMode(Ogre::PM_WIREFRAME);
			//	material->load();
			//}

			//if	(this->mpRenderableObject == NULL) return;
			//CPipeLine* pipeRenderObject = dynamic_cast<CPipeLine*>(this->mpRenderableObject);
			//if (pipeRenderObject == NULL)
			//{
			//	return;
			//}
			//int objectCount = pipeRenderObject->getGeoObjectCount();
			//for (int i = 0; i<objectCount; ++i)
			//{
			//	CTerraneObject* terraneObject = dynamic_cast<CTerraneObject*>(terraneRenderObject->getGeoObject(i));
			//	CTerraneProperty* terranePro = dynamic_cast<CTerraneProperty*>(terraneObject->getGeoProperty());
			//	CTerraneStyle* terraneStyle = dynamic_cast<CTerraneStyle*>(terraneObject->getStyle());
			//	//CLaneWayLineGeometry* lanewayGeometry = dynamic_cast<CLaneWayLineGeometry*>(lanewayObject->getGeometry());
			//	//CLanewayStyle* lanewayStyle = dynamic_cast<CLanewayStyle*>(lanewayObject->getStyle());

			//	Ogre::ManualObject* renderObject = this->ref_mpGeoSceneManager->getManualObject(terranePro->getName());
			//	int count = renderObject->getNumSections();
			//	if (isFrameMode)
			//	{
			//		for (int j = 0; j< count; ++j)
			//		{
			//			renderObject->getSection(j)->setMaterialName("pureMaterial");
			//		}
			//	}
			//	else
			//	{
			//		for (int j = 0; j< count; ++j)
			//		{
			//			renderObject->getSection(j)->setMaterialName(terranePro->getName());
			//		}
			//	}

			//}

		}



	}
}
