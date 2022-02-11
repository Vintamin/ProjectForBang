#ifndef _HTTPDOWNLOAD_H
#define _HTTPDOWNLOAD_H

#include "vr_httphelper_global.h"
#include <QtCore/QtCore>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
namespace VirtualMine
{
	namespace HttpHelper
	{
		class VR_HTTPHELPER_EXPORT CHttpDownload : public QObject
		{
			Q_OBJECT
		public:
			CHttpDownload();
			~CHttpDownload();

		public:
			 void readUrl(const QString& url);

			private slots:
				void httpReadyRead();
		private:
			QUrl url;
			QNetworkAccessManager qnam;
			QNetworkReply *reply;
			QByteArray mByteArray;
		};
	}
}


#endif // _HTTPDOWNLOAD_H