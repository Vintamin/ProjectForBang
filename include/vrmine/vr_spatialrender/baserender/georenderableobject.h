//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : georenderableobject.h
//  @ Date : 2014/7/6
//  @ Author : ʢ����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_GEORENDERABLEOBJECT_H)
#define _GEORENDERABLEOBJECT_H

#include "vrmine\vr_spatialinterface\irenderableobject.h"
#include "vrmine\vr_spatialinterface\igeoobject.h"
#include "vrmine\vr_spatialrender\spatialrender_config.h"

namespace VirtualMine
{
	namespace BaseRender
	{
		class VR_SPATIALRENDER_DLL CGeoRenderableObject : public VirtualMine::SpatialInterface::IRenderableObject
		{
		public:
			CGeoRenderableObject();
			virtual ~CGeoRenderableObject();
			void setGeoObject(VirtualMine::SpatialInterface::CGeoObject* geoObject);
			VirtualMine::SpatialInterface::CGeoObject* getGeoObject();
		protected:
			VirtualMine::SpatialInterface::CGeoObject* mpGeoObject ;
		};
	}
}

#endif  //_GEORENDERABLEOBJECT_H