#ifndef DRILLINGMACHINETYPED_YTDLG_H
#define DRILLINGMACHINETYPED_YTDLG_H


#include <QtGui/QDialog>
#include "bang_ForUI/bang_configui.h"



namespace Ui
{
	class drillingmachinetyped_ytForm;
}
namespace Bang
{
	class BANG_VRGENERALUI_DLL CDrillingMachineTyped_YtDlg : public QDialog
	{
		Q_OBJECT

	public:
		CDrillingMachineTyped_YtDlg(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CDrillingMachineTyped_YtDlg();
	private:
		Ui::drillingmachinetyped_ytForm* ui;

	};
}




#endif // DRILLINGMACHINETYPED_YTDLG_H
