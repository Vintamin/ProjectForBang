#ifndef COALCONDITIONDLG_H
#define COALCONDITIONDLG_H


#include <QtGui/QDialog>
#include "bang_configui.h"



namespace Ui
{
	class coalConditionsForm;
}
namespace Bang
{
	class BANG_VRGENERALUI_DLL CCoalConditionDlg : public QDialog
	{
		Q_OBJECT

	public:
		CCoalConditionDlg(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CCoalConditionDlg();
	private:
		Ui::coalConditionsForm* ui;

	};
}




#endif // COALCONDITIONDLG_H
