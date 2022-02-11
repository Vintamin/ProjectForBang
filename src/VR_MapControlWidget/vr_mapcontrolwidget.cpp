#include "vrmine/vr_plugins/vr_mapcontrolwidget.h"
#include <qpainter.h>
#include <qcoreevent.h>
#include <qevent.h>
#include "vrmine/vr_maplayer/map.h"
#include "OGRE/OgreStringConverter.h"


using namespace VirtualMine::Map;


class VR_MapControlWidget_Private 
{
public:

	VR_MapControlWidget_Private(VR_MapControlWidget* ref_pParentWidget)
		:ref_mpParentWidget(ref_pParentWidget)
	{
		this->mIsMousePress = false;
		this->mIsMouseDragging = false;
		this->mCurMapOperateType = MOT_NONE;
		this->mLeftTopPrjPos = QPointF(0,0);
		this->mRightBottomPrjPos = QPointF(0,0);
		this->mCurScale = 1;
		this->drawMap(1000,800);
	}

	~VR_MapControlWidget_Private()
	{

	}

	bool drawMap(const int& width,const int& height)
	{
		this->mRenderBufferImage = QPixmap(width,height);
		this->mRenderImage = QPixmap(width,height);
		//this->mRenderImage.fill(QColor(255,255,255,0));
		QPainter painter(&this->mRenderImage);
		int size(20);
		QFont font("Arial",size,QFont::Bold,false);
		painter.setFont(font);
		QPen pen; //
		//先绘制底图
		pen.setColor(QColor(255,0,0,255));  
		QBrush brush(QColor(0,150,0,150)); //
		painter.fillRect(QRect(100,100,400,400),QColor(255,255,0,100));
		painter.drawRect(100,100,400,400);


		//pen.setColor(QColor(0,0,255,255));  
		//brush.setColor(QColor(150,150,150,150)); //
		//painter.setPen(pen); //
		//painter.setBrush(brush); //
		//painter.drawRect(0,0,this->ref_mpParentWidget->width(),this->ref_mpParentWidget->height()); //
		//QString str(tr("2DMapControl..."));
		//int horizonOffset = str.length() * size;
		//再绘制文字
		//painter.drawText((this->ref_mpParentWidget->width()-horizonOffset) / 2,this->ref_mpParentWidget->height() / 2,str);
		return true;
	}

	QPixmap mRenderImage;
	QPixmap mRenderBufferImage;
	VR_MapControlWidget* ref_mpParentWidget;
	bool mIsMousePress;
	bool mIsMouseDragging;
	QPointF mMouseLastPos;
	QPointF mMoveDirection;
	EMapOperateType mCurMapOperateType;
	std::vector<CMap*> mMaps;
	QPointF mLeftTopPrjPos;
	QPointF mRightBottomPrjPos;
	QPointF mCurMousePrjPos;
	double mCurScale;
	Ogre::AxisAlignedBox mBoundingBox;
};

VR_MapControlWidget::VR_MapControlWidget(QWidget *parent)
	: QWidget(parent)
{
	this->mpPrivate = new VR_MapControlWidget_Private(this);
}

VR_MapControlWidget::~VR_MapControlWidget()
{

}

VirtualMine::Map::CMap* VR_MapControlWidget::addMap()
{
	CMap* pMap = new VirtualMine::Map::CMap();
	this->mpPrivate->mMaps.push_back(pMap);
	return pMap;	
}

void VR_MapControlWidget::setCurMapOperateType(const EMapOperateType& type)
{
	this->mpPrivate->mCurMapOperateType = type;
}

void VR_MapControlWidget::panMap()
{

}
	
void VR_MapControlWidget::zoomInMap()
{
	
}
	
void VR_MapControlWidget::zoomOutMap()
{
	
}

void VR_MapControlWidget::resizeEvent(QResizeEvent * evt)
{
	this->mpPrivate->drawMap(this->width(),this->height());
}

void VR_MapControlWidget::drawZoomShape(QPainter& painter)
{
	QPixmap tempMap = this->mpPrivate->mRenderImage;
	QPainter curZoomInBufferPainter(&tempMap);
	QPen pen(QColor(255,0,0,255));
	pen.setWidth(2);
	curZoomInBufferPainter.setPen(pen);
	QPointF curPoint = this->mpPrivate->mMouseLastPos + this->mpPrivate->mMoveDirection;
	int zoomWidth = curPoint.x() - this->mpPrivate->mMouseLastPos.x();
	int zoomHeigth = curPoint.y() - this->mpPrivate->mMouseLastPos.y();
	QRect rect(this->mpPrivate->mMouseLastPos.x(),
		this->mpPrivate->mMouseLastPos.y(),zoomWidth,zoomHeigth);
	curZoomInBufferPainter.drawRect(rect);
	QFont font("Arial",15,QFont::Bold,false);
	curZoomInBufferPainter.setFont(font);
	QString zoomLabel = this->mpPrivate->mCurMapOperateType == MOT_ZOOMIN ? QString("ZoomIn") : QString("ZoomOut");
	curZoomInBufferPainter.setPen(QPen(QColor(0,0,255,255)));
	curZoomInBufferPainter.drawText(rect,zoomLabel);
	painter.drawPixmap(0,0,tempMap);
}

void VR_MapControlWidget::drawPanMap(QPainter& painter)
{
	QPixmap tempMap(this->width(),this->height());
	QPainter curPanBufferPainter(&tempMap);
	curPanBufferPainter.drawPixmap(this->mpPrivate->mMoveDirection.x(),
		this->mpPrivate->mMoveDirection.y(),this->mpPrivate->mRenderImage);

	painter.drawPixmap(0,0,tempMap);
	this->mpPrivate->mRenderBufferImage = tempMap;
}

void VR_MapControlWidget::paintEvent(QPaintEvent * evt)
{
	QPainter painter(this); 
	//漫游操作
	if (this->mpPrivate->mCurMapOperateType == MOT_PAN
		&& this->mpPrivate->mIsMouseDragging)
	{
		this->drawPanMap(painter);
	}
	//放大、缩小操作
	else if ((this->mpPrivate->mCurMapOperateType == MOT_ZOOMIN
		|| this->mpPrivate->mCurMapOperateType == MOT_ZOOMOUT)
		&& this->mpPrivate->mIsMouseDragging)
	{
		this->drawZoomShape(painter);
	}
	//重新绘图
	else
	{
		this->drawMap(painter);
	}
	
	
}

void VR_MapControlWidget::setBoundingBox(const Ogre::AxisAlignedBox& boundingBox)
{
	this->mpPrivate->mBoundingBox = boundingBox;
}

Ogre::AxisAlignedBox& VR_MapControlWidget::getBoundingBox()
{
	return this->mpPrivate->mBoundingBox;
}

void VR_MapControlWidget::updateBounds()
{
	this->computeDrawExtend();
}

void VR_MapControlWidget::reComputeDrawExtend(const QPointF& lastPostion,const QPointF& curPostion)
{
	if (this->mpPrivate->mCurMapOperateType == MOT_PAN)
	{
		QPointF panDirection = curPostion - lastPostion;
		QPointF deltaScale = (panDirection * this->mpPrivate->mCurScale);
		this->mpPrivate->mLeftTopPrjPos.setX(this->mpPrivate->mLeftTopPrjPos.x() - deltaScale.x());
		this->mpPrivate->mLeftTopPrjPos.setY(this->mpPrivate->mLeftTopPrjPos.y() + deltaScale.y());

		this->mpPrivate->mRightBottomPrjPos.setX(this->mpPrivate->mRightBottomPrjPos.x() - deltaScale.x());
		this->mpPrivate->mRightBottomPrjPos.setY(this->mpPrivate->mRightBottomPrjPos.y() + deltaScale.y());

	}
	else if (this->mpPrivate->mCurMapOperateType == MOT_ZOOMIN)
	{
		QPointF leftTopPrjPos = this->mpPrivate->mLeftTopPrjPos;
		this->mpPrivate->mLeftTopPrjPos.setX(leftTopPrjPos.x() + lastPostion.x() * this->mpPrivate->mCurScale);
		this->mpPrivate->mLeftTopPrjPos.setY(leftTopPrjPos.y() - lastPostion.y() * this->mpPrivate->mCurScale);

		this->mpPrivate->mRightBottomPrjPos.setX(leftTopPrjPos.x() + curPostion.x() * this->mpPrivate->mCurScale);
		this->mpPrivate->mRightBottomPrjPos.setY(leftTopPrjPos.y() - curPostion.y() * this->mpPrivate->mCurScale);

		this->mpPrivate->mBoundingBox.setMaximum(this->mpPrivate->mRightBottomPrjPos.x(),
			this->mpPrivate->mLeftTopPrjPos.y(),0);
		this->mpPrivate->mBoundingBox.setMinimum(this->mpPrivate->mLeftTopPrjPos.x(),
			this->mpPrivate->mRightBottomPrjPos.y(),0);

		this->computeDrawExtend();
	}
	else if (this->mpPrivate->mCurMapOperateType == MOT_ZOOMOUT)
	{

	}
}

void VR_MapControlWidget::computeDrawExtend()
{
	float extendDx = this->mpPrivate->mBoundingBox.getMaximum().x - this->mpPrivate->mBoundingBox.getMinimum().x;
	float extendDy = this->mpPrivate->mBoundingBox.getMaximum().y - this->mpPrivate->mBoundingBox.getMinimum().y;
	float extendRatio = extendDx / extendDy;
	float viewRatio = this->width() / (float)this->height();
	if (viewRatio > extendRatio)
	{
		//以高度方向占满整个视口（每个像素代表的实际长度）
		this->mpPrivate->mCurScale = extendDy / this->height();
	}
	else 
	{
		//以宽度方向占满整个视口
		this->mpPrivate->mCurScale = extendDx / this->width();
	}
	QPointF mapCenterPos((this->mpPrivate->mBoundingBox.getMaximum().x 
		+ this->mpPrivate->mBoundingBox.getMinimum().x)/2,
		(this->mpPrivate->mBoundingBox.getMaximum().y 
		+ this->mpPrivate->mBoundingBox.getMinimum().y)/2);

	this->mpPrivate->mLeftTopPrjPos.setX(mapCenterPos.x() - this->mpPrivate->mCurScale * this->width()/2);
	this->mpPrivate->mLeftTopPrjPos.setY(mapCenterPos.y() + this->mpPrivate->mCurScale * this->height()/2);
	
	this->mpPrivate->mRightBottomPrjPos.setX(mapCenterPos.x() + this->mpPrivate->mCurScale * this->width()/2);
	this->mpPrivate->mRightBottomPrjPos.setY(mapCenterPos.y() - this->mpPrivate->mCurScale * this->height()/2);
}

void VR_MapControlWidget::drawMap(QPainter& painter)
{
	std::vector<QPixmap> curImages;
	for (size_t i = 0; i < this->mpPrivate->mMaps.size(); ++i)
	{
		if (this->mpPrivate->mMaps[i]->draw(painter,
			this->width(),this->height(),
			this->mpPrivate->mLeftTopPrjPos,
			this->mpPrivate->mRightBottomPrjPos,
			this->mpPrivate->mCurScale))
		{
			curImages.push_back(this->mpPrivate->mMaps[i]->getMapImage());
		}
		
	}
	QPixmap renderBufferImage(this->width(),this->height());
	QPainter curBufferPainter(&renderBufferImage);
	//绘制地图
	if (curImages.size() > 0)
	{
		for (size_t i = 0; i < curImages.size(); ++i)
		{
			curBufferPainter.drawPixmap(0,0,curImages[i]);
		}
	}
	this->mpPrivate->mRenderImage = renderBufferImage;
	//绘制坐标信息
	//计算当前鼠标的坐标
	QPen pen(QColor(0,0,0,255));
	curBufferPainter.setPen(pen);

	Ogre::String coorInfo = "X:";
	coorInfo += Ogre::StringConverter::toString((unsigned long)this->mpPrivate->mCurMousePrjPos.x());
	coorInfo += "  Y：";
	coorInfo += Ogre::StringConverter::toString((unsigned long)this->mpPrivate->mCurMousePrjPos.y());
	curBufferPainter.drawText(5,this->height() - 5,QString(coorInfo.c_str()));

	
	painter.drawPixmap(0,0,renderBufferImage);
}

void VR_MapControlWidget::refresh()
{
	this->update();
}

void VR_MapControlWidget::mousePressEvent(QMouseEvent * evt)
{
	if(evt->button()==Qt::LeftButton) //
	{
		this->mpPrivate->mIsMousePress = true;
		this->mpPrivate->mMouseLastPos = evt->posF();

		QCursor cursor = Qt::ArrowCursor;
		if (this->mpPrivate->mCurMapOperateType == MOT_PAN)
		{
			cursor = QCursor(QPixmap("data\\Resources\\image\\pan.png")); 
		}
		else if (this->mpPrivate->mCurMapOperateType == MOT_ZOOMIN)
		{
			cursor = QCursor(QPixmap("data\\Resources\\image\\zoomIn.PNG")); 
		}
		else if (this->mpPrivate->mCurMapOperateType == MOT_ZOOMOUT)
		{
			cursor = QCursor(QPixmap("data\\Resources\\image\\zoomOut.png")); 
		}
		this->setCursor(cursor);
	}
	
}

void VR_MapControlWidget::computeCurPrjPosition(const QPointF& pos)
{
	this->mpPrivate->mCurMousePrjPos.setX(this->mpPrivate->mLeftTopPrjPos.x() + pos.x() * this->mpPrivate->mCurScale);
	this->mpPrivate->mCurMousePrjPos.setY(this->mpPrivate->mLeftTopPrjPos.y() - pos.y() * this->mpPrivate->mCurScale);
}

void VR_MapControlWidget::mouseMoveEvent(QMouseEvent * evt)
{
	if (this->mpPrivate->mIsMousePress)
	{
		this->mpPrivate->mIsMouseDragging = true;
		this->mpPrivate->mMoveDirection = evt->posF() - this->mpPrivate->mMouseLastPos;
	}
	this->computeCurPrjPosition(evt->posF());
	this->update();
}

void VR_MapControlWidget::mouseReleaseEvent(QMouseEvent * evt)
{
	if (this->mpPrivate->mIsMouseDragging)
	{
		this->mpPrivate->mRenderImage = this->mpPrivate->mRenderBufferImage;
		this->mpPrivate->mIsMouseDragging = false;
		this->mpPrivate->mMoveDirection = evt->posF() - this->mpPrivate->mMouseLastPos;
		this->reComputeDrawExtend(this->mpPrivate->mMouseLastPos,evt->posF());
		this->update();
	}
	
	this->mpPrivate->mMoveDirection = QPointF(0,0);
	this->mpPrivate->mIsMousePress = false;
	QCursor cursor = Qt::ArrowCursor;
	this->setCursor(cursor);
}

void VR_MapControlWidget::wheelEvent(QWheelEvent * evt)
{

}