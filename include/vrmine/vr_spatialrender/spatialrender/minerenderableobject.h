//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : minerenderableobject.h
//  @ Date : 2014/7/6
//  @ Author : ʢ����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_MINERENDERABLEOBJECT_H)
#define _MINERENDERABLEOBJECT_H

#include "vrmine/vr_spatialrender/baserender/geomultirenderableobject.h"
#include <OGRE/Ogre.h>


namespace VirtualMine
{
	namespace SpatialRender
	{
		class VR_SPATIALRENDER_DLL CMineRenderableObject : public VirtualMine::BaseRender::CGeoMultiRenderableObject
		{
		public:
			CMineRenderableObject();
			~CMineRenderableObject();	
		public:
			void build();
			void render();
			void deRender();

		};
	}
}

#endif  //_MINERENDERABLEOBJECT_H