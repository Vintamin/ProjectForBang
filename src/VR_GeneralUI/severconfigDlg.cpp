#include "vrmine/vr_generalui/severconfigDlg.h"
#include "ui_severconfigDlg.h"
#include "vrmine/vr_projectmanager/project/projectmanager.h"

using namespace VirtualMine::Project;
namespace VirtualMine
{
	namespace GeneralUI
	{
		CSeverConfigDlg::CSeverConfigDlg(QWidget *parent /* = 0 */)
			:QDialog(parent)
		{
			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			setFixedSize(this->width(), this->height());
			this->ui = new Ui::SeverConfigWidget();
			this->ui->setupUi(this);

			connect(ui->okbtn,SIGNAL(pressed()),this,SLOT(slotOk()));
			connect(ui->cancelbtn,SIGNAL(pressed()),this,SLOT(close()));
		}

		CSeverConfigDlg::~CSeverConfigDlg()
		{
			setAttribute (Qt::WA_DeleteOnClose);
		}

		void CSeverConfigDlg::initialize()
		{
			this->ui->typeCbb->setCurrentIndex(0);
			this->ui->severtext->setText(QString::fromStdString(CServerConfigParam::Server));
			this->ui->usertext->setText(QString::fromStdString(CServerConfigParam::User));
			this->ui->passwordtext->setText(QString::fromStdString(CServerConfigParam::Password));
			this->ui->databasetext->setText(QString::fromStdString(CServerConfigParam::DataBase));

			this->ui->simutext->setText(QString::fromStdString(CServerConfigParam::SimuUrl));
			this->ui->switchtext->setText(QString::fromStdString(CServerConfigParam::SwitchUrl));
		}

		void CSeverConfigDlg::slotOk()
		{
			CServerConfigParam::Server = this->ui->severtext->text().toStdString();
			CServerConfigParam::User = this->ui->usertext->text().toStdString();
			CServerConfigParam::Password = this->ui->passwordtext->text().toStdString();
			CServerConfigParam::DataBase = this->ui->databasetext->text().toStdString();

			CServerConfigParam::SimuUrl = this->ui->simutext->text().toStdString();
			CServerConfigParam::SwitchUrl= this->ui->switchtext->text().toStdString();

			this->accept();
		}
	}
}