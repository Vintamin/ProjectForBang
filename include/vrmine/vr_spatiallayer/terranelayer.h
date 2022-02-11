#if !defined(_CTerraneLayer_H)
#define _CTerraneLayer_H

#include "vrmine/vr_spatiallayer/scenelayer.h"


namespace VirtualMine
{
	namespace SpatialLayer
	{
		class VR_SPATIALLAYER_DLL CTerraneLayer : public CSceneLayer
		{
		public:
			CTerraneLayer();
			virtual ~CTerraneLayer();
			virtual void initialise();
			virtual void notifyUpdate();
			//virtual void setStyle(VirtualMine::SpatialInterface::IStyle* pStyle);
			virtual void setFrameMode(bool isFrameMode);
			virtual void update();
			
			};
	}
}


#endif  //_CTerraneLayer_H