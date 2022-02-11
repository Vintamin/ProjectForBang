# ifndef _CUTILITY_H
#define _CUTILITY_H

#include "vrmine\vr_utility\utility_config.h"
#include <string>

namespace VirtualMine
{
	namespace Base
	{
		class IGeoObject;
	}
	namespace Database
	{
		class IFeature;
	}

	namespace Utility
	{
		class VR_UTILITY_DLL CSpatialUtility
		{
		public :
			CSpatialUtility();
			~CSpatialUtility();
			
			static VirtualMine::Database::IFeature* transformGeoObjectToFeature(VirtualMine::Base::IGeoObject* pGeoObject);
			
			static VirtualMine::Base::IGeoObject* transformFeatureToGeoObject(VirtualMine::Database::IFeature* pFeature,const std::string& type);

		};
	}
}
#endif