//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : workingplanestyle.cpp
//  @ Date : 2014/10/26
//  @ Author : 王凯
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine/vr_style/style/workingplanestyle.h"

namespace VirtualMine
{
	namespace Style
	{
		CWorkingplaneStyle::CWorkingplaneStyle()
		{
			this->mFontColor = Ogre::ColourValue(0,0,0,0.6);
			this->mFillColor = Ogre::ColourValue(0.8,0,0,1);
		}

		CWorkingplaneStyle::~CWorkingplaneStyle()
		{

		}

		void CWorkingplaneStyle::setFontColor(const Ogre::ColourValue& color)
		{
			this->mFontColor = color;
		}

		Ogre::ColourValue CWorkingplaneStyle::getFontColor()
		{
			return this->mFontColor;
		}

		void CWorkingplaneStyle::setFillColor(const Ogre::ColourValue& color)
		{
			this->mFillColor = color;
		}

		Ogre::ColourValue CWorkingplaneStyle::getFillColor()
		{
			return this->mFillColor;
		}
	}
}
