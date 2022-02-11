#include "vrmine/vr_generalui/touranalysisdlg.h"
#include "ui_touranalysisdlg.h"


#include <QFileDialog>
#include <QMessageBox>

namespace VirtualMine
{
	namespace GeneralUI
	{
		CTourAnalysisDlg::CTourAnalysisDlg(QWidget *parent /* = 0 */)
			:QDialog(parent)
		{
			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			//setFixedSize(this->width(), this->height());
			this->ui = new Ui::touranalysis;
			this->ui->setupUi(this);

			this->ref_mpGeoSpatialControl = NULL;
			this->mpTourObject = NULL;

		    connect(ui->luzhiToutBtn,SIGNAL(clicked()),this,SLOT(slotLuzhiTour()));
			connect(ui->jieshuTourBtn,SIGNAL(clicked()),this,SLOT(slotJieshuTour()));
			connect(ui->playTourBtn,SIGNAL(clicked()),this,SLOT(slotPlayTour()));
			connect(ui->pauseTour,SIGNAL(clicked()),this,SLOT(slotPauseTour()));
			connect(ui->stopPlayBtn,SIGNAL(clicked()),this,SLOT(slotStopTour()));
			connect(ui->clearTourBtn,SIGNAL(clicked()),this,SLOT(slotClearTour()));
		
		}

		CTourAnalysisDlg::~CTourAnalysisDlg()
		{
			//setAttribute (Qt::WA_DeleteOnClose);
		}

	
	
	
		void CTourAnalysisDlg::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl)
		{
			this->ref_mpGeoSpatialControl = ref_pGeoSpatialControl;
			//this->mpMineSafeSolution->setGeoSpatialControl(ref_pGeoSpatialControl);
		
		}

		VirtualMine::Scene::CGeoSpatialControl* CTourAnalysisDlg::getGeoSpatialControl()
		{
			return this->ref_mpGeoSpatialControl;
		}

		void CTourAnalysisDlg::slotLuzhiTour()
		{
			if (this->mpTourObject)
			{
				int button = QMessageBox::warning(this,tr("提示"),tr("是否要清除当前游览？"),
					tr("确定"),tr("取消"));
				if (button == 0)
				{
					delete this->mpTourObject;
					this->mpTourObject = NULL;
				}
				else
				{
					return;
				}
			}
			if (this->mpTourObject == NULL)
			{
				this->mpTourObject = new VirtualMine::Kml::CTourObject(this->getGeoSpatialControl());
			}
			if (this->mpTourObject->getState() == VirtualMine::Kml::TS_PLAY_P)
			{
				QMessageBox::warning(this,tr("提示"),tr("当前游览处于播放状态，\n请先停止播放！"),
					tr("确定"));
				return;
			}
			this->mpTourObject->startRecord();
		}

		void CTourAnalysisDlg::slotJieshuTour()
		{
			if (this->mpTourObject == NULL)
			{
				QMessageBox::warning(this,tr("提示"),tr("当前没有操作的游览！"),
					tr("确定"));
				return;
			}
			if (this->mpTourObject->getState() != VirtualMine::Kml::TS_RECORD_R)
			{
				QMessageBox::warning(this,tr("提示"),tr("当前没有正在录制的游览！"),
					tr("确定"));
				return;
			}
			this->mpTourObject->stopRecord();
		}

		void CTourAnalysisDlg::slotPlayTour()
		{
			if (this->mpTourObject == NULL)
			{
				QMessageBox::warning(this,tr("提示"),tr("当前没有操作的游览！"),
					tr("确定"));
				return;
			}
			if (this->mpTourObject->getState() == VirtualMine::Kml::TS_RECORD_R)
			{
				QMessageBox::warning(this,tr("提示"),tr("您还不能播放游览！"),
					tr("确定"));
				return;
			}
			this->mpTourObject->startPlay();
		}

		void CTourAnalysisDlg::slotPauseTour()
		{
			if (this->mpTourObject == NULL)
			{
				QMessageBox::warning(this,tr("提示"),tr("当前没有操作的游览！"),
					tr("确定"));
				return;
			}
			if (this->mpTourObject->getState() != VirtualMine::Kml::TS_PLAY_P)
			{
				QMessageBox::warning(this,tr("提示"),tr("游览未处于播放状态，\n您不能暂停游览！"),
					tr("确定"));
				return;
			}
			this->mpTourObject->pausePlay();
		}

		void CTourAnalysisDlg::slotStopTour()
		{
			if (this->mpTourObject == NULL)
			{
				QMessageBox::warning(this,tr("提示"),tr("当前没有操作的游览！"),
					tr("确定"));
				return;
			}
			if (this->mpTourObject->getState() != VirtualMine::Kml::TS_PLAY_P)
			{
				QMessageBox::warning(this,tr("提示"),tr("游览未处于播放状态，\n您不能终止游览！"),
					tr("确定"));
				return;
			}
			this->mpTourObject->stopPlay();
		}

		void CTourAnalysisDlg::slotClearTour()
		{
			if (this->mpTourObject)
			{
				if (this->mpTourObject->getPath() == "")
				{
					int button = QMessageBox::question(this, tr("消息提示"),  
						QString(tr("是否要保存当前游览?")), tr("确定"),tr("取消"));  
					if (button == 0)
					{
						QString defaultPathToSave;
						QString filter(tr("kml (*.kml)"));
						QString dstFilePath = QFileDialog::getSaveFileName(this, QString("另存游览文件"), defaultPathToSave,filter);
						if (dstFilePath != "")
						{
							this->mpTourObject->toFile(dstFilePath.toStdString());
						}
					}
				}
				delete this->mpTourObject;
				this->mpTourObject = NULL;
			}
		}



	
	}
}