#if !defined(_METADATADATASET_H)
#define _METADATADATASET_H

#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/dataset.h"
#include "vrmine/vr_databaseengine/database_config.h"


namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CMetadataDataset : public VirtualMine::Database::CDataset
		{
		public:
			CMetadataDataset();

			~CMetadataDataset();

			static std::string MetadataDataset;
		
		};
	}
}

#endif //_METADATADATASET_H