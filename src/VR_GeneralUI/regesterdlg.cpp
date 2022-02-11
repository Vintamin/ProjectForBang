#include "vrmine/vr_generalui/regesterdlg.h"
#include "ui_registerdlg.h"

#include "vrmine/vr_sqlitedatabase/sqlitedatabase/sqlitedatabasemanager.h"
#include "vrmine/vr_databaseengine/database/idatasourceinfo.h"
#include <Qt\qtextcodec.h>
#include <QMessageBox>

#include "vrmine\vr_mathenine\mathengine\mathcalculator.h"

using namespace VirtualMine::Database;
using namespace VirtualMine::SQLiteDatabase;
using namespace VirtualMine::Core;

namespace VirtualMine
{
	namespace GeneralUI
	{
		CRegisterDlg::CRegisterDlg(QWidget *parent /* = 0 */)
			:QDialog(parent)
		{
			//setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			//setFixedSize(this->width(), this->height());
			
			this->ui = new Ui::registerForm();
			this->ui->setupUi(this);

			//this->ref_mpGeoSpatialControl = NULL;

			connect(ui->okButton,SIGNAL(clicked()),this,SLOT(slotOnOK()));
			connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(slotCancel()));
			//connect(ui->openDatasourceBtn,SIGNAL(clicked()),this,SLOT(slotOpenDatasource()));

			mpSQLiteDB = NULL;
		
		}

		CRegisterDlg::~CRegisterDlg()
		{
			//setAttribute (Qt::WA_DeleteOnClose);

			if (mpSQLiteDB)
			{
				delete mpSQLiteDB;
				mpSQLiteDB = NULL;
			}
		}



		// 		void CRegisterDlg::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl)
		// 		{
		// 			this->ref_mpGeoSpatialControl = ref_pGeoSpatialControl;
		// 		}
		// 
		// 		VirtualMine::Scene::CGeoSpatialControl* CRegisterDlg::getGeoSpatialControl()
		// 		{
		// 			return this->ref_mpGeoSpatialControl;
		// 		}
		std::string CRegisterDlg::getUserName()
		{
			std::string name = this->ui->usrLineEdit->text().toStdString();
			this->mUserName = name;
			return name;
		}
		std::string CRegisterDlg::getPassword()
		{
			std::string psw = this->ui->pwdLineEdit->text().toStdString();
			this->mPassword = psw;

			return psw;
		}



		void CRegisterDlg::slotOnOK()
		{
			QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));//显示中文

			std::string psw = this->ui->pwdLineEdit->text().toStdString();
			this->mPassword = psw;
			std::string name = this->ui->usrLineEdit->text().toStdString();
			this->mUserName = name;

			this->mPasswordConform = this->ui->pwdLineEdit_confirm->text().toStdString();
			if (this->mPasswordConform != this->mPassword)
			{
				QMessageBox::warning(this,tr("警告"),tr("密码不一致！"),tr("确定"));
				return;
			}
			this->openDatasource();
		
			this->registerInfo();

			QDialog::accept();
		}
		void CRegisterDlg::slotCancel()
		{
			QDialog::reject();
		}

		std::string CRegisterDlg::getDatasoureName()
		{
			return	this->mDatabaseName;
		}

		void CRegisterDlg::openDatasource()
		{
			//QTextCodec *codec = QTextCodec::codecForName("UTF-8");
			//QTextCodec::setCodecForTr(codec);
			////QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
			//QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
			//QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

			
			QString curDir = QCoreApplication::applicationDirPath();

			this->mDatabaseName = curDir.toLocal8Bit().constData();//VirtualMine::MathEngine::CMathCalculator::getCurrentDir();


			this->mDatabaseName += "\\data\\userinfo.vrdb";

	



			IDataSourceInfo*  datasourceInfo = new CDatabaseInfo();

			datasourceInfo->setUri(this->mDatabaseName);
			CSQLiteDatabaseManager* manager = new CSQLiteDatabaseManager();
			manager->openDataSource(datasourceInfo);
			mpSQLiteDB = dynamic_cast<CSQLiteDatabase*>(manager->getDataSource());


		}

		void CRegisterDlg::registerInfo()
		{
			if (this->getUserName() == "" || this->getPassword() == "")
			{

				QMessageBox::warning(this,tr("警告"),tr("用户名或密码为空！"),tr("确定"));
			}
			else
			{

#if  1 shujuku
				int resul = 0;

				if (mpSQLiteDB)
				{

					CUserInfoFeature* fea = new CUserInfoFeature();
					fea->setFieldName(this->getUserName());
					fea->setFieldPassword(this->getPassword());

					resul = mpSQLiteDB->insertUserInfoToInfoDataset(fea);
				}

				 if (resul == 101)
				 {
					 QMessageBox::warning(this,tr("提示"),tr("用户注册成功！"),tr("确定"));
				 }

				//this->NamePassword.insert(pair<string,string>(name,psw));


#endif



#if 0 excel

				QString fileName  = VirtualMine::MathEngine::CMathCalculator::getCurrentDir().c_str();
				fileName += "\\data\\userinfo.xls";


				QTextCodec *code = 0;
				code = QTextCodec::codecForName("UTF-8");
				if (0 == code)
				{
					return;
				}
				std::string fileBuffer = code->fromUnicode(fileName).data();
				FILE *fileWrite = fopen(fileBuffer.c_str(), "w");

				QString carryOut = "\n";
				QString tab = "\t";

				std::string content = code->fromUnicode(carryOut + QString(name.c_str()) + tab + QString(psw.c_str()) + carryOut);

				char* readstr;
				QFile file;
				file.open(fileWrite, QIODevice::WriteOnly);
				file.readLine(readstr);
				if (readstr != NULL)
				{

				}

				file.write(content.c_str(), qstrlen(content.c_str()));
				file.close();


#endif

#if 0 txt


				QFile file(curDir.c_str());    

				if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
				{    
					qDebug()<<"Can't open the file!"<<endl;    

				}    



				QTextStream stream(&file);    


				stream.seek(stream.pos());    
				stream.seek(file.size());//将当前读取文件指针移动到文件末尾    


				stream << QObject::trUtf8(name.c_str()) <<  QObject::trUtf8(" ") <<  QObject::trUtf8(psw.c_str()); 

#endif


			}

		}


	}

}