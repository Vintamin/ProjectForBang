
#ifndef _QUERYCOORDINATIONDLG_H_
#define _QUERYCOORDINATIONDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include "vrmine\vr_scenecontrol\geospatialcontrol.h"



namespace Ui
{	
	class QueryCoordinationForm;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CQueryCordinationDlg : public QDialog
		{
			Q_OBJECT

		public:
			CQueryCordinationDlg(QWidget *parent = 0);
			virtual ~CQueryCordinationDlg();
			void setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl);
			VirtualMine::Scene::CGeoSpatialControl* getGeoSpatialControl();
			std::string getX();
			std::string getY();
			std::string getZ();


			private slots:			
				void slotQueryLaneway();

		private:	
			Ui::QueryCoordinationForm* ui;
			std::string mSolutionPath; 
			//VirtualMine::Solution::CMineSafetySolution* mMineSafetySolution; 
			VirtualMine::Scene::CGeoSpatialControl* ref_mpGeoSpatialControl;
		};

	}
}


#endif