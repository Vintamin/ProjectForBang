//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : fault.h
//  @ Date : 2014/8/6
//  @ Author : �����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 



#if !defined(_FAULT_H)
#define _FAULT_H

#include "vrmine/vr_spatialinterface/igeometry.h"
#include "vrmine\vr_geometry\geometry\geometry_config.h"
#include "vrmine/vr_core/coredefine.h"
#include "vrmine/vr_geometry/geometry/line.h"
#include <OGRE/Ogre.h>

namespace VirtualMine
{
	namespace Geometry
	{
		class VR_GEOMETRY_DLL CFaultGeometry : public VirtualMine::Geometry::CLine
		{
		public: 
			CFaultGeometry();
			~CFaultGeometry();

		};
	}
}

#endif  //_FAULT_H