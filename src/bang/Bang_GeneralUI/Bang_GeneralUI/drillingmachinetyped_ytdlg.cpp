#include "bang_ForUI/drillingmachinetyped_ytdlg.h"
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_drillingmachinetyped_ytdlg.h"
#include "string"

using namespace  std;
using namespace Bang;


CDrillingMachineTyped_YtDlg::CDrillingMachineTyped_YtDlg( QWidget *parent , Qt::WFlags flags  )
	: QDialog(parent, flags)
{
	this->ui = new Ui::drillingmachinetyped_ytForm();
	ui->setupUi(this);

}

CDrillingMachineTyped_YtDlg::~CDrillingMachineTyped_YtDlg()
{

}

