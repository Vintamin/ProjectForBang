#ifndef _HTTPDOWNLOAD_H
#define _HTTPDOWNLOAD_H


#include "vrmine/vr_sqldatabasehelper/vr_sqldatabasehelperconfig.h"
#include <QWidget>
#include <QtCore/QtCore>
#include <QtNetwork/QHttp>
#include <QUrl>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>


namespace VirtualMine
{
	namespace Http
	{
		class VR_SQLDBHELPER_DLL HttpDownload: public QWidget
		{
		Q_OBJECT
		//public:
		//	HttpDownload();

		//	void startRequest(QUrl url);
		//	private slots:
		//		void downloadFile();
		//		void cancelDownload();
		//		void httpFinished();
		//		void httpReadyRead();
		//		void updateDataReadProgress(qint64 bytesRead, qint64 totalBytes);
		//		void enableDownloadButton();
		//		void slotAuthenticationRequired(QNetworkReply*,QAuthenticator *);
		//private:
		//	QUrl url;
		//	QNetworkAccessManager qnam;
		//	QNetworkReply *reply;
		//	QFile *file;
		//	int httpGetId;
		//	bool httpRequestAborted;
		//};
		};
	}
}


#endif  //_HTTPDOWNLOAD_H