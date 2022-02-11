
#include "vrmine/vr_generalui/querylanewaydlg.h"
#include "ui_queryLanewayByName.h"
#include "vrmine/vr_spatiallayer/lanwaylayer.h"
#include "vrmine/vr_spatialrender/spatialrender/lanewayrenderableobject.h"
#include "vrmine/vr_spatialobject/mine/lanwayobject.h"
#include <QKeyEvent>

using namespace VirtualMine::GeneralUI;
using namespace std;
using namespace Ogre;


CQueryLanewayDlg::CQueryLanewayDlg(QWidget *parent)
	:QDialog(parent)
{
	setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
	//setFixedSize(this->width(), this->height());
	this->ui = new Ui::queryLanewayForm();
	this->ui->setupUi(this);
	this->ref_mpGeoSpatialControl = NULL;
	isfromCombox=false;

	connect(ui->queryBtn,SIGNAL(clicked()),this,SLOT(slotQueryLaneway()));
	connect(ui->lineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(slotLineditNamechanged(const QString &)));
	connect(ui->queryLanewayCmb,SIGNAL(activated(QString)),this,SLOT(slotLineditName(const QString &)));
	
	

}


CQueryLanewayDlg::~CQueryLanewayDlg()
{

}


void CQueryLanewayDlg::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl)
{
	this->ref_mpGeoSpatialControl = ref_pGeoSpatialControl;
}


VirtualMine::Scene::CGeoSpatialControl* CQueryLanewayDlg::getGeoSpatialControl()
{
	return ref_mpGeoSpatialControl;
}



void CQueryLanewayDlg::slotQueryLaneway()
{
	QDialog::accept();

}

std::string VirtualMine::GeneralUI::CQueryLanewayDlg::getLanewayName()
{
	return this->ui->lineEdit->text().toStdString();
}

void VirtualMine::GeneralUI::CQueryLanewayDlg::slotLineditNamechanged(const QString &)
{
	if (isfromCombox==false)
	{
		if (this->ui->lineEdit->text()!=NULL)
		{
			this->ui->queryLanewayCmb->clear();

			for (std::vector<string>::iterator iter =lanewayAllName.begin(); iter != lanewayAllName.end(); iter++)
			{

				String strtemp = (String)(*iter);
				String strText=this->ui->lineEdit->text().toStdString();
				if (strtemp.find(strText)!=String::npos)
				{
					QString str = QString::fromStdString(strtemp);
					this->ui->queryLanewayCmb->addItem(str);
				}
			}
			this->ui->queryLanewayCmb->showPopup();
		}
		else
		{
			setQueryLanewayCmbItems();
		}

	}

	isfromCombox=false;

				
}


void VirtualMine::GeneralUI::CQueryLanewayDlg::initialsize()
{
	if (this->getGeoSpatialControl()->getScene()==NULL)
	{
		return;
	}

	VirtualMine::SpatialLayer::CLanewayLayer* lanewaylayer = dynamic_cast<VirtualMine::SpatialLayer::CLanewayLayer*>(this->getGeoSpatialControl()->getScene()->getLanewayLayer());

	if (lanewaylayer == NULL)
	{
		return;

	}

	VirtualMine::SpatialRender::CLanewayRenderableObject* lanewayRenderObject = dynamic_cast<VirtualMine::SpatialRender::CLanewayRenderableObject*> (lanewaylayer->getRenderableObject());

	if (lanewayRenderObject == NULL)
	{
		return;

	}

	int lanewayobjectCount = lanewayRenderObject->getGeoObjectCount();

	VirtualMine::SpatialInterface::GeoObjectVector geoobjectVec = lanewayRenderObject->getGeoObjectVec();

	if (lanewayobjectCount > 0)
	{
		for (int i = 0; i < lanewayobjectCount; i++)
		{
			VirtualMine::Mine::CLaneWayObject* lanewayObject = dynamic_cast<VirtualMine::Mine::CLaneWayObject*>(geoobjectVec.at(i));
			Ogre::String lanewayNametemp = lanewayObject->getName();
			lanewayAllName.push_back(lanewayNametemp);

		}
	}

	
}

void VirtualMine::GeneralUI::CQueryLanewayDlg::slotLineditName(const QString &)
{
	isfromCombox = true;
	this->ui->lineEdit->setText(this->ui->queryLanewayCmb->currentText());

}

void VirtualMine::GeneralUI::CQueryLanewayDlg::setQueryLanewayCmbItems()
{
	for (std::vector<string>::iterator iter =lanewayAllName.begin(); iter != lanewayAllName.end(); iter++)
	{
		String strtemp = (String)(*iter);
		QString str = QString::fromStdString(strtemp);
		this->ui->queryLanewayCmb->addItem(str);
	}
}
