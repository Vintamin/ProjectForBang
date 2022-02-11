#if !defined(_DRILLINGDATASET_H)
#define _DRILLINGDATASET_H


#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/dataset.h"
#include "vrmine/vr_databaseengine/database_config.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CDrillingDataset : public VirtualMine::Database::CDataset
		{
		public:
			CDrillingDataset();

			~CDrillingDataset();

			/*CDrillingFeature createFeature(const std::string& featureName);

			void destroyFeature(const std::string& featureName);

			CDrillingFeature* getFeature(int index);

			CDrillingFeature* getFeature(const std::string& featureName);
*/

	/*	private:
			vector<CDrillingFeature*>* mpDrillingFeature;*/

		};
	}
}

#endif//_DRILLINGDATASET_H