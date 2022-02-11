#include "vrmine/vr_generalui/loadvideodlg.h"

#include "ui_loadvideo.h"
#include <QFileDialog>
#include <QObject>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QtGUI>
#include <QtGui/QInputDialog>
#include <QMessageBox>
#include <Qt/qurl.h>

namespace VirtualMine
{
	namespace GeneralUI
	{

		CLoadVideoDlg::CLoadVideoDlg(QWidget *parent,Qt::WFlags flags)
			:QDialog(parent,flags)
		{
			this->ui = new Ui::LoadVideo();
			this->ui->setupUi(this);
			this->setWindowTitle("历史事故回放");			
			//this->showFullScreen();
			this->resize(QApplication::desktop()->width() - 12,QApplication::desktop()->height() - 56);


			connect(ui->openOrPauseButton,SIGNAL(clicked()),this,SLOT(slotOpenVideo()));
			connect(ui->quitButton,SIGNAL(clicked()),this,SLOT(slotCloseVideo()));

			//this->ui->mediaWidget = new QWidget(this);  
			////QWidget *widget = new QWidget(this);      
			//this->ui->mediaWidget->setWindowTitle("事故回放");     
			////widget->resize(1500,1200); 
			//this->ui->mediaWidget->showFullScreen();


			//Phonon::MediaObject *media = new Phonon::MediaObject;   
			this->media = new Phonon::MediaObject(this);

			QString videoPath;  
			QDir dir;  
			videoPath = dir.currentPath();  
			//videoPath += "/vrmineresourcegroup/minevideo/test.mpg";
			videoPath += "/vrmineresourcegroup/minevideo/test.avi";

			media->setCurrentSource(Phonon::MediaSource(videoPath));    

			//media->set
			Phonon::VideoWidget *vwidget = new Phonon::VideoWidget(this->ui->widget);   
			vwidget->showFullScreen();
			Phonon::createPath(media, vwidget);   
			vwidget->setAspectRatio(Phonon::VideoWidget::AspectRatioWidget);    
			Phonon::AudioOutput *aOutput = new Phonon::AudioOutput(Phonon::VideoCategory,this);   	
			Phonon::createPath(media, aOutput);       

			//vwidget->showFullScreen();

			//QLabel *label = new QLabel("Volume: ");    		
			//Phonon::VolumeSlider *volumeSlider = new Phonon::VolumeSlider;    
			//volumeSlider->setAudioOutput(aOutput); 
			//volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);     
			
			//Phonon::SeekSlider *seekSlider = new Phonon::SeekSlider;   
			//seekSlider->setMediaObject(media);    
			ui->volumeSlider->setAudioOutput(aOutput);
			ui->volumeSlider->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
			ui->videoSeekSlider->setMediaObject(media);

			//QHBoxLayout *hLayout = new QHBoxLayout;   
			//hLayout->addWidget(label);   
			//hLayout->addWidget(volumeSlider);   
			//hLayout->addStretch();   
			
			
			//this->ui->verticalLayout->addWidget(vwidget);
			this->ui->videoLayout->addWidget(vwidget);

			//QVBoxLayout *vLayout = new QVBoxLayout;   
			//vLayout->addWidget(vwidget);   
			//vLayout->addWidget(seekSlider);   
			//vLayout->addLayout(hLayout);      
			//this->ui->mediaWidget->setLayout(vLayout);      
			//this->setLayout(vLayout);
			/*this->ui->mediaWidget->setWindowModality(Qt::ApplicationModal);
			this->ui->mediaWidget->show();     
			*/
			media->play();     



		}

		CLoadVideoDlg::~CLoadVideoDlg()
		{
			this->media->clear();
		}

		void CLoadVideoDlg::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl)
		{
			this->ref_mpGeoSpatialControl = ref_pGeoSpatialControl;
		}

		VirtualMine::Scene::CGeoSpatialControl* CLoadVideoDlg::getGeoSpatialControl()
		{
			return ref_mpGeoSpatialControl;
		}

		void CLoadVideoDlg::slotSelectPath()
		{

			////文件路径
			/*	QString file =
			QFileDialog::getOpenFileName(this, tr("Open file"),
			QDir::homePath(),
			tr("Multimedia files(*)"));

			if (file.isEmpty())
			return;
			*/

			//QString file = "F://test.mpg";

			///*		this->media = new Phonon::MediaObject;		
			//this->media->setCurrentSource(Phonon::MediaSource(file));*/

			////QWidget *mainWidget = new QWidget();
			//this->ui->videoPlayer = new Phonon::VideoPlayer(this->ui->videoPlayer);
			//this->ui->videoPlayer->load(Phonon::MediaSource(file));
			////this->ui->videoPlayer->showFullScreen();
			//this->ui->videoPlayer->play();
		 //   this->ui->videoPlayer->setFocus(); 
			//this->ui->videoPlayer->show();  

			//mainWidget->setAttribute(Qt::WA_ShowModal,true);
				
			//Phonon::VideoWidget *vwidget = new Phonon::VideoWidget;
		
			//	
			//Phonon::createPath(media, vwidget);		
	  //   	vwidget->setAspectRatio(Phonon::VideoWidget::AspectRatioAuto);

			////this->media = Phonon::createPlayer(Phonon::VideoCategory,Phonon::MediaSource(file));
			//Phonon::AudioOutput *aOutput = new Phonon::AudioOutput(Phonon::VideoCategory);
			//Phonon::createPath(media, aOutput);	
		
		
			//
			//vwidget->show();

		
			////this->ui->videoPlayer = new Phonon::VideoPlayer(Phonon::VideoCategory, widget); 					
			////this->ui->videoPlayer->load(Phonon::MediaSource(file));//貌似只支持mpg格式
			////this->ui->videoPlayer->play();
			////widget->show();

			//

			//Phonon::State state = media->state();
			//
		

			//QLabel *label = new QLabel("Volume: ");
			//Phonon::VolumeSlider *volumeSlider = new Phonon::VolumeSlider;
			////volumeSlider->setAudioOutput(aOutput);
			//volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

			//Phonon::SeekSlider *seekSlider = new Phonon::SeekSlider;
			//seekSlider->setMediaObject(media);

			//QHBoxLayout *hLayout = new QHBoxLayout;
			//hLayout->addWidget(label);
			//hLayout->addWidget(volumeSlider);
			//hLayout->addStretch();

			//QVBoxLayout *vLayout = new QVBoxLayout;
			//vLayout->addWidget(vwidget);
			//vLayout->addWidget(seekSlider);
			//vLayout->addLayout(hLayout);
			////this->ui->videoPlayer->setLayout(vLayout);
	  //      //this->ui->videoPlayer->show();

			//this->ui->videoWidget->setLayout(vLayout);
			//
   // 
			//media->play();
			//this->ui->videoWidget->show();
		}
		void CLoadVideoDlg::slotOpenVideo()
		{
			switch (media->state())
			{
			case Phonon::PlayingState:
				media->pause();
				break;
			case Phonon::PausedState:
				media->play();
				break;
			}
		}
		void CLoadVideoDlg::slotCloseVideo()
		{
			media->stop();
		}

	}
}
