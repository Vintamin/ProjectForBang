//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : surfaceobject.h
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_SURFACEOBJECT_H)
#define _SURFACEOBJECT_H

#include "..\base\igeoobject.h"


namespace VirtualMine
{
	namespace Mine
	{
		class VR_SPATIALOBJECT_DLL CSurfaceObject : public VirtualMine::Base::IGeoObject
		{
			virtual void fromFeature(VirtualMine::Database::IFeature* pFeature);
			virtual VirtualMine::Database::IFeature* toFeature();
		};
	}
}

#endif  //_SURFACEOBJECT_H
