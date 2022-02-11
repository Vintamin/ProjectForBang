#ifndef _CSYSTEMSETTING_H_
#define _CSYSTEMSETTING_H_
#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>

namespace Ui
{
	class ShortCutView_UI;
}

namespace VirtualMine
{
	namespace GeneralUI
	{

		class VRGENERALUI_DLL CShortCutViewDlg :public QDialog
		{
			Q_OBJECT
		public:
			CShortCutViewDlg(QWidget *parent = 0);

			virtual ~CShortCutViewDlg(void);

		private:
			Ui::ShortCutView_UI* ui;
		};
	}}
#endif

