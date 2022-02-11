#if !defined(_LANEWAYDATASET_H)
#define _LANEWAYDATASET_H

#include "vrmine/vr_databaseengine/database_config.h"
#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/dataset.h"
//#include "vrmine/vr_sqlitedatabase/sqlitedatabase/lanewayfeature.h"
#include "vrmine/vr_databaseengine/database/lanewayfeature.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CLanewayDataset : public VirtualMine::Database::CDataset
		{
		public:
			CLanewayDataset();

			~CLanewayDataset();

		/*	void addFeature(CLanewayFeature feature);

			void destroyFeature(const std::string& featureName);*/

			//IFeature* getFeature(const int& id);

			////IFeature* getFeature(const int& id);

			//vector<IFeature*>* getLanewayFeature();

		//private:
		//	vector<IFeature*>* mpLanewayFeature;

		};
	}
}
#endif //_LANEWAYDATASET_H