#ifndef OPENPROJECTDLG_H
#define OPENPROJECTDLG_H


#include <QtGui/QDialog>
#include "bang_configui.h"
#include "vrmine/vr_scenecontrol/geospatialcontrol.h"
//#include "vrmine/vr_sqlitedatabase/sqlitedatabase/sqlitedatabase.h"
#include "bang/bangsqlitedatabase.h"
#include <QTableWidgetItem>

namespace Ui
{
	class openProjectForm;
}
namespace Bang
{
	class BANG_VRGENERALUI_DLL COpenprojectdlg : public QDialog
	{
		Q_OBJECT

	public:
		COpenprojectdlg(QWidget *parent=0, Qt::WFlags flags=0);
		~COpenprojectdlg();

		/*	void setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl);
		VirtualMine::Scene::CGeoSpatialControl* getGeoSpatialControl();	*/	
		
		int getProjectID();
		VirtualMine::Bang_Database::CBangSqliteDatabase* getDatabase();
		void setDatabse(VirtualMine::Bang_Database::CBangSqliteDatabase* pDatabase);

	private slots:
	    void slotOnOK();
		void slotGetProItem(QTableWidgetItem* item);
		
	public:
		void initial();
	private:
		Ui::openProjectForm* ui;
		//VirtualMine::Scene::CGeoSpatialControl* ref_mpControl;
		//VirtualMine::SQLiteDatabase::CSQLiteDatabase* ref_mpSqliteDatabase;
		VirtualMine::Bang_Database::CBangSqliteDatabase* ref_mpSqliteDatabase;

	};
}




#endif // OPENPROJECTDLG_H
