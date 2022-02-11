#include "bang_ForUI/drillingmachinetyped_Trolleydlg.h"
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_drillingmachinetyped_Trolleydlg.h"
#include "string"

using namespace  std;
using namespace Bang;


CDrillingMachineTyped_TrolleyDlg::CDrillingMachineTyped_TrolleyDlg( QWidget *parent , Qt::WFlags flags  )
	: QDialog(parent, flags)
{
	this->ui = new Ui::drillingMachineTyped_trolleyForm();
	ui->setupUi(this);

}

CDrillingMachineTyped_TrolleyDlg::~CDrillingMachineTyped_TrolleyDlg()
{

}

