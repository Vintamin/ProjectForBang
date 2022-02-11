#include "bang_ForUI/projectsummarydlg.h"
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_projectsummarydlg.h"
#include "string"

using namespace  std;
using namespace Bang;


CProjectSummaryDlg::CProjectSummaryDlg( QWidget *parent , Qt::WFlags flags  )
	: QDialog(parent, flags)
{
	this->ui = new Ui::projectSummaryForm();
	ui->setupUi(this);

}

CProjectSummaryDlg::~CProjectSummaryDlg()
{

}

