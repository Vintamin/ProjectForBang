

#if !defined(_TERRANEOBJECT_H)
#define _TERRANEOBJECT_H

#include "vrmine\vr_spatialobject\spatialobject_config.h"
#include "vrmine\vr_spatialinterface\igeoobject.h"


namespace VirtualMine
{
	namespace Mine
	{
		class VR_SPATIALOBJECT_DLL CTerraneObject : public VirtualMine::SpatialInterface::CGeoObject
		{
		public: 
			CTerraneObject();
			~CTerraneObject();
		public:
			VirtualMine::SpatialInterface::IStyle* getStyle();
			VirtualMine::SpatialInterface::IGeometry* getGeometry();
			VirtualMine::SpatialInterface::IGeoProperty* getGeoProperty();
			virtual void fromFeature(VirtualMine::Database::IFeature* pFeature);
			virtual VirtualMine::Database::IFeature* toFeature();
		};
	}
}

#endif  //_TERRANEOBJECT_H
