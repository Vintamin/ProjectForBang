
#ifndef _QUERYLANEWAYDLG_H_
#define _QUERYLANEWAYDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include "vrmine\vr_scenecontrol\geospatialcontrol.h"
#include <vector>
#include <OGRE/OgreString.h>

namespace Ui
{	
	class queryLanewayForm;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CQueryLanewayDlg : public QDialog
		{
			Q_OBJECT

		public:
			CQueryLanewayDlg(QWidget *parent = 0);
			virtual ~CQueryLanewayDlg();
			void setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl);
			VirtualMine::Scene::CGeoSpatialControl* getGeoSpatialControl();
	        std::string getLanewayName();
			void initialsize();
			void setQueryLanewayCmbItems();

			private slots:			
				void slotQueryLaneway();
				void slotLineditNamechanged(const QString &);
				void slotLineditName(const QString &);
		private:	
			Ui::queryLanewayForm* ui;
			std::string mSolutionPath; 
			//VirtualMine::Solution::CMineSafetySolution* mMineSafetySolution; 
			VirtualMine::Scene::CGeoSpatialControl* ref_mpGeoSpatialControl;
			std::vector<Ogre::String> lanewayAllName;
			bool isfromCombox;
		};

	}
}


#endif