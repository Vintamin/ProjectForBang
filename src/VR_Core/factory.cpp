//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : ilayer.cpp
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine\vr_core\factory.h"

namespace VirtualMine
{
	namespace Core
	{
		CFactory::CFactory()
		{
		
		}

		CFactory::~CFactory()
		{
		
		}

		/*CBaseObject* CFactory::createInstance()
		{
			throw ("a same type of factory exsited !");
		}

		std::string CFactory::getType()
		{
			throw ("a same type of factory exsited !");
		}*/

		
		//CFactoryRegister* CFactoryRegister::mpSingletonPtr(NULL);

		CFactoryRegister::CFactoryRegister()
		{
		
		}

		
		CFactoryRegister::~CFactoryRegister()
		{
		
		}

		
		/*CFactoryRegister* CFactoryRegister::getSingletonPtr()
		{
			if (NULL == mpSingletonPtr)
				mpSingletonPtr = new CFactoryRegister();
			return mpSingletonPtr;
		}

		
		CFactoryRegister& CFactoryRegister::getSingleton()
		{
			if (NULL == mpSingletonPtr)
				mpSingletonPtr = new CFactoryRegister();
			return *mpSingletonPtr;	
		}*/

		
		bool CFactoryRegister::registerFactory(CFactory* pFactory)
		{
			assert(pFactory);
			if (NULL == pFactory)
				return false;

			std::map<std::string,CFactory*>::iterator itr= this->mObjecMap.find(pFactory->getType());
			if (itr == this->mObjecMap.end())
			{
				this->mObjecMap.insert(std::pair<std::string,CFactory*>(pFactory->getType(),pFactory));
				return true;
			}
			else
			{
				throw std::exception("a same type of factory exsited !");
			}
			return false;
		}

		
		CFactory* CFactoryRegister::getFactory(const std::string& type)
		{
			std::map<std::string,CFactory*>::iterator itr= this->mObjecMap.find(type);
			if (itr != this->mObjecMap.end())
			{
				return itr->second;
			}
			return NULL;
		}

		
		bool CFactoryRegister::destroyFactory(CFactory* pFactory)
		{
			SAFE_DELETE(pFactory);
			return true;
		}
		

	}
}
