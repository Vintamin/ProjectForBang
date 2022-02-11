#include "vrmine/vr_databaseengine/database/idatasource.h"
#include "vrmine/vr_sqlitedatabase/sqlitedatabase/sqlite3.h"  

namespace VirtualMine
{
	namespace SQLiteDatabase
	{
		class CDatabase £ºpublic VirtualMine::Database::IDataSource
		{
		public:
			CDatabase::CDatabase():mName(),mID()
			{
				
			}

			CDatabase::CDatabase(const string& name):mName(name),mID()
			{
				
			}

			CDatabase::~CDatabase()
			{

			}

			void CDatabase::createDataSet()
			{

			}

			void CDatabase::destroyDataSet()
			{

			}

			//void getDataSet();

			void CDatabase::setName(const string& name)
			{
				this->mName = name;
			}

			void CDatabase::getName()
			{
				return this->mName;
			}

			int CDatabase::getID()
			{
                return this->mID;
			}

			void CDatabase::createMetaDataTable()
			{

			}

			void CDatabase::createLanewayTable()
			{

			}

			void CDatabase::createDrillingTable()
			{

			}

			void CDatabase::createRoadTable()
			{

			}


			int CDatabase::insertFeatureToLaneTable(VirtualMine::Database::IFeature feature)
			{

			}

			int CDatabase::insertFeatureToDrillingTable(VirtualMine::Database::IFeature feature)
			{

			}

			int CDatabase::insertFeatureToRoadTable(VirtualMine::Database::IFeature feature)
			{

			}

			int CDatabase::insertFeatureToCoalTable(VirtualMine::Database::IFeature feature)
			{

			}

	/*		void insertDatasetToLanewayTable();
			void insertDatasetToDrillingTable();
			void insertDatasetToRoadTable();*/
		

		private:
			string mName;
		   

		};
	}
}