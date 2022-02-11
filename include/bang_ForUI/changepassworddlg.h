#ifndef CHANGEPASSWORDDLG_H
#define CHANGEPASSWORDDLG_H


#include <QtGui/QDialog>
#include "bang_configui.h"



namespace Ui
{
	class changePasswordForm;
}
namespace Bang
{
	class BANG_VRGENERALUI_DLL CChangePasswordDlg : public QDialog
	{
		Q_OBJECT

	public:
		CChangePasswordDlg(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CChangePasswordDlg();
	private:
		Ui::changePasswordForm* ui;

	};
}




#endif // CHANGEPASSWORDDLG_H
