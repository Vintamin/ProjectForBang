
#ifndef _SIMUVALUEDLG_H_
#define _SIMUVALUEDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include "vrmine/vr_scenecontrol/geospatialcontrol.h"
#include <QModelIndex>
namespace Ui
{
	class SimuValueWidget;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CSimuValueDlg : public QDialog
		{
			Q_OBJECT
		public:
			CSimuValueDlg(QWidget *parent = 0);
			virtual ~CSimuValueDlg();

			void setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* geoSpatialControl);
			void initialize();
			private slots:
				void slotDoubleClick(QModelIndex index);
		private:
			Ui::SimuValueWidget* ui;
			VirtualMine::Scene::CGeoSpatialControl* ref_mgeoSpatialControl;
		};

	}
}


#endif