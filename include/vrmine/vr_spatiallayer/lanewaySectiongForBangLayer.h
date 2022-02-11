#if !defined(_CLaneWaySectionForBangLayer_H)
#define _CLaneWaySectionForBangLayer_H

#include "vrmine/vr_spatiallayer/scenelayer.h"
#include <Ogre/Ogre.h>

namespace VirtualMine
{
	namespace SpatialLayer
	{
		class VR_SPATIALLAYER_DLL CLaneWaySectionForBangLayer : public CSceneLayer
		{
		public:
			CLaneWaySectionForBangLayer();
			virtual ~CLaneWaySectionForBangLayer();
			virtual void initialise();
			virtual void notifyUpdate();
			//virtual void setStyle(VirtualMine::SpatialInterface::IStyle* pStyle);
			virtual void setFrameMode(bool isFrameMode);
			virtual void update();

		};
	}
}


#endif  //_CLaneWaySectionForBangLayer_H