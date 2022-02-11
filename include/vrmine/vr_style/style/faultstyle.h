//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : faultstyle.h
//  @ Date : 2014/8/6
//  @ Author : 朱炜鹏
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_FAULTSTYLE_H)
#define _FAULTSTYLE_H

#include "vrmine\vr_style\style_config.h"
#include "vrmine/vr_spatialinterface/istyle.h"

namespace VirtualMine
{
	namespace Style
	{
		class VR_STYLE_DLL CFaultStyle : public VirtualMine::SpatialInterface::CStyle
		{
		public:
			CFaultStyle();
			~CFaultStyle();
		public:
			void setFaultColor(const Ogre::ColourValue& color);
			Ogre::ColourValue getFaultColor();

			void setTextureName(const std::string& name);
			std::string getTextureName();
		private:
			Ogre::ColourValue mColor;
			std::string mTextureName;

		};
	}
}

#endif  //_FAULTSTYLE_H
