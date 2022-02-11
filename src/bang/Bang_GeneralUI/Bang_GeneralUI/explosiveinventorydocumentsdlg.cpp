#include "bang_ForUI/explosiveinventorydocumentsdlg.h"
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <Qt\qtextcodec.h>
#include "ui_explosiveinventorydocumentsdlg.h"
#include "string"

using namespace  std;
using namespace Bang;


CExplosiveInventoryDocumentsDlg::CExplosiveInventoryDocumentsDlg( QWidget *parent , Qt::WFlags flags  )
	: QDialog(parent, flags)
{
	this->ui = new Ui::explosiveInventoryDocumentsForm();
	ui->setupUi(this);

	connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(btnok()));

}

CExplosiveInventoryDocumentsDlg::~CExplosiveInventoryDocumentsDlg()
{

}


void CExplosiveInventoryDocumentsDlg::btnok()
{

	
}