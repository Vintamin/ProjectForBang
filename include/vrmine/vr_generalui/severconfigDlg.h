
#ifndef _CSERVERCONFIGDLG_H_
#define _CSERVERCONFIGDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
namespace Ui
{
	class SeverConfigWidget;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CSeverConfigDlg :public QDialog
		{
			Q_OBJECT
		public:
			CSeverConfigDlg(QWidget *parent = 0);
			virtual ~CSeverConfigDlg();

			void initialize();

			private slots:
				void slotOk();
				//void slotCancel();
		private:
			Ui::SeverConfigWidget* ui;
		};
	}
}


#endif //_CSERVERCONFIGDLG_H_