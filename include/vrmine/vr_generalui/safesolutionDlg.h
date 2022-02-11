
#ifndef _CSAFESOLUTIONDLG_H_
#define _CSAFESOLUTIONDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include "vrmine/vr_solutions/minesafetysolution.h"

namespace Ui
{
	class SafeSolution_UI;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CSafeSolutionDlg : public QDialog
		{
			Q_OBJECT
		public:
			CSafeSolutionDlg(QWidget *parent = 0);
			virtual ~CSafeSolutionDlg();
			virtual void bindingMineSafetySolution(VirtualMine::Solution::CMineSafetySolution* ref_pSafeSolution);
			/*void setFloodAnalysisTool(VirtualMine::SystemUI::CFloodAnalysisTool* ref_pFloodAnalysisTool);
			void bindingOperator();
			void initialControl();
		private slots:
			void slotSelectWaterColor();
			void slotSetWaterHeight();*/
			virtual void initialControl();
		private slots:
			void slotHandIn();
			void slotCancel();
		private:

			Ui::SafeSolution_UI* ui;
			VirtualMine::Solution::CMineSafetySolution* ref_mpSafeSolution;
			/*VirtualMine::SystemUI::CFloodAnalysisTool* ref_mpFloodAnalysisTool;
			*/
		};

	}
}


#endif