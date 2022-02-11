
#ifndef _GLOBALMONITORDLG_H_
#define _GLOBALMONITORDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>

namespace Ui
{
	class globalMonitorWidget;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CGlobalMonitorDlg : public QDialog
		{
			Q_OBJECT
		public:
			CGlobalMonitorDlg(QWidget *parent = 0);
			virtual ~CGlobalMonitorDlg();
			private slots:
				void slottest();
		private:
			Ui::globalMonitorWidget* ui;
		};

	}
}


#endif