
#ifndef _CMODELPROPERTYDLG_H_
#define _CMODELPROPERTYDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include "vrmine/vr_spatialobject/mine/modelobject.h"
#include "vrmine/vr_scenecontrol/geospatialcontrol.h"
#include "OGRE/OgreEntity.h"

namespace Ui
{
	class ModelProperty_UI;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
	    enum ModelDlgType
		{
			MDL_ADDMODEL,
			MDL_EDITMODEL,
		};
		class CModelPosSelectedTool;
		class VRGENERALUI_DLL CModelPropertyDlg : public QDialog
		{
			Q_OBJECT
			
		public:
			CModelPropertyDlg(QWidget *parent = 0);
			virtual ~CModelPropertyDlg();
			void setGeoSceneControl(VirtualMine::Scene::CGeoSpatialControl* ref_pControl);
			void BindingOjbect(VirtualMine::Mine::CModelObject* pObject);
			void BindingLayer(VirtualMine::SpatialInterface::ILayer* ref_pLayer);
			void initial();
		protected slots:
			void slotPosXChanged(double value);
			void slotPosYChanged(double value);
			void slotPosZChanged(double value);
			void slotRoateXChanged(double value);
			void slotRoateYChanged(double value);
			void slotRoateZChanged(double value);
			void slotScaleXChanged(double value);
			void slotScaleYChanged(double value);
			void slotScaleZChanged(double value);
			void slotHandIn();
			void slotCancel();
			void slotPosSelected();
			void upatePosture();
			void initialModelLibResource();
		protected:
			VirtualMine::Scene::CGeoSpatialControl* ref_mpControl;
			VirtualMine::Mine::CModelObject* ref_mpModelObject;
			VirtualMine::SpatialInterface::ILayer* ref_mpLayer;
			Ogre::Entity* ref_mpCurEntity;
			Ui::ModelProperty_UI* ui;
			bool mNeedSelectPos;
			CModelPosSelectedTool* mpPosSelectedTool;

			friend class CModelPosSelectedTool;
		private:
			ModelDlgType mDlgType;
		};

	}
}


#endif