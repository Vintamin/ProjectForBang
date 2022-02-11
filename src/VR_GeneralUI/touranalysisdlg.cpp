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
				int button = QMessageBox::warning(this,tr("��ʾ"),tr("�Ƿ�Ҫ�����ǰ������"),
					tr("ȷ��"),tr("ȡ��"));
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
				QMessageBox::warning(this,tr("��ʾ"),tr("��ǰ�������ڲ���״̬��\n����ֹͣ���ţ�"),
					tr("ȷ��"));
				return;
			}
			this->mpTourObject->startRecord();
		}

		void CTourAnalysisDlg::slotJieshuTour()
		{
			if (this->mpTourObject == NULL)
			{
				QMessageBox::warning(this,tr("��ʾ"),tr("��ǰû�в�����������"),
					tr("ȷ��"));
				return;
			}
			if (this->mpTourObject->getState() != VirtualMine::Kml::TS_RECORD_R)
			{
				QMessageBox::warning(this,tr("��ʾ"),tr("��ǰû������¼�Ƶ�������"),
					tr("ȷ��"));
				return;
			}
			this->mpTourObject->stopRecord();
		}

		void CTourAnalysisDlg::slotPlayTour()
		{
			if (this->mpTourObject == NULL)
			{
				QMessageBox::warning(this,tr("��ʾ"),tr("��ǰû�в�����������"),
					tr("ȷ��"));
				return;
			}
			if (this->mpTourObject->getState() == VirtualMine::Kml::TS_RECORD_R)
			{
				QMessageBox::warning(this,tr("��ʾ"),tr("�������ܲ���������"),
					tr("ȷ��"));
				return;
			}
			this->mpTourObject->startPlay();
		}

		void CTourAnalysisDlg::slotPauseTour()
		{
			if (this->mpTourObject == NULL)
			{
				QMessageBox::warning(this,tr("��ʾ"),tr("��ǰû�в�����������"),
					tr("ȷ��"));
				return;
			}
			if (this->mpTourObject->getState() != VirtualMine::Kml::TS_PLAY_P)
			{
				QMessageBox::warning(this,tr("��ʾ"),tr("����δ���ڲ���״̬��\n��������ͣ������"),
					tr("ȷ��"));
				return;
			}
			this->mpTourObject->pausePlay();
		}

		void CTourAnalysisDlg::slotStopTour()
		{
			if (this->mpTourObject == NULL)
			{
				QMessageBox::warning(this,tr("��ʾ"),tr("��ǰû�в�����������"),
					tr("ȷ��"));
				return;
			}
			if (this->mpTourObject->getState() != VirtualMine::Kml::TS_PLAY_P)
			{
				QMessageBox::warning(this,tr("��ʾ"),tr("����δ���ڲ���״̬��\n��������ֹ������"),
					tr("ȷ��"));
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
					int button = QMessageBox::question(this, tr("��Ϣ��ʾ"),  
						QString(tr("�Ƿ�Ҫ���浱ǰ����?")), tr("ȷ��"),tr("ȡ��"));  
					if (button == 0)
					{
						QString defaultPathToSave;
						QString filter(tr("kml (*.kml)"));
						QString dstFilePath = QFileDialog::getSaveFileName(this, QString("��������ļ�"), defaultPathToSave,filter);
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