//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : point.h
//  @ Date : 2015/8/3
//  @ Author : 王向上
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine/vr_maplayer/point2D.h"

namespace VirtualMine
{
	namespace Map
	{
		CPoint2D::CPoint2D()
		{
		}

		CPoint2D::~CPoint2D()
		{

		}	

		void CPoint2D::setID(const int& ID)
		{
			this->mID=ID;
		}

		int CPoint2D::getID()
		{
			return mID;
		}

	}



}
