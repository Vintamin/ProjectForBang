#ifndef VRSCENETREEWIDGET_H
#define VRSCENETREEWIDGET_H

#include <QtGui/QWidget>
#include <QTreeWidget>
#include "vrmine\vr_scenecontrol\geospatialcontrol.h"
#include "vrmine\vr_scenecontrol\geospatialscene.h"
#include "vrmine\vr_spatialengine\geoscenemanager.h"
#include "vrmine\vr_core\event.h"
#include "vrmine\vr_spatialobject\mine\modelobject.h"
#include "vrmine/vr_scenecontrol/geospatialcontrol.h"
#include "vrmine/vr_plugins/treeitem/layeritem.h"

class VRSceneTreeWidget_PrivateData;
class VRAsynchronousHandler;
class VRSCENETREE_DLL VRSceneTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	VRSceneTreeWidget(QWidget *parent = 0);
	virtual ~VRSceneTreeWidget();
	virtual void setGeoSpatialScene(VirtualMine::SpatialInterface::IScene* ref_pScene);
	virtual VirtualMine::SpatialInterface::IScene* getGeoSpatialScene();
	virtual void initialControl();
	virtual void unLoadScene();
	virtual void unLoadItem(QTreeWidgetItem* item);
	virtual void loadLayer(VirtualMine::SpatialInterface::ILayer* pLayer);
	void removeLayer();
	virtual void loadGeoObject(QTreeWidgetItem* parentItem,VirtualMine::SpatialInterface::IGeoObject* pObject);
	virtual void createDefaultItems();
	virtual std::string getItemIconName(VirtualMine::SpatialInterface::ILayer* pLayer);
	virtual void setGeoSceneControl(VirtualMine::Scene::CGeoSpatialControl* ref_pSceneControl);
	virtual void deleteBasicSceneItem();
protected:
	void contextMenuEvent(QContextMenuEvent * event ); 
	void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *  event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	protected slots:
		//图层操作
		void setLayerVisible();
		void setDataSetProperty();
		void setLayerProperty();
		void setRemoveLayer();
		//场景管理操作
		void slotCreateScene();
		//场景操作
		void slotAddLayer();
		//模型操作
		void slotAddModel();
		void slotModelProperty();
private:
	VRSceneTreeWidget_PrivateData* mpPrivate;

};

class VRSCENETREE_DLL CSceneControlInitialHandler : public VirtualMine::Core::CEventHandler
{
public:
	CSceneControlInitialHandler(VRSceneTreeWidget* ref_pOperator);
	~CSceneControlInitialHandler();
	virtual bool handleEvent(VirtualMine::Core::CEvent* evt);
protected:
	VRSceneTreeWidget* ref_mpOperator;

};

class VRSCENETREE_DLL CSceneLoadHandler_SceneTreeWidget : public VirtualMine::Core::CEventHandler
{
public :
	CSceneLoadHandler_SceneTreeWidget();
	CSceneLoadHandler_SceneTreeWidget(VRSceneTreeWidget* pControl);
	virtual ~CSceneLoadHandler_SceneTreeWidget();
	virtual bool handleEvent(VirtualMine::Core::CEvent* evt);

private:
	VRSceneTreeWidget* ref_mpControl;
};

class VRSCENETREE_DLL CLayerLoadHandler_SceneTreeWidget : public VirtualMine::Core::CEventHandler
{
public :
	CLayerLoadHandler_SceneTreeWidget();
	CLayerLoadHandler_SceneTreeWidget(VRSceneTreeWidget* pControl);
	virtual ~CLayerLoadHandler_SceneTreeWidget();
	virtual bool handleEvent(VirtualMine::Core::CEvent* evt);

private:
	VRSceneTreeWidget* ref_mpControl;
};

class CRenderThread : public Ogre::FrameListener
{
public:
	CRenderThread();
	~CRenderThread();
	virtual bool frameStarted(const Ogre::FrameEvent& evt);
	virtual void setOperator(VRAsynchronousHandler* ref_pOperator);
protected:
	VRAsynchronousHandler* ref_mpOperator;
};

#endif // VRSCENETREEWIDGET_H
