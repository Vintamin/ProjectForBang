
#ifndef _CPROJECTLISTDLG_H_
#define _CPROJECTLISTDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>

namespace Ui
{
	class ProjectListDlg;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CProjectListDlg :public QDialog
		{
			Q_OBJECT
		public:
			CProjectListDlg(QWidget *parent = 0);
			virtual ~CProjectListDlg();
			void initialize();

			static std::string FileName;

			private slots:
				void slotOk();
		private:
			Ui::ProjectListDlg* ui;
			
		};
	}
}


#endif //_CPROJECTLISTDLG_H_