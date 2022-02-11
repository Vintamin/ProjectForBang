#include "vrmine/vr_generalui/layerpropertyDlg.h"
#include "ui_layerpropertyDlg.h"
#include "ui_datasetpropertyDlg.h"
#include "ui_createnewsceneDlg.h"
#include "ui_layeraddDlg.h"
#include "vrmine/vr_projectmanager/project/projectmanager.h"
#include "vrmine/vr_databaseengine/database/logicdataset.h"
#include "vrmine/vr_databaseengine/database/logicfeature.h"
#include "vrmine/vr_databaseengine/database/idatasourcemanager.h"
#include <QMessageBox>
#include "vrmine/vr_core/geodatatype.h"
#include "ogre/OgreStringConverter.h"

using namespace VirtualMine::Database;

namespace VirtualMine
{
	namespace GeneralUI
	{

		CLayerPropertyDlg::CLayerPropertyDlg(QWidget *parent)
			:QDialog(parent),ref_mpLayer(NULL)
		{
			this->ui = new Ui::LayerProperty_UI();
			this->ui->setupUi(this);
		}
		CLayerPropertyDlg::~CLayerPropertyDlg()
		{

		}

		void CLayerPropertyDlg::BindingOjbect(VirtualMine::SpatialInterface::ILayer* ref_pLayer)
		{
			this->ref_mpLayer = ref_pLayer;
		}
		
		void CLayerPropertyDlg::initial()
		{
			if (this->ref_mpLayer)
			{
				QString layerName(this->ref_mpLayer->getName().c_str());
				this->ui->textEdit->setText(layerName);
			}

		}

		CDataSetPropertyDlg::CDataSetPropertyDlg(QWidget *parent)
			:QDialog(parent),ref_mpLayer(NULL)
		{
			this->ui = new Ui::DataSetProperty_UI();
			this->ui->setupUi(this);
		}

		CDataSetPropertyDlg::~CDataSetPropertyDlg()
		{

		}
		void CDataSetPropertyDlg::BindingOjbect(VirtualMine::SpatialInterface::ILayer* ref_pLayer)
		{

		}

		void CDataSetPropertyDlg::initial()
		{

		}

		CCreateNewSceneDlg::CCreateNewSceneDlg(QWidget *parent)
			:QDialog(parent)
		{
			this->ui = new Ui::CreateNewScene_UI();
			this->ui->setupUi(this);
		}

		CCreateNewSceneDlg::~CCreateNewSceneDlg()
		{

		}

		Ogre::Vector3 CCreateNewSceneDlg::getReferenceCenter()
		{
			Ogre::Vector3 referenceCenter(this->ui->refereneceX->value(),
				this->ui->refereneceY->value(),
				this->ui->refereneceZ->value());
			return referenceCenter;
		}

		void CCreateNewSceneDlg::setRefcenteCenterX(const double& x)
		{
			//this->ui->refereneceX->textFromValue(x);
			Ogre::Real xx = x;
			this->ui->refereneceX->setValue(x); // Ogre::StringConverter::toString(xx).c_str();
		}
		void CCreateNewSceneDlg::setRefcenteCenterY(const double& y)
		{
			Ogre::Real xx = y;
			this->ui->refereneceY->setValue(y);  // = Ogre::StringConverter::toString(xx).c_str();
		}
		void CCreateNewSceneDlg::setRefcenteCenterZ(const double& Z)
		{
			Ogre::Real xx = Z;
			this->ui->refereneceZ->setValue(Z); // = Ogre::StringConverter::toString(xx).c_str();
		}


		std::string CCreateNewSceneDlg::getSceneName()
		{
			return this->ui->sceneName->toPlainText().toLocal8Bit().constData();
		}

		void CCreateNewSceneDlg::slotHandIn()
		{
			if (this->ui->sceneName->toPlainText() != QString(""))
			{
				return QDialog::accept();
			}
			else
			{
				QMessageBox::information(this,QString("消息提示"),
					QString("请输入场景名称"),QMessageBox::Yes | QMessageBox::No,
					QMessageBox::Yes);
			}
		}
		
		void CCreateNewSceneDlg::slotCancel()
		{
			return QDialog::reject();
		}

		void CLayerAddDlg::bindingControl(VirtualMine::Scene::CGeoSpatialControl* ref_pControl)
		{
			this->ref_mpControl = ref_pControl;
		}

		CLayerAddDlg::CLayerAddDlg(QWidget *parent)
			:QDialog(parent)
		{
			this->ui = new Ui::LayerAdd_UI();
			this->ui->setupUi(this);
			this->initialControl();
			this->ref_mpControl = NULL;

			//connect(ui->layerType,SIGNAL(currentIndexChanged(QString)),this,SLOT(slotLayerNameInitialize(QString)));
			
			connect(ui->releativeDataSet,SIGNAL(currentIndexChanged(QString)),this,SLOT(slotLayerNameInitialize(QString)));
			this->ui->layerName->setText(ui->releativeDataSet->currentText());

			this->setLayerType(ui->releativeDataSet->currentText().toStdString());


		}


		void CLayerAddDlg::slotLayerNameInitialize(QString layerName)
		{
			this->ui->layerName->setText(layerName);
			this->deviceKind = 0;
			this->getLayerType();
			////图层类型设置？
			this->setLayerType(layerName.toStdString());

		}

		CLayerAddDlg::~CLayerAddDlg()
		{

		}

		std::string CLayerAddDlg::getLayerName()
		{
			return this->ui->layerName->toPlainText().toLocal8Bit().constData();
		}
		std::string CLayerAddDlg::getLayerType()
		{
			std::string layerType("");
			int index = this->ui->layerType->currentIndex();
			switch(index)
			{
			case 0:
				{
					layerType = VirtualMine::Core::GeoDataType::GDT_IMAGE;
					break;
				}
			case 1:
				{
					layerType = VirtualMine::Core::GeoDataType::GDT_DEM;
					break;
				}
			case 2:
				{
					layerType = VirtualMine::Core::GeoDataType::GDT_MODEL;
					deviceKind = 0;
					break;
				}
			case 3:
				{
					layerType = VirtualMine::Core::GeoDataType::GDT_LANWAY;
					break;
				}
			case 4:
				{
					layerType = VirtualMine::Core::GeoDataType::GDT_DRILL;
					break;
				}
			case 5:
				{
					layerType = VirtualMine::Core::GeoDataType::GDT_COALSEAM;
					break;
				}
			case 6:
				{
					layerType = VirtualMine::Core::GeoDataType::GDT_MODEL;
					deviceKind = 1;
					break;
				}
			case 7:
				{
					layerType = VirtualMine::Core::GeoDataType::GDT_MODEL;
					deviceKind = 2;
					break;
				}
			case 8:
				{
					layerType = VirtualMine::Core::GeoDataType::GDT_WORKINGPLANE;
					break;
				}
			case 9:
				{
					layerType = VirtualMine::Core::GeoDataType::GDT_FAULT;
					break;
				}

			}
			return layerType;
		}

		std::string CLayerAddDlg::getDataSetName()
		{
			return this->ui->releativeDataSet->currentText().toLocal8Bit().constData();
		}

		void CLayerAddDlg::slotHandIn()
		{
			bool existSameLayer(false);
			if (this->ref_mpControl
				&& this->ref_mpControl->getScene())
			{
				existSameLayer = (this->ref_mpControl->getScene()->getLayer(this->getLayerName()) ? true : false);
			}
			if (existSameLayer)
			{
				QMessageBox::information(this,QString("消息提示"),
					QString("场景中已经存在同名图层，请重命名！"),QMessageBox::Yes,
					QMessageBox::Yes);
				return;
			}

			std::string curLayerType = this->getLayerType();
			
			std::string curDataSetType = this->mDataSetinfoMap[this->getDataSetName()];
		 
			std::string reflayerName; 
		    if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_DEM)
		    {
				reflayerName = "DEM";
				

		    }
			else if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_COALSEAM)
			{
				reflayerName = "煤层";
			}
			else if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_DRILL)
			{
				reflayerName = "钻孔";
			}
			else if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_IMAGE)
			{
				reflayerName = "影像";
			}
			else if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_LANWAY)
			{
				reflayerName = "巷道";
			}
			else if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_WORKINGPLANE)
			{
				reflayerName = "工作面";
			}

			else if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_MODEL)
			{
				reflayerName = "模型";

				if (deviceKind == 0)
				{
					reflayerName = "地面建筑";
				}
				if (deviceKind == 1)
				{
					reflayerName = "监测模型";
				}
				if (deviceKind == 2)
				{
					reflayerName = "人员定位";
				}

			}
			QDialog::accept();


			/*	if (curLayerType != curDataSetType)
			{
			QMessageBox::information(this,QString("消息提示"),
			QString("图层与数据集类型不匹配，请重选择！"),QMessageBox::Yes | QMessageBox::No,
			QMessageBox::Yes);
			}
			else
			{
			return QDialog::accept();
			}*/
		}

		void CLayerAddDlg::slotCancel()
		{
			return QDialog::reject();
		}

		void CLayerAddDlg::initialControl()
		{
			this->ui->layerName->setText(ui->layerType->currentText());
			mDataSetinfoMap.clear();
			this->ui->releativeDataSet->clear();
			VirtualMine::Database::IDataSourceManager* pDataSourceManager = VirtualMine::Project::CProjectManager::getSingletonPtr()->getDataSourceManager();
			if (pDataSourceManager
				&& pDataSourceManager->getDataSource())
			{
				VirtualMine::Database::IDataSource* pDataSource = pDataSourceManager->getDataSource();
				std::vector<IDataset*>* pDataSets = pDataSource->getDatasetSet();
				IDataset* pLogicDataSet = pDataSource->getDataset("LogicDataset");
				if (pLogicDataSet)
				{
					std::vector<IFeature*>* logicalDataList = pLogicDataSet->getFeatureList();
					std::vector<IFeature*>::iterator logicalBItr = logicalDataList->begin();
					std::vector<IFeature*>::iterator logicalEItr = logicalDataList->end();
					while (logicalBItr != logicalEItr)
					{
						CLogicFeature* pLogicalFeature = dynamic_cast<CLogicFeature*>(*logicalBItr);
						std::string datasetName = pLogicalFeature->getName();
						std::string type ;
						CPropertySet* pProperty = pLogicalFeature->getPropertySet();
						std::vector<VirtualMine::Database::CField> fileds = pProperty->getFields();
						fileds.at(1).getVarient().getValue(datasetName);
						fileds.at(2).getVarient().getValue(type);

						this->ui->releativeDataSet->addItem(QString(datasetName.c_str()),QVariant(type.c_str()));

						mDataSetinfoMap.insert(std::pair<std::string,std::string>(datasetName,type));
						++logicalBItr;
					}
				}
			}
		}

		void CLayerAddDlg::setLayerType( const std::string& layerType )
		{

			 int index ; // = this->ui->layerType->currentIndex();

			 std::string dstname =  this->getDataSetName();
			
			 std::string curDataSetType = this->mDataSetinfoMap[this->getDataSetName()];


		        if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_IMAGE)
		        {
					index = 0;
		        }
				else if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_DEM)
				{
					index = 1;
				}
				else if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_MODEL && deviceKind == 0)
				{
					index = 2;
				}
				else if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_LANWAY)
				{
                    index = 3;
				}
				else if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_DRILL)
				{
					index = 4;
				}
				else if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_COALSEAM)
				{
					index = 5;
				}	
				else if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_MODEL && deviceKind == 1)
				{
					index = 6;
				}
				else if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_MODEL && deviceKind == 2)
				{
					index = 7;
				}
			
				else if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_WORKINGPLANE)
				{
					index = 8;
				}
				else if (curDataSetType == VirtualMine::Core::GeoDataType::GDT_FAULT)
				{

					index = 9;
				}
			
				this->ui->layerType->setCurrentIndex(index);
		}

		int CLayerAddDlg::getDeviceKind()
		{
			return deviceKind;
		}

		void CLayerAddDlg::setDeviceKind( const int& deviceKind )
		{
			this->deviceKind = deviceKind;
		}

	}
}