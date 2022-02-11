#ifndef VRSCENETREEWIDGET_H
#define VRSCENETREEWIDGET_H

#include <QtGui/QWidget>

class VRSceneTreeWidget : public QWidget
{
	Q_OBJECT

public:
	VRSceneTreeWidget(QWidget *parent = 0);
	~VRSceneTreeWidget();
	virtual void paintEvent(QPaintEvent * evt);

};

#endif // VRSCENETREEWIDGET_H
