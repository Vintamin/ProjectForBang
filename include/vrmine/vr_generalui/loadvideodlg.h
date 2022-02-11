
#ifndef _LOADVIDEO_H_
#define _LOADVIDEO_H_

#include "vrmine/vr_generalui/vr_generaluiconfig.h"
#include <QtGui/QDialog>
#include <QtGui/QWidget>
#include <QtGui/QMainWindow>
#include "vrmine\vr_scenecontrol\geospatialcontrol.h"

#include <phonon/phonon>
#include "phonon/MediaObject"
#include "phonon/VideoPlayer"


namespace Ui
{	
	class LoadVideo;
}

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CLoadVideoDlg : public QDialog
		{
			Q_OBJECT

		public:
			CLoadVideoDlg(QWidget *parent = 0,Qt::WFlags flags =0);
			virtual ~CLoadVideoDlg();
			void setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl);
			VirtualMine::Scene::CGeoSpatialControl* getGeoSpatialControl();
			private slots:			
				void slotSelectPath();
				void slotOpenVideo();
				void slotCloseVideo();

		private:	


			Ui::LoadVideo* ui;
			Phonon::MediaObject *media ;
			VirtualMine::Scene::CGeoSpatialControl* ref_mpGeoSpatialControl;
		};

	}
}


#endif