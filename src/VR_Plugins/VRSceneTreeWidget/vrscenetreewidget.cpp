#include "vrmine\vr_plugins\vrscenetreewidget.h"
#include "vrmine\vr_plugins\treeitem\layeritem.h"
#include "vrmine\vr_core\geodatatype.h"
#include <QTextCodec>
#include "vrmine\vr_spatialinterface\ilayer.h"
#include "vrmine\vr_spatialinterface\event\eventobject.h"
#include "qmenu.h"
#include "qevent.h"
#include "vrmine/vr_generalui/layerpropertyDlg.h"
#include "vrmine/vr_projectmanager/project/projectmanager.h"
#include <QThread>
#include <QReadWriteLock>
#include <QWaitCondition>
#include "vrmine/vr_spatiallayer/modellayer.h"
#include "vrmine/vr_generalui/modelpropertyDlg.h"
#include "OGRE/OgreRoot.h"
#include "vrmine/vr_geometry/geometry/point.h"
#include "vrmine/vr_spatialinterface/iscene.h"
#include "vrmine/vr_databaseengine/database/database.h"
#include <QString>
#include <QApplication>
#include "vrmine/vr_sqlitedatabase/sqlitedatabase/sqlitedatabase.h"
#include "vrmine/vr_databaseengine/database/logicfeature.h"
#include "vrmine/vr_databaseengine/database/logicdataset.h"

using namespace VirtualMine::Scene;
using namespace VirtualMine::Core;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::SpatialLayer;
using namespace VirtualMine::Geometry;
using namespace VirtualMine::Database;

class VRAsynchronousHandler : public VirtualMine::Core::CEventHandler,public QThread
{
	friend class CRenderThread;
public:
	VRAsynchronousHandler()
	{
		mpRenderThread = new CRenderThread();
		mpRenderThread->setOperator(this);
		/*Ogre::Root::getSingleton().addFrameListener(mpRenderThread);*/
	}

	virtual ~VRAsynchronousHandler()
	{

	}

	virtual void addRenderEventToScene(CEvent* pEvent)
	{
		mRenderLock.lockForWrite();
		this->mEventLoadedQueue.push_back(pEvent);
		mRenderLock.unlock();
	}

	virtual void run()
	{
		Ogre::Root::getSingleton().getRenderSystem()->registerThread();
		while (true)
		{
			{
				//mWaitCondition.wait(&mLock);
			}
			mLock.lockForWrite();
			{
				if (!this->mEventQueue.empty())
				{
					for (size_t i = 0 ; i < this->mEventQueue.size(); ++i)
					{
						CEvent* pEvent = this->mEventQueue.at(i);
						//CEventDispatcher::setEvent(pEvent);
						if (CSceneRenderEvent* pRenerEvent = dynamic_cast<CSceneRenderEvent*>(pEvent))
						{
							pRenerEvent->getGeoScene()->initial();
							this->addRenderEventToScene(pEvent);
						}
						else if (CLayerRenderEvent* pRenerEvent = dynamic_cast<CLayerRenderEvent*>(pEvent))
						{
							pRenerEvent->getLayer()->initialise();
							this->addRenderEventToScene(pEvent);
						}

					}
					this->mEventQueue.clear();
				}
			}
			mLock.unlock();
		}
		Ogre::Root::getSingleton().getRenderSystem()->unregisterThread();
	}

	virtual bool handleEvent(CEvent* evt)
	{
		if (CSceneRenderEvent* pRenerEvent = dynamic_cast<CSceneRenderEvent*>(evt))
		{
			/*CSceneRenderEvent* pTempRenderEvent = new CSceneRenderEvent();
			pTempRenderEvent->setGeoScene(pRenerEvent->getGeoScene());
			mLock.lockForWrite();
			{
				mEventQueue.push_back(pTempRenderEvent);
			}
			mLock.unlock();*/
			pRenerEvent->getGeoScene()->initial();
			pRenerEvent->getGeoScene()->draw();
			evt->accept();
		}
		else if (CLayerRenderEvent* pRenerEvent = dynamic_cast<CLayerRenderEvent*>(evt))
		{
			/*CLayerRenderEvent* pTempRenderEvent = new CLayerRenderEvent();
			pTempRenderEvent->setLayer(pRenerEvent->getLayer());
			mLock.lockForWrite();
			{
			mEventQueue.push_back(pTempRenderEvent);
			}
			mLock.unlock();*/
			pRenerEvent->getLayer()->initialise();
			pRenerEvent->getLayer()->draw();
			evt->accept();
		}
		return evt->isAccepted();
	}

private:
	CRenderThread* mpRenderThread;
	EventVector mEventQueue;
	EventVector mEventLoadedQueue;
	QReadWriteLock mLock;
	QReadWriteLock mRenderLock;
	QWaitCondition mWaitCondition;
};

class VRSceneTreeWidget_PrivateData
{
	friend class CRenderThread;
public :
	VRSceneTreeWidget_PrivateData()
		:ref_mpGeoSpatialScene(NULL),mpRootItem(NULL),mpLayerMenu(NULL),
		mpSceneLoadEventObject(NULL),mpLayerLoadEventObject(NULL),
		mpBasicSceneItem(NULL),mpSafeSceneItem(NULL),ref_mpSelectedItem(NULL),
		mpSceneMenu(NULL),mpSceneManagerMenu(NULL),mpCurSceneItem(NULL),
		mpFeatureMenu(NULL),ref_mpSceneControl(NULL),mpSceneControlEventObject(NULL)
	{
		mpAsynchronousHandler = new VRAsynchronousHandler();
		//mpAsynchronousHandler->start(QThread::LowPriority); 
	}

	~VRSceneTreeWidget_PrivateData()
	{
		if (mpSceneLoadEventObject)
		{
			delete mpSceneLoadEventObject;
			mpSceneLoadEventObject = NULL;
		}

		if (mpLayerLoadEventObject)
		{
			delete mpLayerLoadEventObject;
			mpLayerLoadEventObject = NULL;
		}
	}

public:
	QTreeWidgetItem * ref_mpSelectedItem;
	VRSceneManagerItem* mpRootItem;
	VRSceneItem* mpCurSceneItem;
	QTreeWidgetItem* mpBasicSceneItem;
	QTreeWidgetItem* mpSafeSceneItem;
	QMenu* mpFeatureMenu;
	QMenu* mpLayerMenu;
	QMenu* mpSceneMenu;
	QMenu* mpSceneManagerMenu;
	VirtualMine::Scene::CGeoSpatialScene* ref_mpGeoSpatialScene;
	CSceneLoadHandler_SceneTreeWidget* mpSceneLoadEventObject;
	CLayerLoadHandler_SceneTreeWidget* mpLayerLoadEventObject;
	CSceneControlInitialHandler* mpSceneControlEventObject;
	VRAsynchronousHandler* mpAsynchronousHandler;
	VirtualMine::Scene::CGeoSpatialControl* ref_mpSceneControl;
};

VRSceneTreeWidget::VRSceneTreeWidget(QWidget *parent)
	: QTreeWidget(parent)
{
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	this->mpPrivate = new VRSceneTreeWidget_PrivateData();
	this->createDefaultItems();

	this->mpPrivate->mpSceneLoadEventObject = new CSceneLoadHandler_SceneTreeWidget(this);
	this->mpPrivate->mpLayerLoadEventObject = new CLayerLoadHandler_SceneTreeWidget(this);
	this->mpPrivate->mpSceneControlEventObject = new CSceneControlInitialHandler(this);
}

VRSceneTreeWidget::~VRSceneTreeWidget()
{

}

void VRSceneTreeWidget::setGeoSpatialScene(VirtualMine::SpatialInterface::IScene* ref_pScene)
{
	this->mpPrivate->ref_mpGeoSpatialScene = dynamic_cast<VirtualMine::Scene::CGeoSpatialScene*>(ref_pScene);
}

VirtualMine::SpatialInterface::IScene* VRSceneTreeWidget::getGeoSpatialScene()
{
	return this->mpPrivate->ref_mpGeoSpatialScene;
}

void VRSceneTreeWidget::contextMenuEvent(QContextMenuEvent * event )
{
	QPoint point = QCursor::pos();
	point = mapFromGlobal(point);
	QTreeWidgetItem *item = this->itemAt(point);
	this->mpPrivate->ref_mpSelectedItem = item;
	if (item != NULL)
	{
		if (dynamic_cast<VRSceneManagerItem*>(item))
		{
			this->mpPrivate->mpSceneManagerMenu->exec(QCursor::pos());
		}
		else if (dynamic_cast<VRSceneItem*>(item))
		{
			this->mpPrivate->mpSceneMenu->exec(QCursor::pos());
		}
		else if (VRLayerItem* pLayerItem = dynamic_cast<VRLayerItem*>(item))
		{
			this->mpPrivate->mpLayerMenu->exec(QCursor::pos());
			event->accept();
		}
		else if (dynamic_cast<VRFeatureItem*>(item))
		{
			this->mpPrivate->mpFeatureMenu->exec(QCursor::pos());
			event->accept();
		}
	}
	
}

void VRSceneTreeWidget::mouseReleaseEvent(QMouseEvent *  event)
{
	QPoint point = QCursor::pos();
	point = mapFromGlobal(point);
	QTreeWidgetItem *item = this->itemAt(point);
	if (item)
	{
		VRLayerItem* pLayerItem = dynamic_cast<VRLayerItem*>(item);
		if (pLayerItem)
		{
			Qt::CheckState oldCheckstatus = item->checkState(0);
			QTreeWidget::mouseReleaseEvent(event);
			Qt::CheckState curCheckstatus = item->checkState(0);
			bool changed = (oldCheckstatus != curCheckstatus);
			if (changed)
			{
				pLayerItem->getBindingObject()->setVisible(curCheckstatus);
			}
		}
		
	}
	
}

void VRSceneTreeWidget::mousePressEvent(QMouseEvent * event)
{
	QTreeWidget::mousePressEvent(event);
}

void VRSceneTreeWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	QPoint point = QCursor::pos();
	point = mapFromGlobal(point);
	QTreeWidgetItem *item = this->itemAt(point);
	this->mpPrivate->ref_mpSelectedItem = item;

	VRFeatureItem* pFeatureItem = dynamic_cast<VRFeatureItem*>(this->mpPrivate->ref_mpSelectedItem);
	if (pFeatureItem == NULL)
	{
		return;
	}

	VRLayerItem* pLayerItem = dynamic_cast<VRLayerItem*>(pFeatureItem->parent());
	VirtualMine::Mine::CModelObject* pObject = dynamic_cast<VirtualMine::Mine::CModelObject*>(pFeatureItem->getBindingObject());

	if (pLayerItem == NULL || pObject == NULL)
	{
		return;
	}

	CPoint* position =dynamic_cast<CPoint*> (pObject->getGeometry());

	if (position != NULL)
	{
		VirtualMine::SpatialInterface::CFlyToEvent flyEvent;
		this->mpPrivate->ref_mpSceneControl->flyTo(position->getX(),position->getY(),position->getZ());
	}
}

void VRSceneTreeWidget::setLayerVisible()
{

}

void VRSceneTreeWidget::setDataSetProperty()
{
	if (this->mpPrivate->ref_mpSelectedItem)
	{
		VRLayerItem* pLayerItem = dynamic_cast<VRLayerItem*>(this->mpPrivate->ref_mpSelectedItem);
		if (pLayerItem)
		{
			VirtualMine::GeneralUI::CDataSetPropertyDlg dataSetPropertyDlg;
			dataSetPropertyDlg.BindingOjbect(pLayerItem->getBindingObject());
			dataSetPropertyDlg.initial();
			dataSetPropertyDlg.exec();
		}
	}
}

void VRSceneTreeWidget::slotCreateScene()
{
	VirtualMine::GeneralUI::CCreateNewSceneDlg createNewSceneDlg(this);

	//Ogre::Vector3 center =  VirtualMine::SpatialInterface::IScene::ReferenceCenter;
	 double minX,minY,minZ,maxX,maxY,maxZ; 
	//VirtualMine::Project::CProjectManager::getSingletonPtr()->getDataSourceManager()->getDataSource()->getReferenceCenter(x,y,z);

   //VirtualMine::Database::IDataSource* datasource = VirtualMine::Project::CProjectManager::getSingletonPtr()->getDataSourceManager()->getDataSource();
	 
	 if (!VirtualMine::Project::CProjectManager::getSingletonPtr()->getDataSourceManager())
	 {
		 return;
	 }
   VirtualMine::SQLiteDatabase::CSQLiteDatabase* sqlitedatabase = (VirtualMine::SQLiteDatabase::CSQLiteDatabase*)(VirtualMine::Project::CProjectManager::getSingletonPtr()->getDataSourceManager()->getDataSource());
   if (sqlitedatabase)
	{
	   CLogicDataset* dataset =	(CLogicDataset*)sqlitedatabase->getDataset("LogicDataset");
	   CLogicFeature* demfeature;
	   if (dataset)
	   {
		  int count = dataset->getFeatureList()->size();
		  for (int i = 0; i < count; i++)
		  {
			  std::string type = dataset->getFeature(i)->getFieldType();
			  if (type == VirtualMine::Core::GeoDataType::GDT_DEM)
			  {
				  demfeature = (CLogicFeature*)dataset->getFeature(i);
			  }
		  }
	   }
	   

	 
	   minX = demfeature->getFieldminRangeX();
	   minY = demfeature->getFieldminRangeY();
	   minZ = demfeature->getFieldminRangeZ();


	   maxX = demfeature->getFieldmaxRangeX();
	   maxY = demfeature->getFieldmaxRangeY();
       maxZ = demfeature->getFieldmaxRangeZ();



	   //sqlitedatabase->getReferenceCenter(x,y,z);
   }
   double centerX = 0.5*(minX + maxX);
   double centerY = 0.5*(minY + maxY);
   double centerZ = 0.5*(minZ + maxZ);


   /////不是ogre场景坐标系
   createNewSceneDlg.setRefcenteCenterX(centerX);
   createNewSceneDlg.setRefcenteCenterY(centerY);
   createNewSceneDlg.setRefcenteCenterZ(centerZ);
	
	int ret = createNewSceneDlg.exec();
	if (ret == QDialog::Accepted
		&& createNewSceneDlg.getSceneName() != "")
	{
		VirtualMine::Project::CProjectManager::getSingletonPtr()->createScene(createNewSceneDlg.getSceneName(),
			createNewSceneDlg.getReferenceCenter(),"xian_1980");
	}
	QString curDir = QCoreApplication::applicationDirPath();	
	dynamic_cast<VirtualMine::Scene::CGeoSpatialScene*>(this->getGeoSpatialScene())->setCurDirName(curDir.toStdString());
}

void VRSceneTreeWidget::slotAddLayer()
{
	VirtualMine::GeneralUI::CLayerAddDlg layerAddDlg(this);
	layerAddDlg.bindingControl(this->mpPrivate->ref_mpSceneControl);
	int ret = layerAddDlg.exec();
	if (ret == QDialog::Accepted)
	{
		VirtualMine::Project::CProjectManager::getSingletonPtr()->createLayer(layerAddDlg.getLayerName(),
			layerAddDlg.getLayerType(),layerAddDlg.getDataSetName());
	}
}

void VRSceneTreeWidget::setLayerProperty()
{
	if (this->mpPrivate->ref_mpSelectedItem)
	{
		VRLayerItem* pLayerItem = dynamic_cast<VRLayerItem*>(this->mpPrivate->ref_mpSelectedItem);
		if (pLayerItem)
		{
			VirtualMine::GeneralUI::CLayerPropertyDlg layerPropertyDlg;
			layerPropertyDlg.BindingOjbect(pLayerItem->getBindingObject());
			layerPropertyDlg.initial();
			layerPropertyDlg.exec();
		}
	}
}

void VRSceneTreeWidget::setRemoveLayer()
{
	if (this->mpPrivate->ref_mpSelectedItem)
	{
		VRLayerItem* pLayerItem = dynamic_cast<VRLayerItem*>(this->mpPrivate->ref_mpSelectedItem);
		if (pLayerItem)
		{
			
			std::string layerName = pLayerItem->getBindingObject()->getName();
			VirtualMine::Project::CProjectManager::getSingletonPtr()->removeLayer(layerName);
			this->unLoadItem(pLayerItem);
				
		}
	}
}

void VRSceneTreeWidget::setGeoSceneControl(VirtualMine::Scene::CGeoSpatialControl* ref_pSceneControl)
{
	this->mpPrivate->ref_mpSceneControl = ref_pSceneControl;
}

std::string VRSceneTreeWidget::getItemIconName(VirtualMine::SpatialInterface::ILayer* pLayer)
{
	std::string iconName = "data\\layermangericon\\default.png";
	std::string type = pLayer->getType();
	if (type == GeoDataType::GDT_IMAGE)
	{
		iconName = "data\\layermangericon\\image.png";
	}
	else if (type == GeoDataType::GDT_DEM)
	{
		iconName = "data\\layermangericon\\dem.png";
	}
	else if (type == GeoDataType::GDT_MODEL)
	{
		iconName = "data\\layermangericon\\surfacemodel.png";
	}
	else if (type == GeoDataType::GDT_VECTOR)
	{
		iconName = "data\\layermangericon\\image.png";
	}
	else if (type == GeoDataType::GDT_COALSEAM)
	{
		iconName = "data\\layermangericon\\coallayer.png";
	}
	else if (type == GeoDataType::GDT_DRILL)
	{
		iconName = "data\\layermangericon\\drill.png";
	}
	else if (type == GeoDataType::GDT_LANWAY)
	{
		iconName = "data\\layermangericon\\laneway.png";
	}
	else if (type == GeoDataType::GDT_FAULT)
	{
		iconName = "data\\layermangericon\\fault.png";
	}
	else if (type == GeoDataType::GDT_MININGAREA)
	{
		iconName = "data\\layermangericon\\miningArea.png";
	}
	else if (type == GeoDataType::GDT_MINE)
	{
		iconName = "data\\layermangericon\\mine.png";
	}
	else if (type == GeoDataType::GDT_WORKINGPLANE)
	{
		iconName = "data\\layermangericon\\wordSurface.png";
	}
	
	return iconName;
}

void VRSceneTreeWidget::createDefaultItems()
{
	this->setHeaderHidden(true);

#if 1
	//创建场景根节点
	this->mpPrivate->mpRootItem = new VRSceneManagerItem();
	this->mpPrivate->mpRootItem->setText(0,QString(tr("数字矿山管理")).arg(1));
	std::string iconName = "data\\layermangericon\\digitalmine.png";
	this->mpPrivate->mpRootItem->setIcon(0,QIcon(iconName.c_str()));
	this->addTopLevelItem(this->mpPrivate->mpRootItem);

#endif
	this->expandAll();

	//创建模型快捷菜单
	this->mpPrivate->mpFeatureMenu = new QMenu(this);
	QAction * pModelPropertyAction = new QAction(tr("模型属性"),this);
	
	connect(pModelPropertyAction, SIGNAL(triggered()), this, SLOT(slotModelProperty())); 
	this->mpPrivate->mpFeatureMenu->addAction(pModelPropertyAction);

	//创建图层快捷菜单
	this->mpPrivate->mpLayerMenu = new QMenu(this);
	QAction * pLayerPropertyAction = new QAction(tr("图层属性"),this);
	QAction * pDataSetPropertyAction = new QAction(tr("数据集属性"),this);
	QAction * pModelAddAction = new QAction(tr("添加要素"),this);
	QAction * pRemoveLayer = new QAction(tr("删除图层"),this);

	connect(pModelAddAction, SIGNAL(triggered()), this, SLOT(slotAddModel())); 
	connect(pDataSetPropertyAction, SIGNAL(triggered()), this, SLOT(setDataSetProperty())); 
	connect(pLayerPropertyAction, SIGNAL(triggered()), this, SLOT(setLayerProperty())); 
	connect(pRemoveLayer, SIGNAL(triggered()), this, SLOT(setRemoveLayer()));

	this->mpPrivate->mpLayerMenu->addAction(pModelAddAction);
	this->mpPrivate->mpLayerMenu->addAction(pLayerPropertyAction);
	this->mpPrivate->mpLayerMenu->addAction(pDataSetPropertyAction);
	this->mpPrivate->mpLayerMenu->addAction(pRemoveLayer);
	//创建场景快捷菜单
	this->mpPrivate->mpSceneMenu = new QMenu(this);
	QAction * pAddLayerAction = new QAction(tr("添加图层"),this);
	connect(pAddLayerAction, SIGNAL(triggered()), this, SLOT(slotAddLayer())); 
	this->mpPrivate->mpSceneMenu->addAction(pAddLayerAction);

	//创建场景快捷菜单
	this->mpPrivate->mpSceneManagerMenu = new QMenu(this);
	QAction * pCreateSceneAction = new QAction(tr("创建场景"),this);
	connect(pCreateSceneAction, SIGNAL(triggered()), this, SLOT(slotCreateScene()));
	this->mpPrivate->mpSceneManagerMenu->addAction(pCreateSceneAction);

}

void VRSceneTreeWidget::slotAddModel()
{
	if (this->mpPrivate->ref_mpSelectedItem)
	{
		VRLayerItem* pLayerItem = dynamic_cast<VRLayerItem*>(this->mpPrivate->ref_mpSelectedItem);
		if (pLayerItem && pLayerItem->getBindingObject()->getType() == GeoDataType::GDT_MODEL)
		{
			VRFeatureItem* pFeatureItem = dynamic_cast<VRFeatureItem*>(this->mpPrivate->ref_mpSelectedItem);
			VirtualMine::GeneralUI::CModelPropertyDlg* modelDlg = new VirtualMine::GeneralUI::CModelPropertyDlg(this);
			modelDlg->setGeoSceneControl(this->mpPrivate->ref_mpSceneControl);
			modelDlg->BindingLayer(pLayerItem->getBindingObject());
			modelDlg->initial();
			//modelDlg.exec();
			modelDlg->show();
		}
	}
}

void VRSceneTreeWidget::slotModelProperty()
{
	if (this->mpPrivate->ref_mpSelectedItem && this->mpPrivate->ref_mpSceneControl)
	{
		VRFeatureItem* pFeatureItem = dynamic_cast<VRFeatureItem*>(this->mpPrivate->ref_mpSelectedItem);
		VRLayerItem* pLayerItem = dynamic_cast<VRLayerItem*>(pFeatureItem->parent());
		VirtualMine::Mine::CModelObject* pObject = dynamic_cast<VirtualMine::Mine::CModelObject*>(pFeatureItem->getBindingObject());

		if (pLayerItem == NULL || pObject == NULL)
		{
			return;
		}

		VirtualMine::GeneralUI::CModelPropertyDlg* modelDlg = new VirtualMine::GeneralUI::CModelPropertyDlg(this);
		modelDlg->setGeoSceneControl(this->mpPrivate->ref_mpSceneControl);
		modelDlg->BindingLayer(pLayerItem->getBindingObject());
		modelDlg->BindingOjbect(pObject);
		modelDlg->initial();
		modelDlg->show();
	}
}

void VRSceneTreeWidget::loadLayer(VirtualMine::SpatialInterface::ILayer* pLayer)
{
	assert(pLayer);
	if (NULL == pLayer)
		return;
	/*VirtualMine::SpatialInterface::CExportInfoEvent exEvt;
	std::string info = "正在加载图层" + pLayer->getName() + "...";
	exEvt.setInfo(info);
	CEventDispatcher::setEvent(&exEvt);*/

	VRLayerItem* pLayerItem = new VRLayerItem();
	pLayerItem->setType(pLayer->getType());
	Qt::CheckState checkState = pLayer->getVisible() ? Qt::Checked : Qt::Unchecked;  
	pLayerItem->setCheckState(0,checkState);
	pLayerItem->setBindingObject(pLayer);
	std::string iconName = this->getItemIconName(pLayer);
	pLayerItem->setIcon(0,QIcon(iconName.c_str()));
	pLayerItem->setText(0,QString(tr(pLayer->getName().c_str())).arg(1));
	this->mpPrivate->mpCurSceneItem->addChild(pLayerItem);

	if (pLayer->getType() == GeoDataType::GDT_MODEL)
	{
		CModelLayer* pModelLayer = dynamic_cast<CModelLayer*>(pLayer);
		GeoObjectVector geoObjects;
		pModelLayer->getGeoObjects(geoObjects);
		for (size_t i = 0; i < geoObjects.size(); ++i)
		{
			this->loadGeoObject(pLayerItem,geoObjects.at(i));
		}
	}
}

void VRSceneTreeWidget::removeLayer()
{
	this->setRemoveLayer();
}

void VRSceneTreeWidget::loadGeoObject(QTreeWidgetItem* parentItem,
	VirtualMine::SpatialInterface::IGeoObject* pObject)
{
	VRFeatureItem* pFeatureItem = new VRFeatureItem();
	/*Qt::CheckState checkState = Qt::Checked;  */
	//pLayerItem->setCheckState(0,checkState);
	pFeatureItem->setBindingObject(pObject);
	std::string iconName = "data\\layermangericon\\default.png";
	pFeatureItem->setIcon(0,QIcon(iconName.c_str()));
	pFeatureItem->setText(0,QString(tr(pObject->getName().c_str())).arg(1));
	parentItem->addChild(pFeatureItem);
}

void VRSceneTreeWidget::initialControl()
{
	if (this->mpPrivate->mpBasicSceneItem)
	{
		return;
	}
	if (this->mpPrivate->ref_mpGeoSpatialScene != NULL)
	{
		//初始化基础场景节点
		{
			this->mpPrivate->mpBasicSceneItem = new QTreeWidgetItem();
			this->mpPrivate->mpBasicSceneItem->setText(0,QString(tr("基础场景")).arg(1));
			this->mpPrivate->mpBasicSceneItem->setIcon(0,QIcon("data\\layermangericon\\basicscene.png"));
			this->mpPrivate->mpRootItem->addChild(this->mpPrivate->mpBasicSceneItem);
		}
		////初始化安全场景节点
		//{
		//	this->mpPrivate->mpSafeSceneItem = new QTreeWidgetItem();
		//	this->mpPrivate->mpSafeSceneItem->setText(0,QString(tr("矿山安全")).arg(1));
		//	this->mpPrivate->mpSafeSceneItem->setIcon(0,QIcon("data\\layermangericon\\safescene.png"));
		//	this->mpPrivate->mpRootItem->addChild(this->mpPrivate->mpSafeSceneItem);
		//}
		//加载当前场景节点

		this->mpPrivate->mpCurSceneItem = new VRSceneItem();
		this->mpPrivate->mpCurSceneItem->setText(0,QString(this->mpPrivate->ref_mpGeoSpatialScene->getName().c_str()).arg(1));
		this->mpPrivate->mpCurSceneItem->setIcon(0,QIcon("data\\layermangericon\\basicscene.png"));
		this->mpPrivate->mpBasicSceneItem->addChild(this->mpPrivate->mpCurSceneItem);

		//VirtualMine::SpatialInterface::CExportInfoEvent exEvt;
		/*exEvt.setInfo("正在加载场景...");
		CEventDispatcher::setEvent(&exEvt);*/

		VirtualMine::SpatialInterface::LayerMap::iterator bItr = this->mpPrivate->ref_mpGeoSpatialScene->getLayerMap().begin();
		VirtualMine::SpatialInterface::LayerMap::iterator eItr = this->mpPrivate->ref_mpGeoSpatialScene->getLayerMap().end();
		while (bItr != eItr)
		{			
			this->loadLayer(bItr->second);
			++bItr;
		}
		this->expandAll();
	}
}

void VRSceneTreeWidget::unLoadItem(QTreeWidgetItem* item)
{
	if (item)
	{
		if (item->childCount() > 0) 
		{
			for (int i = 0; i < item->childCount();++i)
			{
				QTreeWidgetItem* childItem = item->child(i);
				this->unLoadItem(childItem);
				item->removeChild(childItem);
			}	
		}
		delete item;
		item = NULL;
	}
}

void VRSceneTreeWidget::unLoadScene()
{
	if (this->mpPrivate->mpRootItem)
	{
		this->mpPrivate->mpRootItem->removeChild(this->mpPrivate->mpBasicSceneItem);
		this->unLoadItem(this->mpPrivate->mpBasicSceneItem);
		this->mpPrivate->mpBasicSceneItem = NULL;
		this->mpPrivate->mpCurSceneItem = NULL;
	}

}

void VRSceneTreeWidget::deleteBasicSceneItem()
{
	if (this->mpPrivate->mpBasicSceneItem)
	{
		delete this->mpPrivate->mpBasicSceneItem;
		this->mpPrivate->mpBasicSceneItem = NULL;
	}
	if (this->mpPrivate->ref_mpGeoSpatialScene)
	{
		delete this->mpPrivate->ref_mpGeoSpatialScene;
		this->mpPrivate->ref_mpGeoSpatialScene = NULL;
	}
}

CSceneLoadHandler_SceneTreeWidget::CSceneLoadHandler_SceneTreeWidget()
	:ref_mpControl(NULL)
{

}

CSceneLoadHandler_SceneTreeWidget::CSceneLoadHandler_SceneTreeWidget(VRSceneTreeWidget* pControl)
	:ref_mpControl(pControl)
{

}

CSceneLoadHandler_SceneTreeWidget::~CSceneLoadHandler_SceneTreeWidget()
{

}

bool CSceneLoadHandler_SceneTreeWidget::handleEvent(VirtualMine::Core::CEvent* evt)
{
	CSceneLoadEvent* pSceneEvent = dynamic_cast<CSceneLoadEvent*>(evt);
	if (pSceneEvent && this->ref_mpControl)
	{
		this->ref_mpControl->setGeoSpatialScene(pSceneEvent->getGeoScene());
		this->ref_mpControl->initialControl();
		return true;
	}
	return false;
}

CLayerLoadHandler_SceneTreeWidget::CLayerLoadHandler_SceneTreeWidget()
{
	this->ref_mpControl = NULL;
}

CLayerLoadHandler_SceneTreeWidget::CLayerLoadHandler_SceneTreeWidget(VRSceneTreeWidget* pControl)
	:ref_mpControl(pControl)
{

}

CLayerLoadHandler_SceneTreeWidget::~CLayerLoadHandler_SceneTreeWidget()
{

}

bool CLayerLoadHandler_SceneTreeWidget::handleEvent(VirtualMine::Core::CEvent* evt)
{
	CLayerLoadEvent* pLayerLoadEvent = dynamic_cast<CLayerLoadEvent*>(evt);
	if (pLayerLoadEvent && this->ref_mpControl)
	{
		this->ref_mpControl->loadLayer(pLayerLoadEvent->getLayer());
		CLayerRenderEvent layerRenderEvt;
		layerRenderEvt.setLayer(pLayerLoadEvent->getLayer());
		CEventDispatcher::setEvent(&layerRenderEvt);
		return true;
	}

	CLayerRemoveEvent* pLayerRemoveEvent = dynamic_cast<CLayerRemoveEvent*>(evt);
	if (pLayerRemoveEvent && this->ref_mpControl)
	{
		this->ref_mpControl->removeLayer();
		return true;
	}

	CSceneUnLoadEvent* pSceneUnLoadEvent = dynamic_cast<CSceneUnLoadEvent*>(evt);
	if (pSceneUnLoadEvent && this->ref_mpControl)
	{
		this->ref_mpControl->unLoadScene();
		return true;
	}

	return false;
}

CSceneControlInitialHandler::CSceneControlInitialHandler(VRSceneTreeWidget* ref_pOperator)
	:ref_mpOperator(ref_pOperator)
{

}

CSceneControlInitialHandler::~CSceneControlInitialHandler()
{

}

bool CSceneControlInitialHandler::handleEvent(VirtualMine::Core::CEvent* evt)
{
	VirtualMine::Scene::CControlInitialEvent* pEvent = dynamic_cast<VirtualMine::Scene::CControlInitialEvent*>(evt);
	if (pEvent)
	{
		this->ref_mpOperator->setGeoSceneControl(pEvent->getBindingObject());
		evt->accept();
	}
	return evt->isAccepted();
}

CRenderThread::CRenderThread()
{


}

CRenderThread::~CRenderThread()
{

}

bool CRenderThread::frameStarted(const Ogre::FrameEvent& evt)
{
	if (this->ref_mpOperator)
	{
		{
			this->ref_mpOperator->mRenderLock.lockForWrite();
			while (!this->ref_mpOperator->mEventLoadedQueue.empty())
			{
				EventVector::iterator itr = this->ref_mpOperator->mEventLoadedQueue.begin();
				if (CSceneRenderEvent* pRenerEvent = dynamic_cast<CSceneRenderEvent*>(*itr))
				{
					pRenerEvent->getGeoScene()->draw();
				}
				else if (CLayerRenderEvent* pRenerEvent = dynamic_cast<CLayerRenderEvent*>(*itr))
				{
					pRenerEvent->getLayer()->draw();
				}
				delete *itr;
				this->ref_mpOperator->mEventLoadedQueue.erase(itr);
			}
			this->ref_mpOperator->mRenderLock.unlock();
		}

	}
	return true;
}

void CRenderThread::setOperator(VRAsynchronousHandler* ref_pOperator)
{
	this->ref_mpOperator = ref_pOperator;
}

