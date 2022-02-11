#include "bang_ForUI/advanceschedule.h"
#include "ui_advanceschedule.h"
#include <QWidget>
#include <Qt\qtextcodec.h>
#include "string"


using namespace  std;
using namespace Bang;

CAdvanceSchedule::CAdvanceSchedule(QWidget *parent , Qt::WFlags flags)
	: QDialog(parent , flags)
{
	this->ui = new Ui::advanceScheduleForm();
	ui->setupUi(this);
}

CAdvanceSchedule::~CAdvanceSchedule()
{

}
