
#ifndef _CSWITCHPROPERTYDLG_H_
#define _CSWITCHPROPERTYDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include <QDomDocument>
namespace Ui
{
	class SwitchDlg;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CSwitchPropertyDlg :public QDialog
		{
			Q_OBJECT
		public:
			CSwitchPropertyDlg(QWidget *parent = 0);
			virtual ~CSwitchPropertyDlg();

			void setID(const std::string& substationID,const std::string& sensorID);

			void initialize(QDomDocument* doc);
		private:
			Ui::SwitchDlg* ui;
			std::string mSubstationID;
			std::string mSensorID;
		};
	}
}


#endif //_CSWITCHPROPERTYDLG_H_