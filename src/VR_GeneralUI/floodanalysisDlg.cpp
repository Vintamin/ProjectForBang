#include "vrmine/vr_generalui/floodanalysisDlg.h"
#include "ui_floodanalysisDlg.h"
//#include <qpalette.h>
#include <QColorDialog>
#include <QPalette>
#include <QString>
#include "ui_tourPropertyDlg.h"
#include <QFileDialog>
#include <QFile>


namespace VirtualMine
{
	namespace GeneralUI
	{

		CFloodAnalysisDlg::CFloodAnalysisDlg(QWidget *parent)
			:QDialog(parent),ref_mpFloodAnalysisTool(NULL)
		{
			this->ui = new Ui::FloodAnalysis_UI();
			this->ui->setupUi(this);
		}

		CFloodAnalysisDlg::~CFloodAnalysisDlg()
		{

		}

		void CFloodAnalysisDlg::setFloodAnalysisTool(VirtualMine::SystemUI::CFloodAnalysisTool* ref_pFloodAnalysisTool)
		{
			this->ref_mpFloodAnalysisTool = ref_pFloodAnalysisTool;
		}

		void CFloodAnalysisDlg::slotSetWaterHeight(double value)
		{
			if (this->ref_mpFloodAnalysisTool)
			{
				this->ref_mpFloodAnalysisTool->setWaterHeight(this->ui->waterHeight->value());
			}
		}

		void CFloodAnalysisDlg::slotSelectWaterColor()
		{
			QPalette colorPalette = this->ui->selectWaterColour->palette();   
		

			QColor waterColor = QColorDialog::getColor(
				QColor(this->ref_mpFloodAnalysisTool->getWaterColor().r*255,
				this->ref_mpFloodAnalysisTool->getWaterColor().g*255,
				this->ref_mpFloodAnalysisTool->getWaterColor().b*255,
				this->ref_mpFloodAnalysisTool->getWaterColor().a*255),this);

			qreal r,g,b,a;
			waterColor.getRgbF(&r,&g,&b,&a);

			Ogre::ColourValue waterColorValue(r,g,b,a);


			//colorPalette.setColor(QColorGroup::Button,QColor(255,0,0));		
			//colorPalette.setColor(QColorGroup::Button,waterColor);
			
		/*	
			colorPalette.setColor(QPalette::Button,waterColor);
			this->ui->selectWaterColour->setPalette(colorPalette);  */	
			
			QString sss = "QPushButton{background-color:rgb(" + QString::number(waterColor.red()) +  "," + QString::number(waterColor.green()) + "," + QString::number(waterColor.blue()) + ")}";

			ui->selectWaterColour->setStyleSheet(sss);
			if (this->ref_mpFloodAnalysisTool)
			{
				this->ref_mpFloodAnalysisTool->setWaterColor(waterColorValue);
			}

		}


		void CFloodAnalysisDlg::initialControl()
		{
			if (NULL == this->ref_mpFloodAnalysisTool)
			{
				return;
			}
			/*Qt::CheckState checkState = this->ref_mpFloodAnalysisTool->getUseFloodAnalysis() ? Qt::Checked : Qt::Unchecked; */
			/*this->ui->useFloodAnalysis->setChecked(this->ref_mpFloodAnalysisTool->getUseFloodAnalysis());*/
			this->ui->waterHeight->setValue(this->ref_mpFloodAnalysisTool->getWaterHeight());
			
			this->ui->useWaterFlow->setChecked(this->ref_mpFloodAnalysisTool->getUseFloatEffect());
			this->ui->showWaterSurface->setChecked(this->ref_mpFloodAnalysisTool->getWaterSurfaceState());
			QString sss = "QPushButton{background-color:rgb(" + 
				QString::number(this->ref_mpFloodAnalysisTool->getWaterColor().r * 255) +  "," + 
				QString::number(this->ref_mpFloodAnalysisTool->getWaterColor().g * 255) +  "," + 
				QString::number(this->ref_mpFloodAnalysisTool->getWaterColor().b * 255) +  "," +
				QString::number(this->ref_mpFloodAnalysisTool->getWaterColor().a * 255) +
				")}";
			ui->selectWaterColour->setStyleSheet(sss);
			this->ui->floodDescription->append("淹没分析：水面高度发生变化时，\n在水面以下的巷道被淹没");
		}

		void CFloodAnalysisDlg::slotShowWaterSurface(bool value)
		{
			if (this->ref_mpFloodAnalysisTool)
			{
				this->ref_mpFloodAnalysisTool->setWaterSurfaceState(value);
			}
		}

		void CFloodAnalysisDlg::slotWaterSurfaceEffect(bool value)
		{
			if (this->ref_mpFloodAnalysisTool)
			{
				this->ref_mpFloodAnalysisTool->setUseFloatEffect(value);
			}
		}

		void CFloodAnalysisDlg::slotHandIn()
		{
			QDialog::accept();
		}

		CTourPropertyDlg::CTourPropertyDlg(QWidget *parent)
			:QDialog(parent)
		{
			this->ui = new Ui::TourPropertyUI();
			this->ui->setupUi(this);
			this->mTourPath = "";
		}

		CTourPropertyDlg::~CTourPropertyDlg()
		{


		}
		void CTourPropertyDlg::slotSelectPath()
		{
			QString defaultPathToSave;
			QString filter(tr("kml(*.kml)"));
			QString dstFilePath = QFileDialog::getOpenFileName(this, QString("打开游览文件"), defaultPathToSave,filter);
			if (QFile::exists(dstFilePath))
			{
				this->ui->tourPath->setText(dstFilePath.toStdString().c_str());
			}
		}

		void CTourPropertyDlg::slotLoadTour()
		{
			this->mTourPath = this->ui->tourPath->text().toStdString();
			return QDialog::accept();
		}

		void CTourPropertyDlg::slotUnloadTour()
		{

		}

		std::string CTourPropertyDlg::getTourPath()
		{
			return this->mTourPath;
		}

		void CTourPropertyDlg::slotClose()
		{
			QDialog::close();
		}
	}
}