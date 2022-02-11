//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : polygon.h
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_POLYGON_H)
#define _POLYGON_H

#include "vrmine/vr_spatialinterface/igeometry.h"
#include "vrmine/vr_core/coredefine.h"
#include "vrmine/vr_geometry/geometry/point.h"

namespace VirtualMine
{
	namespace Geometry
	{
		class VR_GEOMETRY_DLL CPolygon : public VirtualMine::SpatialInterface::CGeometry
		{
		public:
			CPolygon();
			virtual ~CPolygon();
			void addPoint(CPoint& point);
			void addPoint(const double& x,const double& y,const double& z);
			CPoint getPoint(const size_t& index);
			size_t getCount();
			void removePoint(const size_t& index);
			virtual void toStream(VirtualMine::Core::CVRDataStream& datastream);
			virtual void fromStream(VirtualMine::Core::CVRDataStream& datastream);



		private:
			DoubleVector mXCoors;
			DoubleVector mYCoors;
			DoubleVector mZCoors;
		};
	}
}

#endif  //_POLYGON_H
