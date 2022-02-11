//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : layermanager.cpp
//  @ Date : 2014/7/6
//  @ Author : ʢ����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine\vr_spatiallayer\layerfactory.h"
#include "vrmine\vr_scenecontrol\scenehelper.h"

using namespace VirtualMine::SpatialLayer;
using namespace VirtualMine::SpatialInterface;

namespace VirtualMine
{
	namespace Scene
	{

		CSceneHelper* CSceneHelper::mpSingletonPtr(NULL);

		CSceneHelper::CSceneHelper()
			:ref_mpGeoSceneManager(NULL)
		{
			/*this->mpImageLayer = new VirtualMine::SpatialLayer::CImageLayer();
			this->mpDemLayer = new VirtualMine::SpatialLayer::CDemLayer();

			this->mpMineLayerMap = new CSceneHelper::LayerMap();
			this->mpMineLayerMap->insert(std::pair<std::string,ILayer*>(this->mpImageLayer->getName(),this->mpImageLayer));
			this->mpMineLayerMap->insert(std::pair<std::string,ILayer*>(this->mpDemLayer->getName(),this->mpDemLayer));*/
		}

		CSceneHelper::~CSceneHelper()
		{
		
		}

		CSceneHelper& CSceneHelper::getSingleton()
		{
			if(NULL == mpSingletonPtr)
				mpSingletonPtr = new CSceneHelper();
			return *mpSingletonPtr;
		}

		CSceneHelper* CSceneHelper::getSingletonPtr()
		{
			if(NULL == mpSingletonPtr)
				mpSingletonPtr = new CSceneHelper();
			return mpSingletonPtr;
		}

		void CSceneHelper::setGeoSceneManager(VirtualMine::SpatialEngine::CGeoSceneManager * ref_pGeoSceneManager)
		{
			this->ref_mpGeoSceneManager = ref_pGeoSceneManager;
		}

		ILayer* CSceneHelper::createLayer(const std::string& name)
		{
			return NULL;
		}

		ILayer* CSceneHelper::createLayer(const std::string& name,const std::string& layerType)
		{
			CLayerFactory* pLayerFactory = dynamic_cast<CLayerFactory*>(CLayerFactoryRegister::getSingletonPtr()->getFactory(layerType));
			if (NULL != pLayerFactory)
			{
				ILayer* pLayer = pLayerFactory->createInstance(name);
				pLayer->setGeoSceneManager(this->ref_mpGeoSceneManager);

				//mpMineLayerMap->insert(std::pair<std::string,ILayer*>(name,pLayer));
				return pLayer;
			}
			return NULL;
		}

		ILayer* CSceneHelper::getImageLayer()
		{
			return NULL;
		}

		ILayer* CSceneHelper::getDemLayer()
		{
			return NULL;
		}

		CSceneHelper::LayerMap* CSceneHelper::getLayerMap()
		{
			return NULL;
		}
		
		void CSceneHelper::renderToScene()
		{
			/*if (this->mpMineLayerMap->size() > 0)
			{
				CSceneHelper::LayerMap::iterator bItr = this->mpMineLayerMap->begin();
				CSceneHelper::LayerMap::iterator eItr = this->mpMineLayerMap->end();
				while (bItr != eItr)
				{
					bItr->second->draw();
					++bItr;
				}
			}*/
		}
		
		void CSceneHelper::renderToScene(const std::string& name)
		{
			ILayer* pLayer = this->getLayer(name);
			if (NULL != pLayer)
			{
				pLayer->draw();
			}
		}


		ILayer* CSceneHelper::getLayer(const std::string& name)
		{
			/*LayerMap::iterator itr = this->mpMineLayerMap->begin();
			if (itr != this->mpMineLayerMap->end())
			{
				return itr->second;
			}*/
			return NULL;
		}

		bool CSceneHelper::destroyLayer(const std::string& name)
		{
			ILayer* pLayer = this->getLayer(name);
			if (pLayer)
			{
				CLayerFactory* pLayerFactory = dynamic_cast<CLayerFactory*>(CLayerFactoryRegister::getSingletonPtr()->getFactory(pLayer->getType()));
				if (NULL != pLayerFactory)
				{
					pLayerFactory->destroyInstance(pLayer);
				}
			}
			
			return false;
		}

	}
}