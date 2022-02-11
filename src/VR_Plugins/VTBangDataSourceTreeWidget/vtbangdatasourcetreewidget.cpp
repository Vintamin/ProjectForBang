#include "vrmine/vr_plugins/vtbangdatasourcetreewidget.h"
#include <QTextCodec>
#include "vrmine/vr_sqlitedatabase/sqlitedatabase/sqlitedatabasemanager.h"
#include "vrmine/vr_databaseengine/database/idataset.h"
#include "vrmine/vr_databaseengine/database/idatasource.h"
#include "vrmine/vr_sqlitedatabase/sqlitedatabase/sqlitedatabase.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_spatiallayer/layerfactory.h"
#include "vrmine/vr_spatialinterface/ilayer.h"
#include "vrmine/vr_spatiallayer/terranelayer.h"
#include "vrmine/vr_spatiallayer/shotholelayer.h"
#include "vrmine/vr_plugins/treeitem/layeritem.h"
#include "vrmine/vr_core/event.h"
#include "vrmine/vr_maplayer/idrawobject.h"
#include "vrmine/vr_spatialobject/mine/terraneobject.h"
#include "vrmine/vr_spatialrender/spatialrender/terranerenderobject.h"
#include "vrmine/vr_spatialrender/lanewaypiperender/pipeline.h"
#include "vrmine/vr_spatialobject/base/geoline.h"
#include "vrmine/vr_style/style/pipestyle.h"
#include "vrmine/vr_maplayer/shotholelayer.h"
#include "vrmine/vr_maplayer/rocklayer2D.h"
#include "vrmine/vr_style/style/terranestyle.h"
#include "vrmine/vr_spatialinterface/event/eventobject.h"
#include "vrmine/vr_spatiallayer/lanwaylayer.h"
#include "vrmine/vr_spatialrender/spatialrender/lanewayrenderableobject.h"
//kk
#include "vrmine/vr_spatialrender/spatialrender/lanewayrenderableprogress.h"
#include "vrmine/vr_spatialobject/mine/lanwayobject.h"
//kk
#include "vrmine/vr_spatialobject/mine/lanwayobjectpro.h"
#include "vrmine/vr_spatiallayer/escaperoutelayer.h"
//kk
#include "vrmine/vr_spatiallayer/conprogresslayer.h"
#include <QTreeWidgetItem>
#include "qmenu.h"
#include "qevent.h"
#include <QFile>
#include <QMessageBox>

#include <vector>
#include <set>
#include "bang/shotholedataset.h"
#include "bang/shotholefeature.h"

using namespace VirtualMine::Core;
using namespace VirtualMine::SQLiteDatabase;
using namespace VirtualMine::Database;
using namespace VirtualMine::SpatialLayer;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Map;
using namespace VirtualMine::Bang_Database;
using namespace VirtualMine::SpatialRender;
using namespace VirtualMine::Mine;
using namespace VirtualMine::Style;


class CBangLayerLoadHandler;
//class VRBANGDATASOURCETREE_WIDGET_DLL VRBangLayerItem : public QTreeWidgetItem
//{
//public :
//	VRBangLayerItem()
//	{
//		this->ref_mp2DBindingObject = NULL;
//		this->ref_mp3DBindingObject = NULL;
//		mType = 1;
//	}
//	~VRBangLayerItem()
//	{
//
//	}
//	int getIntType()
//	{
//		return mType;
//	}
//	void setIntType(const int& ref_type)
//	{
//		mType = ref_type;
//	}
//	virtual void setBindingObject(
//		VirtualMine::SpatialInterface::ILayer* ref_p2DBindingObject,
//		VirtualMine::SpatialInterface::ILayer* ref_p3DBindingObject)
//	{
//		this->ref_mp2DBindingObject = ref_p2DBindingObject;
//		this->ref_mp3DBindingObject = ref_p3DBindingObject;
//	}
//	virtual VirtualMine::SpatialInterface::ILayer* get2DBindingObject()
//	{
//		return this->ref_mp2DBindingObject;
//	}
//	virtual VirtualMine::SpatialInterface::ILayer* get3DBindingObject()
//	{
//		return this->ref_mp3DBindingObject;	
//	}
//protected :
//	int mType; 
//	VirtualMine::SpatialInterface::ILayer* ref_mp2DBindingObject;
//	VirtualMine::SpatialInterface::ILayer* ref_mp3DBindingObject;
//};

//kk  VRBangLayerItem
VRBangLayerItem::VRBangLayerItem()
{
	this->ref_mp2DBindingObject = NULL;
	this->ref_mp3DBindingObject = NULL;
	mType = 1;
}


VRBangLayerItem::~VRBangLayerItem()
{

}


int VRBangLayerItem::getIntType()
{
	return this->mType;
}
void VRBangLayerItem::setIntType(const int& ref_type)
{
	this->mType = ref_type;
}

void VRBangLayerItem::setBindingObject(
	VirtualMine::SpatialInterface::ILayer* ref_p2DBindingObject,
	VirtualMine::SpatialInterface::ILayer* ref_p3DBindingObject)
{
	this->ref_mp2DBindingObject = ref_p2DBindingObject;
	this->ref_mp3DBindingObject = ref_p3DBindingObject;
}


VirtualMine::SpatialInterface::ILayer* VRBangLayerItem::get2DBindingObject()
{
	return this->ref_mp2DBindingObject;
}



VirtualMine::SpatialInterface::ILayer* VRBangLayerItem::get3DBindingObject()
{
	return this->ref_mp3DBindingObject;	
}
//kk定义VRBangLayerItem结束


//class VRBangFeatureItem : public QTreeWidgetItem
//{
//public :
//	VRBangFeatureItem()
//	{
//		this->ref_mpFeature = NULL;
//		this->ref_mp3DBindingObject = NULL;
//	}
//	~VRBangFeatureItem()
//	{
//
//	}
//	virtual void setBindingObject(
//		VirtualMine::Database::IFeature* ref_pFeature,
//		VirtualMine::SpatialInterface::ILayer* ref_p3DBindingObject)
//	{
//		this->ref_mpFeature = ref_pFeature;
//		this->ref_mp3DBindingObject = ref_p3DBindingObject;
//	}
//	virtual VirtualMine::Database::IFeature* getFeature()
//	{
//		return this->ref_mpFeature;
//	}
//	virtual VirtualMine::SpatialInterface::ILayer* get3DBindingObject()
//	{
//		return this->ref_mp3DBindingObject;	
//	}
//protected :
//	VirtualMine::Database::IFeature* ref_mpFeature;
//	VirtualMine::SpatialInterface::ILayer* ref_mp3DBindingObject;
//};

//kk VRBangFeatureItem

VRBangFeatureItem::VRBangFeatureItem()
{
	this->ref_mpFeature = NULL;
	this->ref_mp3DBindingObject = NULL;
}

VRBangFeatureItem::~VRBangFeatureItem()
{

}

void VRBangFeatureItem::setBindingObject(
	VirtualMine::Database::IFeature* ref_pFeature,
	VirtualMine::SpatialInterface::ILayer* ref_p3DBindingObject)
{
	this->ref_mpFeature = ref_pFeature;
	this->ref_mp3DBindingObject = ref_p3DBindingObject;
}

VirtualMine::Database::IFeature* VRBangFeatureItem::getFeature()
{
	return this->ref_mpFeature;
}

VirtualMine::SpatialInterface::ILayer* VRBangFeatureItem::get3DBindingObject()
{
	return this->ref_mp3DBindingObject;	
}




class VTBangDataSourceTreeWidget_PrivateData
{
public:
	VTBangDataSourceTreeWidget_PrivateData()
	{
		ref_mpDataSource = NULL;
	}
	~VTBangDataSourceTreeWidget_PrivateData()
	{
		if (this->mpBangLayerLoadHandler)
		{
			delete this->mpBangLayerLoadHandler;
			this->mpBangLayerLoadHandler = NULL;
		}
	}

public:
	VRSceneItem* mpProjectItem;
	VRBangLayerItem* mpRockItem;
	VRBangLayerItem* mpSectionItem;
	VRBangLayerItem* mpShotHoleItem;
	VRBangLayerItem* mpFireOrderItem;
	VRBangLayerItem* mpEvacuationRouteItem;
	VRBangLayerItem* mpConstructionOrgItem;
	VRBangLayerItem* mpConstructionProgressItem;
	VRBangLayerItem* mpBlastingModelItem;

	//界面交互
	QTreeWidgetItem * ref_mpSelectedItem;
	QMenu* mpAddMenu;
	QMenu* mpModifyMenu;
	QMenu* mpDeleteMenu;
	QMenu* mpCopeMenu;
	QMenu* mpCutMenu;
	QMenu* mpPasteMenu;

	//关于数据库
	CSQLiteDatabase* ref_mpDataSource;
	CBangLayerLoadHandler* mpBangLayerLoadHandler;
};

class CBangLayerLoadHandler : public VirtualMine::Core::CEventHandler
{
public:
	CBangLayerLoadHandler(VTBangDataSourceTreeWidget* ref_pOperator)
	{
		this->ref_mpOperator = ref_pOperator;
	}
	~CBangLayerLoadHandler()
	{

	}
	virtual bool handleEvent(VirtualMine::Core::CEvent* evt)
	{
		if (this->ref_mpOperator)
		{
			return this->ref_mpOperator->handleLayerLoadEvent(evt);
		}
		return false;
	}
protected:
	VTBangDataSourceTreeWidget* ref_mpOperator;

};



VTBangDataSourceTreeWidget::VTBangDataSourceTreeWidget(QWidget *parent)
	: QTreeWidget(parent)
{
	this->mpPrivate = new VTBangDataSourceTreeWidget_PrivateData();
	this->mpPrivate->mpBangLayerLoadHandler = new CBangLayerLoadHandler(this);
	this->initialControl();
	this->mIsSelectedCheck = false;
    oldtypename = "noname";
	oldBoomID = 0;
	oldOrverID2D="lianxian0";
	curColor=Ogre::ColourValue::Red;
	oldColor=Ogre::ColourValue::Black;
	oldorderColor=Ogre::ColourValue::Black;
	connect(this, SIGNAL(itemPressed(QTreeWidgetItem*,int)), this,SLOT(slotItemPress()));
	
}

VTBangDataSourceTreeWidget::~VTBangDataSourceTreeWidget()
{

}
//kk
void VTBangDataSourceTreeWidget::getTableWidget(QTableWidget* tablewidget)
{
	this->mytablewidget = tablewidget;
}
//kk
void VTBangDataSourceTreeWidget::setTableItem(QTableWidget* tablewidget,std::vector<std::string> InfoVec)
{
	tablewidget->verticalHeader()->setVisible(false);
	tablewidget->horizontalHeader()->setVisible(false);
	tablewidget->horizontalHeader()->setStretchLastSection(true);


	tablewidget->clear();
	int datasize = InfoVec.size();
	tablewidget->setRowCount(datasize/2);
	tablewidget->setColumnCount(2);

	for (int i = 0;i<datasize/2;i++)
	{
		for (int j = 0;j<2;j++)
		{
			QTableWidgetItem * item = new QTableWidgetItem(InfoVec[i*2+j].c_str());
			if ( j == 0)
			{
				//item->setFlags(item->flags() & (~Qt::ItemIsEditable));//kk设置第一列不可编辑
				item->setBackground(QBrush(QColor(Qt::lightGray)));
				item->setFlags(item->flags() & (~Qt::ItemIsEditable));
			}
			tablewidget->setItem(i,j,item) ;

		}
	}
	tablewidget->show();

}


bool VTBangDataSourceTreeWidget::handleLayerLoadEvent(VirtualMine::Core::CEvent* evt)
{
	std::cout<<"哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈"<<endl;
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	CBangLayerLoadEvent* pLayerLoadEvt = dynamic_cast<CBangLayerLoadEvent*>(evt);
	if (pLayerLoadEvt
		&& pLayerLoadEvt->get2DLayer()
		&& pLayerLoadEvt->get3DLayer())
	{
		std::cout<<"进入到handleLayerLoadEvent啦啦啦啦啦啦"<<endl;
	    std::string LayerType = pLayerLoadEvt->get3DLayer()->getType();
		//cout<<"我的handleLayerLoadEvent类型是！！！！！！！！！"<<LayerType<<endl;
		VRBangLayerItem* pLayerItem = (VRBangLayerItem*)this->getItem(pLayerLoadEvt->get3DLayer()->getType());
		pLayerItem->setCheckState(0,Qt::Checked);
		QString iconPath = this->getItemIcon(pLayerLoadEvt->get3DLayer()->getType());
		if (pLayerItem)
		{
			pLayerItem->setIcon(0,QIcon(iconPath));
			pLayerItem->setBindingObject(pLayerLoadEvt->get2DLayer(),pLayerLoadEvt->get3DLayer());
			QString proIconPath = this->getItemIcon(VirtualMine::Core::GeoDataType::GDT_IMAGE);
			this->mpPrivate->mpProjectItem->setIcon(0,QIcon(proIconPath));
			if (LayerType == VirtualMine::Core::GeoDataType::GDT_SHOTHOLE)
			{
				this->mpPrivate->mpFireOrderItem->setIcon(0,QIcon(iconPath));
				this->mpPrivate->mpFireOrderItem->setBindingObject(pLayerLoadEvt->get2DLayer(),pLayerLoadEvt->get3DLayer());
				this->mpPrivate->mpFireOrderItem->setCheckState(0,Qt::Checked);
                  

#if 1 炮眼
				std::set<std::string> typeSet;
				int count = pLayerLoadEvt->get3DLayer()->getDataSet()->getCount();
				////得到有几种类型的炮眼
				for (int i = 0; i < count; i++)
				{
					IFeature* pfeature = pLayerLoadEvt->get3DLayer()->getDataSet()->getFeature(i);
					CShotHoleFeature* pShotholefeature = dynamic_cast<CShotHoleFeature*>(pfeature);
					std::string shotholetype = pShotholefeature->getFieldType();  
					typeSet.insert(shotholetype);
				}
				/////将不同类型的炮眼按类别存在shotHoleDatasetVec里面
				std::vector<CShotHoleDataset*> shotHoleDatasetVec; 
				std::set<std::string>::iterator itr;
				for (itr = typeSet.begin(); itr != typeSet.end(); itr++)
				{ 
					CShotHoleDataset* pShotHoleDataset = new CShotHoleDataset();

					for (int m = 0; m < count; m++ )
					{
						IFeature* pfeature = pLayerLoadEvt->get3DLayer()->getDataSet()->getFeature(m);
						CShotHoleFeature* pShotholefeature = dynamic_cast<CShotHoleFeature*>(pfeature);
						std::string shotholetype = pShotholefeature->getFieldType();  
						if (*itr == shotholetype)
						{
							pShotHoleDataset->setName(shotholetype);
							pShotHoleDataset->addFeature(pShotholefeature);
						}
					}
					shotHoleDatasetVec.push_back(pShotHoleDataset);
				}


				int DatasetCount = shotHoleDatasetVec.size();
				for (int s = 0; s < DatasetCount;s++ )
				{
					std::string itemName = shotHoleDatasetVec.at(s)->getName();
					IFeature* pFeature = shotHoleDatasetVec.at(s)->getFeature(0);
					VRBangFeatureItem* pShotHoleTypeItem = new VRBangFeatureItem();
					//pShotHoleTypeItem->setBindingObject(pLayerLoadEvt->get2DLayer(),pLayerLoadEvt->get3DLayer());		
					pShotHoleTypeItem->setBindingObject(pFeature,pLayerLoadEvt->get3DLayer());
					pLayerItem->addChild(pShotHoleTypeItem);
					pShotHoleTypeItem->setText(0,QString(tr(itemName.c_str())).arg(1));
					pShotHoleTypeItem->setIcon(0,QIcon(iconPath));
					Qt::CheckState checkState = Qt::Checked; 
					pShotHoleTypeItem->setCheckState(0,checkState);
					//pShotHoleTypeItem->setBindingObject()
				}
#endif

#if 1
				////得到有几种起爆顺序的炮眼
				std::set<int> bangOrderSet;
				for (int i = 0; i < count; i++)
				{
					IFeature* pfeature = pLayerLoadEvt->get3DLayer()->getDataSet()->getFeature(i);
					CShotHoleFeature* pShotholefeature = dynamic_cast<CShotHoleFeature*>(pfeature);
					int bangOrder = pShotholefeature->getFieldBangOrder();  
					bangOrderSet.insert(bangOrder);
				}

				/////将不同起爆顺序的炮眼按类别存在shotHoleDatasetVec里面
				std::vector<CShotHoleDataset*> shotHoleBangOrderDatasetVec; 
				std::set<int>::iterator itr2;
				for (itr2 = bangOrderSet.begin(); itr2 != bangOrderSet.end(); itr2++)
				{ 
					CShotHoleDataset* pShotHoleDataset = new CShotHoleDataset();

					for (int m = 0; m < count; m++ )
					{
						IFeature* pfeature = pLayerLoadEvt->get3DLayer()->getDataSet()->getFeature(m);
						CShotHoleFeature* pShotholefeature = dynamic_cast<CShotHoleFeature*>(pfeature);
						int shotholebangorder = pShotholefeature->getFieldBangOrder();  
						std::string name = Ogre::StringConverter::toString(shotholebangorder);
						if (*itr2 == shotholebangorder)
						{
							pShotHoleDataset->setName(name);
							pShotHoleDataset->addFeature(pShotholefeature);
						}
					}
					shotHoleBangOrderDatasetVec.push_back(pShotHoleDataset);
				}

				int DatasetCount2 = shotHoleBangOrderDatasetVec.size();
				QString iconPath = this->getItemIcon(VirtualMine::Core::GeoDataType::GDT_FAULT);
				for (int s = 0; s < DatasetCount2;s++ )
				{
					std::string itemName = shotHoleBangOrderDatasetVec.at(s)->getName();
					IFeature* pFeature = shotHoleBangOrderDatasetVec.at(s)->getFeature(0);
					VRBangFeatureItem* pShotHoleTypeItem = new VRBangFeatureItem();				
					this->mpPrivate->mpFireOrderItem->addChild(pShotHoleTypeItem);
					pShotHoleTypeItem->setBindingObject(pFeature,pLayerLoadEvt->get3DLayer());
					pShotHoleTypeItem->setText(0,QString(tr(itemName.c_str())).arg(1));
					pShotHoleTypeItem->setIcon(0,QIcon(iconPath));
					Qt::CheckState checkState = Qt::Checked; 
					pShotHoleTypeItem->setCheckState(0,checkState);
					//pShotHoleTypeItem->setBindingObject()
				}


#endif

			}
			else if (LayerType == VirtualMine::Core::GeoDataType::GDT_ESCAPEROUTE)///
			{
				std::cout<<"我的事件是避难路线-------------"<<endl;
				pLayerItem->setCheckState(0,Qt::Unchecked);
			}
			//kk
			else if (LayerType == VirtualMine::Core::GeoDataType::GDT_CONORGANIZATION)///
			{
				std::cout<<"我的事件是施工组织-------------"<<endl;
				pLayerItem->setCheckState(0,Qt::Unchecked);
			}
			//kk
			else if (LayerType == VirtualMine::Core::GeoDataType::GDT_CONPROGRESS)///
			{
				std::cout<<"我的事件是施工进度-------------"<<endl;
				pLayerItem->setCheckState(0,Qt::Unchecked);
			}
			else if (LayerType == VirtualMine::Core::GeoDataType::GDT_TERRANE)///
			{
				pLayerItem->setCheckState(0,Qt::Unchecked);
				int count = pLayerLoadEvt->get3DLayer()->getDataSet()->getCount();

				for (int i = 0; i < count; i++)
				{
					IFeature* pfeature = pLayerLoadEvt->get3DLayer()->getDataSet()->getFeature(i);
					CTerraneFeature* pShotholefeature = dynamic_cast<CTerraneFeature*>(pfeature);
					std::string rockName = pShotholefeature->getFieldName(); 
					iconPath = this->getItemIcon(VirtualMine::Core::GeoDataType::GDT_TERRANE);
					//VRBangLayerItem* pShotHoleTypeItem = new VRBangLayerItem();
					VRBangFeatureItem* pShotHoleTypeItem = new VRBangFeatureItem();
					pShotHoleTypeItem->setBindingObject(pShotholefeature,pLayerLoadEvt->get3DLayer());
					pShotHoleTypeItem->setIcon(0,QIcon(iconPath));
					this->mpPrivate->mpRockItem->addChild(pShotHoleTypeItem);
					pShotHoleTypeItem->setText(0,QString(tr(rockName.c_str())).arg(1));
					Qt::CheckState checkState = Qt::Unchecked; /////不勾选
					pShotHoleTypeItem->setCheckState(0,checkState);
					//pShotHoleTypeItem->setBindingObject(NULL,)
				}
			}
			else if (LayerType == VirtualMine::Core::GeoDataType::GDT_FAULT)///?爆破结果模拟
			{
			
					//IFeature* pfeature = pLayerLoadEvt->get3DLayer()->getDataSet()->getFeature(i);
		
					VRBangLayerItem* pShotHoleTypeItem = new VRBangLayerItem();
					pLayerItem->addChild(pShotHoleTypeItem);
					pShotHoleTypeItem->setText(0,QString(tr("打眼过程模拟")));
					Qt::CheckState checkState = Qt::Checked; 
					pShotHoleTypeItem->setCheckState(0,checkState);
					//pShotHoleTypeItem->setBindingObject(NULL,)
			}

		}
		return true;
		}
	return false;
}

void VTBangDataSourceTreeWidget::initialControl()
{
	this->setHeaderHidden(true);
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
#if 1 创建数据节点
	//创建场景根节点
	this->mpPrivate->mpProjectItem = new VRSceneItem();
	
	this->mpPrivate->mpProjectItem->setText(0,QString(tr("工程管理")).arg(1));
	std::string iconName = "data\\Resources\\project\\default.png";
	this->mpPrivate->mpProjectItem->setIcon(0,QIcon(iconName.c_str()));
	this->addTopLevelItem(this->mpPrivate->mpProjectItem);

	this->mpPrivate->mpRockItem = new VRBangLayerItem();
	this->mpPrivate->mpRockItem->setIntType(1);
	Qt::CheckState checkState = Qt::Checked;

	this->mpPrivate->mpRockItem->setCheckState(0,checkState);
	this->mpPrivate->mpRockItem->setIcon(0,QIcon(iconName.c_str()));
	this->mpPrivate->mpRockItem->setText(0,QString(tr("岩层参数")).arg(1));
	this->mpPrivate->mpRockItem->setCheckState(0,Qt::Unchecked);
	this->mpPrivate->mpProjectItem->addChild(this->mpPrivate->mpRockItem);

	this->mpPrivate->mpSectionItem = new VRBangLayerItem();
	this->mpPrivate->mpSectionItem->setIntType(2);
	this->mpPrivate->mpSectionItem->setCheckState(0,checkState);
	this->mpPrivate->mpSectionItem->setIcon(0,QIcon(iconName.c_str()));
	this->mpPrivate->mpSectionItem->setText(0,QString(tr("断面参数")).arg(1));
	this->mpPrivate->mpSectionItem->setCheckState(0,Qt::Unchecked);
	this->mpPrivate->mpProjectItem->addChild(this->mpPrivate->mpSectionItem);

	//
	this->mpPrivate->mpShotHoleItem = new VRBangLayerItem();
	this->mpPrivate->mpShotHoleItem->setIntType(3);
	this->mpPrivate->mpShotHoleItem->setCheckState(0,checkState);
	this->mpPrivate->mpShotHoleItem->setIcon(0,QIcon(iconName.c_str()));
	this->mpPrivate->mpShotHoleItem->setText(0,QString(tr("炮眼设计")).arg(1));
	this->mpPrivate->mpShotHoleItem->setCheckState(0,Qt::Unchecked);
	this->mpPrivate->mpProjectItem->addChild(this->mpPrivate->mpShotHoleItem);

	this->mpPrivate->mpFireOrderItem = new VRBangLayerItem(); 
	this->mpPrivate->mpFireOrderItem->setIntType(4);
	this->mpPrivate->mpFireOrderItem->setCheckState(0,checkState);
	this->mpPrivate->mpFireOrderItem->setIcon(0,QIcon(iconName.c_str()));
	this->mpPrivate->mpFireOrderItem->setText(0,QString(tr("起爆顺序")).arg(1));
	this->mpPrivate->mpFireOrderItem->setCheckState(0,Qt::Unchecked);
	this->mpPrivate->mpProjectItem->addChild(this->mpPrivate->mpFireOrderItem);
	
	this->mpPrivate->mpEvacuationRouteItem = new VRBangLayerItem(); 
	this->mpPrivate->mpEvacuationRouteItem->setIntType(5);
	this->mpPrivate->mpEvacuationRouteItem->setCheckState(0,checkState);
	this->mpPrivate->mpEvacuationRouteItem->setIcon(0,QIcon(iconName.c_str()));
	this->mpPrivate->mpEvacuationRouteItem->setText(0,QString(tr("避难路线")).arg(1));
	this->mpPrivate->mpEvacuationRouteItem->setCheckState(0,Qt::Unchecked);
	this->mpPrivate->mpProjectItem->addChild(this->mpPrivate->mpEvacuationRouteItem);

	this->mpPrivate->mpConstructionOrgItem = new VRBangLayerItem(); 
    this->mpPrivate->mpConstructionOrgItem->setIntType(6);
	this->mpPrivate->mpConstructionOrgItem->setCheckState(0,checkState);
	this->mpPrivate->mpConstructionOrgItem->setIcon(0,QIcon(iconName.c_str()));
	this->mpPrivate->mpConstructionOrgItem->setText(0,QString(tr("施工组织图")).arg(1));
	this->mpPrivate->mpConstructionOrgItem->setCheckState(0,Qt::Unchecked);
	this->mpPrivate->mpProjectItem->addChild(this->mpPrivate->mpConstructionOrgItem);

	this->mpPrivate->mpConstructionProgressItem = new VRBangLayerItem();
	this->mpPrivate->mpConstructionProgressItem->setIntType(7);
	this->mpPrivate->mpConstructionProgressItem->setCheckState(0,checkState);
	this->mpPrivate->mpConstructionProgressItem->setIcon(0,QIcon(iconName.c_str()));
	this->mpPrivate->mpConstructionProgressItem->setText(0,QString(tr("施工进度图")).arg(1));
	this->mpPrivate->mpConstructionProgressItem->setCheckState(0,Qt::Unchecked);
	this->mpPrivate->mpProjectItem->addChild(this->mpPrivate->mpConstructionProgressItem);

	this->mpPrivate->mpBlastingModelItem = new VRBangLayerItem();
	this->mpPrivate->mpBlastingModelItem->setIntType(8);
	this->mpPrivate->mpBlastingModelItem->setCheckState(0,checkState);
	this->mpPrivate->mpBlastingModelItem->setIcon(0,QIcon(iconName.c_str()));
	this->mpPrivate->mpBlastingModelItem->setText(0,QString(tr("爆破模拟")).arg(1));
	this->mpPrivate->mpBlastingModelItem->setCheckState(0,Qt::Unchecked);
	this->mpPrivate->mpProjectItem->addChild(this->mpPrivate->mpBlastingModelItem);
	
	//this->expandAll();
	//this->expand(QModelIndex(0));
	this->expandItem(this->mpPrivate->mpProjectItem);

#endif

	//////////////////////////////////////////////////////////////////////////	
	
	this->mpPrivate->mpAddMenu = new QMenu(this);
	QAction * pAddAction = new QAction(tr("新增"),this);
	connect(pAddAction, SIGNAL(triggered()), this, SLOT(slotAdd())); 
	QAction * pModifyAction = new QAction(tr("修改"),this);
	connect(pModifyAction, SIGNAL(triggered()), this, SLOT(slotModify())); 
	QAction * pDeleteAction = new QAction(tr("删除"),this);
	connect(pDeleteAction, SIGNAL(triggered()), this, SLOT(slotDelete())); 
	QAction * pCopeAction = new QAction(tr("复制"),this);
	connect(pCopeAction, SIGNAL(triggered()), this, SLOT(slotCope())); 
	QAction * pCutAction = new QAction(tr("剪切"),this);
	connect(pCutAction, SIGNAL(triggered()), this, SLOT(slotCut())); 
	QAction * pPasteAction = new QAction(tr("粘贴"),this);
	connect(pPasteAction, SIGNAL(triggered()), this, SLOT(slotPaste())); 
	this->mpPrivate->mpAddMenu->addAction(pAddAction);
	this->mpPrivate->mpAddMenu->addAction(pDeleteAction);
	this->mpPrivate->mpAddMenu->addAction(pModifyAction);
	this->mpPrivate->mpAddMenu->addAction(pCopeAction);
	this->mpPrivate->mpAddMenu->addAction(pCutAction);
	this->mpPrivate->mpAddMenu->addAction(pPasteAction);


	this->mpPrivate->mpModifyMenu = new QMenu(this);

	this->mpPrivate->mpModifyMenu->addAction(pAddAction);
	this->mpPrivate->mpModifyMenu->addAction(pDeleteAction);
	this->mpPrivate->mpModifyMenu->addAction(pModifyAction);
	this->mpPrivate->mpModifyMenu->addAction(pCopeAction);
	this->mpPrivate->mpModifyMenu->addAction(pCutAction);
	this->mpPrivate->mpModifyMenu->addAction(pPasteAction);



	this->mpPrivate->mpDeleteMenu = new QMenu(this);

	this->mpPrivate->mpDeleteMenu->addAction(pAddAction);
	this->mpPrivate->mpDeleteMenu->addAction(pDeleteAction);
	this->mpPrivate->mpDeleteMenu->addAction(pModifyAction);
	this->mpPrivate->mpDeleteMenu->addAction(pCopeAction);
	this->mpPrivate->mpDeleteMenu->addAction(pCutAction);
	this->mpPrivate->mpDeleteMenu->addAction(pPasteAction);


	this->mpPrivate->mpCopeMenu = new QMenu(this);
	this->mpPrivate->mpCopeMenu->addAction(pDeleteAction);
	this->mpPrivate->mpCopeMenu->addAction(pAddAction);
	this->mpPrivate->mpCopeMenu->addAction(pDeleteAction);
	this->mpPrivate->mpCopeMenu->addAction(pModifyAction);
	this->mpPrivate->mpCopeMenu->addAction(pCopeAction);
	this->mpPrivate->mpCopeMenu->addAction(pCutAction);
	this->mpPrivate->mpCopeMenu->addAction(pPasteAction);

	
	

	this->mpPrivate->mpCutMenu = new QMenu(this);

	this->mpPrivate->mpCutMenu->addAction(pDeleteAction);
	this->mpPrivate->mpCutMenu->addAction(pAddAction);
	this->mpPrivate->mpCutMenu->addAction(pDeleteAction);
	this->mpPrivate->mpCutMenu->addAction(pModifyAction);
	this->mpPrivate->mpCutMenu->addAction(pCopeAction);
	this->mpPrivate->mpCutMenu->addAction(pCutAction);
	this->mpPrivate->mpCutMenu->addAction(pPasteAction);

	this->mpPrivate->mpPasteMenu = new QMenu(this);
	this->mpPrivate->mpPasteMenu->addAction(pDeleteAction);
	this->mpPrivate->mpPasteMenu->addAction(pAddAction);
	this->mpPrivate->mpPasteMenu->addAction(pDeleteAction);
	this->mpPrivate->mpPasteMenu->addAction(pModifyAction);
	this->mpPrivate->mpPasteMenu->addAction(pCopeAction);
	this->mpPrivate->mpPasteMenu->addAction(pCutAction);
	this->mpPrivate->mpPasteMenu->addAction(pPasteAction);
}

QString VTBangDataSourceTreeWidget::getItemIcon(const std::string& type)
{
	QString iconPath("data\\Resources\\project\\default.png");
	if (type == VirtualMine::Core::GeoDataType::GDT_TERRANE)
	{
		iconPath = QString("data\\Resources\\project\\rocklayer.png");
	}
	else if (type == VirtualMine::Core::GeoDataType::GDT_SHOTHOLE)
	{
		iconPath = QString("data\\Resources\\project\\taocaoyan.png");
	}
	else if (type == VirtualMine::Core::GeoDataType::GDT_ESCAPEROUTE)
	{
		iconPath = QString("data\\Resources\\project\\escapRoute.png");
	}
	else if(type == VirtualMine::Core::GeoDataType::GDT_LANEWAYSECTION)
	{
		iconPath = QString("data\\Resources\\project\\section.png");////
	}
	else if(type == VirtualMine::Core::GeoDataType::GDT_FAULT)/////爆破顺序
	{
		iconPath = QString("data\\Resources\\project\\bangorder.png");////
	}
	else if(type == VirtualMine::Core::GeoDataType::GDT_IMAGE)/////工程图片
	{
		iconPath = QString("data\\Resources\\project\\project.png");////
	}


	return iconPath;
}

QTreeWidgetItem* VTBangDataSourceTreeWidget::getItem(const std::string& type)
{
	if (type == VirtualMine::Core::GeoDataType::GDT_TERRANE)
	{
		return this->mpPrivate->mpRockItem;
	}
	else if (type == VirtualMine::Core::GeoDataType::GDT_SHOTHOLE)
	{
		return this->mpPrivate->mpShotHoleItem;
	}
	else if (type == VirtualMine::Core::GeoDataType::GDT_ESCAPEROUTE)
	{
		return this->mpPrivate->mpEvacuationRouteItem;
	} 
	else if (type == VirtualMine::Core::GeoDataType::GDT_LANEWAYSECTION)
	{
		return this->mpPrivate->mpSectionItem;
	} 
	//kk
	else if (type == VirtualMine::Core::GeoDataType::GDT_CONORGANIZATION)
	{
		return this->mpPrivate->mpConstructionOrgItem;
	}
	//kk
	else if (type == VirtualMine::Core::GeoDataType::GDT_CONPROGRESS)
	{
		return this->mpPrivate->mpConstructionProgressItem;
	}
	return NULL;
}

void VTBangDataSourceTreeWidget::slotAdd()
{

}

void VTBangDataSourceTreeWidget::slotModify()
{

}
void VTBangDataSourceTreeWidget::slotDelete()
{
	
}
void VTBangDataSourceTreeWidget::slotCope()
{

}
void VTBangDataSourceTreeWidget::slotCut()
{

}
void VTBangDataSourceTreeWidget::slotPaste()
{

}

void VTBangDataSourceTreeWidget::contextMenuEvent( QContextMenuEvent * event )
{
	QPoint point = QCursor::pos();
	point = mapFromGlobal(point);
	QTreeWidgetItem *item = this->itemAt(point);
	this->mpPrivate->ref_mpSelectedItem = item;
	if (item != NULL)
	{
		VRBangLayerItem* pMgrItem = dynamic_cast<VRBangLayerItem*>(item);
		if (pMgrItem)
		{
	        int intType = pMgrItem->getIntType();   
			if (intType == 1)
			{
				this->mpPrivate->mpAddMenu->exec(QCursor::pos());
				
			}
			else if (intType == 2)
			{
				this->mpPrivate->mpAddMenu->exec(QCursor::pos());
			
			}
			else if (intType == 3)
			{
				this->mpPrivate->mpAddMenu->exec(QCursor::pos());
			
			}
			else if (intType == 4)
			{
				this->mpPrivate->mpAddMenu->exec(QCursor::pos());
			
			}
			else if (intType == 5)
			{
				this->mpPrivate->mpAddMenu->exec(QCursor::pos());
			
			}
			else if (intType == 6)
			{
				this->mpPrivate->mpAddMenu->exec(QCursor::pos());
			
			}
			else if (intType == 7)
			{
				this->mpPrivate->mpAddMenu->exec(QCursor::pos());
				
			}
			else if (intType == 8)
			{
				this->mpPrivate->mpAddMenu->exec(QCursor::pos());
				
			}


			event->accept();
		}
	}
}

void VTBangDataSourceTreeWidget::mouseReleaseEvent(QMouseEvent *  event)
{
	QPoint point = QCursor::pos();
	point = mapFromGlobal(point);
	
	//QTreeWidgetItem *item = this->itemAt(point);
	//kk
	item = this->itemAt(point);
	std::vector<string> exportInfoVec;
	int exportInfoCount = 0;

	if (item)
  {
		//kk
		//VRBangLayerItem* pLayerItem = dynamic_cast<VRBangLayerItem*>(item);

		pLayerItem= dynamic_cast<VRBangLayerItem*>(item);
		if (pLayerItem)
		{
			layerType = pLayerItem->getIntType();
			cout<<"我的type类型是！！！！！！"<<layerType<<endl;
#pragma region  岩层参数
			if (layerType == 1)
			{
				Qt::CheckState oldCheckstatus = item->checkState(0);
				QTreeWidget::mouseReleaseEvent(event);
				Qt::CheckState curCheckstatus = item->checkState(0);
				bool changed = (oldCheckstatus != curCheckstatus);
				if (!changed)
				{
					{
						pLayerItem->setCheckState(0,Qt::CheckState::Checked);
						pLayerItem->get3DBindingObject()->setVisible(true);
						int childCount =  pLayerItem->childCount();

						exportInfoVec.push_back("岩层数量");
						string terraneAllCount = Ogre::StringConverter::toString(childCount);
						exportInfoVec.push_back(terraneAllCount);

						if (childCount > 0)
						{
							for (int i = 0; i < childCount; i++)
							{
								pLayerItem->child(i)->setCheckState(0,Qt::CheckState::Checked);
							}
						}

#pragma region 岩层高亮

				

#if 1 当前岩层

						if (pLayerItem->get3DBindingObject())
						{
							
							VirtualMine::SpatialInterface::GeoObjectVector objVec;

							CTerraneLayer* pLayer = dynamic_cast<CTerraneLayer*>(pLayerItem->get3DBindingObject());	
							VirtualMine::SpatialRender::CTerraneRenderableObject* renderobject = dynamic_cast<VirtualMine::SpatialRender::CTerraneRenderableObject* >(pLayer->getRenderableObject());

							VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
							renderobject->getGeoExtentionDatas(geoExtenvec);
							int size1 =  renderobject->getExtentionData().size();

							for (int i = 0 ; i < size1; i++)
							{
								VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
								std::string nameMat = extentData->getExtentionData()->getName();
								if (nameMat == "砂岩")
								{
									int count = extentData->getExtentionData()->getNumSections();
									for (int i = 0; i < count; i++)
									{
										///设置原来的材质
										extentData->getExtentionData()->getSection(i)->setMaterialName("terraneUpMaterial",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);		
									}
								}
								else if (nameMat == "灰岩")
								{
									int count = extentData->getExtentionData()->getNumSections();
									for (int i = 0; i < count; i++)
									{
										///设置原来的材质
										extentData->getExtentionData()->getSection(i)->setMaterialName("terraneDownMaterial",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);		
									}
								}
								else
								{
									int count = extentData->getExtentionData()->getNumSections();
									for (int i = 0; i < count; i++)
									{
										///设置原来的材质
										extentData->getExtentionData()->getSection(i)->setMaterialName("terraneSiderMaterial",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);		
									}
								}


							}
					
						}
#endif							



#pragma endregion

					}
				}
				else if (changed)
				{
					if (pLayerItem->get3DBindingObject())
					{
						pLayerItem->get3DBindingObject()->setVisible(curCheckstatus);
						std::vector<Ogre::SceneNode*> pNodes = dynamic_cast<CSceneLayer*>(pLayerItem->get3DBindingObject())->getTextNodes();
						if (pNodes.size() > 0)
						{
							for (int i = 0; i < pNodes.size();i++)
							{
								pNodes.at(i)->setVisible(curCheckstatus);

							}
						}
					}
					int childCount =  pLayerItem->childCount();
					if (childCount > 0)
					{
						for (int i = 0; i < childCount; i++)
						{
							pLayerItem->child(i)->setCheckState(0,curCheckstatus);
						}
					}

					///2维
					if (pLayerItem->get2DBindingObject())
					{
						pLayerItem->get2DBindingObject()->setVisible(curCheckstatus);
						CRefreshMapEvent refreshMapEvt;
						CEventDispatcher::setEvent(&refreshMapEvt);
					}					
				}

			}
#pragma endregion
#pragma region  巷道断面
			if (layerType == 2 )
			{
				Qt::CheckState oldCheckstatus = item->checkState(0);
				QTreeWidget::mouseReleaseEvent(event);
				Qt::CheckState curCheckstatus = item->checkState(0);
				bool changed = (oldCheckstatus != curCheckstatus);
				if (!changed)
				{									
						pLayerItem->setCheckState(0,Qt::CheckState::Checked);
						pLayerItem->get3DBindingObject()->setVisible(true);
						int childCount =  pLayerItem->childCount();
						if (childCount > 0)
						{
							for (int i = 0; i < childCount; i++)
							{
								pLayerItem->child(i)->setCheckState(0,Qt::CheckState::Checked);
							}
						}
						if (pLayerItem->get2DBindingObject())
						{
							//pLayerItem->get2DBindingObject()->setVisible(curCheckstatus);
							C2DLanewaySectionLayer* Layer2D=dynamic_cast<C2DLanewaySectionLayer*>(pLayerItem->get2DBindingObject());
							Layer2D->setVisibled(true);
							CRefreshMapEvent refreshMapEvt;
							CEventDispatcher::setEvent(&refreshMapEvt);
						}
#pragma region 清除炮眼高亮					
						{
							
							if (this->mpPrivate->mpShotHoleItem)
							{
								if (mpPrivate->mpShotHoleItem->get3DBindingObject())
								{
									VirtualMine::SpatialInterface::GeoObjectVector objVec;

									CShotHoleLayer* pLayer = dynamic_cast<CShotHoleLayer*>(mpPrivate->mpShotHoleItem->get3DBindingObject());	
									VirtualMine::BaseRender::CPipeLine* renderobject = dynamic_cast<VirtualMine::BaseRender::CPipeLine* >(pLayer->getRenderableObject());

									VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
									renderobject->getGeoExtentionDatas(geoExtenvec);
									int size1 =  renderobject->getExtentionData().size();


									for (int i = 0 ; i < size1; i++)
									{
										VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
										std::string boomType = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomType();
										int boomOrder = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomOrder();
										int boomID = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomID();

										int count = extentData->getExtentionData()->getNumSections();
										for (int i = 0; i < count; i++)
										{
											extentData->getExtentionData()->getSection(i)->setMaterialName("pipelineMat",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);		
										}

									}
								}
							}
									

						}
#pragma endregion
						if (this->mpPrivate->mpShotHoleItem)
						{							
						  if (this->mpPrivate->mpShotHoleItem->get2DBindingObject())
						  {
							C2DShotHoleLayer* Layer2Dshot=dynamic_cast<C2DShotHoleLayer*>(this->mpPrivate->mpShotHoleItem->get2DBindingObject());						
							//主视图清楚高亮
							std::set<int>::iterator curitr = curholeIDVec.begin();
							while(curitr != curholeIDVec.end())
							{
								int id = *curitr;
								std::string idName = Ogre::StringConverter::toString(id);								
								VirtualMine::Map::CPointDrawItem* pItem = dynamic_cast<VirtualMine::Map::CPointDrawItem*>(Layer2Dshot->getGeometryItem(idName));
								if (pItem)
								{														
									pItem->getStyle()->setColor(oldColor);							
								}
								curitr++;
							}
							//左视图，俯视图清楚高亮
							for (int i=0;i<shortypeVector.size();++i)
							{
								VirtualMine::Map::CLineDrawItem* pItem = dynamic_cast<VirtualMine::Map::CLineDrawItem*>(Layer2Dshot->getGeometryItem(shortypeVector.at(i)));
								if (pItem)
								{	
									//oColor[i]=pItem->getStyle()->getColor();
									pItem->getStyle()->setColor(oColor[i]);	
									//pItem->setVisible(true);
								}
							}
							//起爆顺序清除高亮
							CLineDrawItem* oldItem=dynamic_cast<CLineDrawItem*>(Layer2Dshot->getGeometryItem(oldOrverID2D));
							if (oldItem)
							{
								oldItem->getStyle()->setColor(oldorderColor);
							}
						  }
						}

				}
				else if (changed)
				{
					if (pLayerItem->get3DBindingObject())
					{
						pLayerItem->get3DBindingObject()->setVisible(curCheckstatus);
						std::vector<Ogre::SceneNode*> pNodes = dynamic_cast<CSceneLayer*>(pLayerItem->get3DBindingObject())->getTextNodes();
						if (pNodes.size() > 0)
						{
							for (int i = 0; i < pNodes.size();i++)
							{
								pNodes.at(i)->setVisible(curCheckstatus);

							}
						}
					}
					int childCount =  pLayerItem->childCount();
					if (childCount > 0)
					{
						for (int i = 0; i < childCount; i++)
						{
							pLayerItem->child(i)->setCheckState(0,curCheckstatus);
						}
					}

					///2维
					if (pLayerItem->get2DBindingObject())
					{
						//pLayerItem->get2DBindingObject()->setVisible(curCheckstatus);
						C2DLanewaySectionLayer* Layer2D=dynamic_cast<C2DLanewaySectionLayer*>(pLayerItem->get2DBindingObject());
						Layer2D->setVisibled(curCheckstatus);
						CRefreshMapEvent refreshMapEvt;
						CEventDispatcher::setEvent(&refreshMapEvt);
					}					
				}

			}
#pragma endregion
#pragma region 炮眼设计	
			else if (layerType == 3)////炮眼
			{
				//////////////////////////////////////////////////////////////////////////
				//显示属性

				std::set<int> holeset;
				std::set<std::string> typeSet;
				std::string shotHoleName = "";
				if (pLayerItem->get3DBindingObject())
				{			
					CShotHoleLayer* pLayer = dynamic_cast<CShotHoleLayer*>(pLayerItem->get3DBindingObject());	
					VirtualMine::BaseRender::CPipeLine* renderobject = dynamic_cast<VirtualMine::BaseRender::CPipeLine* >(pLayer->getRenderableObject());

					VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
					renderobject->getGeoExtentionDatas(geoExtenvec);
					int size1 =  renderobject->getExtentionData().size();
					for (int i = 0 ; i < size1; i++)
					{
						VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);				
						int bangID= dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomID();							
						std::string bangType= dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomType();
						holeset.insert(bangID);	
						typeSet.insert(bangType);

					}

					exportInfoVec.push_back("炮眼类型数");
					string shotHoleAllTypeCount =Ogre::StringConverter::toString(typeSet.size());
					exportInfoVec.push_back(shotHoleAllTypeCount);
					exportInfoVec.push_back("炮眼数量");
					string shotHoleAllCount =Ogre::StringConverter::toString(holeset.size());
					exportInfoVec.push_back(shotHoleAllCount);

				}
				//////////////////////////////////////////////////////////////////////////
				Qt::CheckState oldCheckstatus = item->checkState(0);
				QTreeWidget::mouseReleaseEvent(event);
				Qt::CheckState curCheckstatus = item->checkState(0);
				bool changed = (oldCheckstatus != curCheckstatus);			
				///2维
				if (!changed)
				{			
						pLayerItem->setCheckState(0,Qt::CheckState::Checked);
						if (pLayerItem->get3DBindingObject())
						{
							pLayerItem->get3DBindingObject()->setVisible(true);	
						}
											
						C2DShotHoleLayer* Layer2D = dynamic_cast<C2DShotHoleLayer*>(pLayerItem->get2DBindingObject());
						if (Layer2D)
						{
							Layer2D->setVisibled(0,true);
						}
						
						int childCount =  pLayerItem->childCount();
						if (childCount > 0)
						{
							for (int i = 0; i < childCount; i++)
							{
								pLayerItem->child(i)->setCheckState(0,Qt::CheckState::Checked);
							}
						}
//主视图清除高亮
						std::set<int>::iterator curitr = curholeIDVec.begin();
						while(curitr != curholeIDVec.end())
						{
							int id = *curitr;
							std::string idName = Ogre::StringConverter::toString(id);								
							VirtualMine::Map::CPointDrawItem* pItem = dynamic_cast<VirtualMine::Map::CPointDrawItem*>(Layer2D->getGeometryItem(idName));
							if (pItem)
							{	
								if (pItem->getStyle())
							    {
								    pItem->getStyle()->setColor(oldColor);	
						     	}


							}
							curitr++;
						}
//左视图，俯视图清除高亮
						for (int i = 0; i < shortypeVector.size(); ++i)
						{
							VirtualMine::Map::CLineDrawItem* pItem = dynamic_cast<VirtualMine::Map::CLineDrawItem*>(Layer2D->getGeometryItem(shortypeVector.at(i)));
							if (pItem)
							{	
								//oColor[i]=pItem->getStyle()->getColor();
								if (pItem->getStyle())
								{
									pItem->getStyle()->setColor(oColor[i]);	
								}
								
								//pItem->setVisible(true);
							}
						}
						CRefreshMapEvent refreshMapEvt;
					    CEventDispatcher::setEvent(&refreshMapEvt);

#pragma region  清除炮眼高亮											

						if (pLayerItem->get3DBindingObject())
						{

							VirtualMine::SpatialInterface::GeoObjectVector objVec;

							CShotHoleLayer* pLayer = dynamic_cast<CShotHoleLayer*>(pLayerItem->get3DBindingObject());	
							VirtualMine::BaseRender::CPipeLine* renderobject = dynamic_cast<VirtualMine::BaseRender::CPipeLine* >(pLayer->getRenderableObject());

							VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
							renderobject->getGeoExtentionDatas(geoExtenvec);
							int size1 =  renderobject->getExtentionData().size();


							for (int i = 0 ; i < size1; i++)
							{
								VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
								std::string boomType = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomType();
								int boomOrder = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomOrder();
								int boomID = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomID();

								int count = extentData->getExtentionData()->getNumSections();
								for (int i = 0; i < count; i++)
								{
									extentData->getExtentionData()->getSection(i)->setMaterialName("pipelineMat",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);		
								}

							}

						}					


#pragma endregion				
				}
				else if (changed)
				{	
					if ( pLayerItem->get3DBindingObject())
					{
						 pLayerItem->get3DBindingObject()->setVisible(curCheckstatus);
					}
				 
				  C2DShotHoleLayer* Layer2D = dynamic_cast<C2DShotHoleLayer*>(pLayerItem->get2DBindingObject());
				  if (Layer2D)
				  {
					   Layer2D->setVisibled(0,curCheckstatus);
				  }
				 
				  CRefreshMapEvent refreshMapEvt;
				  CEventDispatcher::setEvent(&refreshMapEvt);
					int childCount =  pLayerItem->childCount();
					if (childCount > 0)
					{
						for (int i = 0; i < childCount; i++)
						{
							pLayerItem->child(i)->setCheckState(0,curCheckstatus);
						}
					}					
				}	
				
			}
#pragma endregion
#pragma region 起爆顺序
			else if (layerType == 4)////起爆顺序
			{
				//////////////////////////////////////////////////////////////////////////
				//属性
				std::set<int> holeBangOrderVec;
				std::string shotHoleOrderName = "";
				if (pLayerItem->get3DBindingObject())
				{
					//pLayerItem->get3DBindingObject()->setVisible(curCheckstatus);
					//VirtualMine::SpatialInterface::GeoObjectVector objVec;
					CShotHoleLayer* pLayer = dynamic_cast<CShotHoleLayer*>(pLayerItem->get3DBindingObject());	
					VirtualMine::BaseRender::CPipeLine* renderobject = dynamic_cast<VirtualMine::BaseRender::CPipeLine* >(pLayer->getRenderableObject());

					VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
					if (renderobject)
					{
						renderobject->getGeoExtentionDatas(geoExtenvec);
					}
					
					int size1 =  renderobject->getExtentionData().size();

					if (size1 > 0)
					{
						for (int i = 0 ; i < size1; i++)
						{
							VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
							int boomOrder = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomOrder();						
							{
								holeBangOrderVec.insert(boomOrder);
							}
						}
					}
				


					std::set<int>::iterator shotHoleOrderItr = holeBangOrderVec.begin();
					while(shotHoleOrderItr!=holeBangOrderVec.end())
					{
						int orderTemp = *shotHoleOrderItr;
						shotHoleOrderName = Ogre::StringConverter::toString(orderTemp) + " " + shotHoleOrderName;
						shotHoleOrderItr++;
					}

					//exportInfoVec.push_back("起爆顺序");
					//exportInfoVec.push_back(shotHoleOrderName);
					exportInfoVec.push_back("起爆段数");
					std::string shotHoleOrderAllCount = Ogre::StringConverter::toString(holeBangOrderVec.size());
					exportInfoVec.push_back(shotHoleOrderAllCount);


				}

				//////////////////////////////////////////////////////////////////////////
				Qt::CheckState oldCheckstatus = item->checkState(0);
				QTreeWidget::mouseReleaseEvent(event);
				Qt::CheckState curCheckstatus = item->checkState(0);
				bool changed = (oldCheckstatus != curCheckstatus);
				///2维
				if (!changed)
				{
					
						pLayerItem->setCheckState(0,Qt::CheckState::Checked);
						if (pLayerItem->get3DBindingObject())
						{
							pLayerItem->get3DBindingObject()->setVisible(true);
						}
						
						C2DShotHoleLayer* Layer2D = dynamic_cast<C2DShotHoleLayer*>(pLayerItem->get2DBindingObject());
						if (Layer2D)
						{
							Layer2D->setVisibled(1,true);
						}
						
						CRefreshMapEvent refreshMapEvt;
						CEventDispatcher::setEvent(&refreshMapEvt);

						int childCount =  pLayerItem->childCount();
						if (childCount > 0)
						{
							for (int i = 0; i < childCount; i++)
							{
								pLayerItem->child(i)->setCheckState(0,Qt::CheckState::Checked);
							}
						}
//起爆顺序清除高亮
						CLineDrawItem* oldItem = NULL;
						if (Layer2D)
						{
							 oldItem = dynamic_cast<CLineDrawItem*>(Layer2D->getGeometryItem(oldOrverID2D));

						}
						if (oldItem)
						{
							if (oldItem->getStyle())
							{
								oldItem->getStyle()->setColor(oldorderColor);
							}
							
						}
						
#pragma region 炮眼高亮					
						{
							std::set<int> oldholeIDVec;
							std::set<int> curholeIDVec;
							std::set<std::string> typename2;
							std::vector<std::string> shortypeVector;
							std::vector<std::string> oldshortypeVector;
							if (pLayerItem->get3DBindingObject())
							{

								VirtualMine::SpatialInterface::GeoObjectVector objVec;

								CShotHoleLayer* pLayer = dynamic_cast<CShotHoleLayer*>(pLayerItem->get3DBindingObject());	
								VirtualMine::BaseRender::CPipeLine* renderobject = NULL;
								if (pLayer)
								{
									renderobject = dynamic_cast<VirtualMine::BaseRender::CPipeLine* >(pLayer->getRenderableObject());
								}
							

								VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
								if (renderobject)
								{
									renderobject->getGeoExtentionDatas(geoExtenvec);
								}
							
								int size1 =  renderobject->getExtentionData().size();

								if (size1 > 0)
								{

									for (int i = 0 ; i < size1; i++)
									{
										VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
										std::string boomType = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomType();
										int boomOrder = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomOrder();
										int boomID = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomID();

										int count = extentData->getExtentionData()->getNumSections();
										for (int i = 0; i < count; i++)
										{
											extentData->getExtentionData()->getSection(i)->setMaterialName("pipelineMat",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);		
										}

									}
								}

							}					

						}
#pragma endregion
                       //C2DShotHoleLayer* p2Dlayer = dynamic_cast<C2DShotHoleLayer*>(pLayerItem->get2DBindingObject());					
				       
				}
				else if (changed)
				{
					if (pLayerItem->get2DBindingObject())
					{	
						std::set<int> holeBangOrderVec;
						if (pLayerItem->get3DBindingObject())
						{
							if (pLayerItem->get3DBindingObject())
							{
								pLayerItem->get3DBindingObject()->setVisible(curCheckstatus);
							}
							
							VirtualMine::SpatialInterface::GeoObjectVector objVec;
							CShotHoleLayer* pLayer = dynamic_cast<CShotHoleLayer*>(pLayerItem->get3DBindingObject());	
						   	VirtualMine::BaseRender::CPipeLine* renderobject = NULL;
							if (pLayer)
						    {
							   renderobject = dynamic_cast<VirtualMine::BaseRender::CPipeLine* >(pLayer->getRenderableObject());

						    }

							VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
							if (renderobject)
							{
								renderobject->getGeoExtentionDatas(geoExtenvec);
							}

							int size1 =  renderobject->getExtentionData().size();
							if (size1 > 0)
							{
								for (int i = 0 ; i < size1; i++)
								{
									VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
									int boomOrder = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomOrder();						
									{
										holeBangOrderVec.insert(boomOrder);
									}
								}
							}
						
						}
						int childCount =  pLayerItem->childCount();
						if (childCount > 0)
						{
							for (int i = 0; i < childCount; i++)
							{
								pLayerItem->child(i)->setCheckState(0,curCheckstatus);
							}
						}						
						std::set<int>::iterator orderItr = holeBangOrderVec.begin();
						while(orderItr != holeBangOrderVec.end())
						{
							int bangOrder = *orderItr;
							std::string orderID="lianxian"+Ogre::StringConverter::toString(bangOrder);
							std::string holeName = "boomline" + Ogre::StringConverter::toString(bangOrder);
							C2DShotHoleLayer* p2Dlayer = dynamic_cast<C2DShotHoleLayer*>(pLayerItem->get2DBindingObject());
							dynamic_cast<CLineDrawItem*>(p2Dlayer->getGeometryItem(holeName))->setVisible(curCheckstatus);
							dynamic_cast<CTextDrawItem*>(p2Dlayer->getGeometryItem(orderID))->setVisible(curCheckstatus);
							orderItr++;
						}
						CRefreshMapEvent refreshMapEvt;
						CEventDispatcher::setEvent(&refreshMapEvt);
					}
				}
			
			
			}

#pragma endregion
#pragma region 避难路线
			else if (layerType == 5)
			{
				//////////////////////////////////////////////////////////////////////////
				//属性
				std::set<std::string> lanewayNameSet;
				std::string lanewayAllName = "";
				if (pLayerItem->get3DBindingObject())
				{

					VirtualMine::SpatialLayer::CEscapeRouteLayer* pLayer = dynamic_cast<VirtualMine::SpatialLayer::CEscapeRouteLayer*>(pLayerItem->get3DBindingObject());	
					VirtualMine::SpatialRender::CLanewayRenderableObject* renderobject = dynamic_cast<VirtualMine::SpatialRender::CLanewayRenderableObject*>(pLayer->getRenderableObject());

					VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
					renderobject->getGeoExtentionDatas(geoExtenvec);
					int size1 =  renderobject->getExtentionData().size();
					for (int i = 0 ; i < size1; i++)
					{
						VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);	
						std::string lanewayName =  dynamic_cast<CLaneWayObject*>(renderobject->getGeoObject(i))->getName();
						lanewayNameSet.insert(lanewayName);
					}	
					std::set<std::string>::iterator lanewayNameItr = lanewayNameSet.begin();
					while(lanewayNameItr!=lanewayNameSet.end())
					{
						lanewayAllName = *lanewayNameItr + " " + lanewayAllName;
						lanewayNameItr++;
					}
					//exportInfoVec.push_back("巷道名称");
					//exportInfoVec.push_back(lanewayAllName);
					std::string lanewayAllCount = Ogre::StringConverter::toString(lanewayNameSet.size());
					exportInfoVec.push_back("巷道数量");
					exportInfoVec.push_back(lanewayAllCount);
					exportInfoVec.push_back("标示数量");
					exportInfoVec.push_back("3");

				}
				
				//////////////////////////////////////////////////////////////////////////
				Qt::CheckState oldCheckstatus = item->checkState(0);
				QTreeWidget::mouseReleaseEvent(event);
				Qt::CheckState curCheckstatus = item->checkState(0);
				bool changed = (oldCheckstatus != curCheckstatus);
						
				if (!changed)
				{
					//changed为0，也就是状态没改变
					/*mIsSelectedCheck = false;
					if (!mIsSelectedCheck)*/
					{
						pLayerItem->setCheckState(0,Qt::CheckState::Checked);
						if (pLayerItem->get3DBindingObject())
						{
						   pLayerItem->get3DBindingObject()->setVisible(true);
						}

					
						int childCount =  pLayerItem->childCount();
						if (childCount > 0)
						{
							for (int i = 0; i < childCount; i++)
							{
								pLayerItem->child(i)->setCheckState(0,Qt::CheckState::Checked);
							}
						}
					}
				}
				else if (changed)
				{
					//changed为1，也就是状态改变了
					if (pLayerItem->get3DBindingObject())
					{
						pLayerItem->get3DBindingObject()->setVisible(curCheckstatus);
						 
						std::vector<Ogre::SceneNode*> pNodes = dynamic_cast<CSceneLayer*>(pLayerItem->get3DBindingObject())->getTextNodes();
						if (pNodes.size() > 0)
						{
							for (int i = 0; i < pNodes.size();i++)
							{
								pNodes.at(i)->setVisible(curCheckstatus);

							}
						}
					}
				}
			
			}
#pragma endregion
			//kk施工组织图
#pragma region 施工组织图
			else if (layerType == 6)
			{
				//////////////////////////////////////////////////////////////////////////
				//属性
				std::set<std::string> lanewayNameSet;
				std::string lanewayAllName = "";
				if (pLayerItem->get3DBindingObject())
				{

					VirtualMine::SpatialLayer::CEscapeRouteLayer* pLayer = dynamic_cast<VirtualMine::SpatialLayer::CEscapeRouteLayer*>(pLayerItem->get3DBindingObject());	
					VirtualMine::SpatialRender::CLanewayRenderableObject* renderobject = dynamic_cast<VirtualMine::SpatialRender::CLanewayRenderableObject*>(pLayer->getRenderableObject());

					VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
					renderobject->getGeoExtentionDatas(geoExtenvec);
					int size1 =  renderobject->getExtentionData().size();
					for (int i = 0 ; i < size1; i++)
					{
						VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);	
						std::string lanewayName =  dynamic_cast<CLaneWayObject*>(renderobject->getGeoObject(i))->getName();
						lanewayNameSet.insert(lanewayName);
					}	
					std::set<std::string>::iterator lanewayNameItr = lanewayNameSet.begin();
					while(lanewayNameItr!=lanewayNameSet.end())
					{
						lanewayAllName = *lanewayNameItr + " " + lanewayAllName;
						lanewayNameItr++;
					}
					//exportInfoVec.push_back("巷道名称");
					//exportInfoVec.push_back(lanewayAllName);
					std::string lanewayAllCount = Ogre::StringConverter::toString(lanewayNameSet.size());
					exportInfoVec.push_back("巷道数量");
					exportInfoVec.push_back(lanewayAllCount);
					exportInfoVec.push_back("标示数量");
					exportInfoVec.push_back("3");

				}
				

				//////////////////////////////////////////////////////////////////////////
				Qt::CheckState oldCheckstatus = item->checkState(0);
				QTreeWidget::mouseReleaseEvent(event);
				Qt::CheckState curCheckstatus = item->checkState(0);
				bool changed = (oldCheckstatus != curCheckstatus);
				if (!changed)
				{
					/*mIsSelectedCheck = false;
					if (!mIsSelectedCheck)*/
					{
						pLayerItem->setCheckState(0,Qt::CheckState::Checked);
						if (pLayerItem->get3DBindingObject())
						{
						   pLayerItem->get3DBindingObject()->setVisible(true);
						}

					
						int childCount =  pLayerItem->childCount();
						if (childCount > 0)
						{
							for (int i = 0; i < childCount; i++)
							{
								pLayerItem->child(i)->setCheckState(0,Qt::CheckState::Checked);
							}
						}
					}
				}
				else if (changed)
				{
					if (pLayerItem->get3DBindingObject())
					{
						pLayerItem->get3DBindingObject()->setVisible(curCheckstatus);
						 
						std::vector<Ogre::SceneNode*> pNodes = dynamic_cast<CSceneLayer*>(pLayerItem->get3DBindingObject())->getTextNodes();
						if (pNodes.size() > 0)
						{
							for (int i = 0; i < pNodes.size();i++)
							{
								pNodes.at(i)->setVisible(curCheckstatus);

							}
						}
					}
				}
			
			}
#pragma endregion
			//kk施工进度图
#pragma region 施工进度图
			else if (layerType == 7)
			{
				//////////////////////////////////////////////////////////////////////////
				//属性
				std::set<std::string> lanewayNameSet;
				std::string lanewayAllName = "";
				if (pLayerItem->get3DBindingObject())
				{

					VirtualMine::SpatialLayer::CConProgressLayer* pLayer = dynamic_cast<VirtualMine::SpatialLayer::CConProgressLayer*>(pLayerItem->get3DBindingObject());	
					VirtualMine::SpatialRender::CLanewayRenderableProgress* renderobject = dynamic_cast<VirtualMine::SpatialRender::CLanewayRenderableProgress*>(pLayer->getRenderableObject());

					VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
					renderobject->getGeoExtentionDatas(geoExtenvec);
					int size1 =  renderobject->getExtentionData().size();
					for (int i = 0 ; i < size1; i++)
					{
					VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);	
						std::string lanewayName =  dynamic_cast<CLaneWayObjectPro*>(renderobject->getGeoObject(i))->getName();
						lanewayNameSet.insert(lanewayName);
					}	
					std::set<std::string>::iterator lanewayNameItr = lanewayNameSet.begin();
					while(lanewayNameItr!=lanewayNameSet.end())
					{
						lanewayAllName = *lanewayNameItr + " " + lanewayAllName;
						lanewayNameItr++;
					}
					//exportInfoVec.push_back("巷道名称");
					//exportInfoVec.push_back(lanewayAllName);
					std::string lanewayAllCount = Ogre::StringConverter::toString(lanewayNameSet.size());
					exportInfoVec.push_back("巷道数量");
					exportInfoVec.push_back(lanewayAllCount);
					exportInfoVec.push_back("标示数量");
					exportInfoVec.push_back("3");

				}
				
				//////////////////////////////////////////////////////////////////////////
				Qt::CheckState oldCheckstatus = item->checkState(0);
				QTreeWidget::mouseReleaseEvent(event);
				Qt::CheckState curCheckstatus = item->checkState(0);
				bool changed = (oldCheckstatus != curCheckstatus);
						
				if (!changed)
				{
					//changed为0，也就是状态没改变
					/*mIsSelectedCheck = false;
					if (!mIsSelectedCheck)*/
					{
						pLayerItem->setCheckState(0,Qt::CheckState::Checked);
						if (pLayerItem->get3DBindingObject())
						{
						   pLayerItem->get3DBindingObject()->setVisible(true);
						}

					
						int childCount =  pLayerItem->childCount();
						if (childCount > 0)
						{
							for (int i = 0; i < childCount; i++)
							{
								pLayerItem->child(i)->setCheckState(0,Qt::CheckState::Checked);
							}
						}
					}
				}
				else if (changed)
				{
					//changed为1，也就是状态改变了
					if (pLayerItem->get3DBindingObject())
					{
						pLayerItem->get3DBindingObject()->setVisible(curCheckstatus);
						 
						std::vector<Ogre::SceneNode*> pNodes = dynamic_cast<CSceneLayer*>(pLayerItem->get3DBindingObject())->getTextNodes();
						if (pNodes.size() > 0)
						{
							for (int i = 0; i < pNodes.size();i++)
							{
								pNodes.at(i)->setVisible(curCheckstatus);

							}
						}
					}
				}
			
			}
#pragma endregion
		}

		//----------------------------kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk---------------------------//
		//-------点击子项item的监测-------------------//
		//VRBangFeatureItem* pFeatureItem = dynamic_cast<VRBangFeatureItem*>(item);
		pFeatureItem = dynamic_cast<VRBangFeatureItem*>(item);
		if (pFeatureItem)
		{

			Qt::CheckState oldCheckstatus = item->checkState(0);
			QTreeWidget::mouseReleaseEvent(event);
			Qt::CheckState curCheckstatus = item->checkState(0);
			bool changed = (oldCheckstatus != curCheckstatus);
			//kk：changed为false时表示未改变状态
			//kk状态未改变
			if (!changed)
			{		

					pFeatureItem->setCheckState(0,Qt::CheckState::Checked);

#pragma region 高亮
			
						//Ogre::ColourValue curColor=Ogre::ColourValue::Red;
						Ogre::ColourValue curorderColor=Ogre::ColourValue::Red;

						std::string curtypename = "nonametoo";
						CShotHoleFeature* pShotHoleFeature = dynamic_cast<CShotHoleFeature*>(pFeatureItem->getFeature());
						if (pShotHoleFeature)
						{
							//kk获得子item的父级item的intType
							int intType = dynamic_cast<VRBangLayerItem*>(pFeatureItem->parent())->getIntType();
#pragma region 起爆顺序			
							if (intType == 4 )
							{	
								
								std::set<int> orderIDset;		
								if (pFeatureItem->get3DBindingObject())
								{
									std::string name =	pShotHoleFeature->getFieldName();
									//curtypename = pShotHoleFeature->getFieldType();
									int curBangOreder = pShotHoleFeature->getFieldBangOrder();
									VirtualMine::SpatialInterface::GeoObjectVector objVec;

									CShotHoleLayer* pLayer = dynamic_cast<CShotHoleLayer*>(pFeatureItem->get3DBindingObject());	
									VirtualMine::BaseRender::CPipeLine* renderobject = dynamic_cast<VirtualMine::BaseRender::CPipeLine* >(pLayer->getRenderableObject());

									VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
									renderobject->getGeoExtentionDatas(geoExtenvec);
									int size1 =  renderobject->getExtentionData().size();
									for (int i = 0 ; i < size1; i++)
									{
										VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
										int boomOrder = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomOrder();
										int boomID = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomID();
										orderIDset.insert(boomOrder);						
									}
									for (int i = 0 ; i < size1; i++)
									{
										VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);										
										int count = extentData->getExtentionData()->getNumSections();
										for (int i = 0; i < count; i++)
										{
											extentData->getExtentionData()->getSection(i)->setMaterialName("pipelineMat",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
											
										}

									}

									for (int i = 0 ; i < size1; i++)
									{
										VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);										
										int boomOrder = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomOrder();
										if (boomOrder == oldBoomID)
										{
											int count = extentData->getExtentionData()->getNumSections();
											for (int i = 0; i < count; i++)
											{
												extentData->getExtentionData()->getSection(i)->setMaterialName("pipelineMat",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);		
											}										
										}

										if (boomOrder == curBangOreder)
										{
											int count = extentData->getExtentionData()->getNumSections();
											for (int i = 0; i < count; i++)
											{
												extentData->getExtentionData()->getSection(i)->setMaterialName("highlightMat",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);		
												extentData->getExtentionData()->setVisible(true);
												exportInfoCount++;
											}										
										}
									}
									exportInfoVec.push_back("段数名称");
									string bangOrder = Ogre::StringConverter::toString(curBangOreder);
									exportInfoVec.push_back(bangOrder);
									exportInfoVec.push_back("段数");
									string bangOrderCount = Ogre::StringConverter::toString(exportInfoCount/3);
									exportInfoVec.push_back(bangOrderCount);

									VRBangLayerItem* pParent = dynamic_cast<VRBangLayerItem*>(pFeatureItem->parent());
									ILayer* p2Dlayer = NULL;
									if (pParent)
									{
										p2Dlayer = pParent->get2DBindingObject();
									}
									C2DShotHoleLayer* pShotLayer = dynamic_cast<C2DShotHoleLayer*>(p2Dlayer);

									std::string idName = Ogre::StringConverter::toString(curBangOreder);					
									std::string curordername2D = "boomline" + idName;			
									VirtualMine::Map::CLineDrawItem* pItem = dynamic_cast<VirtualMine::Map::CLineDrawItem*>(pShotLayer->getGeometryItem(curordername2D));

									if (pItem->getName()==curordername2D)
									{
										oldorderColor=pItem->getStyle()->getColor();
										pItem->getStyle()->setColor(curorderColor);
										pItem->setVisible(true);
									}					
									std::set<int>::iterator olditr = orderIDset.begin();
									while(olditr != orderIDset.end())
									{
										int id = *olditr;
										std::string idName = "boomline"+Ogre::StringConverter::toString(id);
										if (idName==oldOrverID2D)
										{
											VirtualMine::Map::CLineDrawItem* pItem = dynamic_cast<VirtualMine::Map::CLineDrawItem*>(pShotLayer->getGeometryItem(idName));
											if (pItem->getName()==oldOrverID2D)
											{
												pItem->getStyle()->setColor(oldorderColor);								
											}
										}								
										olditr++;
									}						
									oldBoomID = curBangOreder;

									oldOrverID2D=curordername2D;

									//主视图清除高亮
									std::set<int>::iterator curitr = curholeIDVec.begin();
									while(curitr != curholeIDVec.end())
									{
										int id = *curitr;
										std::string idName = Ogre::StringConverter::toString(id);								
										VirtualMine::Map::CPointDrawItem* pItem = dynamic_cast<VirtualMine::Map::CPointDrawItem*>(pShotLayer->getGeometryItem(idName));
										if (pItem)
										{														
											pItem->getStyle()->setColor(oldColor);							
										}
										curitr++;
									}
									//左视图，俯视图清除高亮
									for (int i=0;i<shortypeVector.size();++i)
									{
										VirtualMine::Map::CLineDrawItem* pItem = dynamic_cast<VirtualMine::Map::CLineDrawItem*>(pShotLayer->getGeometryItem(shortypeVector.at(i)));
										if (pItem)
										{	
											//oColor[i]=pItem->getStyle()->getColor();
											pItem->getStyle()->setColor(oColor[i]);	
											//pItem->setVisible(true);
										}
									}
									CRefreshMapEvent refreshMapEvt;
									CEventDispatcher::setEvent(&refreshMapEvt);
								}

							}
#pragma endregion
#pragma region 炮眼设计
							else if (intType == 3)
							{								
								
								std::set<std::string> typename2;
								
								if (pFeatureItem->get3DBindingObject())
								{
									std::string name =	pShotHoleFeature->getFieldName();
									curtypename = pShotHoleFeature->getFieldType();
									VirtualMine::SpatialInterface::GeoObjectVector objVec;

									CShotHoleLayer* pLayer = dynamic_cast<CShotHoleLayer*>(pFeatureItem->get3DBindingObject());	
									VirtualMine::BaseRender::CPipeLine* renderobject = dynamic_cast<VirtualMine::BaseRender::CPipeLine* >(pLayer->getRenderableObject());

									VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
									renderobject->getGeoExtentionDatas(geoExtenvec);
									int size1 =  renderobject->getExtentionData().size();
									oldholeIDVec.clear();
									curholeIDVec.clear();
									for (int i = 0 ; i < size1; i++)
									{
										VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
										std::string boomType = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomType();
										int boomID = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomID();
										typename2.insert(boomType);
										if (boomType == curtypename)
										{
											curholeIDVec.insert(boomID);
											exportInfoCount++;
											if (exportInfoCount == 1) //属性
											{
												int boomOrder = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomOrder();
												double boomZhuangYaoLength = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomZhuangYaoLength();
												double boomShuiPaoNiLength = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomShuiPaoNiLength();
												double boomFengKongLegth = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomFengNiLength();
												double boomDepth = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomDepth();
												double boomInterval = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomInterval();
												double boomLineOfLeastResistance = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomLineOfLeastResistance();

												string boomOrderStr = Ogre::StringConverter::toString(boomOrder);

												Ogre::Real boomZhuangYaoLengthStrTemp = (Ogre::Real)boomZhuangYaoLength;
												string boomZhuangYaoLengthStr = Ogre::StringConverter::toString(boomZhuangYaoLengthStrTemp);

												Ogre::Real boomShuiPaoNiLengthStrTemp = (Ogre::Real)boomShuiPaoNiLength;
												string boomShuiPaoNiLengthStr = Ogre::StringConverter::toString(boomShuiPaoNiLengthStrTemp);

												Ogre::Real boomFengKongLegthStrTemp = (Ogre::Real)boomFengKongLegth;
												string boomFengKongLegthStr = Ogre::StringConverter::toString(boomFengKongLegthStrTemp);

												Ogre::Real boomDepthStrTemp = (Ogre::Real)boomDepth;
												string boomDepthStr = Ogre::StringConverter::toString(boomDepthStrTemp);

												Ogre::Real boomIntervalStrTemp = (Ogre::Real)boomInterval;
												string boomIntervalStr = Ogre::StringConverter::toString(boomIntervalStrTemp);

												Ogre::Real boomLineOfLeastResistanceStrTemp = (Ogre::Real)boomLineOfLeastResistance;
												string boomLineOfLeastResistanceStr = Ogre::StringConverter::toString(boomLineOfLeastResistanceStrTemp);

												exportInfoVec.push_back("起爆顺序");
												exportInfoVec.push_back(boomOrderStr);
												exportInfoVec.push_back("装药长度");
												exportInfoVec.push_back(boomZhuangYaoLengthStr);
												exportInfoVec.push_back("水炮泥长度");
												exportInfoVec.push_back(boomShuiPaoNiLengthStr);
												exportInfoVec.push_back("封孔长度");
												exportInfoVec.push_back(boomFengKongLegthStr);
												exportInfoVec.push_back("炮孔深度");
												exportInfoVec.push_back(boomDepthStr);
												exportInfoVec.push_back("炮眼间距");
												exportInfoVec.push_back(boomIntervalStr);
												exportInfoVec.push_back("最小抵抗线");
												exportInfoVec.push_back(boomLineOfLeastResistanceStr);

											}
											
										}
										
										if (boomType==oldtypename)
										{
											oldholeIDVec.insert(boomID);
										}
									}
									oldshortypeVector.clear();
									shortypeVector.clear();
								    leftovershotVector(curtypename,shortypeVector);
					
									std::set<std::string>::iterator oldite=typename2.begin();
									while(oldite!=typename2.end())                    
									{
										if (oldtypename==*oldite)
										{
											leftovershotVector(oldtypename,oldshortypeVector);
						
										}

										oldite++;
									}
									for (int i = 0 ; i < size1; i++)
									{
										VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
										std::string boomType = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomType();
										int boomOrder = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomOrder();
										int boomID = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomID();

										int count = extentData->getExtentionData()->getNumSections();
										for (int i = 0; i < count; i++)
										{
											extentData->getExtentionData()->getSection(i)->setMaterialName("pipelineMat",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);		
										}

									}

									for (int i = 0 ; i < size1; i++)
									{
										VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
										std::string boomType = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomType();

										if (boomType==oldtypename)
										{
											int count = extentData->getExtentionData()->getNumSections();
											for (int i = 0; i < count; i++)
											{
												extentData->getExtentionData()->getSection(i)->setMaterialName("pipelineMat",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);		
											}											
										}
										if (boomType == curtypename)
										{
											int count = extentData->getExtentionData()->getNumSections();
											for (int i = 0; i < count; i++)
											{
												extentData->getExtentionData()->getSection(i)->setMaterialName("highlightMat",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);		
											    extentData->getExtentionData()->setVisible(true);
											}
										}

									}
								}					
								//二维炮眼
								if (pFeatureItem->parent())
								{
									VRBangLayerItem* pParent = (VRBangLayerItem*)(pFeatureItem->parent());
									if (!pParent->get2DBindingObject())
									{
										return;
									}										
									C2DShotHoleLayer* p2DLayer = dynamic_cast<C2DShotHoleLayer*>(pParent->get2DBindingObject());													
									std::set<int>::iterator curitr = curholeIDVec.begin();
									while(curitr != curholeIDVec.end())
									{
										int id = *curitr;
										std::string idName = Ogre::StringConverter::toString(id);								
										VirtualMine::Map::CPointDrawItem* pItem = dynamic_cast<VirtualMine::Map::CPointDrawItem*>(p2DLayer->getGeometryItem(idName));
										if (pItem)
										{								
											oldColor=pItem->getStyle()->getColor();
											pItem->getStyle()->setColor(curColor);	
											pItem->setVisible(true);
										}
										curitr++;
									}
									
									std::set<int>::iterator olditr = oldholeIDVec.begin();
									while(olditr != oldholeIDVec.end())
									{
										int id = *olditr;									
										std::string idName = Ogre::StringConverter::toString(id);								
										VirtualMine::Map::CPointDrawItem* pItem = dynamic_cast<VirtualMine::Map::CPointDrawItem*>(p2DLayer->getGeometryItem(idName));
										if (pItem)
										{							
											pItem->getStyle()->setColor(oldColor);	
											//pItem->setVisible(true);
										}
										olditr++;
									}
									for (int i=0;i<oldshortypeVector.size();++i)
									{
										VirtualMine::Map::CLineDrawItem* pItem = dynamic_cast<VirtualMine::Map::CLineDrawItem*>(p2DLayer->getGeometryItem(oldshortypeVector.at(i)));
										if (pItem)
										{							
											pItem->getStyle()->setColor(oColor[i]);	
											//pItem->setVisible(true);
										}
									}
									for (int i=0;i<shortypeVector.size();++i)
									{
										VirtualMine::Map::CLineDrawItem* pItem = dynamic_cast<VirtualMine::Map::CLineDrawItem*>(p2DLayer->getGeometryItem(shortypeVector.at(i)));
										if (pItem)
										{	
											oColor[i]=pItem->getStyle()->getColor();
											pItem->getStyle()->setColor(curColor);	
											pItem->setVisible(true);
										}
									}
									oldtypename=curtypename;									
							       // oldshortypeVector.clear();
									//shortypeVector.clear();

									//起爆顺序清除高亮
									CLineDrawItem* oldItem=dynamic_cast<CLineDrawItem*>(p2DLayer->getGeometryItem(oldOrverID2D));
									if (oldItem)
									{
										oldItem->getStyle()->setColor(oldorderColor);
									}
									CRefreshMapEvent refreshMapEvt;
									CEventDispatcher::setEvent(&refreshMapEvt);

								}
							}
#pragma endregion

						}
						CTerraneFeature* pTerraneFeature = dynamic_cast<CTerraneFeature*>(pFeatureItem->getFeature());
						if (pTerraneFeature)
						{
#pragma region 岩层高亮
														
							std::string RockName = ""; 
							if (pTerraneFeature)
							{
								RockName = pTerraneFeature->getFieldName();
							}

#if 1 当前岩层

							if (pFeatureItem->get3DBindingObject())
							{
								std::string name =	pTerraneFeature->getFieldName();
								
								exportInfoVec.push_back("岩层名称");
								exportInfoVec.push_back(name);
								exportInfoVec.push_back("岩层厚度");
								exportInfoVec.push_back(" ");


								
								VirtualMine::SpatialInterface::GeoObjectVector objVec;

								CTerraneLayer* pLayer = dynamic_cast<CTerraneLayer*>(pFeatureItem->get3DBindingObject());	
								VirtualMine::SpatialRender::CTerraneRenderableObject* renderobject = dynamic_cast<VirtualMine::SpatialRender::CTerraneRenderableObject* >(pLayer->getRenderableObject());

								VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
								renderobject->getGeoExtentionDatas(geoExtenvec);
								int size1 =  renderobject->getExtentionData().size();

								for (int i = 0 ; i < size1; i++)
								{
									VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
									std::string nameMat = extentData->getExtentionData()->getName();
									if (nameMat == "砂岩")
									{
										int count = extentData->getExtentionData()->getNumSections();
										for (int i = 0; i < count; i++)
										{
											///设置原来的材质
											extentData->getExtentionData()->getSection(i)->setMaterialName("terraneUpMaterial",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);		
										}
									}
									else if (nameMat == "灰岩")
									{
										int count = extentData->getExtentionData()->getNumSections();
										for (int i = 0; i < count; i++)
										{
											///设置原来的材质
											extentData->getExtentionData()->getSection(i)->setMaterialName("terraneDownMaterial",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);		
										}
									}
									else
									{
										int count = extentData->getExtentionData()->getNumSections();
										for (int i = 0; i < count; i++)
										{
											///设置原来的材质
											extentData->getExtentionData()->getSection(i)->setMaterialName("terraneSiderMaterial",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);		
										}
									}


								}

								for (int i = 0 ; i < size1; i++)
								{
									VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
									std::string tmpName = extentData->getExtentionData()->getName();
									if (RockName == tmpName)
									{
										int count = extentData->getExtentionData()->getNumSections();
										for (int i = 0; i < count; i++)
										{
											extentData->getExtentionData()->getSection(i)->setMaterialName("highlightMat",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);		
											extentData->getExtentionData()->setVisible(true);
										}

									}

								}

							}
#endif							

					

#pragma endregion
						}
			
#pragma endregion
			}
			//kk状态发生改变了
			else if (changed)
			{
#pragma region 岩层
				CTerraneFeature* pTerraneFeature = dynamic_cast<CTerraneFeature*>(pFeatureItem->getFeature());
				if (pTerraneFeature)
				{
					if (pFeatureItem->get3DBindingObject())
					{
						std::string name =	pFeatureItem->getFeature()->getFieldName();
						VirtualMine::SpatialInterface::GeoObjectVector objVec;

						CTerraneLayer* pLayer = dynamic_cast<CTerraneLayer*>(pFeatureItem->get3DBindingObject());	
						VirtualMine::SpatialRender::CTerraneRenderableObject* renderobject = dynamic_cast<VirtualMine::SpatialRender::CTerraneRenderableObject* >(pLayer->getRenderableObject());
						VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
						renderobject->getGeoExtentionDatas(geoExtenvec);
						int size1 =  renderobject->getExtentionData().size();

						for (int i = 0 ; i < size1; i++)
						{
							VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
							std::string selectname = extentData->getExtentionData()->getName();
							if (name == selectname)
							{					
								extentData->getExtentionData()->setVisible(curCheckstatus);							
							}
						}
						int childCount =  pFeatureItem->childCount();
						if (childCount > 0)
						{
							for (int i = 0; i < childCount; i++)
							{
								pFeatureItem->child(i)->setCheckState(0,curCheckstatus);
							}
						}
					}
				}
#pragma endregion
				CShotHoleFeature* pShotHoleFeature = dynamic_cast<CShotHoleFeature*>(pFeatureItem->getFeature());
				if (pShotHoleFeature)
				{
					int intType = dynamic_cast<VRBangLayerItem*>(pFeatureItem->parent())->getIntType();				
#pragma region 炮眼设计
					if (intType == 3)
					{

						std::set<int> holeIDVec;
						std::vector<std::string> tyVector;
						if (pFeatureItem->get3DBindingObject())
						{
							std::string name =	pShotHoleFeature->getFieldName();
							std::string type = pShotHoleFeature->getFieldType();
							VirtualMine::SpatialInterface::GeoObjectVector objVec;

							CShotHoleLayer* pLayer = dynamic_cast<CShotHoleLayer*>(pFeatureItem->get3DBindingObject());	
							VirtualMine::BaseRender::CPipeLine* renderobject = dynamic_cast<VirtualMine::BaseRender::CPipeLine* >(pLayer->getRenderableObject());									
							VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
							renderobject->getGeoExtentionDatas(geoExtenvec);
							int size1 =  renderobject->getExtentionData().size();

							for (int i = 0 ; i < size1; i++)
							{
								VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
								std::string boomType = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomType();
								int boomID = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomID();
								if (boomType == type)
								{
									holeIDVec.insert(boomID);
									renderobject->getGeoObject(i)->setVisible(curCheckstatus);
									extentData->getExtentionData()->setVisible(curCheckstatus);

									std::string leftfrontfirstline="left"+type+"frontfirstline";
									std::string leftfrontsecondline="left"+type+"frontsecondline";
									std::string leftfrontthirdline="left"+type+"frontthirdline";
									std::string leftmidfirstline="left"+type+"midfirstline";
									std::string leftmidsecondline="left"+type+"midsecondline";
									std::string leftmidthirdline="left"+type+"midthirdline";

									std::string overfrontfirstline="over"+type+"frontfirstline";
									std::string overfrontsecondline="over"+type+"frontsecondline";
									std::string overfrontthirdline="over"+type+"frontthirdline";
									std::string overbackfirstline="over"+type+"backfirstline";
									std::string overbacksecondline="over"+type+"backsecondline";
									std::string overbackthirdline="over"+type+"backthirdline";
									tyVector.push_back(leftfrontfirstline);
									tyVector.push_back(leftfrontsecondline);
									tyVector.push_back(leftfrontthirdline);
									tyVector.push_back(leftmidfirstline);
									tyVector.push_back(leftmidsecondline);
									tyVector.push_back(leftmidthirdline);

									tyVector.push_back(overfrontfirstline);
									tyVector.push_back(overfrontsecondline);
									tyVector.push_back(overfrontthirdline);
									tyVector.push_back(overbackfirstline);
									tyVector.push_back(overbacksecondline);
									tyVector.push_back(overbackthirdline);															
								}							
							}
							CRefreshMapEvent refreshMapEvt;
							CEventDispatcher::setEvent(&refreshMapEvt);					   						   
							int childCount =  pFeatureItem->childCount();
							if (childCount > 0)
							{
								for (int i = 0; i < childCount; i++)
								{
									pFeatureItem->child(i)->setCheckState(0,curCheckstatus);
								}
							}

						}
						//二维炮眼
						if (pFeatureItem->parent())
						{
							VRBangLayerItem* pParent = (VRBangLayerItem*)(pFeatureItem->parent());
							if (!pParent->get2DBindingObject())
							{
								return;
							}
							std::string holetype = pShotHoleFeature->getFieldType();				
							C2DShotHoleLayer* p2DLayer = dynamic_cast<C2DShotHoleLayer*>(pParent->get2DBindingObject());

							int idSize = holeIDVec.size();
							std::set<int>::iterator itr = holeIDVec.begin();
							while(itr != holeIDVec.end())
							{
								int id = *itr;
								std::string idName = Ogre::StringConverter::toString(id);

								VirtualMine::Map::CPointDrawItem* pItem = dynamic_cast<VirtualMine::Map::CPointDrawItem*>(p2DLayer->getGeometryItem(idName));
								if (pItem)
								{
									pItem->setVisible(curCheckstatus);					
								}
								itr++;
							}
							for (int i=0;i<tyVector.size();++i)
							{						
								VirtualMine::Map::CLineDrawItem* pItem = dynamic_cast<VirtualMine::Map::CLineDrawItem*>(p2DLayer->getGeometryItem(tyVector.at(i)));
								if (pItem)
								{
									pItem->setVisible(curCheckstatus);										
								}															
							}
							CRefreshMapEvent refreshMapEvt;
							CEventDispatcher::setEvent(&refreshMapEvt);
						}
					}
#pragma endregion
#pragma region 起爆顺序
					else if (intType == 4)
					{
						std::set<int> bangOrdertoIDVec; ///只记录起爆ID，未记录对应的炮眼id
						if (pFeatureItem->get3DBindingObject())
						{
							std::string name =	pShotHoleFeature->getFieldName();
							std::string type = pShotHoleFeature->getFieldType();

							int bangOrder = pShotHoleFeature->getFieldBangOrder();
							VirtualMine::SpatialInterface::GeoObjectVector objVec;

							CShotHoleLayer* pLayer = dynamic_cast<CShotHoleLayer*>(pFeatureItem->get3DBindingObject());	
							VirtualMine::BaseRender::CPipeLine* renderobject = dynamic_cast<VirtualMine::BaseRender::CPipeLine* >(pLayer->getRenderableObject());

							VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
							renderobject->getGeoExtentionDatas(geoExtenvec);
							int size1 =  renderobject->getExtentionData().size();

							for (int i = 0 ; i < size1; i++)
							{
								VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
								int  boomOrder = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomOrder();
								int  boomID = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomID();

								if (boomOrder == bangOrder)
								{
									bangOrdertoIDVec.insert(boomOrder);
									renderobject->getGeoObject(i)->setVisible(curCheckstatus);
									extentData->getExtentionData()->setVisible(curCheckstatus);
								}					
							}					  					
						}
						///2维
						if (pFeatureItem->parent())
						{
							VRBangLayerItem* pParent = (VRBangLayerItem*)(pFeatureItem->parent());
							if (!pParent->get2DBindingObject())
							{
								return;
							}
							int bangOrder = pShotHoleFeature->getFieldBangOrder();					
							C2DShotHoleLayer* p2DLayer = dynamic_cast<C2DShotHoleLayer*>(pParent->get2DBindingObject());

							int idSize = bangOrdertoIDVec.size();
							std::set<int>::iterator itr = bangOrdertoIDVec.begin();
							while(itr != bangOrdertoIDVec.end())
							{
								int id = *itr;
								std::string idName = Ogre::StringConverter::toString(id);
								std::string boomName="lianxian"+idName;
								idName = "boomline" + idName;			
								VirtualMine::Map::CLineDrawItem* pItem = dynamic_cast<VirtualMine::Map::CLineDrawItem*>(p2DLayer->getGeometryItem(idName));
								if (pItem)
								{
									pItem->setVisible(curCheckstatus);
								}
								VirtualMine::Map::CTextDrawItem* pItem2 = dynamic_cast<VirtualMine::Map::CTextDrawItem*>(p2DLayer->getGeometryItem(boomName));
								if (pItem2)
								{
									pItem2->setVisible(curCheckstatus);
								}
								itr++;
							}					
							CRefreshMapEvent refreshMapEvt;
							CEventDispatcher::setEvent(&refreshMapEvt);						
						}			
					}
#pragma endregion
				}

			}

#if 1	子节点全选，父节点也全选
			if (pFeatureItem->parent())
			{
				VRBangLayerItem* pLayerParaent = dynamic_cast<VRBangLayerItem*>(pFeatureItem->parent());
				if (pLayerParaent == NULL)
				{
					return;
				}
				int childCount = pLayerParaent->childCount();
				bool parentCheck = true;
				bool parentUnCheck = false;
				if (childCount > 0)
				{
					for (int i = 0; i < childCount; i++)
					{
						bool childCheck  = false;
						Qt::CheckState checkState = pLayerParaent->child(i)->checkState(0);
						if (checkState == Qt::CheckState::Checked)
						{
							childCheck = true;
						}
						else
						{
							childCheck = false;
						}
						parentCheck &= childCheck;
						parentUnCheck |= childCheck;
					}
					if (parentCheck == true)
					{
						pLayerParaent->setCheckState(0,Qt::CheckState::Checked);
					}
					else if (parentUnCheck == false)
					{
						pLayerParaent->setCheckState(0,Qt::CheckState::Unchecked);
					}
					else
					{
						pLayerParaent->setCheckState(0,Qt::CheckState::PartiallyChecked);
					}
				}

			}


#endif
		}
   }
  // oldholeIDVector->clear();
 
   //kk如果重复点击同一item就不重复放入到tablewidget中
   if (this->myInfoVec !=exportInfoVec)
   {
	   cout<<"**********************进入了改变范围"<<endl;
	   this->myInfoVec = exportInfoVec;
	   this->setTableItem(this->mytablewidget,exportInfoVec);
   }  
   
   //kk
   /* CExportInfoEvent eventExport;
   eventExport.setInfo(exportInfoVec);
   CEventDispatcher::setEvent(&eventExport);*/


}
//根据类型获取左视图和俯视图的三段线vector
std::vector<std::string> VTBangDataSourceTreeWidget::leftovershotVector(const std::string& type,std::vector<std::string>& sVector )
{
	std::string leftfrontfirstline="left"+type+"frontfirstline";
	std::string leftfrontsecondline="left"+type+"frontsecondline";
	std::string leftfrontthirdline="left"+type+"frontthirdline";
	std::string leftmidfirstline="left"+type+"midfirstline";
	std::string leftmidsecondline="left"+type+"midsecondline";
	std::string leftmidthirdline="left"+type+"midthirdline";

	std::string overfrontfirstline="over"+type+"frontfirstline";
	std::string overfrontsecondline="over"+type+"frontsecondline";
	std::string overfrontthirdline="over"+type+"frontthirdline";
	std::string overbackfirstline="over"+type+"backfirstline";
	std::string overbacksecondline="over"+type+"backsecondline";
	std::string overbackthirdline="over"+type+"backthirdline";
	sVector.push_back(leftfrontfirstline);
	sVector.push_back(leftfrontsecondline);
	sVector.push_back(leftfrontthirdline);
	sVector.push_back(leftmidfirstline);
	sVector.push_back(leftmidsecondline);
	sVector.push_back(leftmidthirdline);

	sVector.push_back(overfrontfirstline);
	sVector.push_back(overfrontsecondline);
	sVector.push_back(overfrontthirdline);
	sVector.push_back(overbackfirstline);
	sVector.push_back(overbacksecondline);
	sVector.push_back(overbackthirdline);

	return sVector;
}

void VTBangDataSourceTreeWidget::mousePressEvent( QMouseEvent *event )
{
	QPoint point = QCursor::pos();
	point = mapFromGlobal(point);
	QTreeWidgetItem *item = this->itemAt(point);
	if (item)
	{
		VRBangLayerItem* pLayerItem = dynamic_cast<VRBangLayerItem*>(item);
		if (pLayerItem)
		{
#if 1  隐藏其他图层
			int intType = pLayerItem->getIntType();
			//kk
			if (intType == 1 || intType == 5 || intType == 7)
			{
				if (this->mpPrivate->mpSectionItem)
				{
					this->mpPrivate->mpSectionItem->setCheckState(0,Qt::CheckState::Unchecked);
					if (this->mpPrivate->mpSectionItem->get3DBindingObject())
					{
						this->mpPrivate->mpSectionItem->get3DBindingObject()->setVisible(false);
					}
					if (this->mpPrivate->mpSectionItem->get2DBindingObject())
					{
						C2DLanewaySectionLayer* Layer2D=dynamic_cast<C2DLanewaySectionLayer*>(this->mpPrivate->mpSectionItem->get2DBindingObject());
						Layer2D->setVisibled(false);
						//this->mpPrivate->mpShotHoleItem->get2DBindingObject()->setVisible(false);	
					}
				}
				if (this->mpPrivate->mpShotHoleItem)
				{
					this->mpPrivate->mpShotHoleItem->setCheckState(0,Qt::CheckState::Unchecked);
					if (this->mpPrivate->mpShotHoleItem->get3DBindingObject())
					{
						this->mpPrivate->mpShotHoleItem->get3DBindingObject()->setVisible(false);					
			
					}
					if (this->mpPrivate->mpShotHoleItem->get2DBindingObject())
					{
						C2DShotHoleLayer* Layer2D=dynamic_cast<C2DShotHoleLayer*>(this->mpPrivate->mpShotHoleItem->get2DBindingObject());
						Layer2D->setVisibled(false);
						//this->mpPrivate->mpShotHoleItem->get2DBindingObject()->setVisible(false);	
					}
					int childCount =  this->mpPrivate->mpShotHoleItem->childCount();
					if (childCount > 0)
					{
						for (int i = 0; i < childCount; i++)
						{
							this->mpPrivate->mpShotHoleItem->child(i)->setCheckState(0,Qt::CheckState::Unchecked);
						}
					}
				}
				if (this->mpPrivate->mpFireOrderItem)
				{
					this->mpPrivate->mpFireOrderItem->setCheckState(0,Qt::CheckState::Unchecked);
					if (this->mpPrivate->mpFireOrderItem->get3DBindingObject())
					{
						this->mpPrivate->mpFireOrderItem->get3DBindingObject()->setVisible(false);
					}
					if (this->mpPrivate->mpShotHoleItem->get2DBindingObject())
					{
						C2DShotHoleLayer* Layer2D=dynamic_cast<C2DShotHoleLayer*>(this->mpPrivate->mpShotHoleItem->get2DBindingObject());
						Layer2D->setVisibled(false);
						//this->mpPrivate->mpShotHoleItem->get2DBindingObject()->setVisible(false);
					}
					int childCount =  this->mpPrivate->mpFireOrderItem->childCount();
					if (childCount > 0)
					{
						for (int i = 0; i < childCount; i++)
						{
							this->mpPrivate->mpFireOrderItem->child(i)->setCheckState(0,Qt::CheckState::Unchecked);
						}
					}
				}
			}
			if (intType == 3 || intType == 4 || intType == 2)
			{
			    if (this->mpPrivate->mpRockItem)
			    {
					this->mpPrivate->mpRockItem->setCheckState(0,Qt::CheckState::Unchecked);

					if (this->mpPrivate->mpRockItem->get3DBindingObject())
					{
						this->mpPrivate->mpRockItem->get3DBindingObject()->setVisible(false);
					}
					int childCount =  this->mpPrivate->mpRockItem->childCount();
					if (childCount > 0)
					{
						for (int i = 0; i < childCount; i++)
						{
							this->mpPrivate->mpRockItem->child(i)->setCheckState(0,Qt::CheckState::Unchecked);
						}
					}	
			    }
				if (this->mpPrivate->mpEvacuationRouteItem)
				{

					this->mpPrivate->mpEvacuationRouteItem->setCheckState(0,Qt::CheckState::Unchecked);
				    if (this->mpPrivate->mpEvacuationRouteItem->get3DBindingObject())
				    {
						this->mpPrivate->mpEvacuationRouteItem->get3DBindingObject()->setVisible(false);
				    }
					int childCount =  this->mpPrivate->mpEvacuationRouteItem->childCount();
					if (childCount > 0)
					{
						for (int i = 0; i < childCount; i++)
						{
							this->mpPrivate->mpEvacuationRouteItem->child(i)->setCheckState(0,Qt::CheckState::Unchecked);
						}
					}
				}
				//kk
				if (this->mpPrivate->mpConstructionProgressItem)
				{

					this->mpPrivate->mpConstructionProgressItem->setCheckState(0,Qt::CheckState::Unchecked);
					if (this->mpPrivate->mpConstructionProgressItem->get3DBindingObject())
					{
						this->mpPrivate->mpConstructionProgressItem->get3DBindingObject()->setVisible(false);
					}
					int childCount =  this->mpPrivate->mpConstructionProgressItem->childCount();
					if (childCount > 0)
					{
						for (int i = 0; i < childCount; i++)
						{
							this->mpPrivate->mpConstructionProgressItem->child(i)->setCheckState(0,Qt::CheckState::Unchecked);
						}
					}
				}
		
			}

#endif	
			//pLayerItem->get3DBindingObject()->getGeoObjects();
			CBangLayerFlyToSceneEvent flyToSceneEvt;
			flyToSceneEvt.set3DLayer(pLayerItem->get3DBindingObject());
			CEventDispatcher::setEvent(&flyToSceneEvt);
		}
		VRBangFeatureItem* pFeatureItem = dynamic_cast<VRBangFeatureItem*>(item);
		if (pFeatureItem)
		{
			//pFeatureItem->get3DBindingObject()->getGeoObjects();

			 pFeatureItem->getFeature();
			 VRBangLayerItem* pParaent = dynamic_cast<VRBangLayerItem*>(pFeatureItem->parent());
			 if (pParaent == NULL)
			 {
				 return;
			 }
#if 1  隐藏其他图层
			 int intType = pParaent->getIntType();
			 //kk
			 if (intType == 1 || intType == 5 || intType == 7)
			 {
				 if (this->mpPrivate->mpSectionItem)
				 {
					 this->mpPrivate->mpSectionItem->setCheckState(0,Qt::CheckState::Unchecked);
					 if (this->mpPrivate->mpSectionItem->get3DBindingObject())
					 {
						 this->mpPrivate->mpSectionItem->get3DBindingObject()->setVisible(false);
					   						
					 }
					 if (this->mpPrivate->mpSectionItem->get2DBindingObject())
					 {
						 C2DLanewaySectionLayer* Layer2D=dynamic_cast<C2DLanewaySectionLayer*>(this->mpPrivate->mpSectionItem->get2DBindingObject());
						 Layer2D->setVisibled(false);
						 //this->mpPrivate->mpShotHoleItem->get2DBindingObject()->setVisible(false);	
					 }
				 }
				 if (this->mpPrivate->mpShotHoleItem)
				 {
					 this->mpPrivate->mpShotHoleItem->setCheckState(0,Qt::CheckState::Unchecked);
					 if (this->mpPrivate->mpShotHoleItem->get3DBindingObject())
					 {
						 this->mpPrivate->mpShotHoleItem->get3DBindingObject()->setVisible(false);
					 }
					 if (this->mpPrivate->mpShotHoleItem->get2DBindingObject())
					 {
						 C2DShotHoleLayer* Layer2D=dynamic_cast<C2DShotHoleLayer*>(this->mpPrivate->mpShotHoleItem->get2DBindingObject());
						 Layer2D->setVisibled(false);
						 //this->mpPrivate->mpShotHoleItem->get2DBindingObject()->setVisible(false);
					 }
					 int childCount =  this->mpPrivate->mpShotHoleItem->childCount();
					 if (childCount > 0)
					 {
						 for (int i = 0; i < childCount; i++)
						 {
							 this->mpPrivate->mpShotHoleItem->child(i)->setCheckState(0,Qt::CheckState::Unchecked);
						 }
					 }
				 }
				 if (this->mpPrivate->mpFireOrderItem)
				 {
					 this->mpPrivate->mpFireOrderItem->setCheckState(0,Qt::CheckState::Unchecked);
					 if (this->mpPrivate->mpFireOrderItem->get3DBindingObject())
					 {
						 this->mpPrivate->mpFireOrderItem->get3DBindingObject()->setVisible(false);
					 }
					 if (this->mpPrivate->mpShotHoleItem->get2DBindingObject())
					 {
						 C2DShotHoleLayer* Layer2D=dynamic_cast<C2DShotHoleLayer*>(this->mpPrivate->mpShotHoleItem->get2DBindingObject());
						 Layer2D->setVisibled(false);
						 //this->mpPrivate->mpShotHoleItem->get2DBindingObject()->setVisible(false);
					 }
					 int childCount =  this->mpPrivate->mpFireOrderItem->childCount();
					 if (childCount > 0)
					 {
						 for (int i = 0; i < childCount; i++)
						 {
							 this->mpPrivate->mpFireOrderItem->child(i)->setCheckState(0,Qt::CheckState::Unchecked);
						 }
					 }
				 }
			 }
			 if (intType == 3 || intType == 4 || intType == 2)
			 {
				 if (this->mpPrivate->mpRockItem)
				 {
					 this->mpPrivate->mpRockItem->setCheckState(0,Qt::CheckState::Unchecked);

					 if (this->mpPrivate->mpRockItem->get3DBindingObject())
					 {
						 this->mpPrivate->mpRockItem->get3DBindingObject()->setVisible(false);
					 }
					 int childCount =  this->mpPrivate->mpRockItem->childCount();
					 if (childCount > 0)
					 {
						 for (int i = 0; i < childCount; i++)
						 {
							 this->mpPrivate->mpRockItem->child(i)->setCheckState(0,Qt::CheckState::Unchecked);
						 }
					 }	
				 }
				 if (this->mpPrivate->mpEvacuationRouteItem)
				 {

					 this->mpPrivate->mpEvacuationRouteItem->setCheckState(0,Qt::CheckState::Unchecked);
					 if (this->mpPrivate->mpEvacuationRouteItem->get3DBindingObject())
					 {
						 this->mpPrivate->mpEvacuationRouteItem->get3DBindingObject()->setVisible(false);
					 }
					 int childCount =  this->mpPrivate->mpEvacuationRouteItem->childCount();
					 if (childCount > 0)
					 {
						 for (int i = 0; i < childCount; i++)
						 {
							 this->mpPrivate->mpEvacuationRouteItem->child(i)->setCheckState(0,Qt::CheckState::Unchecked);
						 }
					 }
				 }
				 //kk
				 if (this->mpPrivate->mpConstructionProgressItem)
				 {

					 this->mpPrivate->mpConstructionProgressItem->setCheckState(0,Qt::CheckState::Unchecked);
					 if (this->mpPrivate->mpConstructionProgressItem->get3DBindingObject())
					 {
						 this->mpPrivate->mpConstructionProgressItem->get3DBindingObject()->setVisible(false);
					 }
					 int childCount =  this->mpPrivate->mpConstructionProgressItem->childCount();
					 if (childCount > 0)
					 {
						 for (int i = 0; i < childCount; i++)
						 {
							 this->mpPrivate->mpConstructionProgressItem->child(i)->setCheckState(0,Qt::CheckState::Unchecked);
						 }
					 }
				 }

			 }

#endif	

			CBangLayerFlyToSceneEvent flyToSceneEvt;
			flyToSceneEvt.set3DLayer(pFeatureItem->get3DBindingObject());
			CEventDispatcher::setEvent(&flyToSceneEvt);
		}


#if 0

		VRBangLayerItem* pLayerItem = dynamic_cast<VRBangLayerItem*>(item);
		if (pLayerItem)
		{
			int layerType = pLayerItem->getIntType();
#if 1 岩层参数

			if (layerType==1)
			{

				{




					///2维
					if (pLayerItem->get2DBindingObject())
					{
						pLayerItem->get2DBindingObject()->setVisible(curCheckstatus);


						CRefreshMapEvent refreshMapEvt;
						CEventDispatcher::setEvent(&refreshMapEvt);
					}


				}

			}

#endif
#if 炮眼图层item

			else if (layerType == 3)////炮眼
			{
				Qt::CheckState oldCheckstatus = item->checkState(0);
				QTreeWidget::mouseReleaseEvent(event);
				Qt::CheckState curCheckstatus = item->checkState(0);
				bool changed = (oldCheckstatus != curCheckstatus);
				///2维
				if (changed)
				{
					if (pLayerItem->get2DBindingObject())
					{
						std::set<int> holeset;
						std::set<std::string> typeSet;
						if (pLayerItem->get3DBindingObject())
						{
							pLayerItem->get3DBindingObject()->setVisible(curCheckstatus);
							VirtualMine::SpatialInterface::GeoObjectVector objVec;

							CShotHoleLayer* pLayer = dynamic_cast<CShotHoleLayer*>(pLayerItem->get3DBindingObject());	
							VirtualMine::BaseRender::CPipeLine* renderobject = dynamic_cast<VirtualMine::BaseRender::CPipeLine* >(pLayer->getRenderableObject());

							VirtualMine::SpatialInterface::GeoExtentionDataVector geoExtenvec;
							renderobject->getGeoExtentionDatas(geoExtenvec);
							int size1 =  renderobject->getExtentionData().size();

							for (int i = 0 ; i < size1; i++)
							{
								VirtualMine::SpatialInterface::CGeoExtentionData* extentData  =  renderobject->getExtentionData().at(i);
								//std::string boomtype = dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomType();
								int bangID= dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomID();							
								std::string bangType= dynamic_cast<CPipeLineStyle*>(renderobject->getGeoObject(i)->getStyle())->getBoomType();
								holeset.insert(bangID);	
								typeSet.insert(bangType);
							}					
						}	
						std::set<int>::iterator IDItr = holeset.begin();
						std::string markName="MarkText";
						while(IDItr != holeset.end())
						{
							int ID = *IDItr;
							std::string holeName =Ogre::StringConverter::toString(ID);
							C2DShotHoleLayer* p2Dlayer = dynamic_cast<C2DShotHoleLayer*>(pLayerItem->get2DBindingObject());
							dynamic_cast<CPointDrawItem*>(p2Dlayer->getGeometryItem(holeName))->setVisible(curCheckstatus);
							dynamic_cast<CTextDrawItem*>(p2Dlayer->getGeometryItem(markName))->setVisible(curCheckstatus);
							IDItr++;
						}
						std::set<std::string>::iterator typeItr = typeSet.begin();
						while(typeItr != typeSet.end())
						{
							std::string boName=*typeItr;
							std::string leftfrontfirstline="left"+boName+"frontfirstline";
							std::string leftfrontsecondline="left"+boName+"frontsecondline";
							std::string leftfrontthirdline="left"+boName+"frontthirdline";
							std::string leftmidfirstline="left"+boName+"midfirstline";
							std::string leftmidsecondline="left"+boName+"midsecondline";
							std::string leftmidthirdline="left"+boName+"midthirdline";

							std::string overfrontfirstline="over"+boName+"frontfirstline";
							std::string overfrontsecondline="over"+boName+"frontsecondline";
							std::string overfrontthirdline="over"+boName+"frontthirdline";
							std::string overbackfirstline="over"+boName+"backfirstline";
							std::string overbacksecondline="over"+boName+"backsecondline";
							std::string overbackthirdline="over"+boName+"backthirdline";

							C2DShotHoleLayer* p2Dlayer = dynamic_cast<C2DShotHoleLayer*>(pLayerItem->get2DBindingObject());
							dynamic_cast<CLineDrawItem*>(p2Dlayer->getGeometryItem(leftfrontfirstline))->setVisible(curCheckstatus);
							dynamic_cast<CLineDrawItem*>(p2Dlayer->getGeometryItem(leftfrontsecondline))->setVisible(curCheckstatus);
							dynamic_cast<CLineDrawItem*>(p2Dlayer->getGeometryItem(leftfrontthirdline))->setVisible(curCheckstatus);
							dynamic_cast<CLineDrawItem*>(p2Dlayer->getGeometryItem(leftmidfirstline))->setVisible(curCheckstatus);
							dynamic_cast<CLineDrawItem*>(p2Dlayer->getGeometryItem(leftmidsecondline))->setVisible(curCheckstatus);
							dynamic_cast<CLineDrawItem*>(p2Dlayer->getGeometryItem(leftmidthirdline))->setVisible(curCheckstatus);

							dynamic_cast<CLineDrawItem*>(p2Dlayer->getGeometryItem(overfrontfirstline))->setVisible(curCheckstatus);
							dynamic_cast<CLineDrawItem*>(p2Dlayer->getGeometryItem(overfrontsecondline))->setVisible(curCheckstatus);
							dynamic_cast<CLineDrawItem*>(p2Dlayer->getGeometryItem(overfrontthirdline))->setVisible(curCheckstatus);
							dynamic_cast<CLineDrawItem*>(p2Dlayer->getGeometryItem(overbackfirstline))->setVisible(curCheckstatus);
							dynamic_cast<CLineDrawItem*>(p2Dlayer->getGeometryItem(overbacksecondline))->setVisible(curCheckstatus);
							dynamic_cast<CLineDrawItem*>(p2Dlayer->getGeometryItem(overbackthirdline))->setVisible(curCheckstatus);
							typeItr++;
						}					
					}
					CRefreshMapEvent refreshMapEvt;
					CEventDispatcher::setEvent(&refreshMapEvt);
					int childCount =  pLayerItem->childCount();
					if (childCount > 0)
					{
						for (int i = 0; i < childCount; i++)
						{
							pLayerItem->child(i)->setCheckState(0,curCheckstatus);
						}

					}

				}

			}

#endif


			else if (layerType == 4)////起爆顺序

#endif





	}

	QTreeWidget::mousePressEvent(event);
}

void VTBangDataSourceTreeWidget::slotItemPress()
{
	
	{
		int i = 0;
	}
}


