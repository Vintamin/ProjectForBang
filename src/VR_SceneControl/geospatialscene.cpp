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


#include "vrmine\vr_scenecontrol\geospatialscene.h"
#include "vrmine\vr_spatiallayer\demlayer.h"
#include "vrmine\vr_spatiallayer\imagelayer.h"
#include "vrmine\vr_spatiallayer\lanwaylayer.h"
#include "vrmine\vr_spatialinterface\event\eventobject.h"
#include "vrmine\vr_spatiallayer\layerfactory.h"
#include "vrmine\vr_core\event.h"
#include "vrmine\vr_databaseengine\database\idatasourcemanager.h"
#include "vrmine\vr_core\variant.h"
#include "OGRE/OgreFileSystem.h"
#include <fstream>
#include <ostream>
#include "vrmine/vr_core/tinyxml/tinyxml.h"
#include "OGRE/OgreResourceManager.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine\vr_spatialengine\geoscenecamera.h"

using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::SpatialLayer;
using namespace VirtualMine::Database;
using namespace VirtualMine::Core;
using namespace std;
using namespace VirtualMine::SpatialEngine;


namespace VirtualMine
{
	namespace Scene
	{

		CGeoSpatialScene::CGeoSpatialScene()
			:mName("三维数字矿山"),mVisible(true),
			mpImageLayer(NULL),mpDemLayer(NULL),
			mReferenceCenter(Ogre::Vector3::ZERO)
		{
			
		}

		CGeoSpatialScene::~CGeoSpatialScene()
		{
			LayerMap::iterator bItr = this->mLayerMap.begin();
			LayerMap::iterator eItr = this->mLayerMap.end();
			while (bItr != eItr)
			{
				delete bItr->second;
				++bItr;
			}
			this->mLayerMap.clear();
		}

		void CGeoSpatialScene::setName(const std::string& name)
		{
			this->mName = name;
		}

		std::string CGeoSpatialScene::getName()
		{
			return this->mName;
		}

		void CGeoSpatialScene::setVisible(const bool& value)
		{
			this->mVisible = value;
		}

		bool CGeoSpatialScene::getVisible()
		{
			return this->mVisible;
		}

		void CGeoSpatialScene::setGeoSceneManager(Ogre::SceneManager* ref_pSceneManager)
		{
			this->ref_mpSceneManager = dynamic_cast<VirtualMine::SpatialEngine::CGeoSceneManager*>(ref_pSceneManager);
		}
		Ogre::SceneManager* CGeoSpatialScene::getGeoSceneManager()
		{
			return this->ref_mpSceneManager;
		}

		ILayer* CGeoSpatialScene::createLayer(const std::string& name,const std::string& layerType)
		{
			CLayerFactory* pFactory = dynamic_cast<CLayerFactory*>(CLayerFactoryRegister::getSingletonPtr()->getFactory(layerType));
			if (pFactory)
			{
				ILayer* pLayer = pFactory->createInstance(name);
				pLayer->setScene(this);
				this->mLayerMap.insert(std::pair<std::string,ILayer*>(pLayer->getName(),pLayer));
				return pLayer;
			}
			return NULL;
		}

		ILayer* CGeoSpatialScene::createLayer(const std::string& name)
		{
			return NULL;
		}

		void CGeoSpatialScene::removeLayer(VirtualMine::SpatialInterface::ILayer* layer)
		{
			
		}

		void CGeoSpatialScene::removeLayer(const std::string& layerName)
		{
			LayerMap::const_iterator finder = this->mLayerMap.find(layerName);
			if (finder != this->mLayerMap.end())
			{
				delete (finder->second);
				this->mLayerMap.erase(finder);
			}
		}

		int CGeoSpatialScene::getLayerCount()
		{
			return this->mLayerMap.size();
		}

		Ogre::Vector3 CGeoSpatialScene::getReferenceCenter()
		{
			return this->mReferenceCenter;
		}

		void CGeoSpatialScene::setReferenceCenter(const Ogre::Vector3& referenceCenter)
		{
			this->mReferenceCenter = referenceCenter;
		}

		void CGeoSpatialScene::toFile(const std::string& filename)
		{
#if 0
			CVRDataStream datastream;
			datastream.wirteString(this->mName);
			datastream.wirteBool(mVisible);
			datastream.wirteReal(this->mReferenceCenter.x);
			datastream.wirteReal(this->mReferenceCenter.y);
			datastream.wirteReal(this->mReferenceCenter.z);
			
			VirtualMine::SpatialInterface::LayerMap layermap = this->mLayerMap;
			
			int mapcount = layermap.size();
		    datastream.wirteInt32(mapcount);

			std::map<std::string,VirtualMine::SpatialInterface::ILayer*>::iterator bitr = mLayerMap.begin();
			std::map<std::string,VirtualMine::SpatialInterface::ILayer*>::iterator eitr = mLayerMap.end();
			while (bitr != eitr)
			{
				datastream.wirteString(bitr->first);
				std::string datasetname = bitr->second->getDataSet()->getName();
				std::string datasettype = bitr->second->getDataSet()->getType();
			
				std::string layername = bitr->second->getName();
				std::string layertype = bitr->second->getType();

				bool isvisible = bitr->second->getVisible();
				bool isselected = bitr->second->getSelectable();
			
				datastream.wirteString(datasetname);
				datastream.wirteString(datasettype);
				datastream.wirteString(layername);
				datastream.wirteBool(isvisible);
				datastream.wirteBool(isselected);
				bitr++;
			}


			/*Ogre::DataStreamPtr dsptr;
			dsptr->read(datastream.getData(),datastream.getLength());
			*/
			/*std::ostream fs("filename.prj",std::ios::binary);
			char* pData = (char*)(datastream.getData());
			fs.write(pData,datastream.getLength());
			*/
			//

			int indexofLast =  filename.find_last_of('/');
			std::string imagename = filename.substr(0,indexofLast);
			std::string filewithoutpath = filename.substr(indexofLast+1);

			Ogre::FileSystemArchive file(imagename,"FileSystem");
			/*Ogre::DataStreamPtr dsPtr = file.open(filewithoutpath,false);	*/
			Ogre::DataStreamPtr dsPtr = file.create(filewithoutpath);	
			//dsPtr.get()->read(datastream.getData(),datastream.getLength());
			dsPtr->write(datastream.getData(),datastream.getLength());
			//是否加入load 		
			//file.load();

		/*	Ogre::Image image;
			image.load(dsptr);
		
			image.save(filename);*/
#else
			TiXmlDocument doc;    
			TiXmlDeclaration* decl = new TiXmlDeclaration("1.0","UTF-8", "");  

			TiXmlElement* rootNode = new TiXmlElement("scene");
			rootNode->SetAttribute("name",this->mName.c_str());
			rootNode->SetAttribute("visible",this->mVisible);
			rootNode->SetAttribute("referenceCenter",Ogre::StringConverter::toString(this->mReferenceCenter).c_str());
			{
				TiXmlElement* layersNode = new TiXmlElement("layers");
				//图层属性
				std::map<std::string,VirtualMine::SpatialInterface::ILayer*>::iterator bitr = mLayerMap.begin();
				std::map<std::string,VirtualMine::SpatialInterface::ILayer*>::iterator eitr = mLayerMap.end();
				while (bitr != eitr)
				{
					TiXmlElement* layerNode = new TiXmlElement("layer");
					layerNode->SetAttribute("name",bitr->second->getName().c_str());
					layerNode->SetAttribute("type",bitr->second->getType().c_str());
					layerNode->SetAttribute("visible",Ogre::StringConverter::toString(bitr->second->getVisible()).c_str());
					layerNode->SetAttribute("selectable",Ogre::StringConverter::toString(bitr->second->getSelectable()).c_str());
					layerNode->SetAttribute("datasetName",bitr->second->getDataSet()->getName().c_str());
					layerNode->SetAttribute("datasetType",bitr->second->getDataSet()->getType().c_str());
					layersNode->LinkEndChild(layerNode);
					++bitr;
				}
				rootNode->LinkEndChild(layersNode);
			}
			doc.LinkEndChild(decl);
			doc.LinkEndChild(rootNode);     
			doc.SaveFile(filename.c_str()); 
#endif

		}

		void CGeoSpatialScene::fromFile(const std::string& filename)
		{
#if 0
			int indexofLast =  filename.find_last_of('/');
			std::string imagename = filename.substr(0,indexofLast);
			std::string filewithoutpath = filename.substr(indexofLast);

			Ogre::FileSystemArchive file(imagename,"FileSystem");
			Ogre::DataStreamPtr dsPtr = file.open(filewithoutpath);	



			size_t s = dsPtr.getPointer()->size();
			Ogre::uchar *pBuf = new Ogre::uchar[s];
			dsPtr.getPointer()->read(static_cast<void *>(pBuf), s);
			
			CVRDataStream datastream;
			datastream.wirteBlob(pBuf,s);

			datastream.reseek(0);
			datastream.readString(mName);
			datastream.readBool(mVisible);
			datastream.readReal(this->mReferenceCenter.x);
			datastream.readReal(this->mReferenceCenter.y);
			datastream.readReal(this->mReferenceCenter.z);

			int sizeofLayer(0);
			datastream.readInt32(sizeofLayer);
			for (int i = 0; i < sizeofLayer; i++)
			{
				string firstname; 
				datastream.readString(firstname);

				string datasetname;
				datastream.readString(datasetname);

				string datasettype;
				datastream.readString(datasettype);

				std::string layername;
				datastream.readString(layername);

				std::string layertype;
				datastream.readString(layertype);

				bool isvisible;
				datastream.readBool(isvisible);

				bool isselected;
				datastream.readBool(isselected);

				VirtualMine::SpatialInterface::ILayer* layer = NULL;//new VirtualMine::SpatialInterface::ILayer();
				CLayerFactory* pLayerFactory = dynamic_cast<CLayerFactory*>(CLayerFactoryRegister::getSingletonPtr()->getFactory(layertype));
				layer = pLayerFactory->createInstance(layername);

				layer->setName(layername);
				layer->getDataSet()->setName(datasetname);
				layer->getDataSet()->setType(datasettype);
				layer->setSelectable(isselected);
				layer->setVisible(isvisible);
				this->mLayerMap.insert(make_pair(firstname,layer));

			}	
#else

			TiXmlDocument doc; 
			bool result = doc.LoadFile(filename.c_str(),TIXML_ENCODING_UTF8);
			TiXmlElement* sceneElement = doc.RootElement();  
			TiXmlAttribute* attributeOfScene = sceneElement->FirstAttribute(); 
			for (; attributeOfScene != NULL ; attributeOfScene = attributeOfScene->Next())
			{
				std::string name = attributeOfScene->Name();
				if (name == "name")
				{
					this->mName = attributeOfScene->Value();
				}
				else if (name == "visible")
				{
					this->mVisible = Ogre::StringConverter::parseBool(attributeOfScene->Value());
				}
				else if (name == "referenceCenter")
				{
					this->mReferenceCenter = Ogre::StringConverter::parseVector3(attributeOfScene->Value());
				}
			}
	
			TiXmlElement* layersElement = sceneElement->FirstChildElement("layers");
			TiXmlElement* layerElement = layersElement->FirstChildElement("layer");
			for (; layersElement != NULL ; layersElement = layerElement->NextSiblingElement())
			{
				TiXmlAttribute* attributeOfLayer = layerElement->FirstAttribute(); 
				std::string layerName = "";
				std::string layerType = "";
				bool layerVisible = true;
				bool layerSelectable = false;
				std::string datasetName = "";
				std::string datasetType = "";
				for (; attributeOfLayer != NULL ; attributeOfLayer = attributeOfLayer->Next())
				{
					std::string name = attributeOfLayer->Name();
					if (name == "name")
					{
						layerName = attributeOfLayer->Value();
					}
					else if (name == "type")
					{
						layerType = attributeOfLayer->Value();
					}
					else if (name == "visible")
					{
						layerVisible = Ogre::StringConverter::parseBool(attributeOfLayer->Value());
					}
					else if (name == "selectable")
					{
						layerSelectable = Ogre::StringConverter::parseBool(attributeOfLayer->Value());
					}
					else if (name == "datasetName")
					{
						datasetName = attributeOfLayer->Value();
					}
					else if (name == "datasetType")
					{
						datasetType = attributeOfLayer->Value();
					}
				}
				/*IDataset* pDataSet = CProjectManager::getSingletonPtr()->getDataSource()->getDataset(datasetName);
				if (NULL == pDataSet)
					return false;*/
				VirtualMine::SpatialInterface::ILayer* pLayer = this->createLayer(layerName,layerType);
				if (pLayer)
				{
					pLayer->setVisible(layerVisible);
					pLayer->setSelectable(layerSelectable);
				}
			}
#endif
		
		}

		ILayer* CGeoSpatialScene::getLayer(const std::string& name)
		{
			LayerMap::iterator itr = this->mLayerMap.find(name);
			if (itr != this->mLayerMap.end())
			{
				return itr->second;
			}
			return NULL;
		}

		LayerMap& CGeoSpatialScene::getLayerMap()
		{
			return this->mLayerMap;
		}

		ILayer* CGeoSpatialScene::getImageLayer()
		{
			/*return this->mpImageLayer;*/
			if (!this->mLayerMap.empty())
			{
				LayerMap::iterator bItr = this->mLayerMap.begin();
				LayerMap::iterator eItr = this->mLayerMap.end();
				while (bItr != eItr)
				{
					if (bItr->second->getType() == VirtualMine::Core::GeoDataType::GDT_IMAGE)
					{
						return bItr->second;
					}
					++bItr;
				}
			}
			
			//this->ui.vRControl->getGeoSpatialControl()->getGeoSceneCamera()->setPosition(IScene::ReferenceCenter);
			//this->getGeoSceneManager()->getCamera(CGeoSceneCamera::DEFAULT_CAMERA_NAME)->setPosition(IScene::ReferenceCenter);
			return NULL;

		}

		VirtualMine::SpatialInterface::ILayer* CGeoSpatialScene::getModelLayer()
		{
			if (!this->mLayerMap.empty())
			{
				LayerMap::iterator bItr = this->mLayerMap.begin();
				LayerMap::iterator eItr = this->mLayerMap.end();
				while (bItr != eItr)
				{
					if (bItr->second->getType() == VirtualMine::Core::GeoDataType::GDT_MODEL)
					{
						return bItr->second;
					}
					++bItr;
				}
			}
			return NULL;
		}

		VirtualMine::SpatialInterface::ILayer* CGeoSpatialScene::getLanewayLayer()
		{
			if (!this->mLayerMap.empty())
			{
				LayerMap::iterator bItr = this->mLayerMap.begin();
				LayerMap::iterator eItr = this->mLayerMap.end();
				while (bItr != eItr)
				{
					if (bItr->second->getType() == VirtualMine::Core::GeoDataType::GDT_LANWAY)
					{
						return bItr->second;
					}
					++bItr;
				}
			}
			return NULL;
		}

		ILayer* CGeoSpatialScene::getDemLayer()
		{
			/*return this->mpDemLayer;*/
			if (!this->mLayerMap.empty())
			{
				LayerMap::iterator bItr = this->mLayerMap.begin();
				LayerMap::iterator eItr = this->mLayerMap.end();
				while (bItr != eItr)
				{
					if (bItr->second->getType() == VirtualMine::Core::GeoDataType::GDT_DEM)
					{
						return bItr->second;
					}
					++bItr;
				}
			}
			return NULL;
		}

		void CGeoSpatialScene::draw()
		{
			LayerMap::iterator bItr = this->mLayerMap.begin();
			LayerMap::iterator eItr = this->mLayerMap.end();
			while (bItr != eItr)
			{
				bItr->second->draw();
				++bItr;
			}
		}

		void CGeoSpatialScene::initial()
		{
			LayerMap::iterator bItr = this->mLayerMap.begin();
			LayerMap::iterator eItr = this->mLayerMap.end();
			while (bItr != eItr)
			{
				bItr->second->initialise();
				++bItr;
			}
			//this->mLayerMap.clear();
			/*ILayer* pLayer = new CImageLayer();
			pLayer->setName("影像图层");
			pLayer->setScene(this);
			this->mpImageLayer = dynamic_cast<CImageLayer*>(pLayer);
			this->mLayerMap.insert(std::pair<std::string,ILayer*>(pLayer->getName(),pLayer));
			pLayer = new CDemLayer();
			pLayer->setName("数字高程图层");
			pLayer->setScene(this);
			this->mpDemLayer = dynamic_cast<CDemLayer*>(pLayer);
			this->mLayerMap.insert(std::pair<std::string,ILayer*>(pLayer->getName(),pLayer));*/
			/*pLayer = new CLanewayLayer();
			pLayer->setName("巷道图层");
			pLayer->setScene(this);
			this->mLayerMap.insert(std::pair<std::string,ILayer*>(pLayer->getName(),pLayer));*/
		}

		std::string CGeoSpatialScene::getCurDirName()
		{
			return mCurDirName;
		}

		void CGeoSpatialScene::setCurDirName( const std::string& curName )
		{
			this->mCurDirName = curName;
		}


	}
}
