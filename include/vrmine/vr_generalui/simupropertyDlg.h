
#ifndef _CSIMUPROPERTYDLG_H_
#define _CSIMUPROPERTYDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include <QDomDocument>
namespace Ui
{
	class SimuDlg;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CSimuPropertyDlg :public QDialog
		{
			Q_OBJECT
		public:
			CSimuPropertyDlg(QWidget *parent = 0);
			virtual ~CSimuPropertyDlg();

			void setID(const std::string& substationID,const std::string& sensorID);

			void initialize(QDomDocument* doc);
		private:
			Ui::SimuDlg* ui;
			std::string mSubstationID;
			std::string mSensorID;
		};
	}
}


#endif //_CSIMUPROPERTYDLG_H_