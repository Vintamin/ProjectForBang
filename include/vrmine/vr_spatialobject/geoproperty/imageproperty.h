//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : imageproperty.h
//  @ Date : 2014/8/6
//  @ Author : �����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_IMAGEPROPERTY_H)
#define _IMAGEPROPERTY_H

#include "vrmine/vr_core/coredefine.h"
#include "vrmine/vr_spatialinterface/igeoproperty.h"
#include "vrmine\vr_spatialobject\spatialobject_config.h"
#include <OGRE\Ogre.h>

namespace VirtualMine
{
	namespace GeoProperty
	{
		class VR_SPATIALOBJECT_DLL CImageProperty : public VirtualMine::SpatialInterface::CGeoProperty
		{
		public:
			CImageProperty();
			~CImageProperty();
		public:
			VirtualMine::SpatialInterface::IGeoProperty* clone();

			void setName(const std::string& name);
			std::string getName();

			void setImage(const Ogre::Image& image);
			Ogre::Image getImage();

		private:
			std::string mName;
			Ogre::Image mImage;
		};
	}
}

#endif  //_IMAGEPROPERTY_H