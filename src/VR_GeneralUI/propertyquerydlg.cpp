#include "vrmine/vr_generalui/propertyquerydlg.h"
#include "ui_propertyquerydlg.h"
#include "vrmine/vr_systemui/rayselectedtool.h"

#include <QMessageBox>
#include <QFileDialog>

namespace VirtualMine
{
	namespace GeneralUI
	{
		CPropertyQueryDlg::CPropertyQueryDlg(QWidget *parent /* = 0 */)
			:QDialog(parent)
		{
			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			//setFixedSize(this->width(), this->height());
			this->ui = new Ui::Form();
			this->ui->setupUi(this);
	
			this->ref_mpGeoSpatialControl = NULL;
			this->mStartSelect = false;
			connect(ui->propertyQueryBtn,SIGNAL(clicked()),this,SLOT(slotPropertyQuery()));
			connect(ui->clearQueryBtn,SIGNAL(clicked()),this,SLOT(slotClear()));
		

		}

		CPropertyQueryDlg::~CPropertyQueryDlg()
		{
			//setAttribute (Qt::WA_DeleteOnClose);
		}


	
		void CPropertyQueryDlg::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl)
		{
			this->ref_mpGeoSpatialControl = ref_pGeoSpatialControl;
		}

		VirtualMine::Scene::CGeoSpatialControl* CPropertyQueryDlg::getGeoSpatialControl()
		{
			return this->ref_mpGeoSpatialControl;
		}

		void CPropertyQueryDlg::slotPropertyQuery()
		{

			VirtualMine::SpatialInterface::ITool* pCurTool = this->getGeoSpatialControl()->getCurrentTool();
			if (pCurTool == NULL)
			{
				VirtualMine::SystemUI::CRaySelectedTool* pRaySelectedTool = new VirtualMine::SystemUI::CRaySelectedTool();
				pRaySelectedTool->setGeoSpatialControl(this->getGeoSpatialControl());
				this->getGeoSpatialControl()->setCurrentTool(pRaySelectedTool);
				//this->StartSelected = true;
				this->mStartSelect = true;
			}
			else
			{
				QMessageBox::warning(this,tr("提示"),tr("分析工具正在使用！"),
					tr("确定"),tr("取消"));
				/*if (this->mListner != NULL)
				{
				this->ui.vRControl->getGeoSpatialControl()->removeSceneQueryListener(this->mListner);
				delete this->mListner;
				this->mListner = NULL;
				}*/
				/*this->ui.vRControl->getGeoSpatialControl()->setCurrentTool(NULL);
				this->StartSelected = false;*/
			}
		}

		void CPropertyQueryDlg::slotClear()
		{
			this->getGeoSpatialControl()->setCurrentTool(NULL);
			this->mStartSelect = false;
		}

		bool CPropertyQueryDlg::getStartSelect()
		{
			return mStartSelect;
		}

		void CPropertyQueryDlg::setStartSelect( bool select )
		{
			this->mStartSelect = select;
		}

	

	
	}
}