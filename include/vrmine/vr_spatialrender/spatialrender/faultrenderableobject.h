//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : faultrenderableobject.h
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_FAULTRENDERABLEOBJECT_H)
#define _FAULTRENDERABLEOBJECT_H

#include "vrmine/vr_spatialrender/baserender/geomultirenderableobject.h"
#include <OGRE/Ogre.h>


namespace VirtualMine
{
	namespace SpatialRender
	{
		class VR_SPATIALRENDER_DLL CFaultRenderableObject : public VirtualMine::BaseRender::CGeoMultiRenderableObject
		{
		public:
			CFaultRenderableObject();
			~CFaultRenderableObject();	
		public:
			void build();
			void render();
			void deRender();

		};
	}
}

#endif  //_FAULTRENDERABLEOBJECT_H
