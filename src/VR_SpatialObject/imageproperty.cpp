//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : imageproperty.cpp
//  @ Date : 2014/8/6
//  @ Author : 朱炜鹏
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine/vr_spatialobject/geoproperty/imageproperty.h"

namespace VirtualMine
{
	namespace GeoProperty
	{

		CImageProperty::CImageProperty()
		{

		}

		CImageProperty::~CImageProperty()
		{

		}

		VirtualMine::SpatialInterface::IGeoProperty* CImageProperty::clone()
		{
			return NULL;
		}

		void CImageProperty::setName(const std::string& name)
		{
			this->mName = name;
		}

		std::string CImageProperty::getName()
		{
			return this->mName;
		}

		void CImageProperty::setImage(const Ogre::Image& image)
		{
			this->mImage = image;
		}

		Ogre::Image CImageProperty::getImage()
		{
			return this->mImage;
		}
	}
}
