

#include "vrmine/vr_generalui/querycoordinationdlg.h"

#include "ui_querycoordination.h"


using namespace VirtualMine::GeneralUI;


CQueryCordinationDlg::CQueryCordinationDlg(QWidget *parent)
	:QDialog(parent)
{
	setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
	//setFixedSize(this->width(), this->height());
	this->ui = new Ui::QueryCoordinationForm();
	this->ui->setupUi(this);

	this->ref_mpGeoSpatialControl = NULL;


	connect(ui->queryBtn,SIGNAL(clicked()),this,SLOT(slotQueryLaneway()));

}





CQueryCordinationDlg::~CQueryCordinationDlg()
{

}


void CQueryCordinationDlg::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl)
{
	this->ref_mpGeoSpatialControl = ref_pGeoSpatialControl;
}


VirtualMine::Scene::CGeoSpatialControl* CQueryCordinationDlg::getGeoSpatialControl()
{
	return ref_mpGeoSpatialControl;
}



void CQueryCordinationDlg::slotQueryLaneway()
{
	QDialog::accept();

}





std::string VirtualMine::GeneralUI::CQueryCordinationDlg::getX()
{
	return this->ui->lineEditX->text().toStdString();
}

std::string VirtualMine::GeneralUI::CQueryCordinationDlg::getY()
{
	return this->ui->lineEditY->text().toStdString();
}

std::string VirtualMine::GeneralUI::CQueryCordinationDlg::getZ()
{
	return this->ui->lineEditZ->text().toStdString();
}
