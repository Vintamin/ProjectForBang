

#include "vrmine/vr_spatialobject/mine/terraneobject.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_style/style/terranestyle.h"
#include "vrmine/vr_geometry/geometry/terrane.h"
#include "vrmine/vr_spatialobject/geoproperty/terraneproperty.h"
#include "vrmine/vr_databaseengine/database/terranefeature.h"
#include "OGRE/OgreFileSystem.h"
#include "vrmine/vr_mathenine/mathengine/mathcalculator.h"

//#include "OGRE/OgreArchiveFactory.h"
//#include "OGRE/OgreArchiveManager.h"


using namespace VirtualMine::GeoProperty;
using namespace VirtualMine::Database;
using namespace VirtualMine::Style;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Geometry;
using namespace VirtualMine::MathEngine;

namespace VirtualMine
{
	namespace Mine
	{
		CTerraneObject::CTerraneObject()
		{
			this->setType(VirtualMine::Core::GeoDataType::GDT_TERRANE);
		}

		CTerraneObject::~CTerraneObject()
		{

		}

		VirtualMine::SpatialInterface::IStyle* CTerraneObject::getStyle()
		{
			VirtualMine::SpatialInterface::IStyle* pStyle =  CGeoObject::getStyle();
			if (pStyle == NULL)
			{
				pStyle = new VirtualMine::Style::CTerraneStyle();
				CGeoObject::setStyle(pStyle,true);
				//delete pStyle;
			}
			return  CGeoObject::getStyle();
		}

		VirtualMine::SpatialInterface::IGeometry* CTerraneObject::getGeometry()
		{
			VirtualMine::SpatialInterface::IGeometry* pGeometry =  CGeoObject::getGeometry();
			if (pGeometry == NULL)
			{
				pGeometry = new  VirtualMine::Geometry::CTerraneGeometry();
				CGeoObject::setGeometry(pGeometry,true);
				// delete pStyle;
			}
			return  CGeoObject::getGeometry();
		}

		VirtualMine::SpatialInterface::IGeoProperty* CTerraneObject::getGeoProperty()
		{
			VirtualMine::SpatialInterface::IGeoProperty* pGeoProperty =  CGeoObject::getGeoProperty();
			if (pGeoProperty == NULL)
			{
				pGeoProperty = new VirtualMine::GeoProperty::CTerraneProperty();
				CGeoObject::setGeoProperty(pGeoProperty,true);
				//delete pStyle;
			}
			return  CGeoObject::getGeoProperty();
		}

		void CTerraneObject::fromFeature(VirtualMine::Database::IFeature* pFeature)
		{
			assert(pFeature);
			if (NULL == pFeature)
			{
				return;
			}
			void* pData = dynamic_cast<VirtualMine::Database::CTerraneFeature*>(pFeature)->getPropertySet()->getFields().at(0).getVarient().data();
			int* id = (int*)pData;
			int getID = *id;

			void* pData1 = dynamic_cast<VirtualMine::Database::CTerraneFeature*>(pFeature)->getPropertySet()->getFields().at(1).getVarient().data();
			char* name = (char*)pData1;

			void* pData2 = dynamic_cast<VirtualMine::Database::CTerraneFeature*>(pFeature)->getPropertySet()->getFields().at(2).getVarient().data();
			char* rockType = (char*)pData2;


			void* pData3 = dynamic_cast<VirtualMine::Database::CTerraneFeature*>(pFeature)->getPropertySet()->getFields().at(3).getVarient().data();
			Ogre::uchar* imagetexture = static_cast<Ogre::uchar*>(pData3);

			int texturelength = dynamic_cast<VirtualMine::Database::CTerraneFeature*>(pFeature)->getPropertySet()->getFields().at(3).getVarient().getLength();
			




			VirtualMine::Core::CVRDataStream ds;
			//VirtualMine::Core::CVRDataStream textureds;

			ds.wirteBlob(imagetexture,texturelength);
			//textureds.wirteBlob(imagetexture,texturelength);

			ds.reseek(0);
			dynamic_cast<CTerraneProperty*>(this->getGeoProperty())->setName(name);
			dynamic_cast<CTerraneProperty*>(this->getGeoProperty())->setProjectID(getID);
			dynamic_cast<CTerraneProperty*>(this->getGeoProperty())->setRockType(rockType);
			dynamic_cast<CTerraneGeometry*>(this->getGeometry())->fromStream(ds);
			
		
		
		}

	

		VirtualMine::Database::IFeature* CTerraneObject::toFeature()
		{

			std::string name = dynamic_cast<CTerraneProperty*>(this->getGeoProperty())->getName();
			std::string rockType = dynamic_cast<CTerraneProperty*>(this->getGeoProperty())->getRockType();
			int projectID = 0;
			projectID = dynamic_cast<CTerraneProperty*>(this->getGeoProperty())->getProjectID();
			if (name == "")
			{
				name = "»ÒÑÒ";
			}

			if (rockType == "")
			{
				rockType = "»ÒÑÒ";
			}
			VirtualMine::Core::CVRDataStream datastream;
			static_cast<CTerraneGeometry*>(this->getGeometry())->toStream(datastream);

			datastream.reseek(0);
			VirtualMine::Database::CTerraneFeature* terranefeature = new VirtualMine::Database::CTerraneFeature();
			
			terranefeature->setFieldID(projectID);
			terranefeature->setFieldName(name);
			terranefeature->setFieldRockType(rockType);
			terranefeature->setFieldBlob(datastream.getData(),datastream.getLength());
		
	
			return terranefeature;		
			
		}
	}
}
