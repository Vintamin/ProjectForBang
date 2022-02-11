

#if !defined(_EMBRASURE_GEOMETRY_H)
#define _EMBRASURE_GEOMETRY_H

#include "vrmine/vr_spatialinterface/igeometry.h"
#include "bang_render_config.h"
#include "vrmine/vr_core/coredefine.h"
#include "vrmine/vr_geometry/geometry/point.h"
#include <OGRE/Ogre.h>

namespace BangRender
{
	namespace Geometry
	{
		class BANG_RENDER_DLL CEmbrasureGeometry : public VirtualMine::Geometry::CPoint
		{
		public: 
			CEmbrasureGeometry();
			CEmbrasureGeometry(const double& x,const double& y,const double& z);
			~CEmbrasureGeometry();

		};
	}
}

#endif  //_EMBRASURE_GEOMETRY_H
