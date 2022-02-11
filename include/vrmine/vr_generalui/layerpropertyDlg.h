
#ifndef _CLAYERPROPERTYDLG_H_
#define _CLAYERPROPERTYDLG_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include "vrmine/vr_spatialinterface/ilayer.h"
#include "vrmine/vr_scenecontrol/geospatialcontrol.h"
#include <QtGui/QDialog>

namespace Ui
{
	class LayerProperty_UI;
	class DataSetProperty_UI;
	class LayerAdd_UI;
	class CreateNewScene_UI;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CLayerPropertyDlg : public QDialog
		{
			Q_OBJECT
		public:
			CLayerPropertyDlg(QWidget *parent = 0);
			virtual ~CLayerPropertyDlg();
			void BindingOjbect(VirtualMine::SpatialInterface::ILayer* ref_pLayer);
			void initial();

			VirtualMine::SpatialInterface::ILayer* ref_mpLayer;

			Ui::LayerProperty_UI* ui;
		};

		class VRGENERALUI_DLL CDataSetPropertyDlg : public QDialog
		{
			Q_OBJECT
		public:
			CDataSetPropertyDlg(QWidget *parent = 0);
			virtual ~CDataSetPropertyDlg();
			void BindingOjbect(VirtualMine::SpatialInterface::ILayer* ref_pLayer);
			void initial();

			VirtualMine::SpatialInterface::ILayer* ref_mpLayer;

			Ui::DataSetProperty_UI* ui;
		};

		class VRGENERALUI_DLL CCreateNewSceneDlg : public QDialog
		{
			Q_OBJECT
		public:
			CCreateNewSceneDlg(QWidget *parent = 0);
			virtual ~CCreateNewSceneDlg();
			Ogre::Vector3 getReferenceCenter();
			std::string getSceneName();
			void setRefcenteCenterX(const double& x);
			void setRefcenteCenterY(const double& y);
			void setRefcenteCenterZ(const double& Z);

		private slots:
			void slotHandIn();
			void slotCancel();
		private:
			Ui::CreateNewScene_UI* ui;
			/*Ogre::Vector3 mReferenceCenter;
			std::string mSceneName;*/
		};

		class VRGENERALUI_DLL CLayerAddDlg : public QDialog
		{
			Q_OBJECT
		public:
			CLayerAddDlg(QWidget *parent = 0);
			virtual ~CLayerAddDlg();
			virtual std::string getLayerName();
			virtual std::string getLayerType();
			virtual void setLayerType(const std::string& layerType);

			virtual int getDeviceKind();
			virtual void setDeviceKind(const int& deviceKind);

			virtual std::string getDataSetName();
			virtual void bindingControl(VirtualMine::Scene::CGeoSpatialControl* ref_pControl);
		private slots:
			void slotHandIn();
			void slotCancel();

			void slotLayerNameInitialize(QString layerName);
		protected:
			virtual void initialControl();
		private:
			Ui::LayerAdd_UI* ui;
			typedef std::map<std::string,std::string> DataSetInfo;
			DataSetInfo mDataSetinfoMap;
			VirtualMine::Scene::CGeoSpatialControl* ref_mpControl;
			int deviceKind;
		};
	}
}


#endif