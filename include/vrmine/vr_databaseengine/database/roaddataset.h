#if !defined(_ROADDATASETR_H)
#define _ROADDATASETR_H


#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/dataset.h"
#include "vrmine\vr_databaseengine\database_config.h"

#include "vrmine/vr_databaseengine/database/roadfeature.h"

namespace VirtualMine
{
	namespace Database
	{
		class  VR_DATABASEENGINE_DLL CRoadDataset : public VirtualMine::Database::CDataset
		{
		public:
			CRoadDataset();

			~CRoadDataset();
	

		};
	}
}

#endif //_ROADDATASETR_H