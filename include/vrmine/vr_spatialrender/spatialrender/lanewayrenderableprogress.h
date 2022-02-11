//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : tunnelrenderableobject.h
//  @ Date : 2021/11/29
//  @ Author : 李佳康
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : tunnelrenderable


#if !defined(_TUNNELRENDERABLEOBJECTPRO_H)
#define _TUNNELRENDERABLEOBJECTPRO_H

#include "vrmine/vr_spatialrender/baserender/geomultirenderableobject.h"
#include "vrmine/vr_arithmetic/arithmetic/lanewayprogress_meshcreator.h"

namespace VirtualMine
{
	namespace SpatialRender
	{
		class VR_SPATIALRENDER_DLL CLanewayRenderableProgress : public VirtualMine::BaseRender::CGeoMultiRenderableObject
		{
		public:
			CLanewayRenderableProgress();
			~CLanewayRenderableProgress();	
		public:
			//kk传递mTextNodes
			//void build(std::vector<Ogre::SceneNode*> &mTextNodes);
			void build(std::vector<Ogre::SceneNode*> &mTextNodes);
			void render();
			void deRender();

		};
	}
}

#endif  //_TUNNELRENDERABLEOBJECT_H
