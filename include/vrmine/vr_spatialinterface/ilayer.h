//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : ilayer.h
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_ILAYER_H)
#define _ILAYER_H

#include "vrmine/vr_core/coredefine.h"
#include "vrmine\vr_spatialinterface\irenderableobject.h"
#include "vrmine/vr_spatialinterface/igeoobject.h"

#include "vrmine/vr_databaseengine/database/idataset.h"
#include "vrmine/vr_databaseengine/database/idatasource.h"
#include "vrmine/vr_core/factory.h"
#include "vrmine/vr_spatialinterface/istyle.h"
#include "OGRE\OgreSceneManager.h"
#include "vrmine/vr_core/factory.h"
#include "OGRE/OgreAxisAlignedBox.h"


namespace VirtualMine
{
	namespace SpatialInterface
	{
		class IScene;
		class VR_SPATIALINTERFACE_DLL ILayer : public VirtualMine::Core::CBaseObject
		{
		public:
			ILayer();
			virtual ~ILayer();
			virtual std::string getName()=0;
			virtual void setName(const std::string& name)=0;
			virtual bool getVisible()=0;
			virtual void setVisible(const bool& value)=0;
			virtual bool getSelectable()=0;
			virtual void setSelectable(const bool& value)=0;
			virtual void draw()=0;
			virtual void update()=0;
			virtual void initialise()=0;
			virtual void notifyUpdate()=0;
			virtual void setType(const std::string& type)=0;
			virtual std::string getType()=0;
			virtual VirtualMine::Database::IDataset* getDataSet()=0;
			virtual void setDataSet(VirtualMine::Database::IDataset* pDataSet)=0;		
	        virtual void setDatasource(VirtualMine::Database::IDataSource* pDatasoure)=0;
			virtual VirtualMine::Database::IDataSource* getDatabase()=0;
			virtual void setStyle(VirtualMine::SpatialInterface::IStyle* pStyle)=0;
			virtual VirtualMine::SpatialInterface::IStyle* getStyle()=0;
			virtual void setGeoSceneManager(Ogre::SceneManager* ref_pSceneManager)=0;
			virtual Ogre::SceneManager* getGeoSceneManager()=0;
			virtual void setBoundingBox(const Ogre::AxisAlignedBox& boundingBox)=0;
			virtual Ogre::AxisAlignedBox& getBoundingBox()=0;
			virtual void setScene(IScene* pScene)=0;
			virtual IScene* getScene()=0;
			virtual void  setFrameMode(bool isFrameMode) = 0;
			virtual void setLayerMaxRenderDistance(const double& value)=0;
			virtual double getLayerMaxRenderDistance()=0;
			virtual void setLayerMinRenderDistance(const double& value)=0;
			virtual double getLayerMinRenderDistance()=0;
			virtual void setNeedLabel(const bool& needLabel)=0;
			virtual bool getNeedLabel()=0;
			virtual void setLabelMaxRenderDistance(const double& value)=0;
			virtual double getLabelMaxRenderDistance()=0;
			virtual void setLabelMinRenderDistance(const double& value)=0;
			virtual double getLabelMinRenderDistance()=0;
			virtual void resetResource();
			virtual std::vector<Ogre::SceneNode*> getTextNodes()=0;

			virtual void getGeoObjects(VirtualMine::SpatialInterface::GeoObjectVector& geoObjects)=0;
			virtual VirtualMine::SpatialInterface::IGeoObject* getGeoObject(const std::string& name)=0;

		};
		typedef std::map<std::string,VirtualMine::SpatialInterface::ILayer*> LayerMap;
		/*class CLayerFactory;
		typedef VirtualMine::Core::CRegister<CLayerFactory> CLayerFactoryRegister;*/
		class VR_SPATIALINTERFACE_DLL CLayerFactory : public VirtualMine::Core::CFactory
		{
		public:
			CLayerFactory();
			~CLayerFactory();
			virtual VirtualMine::Core::CBaseObject* createInstance();
			virtual ILayer* createInstance(const std::string& name);
			virtual void destroyInstance(ILayer* pLayer);
			virtual std::string getType();
		};
		
	}
}

#endif  //_ILAYER_H
