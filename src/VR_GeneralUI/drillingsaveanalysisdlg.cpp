#include "vrmine/vr_generalui/drillingsaveanalysisdlg.h"

#include "ui_drillingAnalysisdlg.h"
//#include "vrmine/vr_solutions/minesafetysolution.h"
#include <QFileDialog>
#include <QMessageBox>

namespace VirtualMine
{
	namespace GeneralUI
	{
		CDrillingSaveAnalysiDlg::CDrillingSaveAnalysiDlg(QWidget *parent /* = 0 */)
			:QDialog(parent)
		{
			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			//setFixedSize(this->width(), this->height());
			this->ui = new Ui::drillAnalysi();
			this->ui->setupUi(this);

			this->ref_mpGeoSpatialControl = NULL;
			this->mpMineSafeSolution = new VirtualMine::Solution::CMineSafetySolution("安全决策方案");

			connect(ui->beginBtn,SIGNAL(clicked()),this,SLOT(slotBegin()));		
			connect(ui->selectSavePointBtn,SIGNAL(clicked()),this,SLOT(slotSelectSavePoint()));		
			connect(ui->verticalPointBtn,SIGNAL(clicked()),this,SLOT(slotVerticalPoint()));		
			connect(ui->analysisOptPoint,SIGNAL(clicked()),this,SLOT(slotAnalysisOptPoint()));		
			connect(ui->drillingSaveBtn,SIGNAL(clicked()),this,SLOT(slotDrillingSave()));	
			connect(ui->endAnalysisBtn,SIGNAL(clicked()),this,SLOT(slotEndAnalysis()));
		}

		CDrillingSaveAnalysiDlg::~CDrillingSaveAnalysiDlg()
		{
			//setAttribute (Qt::WA_DeleteOnClose);
		}

		//void  CDrillingSaveAnalysiDlg::slotSelectPath()
		/*	{
		ui->lineEdit->text().clear();
		QFileInfo path;
		QString filePath = QFileDialog::getOpenFileName(this, "选择数据文件",path.dir().absolutePath(),NULL);
		if(NULL == filePath)
		{
		return;
		}
		this->mSolutionPath = filePath.toStdString();
		ui->lineEdit->setText(filePath);

		}*/
	
		void CDrillingSaveAnalysiDlg::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl)
		{
			this->ref_mpGeoSpatialControl = ref_pGeoSpatialControl;
			this->mpMineSafeSolution->setGeoSpatialControl(ref_pGeoSpatialControl);
		
		}

		VirtualMine::Scene::CGeoSpatialControl* CDrillingSaveAnalysiDlg::getGeoSpatialControl()
		{
			return this->ref_mpGeoSpatialControl;
		}

		void CDrillingSaveAnalysiDlg::slotBegin()
		{
			if (this->mpMineSafeSolution)
			{
				this->mpMineSafeSolution->beginEditingSolution();
			}
		}

		void CDrillingSaveAnalysiDlg::slotSelectSavePoint()
		{
			if (this->mpMineSafeSolution)
			{
				this->mpMineSafeSolution->selectAccidentPoint();
			}
		}

		void CDrillingSaveAnalysiDlg::slotVerticalPoint()
		{
			if (this->mpMineSafeSolution)
			{
				this->mpMineSafeSolution->analyseSurfaceNearerPoints();
			}
		}

		void CDrillingSaveAnalysiDlg::slotAnalysisOptPoint()
		{
			if (this->mpMineSafeSolution)
			{
				this->mpMineSafeSolution->analyseOptimalPoint();
			}
		}

		void CDrillingSaveAnalysiDlg::slotDrillingSave()
		{
			if (this->mpMineSafeSolution)
			{
				this->mpMineSafeSolution->drillingToAccident();
			}
		}

		VirtualMine::Solution::CMineSafetySolution* CDrillingSaveAnalysiDlg::getMineSafetySolution()
		{
			return this->mpMineSafeSolution;
		}

		void CDrillingSaveAnalysiDlg::setMineSafetySolution( VirtualMine::Solution::CMineSafetySolution* ref_MineSafetySolution )
		{
			this->mpMineSafeSolution = ref_MineSafetySolution;
		}

		void CDrillingSaveAnalysiDlg::slotEndAnalysis()
		{
			if (this->mpMineSafeSolution)
			{
				//QMessageBox::StandardButton button = QMessageBox::information(this,QString("消息提示"),QString("是否要保存当前方案？"),
				//	tr("确定"),tr("取消"));
				int button = QMessageBox::information(this,QString("消息提示"),QString("是否要保存当前方案？"),
					tr("确定"),tr("取消"));

				if (button == 0)
				{
					QString defaultPathToSave;
					QString filter(tr("solutionFile (*.sf)"));
					QString dstFilePath = QFileDialog::getSaveFileName(this, QString("另存方案文件"), defaultPathToSave,filter);
					if (dstFilePath != "")
					{
						this->mpMineSafeSolution->toFile(dstFilePath.toLocal8Bit().constData());
					}
					this->mpMineSafeSolution->endEditingSolution(true);
				}
				else
				{
					this->mpMineSafeSolution->endEditingSolution(false);
				}
				//this->mpMineSafeSolution->endEditingSolution();
			}

		}

	
	}
}