#include "vrmine/vr_spatialobject/base/geoline.h"
#include "vrmine/vr_style/style/pipestyle.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace VirtualMine::SpatialInterface;

namespace VirtualMine
{
	namespace Base
	{
		CGeoLine::CGeoLine()
		{
		
		}
		
		CGeoLine::~CGeoLine()
		{
		
		}

		VirtualMine::SpatialInterface::IStyle* CGeoLine::getStyle()
		{
			VirtualMine::SpatialInterface::IStyle* pStyle =  CGeoObject::getStyle();
			if (pStyle == NULL)
			{
				pStyle = new VirtualMine::Style::CLineStyle();
				CGeoObject::setStyle(pStyle,true);
			}
			return  CGeoObject::getStyle();
		}

		VirtualMine::SpatialInterface::IGeometry* CGeoLine::getGeometry()
		{
			VirtualMine::SpatialInterface::IGeometry* pGeometry =  CGeoObject::getGeometry();
			if (pGeometry == NULL)
			{
				pGeometry = new  VirtualMine::Geometry::CLine();
				CGeoObject::setGeometry(pGeometry,true);
			}
			return  CGeoObject::getGeometry();
		}

		VirtualMine::SpatialInterface::IGeoProperty* CGeoLine::getGeoProperty()
		{
			return NULL;
		}

		CShotHoleGeoLine::CShotHoleGeoLine()
		{
			this->setType(VirtualMine::Core::GeoDataType::GDT_SHOTHOLE);
		}

		CShotHoleGeoLine::~CShotHoleGeoLine()
		{

		}

		VirtualMine::SpatialInterface::IStyle* CShotHoleGeoLine::getStyle()
		{
			VirtualMine::SpatialInterface::IStyle* pStyle =  CGeoObject::getStyle();
			if (pStyle == NULL)
			{
				pStyle = new VirtualMine::Style::CPipeLineStyle();
				CGeoObject::setStyle(pStyle,true);
			}
			return  CGeoObject::getStyle();
		}

		VirtualMine::SpatialInterface::IGeometry* CShotHoleGeoLine::getGeometry()
		{
			VirtualMine::SpatialInterface::IGeometry* pGeometry =  CGeoObject::getGeometry();
			if (pGeometry == NULL)
			{
				pGeometry = new  VirtualMine::Geometry::CLine();
				CGeoObject::setGeometry(pGeometry,true);
			}
			return  CGeoObject::getGeometry();
		}

		VirtualMine::SpatialInterface::IGeoProperty* CShotHoleGeoLine::getGeoProperty()
		{
			return NULL;
		}

	}
}