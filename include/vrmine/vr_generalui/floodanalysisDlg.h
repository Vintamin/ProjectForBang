
#ifndef _CFLOODANALYSISDLG_H_
#define _CFLOODANALYSISDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include "vrmine/vr_systemui/floodanalysistool.h"

namespace Ui
{
	class FloodAnalysis_UI;
	class TourPropertyUI;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CFloodAnalysisDlg : public QDialog
		{
			Q_OBJECT
		public:
			CFloodAnalysisDlg(QWidget *parent = 0);
			virtual ~CFloodAnalysisDlg();
			void setFloodAnalysisTool(VirtualMine::SystemUI::CFloodAnalysisTool* ref_pFloodAnalysisTool);
			void bindingOperator();
			void initialControl();
		private slots:
			void slotSelectWaterColor();
			void slotSetWaterHeight(double value);
			void slotHandIn();
			void slotShowWaterSurface(bool value);
			void slotWaterSurfaceEffect(bool value);
		private:

			Ui::FloodAnalysis_UI* ui;
			VirtualMine::SystemUI::CFloodAnalysisTool* ref_mpFloodAnalysisTool;
		
		};

		class VRGENERALUI_DLL CTourPropertyDlg : public QDialog
		{
			Q_OBJECT
		public:
			CTourPropertyDlg(QWidget *parent = 0);
			virtual ~CTourPropertyDlg();
			std::string getTourPath();

		protected slots:
			void slotSelectPath();
			void slotLoadTour();
			void slotUnloadTour();
			void slotClose();

		protected:
			std::string mTourPath;
			Ui::TourPropertyUI* ui;
		};

	}
}


#endif