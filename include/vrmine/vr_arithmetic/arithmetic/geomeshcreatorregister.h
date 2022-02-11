//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : cgeomeshcreatorregister.h
//  @ Date : 2014/7/5
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_CGEOMESHCREATORREGISTER_H)
#define _CGEOMESHCREATORREGISTER_H

#include "vrmine/vr_arithmetic/arithmetic_config.h"
#include "vrmine/vr_spatialinterface/igeomeshcreator.h"
#include <map>

namespace VirtualMine
{
	namespace Arithmetic
	{
		class VR_ARITHMETIC_DLL CGeoMeshCreatorRegister
		{
			typedef std::map<std::string,VirtualMine::SpatialInterface::IGeoMeshCreator*> GeoMeshCreatorMap;
		public:
			virtual ~CGeoMeshCreatorRegister();
			bool registerGeoMeshCreator(VirtualMine::SpatialInterface::IGeoMeshCreator* pGeoMeshCreator);
			bool unRegisterGeoMeshCreator(const std::string& type);
			VirtualMine::SpatialInterface::IGeoMeshCreator* getGeoMeshCreator(const std::string& type);
			static CGeoMeshCreatorRegister& getSingleton();
			static CGeoMeshCreatorRegister* getSingletonPtr();
		protected:
			CGeoMeshCreatorRegister();
		protected:
			static CGeoMeshCreatorRegister* mpSingletonPtr;

			GeoMeshCreatorMap mGeoMeshCreatorMap;
		};
	}
}

#endif  //_CGEOMESHCREATORREGISTER_H
