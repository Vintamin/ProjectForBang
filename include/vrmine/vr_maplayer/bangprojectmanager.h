#ifndef _BANGPROJECTMANANGER_H
#define _BANGPROJECTMANANGER_H

#include "vrmine/vr_maplayer/vr_maplayer_global.h"
#include "vrmine/vr_maplayer/map.h"
#include "vrmine/vr_spatialinterface/iscene.h"
#include "vrmine/vr_databaseengine/database/idatasource.h"
//kk
#include "bang/bangsqlitedatabase.h"
#include "vrmine/vr_databaseengine/database/idataset.h"
#include "vrmine/vr_spatiallayer/scenelayer.h"
namespace VirtualMine
{
	namespace Project
	{
		class CBangProjectManager_Private;
		class VR_MAPLAYER_EXPORT CBangProjectManager
		{
		public:
			CBangProjectManager();
			virtual ~CBangProjectManager();
			static CBangProjectManager* getSingletonPtr();
			static CBangProjectManager& getSingleton();
			virtual void setMap(VirtualMine::Map::CMap* ref_pMap);
			virtual void setScene(VirtualMine::SpatialInterface::IScene* ref_pGeoScene);
			virtual void setDataSource(VirtualMine::Database::IDataSource* ref_pDataSource);
			virtual bool loadProject(const int& projectID);
			virtual bool loadData(const std::string& type,const int& projectID);
			//kk������ȡ���ݼ�
			virtual VirtualMine::Bang_Database::CBangSqliteDatabase* getDataSource();
			//kk��ȡ��Ӧ���͵����ݼ�
			VirtualMine::Database::IDataset* TerraneDataSet;
			VirtualMine::Database::IDataset* ShotholeDataSet;
			VirtualMine::Database::IDataset* LanwaysectionDataSet;
			VirtualMine::Database::IDataset* EscapeDataSet;
			VirtualMine::Database::IDataset* ConprogressDataSet;
			//kk��Ӷ�Ӧ����άͼ���Ա����
			VirtualMine::SpatialLayer::CSceneLayer* p3DTerraneLayer;
			VirtualMine::SpatialLayer::CSceneLayer* p3DShotholeLayer;
			VirtualMine::SpatialLayer::CSceneLayer* p3DLanwayLayer;
			VirtualMine::SpatialLayer::CSceneLayer* p3DEscapeLayer;
			VirtualMine::SpatialLayer::CSceneLayer* p3DConOrgLayer;
			VirtualMine::SpatialLayer::CSceneLayer* p3DConProgressLayer;
			//kk��Ӷ�Ӧ�Ķ�άͼ���Ա����
			//kk��ʯͼ��
			VirtualMine::Map::CMap2DLayer* p2DLayerTerrane;
			//VirtualMine::SpatialLayer::CSceneLayer* p2DLayerTerrane;
			//kk����ͼ��
			VirtualMine::Map::CMap2DLayer* p2DLayerShothole;
			//VirtualMine::SpatialLayer::CSceneLayer* p2DLayerShothole;
			//kk���ͼ��
			VirtualMine::Map::CMap2DLayer* p2DLayerLanway;
			//VirtualMine::SpatialLayer::CSceneLayer* p2DLayerLanway;
			//kk����·��ͼ��
			VirtualMine::Map::CMap2DLayer* p2DLayerEscape;
			//VirtualMine::SpatialLayer::CSceneLayer* p2DLayerEscape;
			//kkʩ����֯ͼ��
			VirtualMine::Map::CMap2DLayer* p2DLayerConOrg;
			//VirtualMine::SpatialLayer::CSceneLayer* p2DLayerConOrg;
			//kkʩ������ͼ��
			VirtualMine::Map::CMap2DLayer* p2DLayerConProgress;
			//VirtualMine::SpatialLayer::CSceneLayer* p2DLayerConProgress;
			//kk���map
			VirtualMine::Map::CMap* getMap();
			//kk���ع��̵Ĵ���
			int loadnum;
		private:
			//kkԭʼ����
			CBangProjectManager_Private* mpPrivate;
			static CBangProjectManager* mpSingletonPtr;
			
		};

	}}
#endif