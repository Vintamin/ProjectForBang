//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : tunnelobject.h
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_LANEWAYOBJECT_H)
#define _LANEWAYOBJECT_H

#include "vrmine\vr_spatialinterface\igeoobject.h"
#include "vrmine/vr_style/style/lanewaystyle.h"
#include "vrmine\vr_spatialobject\spatialobject_config.h"

namespace VirtualMine
{
	namespace Mine
	{
		class VR_SPATIALOBJECT_DLL CLaneWayObject : public VirtualMine::SpatialInterface::CGeoObject
		{
		public: 
			CLaneWayObject();
			~CLaneWayObject();
		public:
			 VirtualMine::SpatialInterface::IStyle* getStyle();
			 VirtualMine::SpatialInterface::IGeometry* getGeometry();
			 VirtualMine::SpatialInterface::IGeoProperty* getGeoProperty();

			virtual void fromFeature(VirtualMine::Database::IFeature* pFeature);
			virtual VirtualMine::Database::IFeature* toFeature();
		};
	}
}

#endif  //_LANEWAYOBJECT_H
