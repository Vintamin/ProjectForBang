#ifndef PROJECTDESIGNDLG_H
#define PROJECTDESIGNDLG_H


#include <QtGui/QDialog>
#include "bang_configui.h"



namespace Ui
{
	class projectDesignForm;
}
namespace Bang
{
	class BANG_VRGENERALUI_DLL CProjectDesignDlg : public QDialog
	{
		Q_OBJECT

	public:
		CProjectDesignDlg(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CProjectDesignDlg();
	private:
		Ui::projectDesignForm* ui;

	};
}




#endif // PROJECTDESIGNDLG_H
