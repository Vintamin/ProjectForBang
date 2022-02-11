#include "vrmine/vr_generalui/locationpropertyDlg.h"
#include "ui_locationpropertyDlg.h"
#include "vrmine/vr_sqldatabasehelper/vr_sqldatabasehelper.h"
#include <Ogre/Ogre.h>

using namespace VirtualMine::DataBaseManager;
using namespace Ogre;
namespace VirtualMine
{
	namespace GeneralUI
	{
		CLocationPropertyDlg::CLocationPropertyDlg(QWidget *parent /* = 0 */)
			:QDialog(parent)
		{
			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			setFixedSize(this->width(), this->height());
			this->ui = new Ui::LocationPropertyWidget();
			this->ui->setupUi(this);
		}

		CLocationPropertyDlg::~CLocationPropertyDlg()
		{
			setAttribute (Qt::WA_DeleteOnClose);
		}

		void CLocationPropertyDlg::initialize()
		{	
			/*std::string execStr("");
			execStr.append("exec chkrealinfo_web ");
			execStr.append("@station_code = ");*/
			//execStr.append(Ogre::StringConverter::parseInt(this->mStationID));
			int sID = Ogre::StringConverter::parseInt(this->mStationID);
			int cID = Ogre::StringConverter::parseInt(this->mCardID);

			 sID = 1;
			 cID = 2;
			//execStr.append(std::string);
			//execStr.append(",@chk_code = ");
			//execStr.append(Ogre::StringConverter::parseInt(this->mCardID));
			//execStr.append(this->mCardID);

			QString str = "exec chkrealinfo_web  @station_code =" + QString::number(sID) + ",@chk_code = " + QString::number(cID);

			QSqlQuery query = CDataBaseManager::getSingletonPtr()->execSqlString(str.toStdString());
			int count = 0;

			QString address("");
			while (query.next())
			{
				this->ui->infosTable->setRowCount(count+1); 
				this->ui->infosTable->setRowHeight(count,20);
				QTableWidgetItem *vHeader5 = new QTableWidgetItem(QString::number(count));  
				this->ui->infosTable->setVerticalHeaderItem(count, vHeader5);

				QTableWidgetItem* itemId = new QTableWidgetItem();
				itemId->setText(QString::number(count+1));
				this->ui->infosTable->setItem(count,0,itemId);

				QTableWidgetItem* itemName = new QTableWidgetItem();
				itemName->setText(query.value(0).toString());
				this->ui->infosTable->setItem(count,1,itemName);

				QTableWidgetItem* itemKind = new QTableWidgetItem();
				itemKind->setText(query.value(1).toString());
				this->ui->infosTable->setItem(count,2,itemKind);

				QTableWidgetItem* itemPos = new QTableWidgetItem();
				itemPos->setText(query.value(6).toString());
				this->ui->infosTable->setItem(count,3,itemPos);

				address = query.value(5).toString();
				count++;
			}

			this->ui->peopleText->setText(QString::number(count));
			this->ui->stationIdText->setText(QString::fromStdString(this->mStationID));
			this->ui->cardIdText->setText(QString::fromStdString(this->mCardID));
			this->ui->addressText->setText(address);
		}

		void CLocationPropertyDlg::setID(const std::string& stationID,const std::string& cardID)
		{
			this->mStationID = stationID;
			this->mCardID = cardID;
		}
	}
}