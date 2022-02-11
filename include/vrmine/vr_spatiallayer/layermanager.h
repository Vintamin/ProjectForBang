//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : layermanager.h
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_LAYERMANAGER_H)
#define _LAYERMANAGER_H

#include "vrmine/vr_spatiallayer/spatiallayer_config.h"
#include <string>
#include "vrmine/vr_spatiallayer/ilayer.h"
#include "vrmine/vr_spatialengine/geoscenemanager.h"
#include "vrmine/vr_spatiallayer/demlayer.h"
#include "vrmine/vr_spatiallayer/imagelayer.h"

namespace VirtualMine
{
	namespace SpatialLayer
	{
		class VR_SPATIALLAYER_DLL CLayerManager
		{
		public:
			typedef std::map<std::string,ILayer*> LayerMap;
			static CLayerManager getSingleton();
			static CLayerManager* getSingletonPtr();
			~CLayerManager();
			void setGeoSceneManager(VirtualMine::SpatialEngine::CGeoSceneManager * ref_pGeoSceneManager);
			ILayer* createLayer(const std::string& name,const std::string& layerType);
			ILayer* createLayer(const std::string& name);
			ILayer* getLayer(const std::string& name);
			ILayer* getImageLayer();
			ILayer* getDemoLayer();
			LayerMap* getLayerMap();
			void renderToScene();
			void renderToScene(const std::string& name);
			bool destroyLayer(const std::string& name);

		protected:
			CLayerManager();

		protected:

			static CLayerManager* mpSingletonPtr;
			VirtualMine::SpatialEngine::CGeoSceneManager * ref_mpGeoSceneManager;
			LayerMap* mpMineLayerMap;
			VirtualMine::SpatialLayer::CImageLayer* mpImageLayer;
			VirtualMine::SpatialLayer::CDemLayer* mpDemLayer;
		};
	}
}

#endif  //_LAYERMANAGER_H
