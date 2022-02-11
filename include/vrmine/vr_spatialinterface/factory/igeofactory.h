//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : igeofactory.h
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_IGEOFACTORY_H)
#define _IGEOFACTORY_H

#include "vrmine\vr_spatialinterface\spatialinterface_config.h"

namespace VirtualMine
{
	namespace SpatialInterface
	{
		class VR_SPATIALINTERFACE_DLL IGeoFactory
		{
		public:
			void createInstance();
			void destroyInstance();
			void getType();
		};
	}
}

#endif  //_IGEOFACTORY_H
