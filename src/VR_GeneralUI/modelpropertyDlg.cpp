#include "vrmine/vr_generalui/modelpropertyDlg.h"
#include "vrmine/vr_style/style/modelstyle.h"
#include "vrmine/vr_geometry/geometry/point.h"
#include "ui_modelpropertyDlg.h"
#include "vrmine/vr_spatialinterface/event/eventobject.h"
#include "vrmine/vr_spatialanalyse/spatialanalyse/spatialmeasuretool.h"
#include "vrmine/vr_core/geodatatype.h"
#include <QDir>
#include "vrmine/vr_projectmanager/project/projectmanager.h"
#include "vrmine/vr_databaseengine/database/idatasourcemanager.h"
#include "vrmine/vr_spatialobject/geoproperty/modelProperty.h"
#include "vrmine/vr_databaseengine/database/ifeature.h"
using namespace VirtualMine::Style;
using namespace VirtualMine::Geometry;
using namespace VirtualMine::SpatialAnalyse;
using namespace VirtualMine::Project;
using namespace VirtualMine::GeoProperty;
using namespace VirtualMine::SpatialInterface;

namespace VirtualMine
{
	namespace GeneralUI
	{
		class CModelPosSelectedTool : public CSpatialMeasureTool
		{
		public:
			CModelPosSelectedTool(VirtualMine::Scene::CGeoSpatialControl* ref_pSceneControl)
				:CSpatialMeasureTool(ref_pSceneControl),ref_mpOperator(NULL)
			{

			}
			virtual ~CModelPosSelectedTool()
			{

			}
			virtual void mouseReleaseEvent(const int& x ,const int& y , const int& button)
			{
				if (!this->mIsMouseDrag 
					&& button == 1
					&& this->ref_mpOperator->mNeedSelectPos)
				{
					Ogre::Vector3 intersectPoint(Ogre::Vector3::ZERO);
					if (this->ref_mpSceneControl->getGeoSceneManager()->getRayIntersectedPoint(x,y,intersectPoint))
					{
						this->ref_mpOperator->ui->pos_x->setValue(intersectPoint.x);
						this->ref_mpOperator->ui->pos_y->setValue(intersectPoint.y);
						this->ref_mpOperator->ui->pos_z->setValue(intersectPoint.z);
						this->ref_mpOperator->upatePosture();
					}
				}
				CSpatialMeasureTool::mouseReleaseEvent(x,y,button);
				//this->ref_mpOperator->ui->posSelcted->setEnabled(true);
			}

			virtual void mousePressEvent(const int& x ,const int& y , const int& button)
			{
				CSpatialMeasureTool::mousePressEvent(x,y,button);
			}

			virtual bool handleEvent(VirtualMine::Core::CEvent* evt)
			{
				return CSpatialMeasureTool::handleEvent(evt);
			}

		public:
			CModelPropertyDlg* ref_mpOperator;
		};

		CModelPropertyDlg::CModelPropertyDlg(QWidget *parent)
			:QDialog(parent),ref_mpModelObject(NULL),
			ref_mpControl(NULL),ref_mpCurEntity(NULL),ref_mpLayer(NULL)
		{
			this->ui = new Ui::ModelProperty_UI();
			this->ui->setupUi(this);
			this->mNeedSelectPos = true;
			this->mpPosSelectedTool = NULL;
		}
		
		CModelPropertyDlg::~CModelPropertyDlg()
		{

		}

		void CModelPropertyDlg::setGeoSceneControl(VirtualMine::Scene::CGeoSpatialControl* ref_pControl)
		{
			this->ref_mpControl = ref_pControl;
		}
		
		void CModelPropertyDlg::BindingOjbect(VirtualMine::Mine::CModelObject* pObject)
		{
			this->ref_mpModelObject = pObject;
		}

		void CModelPropertyDlg::BindingLayer(VirtualMine::SpatialInterface::ILayer* ref_pLayer)
		{
			this->ref_mpLayer = ref_pLayer;
		}

		void CModelPropertyDlg::upatePosture()
		{
			if (this->ref_mpCurEntity)
			{
				Ogre::SceneNode* pNode = this->ref_mpCurEntity->getParentSceneNode();

				Ogre::Quaternion q;
				Ogre::Matrix3 mat;
				mat.FromEulerAnglesXYZ(Ogre::Radian(Ogre::Degree(this->ui->rotate_x->value())),
					Ogre::Radian(Ogre::Degree(this->ui->rotate_y->value())),
					Ogre::Radian(Ogre::Degree(this->ui->rotate_z->value())));
				q.FromRotationMatrix(mat);

				pNode->setOrientation(q);

				pNode->setScale(this->ui->scale_x->value(),
					this->ui->scale_y->value(),
					this->ui->scale_z->value());

				pNode->setPosition(this->ui->pos_x->value(),
					this->ui->pos_y->value(),
					this->ui->pos_z->value());
				int x = 0; 
			}
		}

		void CModelPropertyDlg::slotHandIn()
		{
			if (this->mDlgType == ModelDlgType::MDL_ADDMODEL)
			{
				this->ref_mpModelObject = new VirtualMine::Mine::CModelObject();
				
				CModelProperty* pProterty = dynamic_cast<CModelProperty*>(ref_mpModelObject->getGeoProperty());
				pProterty->setMeshName(this->ui->modelLib->currentText().toStdString());
			}
			
			std::string featureName = this->ref_mpModelObject->getName();
			this->ref_mpModelObject->setName(this->ui->modelName->toPlainText().toStdString());

			CPoint* position =dynamic_cast<CPoint*> (this->ref_mpModelObject->getGeometry());			
			position->setX(this->ui->pos_x->value() + VirtualMine::SpatialInterface::IScene::ReferenceCenter.x);
			position->setY(this->ui->pos_y->value() + VirtualMine::SpatialInterface::IScene::ReferenceCenter.y);
			position->setZ((this->ui->pos_z->value()/ VirtualMine::SpatialInterface::IScene::CoefficientOfCoordinateTransform) + VirtualMine::SpatialInterface::IScene::ReferenceCenter.z);

			CModelStyle* pStyle = dynamic_cast<CModelStyle*>(this->ref_mpModelObject->getStyle());				
			double rotateX = this->ui->rotate_x->value();
			double rotateY = this->ui->rotate_y->value();
			double rotateZ = this->ui->rotate_z->value();

			pStyle->getParameter().setRotate(Ogre::Vector3(rotateX,rotateY,rotateZ));

			double scaleX = this->ui->scale_x->value();
			double scaleY = this->ui->scale_y->value();
			double scaleZ = this->ui->scale_z->value();

			pStyle->getParameter().setScale(Ogre::Vector3(scaleX,scaleY,scaleZ));
			VirtualMine::Database::IFeature* feature = this->ref_mpModelObject->toFeature();

			VirtualMine::Database::IDataSourceManager* pDataSourceManager = VirtualMine::Project::CProjectManager::getSingletonPtr()->getDataSourceManager();
			if (pDataSourceManager
				&& pDataSourceManager->getDataSource() && this->ref_mpLayer)
			{
				if (this->mDlgType == ModelDlgType::MDL_ADDMODEL)
				{
					pDataSourceManager->getDataSource()->insertModelFeatureToModelDataset(feature,this->ref_mpLayer->getDataSet()->getName());
				}
				if (this->mDlgType == ModelDlgType::MDL_EDITMODEL)
				{
					VirtualMine::Database::CModelFeature* modelFeature = static_cast<VirtualMine::Database::CModelFeature*>(feature);
					if (modelFeature!= NULL)
					{
						//pDataSourceManager->getDataSource()->insertModelFeatureToModelDataset(feature,this->ref_mpLayer->getDataSet()->getName());
						//pDataSourceManager->getDataSource()->updataModelFeature(feature,featureName);
						pDataSourceManager->getDataSource()->updataModelFeature2(feature,featureName,this->ref_mpLayer->getDataSet()->getName());
					}
				}
			}
			
			//position =dynamic_cast<CPoint*> (this->ref_mpModelObject->getGeometry());			
			position->setX(position->getX() - VirtualMine::SpatialInterface::IScene::ReferenceCenter.x);
			position->setY(position->getY() - VirtualMine::SpatialInterface::IScene::ReferenceCenter.y);
			position->setZ((position->getZ() - VirtualMine::SpatialInterface::IScene::ReferenceCenter.z)* VirtualMine::SpatialInterface::IScene::CoefficientOfCoordinateTransform);

			//this->accept();
		}

		void CModelPropertyDlg::slotPosSelected()
		{
			QString meshName = this->ui->modelLib->currentText();
			QString modelName = this->ui->modelName->toPlainText();
			if (meshName.isEmpty())
			{
				return;
			}
			if (mpPosSelectedTool == NULL)
			{
				this->mpPosSelectedTool = new CModelPosSelectedTool(ref_mpControl);
				this->mpPosSelectedTool->ref_mpOperator = this;
				ref_mpControl->setCurrentTool(NULL);
				ref_mpControl->setCurrentTool(this->mpPosSelectedTool);
			}
			if (this->ref_mpCurEntity == NULL)
			{
				this->ref_mpCurEntity = this->ref_mpControl->getGeoSceneManager()->createEntity(Ogre::String(modelName.toLocal8Bit().constData()),
					meshName.toLocal8Bit().constData(),VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				this->ref_mpControl->getGeoSceneManager()->getRootSceneNode()->createChildSceneNode()->attachObject(this->ref_mpCurEntity);
				this->ref_mpCurEntity->setRenderQueueGroup(90);
				for (int i = 0; i < this->ref_mpCurEntity->getNumSubEntities();++i)
				{
					Ogre::MaterialPtr mat = this->ref_mpCurEntity->getSubEntity(i)->getMaterial();
					/*Ogre::Pass* pass = mat->getTechnique(0)->getPass(0);
					pass->setDepthCheckEnabled(true);
					pass->setDepthWriteEnabled(false);
					pass->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);*/
					mat->load();
				}
			}
			/*this->mNeedSelectPos = true;*/
			this->ui->posSelcted->setEnabled(false);
		}

		void CModelPropertyDlg::slotCancel()
		{
			if (this->ref_mpCurEntity)
			{
				this->ref_mpCurEntity->detachFromParent();
				this->ref_mpControl->getGeoSceneManager()->destroyEntity(this->ref_mpCurEntity->getName());
				this->ref_mpCurEntity = NULL;
			}
			this->reject();
		}
		
		void CModelPropertyDlg::initialModelLibResource()
		{
			QString projectPath = QDir::currentPath()+ QString("//vrmineresourcegroup//LandscapeModel");

			QDir proDir(projectPath);
			if(!proDir.exists())
			{
				return;
			}

			proDir.setFilter(QDir::Dirs|QDir::Files);

			QFileInfoList list = proDir.entryInfoList();


			for (int i = 0; i < list.size() ; ++i)
			{
				QFileInfo fileInfo = list.at(i);
				QString currentFileName = fileInfo.fileName();
				if(currentFileName.endsWith(".mesh")) 
				{
					this->ui->modelLib->addItem(currentFileName);
				}
			}
		}

		void CModelPropertyDlg::initial()
		{			
			if (this->ref_mpModelObject == NULL)
			{
				this->setWindowTitle(QString("Ìí¼ÓÄ£ÐÍ"));
				this->initialModelLibResource();
				this->mDlgType = ModelDlgType::MDL_ADDMODEL;
				return;
			}
			this->mDlgType = ModelDlgType::MDL_EDITMODEL;
			this->ui->posSelcted->setVisible(false);
			CModelStyle* pStyle = dynamic_cast<CModelStyle*>(this->ref_mpModelObject->getStyle());
			CPoint* position =dynamic_cast<CPoint*> (this->ref_mpModelObject->getGeometry());
			if (pStyle == NULL
				|| position == NULL)
			{
				return;
			}

			this->ui->modelName->setText(QString(this->ref_mpModelObject->getName().c_str()));

			this->ui->pos_x->setValue(position->getX());
			this->ui->pos_y->setValue(position->getY());
			this->ui->pos_z->setValue(position->getZ());

			this->ui->rotate_x->setValue(pStyle->getParameter().getRoate().x);
			this->ui->rotate_y->setValue(pStyle->getParameter().getRoate().y);
			this->ui->rotate_z->setValue(pStyle->getParameter().getRoate().z);

			this->ui->scale_x->setValue(pStyle->getParameter().getScale().x);
			this->ui->scale_y->setValue(pStyle->getParameter().getScale().y);
			this->ui->scale_z->setValue(pStyle->getParameter().getScale().z);

			if (NULL == this->ref_mpCurEntity
				&& this->ref_mpControl)
			{
				this->ref_mpCurEntity = this->ref_mpControl->getGeoSceneManager()->getEntity(this->ref_mpModelObject->getName());
				VirtualMine::SpatialInterface::CFlyToEvent flyEvent;
				this->ref_mpControl->flyTo(position->getX(),position->getY(),position->getZ());
			}
		}

		void CModelPropertyDlg::slotPosXChanged(double value)
		{
			this->upatePosture();
		}

		void CModelPropertyDlg::slotPosYChanged(double value)
		{
			this->upatePosture();
		}

		void CModelPropertyDlg::slotPosZChanged(double value)
		{
			this->upatePosture();
		}

		void CModelPropertyDlg::slotRoateXChanged(double value)
		{
			this->upatePosture();
		}

		void CModelPropertyDlg::slotRoateYChanged(double value)
		{
			this->upatePosture();
		}
		void CModelPropertyDlg::slotRoateZChanged(double value)
		{
			this->upatePosture();
		}

		void CModelPropertyDlg::slotScaleXChanged(double value)
		{
			this->upatePosture();
		}

		void CModelPropertyDlg::slotScaleYChanged(double value)
		{
			this->upatePosture();
		}

		void CModelPropertyDlg::slotScaleZChanged(double value)
		{
			this->upatePosture();
		}
	}
}