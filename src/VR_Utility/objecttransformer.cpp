
#include "vrmine/vr_utility/objecttransformer.h"
#include "vrmine/vr_spatialobject/base/geodatatype.h"
#include "vrmine\vr_databaseengine\database\ifeature.h"
//#include "vrmine\vr_spatialobject\base\igeoobject.h"
#include <string>

using namespace VirtualMine::Base;

namespace VirtualMine
{
	namespace Utility
	{
		CSpatialUtility::CSpatialUtility()
		{
		
		}
		
		CSpatialUtility::~CSpatialUtility()
		{
		
		}

		VirtualMine::Database::IFeature* CSpatialUtility::transformGeoObjectToFeature(VirtualMine::Base::IGeoObject* pGeoObject)
		{
			//std::string geoDataType = pGeoObject->getType();
			////std::string type = GeoDataType::GDT_LANWAY;
			////if (geoDataType == GeoDataType::GDT_LANWAY)
			//{

			//}
			return NULL;
		}

		VirtualMine::Base::IGeoObject* CSpatialUtility::transformFeatureToGeoObject(VirtualMine::Database::IFeature* pFeature,
			const std::string& type)
		{
			assert(pFeature);
			if (NULL == pFeature)
			{
				return NULL;
			}

			return NULL;
		}
	}
}
