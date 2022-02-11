#include "vrmine/vr_generalui/localdatasourceDlg.h"
#include "ui_localdatasourceDlg.h"
#include <QDialog>
#include <QFileDialog>
#include <QFile>

namespace VirtualMine
{
	namespace GeneralUI
	{

		CDataSourceConfigDlg::CDataSourceConfigDlg(QWidget *parent)
			:QDialog(parent),mDBPath("")
		{
			this->ui = new Ui::DataSourceConfig_UI();
			this->ui->setupUi(this);
			/*connect(this->ui->SelectAct, SIGNAL(clicked()), this, SLOT(accept()));
			connect(this->ui->handIn,SIGNAL(clicked()),this,SLOT(reject()));*/
		}
		CDataSourceConfigDlg::~CDataSourceConfigDlg()
		{

		}

		void CDataSourceConfigDlg::initial()
		{

		}

		std::string CDataSourceConfigDlg::getDBPath()
		{
			return this->mDBPath;
		}

		std::string CDataSourceConfigDlg::getDBType()
		{
			return this->mDBType;
		}

		/*void CDataSourceConfigDlg::open()
		{

		}*/

		void CDataSourceConfigDlg::slotSelectDataSourcePath()
		{
			QString path;
			QString filter("dataSourceFile (*.vrdb)");//*.vrproj *.xpm *.jpg)
			QString dstFilePath = QFileDialog::getOpenFileName(this, QString("打开本地数据源"), path,filter);
			if (QFile::exists(dstFilePath))
			{
				this->ui->dataSourcePath->setText(dstFilePath);
			}
		}

		void CDataSourceConfigDlg::slotAccept()
		{
			this->mDBPath = this->ui->dataSourcePath->toPlainText().toLocal8Bit().constData();
			this->mDBType = this->ui->dataSourceType->currentText().toLocal8Bit().constData();
			QDialog::accept();
		}


		void CDataSourceConfigDlg::slotCancel()
		{
			QDialog::reject();
		}

	}
}