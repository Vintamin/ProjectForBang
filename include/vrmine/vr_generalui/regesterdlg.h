
#ifndef _REGISTERDLG_H_
#define _REGISTERDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include "vrmine\vr_scenecontrol\geospatialcontrol.h"
//#include "vrmine\vr_solutions\minesafetysolution.h"

#include "vrmine\vr_sqlitedatabase\sqlitedatabase\sqlitedatabase.h"
#include <QFileDialog>
namespace Ui
{	
	class registerForm;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL  CRegisterDlg: public QDialog
		{
			Q_OBJECT

		public:
			CRegisterDlg(QWidget *parent = 0);
			virtual ~CRegisterDlg();
			//void setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl);
			//VirtualMine::Scene::CGeoSpatialControl* getGeoSpatialControl();
			
			std::string getUserName();
			std::string getPassword();
			std::string getDatasoureName();

			void registerInfo();
			void openDatasource();

			private slots:			 
				void slotOnOK();
				void slotCancel();
			
				
		private:	
			Ui::registerForm* ui;
	
			std::string mUserName;
			std::string mPassword;
			std::string mPasswordConform;
			std::string mDatabaseName;
			//VirtualMine::Scene::CGeoSpatialControl* ref_mpGeoSpatialControl;
			VirtualMine::SQLiteDatabase::CSQLiteDatabase* mpSQLiteDB;
		};

	}
}


#endif