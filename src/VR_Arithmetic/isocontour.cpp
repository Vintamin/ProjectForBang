//#include "stdafx.h"


//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : Delaunay.cpp
//  @ Date : 2015/6/18
//  @ Author : ������
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 

#include "vrmine/vr_arithmetic/arithmetic/isocontour.h"

namespace VirtualMine
{
	namespace Arithmetic
	{
		isocontour::isocontour()
		 {

	
		}
		isocontour::~isocontour()
		{

		}
	    std::vector<De_point> isocontour::isoline_con(std::vector<De_point>& V,double h)
		{
			h=h+0.1111111;
			std::vector<De_point> Cp;

			for ( int i=0;i<V.size();i+=3)
			{
			
			  De_point m=V.at(i);
			  De_point n=V.at(i+1);
			  De_point p=V.at(i+2);
				if ((m.Z-h)*(n.Z-h)<0)
				{
					first_1.X=(int)(m.X+(n.X-m.X)*(h-m.Z)/(n.Z-m.Z));
					first_1.Y=(int)(m.Y+(n.Y-m.Y)*(h-m.Z)/(n.Z-m.Z));
					first_1.Z=h-0.1;
				//	L.m=first_1;
					Cp.push_back(first_1);
					
					if ((m.Z-h)*(p.Z-h)<0)
					{
						second_2.X=(int)(m.X+(p.X-m.X)*(h-m.Z)/(p.Z-m.Z));
						second_2.Y=(int)(m.Y+(p.Y-m.Y)*(h-m.Z)/(p.Z-m.Z));
						second_2.Z=h-0.1;
					//	L.n=second_2;
						Cp.push_back(second_2);
					} 
					else 
					{
						second_2.X=(int)(n.X+(p.X-n.X)*(h-n.Z)/(p.Z-n.Z));
						second_2.Y=(int)(n.Y+(p.Y-n.Y)*(h-n.Z)/(p.Z-n.Z));
						second_2.Z=h-0.1;
						//L.n=second_2;
						Cp.push_back(second_2);
					}
				} 
				else if((m.Z-h)*(p.Z-h)<0)
				{
					first_1.X=(int)(m.X+(p.X-m.X)*(h-m.Z)/(p.Z-m.Z));
					first_1.Y=(int)(m.Y+(p.Y-m.Y)*(h-m.Z)/(p.Z-m.Z));
					first_1.Z=h-0.1;
				//	L.m=first_1;
					Cp.push_back(first_1);
					second_2.X=(int)(n.X+(p.X-n.X)*(h-n.Z)/(p.Z-n.Z));
					second_2.Y=(int)(n.Y+(p.Y-n.Y)*(h-n.Z)/(p.Z-n.Z));
					second_2.Z=h-0.1;
					//L.n=second_2;
					Cp.push_back(second_2);
//
				}
				
		
			}
			//return Lp;
			return Cp;

		}



	}
}