#ifndef VR_HTTPHELPER_H
#define VR_HTTPHELPER_H

#include "vr_httphelper_global.h"
#include "vrmine/vr_core/event.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_core/tinyxml/tinyxml.h"
namespace VirtualMine
{
	namespace HttpHelper
	{
		class VR_HTTPHELPER_EXPORT VR_HttpHelper
		{
		public:
			VR_HttpHelper();
			~VR_HttpHelper();

		private:

		};

		class VR_HTTPHELPER_EXPORT CFinishedDownloadEvent : public VirtualMine::Core::CEvent
		{
		public:

			CFinishedDownloadEvent();
			virtual ~CFinishedDownloadEvent();
			virtual void setDownloadData(QByteArray* pData);
			virtual QByteArray* getDownloadData();

		protected:
			QByteArray* ref_mpDownloadData;
		};

		class VR_HTTPHELPER_EXPORT CCurrentDevice
		{
		public:
			static VirtualMine::Core::DeviceKind  CurrentDeviceType;
			static std::string SwitchSubstationID;
			static std::string SwitchSensorID;
			static std::string SimuSubstationID;
			static std::string SimuSensorID;

			static void refresh();

		};

		/*class VR_HTTPHELPER_EXPORT CServerConfigParam
		{
		public:
		CServerConfigParam();
		~CServerConfigParam();

		static void parseConfig(TiXmlElement* rootNode);
		static void saveConfig(TiXmlElement* rootNode);
		public:
		static std::string Driver;
		static std::string Server;
		static std::string DataBase;
		static	std::string User;
		static std::string Password;

		static std::string SimuUrl;
		static std::string SwitchUrl;
		};*/
	}
}


#endif // VR_HTTPHELPER_H
