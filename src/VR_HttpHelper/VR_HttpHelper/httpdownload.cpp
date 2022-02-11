#include "vrmine/vr_httphelper/httpdownload.h"
#include <QFile>
#include "vrmine/vr_httphelper/vr_httphelper.h"

namespace VirtualMine
{
	namespace HttpHelper
	{
		CHttpDownload::CHttpDownload()
		{

		}

		CHttpDownload::~CHttpDownload()
		{

		}

		void CHttpDownload::readUrl(const QString& url)
		{
			reply = qnam.get(QNetworkRequest(QUrl(url)));
			connect(reply, SIGNAL(readyRead()),
				this, SLOT(httpReadyRead()));
		}

		void CHttpDownload::httpReadyRead()
		{
			this->mByteArray = reply->readAll();
			CFinishedDownloadEvent evt;
			evt.setDownloadData(&this->mByteArray);
			VirtualMine::Core::CEventDispatcher::setEvent(&evt);
		} 

		 VirtualMine::Core::DeviceKind  CurrentDeviceType = VirtualMine::Core::DeviceKind::DK_UNKNOWN;
		 std::string SwitchSubstationID("");
		 std::string SwitchSensorID("");
		 std::string SimuSubstationID("");
		 std::string SimuSensorID("");

		void CCurrentDevice::refresh()
		{
			CCurrentDevice::CurrentDeviceType = VirtualMine::Core::DeviceKind::DK_UNKNOWN;
			CCurrentDevice::SwitchSubstationID = "";
			CCurrentDevice::SwitchSensorID= "";
			CCurrentDevice::SimuSubstationID= "";
			CCurrentDevice::SimuSensorID= "";
		}
	}
}

