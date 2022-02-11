#ifndef DRILLINGMACHINETYPED_TROLLEYDLG_H
#define DRILLINGMACHINETYPED_TROLLEYDLG_H


#include <QtGui/QDialog>
#include "bang_ForUI/bang_configui.h"



namespace Ui
{
	class drillingMachineTyped_trolleyForm;
}
namespace Bang
{
	class BANG_VRGENERALUI_DLL CDrillingMachineTyped_TrolleyDlg : public QDialog
	{
		Q_OBJECT

	public:
		CDrillingMachineTyped_TrolleyDlg(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CDrillingMachineTyped_TrolleyDlg();
	private:
		Ui::drillingMachineTyped_trolleyForm* ui;

	};
}




#endif // DRILLINGMACHINETYPED_TROLLEYDLG_H
