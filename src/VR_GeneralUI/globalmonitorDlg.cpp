#include "vrmine/vr_generalui/globalmonitorDlg.h"
#include "ui_globalMonitorDlg.h"

namespace VirtualMine
{
	namespace GeneralUI
	{
		CGlobalMonitorDlg::CGlobalMonitorDlg(QWidget *parent /* = 0 */)
			:QDialog(parent)
		{
			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			setFixedSize(this->width(), this->height());
			this->ui = new Ui::globalMonitorWidget();
			this->ui->setupUi(this);
		}

		CGlobalMonitorDlg::~CGlobalMonitorDlg()
		{
			setAttribute (Qt::WA_DeleteOnClose);
		}

		void CGlobalMonitorDlg::slottest()
		{
			int a =1;
		}
	}
}