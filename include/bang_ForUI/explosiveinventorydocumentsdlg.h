#ifndef EXPLOSIVEINVENTORYDOCUMENTSDLG_H
#define EXPLOSIVEINVENTORYDOCUMENTSDLG_H


#include <QtGui/QDialog>
#include "bang_configui.h"



namespace Ui
{
	class explosiveInventoryDocumentsForm;
}
namespace Bang
{
	class BANG_VRGENERALUI_DLL CExplosiveInventoryDocumentsDlg : public QDialog
	{
		Q_OBJECT

	public:
		CExplosiveInventoryDocumentsDlg(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CExplosiveInventoryDocumentsDlg();
	private:
		Ui::explosiveInventoryDocumentsForm* ui;
	private slots:
			void btnok();

	};
}




#endif // EXPLOSIVEINVENTORYDOCUMENTSDLG_H
