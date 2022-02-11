#include "vrmine\vr_projectmanager\project\projectmanager.h"
#include "vrmine\vr_scenecontrol\geospatialscene.h"
#include "vrmine\vr_databaseengine\database\idataset.h"
#include "vrmine\vr_core\event.h"
#include "vrmine\vr_databaseengine\database\logicfeature.h"
#include "vrmine\vr_spatialinterface\event\eventobject.h"
#include "vrmine\vr_core\tinyxml\tinyxml.h"
#include "vrmine\vr_databaseengine\database\databaseinfo.h"
#include "vrmine\vr_databaseengine\database\database.h"

using namespace VirtualMine::Core;
using namespace VirtualMine::Project;
using namespace VirtualMine::Database;
using namespace VirtualMine::Scene;
using namespace VirtualMine::SpatialInterface;

CProjectManager* CProjectManager::mpSingletonPtr(NULL);

CProjectManager& CProjectManager::getSingleton()
{
	if (mpSingletonPtr == NULL)
		mpSingletonPtr = new CProjectManager();
	return *mpSingletonPtr;
}

CProjectManager* CProjectManager::getSingletonPtr()
{
	if (mpSingletonPtr == NULL)
		mpSingletonPtr = new CProjectManager();
	return mpSingletonPtr;
}

CProjectManager::~CProjectManager()
{

}

bool CProjectManager::openScene()
{
	return false;
}

VirtualMine::SpatialInterface::IScene* CProjectManager::loadScene(const std::string& projectPath)
{
	Ogre::Vector3 cameraPosition = Ogre::Vector3::ZERO;
	Ogre::Vector3 cameraDirection = Ogre::Vector3::ZERO;
	this->parseScene(projectPath,cameraPosition,cameraDirection);
	if (this->mpGeoScene)
	{
		this->mCurProjectPath = projectPath;
		mpDataSetLoadHandler->setGeoSpatialScene(dynamic_cast<CGeoSpatialScene*>(this->mpGeoScene));
		CSceneLoadEvent evt;
		evt.setGeoScene(this->mpGeoScene);
		CEventDispatcher::setEvent(&evt);
		VirtualMine::SpatialEngine::CGeoSceneManager* pGeoSceneManager = dynamic_cast<VirtualMine::SpatialEngine::CGeoSceneManager*>(this->mpGeoScene->getGeoSceneManager());
		if (pGeoSceneManager
			&& cameraPosition!= Ogre::Vector3::ZERO)
		{
			pGeoSceneManager->getDefaultCamera()->setInitialCameraInfo(cameraPosition,cameraDirection);
		}

		LayerMap& layerMap = this->mpGeoScene->getLayerMap();
		LayerMap::iterator bItr = layerMap.begin();
		LayerMap::iterator eItr = layerMap.end();
		while (bItr != eItr)
		{
			CLayerRenderEvent layerRenderEvt;
			layerRenderEvt.setLayer(bItr->second);
			CEventDispatcher::setEvent(&layerRenderEvt);
			++bItr;
		}
	}
	return NULL;
}

void CProjectManager::unloadScene()
{
	if (this->mpGeoScene != NULL)
	{
#if 1 
		int layerCount = this->mpGeoScene->getLayerCount();
		VirtualMine::SpatialInterface::LayerMap layerMap = this->mpGeoScene->getLayerMap();
		VirtualMine::SpatialInterface::LayerMap::iterator itr = layerMap.begin();
		if (layerCount > 0)
		{
			std::vector<std::string> layerNames;
			while(itr != layerMap.end())
			{
				layerNames.push_back(itr->first);	
				itr++;
			}

			for (size_t i = 0; i < layerNames.size();++i)
			{
				this->mpGeoScene->removeLayer(layerNames.at(i));
			}
		}

#endif
		delete this->mpGeoScene; 
		this->mpGeoScene = NULL;

	/*	CSceneUnLoadEvent evt;
		CEventDispatcher::setEvent(&evt);*/
	}

	if (this->mpDataSourceManager != NULL)
	{
		//delete this->mpDataSourceManager;
		this->mpDataSourceManager->destroyDataSource();
		this->mpDataSourceManager = NULL;
	}
}

VirtualMine::SpatialInterface::ILayer* CProjectManager::createLayer(const std::string& layerName,
	const std::string& layerType,const std::string& dataSetName)
{
	if (this->mpGeoScene)
	{
		VirtualMine::SpatialInterface::ILayer* pLayer = this->mpGeoScene->createLayer(layerName,layerType);
		if (pLayer)
		{
			IDataset* pDataSet = CProjectManager::getSingletonPtr()->getDataSource()->getDataset(dataSetName);
			if (pDataSet)
			{
				pLayer->setDataSet(pDataSet);
			}
		}
		VirtualMine::SpatialInterface::CLayerLoadEvent evt;
		evt.setLayer(pLayer);
		VirtualMine::Core::CEventDispatcher::setEvent(&evt);
		return pLayer;
	}
	return NULL;
}

VirtualMine::SpatialInterface::IScene* CProjectManager::createScene(const std::string& name,
	const Ogre::Vector3& referenceCenter,const std::string& sceneType)
{
	if (NULL == this->mpGeoScene)
	{
		this->createScene(name);
		IScene::ReferenceCenter = referenceCenter;
		if (this->mpGeoScene)
		{
			mpDataSetLoadHandler->setGeoSpatialScene(dynamic_cast<CGeoSpatialScene*>(this->mpGeoScene));
			CSceneLoadEvent evt;
			evt.setGeoScene(this->mpGeoScene);
			CEventDispatcher::setEvent(&evt);
		}
		return this->mpGeoScene;
	}
	return NULL;
}

VirtualMine::SpatialInterface::IScene* CProjectManager::createScene(const std::string& name)
{
	if (NULL == this->mpGeoScene)
	{
		VirtualMine::SpatialInterface::IScene* pScene = new VirtualMine::Scene::CGeoSpatialScene();
		pScene->setName(name);
		this->mpGeoScene = pScene;
	}
	return this->mpGeoScene;
}

bool CProjectManager::destroyScene()
{
	if (this->mpGeoScene != NULL)
		SAFE_DELETE(this->mpGeoScene);
	return false;
}

void CProjectManager::removeLayer(const std::string& layerName)
{
	if (this->mpGeoScene != NULL)
	{
		this->mpGeoScene->removeLayer(layerName);
	}
}

CProjectManager::CProjectManager()
	:mpDataSourceManager(NULL),mpGeoScene(NULL),mCurProjectPath("")
{
	mpDataSetLoadHandler = new CDataSetLoadHandler();
}

VirtualMine::SpatialInterface::IScene* CProjectManager::parseScene(const std::string& projectPath,
	Ogre::Vector3& cameraPosition,Ogre::Vector3& cameraDirection)
{
	TiXmlDocument doc; 
	bool result = doc.LoadFile(projectPath.c_str(),TIXML_DEFAULT_ENCODING);
	if (!result)
	{
		return NULL;
	}
	this->createScene("");
	//CProjectManager::getSingletonPtr()->getDataSource()->getDatasetSet();
	TiXmlElement* sceneElement = doc.RootElement();  
	TiXmlAttribute* attributeOfScene = sceneElement->FirstAttribute(); 
	for (; attributeOfScene != NULL ; attributeOfScene = attributeOfScene->Next())
	{
		std::string name = attributeOfScene->Name();
		if (name == "name")
		{
			this->mpGeoScene->setName(attributeOfScene->Value());
		}
		else if (name == "visible")
		{
			this->mpGeoScene->setVisible(Ogre::StringConverter::parseBool(attributeOfScene->Value()));
		}
		else if (name == "referenceCenter")
		{
			IScene::ReferenceCenter = (Ogre::StringConverter::parseVector3(attributeOfScene->Value()));
		}
	}
	TiXmlElement* dataSourceNode = sceneElement->FirstChildElement("dataSource");
	{
		/*VirtualMine::Database::IDataSourceInfo* pDataSourceInfo = this->mpDataSourceManager->getDataSource()->getDataSourceInfo();*/
		TiXmlAttribute* attributeOfDataSource = dataSourceNode->FirstAttribute(); 
		//dataSourceNode->SetAttribute("type",pDataSourceInfo->getDataSourceType().c_str());
		//dataSourceNode->SetAttribute("url",pDataSourceInfo->getUri().c_str());
		VirtualMine::Database::IDataSourceInfo* pDataSourceInfo = new VirtualMine::Database::CDatabaseInfo();
		for (; attributeOfDataSource != NULL ; attributeOfDataSource = attributeOfDataSource->Next())
		{
			std::string name = attributeOfDataSource->Name();
			if (name == "type")
			{
				pDataSourceInfo->setDataSourceType(attributeOfDataSource->Value());
			}
			else if (name == "url")
			{
				pDataSourceInfo->setUri(attributeOfDataSource->Value());
			}
		}
		//打开数据源
		VirtualMine::Project::CProjectManager::getSingletonPtr()->openDataSource(pDataSourceInfo);
	}
	TiXmlElement* cameraElement = sceneElement->FirstChildElement("cameraInfo");
	if (cameraElement)
	{
		TiXmlAttribute* attributeOfcamera = cameraElement->FirstAttribute(); 
		for (; attributeOfcamera != NULL ; attributeOfcamera = attributeOfcamera->Next())
		{
			std::string name = attributeOfcamera->Name();
			if (name == "cameraPosition")
			{
				cameraPosition = (Ogre::StringConverter::parseVector3(attributeOfcamera->Value()));
			}
			else if (name == "cameraDirection")
			{
				cameraDirection = (Ogre::StringConverter::parseVector3(attributeOfcamera->Value()));
			}
		}
	}
	
	//
	TiXmlElement* layersElement = sceneElement->FirstChildElement("layers");
	TiXmlElement* layerElement = layersElement->FirstChildElement("layer");
	for (; layerElement != NULL ; layerElement = layerElement->NextSiblingElement())
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
		VirtualMine::SpatialInterface::ILayer* pLayer = this->mpGeoScene->createLayer(layerName,layerType);
		if (pLayer)
		{
			pLayer->setVisible(layerVisible);
			pLayer->setSelectable(layerSelectable);
			IDataset* pDataSet = CProjectManager::getSingletonPtr()->getDataSource()->getDataset(datasetName);
			if (pDataSet)
			{
				pLayer->setDataSet(pDataSet);
			}
		}
	}

	CServerConfigParam::parseConfig(sceneElement);

	return this->mpGeoScene;
}

VirtualMine::SpatialInterface::IScene* CProjectManager::getScene()
{
	return this->mpGeoScene;
}

void CProjectManager::toProjectFile(const std::string& projectPath)
{
	if (this->mpGeoScene)
	{
		TiXmlDocument doc;    
		TiXmlDeclaration* decl = new TiXmlDeclaration("1.0","GB2312", "yes");  

		TiXmlElement* rootNode = new TiXmlElement("scene");
		rootNode->SetAttribute("name",this->mpGeoScene->getName().c_str());
		rootNode->SetAttribute("visible",this->mpGeoScene->getVisible());
		rootNode->SetAttribute("referenceCenter",Ogre::StringConverter::toString(IScene::ReferenceCenter).c_str());
		rootNode->SetAttribute("sceneType","xian_1980");
		/*rootNode->SetAttribute("datasource",this->mpDataSourceManager->getDataSource()->get);*/
		{
			TiXmlElement* dataSourceNode = new TiXmlElement("dataSource");
			VirtualMine::Database::IDataSourceInfo* pDataSourceInfo = (dynamic_cast<VirtualMine::Database::CDatabase*>(this->mpDataSourceManager->getDataSource()))->getDataSourceInfo();
			dataSourceNode->SetAttribute("type",pDataSourceInfo->getDataSourceType().c_str());
			dataSourceNode->SetAttribute("url",pDataSourceInfo->getUri().c_str());
			rootNode->LinkEndChild(dataSourceNode);
			//
			TiXmlElement* cameraNode = new TiXmlElement("cameraInfo");
			VirtualMine::SpatialEngine::CGeoSceneManager* pGeoSceneManager = dynamic_cast<VirtualMine::SpatialEngine::CGeoSceneManager*>(this->mpGeoScene->getGeoSceneManager());
			cameraNode->SetAttribute("cameraPosition",Ogre::StringConverter::toString(pGeoSceneManager->getDefaultCamera()->getPosition()).c_str());
			cameraNode->SetAttribute("cameraDirection",Ogre::StringConverter::toString(pGeoSceneManager->getDefaultCamera()->getDirection()).c_str());
			rootNode->LinkEndChild(cameraNode);
			TiXmlElement* layersNode = new TiXmlElement("layers");
			//图层属性
			LayerMap& layerMap = this->mpGeoScene->getLayerMap();
			std::map<std::string,VirtualMine::SpatialInterface::ILayer*>::iterator bitr = layerMap.begin();
			std::map<std::string,VirtualMine::SpatialInterface::ILayer*>::iterator eitr = layerMap.end();
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

		CServerConfigParam::saveConfig(rootNode);

		doc.LinkEndChild(decl);
		doc.LinkEndChild(rootNode);     
		doc.SaveFile(projectPath.c_str()); 
		
	}
}

bool CProjectManager::saveAs(const std::string& projectPath)
{
#if 1
	if (this->mpGeoScene)
	{
		this->toProjectFile(projectPath);
	}

#else
	if (this->mpDataSourceManager)
	{
		CGeoSpatialScene* pScene =  new CGeoSpatialScene();
		//pScene->setReferenceCenter(Ogre::Vector3(37536324,156.41852,3060630.3));
		//IScene::ReferenceCenter = Ogre::Vector3(37536324,156.41852,3060630.3);
		mpDataSetLoadHandler->setGeoSpatialScene(pScene);
		CSceneLoadEvent evt;
		evt.setGeoScene(pScene);
		CEventDispatcher::setEvent(&evt);
		IDataSource* pDataSource = this->mpDataSourceManager->getDataSource();
		//
		std::vector<IDataset*>* pDataSets = pDataSource->getDatasetSet();
		IDataset* pLogicDataSet = pDataSource->getDataset("LogicDataset");
		if (pLogicDataSet)
		{
			std::vector<IFeature*>* logicalDataList = pLogicDataSet->getFeatureList();
			std::vector<IFeature*>::iterator logicalBItr = logicalDataList->begin();
			std::vector<IFeature*>::iterator logicalEItr = logicalDataList->end();
			while (logicalBItr != logicalEItr)
			{
				CLogicFeature* pLogicalFeature = dynamic_cast<CLogicFeature*>(*logicalBItr);
				std::string datasetName = pLogicalFeature->getName();
				std::string type ;
				CPropertySet* pProperty = pLogicalFeature->getPropertySet();
				std::vector<VirtualMine::Database::CField> fileds = pProperty->getFields();
				fileds.at(1).getVarient().getValue(datasetName);
				fileds.at(2).getVarient().getValue(type);
				CDataSetLoadEvent dataSetLoadEvent;
				dataSetLoadEvent.setDataSetName(datasetName);
				dataSetLoadEvent.setDataSetType(type);
				//加载数据集
				CEventDispatcher::setEvent(&dataSetLoadEvent);
				++logicalBItr;
			}
		}
		this->mpGeoScene = pScene;
		//this->mpGeoScene->toFile(projectPath);
		this->toProjectFile(projectPath);
	}
#endif
	return false;
}

bool CProjectManager::save()
{
	if (this->mCurProjectPath !="")
	{
		return this->saveAs(this->mCurProjectPath);
	}
	return false;
}

VirtualMine::Database::IDataSource* CProjectManager::getDataSource()
{
	if (this->mpDataSourceManager != NULL)
	{
		return this->mpDataSourceManager->getDataSource();
	}
	return NULL;
}

VirtualMine::Database::IDataSourceManager* CProjectManager::getDataSourceManager()
{
	if (NULL == this->mpDataSourceManager)
	{
		std::string dataSourceType = "";
		this->mpDataSourceManager = CDataSourceManagerRegister::getSingletonPtr()->getDataSourceManager(dataSourceType);
	}
	return this->mpDataSourceManager;
}

bool CProjectManager::openDataSource(VirtualMine::Database::IDataSourceInfo* pDataSourceInfo)
{
	assert(pDataSourceInfo);
	if (pDataSourceInfo == NULL)
	{
		return false;
	}
	if (this->mpDataSourceManager == NULL)
	{
		this->createDataSourceManager(pDataSourceInfo->getDataSourceType());
	}
	this->mpDataSourceManager->openDataSource(pDataSourceInfo);
	VirtualMine::SpatialInterface::CDataSourceLoadEvent evt;
	evt.setDataSourceManager(this->mpDataSourceManager);
	VirtualMine::Core::CEventDispatcher::setEvent(&evt);
}

bool CProjectManager::createDataSourceManager(const std::string& dataSourceType)
{
	this->mpDataSourceManager = CDataSourceManagerRegister::getSingletonPtr()->getDataSourceManager(dataSourceType);
	if (this->mpDataSourceManager == NULL)
		return false;
	return true;
}

CDataSetLoadHandler::CDataSetLoadHandler()
	:ref_mpScene(NULL)
{

}

CDataSetLoadHandler::~CDataSetLoadHandler()
{

}

void CDataSetLoadHandler::setGeoSpatialScene(CGeoSpatialScene* ref_pScene)
{
	this->ref_mpScene = ref_pScene;
}

CGeoSpatialScene* CDataSetLoadHandler::getGeoSpatialScene()
{
	return this->ref_mpScene;
}

bool CDataSetLoadHandler::handleEvent(VirtualMine::Core::CEvent* evt)
{
	CDataSetLoadEvent* pDataSetLoadEvent = dynamic_cast<CDataSetLoadEvent*>(evt);
	if (pDataSetLoadEvent && this->ref_mpScene)
	{
		IDataset* pDataSet = CProjectManager::getSingletonPtr()->getDataSource()->getDataset(pDataSetLoadEvent->getDataSetName());
		if (NULL == pDataSet)
			return false;
		ILayer* pLayer = this->ref_mpScene->createLayer(pDataSetLoadEvent->getDataSetName(),pDataSetLoadEvent->getDataSetType());
		if (pLayer)
		{
			pLayer->setDataSet(pDataSet);
			CLayerLoadEvent layerLoadEvent;
			layerLoadEvent.setLayer(pLayer);
			VirtualMine::Core::CEventDispatcher::setEvent(&layerLoadEvent);
			/*pLayer->draw();*/
			evt->accept();
		}
	}
	return evt->isAccepted();
}

CServerConfigParam::CServerConfigParam()
{

}

CServerConfigParam::~CServerConfigParam()
{

}

void CServerConfigParam::parseConfig(TiXmlElement* rootNode)
{
	TiXmlElement* serverConfigElement = rootNode->FirstChildElement("ServerConfig");
	TiXmlElement* serverElement = serverConfigElement->FirstChildElement("Server");
	for (; serverElement != NULL ; serverElement = serverElement->NextSiblingElement())
	{
		TiXmlAttribute* attributeOfLayer = serverElement->FirstAttribute(); 

		for (; attributeOfLayer != NULL ; attributeOfLayer = attributeOfLayer->Next())
		{
			std::string name = attributeOfLayer->Name();
			if (name == "Type")
			{
				CServerConfigParam::Driver = attributeOfLayer->Value();
			}
			else if (name == "Server")
			{
				CServerConfigParam::Server = attributeOfLayer->Value();
			}
			else if (name == "DataBase")
			{
				CServerConfigParam::DataBase = attributeOfLayer->Value();
			}
			else if (name == "User")
			{
				CServerConfigParam::User = attributeOfLayer->Value();
			}
			else if (name == "Password")
			{
				CServerConfigParam::Password = attributeOfLayer->Value();
			}
			else if (name == "SimuUrl")
			{
				CServerConfigParam::SimuUrl = attributeOfLayer->Value();
			}
			else if (name == "SwitchUrl")
			{
				CServerConfigParam::SwitchUrl = attributeOfLayer->Value();
			}
		}
	}
}


std::string CServerConfigParam::Driver("SQL SERVER");
//std::string CServerConfigParam::Server("192.168.1.208");
//std::string CServerConfigParam::Server("172.18.185.3");
std::string CServerConfigParam::Server("127.0.0.1");
std::string CServerConfigParam::DataBase("location");
std::string CServerConfigParam::User("sa");
std::string CServerConfigParam::Password("123");

std::string CServerConfigParam::SimuUrl("http://localhost:90/realdata/RealSimuXML.xml");
std::string CServerConfigParam::SwitchUrl("http://localhost:90/realdata/RealSwitchXML.xml");

//std::string CServerConfigParam::SimuUrl("http://58.46.64.29:82/kj75web/realdata/RealsimuXML.xml");
//std::string CServerConfigParam::SwitchUrl("http://58.46.64.29:82/kj75web/realdata/RealSwitchXML.xml");

void CServerConfigParam::saveConfig(TiXmlElement* rootNode)
{
	TiXmlElement* serverConfigNode = new TiXmlElement("ServerConfig");

	TiXmlElement* serverNode = new TiXmlElement("Server");
	serverNode->SetAttribute("Type","SQL SERVER");
	serverNode->SetAttribute("Server",CServerConfigParam::Server.c_str());
	serverNode->SetAttribute("DataBase",CServerConfigParam::DataBase.c_str());
	serverNode->SetAttribute("User",CServerConfigParam::User.c_str());
	serverNode->SetAttribute("Password",CServerConfigParam::Password.c_str());

	serverNode->SetAttribute("SimuUrl",CServerConfigParam::SimuUrl.c_str());
	serverNode->SetAttribute("SwitchUrl",CServerConfigParam::SwitchUrl.c_str());

	serverConfigNode->LinkEndChild(serverNode);	 
	rootNode->LinkEndChild(serverConfigNode);  
}




