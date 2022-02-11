#include "vrmine/vr_plugins/vrdatasourcetreewidget.h"
#include <QTreeWidgetItem>
#include "vrmine/vr_spatialinterface/event/eventobject.h"
#include "vrmine/vr_databaseengine/database/logicfeature.h"
#include "vrmine/vr_databaseengine/database/logicdataset.h"
#include "qmenu.h"
#include "qevent.h"
#include <QFile>
#include "vrmine/vr_generalui/localdatasourceDlg.h"
#include "vrmine/vr_generalui/severconfigDlg.h"
#include "vrmine/vr_projectmanager/project/projectmanager.h"
#include "vrmine/vr_databaseengine/database/databaseinfo.h"
#include "vrmine/vr_core/geodatatype.h"
#include <QMessageBox>

using namespace VirtualMine::Database;

class VRDataSourceTreeWidget_PrivateData
{
public:
	VRDataSourceTreeWidget_PrivateData()
		:mpRootItem(NULL),mpLocalDataSourceItem(NULL),
		ref_mpSelectedItem(NULL),mpLocalDataSourceMenu(NULL),
		mpDataSourceLoadHandler(NULL),mpRemoteDataSourceItem(NULL),
		mpCurLocalDataSourceItem(NULL),mpRemoteDataSourceMenu(NULL),
		ref_mpDataSourceManager(NULL)
	{

	}

	virtual ~VRDataSourceTreeWidget_PrivateData()
	{
		if (this->mpDataSourceLoadHandler)
		{
			delete this->mpDataSourceLoadHandler;
			this->mpDataSourceLoadHandler = NULL;
		}
	}

public:
	QTreeWidgetItem* mpRootItem;
	VRDataSourceManagerItem* mpLocalDataSourceItem;
	VRDataSourceItem* mpCurLocalDataSourceItem;
	VRDataSourceManagerItem* mpRemoteDataSourceItem;
	VirtualMine::Database::IDataSourceManager* ref_mpDataSourceManager;
	CDataSourceLoadHandler* mpDataSourceLoadHandler;

	//界面交互
	QTreeWidgetItem * ref_mpSelectedItem;
	QMenu* mpLocalDataSourceMenu;
	QMenu* mpRemoteDataSourceMenu;
};


VRDataSetItem::VRDataSetItem()
{

}
VRDataSetItem::~VRDataSetItem()
{

}

void VRDataSetItem::setBindingObject(VirtualMine::Database::CLogicFeature* ref_pBindingObject)
{
	this->ref_mpBindingObject = ref_pBindingObject;
}
VirtualMine::Database::CLogicFeature* VRDataSetItem::getBindingObject()
{
	return this->ref_mpBindingObject;
}

VRDataSourceTreeWidget::VRDataSourceTreeWidget(QWidget *parent)
	:QTreeWidget(parent)
{
	this->mpPrivate = new VRDataSourceTreeWidget_PrivateData();
	this->mpPrivate->mpDataSourceLoadHandler = new CDataSourceLoadHandler(this);
	this->initialControl();
}

VRDataSourceTreeWidget::~VRDataSourceTreeWidget()
{

}

void VRDataSourceTreeWidget::initialControl()
{
	this->setHeaderHidden(true);
	this->mpPrivate->mpRootItem = new QTreeWidgetItem();
	this->mpPrivate->mpRootItem->setText(0,QString(tr("数据源管理")).arg(1));
	this->mpPrivate->mpRootItem->setIcon(0,QIcon(this->getIcon(this->mpPrivate->mpRootItem).c_str()));
	this->addTopLevelItem(this->mpPrivate->mpRootItem);

	this->mpPrivate->mpLocalDataSourceItem = new VRDataSourceManagerItem();
	this->mpPrivate->mpLocalDataSourceItem->setText(0,QString("本地数据源"));
	this->mpPrivate->mpLocalDataSourceItem->setType(VirtualMine::Core::GeoDatabaseType::GDBT_SQLITE);
	this->mpPrivate->mpLocalDataSourceItem->setIcon(0,QIcon(this->getIcon(this->mpPrivate->mpLocalDataSourceItem).c_str()));
	this->mpPrivate->mpRootItem->addChild(this->mpPrivate->mpLocalDataSourceItem);

	this->mpPrivate->mpRemoteDataSourceItem = new VRDataSourceManagerItem();
	this->mpPrivate->mpRemoteDataSourceItem->setText(0,QString("远程服务器"));
	this->mpPrivate->mpRemoteDataSourceItem->setType(VirtualMine::Core::GeoDatabaseType::GDBT_REMOTE);
	this->mpPrivate->mpRemoteDataSourceItem->setIcon(0,QIcon(this->getIcon(this->mpPrivate->mpRemoteDataSourceItem).c_str()));
	this->mpPrivate->mpRootItem->addChild(this->mpPrivate->mpRemoteDataSourceItem);
	this->expandAll();

	//////////////////////////////////////////////////////////////////////////
	//创建本地数据源快捷菜单
	this->mpPrivate->mpLocalDataSourceMenu = new QMenu(this);
	QAction * pOpenLocalDataSourceAction = new QAction(tr("打开本地数据源"),this);
	connect(pOpenLocalDataSourceAction, SIGNAL(triggered()), this, SLOT(slotOpenLocalDataSource())); 
	this->mpPrivate->mpLocalDataSourceMenu->addAction(pOpenLocalDataSourceAction);

	this->mpPrivate->mpRemoteDataSourceMenu = new QMenu(this);
	QAction * pConnectRemoteServerAction = new QAction(tr("连接远程服务器"),this);
	connect(pConnectRemoteServerAction, SIGNAL(triggered()), this, SLOT(slotConnectRemoteServer())); 
	this->mpPrivate->mpRemoteDataSourceMenu->addAction(pConnectRemoteServerAction);
}

void VRDataSourceTreeWidget::contextMenuEvent(QContextMenuEvent * event )
{
	QPoint point = QCursor::pos();
	point = mapFromGlobal(point);
	QTreeWidgetItem *item = this->itemAt(point);
	this->mpPrivate->ref_mpSelectedItem = item;
	if (item != NULL)
	{
		VRDataSourceManagerItem* pMgrItem = dynamic_cast<VRDataSourceManagerItem*>(item);
		if (pMgrItem)
		{
			std::string localType = this->mpPrivate->ref_mpDataSourceManager == NULL ? VirtualMine::Core::GeoDatabaseType::GDBT_SQLITE : this->mpPrivate->ref_mpDataSourceManager->getType();
			if (pMgrItem->getType() == localType)
			{
				this->mpPrivate->mpLocalDataSourceMenu->exec(QCursor::pos());
			}
			else if (pMgrItem->getType() == VirtualMine::Core::GeoDatabaseType::GDBT_REMOTE)
			{
				this->mpPrivate->mpRemoteDataSourceMenu->exec(QCursor::pos());
			}
			event->accept();
		}
	}
}

void VRDataSourceTreeWidget::mousePressEvent(QMouseEvent *event)
{
	QTreeWidget::mousePressEvent(event);
}

void VRDataSourceTreeWidget::slotConnectRemoteServer()
{
	VirtualMine::GeneralUI::CSeverConfigDlg serverConfigDlg(this);
	serverConfigDlg.initialize();
	int ret = serverConfigDlg.exec();
	if (ret == QDialog::Accepted)
	{
	}
}

void VRDataSourceTreeWidget::slotOpenLocalDataSource()
{
	if (this->mpPrivate->ref_mpDataSourceManager)
	{
		QMessageBox::warning(this,tr("警告"),QString("只能配置一个本地数据源！"));
		return;
	}
	if (this->mpPrivate)
	{
		VirtualMine::GeneralUI::CDataSourceConfigDlg dataSourceConfigDlg(this);
		int ret = dataSourceConfigDlg.exec();
		if (ret == QDialog::Accepted
			&& QFile::exists(dataSourceConfigDlg.getDBPath().c_str()))
		{
			VirtualMine::Database::IDataSourceInfo* datasourceInfo = new VirtualMine::Database::CDatabaseInfo();
			datasourceInfo->setUri(dataSourceConfigDlg.getDBPath()); 
			datasourceInfo->setDataSourceType(VirtualMine::Core::GeoDatabaseType::GDBT_SQLITE);
			VirtualMine::Project::CProjectManager::getSingletonPtr()->openDataSource(datasourceInfo);
		}
	}
}

std::string VRDataSourceTreeWidget::getIcon(QTreeWidgetItem* item)
{
	std::string iconName("data\\datasourceicon\\default.png");
	assert(item);
	if (item == NULL)
	{
		return iconName;
	}
	if (dynamic_cast<VRDataSourceManagerItem*>(item))
	{
		iconName = "data\\datasourceicon\\datasourcemgr.png";
	}
	else if (dynamic_cast<VRDataSourceItem*>(item))
	{
		iconName = "data\\datasourceicon\\datasource.png";
	}
	else if (dynamic_cast<VRDataSetItem*>(item))
	{
		iconName = "data\\datasourceicon\\dataset.png";
	}
	return iconName;
}

void VRDataSourceTreeWidget::loadLogicalFeature(VirtualMine::Database::CLogicFeature* pLogicFeature)
{
	std::string datasetName("");
	std::string type("");
	CPropertySet* pProperty = pLogicFeature->getPropertySet();
	std::vector<VirtualMine::Database::CField> fileds = pProperty->getFields();
	fileds.at(1).getVarient().getValue(datasetName);
	fileds.at(2).getVarient().getValue(type);
	//////////////////////////////////////////////////////////////////////////
	VRDataSetItem* pDataSetItem = new VRDataSetItem();
	pDataSetItem->setText(0,QString(datasetName.c_str()));
	pDataSetItem->setBindingObject(pLogicFeature);
	//pDataSetItem->setCheckState(0,Qt::Checked);
	pDataSetItem->setIcon(0,QIcon(this->getIcon(pDataSetItem).c_str()));
	this->mpPrivate->mpCurLocalDataSourceItem->addChild(pDataSetItem);
	//////////////////////////////////////////////////////////////////////////

}

void VRDataSourceTreeWidget::loadDataSource(VirtualMine::Database::IDataSource* pDataSource)
{
	if (pDataSource && this->mpPrivate->mpLocalDataSourceItem)
	{
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
				this->loadLogicalFeature(pLogicalFeature);
				++logicalBItr;
			}
		}
	}
}

void VRDataSourceTreeWidget::loadDataSource(VirtualMine::Database::IDataSourceManager* pDataSourceMgr)
{
	if (pDataSourceMgr)
	{
		this->mpPrivate->ref_mpDataSourceManager = pDataSourceMgr;
		if (this->mpPrivate->ref_mpDataSourceManager)
		{
			IDataSource* pDataSource = this->mpPrivate->ref_mpDataSourceManager->getDataSource();
			if (pDataSource)
			{
				this->mpPrivate->mpCurLocalDataSourceItem = new VRDataSourceItem();
				this->mpPrivate->mpCurLocalDataSourceItem->bindingObject(pDataSource);
				this->mpPrivate->mpCurLocalDataSourceItem->setText(0,QString("资江煤矿数据源"));
				//this->mpPrivate->mpCurLocalDataSourceItem->setCheckState(0,Qt::Checked);

				
				QString dataName = pDataSource->getName().c_str();////getName()不知道为什么是空的？
				//pDataSource->getDataset()

		      //  CSQLiteDatabase*  db =	(CSQLiteDatabase*)pDataSource;
				
				std::string uri = pDataSource->getDataSourceInfo()->getUri().c_str();
				int lastnode = uri.find_last_of("/");
				std::string name = uri.substr(lastnode+1);
				int lastnode2 = name.find_last_of(".");
				std::string namewithoutposfix = name.substr(0,lastnode2);
				
				QString databaseName = namewithoutposfix.c_str();

				if (databaseName == "" || databaseName.size() == 0 )
				{
					databaseName = "煤矿数据源";
					this->mpPrivate->mpCurLocalDataSourceItem->setText(0,QString("煤矿数据源"));
				}
				else
				{
					databaseName = databaseName + "数据源";
					this->mpPrivate->mpCurLocalDataSourceItem->setText(0,databaseName);
				}


				this->mpPrivate->mpCurLocalDataSourceItem->setIcon(0,QIcon(this->getIcon(this->mpPrivate->mpCurLocalDataSourceItem).c_str()));
				this->mpPrivate->mpLocalDataSourceItem->setType(pDataSourceMgr->getType());
				this->mpPrivate->mpLocalDataSourceItem->addChild(this->mpPrivate->mpCurLocalDataSourceItem);
				this->loadDataSource(pDataSource);
				this->expandAll();
			}
		}
	}
}

void VRDataSourceTreeWidget::unloadDataSource()
{
	if (this->mpPrivate->mpLocalDataSourceItem)
	{
		this->unLoadItem(this->mpPrivate->mpLocalDataSourceItem);
	}
}

void VRDataSourceTreeWidget::unLoadItem(QTreeWidgetItem* item)
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
	//delete item;
	item = NULL;
}


VRDataSourceItem::VRDataSourceItem()
	:ref_mpDataSource(NULL)
{

}
VRDataSourceItem::~VRDataSourceItem()
{

}
void VRDataSourceItem::bindingObject(VirtualMine::Database::IDataSource* ref_pDataSource)
{
	this->ref_mpDataSource = ref_pDataSource;
}

VirtualMine::Database::IDataSource* VRDataSourceItem::getBindingObject()
{
	return this->ref_mpDataSource;
}

CDataSourceLoadHandler::CDataSourceLoadHandler()
	:ref_mpControl(NULL)
{

}
CDataSourceLoadHandler::CDataSourceLoadHandler(VRDataSourceTreeWidget* pControl)
	:ref_mpControl(pControl)
{

}
CDataSourceLoadHandler::~CDataSourceLoadHandler()
{

}
bool CDataSourceLoadHandler::handleEvent(VirtualMine::Core::CEvent* evt)
{
	VirtualMine::SpatialInterface::CDataSourceLoadEvent* pEvent = dynamic_cast<VirtualMine::SpatialInterface::CDataSourceLoadEvent*>(evt);
	if (pEvent && this->ref_mpControl)
	{
		this->ref_mpControl->loadDataSource(pEvent->getDataSourceManager());
	}

	VirtualMine::SpatialInterface::CSceneUnLoadEvent* sceneUnloadEvent = dynamic_cast<VirtualMine::SpatialInterface::CSceneUnLoadEvent*>(evt);
	if (sceneUnloadEvent && this->ref_mpControl)
	{
		this->ref_mpControl->unloadDataSource();
	}

	return evt->isAccepted();
}
