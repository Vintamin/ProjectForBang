//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : line.h
//  @ Date : 2014/8/6
//  @ Author : 朱炜鹏
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_DRILLHOLE_H)
#define _DRILLHOLE_H

#include "vrmine/vr_spatialinterface/igeometry.h"
#include "vrmine\vr_geometry\geometry\geometry_config.h"
#include "vrmine/vr_core/coredefine.h"
#include "vrmine/vr_geometry/geometry/point.h"
#include <OGRE/Ogre.h>

namespace VirtualMine
{
	namespace Geometry
	{
		class VR_GEOMETRY_DLL CDrillHoleGeometry : public VirtualMine::Geometry::CPoint
		{
		public: 
			CDrillHoleGeometry();
			CDrillHoleGeometry(const double& x,const double& y,const double& z);
			~CDrillHoleGeometry();
			
		};
	}
}

#endif  //_DRILLHOLE_H
