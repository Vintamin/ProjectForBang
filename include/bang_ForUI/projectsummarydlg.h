#ifndef PROJECTSUMMARYDLG_H
#define PROJECTSUMMARYDLG_H


#include <QtGui/QDialog>
#include "bang_configui.h"



namespace Ui
{
	class projectSummaryForm;
}
namespace Bang
{
	class BANG_VRGENERALUI_DLL CProjectSummaryDlg : public QDialog
	{
		Q_OBJECT

	public:
		CProjectSummaryDlg(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CProjectSummaryDlg();
	private:
		Ui::projectSummaryForm* ui;

	};
}




#endif // PROJECTSUMMARYDLG_H
