#if !defined(_FAULTlAYERDATASET_H)
#define _FAULTlAYERDATASET_H


#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/dataset.h"
#include "vrmine/vr_databaseengine/database_config.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CFaultLayerDataset : public VirtualMine::Database::CDataset
		{
		public:
			CFaultLayerDataset();

			~CFaultLayerDataset();

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


#endif//_FAULTlAYERDATASET_H