
#ifndef _ADDSOLUTIONDLG_H_
#define _ADDSOLUTIONDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include "vrmine\vr_scenecontrol\geospatialcontrol.h"
#include "vrmine\vr_solutions\minesafetysolution.h"


namespace Ui
{	
	class addSolutionDlg;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CAddSolutionDlg : public QDialog
		{
			Q_OBJECT

		public:
			CAddSolutionDlg(QWidget *parent = 0);
			virtual ~CAddSolutionDlg();
            void setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl);
            VirtualMine::Scene::CGeoSpatialControl* getGeoSpatialControl();
			VirtualMine::Solution::CMineSafetySolution* getMineSafetySolution();
			void setMineSafetySolution(VirtualMine::Solution::CMineSafetySolution* ref_MineSafetySolution);

		private slots:			
			void slotSelectPath();
			void slotOpenSolution();
			void slotCloseSolution();
		private:	
			Ui::addSolutionDlg* ui;
            std::string mSolutionPath; 
			VirtualMine::Solution::CMineSafetySolution* mMineSafetySolution; 
            VirtualMine::Scene::CGeoSpatialControl* ref_mpGeoSpatialControl;
		};

	}
}


#endif