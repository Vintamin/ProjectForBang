#include "vrmine/vr_maplayer/bangprojectmanager.h"
#include "vrmine/vr_sqlitedatabase/sqlitedatabase/sqlitedatabasemanager.h"
#include "vrmine/vr_databaseengine/database/idatasource.h"
//#include "bang/bangsqlitedatabase.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_spatiallayer/layerfactory.h"
#include "vrmine/vr_spatialinterface/ilayer.h"
#include "vrmine/vr_spatialinterface/event/eventobject.h"
#include "vrmine/vr_maplayer/map.h"
//kk
//#include "vrmine/vr_spatiallayer/scenelayer.h"


using namespace VirtualMine::Core;
using namespace VirtualMine::SQLiteDatabase;
using namespace VirtualMine::Database;
using namespace VirtualMine::SpatialLayer;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Map;

namespace VirtualMine
{
	namespace Project
	{
		class CBangProjectManager_Private
		{
		public:
			CBangProjectManager_Private()
			{
				ref_mMap = NULL;
				ref_mpGeoScene = NULL;
				ref_mpDataSource = NULL;
			}

			~CBangProjectManager_Private()
			{

			}

		public:
			VirtualMine::Map::CMap* ref_mMap;
			VirtualMine::SpatialInterface::IScene* ref_mpGeoScene;
			//VirtualMine::SQLiteDatabase::CSQLiteDatabase* ref_mpDataSource;
			VirtualMine::Bang_Database::CBangSqliteDatabase* ref_mpDataSource;
		};

		CBangProjectManager* CBangProjectManager::mpSingletonPtr = NULL;

		CBangProjectManager::CBangProjectManager()
		{
			this->loadnum = 0;
			this->mpPrivate = new CBangProjectManager_Private();
		}


		CBangProjectManager::~CBangProjectManager()
		{
		}
		CBangProjectManager* CBangProjectManager::getSingletonPtr()
		{
			if (NULL == mpSingletonPtr)
				mpSingletonPtr = new CBangProjectManager();
			return mpSingletonPtr;
		}
		CBangProjectManager& CBangProjectManager::getSingleton()
		{
			if (NULL == mpSingletonPtr)
				mpSingletonPtr = new CBangProjectManager();
			return *mpSingletonPtr;
		}

		void CBangProjectManager::setDataSource(VirtualMine::Database::IDataSource* ref_pDataSource)
		{
			this->mpPrivate->ref_mpDataSource = (VirtualMine::Bang_Database::CBangSqliteDatabase*)ref_pDataSource;
		}
		//kk��ȡ���ݼ�
		VirtualMine::Bang_Database::CBangSqliteDatabase* CBangProjectManager::getDataSource()
		{
			return (VirtualMine::Bang_Database::CBangSqliteDatabase*)this->mpPrivate->ref_mpDataSource;
		}
		
		void CBangProjectManager::setMap(VirtualMine::Map::CMap* ref_pMap)
		{
			this->mpPrivate->ref_mMap = ref_pMap;
		}
		//kk
		VirtualMine::Map::CMap* CBangProjectManager::getMap()
		{
			return this->mpPrivate->ref_mMap;
		}

		void CBangProjectManager::setScene(VirtualMine::SpatialInterface::IScene* ref_pGeoScene)
		{
			this->mpPrivate->ref_mpGeoScene = ref_pGeoScene;
		}

		bool CBangProjectManager::loadData(const std::string& type,const int& projectID)
		{
			bool r = false;
			if (this->mpPrivate->ref_mMap
				&& this->mpPrivate->ref_mpGeoScene
				&& this->mpPrivate->ref_mpDataSource)
			{
				CLayerFactory* pFactory = dynamic_cast<CLayerFactory*>(CLayerFactoryRegister::getSingletonPtr()->getFactory(type));
				if (pFactory)
				{
					IDataset* pDataSet = this->mpPrivate->ref_mpDataSource->getDatasetByProjectID(type,projectID);
					//������άͼ��
					//CSceneLayer* p2DLayer = (CSceneLayer*)this->mpPrivate->ref_mMap->addLayer(type);
					//������άͼ��
					CSceneLayer* p3DLayer = (CSceneLayer*)this->mpPrivate->ref_mpGeoScene->createLayer(pDataSet->getName(),type);
					p3DLayer->setDataSet(pDataSet);	
					p3DLayer->setDatasource(this->mpPrivate->ref_mpDataSource);

					//kk���ݲ�ͬ���͸�����ͬ���͵�ͼ��
					CSceneLayer* p2DLayer;
					if (type == "GDT_TERRANE_TYPE")
					{
						TerraneDataSet = pDataSet;
						p2DLayerTerrane =this->mpPrivate->ref_mMap->addLayer(type);
						p2DLayer=(CSceneLayer*)p2DLayerTerrane;
						p3DTerraneLayer = p3DLayer;
						std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!������ʯ����"<<std::endl;
					}else if(type == "GDT_SHOTHOLE_TYPE"){
						ShotholeDataSet = pDataSet;
						p2DLayerShothole=this->mpPrivate->ref_mMap->addLayer(type);
						p2DLayer=(CSceneLayer*)p2DLayerShothole;//��CMap2DLayer����ת����CSceneLayer���͡�
						p3DShotholeLayer = p3DLayer;
						std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!������������"<<std::endl;
					}else if(type == "GDT_LANEWAYSECTION_TYPE"){
						LanwaysectionDataSet = pDataSet;
						p2DLayerLanway =this->mpPrivate->ref_mMap->addLayer(type);
						p2DLayer=(CSceneLayer*)p2DLayerLanway;
						p3DLanwayLayer = p3DLayer;
						std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!�����������"<<std::endl;
					}else if(type == "GDT_ESCAPEROUTE_TYPE"){
						EscapeDataSet = pDataSet;
						p2DLayerEscape = this->mpPrivate->ref_mMap->addLayer(type);
						p2DLayer=(CSceneLayer*)p2DLayerEscape;
						p3DEscapeLayer = p3DLayer;
						std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!���Ǳ���·������"<<std::endl;
					}else if(type == "GDT_CONORGANIZATION_TYPE"){
						p2DLayerConOrg = this->mpPrivate->ref_mMap->addLayer(type);
						p2DLayer=(CSceneLayer*)p2DLayerConOrg;
						p3DConOrgLayer = p3DLayer;
						std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!����ʩ����֯����"<<std::endl;
					}else if(type == "GDT_CONPROGRESS_TYPE"){
						ConprogressDataSet = pDataSet;
						p2DLayerConProgress = this->mpPrivate->ref_mMap->addLayer(type);
						p2DLayer=(CSceneLayer*)p2DLayerConProgress;
						p3DConProgressLayer = p3DLayer;
						std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!����ʩ����������"<<std::endl;
					}


				   if (p2DLayer)
				   {
					   //����������Դ
					   p2DLayer->setDataSet(pDataSet);
					   //kk�����������,���Ƶ����
					   p2DLayer->initialise();
				   }
					
					
					
					
					//kk����ǵ�һ�μ��ع��̲ŵ�������ĺ��������س�����ߵ�treewidget
					if (this->loadnum == 1)
					{
						//�������ݼ�����Ϣ
						VirtualMine::Map::CBangLayerLoadEvent layerLoadevt;
						layerLoadevt.set2DLayer(p2DLayer);
						layerLoadevt.set3DLayer(p3DLayer);
						VirtualMine::Core::CEventDispatcher::setEvent(&layerLoadevt);
					}
					

					//����������Ⱦ��Ϣ
					/*CLayerRenderEvent layerRenderEvt;
					layerRenderEvt.setLayer(p2DLayer);
					CEventDispatcher::setEvent(&layerRenderEvt);

					layerRenderEvt.setLayer(p3DLayer);
					CEventDispatcher::setEvent(&layerRenderEvt);*/
					CRefreshMapEvent refreshMapEvt;
					//kk�����������
					CEventDispatcher::setEvent(&refreshMapEvt);
					//kk
					p3DLayer->initialise();

					p3DLayer->draw();



					//����ǵ��λ����·�߾�ֻ��ʾ��ά����
					if (p3DLayer->getType() == VirtualMine::Core::GeoDataType::GDT_TERRANE
						||p3DLayer->getType() == VirtualMine::Core::GeoDataType::GDT_ESCAPEROUTE
						||p3DLayer->getType() == VirtualMine::Core::GeoDataType::GDT_CONORGANIZATION
						||p3DLayer->getType() == VirtualMine::Core::GeoDataType::GDT_CONPROGRESS
						)                                                                                                                                        
					{
						p3DLayer->setVisible(false);
						std::vector<Ogre::SceneNode*> pTextNodes = dynamic_cast<CSceneLayer*>(p3DLayer)->getTextNodes();
					    if (pTextNodes.size() > 0)
					    {
							for (int i = 0; i < pTextNodes.size(); i++)
							{
								pTextNodes.at(i)->setVisible(false);
							}
					    }
					}
				}
			}
			return r;
		}

		bool CBangProjectManager::loadProject(const int& projectID)
		{
			this->loadnum++;
			bool r = false;		
			r |= this->loadData(VirtualMine::Core::GeoDataType::GDT_TERRANE,projectID);
			//kk�����������
			r |= this->loadData(VirtualMine::Core::GeoDataType::GDT_SHOTHOLE,projectID);
			r |= this->loadData(VirtualMine::Core::GeoDataType::GDT_LANEWAYSECTION,projectID);
				//r |= this->loadData(VirtualMine::Core::GeoDataType::GDT_LANWAY,projectID);
			r |= this->loadData(VirtualMine::Core::GeoDataType::GDT_ESCAPEROUTE,projectID);
			//kkʩ����֯
			r |= this->loadData(VirtualMine::Core::GeoDataType::GDT_CONORGANIZATION,projectID);
			//kkʩ������
			r |= this->loadData(VirtualMine::Core::GeoDataType::GDT_CONPROGRESS,projectID);	
			return r;
		}

	}}