#ifndef VR_MAPCONTROLWIDGET_H
#define VR_MAPCONTROLWIDGET_H

#include <QtGui/QWidget>

class VR_MapControlWidget : public QWidget
{
	Q_OBJECT

public:
	VR_MapControlWidget(QWidget *parent = 0);
	~VR_MapControlWidget();
	virtual void paintEvent(QPaintEvent * evt);
	
 
};

#endif // VR_MAPCONTROLWIDGET_H
