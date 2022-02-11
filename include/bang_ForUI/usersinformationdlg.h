#ifndef USERINFORMATIONDLG_H
#define USERINFORMATIONDLG_H


#include <QtGui/QDialog>
#include "bang_configui.h"



namespace Ui
{
	class userInformationForm;
}
namespace Bang
{
	class BANG_VRGENERALUI_DLL CUserInformationDlg : public QDialog
	{
		Q_OBJECT

	public:
		CUserInformationDlg(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CUserInformationDlg();
	private:
		Ui::userInformationForm* ui;

	};
}




#endif // USERINFORMATIONDLG_H
