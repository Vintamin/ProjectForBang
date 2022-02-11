#ifndef BLASTINGEFFECTDLG_H
#define BLASTINGEFFECTDLG_H


#include <QtGui/QDialog>
#include "bang_configui.h"



namespace Ui
{
	class blastingEffectForm;
}
namespace Bang
{
	class BANG_VRGENERALUI_DLL CBlastingEffectDlg : public QDialog
	{
		Q_OBJECT

	public:
		CBlastingEffectDlg(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CBlastingEffectDlg();
	private:
		Ui::blastingEffectForm* ui;

	};
}




#endif // BLASTINGEFFECTDLG_H
