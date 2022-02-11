#include "vrdbscenecontrolwidget.h"
#include <qpainter.h>
#include <qcoreevent.h>
#include <qevent.h>

VRDBSceneControlWidget::VRDBSceneControlWidget(QWidget *parent)
	: QTreeWidget(parent)
{

}

VRDBSceneControlWidget::~VRDBSceneControlWidget()
{

}

void VRDBSceneControlWidget::paintEvent(QPaintEvent * evt)
{
	QPainter painter(this); 
	int size(20);
	QFont font("Arial",size,QFont::Bold,false);
	painter.setFont(font);
	QPen pen; //
	pen.setColor(QColor(0,0,255,255));  
	QBrush brush(QColor(150,150,150,150)); //
	painter.setPen(pen); //
	painter.setBrush(brush); //
	painter.drawRect(0,0,this->width(),this->height()); //
	QString str(tr("VR-SceneControl"));
	int horizonOffset = str.length() * size;
	painter.drawText((this->width()-horizonOffset) / 2,this->height() / 2,str);
}
