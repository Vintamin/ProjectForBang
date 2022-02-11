#include "bang_ForUI/explosivemagazinetabledlg.h"
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_explosivemagazinetabledlg.h"
#include "string"

using namespace  std;
using namespace Bang;


CExplosiveMagazineTableDlg::CExplosiveMagazineTableDlg( QWidget *parent , Qt::WFlags flags  )
	: QDialog(parent, flags)
{
	this->ui = new Ui::explosiveMagazineTableForm();
	ui->setupUi(this);

}

CExplosiveMagazineTableDlg::~CExplosiveMagazineTableDlg()
{

}

