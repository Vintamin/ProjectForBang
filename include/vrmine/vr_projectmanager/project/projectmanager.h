//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : cprojectmanager.h
//  @ Date : 2014/7/5
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#ifndef _CPROJECTMANAGER_H
#define _CPROJECTMANAGER_H


#include "vrmine\vr_projectmanager\project\project_config.h"
#include <string>
#include "vrmine\vr_scenecontrol\geospatialscene.h"
#include "vrmine\vr_databaseengine\database\idatasource.h"
#include "vrmine\vr_databaseengine\database\idataset.h"
#include "vrmine\vr_databaseengine\database\idatasourcemanager.h"
#include "vrmine\vr_databaseengine\database\idatasourceinfo.h"
#include "vrmine\vr_core\tinyxml\tinyxml.h"

namespace VirtualMine
{
	namespace Project
	{
		class CDataSetLoadHandler;
		class VR_PROJECTMANAGER_DLL CProjectManager //: public CBaseObject
		{
		public:
			static CProjectManager& getSingleton();
			static CProjectManager* getSingletonPtr();
			
			virtual ~CProjectManager();
			VirtualMine::SpatialInterface::IScene* loadScene(const std::string& projectPath);
			void unloadScene();
			VirtualMine::SpatialInterface::IScene* createScene(const std::string& name);
			VirtualMine::SpatialInterface::IScene* createScene(const std::string& name,
				const Ogre::Vector3& referenceCenter,const std::string& sceneType);
			VirtualMine::SpatialInterface::ILayer* createLayer(const std::string& layerName,
				const std::string& layerType,const std::string& dataSetName);
			void removeLayer(const std::string& layerName);

			bool openScene();
			bool openDataSource(VirtualMine::Database::IDataSourceInfo* pDataSourceInfo);
			bool destroyScene();
			bool saveAs(const std::string& projectPath);
			bool save();
			VirtualMine::Database::IDataSource* getDataSource();
			VirtualMine::Database::IDataSourceManager* getDataSourceManager();
			bool createDataSourceManager(const std::string& dataSourceType);
			VirtualMine::SpatialInterface::IScene* getScene();
		protected:
			CProjectManager();
			VirtualMine::SpatialInterface::IScene* parseScene(const std::string& projectPath,
				Ogre::Vector3& cameraPosition,Ogre::Vector3& cameraDirection);
			void toProjectFile(const std::string& projectPath);
		protected:
			static CProjectManager* mpSingletonPtr;
			VirtualMine::SpatialInterface::IScene* mpGeoScene;
			VirtualMine::Database::IDataSourceManager* mpDataSourceManager;
			CDataSetLoadHandler* mpDataSetLoadHandler;
			std::string mCurProjectPath;
		};

		class VR_PROJECTMANAGER_DLL CDataSetLoadHandler : public VirtualMine::Core::CEventHandler
		{
		public:
			CDataSetLoadHandler();
			virtual ~CDataSetLoadHandler();

			void setGeoSpatialScene(VirtualMine::Scene::CGeoSpatialScene* ref_pScene);
			VirtualMine::Scene::CGeoSpatialScene* getGeoSpatialScene();
			virtual bool handleEvent(VirtualMine::Core::CEvent* evt);

		protected:
			VirtualMine::Scene::CGeoSpatialScene* ref_mpScene;
		};

		class VR_PROJECTMANAGER_DLL CServerConfigParam
		{
		public:
			CServerConfigParam();
			~CServerConfigParam();

			static void parseConfig(TiXmlElement* rootNode);
			static void saveConfig(TiXmlElement* rootNode);
		public:
			static std::string Driver;
			static std::string Server;
			static std::string DataBase;
			static	std::string User;
			static std::string Password;

			static std::string SimuUrl;
			static std::string SwitchUrl;
		};
	}
}

#endif  //_CPROJECTMANAGER_H
