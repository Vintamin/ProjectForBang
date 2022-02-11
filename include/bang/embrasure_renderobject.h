#if !defined(_EMBRASURERENDERABLEOBJECT_H)
#define _EMBRASURERENDERABLEOBJECT_H

#include "vrmine/vr_spatialrender/baserender/geomultirenderableobject.h"
#include "bang/embrasure_meshcreator.h"
#include <OGRE/Ogre.h>

namespace BangRender
{
	namespace SpatialRender
	{
		class BANG_RENDER_DLL CEmbrasureRenderableObject : public VirtualMine::BaseRender::CGeoMultiRenderableObject
		{
		public:
			CEmbrasureRenderableObject();
			~CEmbrasureRenderableObject();	
		public:
			virtual void dispose();
			void build();
			void render();
			void deRender();
			void setMaterialName(const std::string& materialName);
		};
	}
}

#endif  //_EMBRASURERENDERABLEOBJECT_H
