#include "vrmine/vr_generalui/simuvalueDlg.h"
#include "ui_simuvalueDlg.h"
#include <QDir>
#include <QDomDocument>
#include <QFile>

#include "vrmine/vr_spatiallayer/modellayer.h"
#include "vrmine/vr_spatialobject/mine/modelobject.h"
#include "vrmine/vr_spatialinterface/igeoobject.h"
#include "vrmine/vr_spatialobject/mine/modelobject.h"
#include "vrmine/vr_spatialobject/geoproperty/cardmodelproperty.h"
#include "vrmine/vr_geometry/geometry/point.h"
#include "vrmine/vr_spatialinterface/igeoproperty.h"
#include <Ogre/Ogre.h>
#include <QTextCodec>
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
		CSimuValueDlg::CSimuValueDlg(QWidget *parent /* = 0 */)
			:QDialog(parent),ref_mgeoSpatialControl(NULL)
		{
			//支持中文
			QTextCodec *codec = QTextCodec::codecForName("GBK");	
			QTextCodec::setCodecForTr(codec);
			QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
			QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			setFixedSize(this->width(), this->height());
			this->ui = new Ui::SimuValueWidget();
			this->ui->setupUi(this);

			connect(this->ui->tableWidget,SIGNAL(doubleClicked(const QModelIndex &)),this,SLOT(slotDoubleClick(const QModelIndex &)));
		}

		CSimuValueDlg::~CSimuValueDlg()
		{
			setAttribute (Qt::WA_DeleteOnClose);
		}

		void CSimuValueDlg::initialize()
		{
			QString path = QDir::currentPath() + QString("/data/RealSimuXML.xml");
			
			QDomDocument doc("RealSimuXML");
			QFile file(path);
			if (!file.open(QIODevice::ReadOnly))
				return;
			if (!doc.setContent(&file)) {
				file.close();
				return;
			}
			file.close();

			QDomElement root = doc.documentElement();

			int count = 0;

			if (root.tagName() == "kj75")
			{
				QDomNode child = root.firstChild();
				while (!child.isNull())
				{
					if (child.toElement().tagName() == "data")
					{
						if (child.hasAttributes())
						{		

							this->ui->tableWidget->setRowCount(count+1); 
							this->ui->tableWidget->setRowHeight(count,20);
							QTableWidgetItem *vHeader5 = new QTableWidgetItem(QString::number(count));  
							this->ui->tableWidget->setVerticalHeaderItem(count, vHeader5);

							QTableWidgetItem* itemId = new QTableWidgetItem();
							itemId->setText(QString::number(count+1));
							this->ui->tableWidget->setItem(count,0,itemId);

							QTableWidgetItem* itemName = new QTableWidgetItem();
							itemName->setText(child.toElement().attribute("DevName"));
							this->ui->tableWidget->setItem(count,1,itemName);

							QTableWidgetItem* itemKind = new QTableWidgetItem();
							itemKind->setText(child.toElement().attribute("Location"));
							this->ui->tableWidget->setItem(count,2,itemKind);
							
							QTableWidgetItem* itemCurrentValue = new QTableWidgetItem();
							itemCurrentValue->setText(child.toElement().attribute("CurrValue"));
							this->ui->tableWidget->setItem(count,3,itemCurrentValue);

							QTableWidgetItem* itemMaxValue = new QTableWidgetItem();
							itemMaxValue->setText(child.toElement().attribute("MaxValue"));
							this->ui->tableWidget->setItem(count,4,itemMaxValue);

							QTableWidgetItem* itemState = new QTableWidgetItem();
							itemState->setText(child.toElement().attribute("CurrState"));
							this->ui->tableWidget->setItem(count,5,itemState);
						}
					}
					child = child.nextSibling();
					count++;
				}
			}
		}

		void CSimuValueDlg::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* geoSpatialControl)
		{
			this->ref_mgeoSpatialControl = geoSpatialControl;
		}

		void CSimuValueDlg::slotDoubleClick(QModelIndex index)
		{
		//	if (this->ref_mGeoSpatialControl == NULL || this->ref_mGeoSpatialControl->getScene() == NULL)
		//	{
		//		return;
		//	}
		//	int rowIndex = index.row();

		//	QString stationID = ui->peopleTableWidget->item(rowIndex,5)->text();
		//	QString cardID = ui->peopleTableWidget->item(rowIndex,6)->text();

		//	CModelLayer* modelLayer = dynamic_cast<CModelLayer*>(this->ref_mGeoSpatialControl->getScene()->getModelLayer());
		//	if (modelLayer == NULL)
		//	{
		//		return;
		//	}
		//	VirtualMine::SpatialInterface::GeoObjectVector objects;
		//	modelLayer->getGeoObjects(objects);
		//	if (objects.size() == 0)
		//	{
		//		return;
		//	}
		//	GeoObjectVector::iterator iteStart = objects.begin();
		//	GeoObjectVector::iterator iteEnd = objects.end();
		//	while (iteStart != iteEnd)
		//	{
		//		IGeoObject* object = dynamic_cast<IGeoObject*>(*iteStart);
		//		CModelObject* model = dynamic_cast<CModelObject*>(object);
		//		if (model != NULL)
		//		{
		//			CCardModelProperty* cardPro = dynamic_cast<CCardModelProperty*>(model->getGeoProperty());
		//			if (cardPro != NULL)
		//			{
		//				//if ((cardPro->getStationID() == stationID.toStdString()) && (cardPro->getCardID() == cardID.toStdString()))
		//				std::string sId = cardPro->getStationID();
		//				std::string cId = cardPro->getCardID();

		//				int s = Ogre::StringConverter::parseInt(sId);
		//				int c = Ogre::StringConverter::parseInt(cId);

		//				if (s == stationID.toInt() && c == cardID.toInt())
		//				{
		//					CPoint* pt = dynamic_cast<CPoint*>(model->getGeometry());
		//					if (pt!=NULL)
		//					{
		//						ref_mGeoSpatialControl->flyTo(pt->getX(),pt->getY(),pt->getZ());	
		//					}
		//				}


		//			}
		//		}
		//		iteStart++;
		//	}
		//}
		}
	}
}