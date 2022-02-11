#include "vrmine/vr_spatialobject/base/geopoint.h"

using namespace VirtualMine::SpatialInterface;

namespace VirtualMine
{
	namespace Base
	{
		CGeoPoint::CGeoPoint()
		{
		
		}
		
		CGeoPoint::~CGeoPoint()
		{
		
		}

		VirtualMine::SpatialInterface::IStyle* CGeoPoint::getStyle()
		{
			VirtualMine::SpatialInterface::IStyle* pStyle =  CGeoObject::getStyle();
			if (pStyle == NULL)
			{
				pStyle = new VirtualMine::Style::CPointStyle();
				CGeoObject::setStyle(pStyle,true);
			}
			return  CGeoObject::getStyle();
		}

		VirtualMine::SpatialInterface::IGeometry* CGeoPoint::getGeometry()
		{
			VirtualMine::SpatialInterface::IGeometry* pGeometry =  CGeoObject::getGeometry();
			if (pGeometry == NULL)
			{
				pGeometry = new  VirtualMine::Geometry::CPoint();
				CGeoObject::setGeometry(pGeometry,true);
			}
			return  CGeoObject::getGeometry();
		}

		VirtualMine::SpatialInterface::IGeoProperty* CGeoPoint::getGeoProperty()
		{
			return NULL;
		}
	}
}