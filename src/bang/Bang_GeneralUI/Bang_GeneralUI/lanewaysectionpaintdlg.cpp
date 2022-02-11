#include "bang_ForUI/lanewaysectionpaintdlg.h"
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_lanewaysectionpaintdlg.h"
#include "string"

using namespace  std;
using namespace Bang;


CLanewaysectionpaintdlg::CLanewaysectionpaintdlg( QWidget *parent /*= 0*/, Qt::WFlags flags /*= 0*/ )
	: QDialog(parent, flags)
{
	this->ui = new Ui::lanewaySectionPaintForm();
	ui->setupUi(this);

}

CLanewaysectionpaintdlg::~CLanewaysectionpaintdlg()
{

}

