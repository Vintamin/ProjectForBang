//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : istyle.h
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_ISTYLE_H)
#define _ISTYLE_H

#include "vrmine\vr_spatialinterface\spatialinterface_config.h"
#include "vrmine\vr_core\baseobject.h"
#include "OGRE\OgreColourValue.h"

namespace VirtualMine
{
	namespace SpatialInterface
	{
		class VR_SPATIALINTERFACE_DLL IStyle : public VirtualMine::Core::CBaseObject
		{
		public:
			IStyle();
			virtual ~IStyle();
			virtual Ogre::ColourValue& getColor()=0;
			virtual void setColor(const Ogre::ColourValue& color)=0;
			virtual Ogre::ColourValue& getHighlightColor()=0;
			virtual void setHighlightColor(const Ogre::ColourValue& color)=0;
			virtual std::string getType()=0;
			virtual IStyle* clone()=0;
			virtual std::string toString()=0;
		};

		class VR_SPATIALINTERFACE_DLL CStyle : public IStyle
		{
		public:
			CStyle();
			virtual ~CStyle();
			Ogre::ColourValue& getColor();
			void setColor(const Ogre::ColourValue& color);
			Ogre::ColourValue& getHighlightColor();
			void setHighlightColor(const Ogre::ColourValue& color);
			virtual std::string getType();
			virtual IStyle* clone();
			virtual std::string toString();
		protected:
			Ogre::ColourValue mColor;
			Ogre::ColourValue mHighlightColor;
			std::string mType;

		};
	}
}
#endif  //_ISTYLE_H
