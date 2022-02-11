//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : pointstyle.cpp
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine\vr_style\style\pointstyle.h"

namespace VirtualMine
{
	namespace Style
	{
		CPointStyle::CPointStyle()
			:mSize(5),mRenderMode(PRM_COLOUR),mIconName("")
		{
			
		}

		CPointStyle::~CPointStyle()
		{
		
		}

		void CPointStyle::setIconName(const std::string& iconName)
		{
			this->mIconName = iconName;
		}
		
		std::string CPointStyle::getIconName()
		{
			return this->mIconName;
		}
		
		void CPointStyle::setPointRenderMode(const CPointStyle::PointRenderMode& renderMode)
		{
			this->mRenderMode = renderMode;
		}
		
		CPointStyle::PointRenderMode CPointStyle::getPointRenderMode()
		{
			return this->mRenderMode;
		}

		void CPointStyle::setSize(const int& size)
		{
			this->mSize = size;
		}

		int CPointStyle::getSize()
		{
			return this->mSize;
		}

	}
}
