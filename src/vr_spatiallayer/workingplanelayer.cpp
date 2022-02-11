


#include "vrmine/vr_spatiallayer/workingplanelayer.h"
#include "vrmine/vr_databaseengine/database/ifeature.h"
#include "vrmine/vr_spatialinterface/igeoobject.h"
#include "vrmine/vr_spatialrender/spatialrender/workplanerenderableobject.h"
#include <list>
#include "vrmine/vr_utility/objecttransformer.h"
#include "vrmine/vr_spatialobject/mine/workingplaneobject.h"
#include "vrmine/vr_geometry/geometry/workingplane.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_style/style/workingplanestyle.h"
#include "vrmine/vr_spatialrender/baserender/moveabletext.h"
//#include "vrmine/vr_projectmanager/project/projectmanager.h"
//#include "vrmine/vr_scenecontrol/geospatialscene.h"


using namespace VirtualMine::Database;
using namespace VirtualMine::Base;
using namespace VirtualMine::SpatialRender;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Style;
//using namespace VirtualMine::Scene;
//using namespace VirtualMine::Project;
using namespace VirtualMine::Geometry;


#define  WPFontsHeight 20

namespace VirtualMine
{
	namespace SpatialLayer
	{
		
		
			CWorkingplaneLayer::CWorkingplaneLayer()
			{
				this->mType = VirtualMine::Core::GeoDataType::GDT_WORKINGPLANE;
			}
			CWorkingplaneLayer::~CWorkingplaneLayer()
			{

			}
			void CWorkingplaneLayer::update()
			{

			}
			void CWorkingplaneLayer::initialise()
			{
			    ///哪里给ref_mpDataSet 赋值？
				if (NULL == this->ref_mpDataSet)
					return;

				this->ref_mpGeoSceneManager = this->getScene()->getGeoSceneManager();
				CWorkplaneRenderableObject* pRenderableObject(NULL);
				
				int featureCount = this->ref_mpDataSet->getCount();//需要数据库引擎提供接口
				for (int i = 0 ; i < featureCount; ++i)
				{
					IFeature* pFeature = this->ref_mpDataSet->getFeature(i);
					VirtualMine::SpatialInterface::IGeoObject* pGeoObject = new VirtualMine::Mine::CWorkingplaneObject();
					pGeoObject->fromFeature(pFeature);

					////根据name写字体
					void* data =  pFeature->getPropertySet()->getFields().at(1).getVarient().data();
					char* name = (char*)data;
					Ogre::String workingplaneName = name;
					int count = dynamic_cast<CWorkingplaneGeometry*>(pGeoObject->getGeometry())->getCount();
					CPoint centerPoint;
					for (int i = 0; i < count; i++)
					{
						 CPoint tmp =  dynamic_cast<CWorkingplaneGeometry*>(pGeoObject->getGeometry())->getPoint(i);
						 centerPoint.setX(centerPoint.getX() + tmp.getX());
						 centerPoint.setY(centerPoint.getY() + tmp.getY());
						 centerPoint.setZ(centerPoint.getZ() + tmp.getZ());
					}

					centerPoint.setX(centerPoint.getX() / count);
					centerPoint.setY(centerPoint.getY() / count + WPFontsHeight);
					centerPoint.setZ(centerPoint.getZ() / count);
			
					Ogre::Vector3 workingplaneCenter(centerPoint.getX(),centerPoint.getY(),centerPoint.getZ()*(-1));

#if 1 //挂接字体

					//Ogre::UTFString str(L"abx");

					//////////////////////////////////////////////////////////////////////////
					int iWLen = MultiByteToWideChar( CP_ACP, 0, workingplaneName.c_str(), workingplaneName.size(), 0, 0 ); // 计算转换后宽字符串的长度。（不包含字符串结束符）  
					wchar_t *lpwsz = new wchar_t [iWLen + 1];  
					MultiByteToWideChar( CP_ACP, 0, workingplaneName.c_str(), workingplaneName.size(), lpwsz, iWLen ); // 正式转换。  
					lpwsz[iWLen] = L'\0';   
					Ogre::DisplayString disName(lpwsz);

					//////////////////////////////////////////////////////////////////////////
					VirtualMine::BaseRender::MovableText* pText = new VirtualMine::BaseRender::MovableText(workingplaneName,
						                                          Ogre::DisplayString(disName),Ogre::String("SimHei"),15,Ogre::ColourValue(1,0,0,1));

					pText->setTextAlignment(VirtualMine::BaseRender::MovableText::H_CENTER,VirtualMine::BaseRender::MovableText::V_CENTER);

					//Ogre::SceneManager* pSceneManager = this->ui.vRControl->getGeoSpatialControl()->getGeoSceneManager();
					if (this->ref_mpGeoSceneManager)
					{
						Ogre::SceneNode* pNode = this->ref_mpGeoSceneManager->getRootSceneNode()->createChildSceneNode(workingplaneCenter);
						pNode->attachObject(pText);
						this->mTextNodes.push_back(pNode);
					}				 							
					this->mNeedLabel = true;
					//this->mpCameraListener->ref_mpObject = pText;
#endif
				

					if(NULL == pRenderableObject)
						pRenderableObject = new  CWorkplaneRenderableObject();

					pRenderableObject->addGeoObject(pGeoObject);

					
				}
				if (pRenderableObject)
				{
					if(NULL != this->mpRenderableObject)
					{
						this->mpRenderableObject->deRender();
						SAFE_DELETE(this->mpRenderableObject);
					}
					pRenderableObject->setGeoSceneManager(this->ref_mpGeoSceneManager);
					pRenderableObject->build();

					pRenderableObject->setNode(this->ref_mpGeoSceneManager->createSceneNode());
					this->mpRenderableObject = pRenderableObject;
				}
				CSceneLayer::initialise();
			}
			void CWorkingplaneLayer::notifyUpdate()
			{
				CSceneLayer::notifyUpdate();
			}
			void CWorkingplaneLayer::setStyle(VirtualMine::SpatialInterface::IStyle* pStyle)
			{

			}
			void CWorkingplaneLayer::setWorkingplaneState(const VirtualMine::Style::CWorkingplaneStyle& workingplaneState)
			{
				CWorkplaneRenderableObject* pRenderableObject = dynamic_cast<CWorkplaneRenderableObject*>(this->mpRenderableObject);
				GeoExtentionDataVector geoDatas;
				pRenderableObject->getGeoExtentionDatas(geoDatas);
				if (geoDatas.size() > 0)
				{
					GeoExtentionDataVector::iterator bItr = geoDatas.begin();
					GeoExtentionDataVector::iterator eItr = geoDatas.end();
					while (bItr != eItr)
					{
						Ogre::ManualObject* pRenderObject = (*bItr)->getExtentionData();
						if (pRenderObject)
						{
						    ///name of material
							std::string matName = "workingplaneMaterial";				
							Ogre::MaterialPtr matPtr = Ogre::MaterialManager::getSingletonPtr()->getByName(matName,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
							if (!matPtr.isNull()
								&& !matPtr->isLoaded())
							{
								matPtr->load();
							}
							for (size_t i = 0; i < pRenderObject->getNumSections();++i)
							{
								pRenderObject->setMaterialName(i,matName,
									VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
							}
						}
						++bItr;
					}
				}
			}
		
	}
}