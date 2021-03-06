//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : coallayerfeature.h
//  @ Date : 2015/7/30
//  @ Author : 王凯
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 



#if !defined(_BAGNSQLITEDATABASE_)
#define _BAGNSQLITEDATABASE_

#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/field.h"
#include "bang/rocklayerconfig.h"
#include "vrmine/vr_databaseengine/database/propertyset.h"
#include "vrmine/vr_sqlitedatabase/sqlitedatabase/sqlitedatabase.h"

#include "bang/lanewaysectionfeature.h"
#include "bang/projectfeature.h"
#include "bang/shotholefeature.h"
#include "bang/lanewaysectiondataset.h"
#include "bang/projectdataset.h"
#include "bang/shotholedataset.h"
#include "bang/escaperoutedataset.h"
#include "bang/escaperoutefeature.h"
//kk
#include "bang/conprogressdataset.h"
#include "bang/conprogressfeature.h"

namespace VirtualMine
{
	namespace Bang_Database
	{
		class VR_BANG_DATABASEENGINE_DLL CBangSqliteDatabase : public VirtualMine::SQLiteDatabase::CSQLiteDatabase
		{
		public:
			CBangSqliteDatabase(VirtualMine::Database::IDataSourceInfo* pDataSourceInfo); 

			~CBangSqliteDatabase();  


#if 1
			/////////爆破系统
			int createLanewSectionDataset(const std::string& tableName);
			int createShotHoleDataset(const std::string& tableName);
			int createProjectFileDataset(const std::string& tableName);
			int createEsacpeRouteDataset(const std::string& tableName);

			int insertLanewaySectionFeatureToLanewaySectionDataset( VirtualMine::Database::IFeature* feature,std::string datasetName);
			int insertShotHoleFeatureToShotHoleDataset( VirtualMine::Database::IFeature* feature,std::string datasetName);
			int insertProjectFileFeatureToProjectFileDataset( VirtualMine::Database::IFeature* feature,std::string datasetName);
			int insertEscapeRouteFeatureToEscapeRouteDataset( VirtualMine::Database::IFeature* feature,std::string datasetName);
			//kk施工进度
			int insertConProgressFeatureToConProgressDataset( VirtualMine::Database::IFeature* feature,std::string datasetName );
			
			VirtualMine::Bang_Database::CLanewaySectionDataset* queryLanewaySectionDataset(const std::string& datesetName);
			VirtualMine::Bang_Database::CLanewaySectionFeature* queryLanewaySectionDataset(const std::string& datesetName,const int& peojectID ,const std::string& featureName);

			VirtualMine::Bang_Database::CProjectFileDataset* queryProjectFileDataset(const std::string& datesetName);
			VirtualMine::Bang_Database::CProjectFileFeature* queryProjectFileDataset(const std::string& datesetName,const int& proID);

			VirtualMine::Bang_Database::CShotHoleDataset* queryShotHoleDataset(const std::string& datesetName);
			VirtualMine::Bang_Database::CShotHoleFeature* queryShotHoleDataset(const std::string& datesetName,const int& proId,const int& holeId);

			VirtualMine::Bang_Database::CEscapeRouteDataset* queryEscapeRouteDataset(const std::string& datesetName);
			VirtualMine::Bang_Database::CEscapeRouteFeature* queryEscapeRouteDataset(const std::string& datesetName,const int& proId,const int& pointId);

			//kk
			VirtualMine::Bang_Database::CConProgressDataset* queryConProgressDataset(const std::string& datesetName);
			VirtualMine::Bang_Database::CConProgressFeature* queryConProgressDataset(const std::string& datesetName,const int& proId,const int& pointId);

			VirtualMine::Database::IDataset*  getDatasetByProjectID(const std::string& datesetType,const int& proId);

#endif	

		};
	}
}

#endif //