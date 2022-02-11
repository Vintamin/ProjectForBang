#include "vrmine/vr_generalui/addsolutiondlg.h"
#include "ui_addSolutionDlg.h"
#include "vrmine/vr_solutions/minesafetysolution.h"
#include <QFileDialog>

namespace VirtualMine
{
	namespace GeneralUI
	{
		CAddSolutionDlg::CAddSolutionDlg(QWidget *parent /* = 0 */)
			:QDialog(parent)
		{
			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			//setFixedSize(this->width(), this->height());
			this->ui = new Ui::addSolutionDlg();
			this->ui->setupUi(this);
			this->ui->lineEdit->setText(this->mSolutionPath.c_str());
			this->ref_mpGeoSpatialControl = NULL;
			this->mMineSafetySolution = NULL;
			connect(ui->selectPathButton,SIGNAL(clicked()),this,SLOT(slotSelectPath()));
			connect(ui->openSolutionPathButton,SIGNAL(clicked()),this,SLOT(slotOpenSolution()));
			connect(ui->closeSolutionButton,SIGNAL(clicked()),this,SLOT(slotCloseSolution()));

		}

		CAddSolutionDlg::~CAddSolutionDlg()
		{
			//setAttribute (Qt::WA_DeleteOnClose);
		}

		void  CAddSolutionDlg::slotSelectPath()
		{
			ui->lineEdit->text().clear();
			QFileInfo path;
			QString filePath = QFileDialog::getOpenFileName(this, "选择数据文件",path.dir().absolutePath(),NULL);
			if(NULL == filePath)
			{
				return;
			}
			this->mSolutionPath = filePath.toStdString();
			ui->lineEdit->setText(filePath);
			
		}
	
		void CAddSolutionDlg::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl)
		{
			this->ref_mpGeoSpatialControl = ref_pGeoSpatialControl;
		}

		VirtualMine::Scene::CGeoSpatialControl* CAddSolutionDlg::getGeoSpatialControl()
		{
			return this->ref_mpGeoSpatialControl;
		}

		void CAddSolutionDlg::slotCloseSolution()
		{
			/*VirtualMine::Project::CProjectManager::getSingletonPtr()->destroyScene();*/
			if (this->mMineSafetySolution)
			{
				this->mMineSafetySolution->endEditingSolution(true);
				delete this->mMineSafetySolution;
				this->mMineSafetySolution = NULL;
			}
		}

		VirtualMine::Solution::CMineSafetySolution* CAddSolutionDlg::getMineSafetySolution()
		{
			return this->mMineSafetySolution;
		}
		void CAddSolutionDlg::setMineSafetySolution(VirtualMine::Solution::CMineSafetySolution* ref_MineSafetySolution)
		{
			this->mMineSafetySolution = ref_MineSafetySolution;
		}


		void CAddSolutionDlg::slotOpenSolution()
		{

			/*	if (this->mMineSafetySolution)
			{
			delete this->mMineSafetySolution;
			this->mMineSafetySolution = NULL;
			}*/

			if (mSolutionPath == "")
			{
				return;
			}


			if( !this->mMineSafetySolution)
			{
				this->mMineSafetySolution =  new VirtualMine::Solution::CMineSafetySolution(mSolutionPath);				 
			}


			//this->mMineSafetySolution =  new VirtualMine::Solution::CMineSafetySolution(mSolutionPath);		
			if(	this->mMineSafetySolution)
			{	
				if (this->getGeoSpatialControl())
				{
					this->mMineSafetySolution->setGeoSpatialControl(this->getGeoSpatialControl());
				}

				//mMineSafetySolution->fromFile(mSolutionPath);	
				mMineSafetySolution->beginEditingSolution();		
				mMineSafetySolution->fromFile(mSolutionPath);	
				mMineSafetySolution->selectAccidentPoint();
				mMineSafetySolution->analyseSurfaceNearerPoints();
				mMineSafetySolution->analyseOptimalPoint();
				mMineSafetySolution->drillingToAccident();
				//mMineSafetySolution->endEditingSolution(true);
			}

		}
	}
}