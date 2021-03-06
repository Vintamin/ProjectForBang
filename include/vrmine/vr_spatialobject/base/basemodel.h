//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : geoline.h
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_BASEMODEL_H)
#define _BASEMODEL_H

#include "vrmine\vr_spatialinterface\igeoobject.h"
#include "vrmine\vr_spatialobject\spatialobject_config.h"
#include "vrmine/vr_style/style/linestyle.h"
#include "vrmine/vr_geometry/geometry/line.h"
#include "vrmine/vr_spatialinterface/igeoproperty.h"


namespace VirtualMine
{
	namespace Base
	{
		class VR_SPATIALOBJECT_DLL CBaseModelObject : public VirtualMine::SpatialInterface::CGeoObject
		{
		public:
			CBaseModelObject();
			virtual ~CBaseModelObject();
			VirtualMine::SpatialInterface::IStyle* getStyle();
			VirtualMine::SpatialInterface::IGeometry* getGeometry();
			VirtualMine::SpatialInterface::IGeoProperty* getGeoProperty();
		};
	}
}

#endif  //_BASEMODEL_H
