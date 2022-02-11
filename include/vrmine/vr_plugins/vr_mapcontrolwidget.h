#ifndef VR_MapControlWidget_H
#define VR_MapControlWidget_H

//定义插件导出符号
#ifndef QMAPCONTROL_EXPORT_WIDGETS
#define VRMAPCONTROL_WIDGET_DLL _declspec(dllimport)
#else
#define VRMAPCONTROL_WIDGET_DLL _declspec(dllexport)
#endif

#include <QtGui/QWidget>
#include "OGRE/OgreAxisAlignedBox.h"

namespace VirtualMine
{
	namespace Map
	{
		class CMap;
	}
}

class VR_MapControlWidget_Private;

enum EMapOperateType
{
	MOT_PAN,
	MOT_ZOOMIN,
	MOT_ZOOMOUT,
	MOT_ZOOMMAPIMAGE,
	MOT_POINTSELECT,
	MOT_POLYGONSELECT,
	MOT_NONE
};

class VRMAPCONTROL_WIDGET_DLL VR_MapControlWidget : public QWidget
{
	Q_OBJECT

public:
	VR_MapControlWidget(QWidget *parent = 0);
	~VR_MapControlWidget();
	virtual void paintEvent(QPaintEvent * evt);
	virtual void mousePressEvent(QMouseEvent * evt);
	virtual void mouseReleaseEvent(QMouseEvent * evt);
	virtual void mouseMoveEvent(QMouseEvent * evt);
	virtual void wheelEvent(QWheelEvent * evt);
	virtual void resizeEvent(QResizeEvent * evt);

	virtual void keyPressEvent(QKeyEvent * event);
	virtual void keyReleaseEvent(QKeyEvent * event);

	virtual void drawScale(QPainter& painter);

signals:
     void keyPressSignal(QKeyEvent* event);
	 void keyReleaseSignal(QKeyEvent* event);
public:
	virtual void setBoundingBox(const Ogre::AxisAlignedBox& boundingBox);
	virtual Ogre::AxisAlignedBox& getBoundingBox();
	void setCurMapOperateType(const EMapOperateType& type);
	EMapOperateType getCurMapOperateType();
	void setBackgroundColor(const QColor& color);
	QColor getBackgroundColor();
	VirtualMine::Map::CMap* addMap();
	void updateBounds();
	void refresh();
	virtual Ogre::AxisAlignedBox& getInitialBoundingBox();
	virtual void setInitialBoundingBox(const Ogre::AxisAlignedBox& boundingBox);

private:
	void panMap();
	void zoomInMap();
	void zoomOutMap();
	void computeDrawExtend();
	void reComputeDrawExtend(const QPointF& lastPostion,
		const QPointF& curPostion);
	void scaleMapAtPoint(const QPointF& curMousePos,const double& scale);
	void computeCurPrjPosition(const QPointF& pos);
	void excutePointSelection(const QPointF& curMousePos);

	void drawMap(QPainter& painter);
	void drawZoomShape(QPainter& painter);
	void drawPanMap(QPainter& painter);
	void drawZoomImage(QPainter& painter);

public:
	void fullScreen();
	void exitFullScreen();

private:
	VR_MapControlWidget_Private* mpPrivate;
	bool mIsFullScreen;
};

#endif // VR_MapControlWidget_H
