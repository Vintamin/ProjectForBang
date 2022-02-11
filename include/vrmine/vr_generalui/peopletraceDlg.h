
#ifndef _CPEOPLETRACEPERTYDLG_H_
#define _CPEOPLETRACEPERTYDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>

namespace Ui
{
	class PeopleTraceWidget;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CPeopleTraceDlg :public QDialog
		{
			Q_OBJECT
		public:
			CPeopleTraceDlg(QWidget *parent = 0);
			virtual ~CPeopleTraceDlg();
			void initialize();

			private slots:
				void slotDepartmentChanged(QString text);
				void slotQuery();
		private:
			Ui::PeopleTraceWidget* ui;
		};
	}
}


#endif //_CPEOPLETRACEPERTYDLG_H_