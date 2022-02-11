#include "bang_ForUI/openprojectdlg.h"
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_openprojectdlg.h"
#include "string"
#include <QTableWidgetItem>
#include "qtablewidget.h"
using namespace  std;
using namespace Bang;


COpenprojectdlg::COpenprojectdlg( QWidget *parent /*= 0*/, Qt::WFlags flags /*= 0*/)
	: QDialog(parent, flags)
{
	this->ui = new Ui::openProjectForm();
	ui->setupUi(this);
    ref_mpSqliteDatabase = NULL;
    connect(ui->onOKPushButton,SIGNAL(clicked()),this,SLOT(slotOnOK()));
	connect(ui->tableWidget,SIGNAL(itemPressed(QTableWidgetItem*)),this,SLOT(slotGetProItem(QTableWidgetItem*)));

}


//void COpenprojectdlg::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl)
//{
//	this->ref_mpControl = ref_pGeoSpatialControl;
//}
//VirtualMine::Scene::CGeoSpatialControl* COpenprojectdlg::getGeoSpatialControl()
//{
//	return this->ref_mpControl;
//}

COpenprojectdlg::~COpenprojectdlg()
{

}


void Bang::COpenprojectdlg::initial()
{


	if (ref_mpSqliteDatabase == NULL)
	{
		return;
	}

	QTextCodec *codec = QTextCodec::codecForName("GBK");
	//QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QTextCodec::setCodecForTr(codec);
	QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
	QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
	ui->tableWidget->clear();

	VirtualMine::Database::CLogicDataset* pLogicDataset = ref_mpSqliteDatabase->queryLogicDataset();
	int count = pLogicDataset->getCount();
	std::string datesetName;
	for (int i = 0; i < count; i++)
	{
		std::string type = dynamic_cast<VirtualMine::Database::CLogicFeature*>(pLogicDataset->getFeature(i))->getFieldType();
		std::string name = dynamic_cast<VirtualMine::Database::CLogicFeature*>(pLogicDataset->getFeature(i))->getFieldName();

		if (type == VirtualMine::Core::GeoDataType::GDT_IMAGE) ///image代表工程文件
		{
			datesetName = name;
			break;
		}
	}
	VirtualMine::Bang_Database::CProjectFileDataset* pProjectFileDataset = ref_mpSqliteDatabase->queryProjectFileDataset(datesetName);
 	if (pProjectFileDataset == NULL)
 	{
		return;
 	}
	 int projectfileCount = pProjectFileDataset->getCount();
	 ui->tableWidget->setColumnCount(9);

	 ui->tableWidget->setRowCount(count);
	 ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//使行选中被显示
	 ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	 // ui->tableWidget->setWindowTitle(QString::fromLocal8Bit(pdrillingdataset->getName().c_str()));  	
	 ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置表中内容不可编辑
	 ui->tableWidget->verticalHeader()->setVisible(false);   //隐藏列表头
	 QStringList header;  
	 header<<"工程ID"<<"工程名称"<<"工程类型"<<"施工管理者"<<"工程期限"<<"开工时间"<<"设计单位"<<"设计者"<<"断面类型";  
	 ui->tableWidget->setHorizontalHeaderLabels(header);  

	 for (int i = 0 ; i < projectfileCount; i++)
	 {
		 VirtualMine::Bang_Database::CProjectFileFeature* pProjectFileFeature = dynamic_cast< VirtualMine::Bang_Database::CProjectFileFeature* >(pProjectFileDataset->getFeature(i));
		 int projectID = pProjectFileFeature->getFieldID();
		 std::string projectName = pProjectFileFeature->getFieldName();
		 std::string projectType = pProjectFileFeature->getFieldType();
		 std::string projectManager = pProjectFileFeature->getFieldManager();
		 std::string projectDesigner  =	pProjectFileFeature->getFieldDesigner();
		 std::string projectDesignerOrgination = pProjectFileFeature->getFieldDesignerOrginazation();
		 std::string projectPeriod = pProjectFileFeature->getFieldProjectPeriod();
		 std::string projectStartTime =	pProjectFileFeature->getFieldStartTime();
		 int projectSection = pProjectFileFeature->getFieldLanewayWindType();

		 ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(projectID)));  
		 ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(projectName)));  
		 ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::fromStdString(projectType)));  
		 ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::fromStdString(projectManager)));  
		 ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::fromStdString(projectPeriod)));  
		 ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::fromStdString(projectStartTime)));  
		 ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::fromStdString(projectDesignerOrgination)));  
		 ui->tableWidget->setItem(i,7,new QTableWidgetItem(QString::fromStdString(projectDesigner)));  
		 ui->tableWidget->setItem(i,8,new QTableWidgetItem(QString::number(projectSection)));  

	 }

	 //ui->tableWidget->show();
}

int Bang::COpenprojectdlg::getProjectID()
{
	return ui->IDlineEdit->text().toInt();
}

void Bang::COpenprojectdlg::slotOnOK()
{
	QDialog::accept();
	this->close();
}

VirtualMine::Bang_Database::CBangSqliteDatabase* Bang::COpenprojectdlg::getDatabase()
{
	return ref_mpSqliteDatabase;
}

void Bang::COpenprojectdlg::setDatabse(VirtualMine::Bang_Database::CBangSqliteDatabase* pDatabase )
{
	ref_mpSqliteDatabase = pDatabase;
}


void Bang::COpenprojectdlg::slotGetProItem(QTableWidgetItem* item)
{
		
	item = this->ui->tableWidget->item(item->row(),0);
	this->ui->IDlineEdit->setText(item->text());

	item = this->ui->tableWidget->item(item->row(),1);
	this->ui->nameLineEdit->setText(item->text());


}

	
