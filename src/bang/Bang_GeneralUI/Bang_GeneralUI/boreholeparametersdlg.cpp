#include "bang_ForUI/boreholeparametersdlg.h"
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_boreholeparametersdlg.h"
#include "string"

using namespace  std;
using namespace Bang;


CBoreHoleParametersDlg::CBoreHoleParametersDlg( QWidget *parent , Qt::WFlags flags  )
	: QDialog(parent, flags)
{
	this->ui = new Ui::boreholeparametersForm();
	ui->setupUi(this);

}

CBoreHoleParametersDlg::~CBoreHoleParametersDlg()
{

}

