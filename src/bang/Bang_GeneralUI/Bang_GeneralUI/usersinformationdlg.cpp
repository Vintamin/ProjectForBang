#include "bang_ForUI/usersinformationdlg.h"
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_usersinformationdlg.h"
#include "string"

using namespace  std;
using namespace Bang;


CUserInformationDlg::CUserInformationDlg( QWidget *parent , Qt::WFlags flags  )
	: QDialog(parent, flags)
{
	this->ui = new Ui::userInformationForm();
	ui->setupUi(this);

}

CUserInformationDlg::~CUserInformationDlg()
{

}

