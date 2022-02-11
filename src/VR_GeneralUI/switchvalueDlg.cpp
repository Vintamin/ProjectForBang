#include "vrmine/vr_generalui/switchvalueDlg.h"
#include "ui_switchvalueDlg.h"
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
		CSwitchValueDlg::CSwitchValueDlg(QWidget *parent /* = 0 */)
			:QDialog(parent)
		{
			//支持中文
			QTextCodec *codec = QTextCodec::codecForName("GBK");	
			QTextCodec::setCodecForTr(codec);
			QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
			QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			setFixedSize(this->width(), this->height());
			this->ui = new Ui::SwitchValueWidget;
			this->ui->setupUi(this);

			//connect(this->ui->tableWidget,SIGNAL(doubleClicked(const QModelIndex &)),this,SLOT(slotDoubleClick(const QModelIndex &)));
		}

		CSwitchValueDlg::~CSwitchValueDlg()
		{
			setAttribute (Qt::WA_DeleteOnClose);
		}

		void CSwitchValueDlg::initialize()
		{
			QString path = QDir::currentPath() + QString("/data/RealSwitchXML.xml");

			QDomDocument doc("RealSwitchXML");
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

							/*QTableWidgetItem* itemMaxValue = new QTableWidgetItem();
							itemMaxValue->setText(child.toElement().attribute("MaxValue"));
							this->ui->tableWidget->setItem(count,4,itemMaxValue);*/

							QTableWidgetItem* itemState = new QTableWidgetItem();
							itemState->setText(child.toElement().attribute("CurrState"));
							this->ui->tableWidget->setItem(count,4,itemState);
						}
					}
					child = child.nextSibling();
					count++;
				}
			}
		}
	}
}