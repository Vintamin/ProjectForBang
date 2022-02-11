
#ifndef _ALLMONITORDLG_H_
#define _ALLMONITORDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include "vrmine/vr_scenecontrol/geospatialcontrol.h"
namespace Ui
{
	class AllMonitorWidget;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CAllMonitorDlg : public QDialog
		{
			Q_OBJECT
		public:
			CAllMonitorDlg(QWidget *parent = 0);
			virtual ~CAllMonitorDlg();

			void initialize();
			void setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* geoSpatialControl);
			private slots:
				void slotShowSimuValue();
				void slotShowSwitchValue();
			public:
			Ui::AllMonitorWidget* ui;
			VirtualMine::Scene::CGeoSpatialControl* ref_geoSpatialControl;
		};

	}
}


#endif