#include "bang_ForUI/projectdesigndlg.h"
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_projectdesigndlg.h"
#include "string"

using namespace  std;
using namespace Bang;


CProjectDesignDlg::CProjectDesignDlg( QWidget *parent , Qt::WFlags flags  )
	: QDialog(parent, flags)
{
	this->ui = new Ui::projectDesignForm();
	ui->setupUi(this);

}

CProjectDesignDlg::~CProjectDesignDlg()
{

}

