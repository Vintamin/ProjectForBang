#ifndef VR_APPLICATION_H
#define VR_APPLICATION_H

#include <QtGui/QMainWindow>
#include "ui_vr_application.h"

class VR_Application : public QMainWindow
{
	Q_OBJECT

public:
	VR_Application(QWidget *parent = 0, Qt::WFlags flags = 0);
	~VR_Application();
private slots:
	void slotPanMap();
	void slotZoomInMap();
	void slotZoomOutMap();
	void slotFullScreen();
	void slotReset();
private:
	Ui::VR_ApplicationClass ui;
};

#endif // VR_APPLICATION_H
