#ifndef CLOGINDLG_H
#define CLOGINDLG_H


#include <QtGui/QDialog>
#include <QMouseEvent>
#include "bang_configui.h"


namespace Ui
{
	class loginform;
}

namespace Bang
{
	class BANG_VRGENERALUI_DLL CLogindlg : public QDialog
	{
		Q_OBJECT

	public:
		CLogindlg(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CLogindlg();

	private:

		Ui::loginform* ui;
		QPoint last;

		protected slots:
			void on_loginBtn_clicked();   //µÇÂ½
			void on_cancleBtn_clicked();  //ÍË³ö

	protected:
		void mousePressEvent(QMouseEvent *e);
		void mouseMoveEvent(QMouseEvent *e);
		void mouseReleaseEvent(QMouseEvent *e);



	};
}

#endif // LOGINDLG_H
