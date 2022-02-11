#ifndef EXPLOSIVEMAGAZINETABLEDLG_H
#define EXPLOSIVEMAGAZINETABLEDLG_H


#include <QtGui/QDialog>
#include "bang_configui.h"



namespace Ui
{
	class explosiveMagazineTableForm;
}
namespace Bang
{
	class BANG_VRGENERALUI_DLL CExplosiveMagazineTableDlg : public QDialog
	{
		Q_OBJECT

	public:
		CExplosiveMagazineTableDlg(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CExplosiveMagazineTableDlg();
	private:
		Ui::explosiveMagazineTableForm* ui;

	};
}




#endif // EXPLOSIVEMAGAZINETABLEDLG_H
