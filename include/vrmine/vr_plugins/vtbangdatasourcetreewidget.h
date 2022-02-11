
#ifndef VTBANGDATASOURCETREEWIDGET_H
#define VTBANGDATASOURCETREEWIDGET_H

//定义插件导出符号
#ifndef QBANGDATASOURCETREE_EXPORT_WIDGETS
#define VRBANGDATASOURCETREE_WIDGET_DLL _declspec(dllimport)
#else
#define VRBANGDATASOURCETREE_WIDGET_DLL _declspec(dllexport)
#endif

#include <QtGui/QWidget>
#include <QTreeWidget>
#include "vrmine/vr_databaseengine/database/idataset.h"

#include "vrmine/vr_core/event.h"
#include "vrmine/vr_spatialinterface/ilayer.h"
#include "vrmine/vr_core/geodatatype.h"
#include <QtGui/QTableWidget>
//kk
#include<QHeaderView>
#include <QTreeWidgetItem>
class VTBangDataSourceTreeWidget_PrivateData;
class CBangLayerLoadHandler;
class VRBangLayerItem;
class VRBangFeatureItem;




//kk定义VRBangLayerItem
class VRBANGDATASOURCETREE_WIDGET_DLL VRBangLayerItem : public QTreeWidgetItem
{
public :
	VRBangLayerItem();
	~VRBangLayerItem();

	int getIntType();
	void setIntType(const int& ref_type);
	virtual void setBindingObject(
		VirtualMine::SpatialInterface::ILayer* ref_p2DBindingObject,
		VirtualMine::SpatialInterface::ILayer* ref_p3DBindingObject);
	virtual VirtualMine::SpatialInterface::ILayer* get2DBindingObject();
	virtual VirtualMine::SpatialInterface::ILayer* get3DBindingObject();

protected :
	int mType; 
	VirtualMine::SpatialInterface::ILayer* ref_mp2DBindingObject;
	VirtualMine::SpatialInterface::ILayer* ref_mp3DBindingObject;
};


//kk定义VRBangFeatureItem


class VRBangFeatureItem : public QTreeWidgetItem
{
public :
	VRBangFeatureItem();
	~VRBangFeatureItem();
	virtual void setBindingObject(
		VirtualMine::Database::IFeature* ref_pFeature,
		VirtualMine::SpatialInterface::ILayer* ref_p3DBindingObject);
	virtual VirtualMine::Database::IFeature* getFeature();
	virtual VirtualMine::SpatialInterface::ILayer* get3DBindingObject();
protected :
	VirtualMine::Database::IFeature* ref_mpFeature;
	VirtualMine::SpatialInterface::ILayer* ref_mp3DBindingObject;
};


class VRBANGDATASOURCETREE_WIDGET_DLL VRProjectManagerItem : public QTreeWidgetItem
{
public :
	VRProjectManagerItem()
	{
		this->mType = VirtualMine::Core::GeoDataType::GDT_SHOTHOLE;
	};
	virtual ~VRProjectManagerItem()
	{

	};
	virtual std::string getType()
	{
		return this->mType;

	}
	virtual void setType(const std::string& type)
	{
		this->mType = type;
	}

protected:
	std::string mType;

};

class VRBANGDATASOURCETREE_WIDGET_DLL VRPropertyWidget :  public QTableWidget
{
	Q_OBJECT
public:
public:
	VRPropertyWidget(QWidget *parent = 0)
	{
		IsInitialState = true;
	}
	~VRPropertyWidget(){}
protected slots:
	void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight)
	{
		emit itemDataChanged(topLeft,bottomRight);
	}
public:
signals:
	void itemDataChanged(const QModelIndex &topLeft,
		const QModelIndex &bottomRight);

public:
	bool IsInitialState;
};

class VRBANGDATASOURCETREE_WIDGET_DLL VTBangDataSourceTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	VTBangDataSourceTreeWidget(QWidget *parent = 0);
	~VTBangDataSourceTreeWidget();
	virtual void initialControl();
    virtual QTreeWidgetItem* getItem(const std::string& type); 
	//kk
	void getTableWidget(QTableWidget* tablewidget);
	//kk
	void setTableItem(QTableWidget* tablewidget,std::vector<std::string> InfoVec);




protected:	
	virtual QString getItemIcon(const std::string& type);
	bool handleLayerLoadEvent(VirtualMine::Core::CEvent* evt);


protected:
	void contextMenuEvent(QContextMenuEvent * event ); 
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *  event);
private slots:
	void slotAdd();
	void slotModify();
	void slotDelete();
	void slotCope();
	void slotCut();
	void slotPaste();
	void slotItemPress();
public: 
	bool mIsSelectedCheck;
	//kk
	std::vector<std::string>  myInfoVec;
	//kk
	QTableWidget* mytablewidget;
	//kk VRBangLayerItem
	VRBangLayerItem* pLayerItem ;
	//kk VRBangFeatureItem
	VRBangFeatureItem* pFeatureItem ;
	//kk
	int layerType;
	//kk对应的treewidget的item
	QTreeWidgetItem *item;

private:
	VTBangDataSourceTreeWidget_PrivateData* mpPrivate;
	friend class CBangLayerLoadHandler;
	std::string oldtypename;
	int oldBoomID;
	std::string oldOrverID2D;
	Ogre::ColourValue oldColor;
	Ogre::ColourValue oldorderColor;
	Ogre::ColourValue oColor[100];
	std::set<int> oldholeIDVec;
	std::set<int> curholeIDVec;
	Ogre::ColourValue curColor;
	std::vector<std::string> shortypeVector;
	std::vector<std::string> oldshortypeVector;
	

private:
	std::vector<std::string> leftovershotVector(const std::string& type,std::vector<std::string>& sVector);
};

#endif // VTBANGDATASOURCETREEWIDGET_H
