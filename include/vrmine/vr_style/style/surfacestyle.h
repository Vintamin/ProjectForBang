//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : surfacestyle.h
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_SURFACESTYLE_H)
#define _SURFACESTYLE_H

#include "vrmine\vr_style\style_config.h"
#include "vrmine/vr_spatialinterface/istyle.h"

namespace VirtualMine
{
	namespace Style
	{
		class  VR_STYLE_DLL CSurfaceStyle : public VirtualMine::SpatialInterface::CStyle
		{
		public:
			void hasFrame();
			void setFrame();
		};
	}
}

#endif  //_SURFACESTYLE_H
