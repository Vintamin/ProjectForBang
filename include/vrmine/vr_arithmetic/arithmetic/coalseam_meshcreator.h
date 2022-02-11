//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : ccoalseam_meshcreator.h
//  @ Date : 2014/7/5
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_CCOALSEAM_MESHCREATOR_H)
#define _CCOALSEAM_MESHCREATOR_H

#include "vrmine/vr_spatialinterface/igeomeshcreator.h"
#include "vrmine\vr_arithmetic\arithmetic_config.h"

//#define borderNodesCount 5 


namespace VirtualMine
{
	namespace Arithmetic
	{
		class VR_ARITHMETIC_DLL CCoalSeam_MeshCreator : public VirtualMine::SpatialInterface::CGeoMeshCreator
		{
		public:
			CCoalSeam_MeshCreator();
			~CCoalSeam_MeshCreator();
		public:
			
			//void createData2(VirtualMine::SpatialInterface::GeoObjectVector& geoObjectVector,std::vector<VirtualMine::SpatialInterface::CGeoExtentionData*>& geoExtentionDatas);

			void createData(VirtualMine::SpatialInterface::GeoObjectVector& geoObjectVector,std::vector<VirtualMine::SpatialInterface::CGeoExtentionData*>& geoExtentionDatas);
			
		//private:
		//	std::vector<Ogre::Vector3> boderNodes; //
		//	std::vector<Ogre::Vector3> tempVec2; //
			
		};
	}
}

#endif  //_CCOALSEAM_MESHCREATOR_H
