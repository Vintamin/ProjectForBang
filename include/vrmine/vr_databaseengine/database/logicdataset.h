#if !defined(_LOGICDATASET_H)
#define _LOGICDATASET_H

//#include <string>
#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/dataset.h"
//#include "vrmine/vr_sqlitedatabase/sqlitedatabase/lanewayfeature.h"
//#include "vrmine/vr_sqlitedatabase/sqlitedatabase_config.h"
#include "vrmine/vr_databaseengine/database/lanewayfeature.h"
#include "vrmine/vr_databaseengine/database_config.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CLogicDataset : public VirtualMine::Database::CDataset
		{
		public:
			CLogicDataset();

			~CLogicDataset();

			std::string  getFeatureTypeByName(std::string featureName);

		/*	void addFeature(CLogicFeature feature);

			void destroyFeature(const std::string& featureName);*/

			//IFeature* getFeature(const int& id);

			////IFeature* getFeature(const int& id);

			//vector<IFeature*>* getLanewayFeature();

			//private:
			//	vector<IFeature*>* mpLanewayFeature;

			static std::string LogicDataset;


		};
	}
}
#endif //_LOGICDATASET_H