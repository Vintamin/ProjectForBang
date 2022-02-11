
#ifndef _DRILLINGSAVEANALYSISDLG_H_
#define _DRILLINGSAVEANALYSISDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include "vrmine\vr_scenecontrol\geospatialcontrol.h"
#include "vrmine\vr_solutions\minesafetysolution.h"


namespace Ui
{	
	class drillAnalysi;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CDrillingSaveAnalysiDlg : public QDialog
		{
			Q_OBJECT

		public:
			CDrillingSaveAnalysiDlg(QWidget *parent = 0);
			virtual ~CDrillingSaveAnalysiDlg();
			void setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl);
			VirtualMine::Scene::CGeoSpatialControl* getGeoSpatialControl();
			VirtualMine::Solution::CMineSafetySolution* getMineSafetySolution();
			void setMineSafetySolution(VirtualMine::Solution::CMineSafetySolution* ref_MineSafetySolution);

			private slots:			
				//void slotSelectPath();
				//void slotOpenSolution();
				//void slotCloseSolution();
				void slotBegin();
				void slotSelectSavePoint();
				void slotVerticalPoint();
				void slotAnalysisOptPoint();
				void slotDrillingSave();
			 	void slotEndAnalysis();
		private:	
			Ui::drillAnalysi* ui;
			//std::string mSolutionPath; 
			VirtualMine::Solution::CMineSafetySolution* mpMineSafeSolution; 
			VirtualMine::Scene::CGeoSpatialControl* ref_mpGeoSpatialControl;
		};

	}
}


#endif