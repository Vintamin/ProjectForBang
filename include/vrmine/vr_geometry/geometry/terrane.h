

#if !defined(_TERRANE_H)
#define _TERRANE_H

#include "vrmine/vr_spatialinterface/igeometry.h"
#include "vrmine\vr_geometry\geometry\geometry_config.h"
#include "vrmine/vr_core/coredefine.h"
#include "vrmine/vr_geometry/geometry/surface.h"
#include <OGRE/Ogre.h>

namespace VirtualMine
{
	namespace Geometry
	{
		class VR_GEOMETRY_DLL CTerraneGeometry : public VirtualMine::Geometry::CSurface
		{
		public: 
			CTerraneGeometry();
			~CTerraneGeometry();
		};
	}
}

#endif  //_TERRANE_H
