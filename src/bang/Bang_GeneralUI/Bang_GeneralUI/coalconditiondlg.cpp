#include "bang_ForUI/coalconditiondlg.h"
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_coalconditiondlg.h"
#include "string"

using namespace  std;
using namespace Bang;


CCoalConditionDlg::CCoalConditionDlg( QWidget *parent , Qt::WFlags flags  )
	: QDialog(parent, flags)
{
	this->ui = new Ui::coalConditionsForm();
	ui->setupUi(this);

}

CCoalConditionDlg::~CCoalConditionDlg()
{

}

