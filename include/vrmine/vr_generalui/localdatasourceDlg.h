
#ifndef _CDATASOURCECONFIG_H_
#define _CDATASOURCECONFIG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>

namespace Ui
{
	class DataSourceConfig_UI;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CDataSourceConfigDlg : public QDialog
		{
			Q_OBJECT
		public:
			CDataSourceConfigDlg(QWidget *parent = 0);
			virtual ~CDataSourceConfigDlg();
			void initial();
			std::string getDBPath();
			std::string getDBType();
		private slots:
			void slotSelectDataSourcePath();
			void slotAccept();
			void slotCancel();
			//virtual void accept();
			//virtual void reject();
			//virtual void open();
		private:
			Ui::DataSourceConfig_UI* ui;
			std::string mDBPath;
			std::string mDBType;
		};

	}
}


#endif