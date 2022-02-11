#if !defined(_CFaultLayer_H)
#define _CFaultLayer_H

#include "vrmine/vr_spatiallayer/scenelayer.h"
#include "vrmine/vr_style/style/faultstyle.h"
#include <Ogre/Ogre.h>
 
namespace VirtualMine
{
	namespace SpatialLayer
	{
		class VR_SPATIALLAYER_DLL CFaultLayer : public CSceneLayer
		{
		public:
			CFaultLayer();
			virtual ~CFaultLayer();
			virtual void initialise();
			virtual void notifyUpdate();
			virtual void setStyle(VirtualMine::SpatialInterface::IStyle* pStyle);
			virtual void setFrameMode(bool isFrameMode);
		};
	}
}


#endif  //_CFaultLayer_H