#include "vrmine\vr_plugins\vrcontrol.h"
#include <qpainter.h>
#include <qcoreevent.h>
#include <qevent.h>
#include <qgridlayout.h>
#include "vrmine/vr_spatiallayer/demlayer.h"


#include <stdio.h>  
#include <windows.h> 
#include <ShellAPI.h>

using namespace VirtualMine::Scene;
using namespace VirtualMine::SpatialLayer;


CSubCameraChangedListener::CSubCameraChangedListener()
{

}

CSubCameraChangedListener::~CSubCameraChangedListener()
{

}

void CSubCameraChangedListener::onCameraInfoChanged()
{
	if (this->ref_mpControl
		&& this->ref_mpGeoCamera)
	{
		Ogre::Vector3 cameraPosition = this->ref_mpGeoCamera->getPosition();
		VirtualMine::SpatialInterface::IScene* pScene = this->ref_mpControl->getScene();
		if (pScene)
		{
			CDemLayer* pDemLayer = dynamic_cast<CDemLayer*>(pScene->getDemLayer());
			if (pDemLayer)
			{
				Ogre::AxisAlignedBox boudingBox = pDemLayer->getBoundingBox();
				bool showSky = true;
				/*if (boudingBox != Ogre::AxisAlignedBox::BOX_NULL
					&& boudingBox.contains(cameraPosition))*/
				{
					Ogre::Real demValue = this->ref_mpControl->getHeight(cameraPosition.x,cameraPosition.z);
					showSky = (cameraPosition.y > demValue);
				}
				/*else
				{
					showSky = true;
				}*/
				showSky = (showSky && this->ref_mpControl->getSkyState());
				this->ref_mpControl->getGeoSceneManager()->setSkyDomeEnabled(showSky);
			}
		}
	}
}


VRControl::VRControl(QWidget *parent)
	: QWidget(parent)
{
	this->mIsFullScreen = false;
	this->mIsMousePress = false;
    this->mIsMouseDragging = false;
	this->mpGeoSceneControl = new CGeoSpatialControl();
	QWidget* parentWidget = new QWidget(this);
	parentWidget->setContentsMargins(0,0,0,0);
	parentWidget->setMouseTracking(true);
	this->mpGeoSceneControl->setupWindowView((size_t)((HWND)parentWidget->winId()),parentWidget->width(),parentWidget->height());
	QGridLayout * pLayOut = new QGridLayout();
	pLayOut->addWidget(parentWidget);
	pLayOut->setContentsMargins(0,0,0,0);
	this->setLayout(pLayOut);
	this->startTimer(1);
	this->setMouseTracking(true);
	this->setFocusPolicy(Qt::StrongFocus);
	this->setMinimumSize(10,10);

	ref_tabwidght = NULL;
	//关于天空是否显示
	this->mpCameraChangedListener = new CSubCameraChangedListener();
	this->mpCameraChangedListener->ref_mpControl = this->mpGeoSceneControl;
	this->mpGeoSceneControl->getGeoSceneCamera()->addCameraListener(this->mpCameraChangedListener);	
}

VRControl::~VRControl()
{

}

bool VRControl::eventFilter(QObject * qObject, QEvent * qEvent)
{
	return true;
}

VirtualMine::Scene::CGeoSpatialControl* VRControl::getGeoSpatialControl()
{
	return this->mpGeoSceneControl;
}

void VRControl::paintEvent(QPaintEvent * event)
{
	//QPainter painter(this);  
	//QPen pen; //
	//pen.setColor(QColor(255,0,0,150));  
	//QBrush brush(QColor(255,0,0,150)); //
	//painter.setPen(pen); //
	//painter.setBrush(brush); //
	//painter.drawRect(0,0,this->width(),this->height()); //
	Q_UNUSED(event);
	if (NULL != this->mpGeoSceneControl)
	{
		/*if (NULL == this->mpGeoSceneControl->getRenderWindow())
		{
		this->mpGeoSceneControl->setupWindowView((size_t)((HWND)this->winId()),this->width(),this->height());
		}*/
		this->mpGeoSceneControl->updateVRScene();
	}
}

void VRControl::mousePressEvent(QMouseEvent * event)
{
	/*LeftButton       = 0x00000001,
	RightButton      = 0x00000002,
	MidButton        = 0x00000004*/
	if (this->mpGeoSceneControl)
	{
		this->mpGeoSceneControl->mousePressEvent(event->x(),event->y(),event->buttons());

		//if ((0<event->x() && event->x()<18) && (240<event->y() && event->y()<315))
		//{
		//	if (ref_tabwidght)
		//	{
		//		if (ref_tabwidght->isVisible())
		//		{
		//			ref_tabwidght->setVisible(false);
		//			this->getGeoSpatialControl()->getmppushbackBtn()->getChild("pushbackBtnPic")->setMaterialName("pushbackBtn_rightbtn");
		//		}
		//		else 
		//		{
		//			ref_tabwidght->setVisible(true);
		//			this->getGeoSpatialControl()->getmppushbackBtn()->getChild("pushbackBtnPic")->setMaterialName("pushbackBtn_leftbtn");
		//		}
		//	}
		//	
		//}
	}
	if (event->buttons() == 1)
	{
		//this->setCursor(Qt::OpenHandCursor);
	}

#if 0 点选 
	if (this->mIsMousePress)
	{
		if (this->mIsMouseDragging)
		{

		}
		else
		{

		}
	}
#endif

	emit mousePressSignal(event);

	return QWidget::mousePressEvent(event);
}

void VRControl::mouseReleaseEvent(QMouseEvent * event)
{
	if (this->mpGeoSceneControl)
	{
		this->mpGeoSceneControl->mouseReleaseEvent(event->x(),event->y(),event->button());
	}
	//this->setCursor(Qt::ArrowCursor);

	emit mouseReleaseSignal(event);

	return QWidget::mouseReleaseEvent(event);
}

void VRControl::mouseDoubleClickEvent(QMouseEvent * event)
{
	if (this->mpGeoSceneControl)
	{
		this->mpGeoSceneControl->mouseDoubleClickEvent(event->x(),event->y(),event->button());
	}

	emit mouseDoubleClickSignal(event);

	return QWidget::mouseDoubleClickEvent(event);
}

bool VRControl::event(QEvent * event)
{
	/*QEvent::Type type = event->type();
	if (event->type() == QEvent::KeyPress)
	{
		QKeyEvent * keyEvent = static_cast<QKeyEvent *>(event);
		this->keyPressEvent(keyEvent);
	}
	else if (event->type() == QEvent::KeyRelease)
	{
		QKeyEvent * keyEvent = static_cast<QKeyEvent *>(event);
		this->keyReleaseEvent(keyEvent);
	}
	else if (event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent * mouseEvent = static_cast<QMouseEvent *>(event);
		this->mousePressEvent(mouseEvent);
	}
	else if (event->type() == QEvent::MouseButtonRelease)
	{
		QMouseEvent * mouseEvent = static_cast<QMouseEvent *>(event);
		this->mouseReleaseEvent(mouseEvent);
	}
	else if (event->type() == QEvent::MouseButtonDblClick)
	{
		QMouseEvent * mouseEvent = static_cast<QMouseEvent *>(event);
		this->mouseDoubleClickEvent(mouseEvent);
	}
	else if (event->type() == QEvent::MouseMove)
	{
		QMouseEvent * mouseEvent = static_cast<QMouseEvent *>(event);
		this->mouseMoveEvent(mouseEvent);
	}*/


	//if (evt->type() == QEvent::KeyPress) {
	//	QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
	//	if (keyEvent->key() == Qt::Key_Tab) {
	//		// 处理Tab鍵
	//		return true;
	//	}
	//}
	
	return QWidget::event(event);
}

void VRControl::mouseMoveEvent(QMouseEvent * event)
{
	if (this->mpGeoSceneControl)
	{
		this->mpGeoSceneControl->mouseMoveEvent(event->x(),event->y(),event->buttons());
	}
	if (this->mIsMousePress)
	{
		QCursor cursor = Qt::ArrowCursor;
		cursor = QCursor(QPixmap("data\\Resources\\image\\queryhand.png")); 
		this->setCursor(cursor);
	}
	else
	{
		QCursor cursor = Qt::ArrowCursor;
		this->setCursor(cursor);
	}

	emit mouseMoveSignal(event);

	return QWidget::mouseMoveEvent(event);
}

void VRControl::wheelEvent(QWheelEvent * event)
{
	if (this->mpGeoSceneControl)
	{
		this->mpGeoSceneControl->wheelEvent(event->x(),event->y(),event->delta());
	}
	//kk源代码
	emit wheelSignal(event);

	return QWidget::wheelEvent(event);
}

void VRControl::timerEvent(QTimerEvent* event)
{
	Q_UNUSED(event);
	if (NULL != this->mpGeoSceneControl)
	{
		this->mpGeoSceneControl->updateVRScene();
	}
}

void VRControl::keyPressEvent(QKeyEvent * event)
{
	if (this->mpGeoSceneControl)
	{
		this->mpGeoSceneControl->keyPressEvent(event->key());

		
		
	}
	emit keyPressSignal(event);
}

void VRControl::keyReleaseEvent(QKeyEvent * event)
{
	if (this->mpGeoSceneControl)
	{
		if (event->key() == Qt::Key_Escape)
		{
			this->exitFullScreen();

		}
	}

	emit keyReleaseSignal(event);
}

void VRControl::resizeEvent(QResizeEvent * event)
{
	Q_UNUSED(event);
	int w = this->width();
	int h = this->height();
	if (NULL != this->mpGeoSceneControl->getRenderWindow())
	{
		/*if (w < 50)
			w = 50;
		if (h < 50)
			h = 50;*/

		/*if (this->mIsFullScreen)
		{
			this->mpGeoSceneControl->getRenderWindow()->setFullscreen(true,w,h);
		}
		else
		{
			this->mpGeoSceneControl->getRenderWindow()->setFullscreen(false,w,h);
		}*/
		this->mpGeoSceneControl->resizeEvent(w,h);
	}
	QWidget::resize(w,h);
}

void VRControl::closeEvent(QCloseEvent * event)
{

}

void VRControl::enterEvent(QEvent * event)
{

}

void VRControl::leaveEvent(QEvent * event)
{

}

void VRControl::moveEvent(QMoveEvent * event)
{

}

void VRControl::fullScreen()
{
	if (!this->mIsFullScreen)
	{
		this->setWindowFlags(Qt::Window);///Qt::Dialog
		this->showFullScreen();
		this->mIsFullScreen = true;
		int height1 = this->height();
		std::string hei = Ogre::StringConverter::toString(height1 - 10);
	    this->getGeoSpatialControl()->getOutTextElement()->setParameter("top",hei.c_str());
	    ////重置影像 
		if (this->getGeoSpatialControl()->getScene())
		{			
			if (this->getGeoSpatialControl()->getScene()->getImageLayer())
			{
				this->getGeoSpatialControl()->getScene()->getImageLayer()->resetResource();
			}
		}


		/*HWND hWnd = FindWindow(LPCWSTR("Shell_TrayWnd"),NULL);
        ShowWindow(hWnd,SW_HIDE);*/

		HWND task;  
		task = FindWindow(L"Shell_TrayWnd",NULL);  
		ShowWindow(task,SW_HIDE);//隐藏任务栏  
		LPARAM lParam;
		lParam = ABS_AUTOHIDE | ABS_ALWAYSONTOP;

#ifndef ABM_SETSTATE 
#define ABM_SETSTATE 0x0000000a 
#endif 

		APPBARDATA apBar; 
		memset(&apBar, 0, sizeof(apBar)); 
		apBar.cbSize = sizeof(apBar); 
		apBar.hWnd = task; 
		if(apBar.hWnd != NULL) 
		{ 
			apBar.lParam = lParam; 
			SHAppBarMessage(ABM_SETSTATE, &apBar); //设置任务栏自动隐藏
		} 





	}

}

void VRControl::exitFullScreen()
{
	if (this->mIsFullScreen)
	{
		this->setWindowFlags(Qt::SubWindow);
		this->showNormal();
		this->mIsFullScreen = false;

	}
	int height1 = this->height();
	std::string hei = Ogre::StringConverter::toString(height1 - 10);
	this->getGeoSpatialControl()->getOutTextElement()->setParameter("top",hei.c_str()); 

	HWND task;  
	task = FindWindow(L"Shell_TrayWnd",NULL);  
	ShowWindow(task,SW_SHOW);


	LPARAM lParam;
	lParam = ABS_ALWAYSONTOP;

#ifndef ABM_SETSTATE 
#define ABM_SETSTATE 0x0000000a 
#endif 

	APPBARDATA apBar; 
	memset(&apBar, 0, sizeof(apBar)); 
	apBar.cbSize = sizeof(apBar); 
	apBar.hWnd = task; 
	if(apBar.hWnd != NULL) 
	{ 
		apBar.lParam = lParam; 
		SHAppBarMessage(ABM_SETSTATE, &apBar); //设置任务栏自动隐藏
	} 

}

QTabWidget* VRControl::getTabwidget()
{
	return ref_tabwidght;
}

void VRControl::setTabwidght( QTabWidget* tab)
{
	this->ref_tabwidght = tab;
}
