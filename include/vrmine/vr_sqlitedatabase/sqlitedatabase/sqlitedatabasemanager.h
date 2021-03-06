//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : sqlitedatabasemanager.h
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_SQLITEDATABASEMANAGER_H)
#define _SQLITEDATABASEMANAGER_H


//#include "vrmine\vr_databaseengine\database\idatasourcemanager.h"
#include "vrmine\vr_databaseengine\database\databasemanager.h"
#include "vrmine\vr_sqlitedatabase\sqlitedatabase_config.h"
#include <string>
#include "sqlite3/sqlite3.h"
#include "vrmine/vr_sqlitedatabase/sqlitedatabase/sqlitedatabase.h"

namespace VirtualMine
{
	namespace SQLiteDatabase
	{
		class VR_SQLITEDATABASE_DLL CSQLiteDatabaseManager : public VirtualMine::Database::CDatabaseManager
		{
		public:

			CSQLiteDatabaseManager();

			~CSQLiteDatabaseManager();   

		    void createDataSource(VirtualMine::Database::IDataSourceInfo* pDataSourceInfo);
			
		    VirtualMine::Database::IDataSource* getDataSource();

		    void openDataSource(VirtualMine::Database::IDataSourceInfo* pDataSourceInfo); 

            void closeDataSource();

            void destroyDataSource(); 

			///将一个数据库复制进另一个数据库

		   void transformDBAtoDBB(CSQLiteDatabase* dba,CSQLiteDatabase* dbb);
			
            //void getSigleton();

		private:

			CSQLiteDatabase* mpDataSource;

		};
	}
}

#endif  //_SQLITEDATABASEMANAGER_H
