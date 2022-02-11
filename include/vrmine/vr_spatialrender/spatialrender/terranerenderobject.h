

#if !defined(_TERRANERENDERABLEOBJECT_H)
#define _TERRANERENDERABLEOBJECT_H

#include "vrmine/vr_spatialrender/baserender/geomultirenderableobject.h"
#include <OGRE/Ogre.h>


namespace VirtualMine
{
	namespace SpatialRender
	{
		class VR_SPATIALRENDER_DLL CTerraneRenderableObject : public VirtualMine::BaseRender::CGeoMultiRenderableObject
		{
		public:
			CTerraneRenderableObject();
			virtual ~CTerraneRenderableObject();	
		public:
			void build();
			void render();
			void deRender();

		};
	}
}

#endif  //_TERRANERENDERABLEOBJECT_H
