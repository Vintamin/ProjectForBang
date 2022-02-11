#include "vrmine/vr_generalui/safesolutionDlg.h"
#include "ui_safesolutionDlg.h"
#include <qpalette.h>

namespace VirtualMine
{
	namespace GeneralUI
	{

		CSafeSolutionDlg::CSafeSolutionDlg(QWidget *parent)
			:QDialog(parent),ref_mpSafeSolution(NULL)
		{
			this->ui = new Ui::SafeSolution_UI();
			this->ui->setupUi(this);
		}

		CSafeSolutionDlg::~CSafeSolutionDlg()
		{

		}

		void CSafeSolutionDlg::slotHandIn()
		{
			this->ref_mpSafeSolution->setName(this->ui->solutionName->toPlainText().toLocal8Bit().constData());
			this->ref_mpSafeSolution->setAnalysisRadius(this->ui->analysisRadius->value());
			this->ref_mpSafeSolution->setSamplingDensity(this->ui->analysisDensity->value());
			this->ref_mpSafeSolution->setSamplingPointCount(this->ui->analysisPointCount->value());
			this->ref_mpSafeSolution->setAnalysisOffsetY(this->ui->verticalOffset->value());
			this->ref_mpSafeSolution->setMaxDrillAngle(this->ui->optimalAngle->value());
			return QDialog::accept();
		}

		void CSafeSolutionDlg::initialControl()
		{
			if (this->ref_mpSafeSolution)
			{
				this->ui->solutionName->setText(this->ref_mpSafeSolution->getName().c_str());
				this->ui->analysisRadius->setValue(this->ref_mpSafeSolution->getAnalysisRadius());
				this->ui->analysisDensity->setValue(this->ref_mpSafeSolution->getSamplingDensity());
				this->ui->analysisPointCount->setValue(this->ref_mpSafeSolution->getSamplingPointCount());
				this->ui->verticalOffset->setValue(this->ref_mpSafeSolution->getAnalysisOffsetY());
				this->ui->optimalAngle->setValue(this->ref_mpSafeSolution->getMaxDrillAngle());
			}
		}

		void CSafeSolutionDlg::bindingMineSafetySolution(VirtualMine::Solution::CMineSafetySolution* ref_pSafeSolution)
		{
			this->ref_mpSafeSolution = ref_pSafeSolution;
		}

		void CSafeSolutionDlg::slotCancel()
		{
			return QDialog::reject();
		}
	}
}