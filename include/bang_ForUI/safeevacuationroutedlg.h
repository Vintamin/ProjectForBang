#ifndef SAFEEVACUATIONROUTEDLG_H
#define SAFEEVACUATIONROUTEDLG_H


#include <QtGui/QDialog>
#include "bang_configui.h"



namespace Ui
{
	class safeevacuationrouteForm;
}
namespace Bang
{
	class BANG_VRGENERALUI_DLL CSafeevacuationroutedlg : public QDialog
	{
		Q_OBJECT

	public:
		CSafeevacuationroutedlg(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CSafeevacuationroutedlg();
	private:
		Ui::safeevacuationrouteForm* ui;

	};
}




#endif // SAFEEVACUATIONROUTEDLG_H
