//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : parameter .cpp
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine\vr_spatialinterface\parameter.h"

namespace VirtualMine
{
	namespace SpatialInterface
	{
		CParameter::CParameter()
			:mScale(Ogre::Vector3::UNIT_SCALE),
			mRotate(Ogre::Vector3::ZERO),
			mTranslate(Ogre::Vector3::ZERO)
		{
		
		}

		CParameter::~CParameter()
		{
		
		}

		Ogre::Vector3& CParameter::getScale()
		{
			return this->mScale;
		}

		Ogre::Vector3& CParameter::getRoate()
		{
			return this->mRotate;
		}

		Ogre::Vector3& CParameter::getTranslate()
		{
			return this->mTranslate;
		}

		void CParameter::setScale(const Ogre::Vector3& scale)
		{
			this->mScale = scale;
		}

		void CParameter::setRotate(const Ogre::Vector3& rotate)
		{
			this->mRotate = rotate;
		}

		void CParameter::setTranslate(const Ogre::Vector3& translate)
		{
			this->mTranslate = translate;
		}

	}
}
