#ifndef COALMECHANICALPARAMETERSDLG_H
#define COALMECHANICALPARAMETERSDLG_H


#include <QtGui/QDialog>
#include "bang_configui.h"



namespace Ui
{
	class coalMechanicalParametersForm;
}
namespace Bang
{
	class BANG_VRGENERALUI_DLL CCoalMechanicalParametersDlg : public QDialog
	{
		Q_OBJECT

	public:
		CCoalMechanicalParametersDlg(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CCoalMechanicalParametersDlg();
	private:
		Ui::coalMechanicalParametersForm* ui;

	};
}




#endif // COALMECHANICALPARAMETERSDLG_H
