#ifndef VR_DATASOURCETREEWIDGET_H
#define VR_DATASOURCETREEWIDGET_H
//定义插件导出符号
#ifndef QVRDATASOURCETREE_EXPORT_WIDGETS
#define VRDATASOURCECONTORL_DLL _declspec(dllimport)
#else
#define VRDATASOURCECONTORL_DLL _declspec(dllexport)
#endif

#include <QtGui/QWidget>
#include <QTreeWidget>
#include "vrmine/vr_databaseengine/database/idataset.h"
#include "vrmine/vr_databaseengine/database/idatasourcemanager.h"
#include "vrmine/vr_core/event.h"
#include "vrmine/vr_databaseengine/database/logicfeature.h"
#include "vrmine/vr_core/geodatatype.h"

class VRDataSourceTreeWidget_PrivateData;

class VRDATASOURCECONTORL_DLL VRDataSourceManagerItem : public QTreeWidgetItem
{
public :
	VRDataSourceManagerItem()
	{
		this->mType = VirtualMine::Core::GeoDatabaseType::GDBT_SQLITE;
	};
	virtual ~VRDataSourceManagerItem()
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

class VRDATASOURCECONTORL_DLL VRDataSourceItem : public QTreeWidgetItem
{
public :
	VRDataSourceItem();
	~VRDataSourceItem();
	virtual void bindingObject(VirtualMine::Database::IDataSource* ref_pDataSource);
	virtual VirtualMine::Database::IDataSource* getBindingObject();

protected:
	VirtualMine::Database::IDataSource* ref_mpDataSource;
};

class VRDATASOURCECONTORL_DLL VRDataSetItem : public QTreeWidgetItem
{
public :
	VRDataSetItem();
	~VRDataSetItem();
	virtual void setBindingObject(VirtualMine::Database::CLogicFeature* ref_pBindingObject);
	virtual VirtualMine::Database::CLogicFeature* getBindingObject();
protected :
	VirtualMine::Database::CLogicFeature* ref_mpBindingObject;
};

class VRDATASOURCECONTORL_DLL VRDataSourceTreeWidget : public QTreeWidget
{
	Q_OBJECT
private slots:
	void slotOpenLocalDataSource();
	void slotConnectRemoteServer();
public:
	VRDataSourceTreeWidget(QWidget *parent = 0);
	~VRDataSourceTreeWidget();
	virtual void initialControl();
	virtual void loadDataSource(VirtualMine::Database::IDataSourceManager* pDataSourceMgr);
	virtual void loadDataSource(VirtualMine::Database::IDataSource* pDataSource);
	virtual void loadLogicalFeature(VirtualMine::Database::CLogicFeature* pLogicFeature);
	virtual void unloadDataSource();
	virtual void unLoadItem(QTreeWidgetItem* item);
protected:
	void contextMenuEvent(QContextMenuEvent * event ); 
	void mousePressEvent(QMouseEvent *event);
	virtual std::string getIcon(QTreeWidgetItem* item);
protected:

	VRDataSourceTreeWidget_PrivateData* mpPrivate;
};

class VRDATASOURCECONTORL_DLL CDataSourceLoadHandler : public VirtualMine::Core::CEventHandler
{
public :
	CDataSourceLoadHandler();
	CDataSourceLoadHandler(VRDataSourceTreeWidget* pControl);
	virtual ~CDataSourceLoadHandler();
	virtual bool handleEvent(VirtualMine::Core::CEvent* evt);

private:
	VRDataSourceTreeWidget* ref_mpControl;
};

#endif // VR_DATASOURCETREEWIDGET_H
