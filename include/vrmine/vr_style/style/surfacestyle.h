//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : surfacestyle.h
//  @ Date : 2014/7/6
//  @ Author : ʢ����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
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