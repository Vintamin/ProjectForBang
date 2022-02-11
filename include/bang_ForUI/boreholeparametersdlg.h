#ifndef BOREHOLEPARAMETERSDLG_H
#define BOREHOLEPARAMETERSDLG_H


#include <QtGui/QDialog>
#include "bang_configui.h"



namespace Ui
{
	class boreholeparametersForm;
}
namespace Bang
{
	class BANG_VRGENERALUI_DLL CBoreHoleParametersDlg : public QDialog
	{
		Q_OBJECT

	public:
		CBoreHoleParametersDlg(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CBoreHoleParametersDlg();
	private:
		Ui::boreholeparametersForm* ui;

	};
}




#endif // BOREHOLEPARAMETERSDLG_H
