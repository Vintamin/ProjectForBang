#include "vrmine/vr_generalui/simupropertyDlg.h"
#include "ui_simupropertyDlg.h"
#include "vrmine/vr_sqldatabasehelper/vr_sqldatabasehelper.h"
#include <QDomDocument>
namespace VirtualMine
{
	namespace GeneralUI
	{
		CSimuPropertyDlg::CSimuPropertyDlg(QWidget *parent /* = 0 */)
			:QDialog(parent)
		{
			setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint |Qt::Tool | Qt::X11BypassWindowManagerHint);
			setFixedSize(this->width(), this->height());
			this->ui = new Ui::SimuDlg();
			this->ui->setupUi(this);
		}

		CSimuPropertyDlg::~CSimuPropertyDlg()
		{
			setAttribute (Qt::WA_DeleteOnClose);
		}

		void CSimuPropertyDlg::setID(const std::string& substationID,const std::string& sensorID)
		{
			this->mSubstationID = substationID;
			this->mSensorID = sensorID;
		}

		void CSimuPropertyDlg::initialize(QDomDocument* doc)
		{
			if (!doc)
			{
				return;
			}
			QDomElement root = doc->documentElement();
			if (root.tagName() == "kj75")
			{
				QDomNode child = root.firstChild();
				while (!child.isNull())
				{
					if (child.toElement().tagName() == "data")
					{
						if (child.hasAttributes())
						{					
							QString  substationID = child.toElement().attribute("SubstationID");
							QString  sensorID = child.toElement().attribute("SensorID");
							QString defaultID = child.toElement().attribute("HisDefAutoID");
							/*if (substationID == QString::fromStdString(this->mSubstationID) &&
							sensorID == QString::fromStdString(this->mSensorID))*/
							if (defaultID == QString::fromStdString(this->mSubstationID))
							{
								this->ui->nameLabel->setText(child.toElement().attribute("DevName"));
								this->ui->typeLabel->setText(child.toElement().attribute("DevType"));
								this->ui->addressLabel->setText(child.toElement().attribute("Location"));

								this->ui->jianceLabel->setText(child.toElement().attribute("CurrValue") + QString(" / ") + child.toElement().attribute("MaxValue"));
								this->ui->statusLabel->setText(child.toElement().attribute("CurrState"));
								this->ui->baojingLabel->setText(child.toElement().attribute("AlertState") + QString(" / ") + child.toElement().attribute("AlertTime"));
								//this->ui->nameLabel->setText(child.toElement().attribute("DevName"));
								this->ui->kuidianLabel->setText(child.toElement().attribute("FeedState") + QString(" / ") + child.toElement().attribute("FeedTime"));
								this->ui->timeLabel->setText(child.toElement().attribute("CurrTime"));

							}
						}
					}
					child = child.nextSibling();
				}
			}

		}
	}
}