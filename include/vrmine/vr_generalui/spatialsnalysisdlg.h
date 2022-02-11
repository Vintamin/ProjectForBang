
#ifndef _SPALTIALANALYSISDLG_H_
#define _SPALTIALANALYSISDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include "vrmine\vr_scenecontrol\geospatialcontrol.h"
//#include "vrmine\vr_solutions\minesafetysolution.h"


namespace Ui
{	
	class SpatialForm;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CSpaltialAnalysiDlg : public QDialog
		{
			Q_OBJECT

		public:
			CSpaltialAnalysiDlg(QWidget *parent = 0);
			virtual ~CSpaltialAnalysiDlg();
			void setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl);
			VirtualMine::Scene::CGeoSpatialControl* getGeoSpatialControl();
		/*	VirtualMine::Solution::CMineSafetySolution* getMineSafetySolution();
			void setMineSafetySolution(VirtualMine::Solution::CMineSafetySolution* ref_MineSafetySolution);*/

			private slots:			
			
				void slotPointMessure();
				void slotDistanceMeasure();
				void slotCleatMeasure();
		private:	
			Ui::SpatialForm* ui;
			//std::string mSolutionPath; 
			//VirtualMine::Solution::CMineSafetySolution* mpMineSafeSolution; 
			VirtualMine::Scene::CGeoSpatialControl* ref_mpGeoSpatialControl;
		};

	



	}
}


#endif