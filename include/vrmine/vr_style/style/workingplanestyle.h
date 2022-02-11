//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : workingplanestyle.h
//  @ Date : 2014/10/26
//  @ Author : ����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(WORKINGPLANESTYLE_H)
#define WORKINGPLANESTYLE_H

#include "vrmine\vr_style\style_config.h"
#include "vrmine/vr_spatialinterface/istyle.h"

namespace VirtualMine
{
	namespace Style
	{
		class VR_STYLE_DLL CWorkingplaneStyle : public VirtualMine::SpatialInterface::CStyle
		{
		public:
			CWorkingplaneStyle();
			~CWorkingplaneStyle();
		public:
			void setFontColor( const Ogre::ColourValue& color);
			Ogre::ColourValue getFontColor();

			void setFillColor(const Ogre::ColourValue& color);
			Ogre::ColourValue getFillColor();
		private:
			Ogre::ColourValue mFontColor;
			Ogre::ColourValue mFillColor;
		};
	}
}

#endif  //WORKINGPLANESTYLE_H