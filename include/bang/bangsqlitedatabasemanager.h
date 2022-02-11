//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : sqlitedatabasemanager.h
//  @ Date : 2015/8/16
//  @ Author : 王凯
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_BANGSQLITEDATABASEMANAGER_H)
#define _BANGSQLITEDATABASEMANAGER_H


//#include "vrmine\vr_databaseengine\database\idatasourcemanager.h"
#include "vrmine\vr_databaseengine\database\databasemanager.h"
#include "bang/rocklayerconfig.h"
#include <string>
#include "sqlite3/sqlite3.h"
#include "vrmine/vr_sqlitedatabase/sqlitedatabase/sqlitedatabase.h"
#include "bang/bangsqlitedatabase.h"

namespace VirtualMine
{
	namespace Bang_Database
	{
		class VR_BANG_DATABASEENGINE_DLL CBangSQLiteDatabaseManager : public VirtualMine::Database::CDatabaseManager
		{
		public:

			CBangSQLiteDatabaseManager();

			~CBangSQLiteDatabaseManager();   

			void createDataSource(VirtualMine::Database::IDataSourceInfo* pDataSourceInfo);

			VirtualMine::Database::IDataSource* getDataSource();

			void openDataSource(VirtualMine::Database::IDataSourceInfo* pDataSourceInfo); 

			void closeDataSource();

			void destroyDataSource(); 

			///将一个数据库复制进另一个数据库

			//void transformDBAtoDBB(CSQLiteDatabase* dba,CSQLiteDatabase* dbb);

			//void getSigleton();

		private:

			VirtualMine::Bang_Database::CBangSqliteDatabase* mpDataSource;

		};
	}
}

#endif  //_BANgSQLITEDATABASEMANAGER_H
