
#if !defined(_LANEWAYRENDERFORBANG)
#define _LANEWAYRENDERFORBANG


#include "vrmine/vr_spatialrender/baserender/geomultirenderableobject.h"
#include "vrmine/vr_spatialobject/mine/lanwayobject.h"

namespace VirtualMine
{
	namespace BaseRender
	{
		class VR_SPATIALRENDER_DLL CLanewayRenderForBang : public CGeoMultiRenderableObject
		{
		public:
			CLanewayRenderForBang();
			virtual ~CLanewayRenderForBang();
			virtual void build();
			virtual void render();
			virtual void dispose();
		protected:
			//void convertGeoLineToRenderData(VirtualMine::Base::CGeoLine* pGeoLine);
			void createLanewayForBang(VirtualMine::Mine::CLaneWayObject* pGeoObject);

		protected:
			Ogre::ManualObject* mpRenderableObject;
		};
	}
}

#endif  //_LANEWAYRENDERFORBANG
