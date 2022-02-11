//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : igeoobject.cpp
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 

#include "vrmine\vr_spatialinterface\event\eventobject.h"

namespace VirtualMine
{
	namespace SpatialInterface
	{
		
		CSceneLoadEvent::CSceneLoadEvent()
			:ref_mpGeoScene(NULL)
		{

		}

		CSceneLoadEvent::~CSceneLoadEvent()
		{

		}

		void CSceneLoadEvent::setGeoScene(VirtualMine::SpatialInterface::IScene* ref_pScene)
		{
			ref_mpGeoScene = ref_pScene;
		}

		VirtualMine::SpatialInterface::IScene* CSceneLoadEvent::getGeoScene()
		{
			return this->ref_mpGeoScene;
		}
		
		CFlyToEvent::CFlyToEvent()
		{
			
		}
		
		CFlyToEvent::~CFlyToEvent()
		{
		
		}

		void CFlyToEvent::setFlyToPosition(const Ogre::Vector3& position)
		{
			this->mFlyToPosition = position;
		}	

		Ogre::Vector3 CFlyToEvent::getFlyToPosition()
		{
			return this->mFlyToPosition;
		}

		void CFlyToEvent::setCurTime(const Ogre::Real& curTime)
		{
			this->mCurTime = curTime;
		}
		
		Ogre::Real CFlyToEvent::getCurTime()
		{
			return this->mCurTime;
		}

		CFrameEvent::CFrameEvent()
		{
			this->mData.timeSinceLastEvent = 0 ;
			this->mData.timeSinceLastFrame = 0 ;
		}

		CFrameEvent::~CFrameEvent()
		{
		
		}

		void CFrameEvent::setTime(const Ogre::Real& timeSinceLastEvent,const Ogre::Real& timeSinceLastFrame)
		{
			this->mData.timeSinceLastEvent = timeSinceLastEvent;
			this->mData.timeSinceLastFrame = timeSinceLastFrame;
		}
		
		void CFrameEvent::getTime(Ogre::Real& timeSinceLastEvent,Ogre::Real& timeSinceLastFrame)
		{
			timeSinceLastEvent = this->mData.timeSinceLastEvent;
			timeSinceLastFrame = this->mData.timeSinceLastFrame;
		}

		void CFrameEvent::setCurTime(const Ogre::Real& curTime)
		{
			this->mCurTime = curTime;
		}
		
		Ogre::Real CFrameEvent::getCurTime()
		{
			return this->mCurTime;
		}

		CDataSetLoadEvent::CDataSetLoadEvent()
		{
			this->mDataSetName = "";
			this->mDataSetType = "";
		}
		
		CDataSetLoadEvent::~CDataSetLoadEvent()
		{
		
		}

		std::string CDataSetLoadEvent::getDataSetName()
		{
			return this->mDataSetName;
		}
		
		void CDataSetLoadEvent::setDataSetName(const std::string& dataSetName)
		{
			this->mDataSetName = dataSetName;
		}

		std::string CDataSetLoadEvent::getDataSetType()
		{
			return this->mDataSetType;
		}

		void CDataSetLoadEvent::setDataSetType(const std::string& dataSetType)
		{
			this->mDataSetType = dataSetType;
		}

		CLayerLoadEvent::CLayerLoadEvent()
		{
			this->ref_mpLayer = NULL;
		}
		
		CLayerLoadEvent::~CLayerLoadEvent()
		{
		
		}

		VirtualMine::SpatialInterface::ILayer* CLayerLoadEvent::getLayer()
		{
			return this->ref_mpLayer;
		}
		
		void CLayerLoadEvent::setLayer(VirtualMine::SpatialInterface::ILayer* ref_pLayer)
		{
			this->ref_mpLayer = 	ref_pLayer;
		}

		CLayerRemoveEvent::CLayerRemoveEvent()
		{

		}

		CLayerRemoveEvent::~CLayerRemoveEvent()
		{

		}

		VirtualMine::SpatialInterface::ILayer* CLayerRemoveEvent::getLayer()
		{
			return this->ref_mpLayer;
		}

		void CLayerRemoveEvent::setLayer(VirtualMine::SpatialInterface::ILayer* ref_pLayer)
		{
			this->ref_mpLayer = ref_pLayer;
		}

		CExportInfoEvent::CExportInfoEvent()
		{
			this->mInfo = "";
		}
		
		CExportInfoEvent::~CExportInfoEvent()
		{

		}
		
		void CExportInfoEvent::setInfo(const std::string& info)
		{
			this->mInfo = info;
		}
		
		std::string CExportInfoEvent::getInfo()
		{
			return this->mInfo;
		}

		CDataSourceLoadEvent::CDataSourceLoadEvent()
			:ref_mpDataSourceMgr(NULL)
		{

		}

		CDataSourceLoadEvent::~CDataSourceLoadEvent()
		{

		}

		void CDataSourceLoadEvent::setDataSourceManager(VirtualMine::Database::IDataSourceManager* ref_pDataSourceMgr)
		{
			this->ref_mpDataSourceMgr = ref_pDataSourceMgr;
		}

		VirtualMine::Database::IDataSourceManager* CDataSourceLoadEvent::getDataSourceManager()
		{
			return this->ref_mpDataSourceMgr;
		}

		CSceneRenderEvent::CSceneRenderEvent()
			:ref_mpGeoScene(NULL)
		{

		}
		CSceneRenderEvent::~CSceneRenderEvent()
		{

		}
		void CSceneRenderEvent::setGeoScene(VirtualMine::SpatialInterface::IScene* ref_pScene)
		{
			this->ref_mpGeoScene = ref_pScene;
		}

		VirtualMine::SpatialInterface::IScene* CSceneRenderEvent::getGeoScene()
		{
			return this->ref_mpGeoScene;
		}

		CLayerRenderEvent::CLayerRenderEvent()
			:ref_mpLayer(NULL)
		{

		}

		CLayerRenderEvent::~CLayerRenderEvent()
		{

		}

		VirtualMine::SpatialInterface::ILayer* CLayerRenderEvent::getLayer()
		{
			return this->ref_mpLayer;
		}

		void CLayerRenderEvent::setLayer(VirtualMine::SpatialInterface::ILayer* ref_pLayer)
		{
			this->ref_mpLayer = ref_pLayer;
		}
	}
}
