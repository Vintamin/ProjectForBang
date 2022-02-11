#include "vrmine/vr_maplayer/igeometrydrawitem.h"

namespace VirtualMine
{
	namespace Map
	{

		IGeometryDrawItem::IGeometryDrawItem()
		{
			
		}

		IGeometryDrawItem::~IGeometryDrawItem()
		{

		}
		
		VirtualMine::SpatialInterface::IGeometry* IGeometryDrawItem::getGeometry()
		{
			return NULL;
		}

		VirtualMine::SpatialInterface::IStyle* IGeometryDrawItem::getStyle()
		{
			return NULL;
		}

		void IGeometryDrawItem::setBoundingBox(const Ogre::AxisAlignedBox& boundingBox)
		{
			
		}
		Ogre::AxisAlignedBox& IGeometryDrawItem::getBoundingBox()
		{
			return Ogre::AxisAlignedBox();
		}
	}
}