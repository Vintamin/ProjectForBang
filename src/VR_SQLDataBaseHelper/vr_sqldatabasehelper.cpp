#include "vrmine/vr_sqldatabasehelper/vr_sqldatabasehelper.h"
#include <QtCore/QtCore>
#include "vrmine/vr_httphelper/httpdownload.h"
#include <QtNetwork/QHttp>
namespace VirtualMine
{	
	namespace DataBaseManager	
	{
		CDataBaseManager* CDataBaseManager::mpSingletonPtr(NULL);

		CDataBaseManager::CDataBaseManager()
			:mIsConnected(false),mIsConfiged(false)
		{
			this->mDsn = "";
			this->mUserName = "";
			this->mPassword = "";
		}

		CDataBaseManager::~CDataBaseManager()
		{
			this->disconnect();
		}

		CDataBaseManager* CDataBaseManager::getSingletonPtr()
		{
			if (mpSingletonPtr == NULL)
				mpSingletonPtr = new CDataBaseManager();
			return mpSingletonPtr;
		}

		CDataBaseManager& CDataBaseManager::getSingleton()
		{
			if (mpSingletonPtr == NULL)
				mpSingletonPtr = new CDataBaseManager();
			return *mpSingletonPtr;
		}

		void CDataBaseManager::parseDatabaseConfig(const std::string& filePath)
		{
			
		}

		void CDataBaseManager::saveDatabaseConfig(const std::string& filePath)
		{
			
		}

		void CDataBaseManager::setConfig(const std::string& dsn,const std::string& username,const std::string& password)
		{
			this->mDsn = dsn;
			this->mUserName = username;
			this->mPassword = password;
			this->mIsConfiged = true;
		}

		bool CDataBaseManager::connect(const std::string& connectStr,const std::string& username,const std::string& password)
		{
			if (this->mIsConnected)  return true;

			this->mDatabase = QSqlDatabase::addDatabase("QODBC");  
			// 注意,对于express版本数据库, 一定要加\\sqlexpress这种后缀  
			QString dsn = QString::fromStdString(connectStr);  
			this->mDatabase.setDatabaseName(dsn);  
			this->mDatabase.setUserName(QString::fromStdString(username));  
			this->mDatabase.setPassword(QString::fromStdString(password));  

			if(!this->mDatabase.open())  
			{  
				return false;  
			}  
			this->mIsConnected = true;
			return true;
		}

		void CDataBaseManager::disconnect()
		{
			if (this->mIsConnected && this->mDatabase.isOpen())
			{
				this->mDatabase.close();
				this->mIsConnected = false;
			}
		}

		QSqlQuery CDataBaseManager::execSqlString(const std::string& sql)
		{
			if (!this->mIsConfiged) return NULL;

			if (!this->mIsConnected)
			{
				if (!this->connect(this->mDsn,this->mUserName,this->mPassword))
				{
					return NULL;
				}
				
			}
			QSqlQuery query;

			if (query.exec(QString::fromStdString(sql)))
			{
				return query;
			}
			else
			{
				return NULL;
			}			
				
			return NULL;	
		}

	}
}