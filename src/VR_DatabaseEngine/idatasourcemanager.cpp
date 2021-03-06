//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : idatasourcemanager.cpp
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine\vr_databaseengine\database\idatasourcemanager.h"
#include "vrmine\vr_core\coredefine.h"

using namespace std;
using namespace VirtualMine::Database;

void IDataSourceManager::createDataSource(VirtualMine::Database::IDataSourceInfo* pDataSourceInfo)
{

}

/*	void IDataSourceManager::connectDataSource()
{

}
*/
void IDataSourceManager::openDataSource(VirtualMine::Database::IDataSourceInfo* pDataSourceInfo)
{

}

void IDataSourceManager::closeDataSource()
{

}

VirtualMine::Database::IDataSource* IDataSourceManager::getDataSource()
{
	return NULL;
}

void IDataSourceManager::destroyDataSource()
{

}

void IDataSourceManager::getSigleton()
{

}

void IDataSourceManager::getSigletonPtr()
{

}

std::string IDataSourceManager::getType()
{
	std::string type;
	return type;
}

CDataSourceManagerRegister* CDataSourceManagerRegister::mpSingletonPtr(NULL);

CDataSourceManagerRegister* CDataSourceManagerRegister::getSingletonPtr()
{
	if (NULL == mpSingletonPtr)
		mpSingletonPtr = new CDataSourceManagerRegister();
	return mpSingletonPtr;
}

CDataSourceManagerRegister& CDataSourceManagerRegister::getSingleton()
{
	if (NULL == mpSingletonPtr)
		mpSingletonPtr = new CDataSourceManagerRegister();
	return *mpSingletonPtr;
}

CDataSourceManagerRegister::~CDataSourceManagerRegister()
{
	
}

bool CDataSourceManagerRegister::registerDataSourceManager(IDataSourceManager* pDataSourceManager)
{
	assert(pDataSourceManager);
	if (NULL == pDataSourceManager)
		return false;

	std::map<std::string,IDataSourceManager*>::iterator itr= this->mObjecMap.find(pDataSourceManager->getType());
	if (itr == this->mObjecMap.end())
	{
		this->mObjecMap.insert(std::pair<std::string,IDataSourceManager*>(pDataSourceManager->getType(),pDataSourceManager));
		return true;
	}
	else
	{
		throw std::exception("a same type of IDataSourceManager exsited !");
	}
	return false;
}

IDataSourceManager* CDataSourceManagerRegister::getDataSourceManager(const std::string& type)
{
	std::map<std::string,IDataSourceManager*>::iterator itr= this->mObjecMap.find(type);
	if (itr != this->mObjecMap.end())
	{
		return itr->second;
	}
	return NULL;
}

bool CDataSourceManagerRegister::destroyDataSourceManager(IDataSourceManager* pDataSourceManager)
{
	SAFE_DELETE(pDataSourceManager);
	return true;
}

CDataSourceManagerRegister::CDataSourceManagerRegister()
{

}
