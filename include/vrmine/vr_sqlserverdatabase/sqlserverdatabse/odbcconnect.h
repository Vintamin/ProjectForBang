#if !defined(_SQLSERVERDATASOURCE_H)
#define _SQLSERVERDATABASESOURCE_H

#include <stdio.h>
//#include <iostream.h>
#include <string.h>
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <odbcss.h>

#include "vrmine/vr_sqlserverdatabase/sqlserverdatabase_config.h"
#include "vrmine/vr_databaseengine/database/database.h"
#include "vrmine/vr_databaseengine/database/idatasourceinfo.h"

#define MAXBUFLEN   255 
#define MaxNameLen  20

namespace VirtualMine
{
	namespace SQLServerDatabase
	{
		class VR_SQLSERVERDATABASE_DLL CSQLServerDatasource //: public VirtualMine::Database::CDatabase
		{
		public:
			CSQLServerDatasource();
			~CSQLServerDatasource();

			void OnInitADOConn();
			bool ExecuteSQL(std::string SQLstr);
			bool openDB();
			bool openDB(std::string dbName);
			bool ExecuteSQLbyCMD(std::string SQLstr);

		
			bool createDatabase(std::string databaseName);

			///创建数据集（表）
			int createDataset(const std::string& tableName, const std::string& type);
			//int createLanewayDataset(); 
			int createLanewayDataset(const std::string& tableName);
			//int createModelDataset();
			int createModelDataset(const std::string& tableName);
			//int createCoalLayerDataset();
			int createCoalLayerDataset(const std::string& tableName);
			//int createDrillingDataset();
			int createDrillingDataset(const std::string& tableName);
			int createFaultLayerDataset(const std::string& tableName);
			//int createFaultLayerDataset();
			//int createRoadDataset();
			int createRoadDataset(const std::string& tableName);
			//int createDEMDataset();
			int createDEMDataset(const std::string& tableName);
			//int createWorkingPlaneDataset();
			int createWorkingPlaneDataset(const std::string& tableName);
			int createImageDataset(const std::string& tableName); 



			////插入数据

			int insertFeatureToDataset(VirtualMine::Database::IFeature *feature,const std::string& tableName);

			int insertLanewayFeatureToLanewayDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName);


			int insertCoalLayerFeatureToCoalLayerDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName);

			int insertDrillingFeatureToDrillingDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName);


			int insertLogicFeatureToLogicDataset(VirtualMine::Database::IFeature* logicfeature);

			int insertMetaDataFeatureToMetaDataset(VirtualMine::Database::IFeature* metadatafeature);


			int insertImageFeatureToImageDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName);





			int insertDEMFeatureToDEMDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName);

			int insertWorkingplaneFeatureToWorkingPlaneDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName);


			int insertModelFeatureToModelDataset( VirtualMine::Database::IFeature* modelfeature,std::string modeldatasetName);



		private:

			//#define SQLBINDCOL
			SQLHENV  henv;    // = SQL_NULL_HENV;//定义环境句柄
			SQLHDBC  hdbc1;   // SQL_NULL_HDBC;//定义数据库连接句柄     
			SQLHSTMT  hstmt1; // SQL_NULL_HSTMT;//定义语句句柄



		};
	}
}



#endif