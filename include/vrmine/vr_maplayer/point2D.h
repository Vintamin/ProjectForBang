//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : point.h
//  @ Date : 2015/8/3
//  @ Author : ������
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 




#include "vrmine/vr_spatialinterface/igeometry.h"
#include "vrmine\vr_geometry\geometry\geometry_config.h"
#include "vrmine/vr_geometry/geometry/point.h"
#include "vrmine/vr_maplayer/igeometrydrawitem.h"

#if !defined(_CPOINT2D_H)
#define _CPOINT2D_H
   namespace VirtualMine
  {	
	namespace Map
	{
		class VR_MAPLAYER_EXPORT CPoint2D : public VirtualMine::Geometry::CPoint
	{
		public:
			CPoint2D();
			~CPoint2D();
			//double& getX();
			//double& getY();
			//double& getZ();
			//void setX(const double& x);
			//void setY(const double& y);
			//void setZ(const double& z);
			virtual void setID(const int& ID);
			virtual int getID();
	private:	
			int mID;
		};
	}
   }
#endif