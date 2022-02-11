#include "bang_ForUI/coalmechanicalparametersdlg.h"
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_coalmechanicalparametersdlg.h"
#include "string"

using namespace  std;
using namespace Bang;


CCoalMechanicalParametersDlg::CCoalMechanicalParametersDlg( QWidget *parent , Qt::WFlags flags  )
	: QDialog(parent, flags)
{
	this->ui = new Ui::coalMechanicalParametersForm();
	ui->setupUi(this);

}

CCoalMechanicalParametersDlg::~CCoalMechanicalParametersDlg()
{

}

