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
			//kk函数获取数据集
			virtual VirtualMine::Bang_Database::CBangSqliteDatabase* getDataSource();
			//kk获取对应类型的数据集
			VirtualMine::Database::IDataset* TerraneDataSet;
			VirtualMine::Database::IDataset* ShotholeDataSet;
			VirtualMine::Database::IDataset* LanwaysectionDataSet;
			VirtualMine::Database::IDataset* EscapeDataSet;
			VirtualMine::Database::IDataset* ConprogressDataSet;
			//kk添加对应的三维图层成员变量
			VirtualMine::SpatialLayer::CSceneLayer* p3DTerraneLayer;
			VirtualMine::SpatialLayer::CSceneLayer* p3DShotholeLayer;
			VirtualMine::SpatialLayer::CSceneLayer* p3DLanwayLayer;
			VirtualMine::SpatialLayer::CSceneLayer* p3DEscapeLayer;
			VirtualMine::SpatialLayer::CSceneLayer* p3DConOrgLayer;
			VirtualMine::SpatialLayer::CSceneLayer* p3DConProgressLayer;
			//kk添加对应的二维图层成员变量
			//kk岩石图层
			VirtualMine::Map::CMap2DLayer* p2DLayerTerrane;
			//VirtualMine::SpatialLayer::CSceneLayer* p2DLayerTerrane;
			//kk炮眼图层
			VirtualMine::Map::CMap2DLayer* p2DLayerShothole;
			//VirtualMine::SpatialLayer::CSceneLayer* p2DLayerShothole;
			//kk巷道图层
			VirtualMine::Map::CMap2DLayer* p2DLayerLanway;
			//VirtualMine::SpatialLayer::CSceneLayer* p2DLayerLanway;
			//kk避难路线图层
			VirtualMine::Map::CMap2DLayer* p2DLayerEscape;
			//VirtualMine::SpatialLayer::CSceneLayer* p2DLayerEscape;
			//kk施工组织图层
			VirtualMine::Map::CMap2DLayer* p2DLayerConOrg;
			//VirtualMine::SpatialLayer::CSceneLayer* p2DLayerConOrg;
			//kk施工进度图层
			VirtualMine::Map::CMap2DLayer* p2DLayerConProgress;
			//VirtualMine::SpatialLayer::CSceneLayer* p2DLayerConProgress;
			//kk获得map
			VirtualMine::Map::CMap* getMap();
			//kk加载工程的次数
			int loadnum;
		private:
			//kk原始代码
			CBangProjectManager_Private* mpPrivate;
			static CBangProjectManager* mpSingletonPtr;
			
		};

	}}
#endif