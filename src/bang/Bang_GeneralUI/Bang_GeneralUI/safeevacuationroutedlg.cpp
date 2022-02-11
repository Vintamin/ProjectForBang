#include "bang_ForUI/safeevacuationroutedlg.h"
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_safeevacuationroutedlg.h"
#include "string"

using namespace  std;
using namespace Bang;


CSafeevacuationroutedlg::CSafeevacuationroutedlg( QWidget *parent /*= 0*/, Qt::WFlags flags /*= 0*/ )
	: QDialog(parent, flags)
{
	this->ui = new Ui::safeevacuationrouteForm();
	ui->setupUi(this);

}

CSafeevacuationroutedlg::~CSafeevacuationroutedlg()
{

}

