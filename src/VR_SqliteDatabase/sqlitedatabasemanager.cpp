#include "vrmine\vr_sqlitedatabase\sqlitedatabase\sqlitedatabasemanager.h"
#include "sqlite3/sqlite3.h"
#include "vrmine/vr_sqlitedatabase/sqlitedatabase/sqlitedatabase.h"
#include <iostream>  
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_databaseengine/database/lanewaydataset.h"
#include "vrmine/vr_databaseengine/database/lanewayfeature.h"
#include "vrmine/vr_databaseengine/database/drillingdataset.h"
#include "vrmine/vr_databaseengine/database/drillingfeature.h"
#include "vrmine/vr_databaseengine/database/logicdataset.h"
#include "vrmine/vr_databaseengine/database/logicfeature.h"
#include "vrmine/vr_databaseengine/database/imagedataset.h"
#include "vrmine/vr_databaseengine/database/imagefeature.h"
#include "vrmine/vr_databaseengine/database/demdataset.h"
#include "vrmine/vr_databaseengine/database/demfeature.h"
#include "vrmine/vr_databaseengine/database/faultlayerfeature.h"
#include "vrmine/vr_databaseengine/database/faultlayerdataset.h"

using namespace VirtualMine::Database;
using namespace VirtualMine::SQLiteDatabase;
using namespace std;

CSQLiteDatabaseManager::CSQLiteDatabaseManager()
{
	this->mpDataSource = NULL;
	this->mType = VirtualMine::Core::GeoDatabaseType::GDBT_SQLITE;
	
}

CSQLiteDatabaseManager::~CSQLiteDatabaseManager()
{
	if (mpDataSource != NULL)
	{
		delete mpDataSource;
		mpDataSource = NULL;
	}
}  

//sqlite3* CSQLiteDatabaseManager::createSQLiteDatabase(std::string pathname)
//{
//	sqlite3* db;
//	//char **results = NULL;  
//	int rc(0);
//	CSQLiteDatabase sqliteDB; 
//	sqliteDB.setSQLite3(db);
//
//	rc = sqlite3_open(pathname.c_str(),&db);
//
//	if (rc != SQLITE_OK)
//	{
//		std::cout<<"打开数据库出错"<<endl;  
//	}
//	sqlite3_close(db);
//	return db;
//
//
//}
//
//sqlite3* CSQLiteDatabaseManager::openSQLiteDatabase(std::string pathname)
//{
//	sqlite3* db;
//	//char **results = NULL;  
//	int rc(0);
//	//string filename = "D:/SqlLiteDB/demo.db";
//	rc = sqlite3_open(pathname.c_str(),&db);
//
//	if (rc != SQLITE_OK)
//	{
//		std::cout<<"打开数据库出错"<<endl;  
//	}
//	sqlite3_close(db);
//	return db;
//}


void CSQLiteDatabaseManager::createDataSource(VirtualMine::Database::IDataSourceInfo* pDataSourceInfo)
{
	assert(pDataSourceInfo);
	if (NULL == pDataSourceInfo)
	{
		return;
	}
	/*sqlite3* db;
	int rc = sqlite3_open(pDataSourceInfo->getUri().c_str(),&db);

	if (rc != SQLITE_OK)
	{
		std::cout<<"创建数据库出错"<<endl;  
	}*/
	if (this->mpDataSource == NULL)
	{
		this->mpDataSource = new CSQLiteDatabase(pDataSourceInfo);
	}
	//this->mpDataSource->setSQLite3(db);
	//sqlite3_close(db);
	/*return db;*/
}

VirtualMine::Database::IDataSource* CSQLiteDatabaseManager::getDataSource()
{
	return this->mpDataSource;
}

void CSQLiteDatabaseManager::openDataSource(VirtualMine::Database::IDataSourceInfo* pDataSourceInfo)
{
	assert(pDataSourceInfo);
	if (NULL == pDataSourceInfo)
	{
		return;
	}
	//sqlite3* db = NULL;
	//int rc = sqlite3_open(pDataSourceInfo->getUri().c_str(),&db);

	//if (rc != SQLITE_OK)
	//{
	//	std::cout<<"打开数据库出错"<<endl;  
	//}
	if (this->mpDataSource == NULL)
	{
		this->mpDataSource = new CSQLiteDatabase(pDataSourceInfo);
		
		//CLogicDataset* logicdataset = this->mpDataSource->queryLogicDataset();
		//CLanewayDataset* lanewaydataset = this->mpDataSource->queryLanewayDataset();
		//CDrillingDataset* drilldataset = this->mpDataSource->queryDrillingDataset();
		//CCoalLayerDataset* coallayerdataset = this->mpDataSource->queryCoalLayerDataset();
	 //   //CDEMDataset* demdataset = this->mpDataSource->queryDEMDataset();
		////CImageDataset* imagedataset = this->mpDataSource->queryImageDatset();
		////CFaultLayerDataset
		//this->mpDataSource->getDatasetSet()->push_back(dynamic_cast<IDataset*>(logicdataset));
		//this->mpDataSource->getDatasetSet()->push_back(dynamic_cast<IDataset*>(lanewaydataset));
		//this->mpDataSource->getDatasetSet()->push_back(dynamic_cast<IDataset*>(drilldataset));
		//this->mpDataSource->getDatasetSet()->push_back(dynamic_cast<IDataset*>(coallayerdataset));
		////this->mpDataSource->getDatasetSet()->push_back(dynamic_cast<IDataset*>(demdataset));
		////this->mpDataSource->getDatasetSet()->push_back(dynamic_cast<IDataset*>(imagedataset));



	}
	//this->mpDataSource->setSQLite3(db);
}

void CSQLiteDatabaseManager::closeDataSource()
{
	sqlite3_close(this->mpDataSource->getSQLite3());
}

void CSQLiteDatabaseManager::destroyDataSource()
{
	if (mpDataSource != NULL)
	{
		delete mpDataSource;
		mpDataSource = NULL;
	}
}


void CSQLiteDatabaseManager::transformDBAtoDBB(CSQLiteDatabase* dba,CSQLiteDatabase* dbb)
{
	if (dbb)
	{
		if (dba)
		{
			IDataset *modeldataset =  dba->getDataset("GroundModelDataset");
			
			if (modeldataset)
			{
				int count = modeldataset->getCount();
				for (int i = 0; i < count; i++)
				{
					IFeature *feature = modeldataset->getFeature(i);
					dbb->insertModelFeatureToModelDataset(feature,"GroundModelDataset");
				}
				   
			}


			IDataset *locationdataset =  dba->getDataset("LocationDataset");
			
			if (locationdataset)
			{
				int count = locationdataset->getCount();
				for (int i = 0; i < count; i++)
				{
					IFeature *feature = locationdataset->getFeature(i);
					dbb->insertModelFeatureToModelDataset(feature,"LocationDataset");
				}
				   
			}


			IDataset *modeldatset2 = dba->getDataset("ModelDataset");
			if (modeldatset2)
			{
				int count = modeldatset2->getCount();
				for (int i = 0; i < count; i++)
				{
					CModelFeature *feature = dynamic_cast<CModelFeature*>(modeldatset2->getFeature(i));
					dbb->insertModelFeatureToModelDataset(feature);
				}

			}

			IDataset *workingplaneDataset = dba->getDataset("WorkingplaneDataset");
			if (workingplaneDataset)
			{
				int count = workingplaneDataset->getCount();
				for (int i = 0;i<count; i++)
				{
					CWorkingplaneFeature* feature = dynamic_cast<CWorkingplaneFeature*>(workingplaneDataset->getFeature(i));
					dbb->insertWorkingplaneFeatureToWorkingPlaneDataset(feature);
				}
			}

			//IDataset *modeldatset3 = dba->getDataset("LanewayDataset");
			//if (modeldatset3)
			//{
			//	int count = modeldatset3->getCount();
			//	for (int i = 0; i < count; i++)
			//	{
			//		CModelFeature *feature = dynamic_cast<CModelFeature*>(modeldatset3->getFeature(i));
			//		dbb->insertModelFeatureToModelDataset(feature);
			//	}

			//}

			//IDataset *modeldatset4 = dba->getDataset("DEMDataset");
			//if (modeldatset2)
			//{
			//	int count = modeldatset2->getCount();
			//	for (int i = 0; i < count; i++)
			//	{
			//		CModelFeature *feature = dynamic_cast<CModelFeature*>(modeldatset2->getFeature(i));
			//		dbb->insertModelFeatureToModelDataset(feature);
			//	}

			//}

			//		IDataset *modeldatset2 = dba->getDataset("ModelDataset");
			//if (modeldatset2)
			//{
			//	int count = modeldatset2->getCount();
			//	for (int i = 0; i < count; i++)
			//	{
			//		CModelFeature *feature = dynamic_cast<CModelFeature*>(modeldatset2->getFeature(i));
			//		dbb->insertModelFeatureToModelDataset(feature);
			//	}

			//}

			IDataset *modeldatset6 = dba->getDataset("DrillingDataset");
			if (modeldatset6)
			{
				int count = modeldatset6->getCount();
				for (int i = 0; i < count; i++)
				{
					CDrillingFeature *feature = dynamic_cast<CDrillingFeature*>(modeldatset6->getFeature(i));
					dbb->insertDrillingFeatureToDrillingDataset(feature);
				}

			}

			IDataset *modeldatset7 = dba->getDataset("LanewayDataset");
			if (modeldatset7)
			{
				int count = modeldatset7->getCount();
				for (int i = 0; i < count; i++)
				{
					CLanewayFeature *feature = dynamic_cast<CLanewayFeature*>(modeldatset7->getFeature(i));
					dbb->insertLanewayFeatureToLanewayDataset(feature);
				}

			}










		
		}
	}
}