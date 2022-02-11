//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : igeoobject.cpp
//  @ Date : 2014/8/6
//  @ Author : 朱炜鹏
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine/vr_spatialobject/mine/lanwayobject.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_spatialinterface/istyle.h"
#include "vrmine/vr_geometry/geometry/laneway.h"
#include "vrmine/vr_spatialobject/geoproperty/lanewayproperty.h"
#include "vrmine/vr_databaseengine/database/lanewayfeature.h"
#include "vrmine/vr_geometry/geometry/laneway.h"
//#include "vrmine/vr_sqlitedatabase/sqlitedatabase/sqlitedatabase.h"

using namespace VirtualMine::Style;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Geometry;

namespace VirtualMine
{
	namespace Mine
	{

		CLaneWayObject::CLaneWayObject()
		{
			this->setType(VirtualMine::Core::GeoDataType::GDT_LANWAY);
		}

		CLaneWayObject::~CLaneWayObject()
		{
		}

		 VirtualMine::SpatialInterface::IStyle* CLaneWayObject::getStyle()
		{
			VirtualMine::SpatialInterface::IStyle* pStyle =  CGeoObject::getStyle();
			if (pStyle == NULL)
			{
				pStyle = new VirtualMine::Style::CLanewayStyle();
				CGeoObject::setStyle(pStyle,true);
				//delete pStyle;
			}
			return  CGeoObject::getStyle();
		}

		 VirtualMine::SpatialInterface::IGeometry* CLaneWayObject::getGeometry()
		 {
			 VirtualMine::SpatialInterface::IGeometry* pGeometry =  CGeoObject::getGeometry();
			 if (pGeometry == NULL)
			 {
				 pGeometry = new  VirtualMine::Geometry::CLaneWayLineGeometry();
				 CGeoObject::setGeometry(pGeometry,true);
				// delete pStyle;
			 }
			 return  CGeoObject::getGeometry();
		 }

		VirtualMine::SpatialInterface::IGeoProperty* CLaneWayObject::getGeoProperty()
		{
			VirtualMine::SpatialInterface::IGeoProperty* pGeoProperty =  CGeoObject::getGeoProperty();
			if (pGeoProperty == NULL)
			{
				pGeoProperty = new VirtualMine::GeoProperty::CLanewayProperty();
				CGeoObject::setGeoProperty(pGeoProperty,true);
				//delete pStyle;
			}
			return  CGeoObject::getGeoProperty();
		}
		
		void CLaneWayObject::fromFeature(VirtualMine::Database::IFeature* pFeature)
		{
			assert(pFeature);
			if (NULL == pFeature)
			{
				return;
			}
			//std::string name = pFeature->getName();
			void* pData1 = static_cast<VirtualMine::Database::CLanewayFeature*>(pFeature)->getPropertySet()->getFields().at(1).getVarient().data();
			char* name = (char*)pData1;

			void* pData2 = static_cast<VirtualMine::Database::CLanewayFeature*>(pFeature)->getPropertySet()->getFields().at(3).getVarient().data();
			float* width = static_cast<float*>(pData2);

			void* pData3 = static_cast<VirtualMine::Database::CLanewayFeature*>(pFeature)->getPropertySet()->getFields().at(4).getVarient().data();
			float* height = static_cast<float*>(pData3);
		
			void* pData5 = static_cast<VirtualMine::Database::CLanewayFeature*>(pFeature)->getPropertySet()->getFields().at(5).getVarient().data();
			int* psectiontype = static_cast<int*>(pData5);
			int sectiontype = *psectiontype;
			VirtualMine::Style::LanewaySectionType sectype = (VirtualMine::Style::LanewaySectionType)sectiontype;

			void* pData6 = static_cast<VirtualMine::Database::CLanewayFeature*>(pFeature)->getPropertySet()->getFields().at(6).getVarient().data();
			int* psupporttype = static_cast<int*>(pData6);
			int supporttype = *psupporttype;
			VirtualMine::Style::LanewaySuppoetType supptype = (VirtualMine::Style::LanewaySuppoetType)supporttype;


			void* pData4 = static_cast<VirtualMine::Database::CLanewayFeature*>(pFeature)->getPropertySet()->getFields().at(7).getVarient().data();
			Ogre::uchar* blob = static_cast<Ogre::uchar*>(pData4);

			int legth = static_cast<VirtualMine::Database::CLanewayFeature*>(pFeature)->getPropertySet()->getFields().at(7).getVarient().getLength();


			void* pData8 = static_cast<VirtualMine::Database::CLanewayFeature*>(pFeature)->getPropertySet()->getFields().at(8).getVarient().data();
			int* planewaywindtype = static_cast<int*>(pData8);
			int lanewaywindtype = *planewaywindtype;
			VirtualMine::Style::LanewayWindType lanewaywindtype2 = (VirtualMine::Style::LanewayWindType)lanewaywindtype;



			//int sizeblob = sizeof(blob);
			//int sizeblob = malloc_usable_size(blob);
			VirtualMine::Core::CVRDataStream ds;
			//int blobsize = strlen((const char*)blob);
			

			ds.wirteBlob(blob,legth);
			ds.reseek(0);
			static_cast<CLanewayStyle*>(this->getStyle())->setHeight(*height);
			static_cast<CLanewayStyle*>(this->getStyle())->setWidth(*width);
			static_cast<CLanewayStyle*>(this->getStyle())->setSectionType(sectype);
			static_cast<CLanewayStyle*>(this->getStyle())->setSupportType(supptype);
			static_cast<CLanewayStyle*>(this->getStyle())->setWindType(lanewaywindtype2);


			static_cast<CLaneWayLineGeometry*>(this->getGeometry())->setName(name);
			static_cast<CLaneWayLineGeometry*>(this->getGeometry())->fromStream(ds);


		}
		
		VirtualMine::Database::IFeature* CLaneWayObject::toFeature()
		{
			//return NULL;
			float height = static_cast<CLanewayStyle*>(this->getStyle())->getHeight();
			float width = static_cast<CLanewayStyle*>(this->getStyle())->getWidth();
			int sectionType =  static_cast<CLanewayStyle*>(this->getStyle())->getSectionType();
			int supportType = static_cast<CLanewayStyle*>(this->getStyle())->getSupportType();
		    int lanewaywindtype =  static_cast<CLanewayStyle*>(this->getStyle())->getWindType();

			std::string name = static_cast<CLaneWayLineGeometry*>(this->getGeometry())->getName();
			std::string type = "Laneway";
			VirtualMine::Core::CVRDataStream datastream;
			static_cast<CLaneWayLineGeometry*>(this->getGeometry())->toStream(datastream);
			datastream.reseek(0);
			VirtualMine::Database::IFeature* lanewayfeature = new VirtualMine::Database::CLanewayFeature();

			lanewayfeature->setFieldName(name);
			lanewayfeature->setFieldHeight(height);
			lanewayfeature->setFieldType(type);
			lanewayfeature->setFieldWidth(width);
			lanewayfeature->setFieldHeightSupportType(supportType);
			lanewayfeature->setFieldSectionType(sectionType);
			lanewayfeature->setFieldLanewayWindType(lanewaywindtype);

			//CVRDatastream的长度有问题
			lanewayfeature->setFieldBlob(datastream.getData(),datastream.getLength());
			//id 有问题
			//lanewayfeature->setFieldID(100);

			return lanewayfeature;
		}
	}
}
