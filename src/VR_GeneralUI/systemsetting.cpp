#include "vrmine/vr_generalui/systemsetting.h"
#include "ui_shortCutViewDlg.h"

namespace VirtualMine
{
	namespace GeneralUI
	{
		CShortCutViewDlg::CShortCutViewDlg(QWidget *parent)
			:QDialog(parent)
		{
			this->ui = new Ui::ShortCutView_UI();
			this->ui->setupUi(this);
		}


		CShortCutViewDlg::~CShortCutViewDlg(void)
		{
		}
	}}
