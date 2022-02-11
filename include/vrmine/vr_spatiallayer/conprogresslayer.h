#if !defined(_CConProgressLayer_H)
#define _CConProgressLayer_H

#include "vrmine/vr_spatiallayer/scenelayer.h"
#include <Ogre/Ogre.h>
#include "string"
#include "OGRE/OgreTextAreaOverlayElement.h"

using namespace std;

namespace VirtualMine
{
	namespace SpatialLayer
	{


		class VR_SPATIALLAYER_DLL CConProgressLayer : public CSceneLayer
		{
		public:
			CConProgressLayer();
			virtual ~CConProgressLayer();
			virtual void initialise();
			virtual void notifyUpdate();
			//virtual void setStyle(VirtualMine::SpatialInterface::IStyle* pStyle);
			virtual void setFrameMode(bool isFrameMode);
			virtual void update();


		};

	}
}


#endif  //_CConProgressLayer_H