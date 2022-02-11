//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : geospatialscene.cpp
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine\vr_spatialinterface\iscene.h"

namespace VirtualMine
{
	namespace SpatialInterface
	{
		
	

		//Ogre::Vector3 IScene::ReferenceCenter(Ogre::Vector3(37538868.246,156.41852,3062404.156));
	
		Ogre::Vector3 IScene::ReferenceCenter(Ogre::Vector3::ZERO);
		Ogre::Real IScene::CoefficientOfCoordinateTransform(-1);

		IScene::IScene()
		{
		
		}

		IScene::~IScene()
		{

		}
 
		Ogre::Vector3 IScene::transformCoor(const Ogre::Vector3& coor)
		{
			Ogre::Vector3 r = coor;
			r.z *= -1;
			r += IScene::ReferenceCenter;
			return r;
		}
		/*void IScene::toFile(const std::string& filename)
		{

		}

		void IScene::fromFile(const std::string& filename)
		{

		}*/
	
	}
}
