//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : igeometry.cpp
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine\vr_spatialinterface\igeometry.h"

namespace VirtualMine
{
	namespace SpatialInterface
	{
		IGeometry::IGeometry()
		{

		}
		IGeometry::~IGeometry()
		{

		}

		void IGeometry::toStream(VirtualMine::Core::CVRDataStream& datastream)
		{

		}
	    void IGeometry::fromStream(VirtualMine::Core::CVRDataStream& datastream)
		{

		}

		CGeometry::CGeometry()
			:ref_mpSR(NULL)
		{

		}
		CGeometry::~CGeometry()
		{

		}

		void CGeometry::copyTo(IGeometry* pGeometry)
		{
		
		}

		IGeometry* CGeometry::clone()
		{
			return NULL;
			//throw std::exception("it's not implemented");
		}

		VirtualMine::SpatialInterface::ISpatialReference* CGeometry::getSpatialReference()
		{
			return this->ref_mpSR;
		}

		void CGeometry::setSpatialReference(VirtualMine::SpatialInterface::ISpatialReference* pSpatialReference)
		{
			this->ref_mpSR = pSpatialReference;
		}

	    void CGeometry::toStream(VirtualMine::Core::CVRDataStream& datastream)
		{

		}

		void CGeometry::fromStream(VirtualMine::Core::CVRDataStream& datastream)
		{

		}
	}
}
