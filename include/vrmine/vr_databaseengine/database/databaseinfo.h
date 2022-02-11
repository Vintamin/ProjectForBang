#if !defined(_DATABASEINFO_H)
#define _DATABASEINFO_H

#include "vrmine\vr_databaseengine\database\idatasourceinfo.h"
#include "vrmine\vr_databaseengine\database_config.h"
#include <string>

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CDatabaseInfo : public VirtualMine::Database::IDataSourceInfo
		{
		public:
			CDatabaseInfo();

			~CDatabaseInfo();

			void setDataSourceType(const std::string& type);

			std::string getDataSourceType();

			void setUri(const std::string& uri);

			std::string getUri();

		private:
			std::string mType;
			std::string mUri;
		};
	}
}

#endif  //_DATABASEINFO_H
