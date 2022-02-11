#ifndef VRLAYERITEM_H
#define VRLAYERITEM_H

#include <QtGui/QWidget>
#include <QWidgetItem>
#include <QItemSelectionModel>
#include <QTreeWidgetItem>  
#include <string>
#include "vrmine\vr_spatialinterface\ilayer.h"
#include "vrmine\vr_spatialinterface\igeoobject.h"

//定义插件导出符号
#ifndef QSCENETREE_EXPORT_WIDGETS
#define VRSCENETREE_DLL _declspec(dllimport)
#else
#define VRSCENETREE_DLL _declspec(dllexport)
#endif

class VRSCENETREE_DLL VRSceneManagerItem : public QTreeWidgetItem
{
public :
	VRSceneManagerItem(){};
	~VRSceneManagerItem(){};
};

class VRSCENETREE_DLL VRSceneItem : public QTreeWidgetItem
{
public :
	VRSceneItem(){};
	~VRSceneItem(){};
};

class VRSCENETREE_DLL VRLayerItem : public QTreeWidgetItem
{
public :
	VRLayerItem();
	~VRLayerItem();
	virtual std::string& getType();
	virtual void setType(const std::string& type);
	virtual void setBindingObject(VirtualMine::SpatialInterface::ILayer* ref_pBindingObject);
	virtual VirtualMine::SpatialInterface::ILayer* getBindingObject();
protected :
	std::string mType;
	VirtualMine::SpatialInterface::ILayer* ref_mpBindingObject;
};


class VRSCENETREE_DLL VRFeatureItem : public QTreeWidgetItem
{
public :
	VRFeatureItem();
	virtual ~VRFeatureItem();
	virtual void setBindingObject(VirtualMine::SpatialInterface::IGeoObject* ref_pBindingObject);
	virtual VirtualMine::SpatialInterface::IGeoObject* getBindingObject();
protected:
	VirtualMine::SpatialInterface::IGeoObject* ref_mpBindingObject;

	
};



#endif // VRLAYERITEM_H
