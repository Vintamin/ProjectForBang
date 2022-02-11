#include "vrmine/vr_generalui/spatialsnalysisdlg.h"
#include "ui_spaltialanalysidlg.h"
//#include "vrmine/vr_solutions/minesafetysolution.h"
#include "vrmine\vr_spatialanalyse\spatialanalyse\distancemeasuretool.h"
#include "vrmine\vr_spatialanalyse\spatialanalyse\pointmeasuretool.h"
#include <QFileDialog>
#include <QMessageBox>

namespace VirtualMine
{
	namespace GeneralUI
	{
		CSpaltialAnalysiDlg::CSpaltialAnalysiDlg(QWidget *parent /* = 0 */)
			:QDialog(parent)
		{
			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			//setFixedSize(this->width(), this->height());
			this->ui = new Ui::SpatialForm();
			this->ui->setupUi(this);

			this->ref_mpGeoSpatialControl = NULL;


			connect(ui->pointMeasureBtn,SIGNAL(clicked()),this,SLOT(slotPointMessure()));
			connect(ui->distanceMeasureBtn,SIGNAL(clicked()),this,SLOT(slotDistanceMeasure()));
		    connect(ui->clearMeasureBtn,SIGNAL(clicked()),this,SLOT(slotCleatMeasure()));
		}

		CSpaltialAnalysiDlg::~CSpaltialAnalysiDlg()
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
	
		void CSpaltialAnalysiDlg::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl)
		{
			this->ref_mpGeoSpatialControl = ref_pGeoSpatialControl;
			//this->mpMineSafeSolution->setGeoSpatialControl(ref_pGeoSpatialControl);
		
		}

		VirtualMine::Scene::CGeoSpatialControl* CSpaltialAnalysiDlg::getGeoSpatialControl()
		{
			return this->ref_mpGeoSpatialControl;
		}


		void CSpaltialAnalysiDlg::slotPointMessure()
		{
			VirtualMine::SpatialInterface::ITool* pCurTool = this->getGeoSpatialControl()->getCurrentTool();
			if (pCurTool == NULL)
			{
				VirtualMine::SpatialAnalyse::CPointMeasureTool* pointMeasureTool = new VirtualMine::SpatialAnalyse::CPointMeasureTool(this->getGeoSpatialControl());
				this->getGeoSpatialControl()->setCurrentTool(pointMeasureTool);	
			}
			else
			{
				QMessageBox::warning(this,tr("提示"),tr("分析工具正在使用！"),
					tr("确定"),tr("取消"));
			}
		}

		void CSpaltialAnalysiDlg::slotDistanceMeasure()
		{
			VirtualMine::SpatialInterface::ITool* pCurTool = this->getGeoSpatialControl()->getCurrentTool();
			if (pCurTool == NULL)
			{
				VirtualMine::SpatialAnalyse::CDistanceMeasureTool* distanceMeasureTool = new VirtualMine::SpatialAnalyse::CDistanceMeasureTool(this->getGeoSpatialControl());
				this->getGeoSpatialControl()->setCurrentTool(distanceMeasureTool);	
			}
			else
			{
				QMessageBox::warning(this,tr("提示"),tr("分析工具正在使用！"),
					tr("确定"),tr("取消"));
			}
		}
		void CSpaltialAnalysiDlg::slotCleatMeasure()
		{
			VirtualMine::SpatialInterface::ITool* pCurTool = this->getGeoSpatialControl()->getCurrentTool();
			VirtualMine::SpatialAnalyse::CSpatialMeasureTool* spatialTool = dynamic_cast<VirtualMine::SpatialAnalyse::CSpatialMeasureTool*>(pCurTool);
			if (spatialTool != NULL)
			{
				spatialTool->clear();
				this->getGeoSpatialControl()->setCurrentTool(NULL);
				delete spatialTool;
			}
		}


	
	}
}