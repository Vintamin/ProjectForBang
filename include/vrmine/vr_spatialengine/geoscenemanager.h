//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : geoscenemanager.h
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_GEOSCENEMANAGER_H)
#define _GEOSCENEMANAGER_H

#include "vrmine\vr_spatialengine\spatialengine_config.h"
#include "OGRE\OgreSceneManager.h"
#include "vrmine\vr_spatialengine\geoscenecamera.h"
#include "OGRE\Threading\OgreThreadDefines.h"
#include "OGRE\OgreSceneQuery.h"


namespace VirtualMine
{
	namespace SpatialEngine
	{
		class VR_SPATIALENGINE_DLL CGeoSceneManager : public Ogre::SceneManager
		{
		public:
			CGeoSceneManager(const Ogre::String& instanceName);
			~CGeoSceneManager(void);
			//void setcene(VirtualMine::SpatialEngine::CGeoSpatialScene* ref_pScene);
			//VirtualMine::SpatialEngine::CGeoSpatialScene* getSceneRef(); 
			const Ogre::String& getTypeName(void) const;
			virtual CGeoSceneCamera* getDefaultCamera();
			virtual Ogre::Camera* createCamera(const Ogre::String& name);
			virtual Ogre::RaySceneQuery* createRayQuery(const Ogre::Ray& ray, unsigned long mask = 0xFFFFFFFF);
			bool getRayIntersectedPoint(const int& screenX ,const int& screenY,Ogre::Vector3& intersectPoint);
			void rayQuery(const int& screenX ,const int& screenY,Ogre::Vector3& intersectPoint,
				Ogre::RaySceneQueryResultEntry& result);

		protected:
			CGeoSceneCamera* mpGeoCamera;
			//CGeoSpatialScene* ref_mpScene;
			OGRE_MUTEX(mPickMutex);
		};

		class VR_SPATIALENGINE_DLL CGeoSceneManagerFactory : public Ogre::SceneManagerFactory
		{
		protected:
			void initMetaData(void) const;
		public:
			CGeoSceneManagerFactory() {}
			~CGeoSceneManagerFactory() {}
			/// Factory type name
			static const Ogre::String FACTORY_TYPE_NAME;
			Ogre::SceneManager* createInstance(const Ogre::String& instanceName);
			void destroyInstance(Ogre::SceneManager* instance);
		};
	}
}

#endif  //_GEOSCENEMANAGER_H
