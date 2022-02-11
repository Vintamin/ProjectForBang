#ifndef _BOARDINFODLG_H_
#define _BOARDINFODLG_H_


//#include "ui_boardinfo.h"
#include <QtGui/QDialog>
#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QMouseEvent>

namespace Ui
{	
	class BoardInfo;
}

namespace VirtualMine
{ 
	namespace GeneralUI
	{

		class VRGENERALUI_DLL CBoardInfoDlg : public QDialog
		{
			Q_OBJECT

		public:
			CBoardInfoDlg(QWidget *parent = 0);
			~CBoardInfoDlg();
			void setText(std::string text);

		private:
			Ui::BoardInfo* ui;
			QPoint last;

		protected:
			void mousePressEvent(QMouseEvent *e);
			void mouseMoveEvent(QMouseEvent *e);
			void mouseReleaseEvent(QMouseEvent *e);

			void setboardHeight(int boardheight); //设置窗体高度
			void setboardGeo(int x, int y);       //设置窗体位置
		



		};
	}
}

#endif