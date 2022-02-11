

#if !defined(_EMBRASURE_STYLE_H)
#define _EMBRASURE_STYLE_H

#include "bang_render_config.h"
#include "vrmine/vr_spatialinterface/istyle.h"

namespace BangRender
{
	namespace Style
	{
		class BANG_RENDER_DLL CEmbrasureStyle : public VirtualMine::SpatialInterface::CStyle
		{
		public:
			CEmbrasureStyle();
			~CEmbrasureStyle();
		public:
			void registStyle();

		};
	}
}

#endif  //_EMBRASURE_STYLE_H
