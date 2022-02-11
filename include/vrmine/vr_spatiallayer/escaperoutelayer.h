#if !defined(_CEscapeRouteLayer_H)
#define _CEscapeRouteLayer_H

#include "vrmine/vr_spatiallayer/scenelayer.h"
#include <Ogre/Ogre.h>
#include "string"

using namespace std;

namespace VirtualMine
{
	namespace SpatialLayer
	{


		class VR_SPATIALLAYER_DLL CEscapeRouteLayer : public CSceneLayer
		{
		public:
			CEscapeRouteLayer();
			virtual ~CEscapeRouteLayer();
			virtual void initialise();
			virtual void notifyUpdate();
			//virtual void setStyle(VirtualMine::SpatialInterface::IStyle* pStyle);
			virtual void setFrameMode(bool isFrameMode);
			virtual void update();


		};

	}
}


#endif  //_CEscapeRouteLayer_H