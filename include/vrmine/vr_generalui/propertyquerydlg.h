
#ifndef _PROPERTYQUERYDLG_H_
#define _PROPERTYQUERYDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include "vrmine\vr_scenecontrol\geospatialcontrol.h"
//#include "vrmine\vr_solutions\minesafetysolution.h"


namespace Ui
{	
	class Form;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CPropertyQueryDlg : public QDialog
		{
			Q_OBJECT

		public:
			CPropertyQueryDlg(QWidget *parent = 0);
			virtual ~CPropertyQueryDlg();
			void setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl);
			VirtualMine::Scene::CGeoSpatialControl* getGeoSpatialControl();
			bool getStartSelect();
			void setStartSelect(bool select);
			private slots:			
				void slotPropertyQuery();
				void slotClear();
		private:	
			Ui::Form* ui;
			//std::string mSolutionPath; 
			//VirtualMine::Solution::CMineSafetySolution* mMineSafetySolution; 
			bool mStartSelect;
			VirtualMine::Scene::CGeoSpatialControl* ref_mpGeoSpatialControl;
		};

	}
}


#endif