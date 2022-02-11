#if !defined(_SQLITEDATABASE_H)
#define _SQLITEDATABASE_H

#include "sqlite3/sqlite3.h"
#include <string>
#include "vrmine/vr_databaseengine/database/database.h"
#include "vrmine/vr_databaseengine/database/lanewaydataset.h"
#include "vrmine/vr_databaseengine/database/lanewayfeature.h"
#include "vrmine/vr_databaseengine/database/modeldataset.h"
#include "vrmine/vr_databaseengine/database/modelfeature.h"
#include "vrmine/vr_databaseengine/database/coallayerdataset.h"
#include "vrmine/vr_databaseengine/database/coallayerfeature.h"
#include "vrmine/vr_databaseengine/database/drillingdataset.h"
#include "vrmine/vr_databaseengine/database/drillingfeature.h"
#include "vrmine/vr_databaseengine/database/logicdataset.h"
#include "vrmine/vr_databaseengine/database/logicfeature.h"
#include "vrmine\vr_sqlitedatabase\sqlitedatabase_config.h"
#include "vrmine\vr_databaseengine\database\metadatafeature.h"
#include "vrmine\vr_databaseengine\database\metadatadataset.h"
#include "vrmine\vr_databaseengine\database\imagefeature.h"
#include "vrmine\vr_databaseengine\database\imagedataset.h"
#include "vrmine\vr_databaseengine\database\demfeature.h"
#include "vrmine\vr_databaseengine\database\demdataset.h"
#include "vrmine\vr_databaseengine\database\faultlayerfeature.h"
#include "vrmine\vr_databaseengine\database\faultlayerdataset.h"
#include "vrmine\vr_databaseengine\database\workingplanefeature.h"
#include "vrmine\vr_databaseengine\database\workingplanedataset.h"
#include "vrmine\vr_databaseengine\database\userinfofeature.h"
#include "vrmine\vr_databaseengine\database\userinfodataset.h"
#include "vrmine/vr_databaseengine/database/terranefeature.h"
#include "vrmine/vr_databaseengine/database/terranedataset.h"


//#include "bang/lanewaysectionfeature.h"
//#include "bang/projectfeature.h"
//#include "bang/shotholefeature.h"
//#include "bang/lanewaysectiondataset.h"
//#include "bang/projectdataset.h"
//#include "bang/shotholedataset.h"
//#include "bang/escaperoutedataset.h"
//#include "bang/escaperoutefeature.h"


#include "OGRE\Ogre.h"
#include "vrmine/vr_core/geodatatype.h"

#include <Windows.h>

namespace VirtualMine
{
	namespace SQLiteDatabase
	{
		class VR_SQLITEDATABASE_DLL CSQLiteDatabase : public VirtualMine::Database::CDatabase
		{
		public:
			//CSQLiteDatabase();

			//CSQLiteDatabase(const string& name);

			CSQLiteDatabase(VirtualMine::Database::IDataSourceInfo* pDataSourceInfo);
			
			/////DEFAULT,0  
			//CSQLiteDatabase(VirtualMine::Database::IDataSourceInfo* pDataSourceInfo,int i);

		

			virtual ~CSQLiteDatabase();



			void  createDefaultTable();

			//UTF-8到GB2312的转换，UTF 包括 GB   
			static char* U2G(const char* utf8);
			
			//GB2312到UTF-8的转换
			static char* G2U(const char* gb2312);
			
		
			static WCHAR *mbcsToUnicode(const char *zFilename);
			static char *unicodeToUtf8(const WCHAR *zWideFilename);
			static WCHAR *utf8ToUnicode(const char *zFilename);
			static char *unicodeToMbcs(const WCHAR *zWideFilename);
			char *AnsiToUtf8( const char *zFilename);
			char *Utf8ToAnsi( char *zFilename);
			 


			int createMetadataDataset();

			int createUserInfoDataset();

			int createLogicDataset();

			int createDataset(const std::string& tableName, const std::string& type);

			int createLanewayDataset(); 

            int createLanewayDataset(const std::string& tableName);


			int createModelDataset();

			int createModelDataset(const std::string& tableName);


			int createCoalLayerDataset();

			int createCoalLayerDataset(const std::string& tableName);

			/////创建岩层数据集
		    virtual	int createTerraneDataset(const std::string& tableName);


			int createDrillingDataset();

			int createDrillingDataset(const std::string& tableName);


			int createFaultLayerDataset(const std::string& tableName);

			int createFaultLayerDataset();


			int createRoadDataset();

			int createRoadDataset(const std::string& tableName);


			int createDEMDataset();

			int createDEMDataset(const std::string& tableName);


            int createWorkingPlaneDataset();

			int createWorkingPlaneDataset(const std::string& tableName);


			int createImageDataset(); 

			int createImageDataset(const std::string& tableName); 




			//int insertFeatureToDataset

			 int insertFeatureToDataset(VirtualMine::Database::IFeature *feature,const std::string& dataType,const std::string& tableName);

			 int insertLanewayFeatureToLanewayDataset(VirtualMine::Database::IFeature* lanewayFeature);

	         int insertLanewayFeatureToLanewayDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName);


			 int insertCoalLayerFeatureToCoalLayerDataset(VirtualMine::Database::IFeature* coalLayerFeature);

             int insertCoalLayerFeatureToCoalLayerDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName);

			 ///插入岩层数据
			 int insertTerraneFeatureToCoalLayerDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName);


			 int insertDrillingFeatureToDrillingDataset(VirtualMine::Database::IFeature* drillingFeature);

             int insertDrillingFeatureToDrillingDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName);

			
             int insertLogicFeatureToLogicDataset(VirtualMine::Database::IFeature* logicfeature);

			 int insertMetaDataFeatureToMetaDataset(VirtualMine::Database::IFeature* metadatafeature);

			 int insertFaultLayerFeatureToFaultLayerDataset(VirtualMine::Database::IFeature* faultlayerfeature);
		
			 int insertFaultLayerFeatureToFaultLayerDataset(VirtualMine::Database::IFeature* faultlayerfeature,const std::string& tableName);


			 int insertImageFeatureToImageDataset(VirtualMine::Database::IFeature* imagefeature);

             int insertImageFeatureToImageDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName);



			 int insertDEMFeatureToDEMDataset(VirtualMine::Database::IFeature* demfeature);

			 int insertDEMFeatureToDEMDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName);

			 int insertWorkingplaneFeatureToWorkingPlaneDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName);


			int insertLanewayFeatureToLanewayDataset( VirtualMine::Database::CLanewayFeature* lanewayfeature);

			int insertLogicFeatureToLogicDataset( VirtualMine::Database::CLogicFeature* logicfeature);

            int insertCoalLayerToCoalLayerDataset( VirtualMine::Database::CCoalLayerFeature* coallayerfeature);

            int insertImageFeatureToImageDataset( VirtualMine::Database::CImageFeature* imagefeature);

            int insertMetaDataFeatureToMetaDataset( VirtualMine::Database::CMetadataFeature* metadatafeature);

			int insertDrillingFeatureToDrillingDataset( VirtualMine::Database::CDrillingFeature* drillingfeature);

			int insertFaultLayerFeatureToFaultLayerDataset( VirtualMine::Database::CFaultLayerFeature* faultlayerfeature);

			int insertDEMFeatureToDEMDataset(VirtualMine::Database::CDEMFeature* demfeature);

			int insertWorkingplaneFeatureToWorkingPlaneDataset(VirtualMine::Database::CWorkingplaneFeature* workingplanefeature);

			int insertModelFeatureToModelDataset( VirtualMine::Database::CModelFeature* modelfeature);
	
			int insertModelFeatureToModelDataset( VirtualMine::Database::IFeature* modelfeature,std::string modeldatasetName);

			///插入用户信息
			int insertUserInfoToInfoDataset(VirtualMine::Database::IFeature* modelfeature);



			VirtualMine::Database::CUserInfoDataset* queryUserInfoDataset();

			VirtualMine::Database::CLogicDataset* queryLogicDataset();
			
			VirtualMine::Database::CLanewayDataset* queryLanewayDataset();

			VirtualMine::Database::CLanewayDataset* queryLanewayDataset(const std::string& lanewayDatasetName);

			VirtualMine::Database::CLanewayFeature* queryLanewayFeature(const std::string& lanewayDatasetName,const std::string& featureName); 

		
			
			VirtualMine::Database::CDrillingDataset* queryDrillingDataset(); 

			VirtualMine::Database::CDrillingDataset* queryDrillingDataset(const std::string& datesetName);

			VirtualMine::Database::CDrillingFeature* queryDrillingFeature(const std::string& datesetName,const std::string& featureName);



         	VirtualMine::Database::CCoalLayerDataset* queryCoalLayerDataset(); 

			VirtualMine::Database::CCoalLayerDataset* queryCoalLayerDataset(const std::string& datesetName);

			VirtualMine::Database::CCoalLayerFeature* queryCoalLayerDataset(const std::string& datesetName,const std::string& featureName);

			///查询岩层数据
			VirtualMine::Database::CTerraneDataset* queryTerraneLayerDataset(const std::string& datesetName);

		
			VirtualMine::Database::CDEMDataset* queryDEMDataset();

			VirtualMine::Database::CDEMDataset* queryDEMDataset(const std::string& datesetName);

			VirtualMine::Database::CDEMFeature* queryDEMFeature(const std::string& datesetName,const std::string& featureName);




			VirtualMine::Database::CWorkingplaneDataset* queryWorkingplaneDataset();

			VirtualMine::Database::CWorkingplaneDataset* queryWorkingplaneDataset(const std::string& datesetName);

			VirtualMine::Database::CWorkingplaneFeature* queryWorkingplaneDataset(const std::string& datesetName,const std::string& featureName);

			
			VirtualMine::Database::CFaultLayerDataset* queryFaultLayerDataset(const std::string& datesetName);

			VirtualMine::Database::CFaultLayerFeature* queryFaultLayerDataset(const std::string& datesetName,const std::string& featureName);



			VirtualMine::Database::CImageDataset* queryImageDataset();

			VirtualMine::Database::CImageDataset* queryImageDataset(const std::string& datesetName);

			VirtualMine::Database::CImageFeature* queryImageDataset(const std::string& datesetName,const std::string& featureName);


			VirtualMine::Database::CModelDataset* queryModelDataset();

			VirtualMine::Database::CModelFeature* queryModelDataset(const std::string& featureName,const std::string& modeldatasetName);


			VirtualMine::Database::CModelDataset* queryModelDataset(const std::string& modeldatasetName);






            void updataDrillingFeature(VirtualMine::Database::CDrillingFeature* feature,std::string featurename);

			void updateLanewayFeature( VirtualMine::Database::CLanewayFeature* feature,std::string featurename);

			//void updateLanewayFeature(const CLanewayFeature& feature,int id);

            void updateLogicFeature(VirtualMine::Database::CLogicFeature* feature,std::string featurename);

		    void updateImageFeature(VirtualMine::Database::CImageFeature* feature,std::string featurename);

			void updateCoalLayerFeature(VirtualMine::Database::CCoalLayerFeature* feature,std::string festurename);

			void updateDEMFeature(VirtualMine::Database::CDEMFeature* feature,std::string festurename);

 	        // void updataModelFeature(VirtualMine::Database::CModelFeature* feature,std::string festurename);

			void updataModelFeature(VirtualMine::Database::IFeature* feature,std::string featurename);

			void updataModelFeature2(VirtualMine::Database::IFeature* feature,std::string featurename,std::string datasetname);

			void updateGroundModelFeature(VirtualMine::Database::CModelFeature* feature,std::string festurename);
			




			void deleteLanewayFeature(const std::string& featurename);

            void deleteLanewayFeatureAll();

			void deleteDrillingFeature(const std::string& featurename);
			
			void deleteDrillingAll();

            void deleteLogicFeature(const std::string& featurename);
    
            void deleteLogicFeatureALL();

            void deleteImageFeature(const std::string& featurename);

            void deleteImageFeatureALL();

			void deleteDEMFeature(const std::string& featurename);

			void deleteDEMFeatureALL();

			void deleteModelFeature(const std::string& featurename);

			void deleteModelFeatureALL();
			
			void deleteFaultLayerFeature(const std::string& featurename);

			void deleteFaultLayerFeatureALL();

			int deleteDBTable(const std::string& tableName);

#if 0
			/////////爆破系统
			int createLanewSectionDataset(const std::string& tableName);
		    int createShotHoleDataset(const std::string& tableName);
		    int createProjectFileDataset(const std::string& tableName);
			int createEsacpeRouteDataset(const std::string& tableName);

			int insertLanewaySectionFeatureToLanewaySectionDataset( VirtualMine::Database::IFeature* feature,std::string datasetName);
			int insertShotHoleFeatureToShotHoleDataset( VirtualMine::Database::IFeature* feature,std::string datasetName);
			int insertProjectFileFeatureToProjectFileDataset( VirtualMine::Database::IFeature* feature,std::string datasetName);
			int insertEscapeRouteFeatureToEscapeRouteDataset( VirtualMine::Database::IFeature* feature,std::string datasetName);

			VirtualMine::Bang_Database::CLanewaySectionDataset* queryLanewaySectionDataset(const std::string& datesetName);
			VirtualMine::Bang_Database::CLanewaySectionFeature* queryLanewaySectionDataset(const std::string& datesetName,const int& peojectID ,const std::string& featureName);

			VirtualMine::Bang_Database::CProjectFileDataset* queryProjectFileDataset(const std::string& datesetName);
			VirtualMine::Bang_Database::CProjectFileFeature* queryProjectFileDataset(const std::string& datesetName,const int& proID);
			
			VirtualMine::Bang_Database::CShotHoleDataset* queryShotHoleDataset(const std::string& datesetName);
			VirtualMine::Bang_Database::CShotHoleFeature* queryShotHoleDataset(const std::string& datesetName,const int& proId,const int& holeId);

			VirtualMine::Bang_Database::CEscapeRouteDataset* queryEscapeRouteDataset(const std::string& datesetName);
			VirtualMine::Bang_Database::CEscapeRouteFeature* queryEscapeRouteDataset(const std::string& datesetName,const int& proId,const int& pointId);


			VirtualMine::Database::IDataset*  getDatasetByProjectID(const std::string& datesetType,const int& proId);

#endif		 
			void initDB();

			VirtualMine::Database::IDataset* getDataset(const std::string& datasetName);
 
			std::vector<VirtualMine::Database::IDataset*>* getDatasetSet();

            void closeSQliteDatabase();

			sqlite3 * getSQLite3();

			void setSQLite3( sqlite3* sqlDB);

		

		public:
				sqlite3 *mpDB;  
			
			

		};  
	}
}

#endif //_SQLITEDATABASE_H