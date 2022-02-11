
#ifndef _SWITCHVALUEDLG_H_
#define _SWITCHVALUEDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include "vrmine/vr_scenecontrol/geospatialcontrol.h"
#include <QModelIndex>
namespace Ui
{
	class SwitchValueWidget;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CSwitchValueDlg : public QDialog
		{
			Q_OBJECT
		public:
			CSwitchValueDlg(QWidget *parent = 0);
			virtual ~CSwitchValueDlg();

			//void setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* geoSpatialControl);
			void initialize();
			/*private slots:
			void slotDoubleClick(QModelIndex index);*/
		private:
			Ui::SwitchValueWidget* ui;
			//VirtualMine::Scene::CGeoSpatialControl* ref_mgeoSpatialControl;
		};

	}
}


#endif