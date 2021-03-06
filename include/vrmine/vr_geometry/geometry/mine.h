//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : mine.h
//  @ Date : 2014/8/6
//  @ Author : 朱炜鹏
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_MINE_H)
#define _MINE_H

#include "vrmine/vr_spatialinterface/igeometry.h"
#include "vrmine\vr_geometry\geometry\geometry_config.h"
#include "vrmine/vr_core/coredefine.h"
#include "vrmine/vr_geometry/geometry/line.h"
#include <OGRE/Ogre.h>

namespace VirtualMine
{
	namespace Geometry
	{
		// 矿井
		class VR_GEOMETRY_DLL CMineGeometry : public VirtualMine::Geometry::CPoint
		{
		public: 
			CMineGeometry();
			~CMineGeometry();
		};
	}
}

#endif  //_MINE_H
