//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : cylinder.h
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_CYLINDER_H)
#define _CYLINDER_H

#include "vrmine/vr_spatialinterface/igeometry.h"
#include "vrmine\vr_geometry\geometry\geometry_config.h"

namespace VirtualMine
{
	namespace Geometry
	{
		class VR_GEOMETRY_DLL CCylinder : public VirtualMine::SpatialInterface::CGeometry
		{
		public:
			void getRadius();
			void setRadius();
			void getTop();
			void setTop();
			void getBottom();
			void setBottom();
		};
	}
}

#endif  //_CYLINDER_H
