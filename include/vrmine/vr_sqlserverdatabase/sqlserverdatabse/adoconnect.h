#if !defined(_SQLSERVERDATABASE_H)
#define _SQLSERVERDATABASE_H

#import "c:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")


#include "vrmine/vr_sqlserverdatabase/sqlserverdatabase_config.h"
#include "vrmine/vr_databaseengine/database/database.h"
#include "vrmine/vr_databaseengine/database/idatasourceinfo.h"
//#include "stdafx.h"


namespace VirtualMine
{
	namespace SQLServerDatabase
	{
		class VR_SQLSERVERDATABASE_DLL CSQLSERVERDatabase //: public VirtualMine::Database::CDatabase
		{
		public:
			CSQLSERVERDatabase();
			~CSQLSERVERDatabase();

			void OnInitADOConn();
			bool ExecuteSQL(std::string SQLstr);
			bool openDB();
			bool openDB(std::string dbName);
			bool ExecuteSQLbyCMD(std::string SQLstr);

		    _ConnectionPtr getConnection();
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
			_ConnectionPtr m_pConnection;
			_RecordsetPtr m_pRecordset;
			std::string mDatabaseName;
			//_CommandPtr m_pCommand;
		};
	}
}



#endif //_ADOCONNECT_H
