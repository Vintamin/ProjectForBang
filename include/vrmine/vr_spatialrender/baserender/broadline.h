#if !defined(_BROADLINE_H)
#define _BROADLINE_H
#include "vrmine/vr_spatialrender/spatialrender_config.h"
#include "vrmine/vr_geometry/geometry/point.h"
#include "vrmine/vr_geometry/geometry/line.h"
#include "vrmine/vr_spatialinterface/irenderableobject.h"
#include "OGRE/OgreSceneManager.h"
#include "OGRE/OgreManualObject.h"
#include "OGRE/OgreTimer.h"

namespace VirtualMine
{
	namespace BaseRender
	{ 
		class CBroadLine;
		class VR_SPATIALRENDER_DLL CBroadLineListener : public Ogre::FrameListener
		{
		public:
			CBroadLineListener(CBroadLine* ref_pBroadLine);

			virtual ~CBroadLineListener();

			virtual bool frameStarted(const Ogre::FrameEvent& evt);

		protected:
			CBroadLine* ref_mpBroadLine;
			Ogre::Timer mTimer;
		};


		class VR_SPATIALRENDER_DLL CBroadLine : public VirtualMine::SpatialInterface::IRenderableObject
		{
			friend class CBroadLineListener;
		public:
			CBroadLine();
			virtual ~CBroadLine();
			virtual void addPoint(VirtualMine::Geometry::CPoint& point);
			virtual void flushToScene();
		protected:
			int mWidth;
			VirtualMine::Geometry::CLine* mpLineData;
			Ogre::ManualObject* mpRenderObject;
		};
	}
}
#endif