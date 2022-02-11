#include "bang_ForUI/changepassworddlg.h"
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_changepassworddlg.h"
#include "string"

using namespace  std;
using namespace Bang;


CChangePasswordDlg::CChangePasswordDlg( QWidget *parent , Qt::WFlags flags  )
	: QDialog(parent, flags)
{
	this->ui = new Ui::changePasswordForm();
	ui->setupUi(this);

}

CChangePasswordDlg::~CChangePasswordDlg()
{

}

