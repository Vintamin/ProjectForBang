#include "bang/bangsqlitedatabasemanager.h"


VirtualMine::Bang_Database::CBangSQLiteDatabaseManager::CBangSQLiteDatabaseManager()
{
	this->mpDataSource = NULL;
	this->mType = VirtualMine::Core::GeoDatabaseType::GDBT_SQLITE;
}

VirtualMine::Bang_Database::CBangSQLiteDatabaseManager::~CBangSQLiteDatabaseManager()
{
	if (!mpDataSource)
	{
		delete mpDataSource;
		mpDataSource = NULL;
	}
}

void VirtualMine::Bang_Database::CBangSQLiteDatabaseManager::createDataSource( VirtualMine::Database::IDataSourceInfo* pDataSourceInfo )
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
		this->mpDataSource = new CBangSqliteDatabase(pDataSourceInfo);
	}
}

VirtualMine::Database::IDataSource* VirtualMine::Bang_Database::CBangSQLiteDatabaseManager::getDataSource()
{
	return this->mpDataSource;
}

void VirtualMine::Bang_Database::CBangSQLiteDatabaseManager::openDataSource( VirtualMine::Database::IDataSourceInfo* pDataSourceInfo )
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
		this->mpDataSource = new CBangSqliteDatabase(pDataSourceInfo);
	}
}

void VirtualMine::Bang_Database::CBangSQLiteDatabaseManager::closeDataSource()
{
	sqlite3_close(this->mpDataSource->getSQLite3());
}

void VirtualMine::Bang_Database::CBangSQLiteDatabaseManager::destroyDataSource()
{
	if (!mpDataSource)
	{
		delete mpDataSource;
		mpDataSource = NULL;
	}
}
