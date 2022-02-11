#include "bang_ForUI/logindlg.h"
#include <QMessageBox>
#include <QWidget>

#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_logindlg.h"

#include "string"
using namespace  std;
using namespace Bang;

CLogindlg::CLogindlg(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	this->ui = new Ui::loginform();
	ui->setupUi(this);

	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QTextCodec::setCodecForTr(codec);
	QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
	QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

	this->setFixedSize( this->width (),this->height ());//固定登陆窗口大小
	this->setWindowFlags(Qt::FramelessWindowHint);//去掉窗口标题栏 

	this->ui->userLineEdit->setText("admin");
	this->ui->passwordLineEdit->setText("123");

	/*std::string name = "admin";
	std::string pwd = "123";*/

}

CLogindlg::~CLogindlg()
{

	
}

void CLogindlg::mouseMoveEvent(QMouseEvent *e)
{
	int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();

	last = e->globalPos();
	move(x()+dx, y()+dy);
}

void CLogindlg::mouseReleaseEvent(QMouseEvent *e)
{
	int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();

	move(x()+dx, y()+dy);
}

void CLogindlg::mousePressEvent(QMouseEvent *e)
{
	last = e->globalPos();
}

void CLogindlg::on_cancleBtn_clicked()
{
	QDialog::reject();
}

void CLogindlg::on_loginBtn_clicked()
{
	if (ui->userLineEdit->text().trimmed()==tr("admin")&&ui->passwordLineEdit->text()==tr("123"))
	{
		QDialog::accept();	
	}
	else
	{
		QString usrinput =ui->userLineEdit->text();
		QString pwdinput = ui->passwordLineEdit->text();

		if (usrinput.isEmpty()|pwdinput.isEmpty())
		{
			if (usrinput.isEmpty())
			{
				QMessageBox::warning(this,tr("警告"),tr(" 请输入用户名!     "),tr("确定"));
			}
			else
			{
				QMessageBox::warning(this,tr("警告"),tr(" 请输入密码!      "),tr("确定"));
			}
		}
		else
		{

			QMessageBox::warning(this,tr("警告"),tr(" 用户名或密码错误!     "),tr("确定"));


			ui->passwordLineEdit->clear();
			ui->passwordLineEdit->setFocus();
		}
	}
}






