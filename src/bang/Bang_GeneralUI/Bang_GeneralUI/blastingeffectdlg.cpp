#include "bang_ForUI/blastingeffectdlg.h"
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_blastingeffectdlg.h"
#include "string"

using namespace  std;
using namespace Bang;



CBlastingEffectDlg::CBlastingEffectDlg( QWidget *parent , Qt::WFlags flags  )
	: QDialog(parent, flags)
{
	this->ui = new Ui::blastingEffectForm();
	ui->setupUi(this);

}

CBlastingEffectDlg::~CBlastingEffectDlg()
{

}

