#if !defined(_DATABASEMANAGER_H)
#define _DATABASEMANAGER_H


#include "vrmine\vr_databaseengine\database_config.h"
#include "vrmine/vr_databaseengine/database/idatasourcemanager.h"
//#include "sqlite3.h"



namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CDatabaseManager : public VirtualMine::Database::IDataSourceManager
		{
		public:
			CDatabaseManager();

			~CDatabaseManager();

			void createDatabase();

			virtual std::string getType();

		protected:
			std::string mType;

		};
	}
}

#endif //_DATABASEMANAGER_H