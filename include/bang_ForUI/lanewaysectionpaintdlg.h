#ifndef LANEWAYSECTIONPAINTDLG_H
#define LANEWAYSECTIONPAINTDLG_H


#include <QtGui/QDialog>
#include "bang_configui.h"


namespace Ui
{
	class lanewaySectionPaintForm;
}
namespace Bang
{
	class BANG_VRGENERALUI_DLL CLanewaysectionpaintdlg : public QDialog
	{
		Q_OBJECT

	public:
		CLanewaysectionpaintdlg(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CLanewaysectionpaintdlg();
	private:
		Ui::lanewaySectionPaintForm* ui;

	};
}




#endif // LANEWAYSECTIONPAINTDLG_H
