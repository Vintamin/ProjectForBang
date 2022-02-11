#include "vrmine/vr_generalui/allmonitorDlg.h"
#include "ui_allmonitorDlg.h"
#include <QDate>
#include "vrmine/vr_generalui/simuvalueDlg.h"
#include "vrmine/vr_generalui/switchvalueDlg.h"
namespace VirtualMine
{
	namespace GeneralUI
	{
		CAllMonitorDlg::CAllMonitorDlg(QWidget *parent /* = 0 */)
			:QDialog(parent),ref_geoSpatialControl(NULL)
		{
			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			setFixedSize(this->width(), this->height());
			this->ui = new Ui::AllMonitorWidget();
			this->ui->setupUi(this);

			connect(ui->simubtn,SIGNAL(pressed()),this,SLOT(slotShowSimuValue()));
			connect(ui->switchbtn,SIGNAL(pressed()),this,SLOT(slotShowSwitchValue()));
		}

		CAllMonitorDlg::~CAllMonitorDlg()
		{
			setAttribute (Qt::WA_DeleteOnClose);
		}

		void CAllMonitorDlg::initialize()
		{
			QDateTime current_date_time = QDateTime::currentDateTime();
			QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
			this->ui->timetext->setText(current_date);
		}

		void CAllMonitorDlg::slotShowSimuValue()
		{
			CSimuValueDlg* dlg = new CSimuValueDlg();
			dlg->initialize();
			dlg->exec();
		}

		void CAllMonitorDlg::slotShowSwitchValue()
		{
			CSwitchValueDlg* dlg = new CSwitchValueDlg();
			dlg->initialize();
			dlg->exec();
		}

		void CAllMonitorDlg::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* geoSpatialControl)
		{
			this->ref_geoSpatialControl = geoSpatialControl;
		}
	}
}