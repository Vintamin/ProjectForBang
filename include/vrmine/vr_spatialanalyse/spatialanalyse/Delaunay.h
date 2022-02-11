//#include "stdafx.h"
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : Delaunay.h
//  @ Date : 2015/6/18
//  @ Author : 王向上
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 

#if !defined(_DELAUNAY_H)
#define _DELAUNAY_H

#include "vrmine/vr_spatialanalyse/spatialanalyse_config.h"
#include "vrmine/vr_core/coredefine.h"
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Triangulation_euclidean_traits_xy_3.h>
#include <CGAL/Delaunay_triangulation_2.h>

#include <iostream>
#include <cmath>
#include <vector>
#include "ogre/Ogre.h"
#include <map>

namespace VirtualMine
{
	namespace SpatialAnalyse
	{
		typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
		typedef CGAL::Delaunay_triangulation_2<K> Delaunay;
		typedef Delaunay::Vertex_handle Vertex_handle;

		typedef K::Point_2 Point_GL;


		class  VR_SPATIALANALYSE_DLL Tri_Delaunay
		{
		public:
			Tri_Delaunay();
			virtual ~Tri_Delaunay();

		public:
			std::vector<De_point>	Triangle_Delaunay(std::vector<De_point>& v);

			std::vector<De_point>	Triangle_D3(std::vector<De_point>& v3,std::vector<De_point>& v);

		private:
			int global_w, global_h;
			std::vector<De_point> v1;
			std::vector<De_point> vv;
			//int tri_state = 0;
			std::vector<Point_GL> vertices;
			//static int count;
		private:
			void Triangle_2(std::vector<De_point>& v);
			void points_add_point( double x, double y );
			std::vector<De_point> points_triangulation();


		};
	}
}

#endif  //_DISTANCEMEASURETOOL_H