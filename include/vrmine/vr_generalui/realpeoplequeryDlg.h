
#ifndef _CREALPEOPLEQUERYDLG_H_
#define _CREALPEOPLEQUERYDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include "vrmine/vr_sqldatabasehelper/vr_sqldatabasehelper.h"
#include <QModelIndex>
#include "vrmine/vr_scenecontrol/geospatialcontrol.h"
namespace Ui
{
	class realpeoplewidget;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CRealPeopleQueryDlg :public QDialog
		{
			Q_OBJECT
		public:
			CRealPeopleQueryDlg(QWidget *parent = 0);
			virtual ~CRealPeopleQueryDlg();

			void initialize();
			void setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* geoSpatialControl);
		protected slots:
			void test(const QModelIndex & index);
			void slotDoubleClick(QModelIndex index);
			
		private:
			Ui::realpeoplewidget* ui;

			VirtualMine::Scene::CGeoSpatialControl* ref_mGeoSpatialControl;
		};
	}
}


#endif //_CREALPEOPLEQUERYDLG_H_