#include "vrmine/vr_generalui/realpeoplequeryDlg.h"
#include "ui_realpeopleDlg.h"
#include <QSqlQuery>
#include <QDateTime>
#include "vrmine/vr_spatiallayer/modellayer.h"
#include "vrmine/vr_spatialobject/mine/modelobject.h"
#include "vrmine/vr_spatialinterface/igeoobject.h"
#include "vrmine/vr_spatialobject/mine/modelobject.h"
#include "vrmine/vr_spatialobject/geoproperty/cardmodelproperty.h"
#include "vrmine/vr_geometry/geometry/point.h"
#include "vrmine/vr_spatialinterface/igeoproperty.h"
#include <Ogre/Ogre.h>
using namespace VirtualMine::DataBaseManager;
using namespace VirtualMine::SpatialLayer;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Geometry;
using namespace VirtualMine::GeoProperty;
using namespace VirtualMine::Mine;
using namespace Ogre;
namespace VirtualMine
{
	namespace GeneralUI
	{
		CRealPeopleQueryDlg::CRealPeopleQueryDlg(QWidget *parent /* = 0 */)
			:QDialog(parent),ref_mGeoSpatialControl(NULL)
		{
			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			setFixedSize(this->width(), this->height());
			this->ui = new Ui::realpeoplewidget();
			this->ui->setupUi(this);

			connect(this->ui->peopleTableWidget,SIGNAL(pressed(const QModelIndex &)),this,SLOT(test(const QModelIndex &)));
			connect(this->ui->peopleTableWidget,SIGNAL(doubleClicked(const QModelIndex &)),this,SLOT(slotDoubleClick(const QModelIndex &)));
		}

		CRealPeopleQueryDlg::~CRealPeopleQueryDlg()
		{
			setAttribute (Qt::WA_DeleteOnClose);
		}

		void CRealPeopleQueryDlg::initialize()
		{
			QSqlQuery query = CDataBaseManager::getSingletonPtr()->execSqlString("exec up_loadCardInf");
			int count = 0;
			QDateTime current_date_time = QDateTime::currentDateTime();
			QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
			while (query.next())
			{
				this->ui->peopleTableWidget->setRowCount(count+1); 
				this->ui->peopleTableWidget->setRowHeight(count,20);
				QTableWidgetItem *vHeader5 = new QTableWidgetItem(QString::number(count));  
				this->ui->peopleTableWidget->setVerticalHeaderItem(count, vHeader5);

				QTableWidgetItem* itemId = new QTableWidgetItem();
				itemId->setText(QString::number(count+1));
				this->ui->peopleTableWidget->setItem(count,0,itemId);

				QTableWidgetItem* itemName = new QTableWidgetItem();
				itemName->setText(query.value(2).toString());
				this->ui->peopleTableWidget->setItem(count,1,itemName);

				QTableWidgetItem* itemKind = new QTableWidgetItem();
				itemKind->setText(query.value(4).toString());
				this->ui->peopleTableWidget->setItem(count,2,itemKind);

				/*QTableWidgetItem* itemPos = new QTableWidgetItem();
				itemPos->setText(query.value(10).toString());
				this->ui->peopleTableWidget->setItem(count,3,itemPos);*/

				QTableWidgetItem* itemEnter = new QTableWidgetItem();
				itemEnter->setText(query.value(12).toString());
				this->ui->peopleTableWidget->setItem(count,3,itemEnter);

				QTableWidgetItem* itemExit = new QTableWidgetItem();
				itemExit->setText(query.value(13).toString());
				this->ui->peopleTableWidget->setItem(count,4,itemExit);

				QTableWidgetItem* itemStation = new QTableWidgetItem();
				itemStation->setText(query.value(10).toString());
				this->ui->peopleTableWidget->setItem(count,5,itemStation);

				QTableWidgetItem* itemCard = new QTableWidgetItem();
				itemCard->setText(query.value(11).toString());
				this->ui->peopleTableWidget->setItem(count,6,itemCard);
				count++;
			}

			this->ui->peopleCountLabel->setText(QString::number(count));
			this->ui->timeLabel->setText(current_date);
		}

		void CRealPeopleQueryDlg::test(const QModelIndex & index)
		{

		}

		void CRealPeopleQueryDlg::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* geoSpatialControl)
		{
			this->ref_mGeoSpatialControl = geoSpatialControl;
		}

		void CRealPeopleQueryDlg::slotDoubleClick(QModelIndex index)
		{

			if (this->ref_mGeoSpatialControl == NULL || this->ref_mGeoSpatialControl->getScene() == NULL)
			{
				return;
			}
			int rowIndex = index.row();

			QString stationID = ui->peopleTableWidget->item(rowIndex,5)->text();
			QString cardID = ui->peopleTableWidget->item(rowIndex,6)->text();

			CModelLayer* modelLayer = dynamic_cast<CModelLayer*>(this->ref_mGeoSpatialControl->getScene()->getModelLayer());
			if (modelLayer == NULL)
			{
				return;
			}
			VirtualMine::SpatialInterface::GeoObjectVector objects;
			modelLayer->getGeoObjects(objects);
			if (objects.size() == 0)
			{
				return;
			}
			GeoObjectVector::iterator iteStart = objects.begin();
			GeoObjectVector::iterator iteEnd = objects.end();
			while (iteStart != iteEnd)
			{
				IGeoObject* object = dynamic_cast<IGeoObject*>(*iteStart);
				CModelObject* model = dynamic_cast<CModelObject*>(object);
				if (model != NULL)
				{
					CCardModelProperty* cardPro = dynamic_cast<CCardModelProperty*>(model->getGeoProperty());
					if (cardPro != NULL)
					{
						//if ((cardPro->getStationID() == stationID.toStdString()) && (cardPro->getCardID() == cardID.toStdString()))
						std::string sId = cardPro->getStationID();
						std::string cId = cardPro->getCardID();

						int s = Ogre::StringConverter::parseInt(sId);
						int c = Ogre::StringConverter::parseInt(cId);

						if (s == stationID.toInt() && c == cardID.toInt())
						{
							CPoint* pt = dynamic_cast<CPoint*>(model->getGeometry());
							if (pt!=NULL)
							{
								ref_mGeoSpatialControl->flyTo(pt->getX(),pt->getY(),pt->getZ());	
							}
						}
						
						
					}
				}
				iteStart++;
			}

				
		}
	}
}