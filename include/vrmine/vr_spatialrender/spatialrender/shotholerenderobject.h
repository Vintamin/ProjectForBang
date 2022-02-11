

#if !defined(_SHOTHOLERENDERABLEOBJECT_H)
#define _SHOTHOLERENDERABLEOBJECT_H

#include "vrmine/vr_spatialrender/baserender/geomultirenderableobject.h"
#include <OGRE/Ogre.h>


namespace VirtualMine
{
	namespace SpatialRender
	{
		class VR_SPATIALRENDER_DLL CShotHoleRenderableObject : public VirtualMine::BaseRender::CGeoMultiRenderableObject
		{
		public:
			CShotHoleRenderableObject();
			~CShotHoleRenderableObject();	
		public:
			void build();
			void render();
			void deRender();

		};
	}
}

#endif  //_SHOTHOLERENDERABLEOBJECT_H
