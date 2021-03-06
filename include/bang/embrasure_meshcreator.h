//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : cdrill_meshcreator.h
//  @ Date : 2014/7/5
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 
#if !defined(_CEMBRASURE_MESHCREATOR_H)
#define _CEMBRASURE_MESHCREATOR_H

#include "vrmine/vr_spatialinterface/igeomeshcreator.h"
#include <OGRE\Ogre.h>
#include "bang\bang_render_config.h"

namespace BangRender
{
	namespace Arithmetic
	{		
		class BANG_RENDER_DLL CEmbrasure_MeshCreator : public VirtualMine::SpatialInterface::CGeoMeshCreator
		{
		public: 
			CEmbrasure_MeshCreator();
			~CEmbrasure_MeshCreator();
		public:
			void createData(VirtualMine::SpatialInterface::GeoObjectVector& geoObjectVector,std::vector<VirtualMine::SpatialInterface::CGeoExtentionData*>& geoExtentionDatas);

		//private:
		//	std::string createDrillMaterial(std::string materialName);
		//	//Ogre::ManualObject* createUnitDrill();
		//    CDrillSection* createSectionPoints(const Ogre::Vector3& position,const float& radius);

			
		//private:
			//std::vector<CDrillSection*> mSections; 
			//VirtualMine::SpatialLayer::CDemLayer* ref_pDemLayer;
		};


	}
}

#endif  //_CDRILL_MESHCREATOR_H