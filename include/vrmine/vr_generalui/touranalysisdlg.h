
#ifndef _TOURANALYSISDLG_H_
#define _TOURANALYSISDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include "vrmine\vr_scenecontrol\geospatialcontrol.h"
//#include "vrmine\vr_solutions\minesafetysolution.h"
#include "vrmine/vr_kml/tourobject.h"

namespace Ui
{	
	class touranalysis;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CTourAnalysisDlg : public QDialog
		{
			Q_OBJECT

		public:
			CTourAnalysisDlg(QWidget *parent = 0);
			virtual ~CTourAnalysisDlg();
			void setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl);
			VirtualMine::Scene::CGeoSpatialControl* getGeoSpatialControl();
		
			private slots:			
				//void slotSelectPath();
				//void slotOpenSolution();
				//void slotCloseSolution();
				void slotLuzhiTour();
				void slotJieshuTour();
				void slotPlayTour();
				void slotPauseTour();
				void slotStopTour();
				void slotClearTour();
		private:	
			Ui::touranalysis* ui;
			//std::string mSolutionPath; 
			//VirtualMine::Solution::CMineSafetySolution* mpMineSafeSolution; 
			VirtualMine::Scene::CGeoSpatialControl* ref_mpGeoSpatialControl;
			VirtualMine::Kml::CTourObject* mpTourObject;
		};

	}
}


#endif