#include "vrmine/vr_generalui/peopletraceDlg.h"
#include "ui_peopletraceDlg.h"
#include "vrmine/vr_sqldatabasehelper/vr_sqldatabasehelper.h"


using namespace VirtualMine::DataBaseManager;

namespace VirtualMine
{
	namespace GeneralUI
	{
		CPeopleTraceDlg::CPeopleTraceDlg(QWidget *parent /* = 0 */)
			:QDialog(parent)
		{
			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			setFixedSize(this->width(), this->height());
			this->ui = new Ui::PeopleTraceWidget();
			this->ui->setupUi(this);
			 connect(ui->departmentCbb, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotDepartmentChanged(QString)));
			 connect(ui->showBtn,SIGNAL(pressed()),this,SLOT(slotQuery()));
		}

		CPeopleTraceDlg::~CPeopleTraceDlg()
		{
			setAttribute (Qt::WA_DeleteOnClose);
		}

		void CPeopleTraceDlg::initialize()
		{	
			//ui->departmentCbb->setCurrentIndex(1);
		}

		void CPeopleTraceDlg::slotDepartmentChanged(QString text)
		{
			QString sqlStr = "select * from people_info where [²¿ÃÅ]= '" + text + "'";
			QSqlQuery query = CDataBaseManager::getSingletonPtr()->execSqlString(sqlStr.toStdString());

			ui->nameCbb->clear();
			while (query.next())
			{
				ui->nameCbb->addItem(query.value(1).toString());
			}
		}

		void CPeopleTraceDlg::slotQuery()
		{
			QString beginTime = ui->dateEditStart->text();
			QString endTime = ui->dateEditEnd->text();
			QString department = ui->departmentCbb->currentText();
			QString name = ui->nameCbb->currentText();
			QString sqlStr = "exec UP_Qrytrace_web" + QString(" @beginTime = '") + beginTime +"',@endTime = '" + endTime + "'," +
													"@department = '" + department + "'," + "@name = '" + name + "'";
			QSqlQuery query = CDataBaseManager::getSingletonPtr()->execSqlString(sqlStr.toStdString());

			int count = 0;
			this->ui->traceTable->clearContents();
			while (query.next())
			{
				this->ui->traceTable->setRowCount(count+1); 
				this->ui->traceTable->setRowHeight(count,20);
				QTableWidgetItem *vHeader5 = new QTableWidgetItem(QString::number(count));  
				this->ui->traceTable->setVerticalHeaderItem(count, vHeader5);

				QTableWidgetItem* itemId = new QTableWidgetItem();
				itemId->setText(QString::number(count+1));
				this->ui->traceTable->setItem(count,0,itemId);

				QTableWidgetItem* itemName = new QTableWidgetItem();
				itemName->setText(query.value(2).toString());
				this->ui->traceTable->setItem(count,1,itemName);

				QTableWidgetItem* itemKind = new QTableWidgetItem();
				itemKind->setText(query.value(3).toString());
				this->ui->traceTable->setItem(count,2,itemKind);
				count++;
			}
		}
	}
}