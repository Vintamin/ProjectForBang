#include "vrmine/vr_generalui/projectlistDlg.h"
#include "ui_projectlistDlg.h"
#include <QDir>
namespace VirtualMine
{
	namespace GeneralUI
	{
		std::string CProjectListDlg::FileName("");

		CProjectListDlg::CProjectListDlg(QWidget *parent /* = 0 */)
			:QDialog(parent)
		{
			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			setFixedSize(this->width(), this->height());
			this->ui = new Ui::ProjectListDlg();
			this->ui->setupUi(this);

			connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(slotOk()));
		}

		CProjectListDlg::~CProjectListDlg()
		{
			setAttribute (Qt::WA_DeleteOnClose);
		}

		void CProjectListDlg::initialize()
		{	
			QString projectPath = QDir::currentPath()+ QString("//data//project");

			QDir proDir(projectPath);
			if(!proDir.exists())
			{
				return;
			}

			proDir.setFilter(QDir::Dirs|QDir::Files);

			QFileInfoList list = proDir.entryInfoList();

			int i = 0;
			do 
			{
				QFileInfo fileInfo = list.at(i);
				QString currentFileName = fileInfo.fileName();
				
				
			    if(currentFileName!="." && currentFileName !=".." && currentFileName.endsWith(".vrproj")) 
				{
					int index;
					index = currentFileName.lastIndexOf(".");  //一般来说，扩展名为最后一个“.”之后的字符；
					currentFileName.truncate(index);//把它cate掉
					this->ui->comboBox->addItem(currentFileName);
				}
				

				i++;
			} 
			while (i<list.size());
			
		}

		void CProjectListDlg::slotOk()
		{
			CProjectListDlg::FileName = this->ui->comboBox->currentText().toStdString();
			QDialog::accept();
		}
	}
}