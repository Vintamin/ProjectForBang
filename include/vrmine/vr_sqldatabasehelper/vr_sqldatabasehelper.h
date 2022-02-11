#ifndef _VR_SQLDATABASEHELPER_H
#define _VR_SQLDATABASEHELPER_H


#include "vrmine/vr_sqldatabasehelper/vr_sqldatabasehelperconfig.h"
#include <string>
#include <QtCore/QtCore>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDomDocument>
#include <QDomComment>

#include <QFile>
#include <QtNetwork/QHttp>
#include <QUrl>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
namespace VirtualMine
{
	namespace DataBaseManager
	{
		class VR_SQLDBHELPER_DLL CDataBaseManager
		{
		public:
			CDataBaseManager();
			~CDataBaseManager();
		public:
			static CDataBaseManager& getSingleton();
			static CDataBaseManager* getSingletonPtr();

			void parseDatabaseConfig(const std::string& filePath);
			void saveDatabaseConfig(const std::string& filePath);
			bool connect(const std::string& dsn,const std::string& username,const std::string& password);
			void setConfig(const std::string& dsn,const std::string& username,const std::string& password);
			void disconnect();
			QSqlQuery execSqlString(const std::string& sql);
		private:
			static CDataBaseManager* mpSingletonPtr;
			QSqlDatabase mDatabase;

			bool mIsConnected;
			bool mIsConfiged;

			std::string mDsn;
			std::string mUserName;
			std::string mPassword;
		};
	}
}

#endif //_VR_SQLDATABASEHELPER_H