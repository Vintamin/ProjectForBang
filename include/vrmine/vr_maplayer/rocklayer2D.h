#if !defined(_CROCKLAYER2D_H)
#define _CROCKLAYER2D_H

#include "vrmine/vr_maplayer/igeometrydrawitem.h"
#include <QtGui/QPixmap>
#include "vrmine/vr_maplayer/map2dlayer.h"
#include "vrmine/vr_maplayer/map.h"
#include "vrmine/vr_maplayer/map2dlayer.h"
#include "vrmine/vr_maplayer/linedrawitem.h"
#include "vrmine/vr_maplayer/pointdrawitem.h"
#include "vrmine/vr_maplayer/textDrawItem.h"
#include "vrmine/vr_geometry/geometry/line.h"
#include "vrmine/vr_geometry/geometry/point.h"
#include "vrmine/vr_style/style/linestyle.h"
#include "OGRE/OgreAxisAlignedBox.h"
#include "vrmine/vr_maplayer/line2D.h"
#include "vrmine/vr_maplayer/point2D.h"


namespace VirtualMine
{
	namespace Map
	{
		class VR_MAPLAYER_EXPORT CRockLayer2DFactory : public VirtualMine::SpatialInterface::CLayerFactory
		{
		public:
			CRockLayer2DFactory();
			virtual ~CRockLayer2DFactory();
			virtual VirtualMine::SpatialInterface::ILayer* createInstance(const std::string& name);
			virtual void destroyInstance(VirtualMine::SpatialInterface::ILayer* pLayer);
			virtual std::string getType();
		};
	class VR_MAPLAYER_EXPORT CRockLayer2D : public  CMap2DLayer
		{
		public:
			CRockLayer2D();
			~CRockLayer2D();
			virtual	void initialise();
		
		private:
			void drawRenderPoint(VirtualMine::Map::CPoint2D* pPoint,Ogre::ColourValue renderColor,const bool& visible);
			void drawRenderLine(VirtualMine::Map::CLine2D* pLine,Ogre::ColourValue renderColor,const bool& visible);
			void drawRockLayer();
			void computeBoundingBox();
		};
	}
}
#endif  