//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : modelobject.cpp
//  @ Date : 2014/8/6
//  @ Author : 朱炜鹏
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine/vr_spatialobject/mine/modelobject.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_spatialobject/geoproperty/jiancemodelproperty.h"

#include "vrmine/vr_style/style/modelstyle.h"
#include "vrmine/vr_geometry/geometry/point.h"
#include "vrmine/vr_databaseengine/database/modelfeature.h"
#include "vrmine/vr_spatialobject/geoproperty/cardmodelproperty.h"
#include "vrmine/vr_style/style/modelstyle.h"
#include "vrmine/vr_spatialinterface/parameter.h"
#include "vrmine/vr_geometry/geometry/point.h"
#include "vrmine/vr_spatialinterface/iscene.h"

using namespace VirtualMine::Core;
using namespace VirtualMine::Database;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Style;
using namespace VirtualMine::GeoProperty;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Geometry;

namespace VirtualMine
{
	namespace Mine
	{
		CModelObject::CModelObject()
		{
			this->setType(VirtualMine::Core::GeoDataType::GDT_MODEL);
			this->setDeviceType();
		}

		CModelObject::~CModelObject()
		{

		}

		VirtualMine::SpatialInterface::IStyle* CModelObject::getStyle()
		{
			VirtualMine::SpatialInterface::IStyle* pStyle =  CGeoObject::getStyle();
			if (pStyle == NULL)
			{
				pStyle = new VirtualMine::Style::CModelStyle();
				CGeoObject::setStyle(pStyle,true);
				//delete pStyle;
			}
			return  CGeoObject::getStyle();
		}

		VirtualMine::SpatialInterface::IGeometry* CModelObject::getGeometry()
		{
			VirtualMine::SpatialInterface::IGeometry* pGeometry =  CGeoObject::getGeometry();
			if (pGeometry == NULL)
			{
				pGeometry = new  VirtualMine::Geometry::CPoint();
				CGeoObject::setGeometry(pGeometry,true);
				// delete pStyle;
			}
			return  CGeoObject::getGeometry();
		}

		VirtualMine::SpatialInterface::IGeoProperty* CModelObject::getGeoProperty()
		{
			VirtualMine::SpatialInterface::IGeoProperty* pGeoProperty =  CGeoObject::getGeoProperty();
			if (pGeoProperty == NULL)
			{
				switch (this->mDeviceType)
				{
				case DeviceType::DT_BEISHAN:
				case DeviceType::DT_FENGMEN:
				case DeviceType::DT_ZHUSHAN:
				case DeviceType::DT_SHUIBENG:
					pGeoProperty = new VirtualMine::GeoProperty::CJianceModelProperty();
					dynamic_cast<CJianceModelProperty*>(pGeoProperty)->setDeviceKind(DeviceKind::DK_SWITCH);
					break;
				case DeviceType::DT_TEMPERATURE:
				case DeviceType::DT_WATERLEVEL:
				case DeviceType::DT_WINDSPEED:
				case DeviceType::DT_GAS:
					pGeoProperty = new VirtualMine::GeoProperty::CJianceModelProperty();
					dynamic_cast<CJianceModelProperty*>(pGeoProperty)->setDeviceKind(DeviceKind::DK_SIMU);
					break;
				case DeviceType::DT_CARDREADER:
					pGeoProperty = new VirtualMine::GeoProperty::CCardModelProperty();
					dynamic_cast<CCardModelProperty*>(pGeoProperty)->setDeviceKind(DeviceKind::DK_LOCATION);
					break;
				default:
					pGeoProperty = new VirtualMine::GeoProperty::CModelProperty();
					break;
				}
				CGeoObject::setGeoProperty(pGeoProperty,true);
			}
			return  CGeoObject::getGeoProperty();
		}

		void CModelObject::fromFeature(VirtualMine::Database::IFeature* pFeature)
		{
			assert(pFeature);
			if (NULL == pFeature)
			{
				return;
			}

			void* pData = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(0).getVarient().data();
			int* id = (int*)pData;

			void* pData1 = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(1).getVarient().data();
			char* name = (char*)pData1;

			void* pData2 = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(2).getVarient().data();
			char* type = (char*)pData2; 

			void* pData3 = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(3).getVarient().data();
			double* posX = (double*)pData3;

			void* pData4 = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(4).getVarient().data();
			double* posY = (double*)pData4;

			void* pData5 = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(5).getVarient().data();
			double* posZ = (double*)pData5;


			void* pData6 = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(6).getVarient().data();
			double* scaleX = (double*)pData6;

			void* pData7 = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(7).getVarient().data();
			double* scaleY = (double*)pData7;

			void* pData8 = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(8).getVarient().data();
			double* scaleZ = (double*)pData8;


			void* pData9 = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(9).getVarient().data();
			double* transX = (double*)pData9;

			void* pData10 = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(10).getVarient().data();
			double* transY = (double*)pData10;

			void* pData11 = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(11).getVarient().data();
			double* transZ = (double*)pData11;

			void* pData12 = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(12).getVarient().data();
			double* rotateX = (double*)pData12;

			void* pData13 = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(13).getVarient().data();
			double* rotateY = (double*)pData13;

			void* pData14 = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(14).getVarient().data();
			double* rotateZ = (double*)pData14;





			void* pData15 =  static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(15).getVarient().data();
			Ogre::uchar* pGeoLayerInfo = static_cast<Ogre::uchar*>(pData15);			
			////////
			int legth = static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(15).getVarient().getLength();

			void* pData16 =  static_cast<VirtualMine::Database::CModelFeature*>(pFeature)->getPropertySet()->getFields().at(16).getVarient().data();

			int* devicetype = (int*)pData16;
			

			Ogre::Vector3 modelscale(*scaleX,*scaleY,*scaleZ);
			Ogre::Vector3 modeltrans(*transX,*transY,*transZ);
			Ogre::Vector3 modelrotate(*rotateX,*rotateY,*rotateZ);

			VirtualMine::SpatialInterface::CParameter par;
			par.setTranslate(modeltrans);
			par.setScale(modelscale);
			par.setRotate(modelrotate);

			dynamic_cast<CModelStyle*>(this->getStyle())->setParameter(par);
	        //dynamic_cast<CJianceModelProperty*>(this->getGeoProperty())->setMeshName();
			
			std::string objectName = name;
			this->setName(objectName);
			this->setID(*id);
			static_cast<CPoint*>(this->getGeometry())->setX(*posX - IScene::ReferenceCenter.x);
			static_cast<CPoint*>(this->getGeometry())->setY(*posY - IScene::ReferenceCenter.y);
			static_cast<CPoint*>(this->getGeometry())->setZ((*posZ - IScene::ReferenceCenter.z) * IScene::CoefficientOfCoordinateTransform);

			VirtualMine::Core::CVRDataStream ds;	
			ds.wirteBlob(pGeoLayerInfo,legth);
			ds.reseek(0);

			std::string dt = type;
			int tpid = Ogre::StringConverter::parseInt(dt);
			this->setDeviceType(VirtualMine::Core::DeviceType(tpid));
			(this->getGeoProperty())->fromStream(ds);
			

		}

		VirtualMine::Database::IFeature* CModelObject::toFeature()
		{
			int modelId = this->getID();
			double posX = dynamic_cast<CPoint*>(this->getGeometry())->getX();
			double posY = dynamic_cast<CPoint*>(this->getGeometry())->getY();
			double posZ = dynamic_cast<CPoint*>(this->getGeometry())->getZ();

			CParameter par = dynamic_cast<CModelStyle*>(this->getStyle())->getParameter();
			Ogre::Vector3 scale = par.getScale();
			Ogre::Vector3 rotate = par.getRoate();
			Ogre::Vector3 trans = par.getTranslate();

			std::string objectname = this->getName();
			
			VirtualMine::Core::DeviceType devicetype = this->getDeviceType();
			int dtype = devicetype;
			std::string type = Ogre::StringConverter::toString(dtype);
			VirtualMine::Core::CVRDataStream ds;
			////需要判断不同模型类型
			//if (devicetype == VirtualMine::Core::DeviceType::DT_CARDREADER)
			//{
			//	dynamic_cast<CCardModelProperty*>(this->getGeoProperty())->toStream(ds);
			//}
			//else
			//{
			//   dynamic_cast<CJianceModelProperty*>(this->getGeoProperty())->toStream(ds);
			//}
			//
			this->getGeoProperty()->toStream(ds);
			ds.reseek(0);

			CModelFeature* feature = new CModelFeature();
			///id 设为 类型的数值
			feature->setFieldID(modelId);			
			feature->setFieldName(objectname);
			feature->setFieldType(type);

			feature->setFieldPosX(posX);
			feature->setFieldPosY(posY);
		    feature->setFieldPosZ(posZ);

			feature->setFieldRotateX(rotate.x);
			feature->setFieldRotateY(rotate.y);
			feature->setFieldRotateZ(rotate.z);
			
			feature->setFieldScaleX(scale.x);
			feature->setFieldScaleY(scale.y);
			feature->setFieldScaleZ(scale.z);

			feature->setFieldTransX(trans.x);
			feature->setFieldTransY(trans.y);
			feature->setFieldTransZ(trans.z);

			feature->setFieldBlob(ds.getData(),ds.getLength());
			feature->setFieldDeviceType(devicetype);
			
			feature->setDeviceType(devicetype);

			return feature;

		}

		void CModelObject::setDeviceType(VirtualMine::Core::DeviceType deviceType /* = VirtualMine::Core::DeviceType::DT_UNKNOWN */)
		{
			this->mDeviceType = deviceType;
		}
		
		VirtualMine::Core::DeviceType CModelObject::getDeviceType()
		{
			return this->mDeviceType;
		}
	}

}
