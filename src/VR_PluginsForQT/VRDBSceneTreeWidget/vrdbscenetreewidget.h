#ifndef VRDBSCENETREEWIDGET_H
#define VRDBSCENETREEWIDGET_H

#include <QtGui/QTreeWidget>

class VRDBSceneTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	VRDBSceneTreeWidget(QWidget *parent = 0);
	~VRDBSceneTreeWidget();
	virtual void paintEvent(QPaintEvent * evt);

};

#endif // VRDBSCENETREEWIDGET_H
