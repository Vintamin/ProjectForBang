
#ifndef _CLOCATIONROPERTYDLG_H_
#define _CLOCATIONROPERTYDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>

namespace Ui
{
	class LocationPropertyWidget;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CLocationPropertyDlg :public QDialog
		{
			Q_OBJECT
		public:
			CLocationPropertyDlg(QWidget *parent = 0);
			virtual ~CLocationPropertyDlg();
			void initialize();
			void setID(const std::string& stationID,const std::string& cardID);
		private:
			Ui::LocationPropertyWidget* ui;
			std::string mStationID;
			std::string mCardID;

		};
	}
}


#endif //_CLOCATIONROPERTYDLG_H_