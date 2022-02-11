

#include "vrmine/vr_generalui/boardinfo.h"
#include <QTextCodec>
#include <QLabel>
#include <QTextBrowser>
#include "ui_boardinfo.h"

namespace VirtualMine
{
	namespace GeneralUI
	{

		CBoardInfoDlg::CBoardInfoDlg(QWidget *parent)
			: QDialog(parent)
		{


			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			this->ui = new Ui::BoardInfo();
			this->ui->setupUi(this);
			this->setWindowFlags(Qt::FramelessWindowHint);//去掉窗口标题栏

			//支持中文
			QTextCodec *codec = QTextCodec::codecForName("GB2312");
			QTextCodec::setCodecForTr(codec);
			QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
			QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());


		}

		CBoardInfoDlg::~CBoardInfoDlg()
		{

		}

		void CBoardInfoDlg::setText(std::string text)
		{
			
			this->ui->infotextEdit->setText(text.c_str());
		}

		void CBoardInfoDlg::mouseMoveEvent(QMouseEvent *e)
		{
			int dx = e->globalX() - last.x();
			int dy = e->globalY() - last.y();

			last = e->globalPos();
			move(x()+dx, y()+dy);
		}

		void CBoardInfoDlg::mouseReleaseEvent(QMouseEvent *e)
		{
			int dx = e->globalX() - last.x();
			int dy = e->globalY() - last.y();

			move(x()+dx, y()+dy);
		}

		void CBoardInfoDlg::mousePressEvent(QMouseEvent *e)
		{
			last = e->globalPos();
		}


	}
}



