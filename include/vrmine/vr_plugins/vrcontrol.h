#ifndef VRCONTROL_H
#define VRCONTROL_H
//定义插件导出符号
#ifndef QVRSCENECONTROL_EXPORT_WIDGETS
#define VRCONTORL_DLL _declspec(dllimport)
#else
#define VRCONTORL_DLL _declspec(dllexport)
#endif

#include <QtGui/QWidget>
#include "vrmine\vr_scenecontrol\geospatialcontrol.h"
#include <QTabWidget>

class VRControl;
class  VRCONTORL_DLL CSubCameraChangedListener : public VirtualMine::SpatialEngine::CCameraChangedListener
{
	friend class VRControl;
public:
	CSubCameraChangedListener();
	virtual ~CSubCameraChangedListener();
	virtual void onCameraInfoChanged();
public:
	VirtualMine::Scene::CGeoSpatialControl* ref_mpControl;
};

class VRCONTORL_DLL VRControl : public QWidget
{ 
	Q_OBJECT

public:
	VRControl(QWidget *parent = 0);
	~VRControl();
	 virtual bool eventFilter(QObject * qObject, QEvent * qEvent);
	VirtualMine::Scene::CGeoSpatialControl* getGeoSpatialControl();

	///new ui	
	QTabWidget* getTabwidget();
	void setTabwidght(QTabWidget* tab);
protected:
	bool event(QEvent * event);
	virtual void mousePressEvent(QMouseEvent * event );
	virtual void mouseReleaseEvent(QMouseEvent *  event);
	virtual void mouseDoubleClickEvent(QMouseEvent *  event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	//#ifndef QT_NO_WHEELEVENT
	virtual void wheelEvent(QWheelEvent * event);
	//#endif
	virtual void timerEvent(QTimerEvent* event);
	virtual void keyPressEvent(QKeyEvent * event);
	virtual void keyReleaseEvent(QKeyEvent * event);
	virtual void paintEvent(QPaintEvent * event);
	virtual void resizeEvent(QResizeEvent * event);
	virtual void closeEvent(QCloseEvent * event);
	virtual void enterEvent(QEvent * event);
    virtual void leaveEvent(QEvent * event);
    virtual void moveEvent(QMoveEvent * event);
	//
signals:
	 void mousePressSignal(QMouseEvent * event );
	 void mouseReleaseSignal(QMouseEvent *  event);
	 void mouseDoubleClickSignal(QMouseEvent *  event);
	 void mouseMoveSignal(QMouseEvent * event);
	//#ifndef QT_NO_WHEELEVENT
	 void wheelSignal(QWheelEvent * event);
	//#endif
	 void keyPressSignal(QKeyEvent* event);
	 void keyReleaseSignal(QKeyEvent * event);
public:
	void fullScreen();
	void exitFullScreen();
	//kk
	//VirtualMine::Scene::CGeoSpatialControl* mpGeoSceneControl;
private:
	//kk原始代码
	VirtualMine::Scene::CGeoSpatialControl* mpGeoSceneControl;
	CSubCameraChangedListener* mpCameraChangedListener;
	bool mIsFullScreen;
	
	////new ui
	QTabWidget* ref_tabwidght;
public:
	///鼠标状态
	bool mIsMousePress;
	bool mIsMouseDragging;
};

#endif // VRCONTROL_H
