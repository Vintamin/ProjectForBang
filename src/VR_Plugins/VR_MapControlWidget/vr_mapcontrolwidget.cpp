#include "vrmine/vr_plugins/vr_mapcontrolwidget.h"
#include <qpainter.h>
#include <qcoreevent.h>
#include <qevent.h>
#include "vrmine/vr_maplayer/map.h"
#include "OGRE/OgreStringConverter.h"
#include <QtGui/QBrush>
#include "vrmine/vr_spatialengine/geoscenecamera.h"

using namespace VirtualMine::Map;

class CRefreshMapHandler : public VirtualMine::Core::CEventHandler
{
public:
	CRefreshMapHandler(VR_MapControlWidget* ref_pOperator)
	{
		this->ref_mpOperator = ref_pOperator;
		this->isScene = false;

	}
	~CRefreshMapHandler()
	{

	}
	virtual bool handleEvent(VirtualMine::Core::CEvent* evt)
	{
		if (this->ref_mpOperator)
		{
			CRefreshMapEvent* pRefreshEvt = dynamic_cast<CRefreshMapEvent*>(evt);
			if (pRefreshEvt)
			{
				this->ref_mpOperator->updateBounds();
				this->ref_mpOperator->refresh();
				return true;
			}
			CBangLayerFlyToSceneEvent* pFlytoScene = dynamic_cast<CBangLayerFlyToSceneEvent*>(evt);
			if (pFlytoScene)
			{
				VirtualMine::SpatialInterface::ILayer* pLayer = pFlytoScene->get3DLayer();
				if (pLayer)
				{
					//kk
					if (pLayer->getType() == VirtualMine::Core::GeoDataType::GDT_ESCAPEROUTE 
						||pLayer->getType() == VirtualMine::Core::GeoDataType::GDT_TERRANE
						||pLayer->getType() == VirtualMine::Core::GeoDataType::GDT_CONPROGRESS
						)
					{
						if (!this->isScene)
						{
							this->ref_mpOperator->setVisible(false);
							VirtualMine::SpatialEngine::CGeoSceneCamera* pCamera = dynamic_cast<VirtualMine::SpatialEngine::CGeoSceneCamera*>(pLayer->getGeoSceneManager()->getCamera(VirtualMine::SpatialEngine::CGeoSceneCamera::DEFAULT_CAMERA_NAME));
							if (pCamera)
							{
								pCamera->setPosition(3894,754,1060);
								pCamera->setDirection(0,-1,-1); 
								this->isScene = true;
							}
							
						}
					

					}
					else if (pLayer->getType() == VirtualMine::Core::GeoDataType::GDT_SHOTHOLE 
						     ||pLayer->getType() == VirtualMine::Core::GeoDataType::GDT_LANEWAYSECTION)
					{
					  if (this->isScene)
					  {
						  this->ref_mpOperator->setVisible(true);
						  VirtualMine::SpatialEngine::CGeoSceneCamera* pCamera = dynamic_cast<VirtualMine::SpatialEngine::CGeoSceneCamera*>(pLayer->getGeoSceneManager()->getCamera(VirtualMine::SpatialEngine::CGeoSceneCamera::DEFAULT_CAMERA_NAME));
						 if (pCamera)
						 {
							 pCamera->setPosition(0,50,50);
							 pCamera->setDirection(0,-1,-1);
							 this->isScene = false;
						 }
						
					  }
				
					}
				}
			}
		}
		return false;
	}
protected:
	VR_MapControlWidget* ref_mpOperator; 
    bool isScene;

};

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
		this->mBackgroundColor = QColor(255,255,255,0);
		this->drawMap(1000,800);
		this->mpRefreshMapHandler = new CRefreshMapHandler(ref_pParentWidget);
		this->mDefaultScaleFactor = 0.2;
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
	Ogre::AxisAlignedBox mInitialBoundingBox;


	QColor mBackgroundColor;
	CRefreshMapHandler* mpRefreshMapHandler;
	double mDefaultScaleFactor;
};


VR_MapControlWidget::VR_MapControlWidget(QWidget *parent)
	: QWidget(parent)
{
	this->mpPrivate = new VR_MapControlWidget_Private(this);
	this->setMouseTracking(true);
	mIsFullScreen = false;
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

void VR_MapControlWidget::setBackgroundColor(const QColor& color)
{
	this->mpPrivate->mBackgroundColor = color;
}

QColor VR_MapControlWidget::getBackgroundColor()
{
	return this->mpPrivate->mBackgroundColor;
}

EMapOperateType VR_MapControlWidget::getCurMapOperateType()
{
	return this->mpPrivate->mCurMapOperateType;
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
	//this->mpPrivate->drawMap(this->width(),this->height());
	this->computeDrawExtend();
	this->refresh();
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
	/*QFont font("Arial",15,QFont::Bold,false);
	curZoomInBufferPainter.setFont(font);
	QString zoomLabel = this->mpPrivate->mCurMapOperateType == MOT_ZOOMIN ? QString("ZoomIn") : QString("ZoomOut");
	curZoomInBufferPainter.setPen(QPen(QColor(0,0,255,255)));
	curZoomInBufferPainter.drawText(rect,zoomLabel);*/
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
	else if (this->mpPrivate->mCurMapOperateType == MOT_ZOOMMAPIMAGE)
	{
		this->drawZoomImage(painter);
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
	if (this->mpPrivate->mMaps.size() > 0)
	{
		this->mpPrivate->mBoundingBox.setNull();
		for (size_t i = 0; i < this->mpPrivate->mMaps.size(); ++i)
		{
			this->mpPrivate->mMaps[i]->computeBoundingBox();
			this->mpPrivate->mBoundingBox.merge(this->mpPrivate->mMaps[i]->getBoundingBox());
		}
	}
	
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
        QPointF tmpLastPoint = lastPostion;
		QPointF tmpCurPoint = curPostion;
		if (lastPostion.y() > curPostion.y())
		{
			tmpLastPoint = curPostion;
			tmpCurPoint = lastPostion;
		
		}
		this->mpPrivate->mLeftTopPrjPos.setX(leftTopPrjPos.x() + tmpLastPoint.x() * this->mpPrivate->mCurScale);
		this->mpPrivate->mLeftTopPrjPos.setY(leftTopPrjPos.y() - tmpLastPoint.y() * this->mpPrivate->mCurScale);

		this->mpPrivate->mRightBottomPrjPos.setX(leftTopPrjPos.x() + tmpCurPoint.x() * this->mpPrivate->mCurScale);
		this->mpPrivate->mRightBottomPrjPos.setY(leftTopPrjPos.y() - tmpCurPoint.y() * this->mpPrivate->mCurScale);


	/*	this->mpPrivate->mLeftTopPrjPos.setX(leftTopPrjPos.x() + lastPostion.x() * this->mpPrivate->mCurScale);
		this->mpPrivate->mLeftTopPrjPos.setY(leftTopPrjPos.y() - lastPostion.y() * this->mpPrivate->mCurScale);

		this->mpPrivate->mRightBottomPrjPos.setX(leftTopPrjPos.x() + curPostion.x() * this->mpPrivate->mCurScale);
		this->mpPrivate->mRightBottomPrjPos.setY(leftTopPrjPos.y() - curPostion.y() * this->mpPrivate->mCurScale);*/

		this->mpPrivate->mBoundingBox.setMaximum(this->mpPrivate->mRightBottomPrjPos.x(),
			this->mpPrivate->mLeftTopPrjPos.y(),0);
		this->mpPrivate->mBoundingBox.setMinimum(this->mpPrivate->mLeftTopPrjPos.x(),
			this->mpPrivate->mRightBottomPrjPos.y(),0);

		this->computeDrawExtend();
	}
	else if (this->mpPrivate->mCurMapOperateType == MOT_ZOOMOUT)/////////
	{
		/*QPointF leftTopPrjPos = this->mpPrivate->mLeftTopPrjPos;
		this->mpPrivate->mLeftTopPrjPos.setX(leftTopPrjPos.x() - lastPostion.x() * this->mpPrivate->mCurScale  );
		this->mpPrivate->mLeftTopPrjPos.setY(leftTopPrjPos.y() + lastPostion.y() * this->mpPrivate->mCurScale );

		this->mpPrivate->mRightBottomPrjPos.setX(leftTopPrjPos.x() - curPostion.x() * this->mpPrivate->mCurScale );
		this->mpPrivate->mRightBottomPrjPos.setY(leftTopPrjPos.y() + curPostion.y() * this->mpPrivate->mCurScale );

		this->mpPrivate->mBoundingBox.setMaximum(this->mpPrivate->mRightBottomPrjPos.x(),
			this->mpPrivate->mLeftTopPrjPos.y(),0);
		this->mpPrivate->mBoundingBox.setMinimum(this->mpPrivate->mLeftTopPrjPos.x(),
			this->mpPrivate->mRightBottomPrjPos.y(),0);

			this->computeDrawExtend();*/
		qreal x = lastPostion.x() + curPostion.x();
		x /= 2;
		qreal y = lastPostion.y() + curPostion.y();
		y /= 2;
		QPointF curMousePos(x,y);
		double scale = this->width() / Ogre::Math::Abs(lastPostion.x() - curPostion.x());
		this->scaleMapAtPoint(QPointF(curMousePos.x(),curMousePos.y()),scale);
		this->refresh();
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

void VR_MapControlWidget::drawZoomImage(QPainter& painter)
{

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
	QBrush brush(this->mpPrivate->mBackgroundColor);
	//QPainter painterBackground(this);
	//painter.setBrush(brush);
	QPalette p;
	p.setBrush(QPalette::Background,brush);
	this->setPalette(p);

	QPixmap renderBufferImage(this->width(),this->height());
	renderBufferImage.fill(Qt::transparent);
	QPainter curBufferPainter(&renderBufferImage);
	
	curBufferPainter.setBrush(brush);
	curBufferPainter.drawRect(0,0,this->width(),this->height());
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
	QPen pen(QColor(255-this->mpPrivate->mBackgroundColor.red(),
		255 - this->mpPrivate->mBackgroundColor.green(),
		255 - this->mpPrivate->mBackgroundColor.blue(),
		255));
	curBufferPainter.setPen(pen);

	Ogre::String coorInfo = "X:";
	coorInfo += QString::number(this->mpPrivate->mCurMousePrjPos.x(),'g',2).toLocal8Bit().constData();
	coorInfo += "  Y：";
	coorInfo += QString::number(this->mpPrivate->mCurMousePrjPos.y(),'g',2).toLocal8Bit().constData();
	
	curBufferPainter.drawText(5,this->height() - 5,QString(coorInfo.c_str()));

	this->drawScale(curBufferPainter);
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
			cursor = QCursor(QPixmap("data\\Resources\\image\\handing.png")); 
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
		//this->mpPrivate
		this->mpPrivate->mIsMouseDragging = true;
		this->mpPrivate->mMoveDirection = evt->posF() - this->mpPrivate->mMouseLastPos;
	}
	else
	{
		if (this->mpPrivate->mCurMapOperateType == MOT_PAN)
		{
			QCursor cursor = Qt::ArrowCursor;
			cursor = QCursor(QPixmap("data\\Resources\\image\\hand.png")); 
			this->setCursor(cursor);
		}
	}
	this->computeCurPrjPosition(evt->posF());
	this->update();
}

void VR_MapControlWidget::excutePointSelection(const QPointF& curMousePos)
{
	this->computeCurPrjPosition(curMousePos);
	for (size_t i = 0; i < this->mpPrivate->mMaps.size(); ++i)
	{
		double tolerance = this->mpPrivate->mCurScale * 2;
		this->mpPrivate->mMaps[i]->pointSelect(this->mpPrivate->mCurMousePrjPos,tolerance);
	}
}

void VR_MapControlWidget::mouseReleaseEvent(QMouseEvent * evt)
{
	if(evt->button()==Qt::LeftButton) //
	{
		if (this->mpPrivate->mIsMouseDragging)
		{
			this->mpPrivate->mRenderImage = this->mpPrivate->mRenderBufferImage;
			this->mpPrivate->mIsMouseDragging = false;
			this->mpPrivate->mMoveDirection = evt->posF() - this->mpPrivate->mMouseLastPos;
			this->reComputeDrawExtend(this->mpPrivate->mMouseLastPos,evt->posF());
			this->update();
		}
		else 
		{
			if (this->mpPrivate->mCurMapOperateType == MOT_POINTSELECT)
			{
				this->excutePointSelection(evt->posF());	
			}
			else if (this->mpPrivate->mCurMapOperateType == MOT_POLYGONSELECT)
			{

			}
		}

		this->mpPrivate->mMoveDirection = QPointF(0,0);
		this->mpPrivate->mIsMousePress = false;
		QCursor cursor = Qt::ArrowCursor;
		if (this->mpPrivate->mCurMapOperateType == MOT_PAN)
		{
			cursor = QCursor(QPixmap("data\\Resources\\image\\hand.png")); 
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
	else
	{
		this->setCursor(Qt::ArrowCursor);
		this->mpPrivate->mCurMapOperateType = MOT_NONE;
	}
}

void VR_MapControlWidget::scaleMapAtPoint(const QPointF& curMousePos,const double& scale)
{
	this->computeCurPrjPosition(curMousePos);
	//计算左上角的点的变化
	double deltaX = this->mpPrivate->mLeftTopPrjPos.x() - this->mpPrivate->mCurMousePrjPos.x();
	double deltaY = this->mpPrivate->mLeftTopPrjPos.y() - this->mpPrivate->mCurMousePrjPos.y();
	deltaX *= scale;
	deltaY *= scale;

	double curLeftTopPos_x = this->mpPrivate->mCurMousePrjPos.x() + deltaX;
	double curLeftTopPos_y = this->mpPrivate->mCurMousePrjPos.y() + deltaY;
	this->mpPrivate->mLeftTopPrjPos.setX(curLeftTopPos_x);
	this->mpPrivate->mLeftTopPrjPos.setY(curLeftTopPos_y);

	//计算右下角点的变化
	deltaX = this->mpPrivate->mRightBottomPrjPos.x() - this->mpPrivate->mCurMousePrjPos.x();
	deltaY = this->mpPrivate->mRightBottomPrjPos.y() - this->mpPrivate->mCurMousePrjPos.y();
	deltaX *= scale;
	deltaY *= scale;

	curLeftTopPos_x = this->mpPrivate->mCurMousePrjPos.x() + deltaX;
	curLeftTopPos_y = this->mpPrivate->mCurMousePrjPos.y() + deltaY;
	this->mpPrivate->mRightBottomPrjPos.setX(curLeftTopPos_x);
	this->mpPrivate->mRightBottomPrjPos.setY(curLeftTopPos_y);

	this->mpPrivate->mBoundingBox.setMaximum(this->mpPrivate->mRightBottomPrjPos.x(),
		this->mpPrivate->mLeftTopPrjPos.y(),0);
	this->mpPrivate->mBoundingBox.setMinimum(this->mpPrivate->mLeftTopPrjPos.x(),
		this->mpPrivate->mRightBottomPrjPos.y(),0);
	this->computeDrawExtend();
}

void VR_MapControlWidget::wheelEvent(QWheelEvent * evt)
{
	EMapOperateType lastMouseOperateType = this->mpPrivate->mCurMapOperateType;
	this->mpPrivate->mCurMapOperateType = MOT_ZOOMMAPIMAGE;
	QPoint curMousePos = evt->pos();
	double defaultScaleFactor = 1.2;
	int delta = evt->delta();
	if (delta < 0)
	{
		defaultScaleFactor = 1 + this->mpPrivate->mDefaultScaleFactor;
	}
	else 
	{
		defaultScaleFactor = 1 - this->mpPrivate->mDefaultScaleFactor; 
	}
	this->scaleMapAtPoint(QPointF(curMousePos.x(),curMousePos.y()),defaultScaleFactor);
	this->refresh();
	this->mpPrivate->mCurMapOperateType = lastMouseOperateType;
}

void VR_MapControlWidget::fullScreen()
{
	if (!this->mIsFullScreen)
	{
		this->setWindowFlags(Qt::Window);///Qt::Dialog
		this->showFullScreen();
		this->mIsFullScreen = true;
	}
}

void VR_MapControlWidget::exitFullScreen()
{
	if (this->mIsFullScreen)
	{
		this->setWindowFlags(Qt::SubWindow);
		this->showNormal();
		this->mIsFullScreen = false;
	}
}

void VR_MapControlWidget::keyPressEvent( QKeyEvent * event )
{

}

void VR_MapControlWidget::keyReleaseEvent( QKeyEvent * event )
{
	
	
		if (event->key() == Qt::Key_Escape)
		{
			this->exitFullScreen();
	
		}
	emit keyReleaseSignal(event);
}

Ogre::AxisAlignedBox& VR_MapControlWidget::getInitialBoundingBox()
{
	return this->mpPrivate->mInitialBoundingBox;
}

void VR_MapControlWidget::setInitialBoundingBox( const Ogre::AxisAlignedBox& boundingBox )
{
	this->mpPrivate->mInitialBoundingBox = boundingBox;
}

void VR_MapControlWidget::drawScale( QPainter& painter )
{
	qreal pixelCount = 100;//100个像素代表的实际距离
	qreal realDis = pixelCount * this->mpPrivate->mCurScale;//每个像素代表的实际距离
	qreal y = this->height() - 5;
	qreal beginX = 120;
	if (y < 30)
		return;
	QPointF ptUp_leftLine(beginX + 5,y-3);
	QPointF ptDown_leftLine(beginX + 5,y);

	QPointF ptUp_rigthLine(beginX + 5+pixelCount,y-3);
	QPointF ptDown_rigthLine(beginX + 5+pixelCount,y);

	QPointF ptLeft_centerLine(beginX + 5,y);
	QPointF ptRight_centerLine(beginX + 5+pixelCount,y);

	QPen oldPen = painter.pen();
	QPen curPen = painter.pen();
	curPen.setWidth(3);
	painter.setPen(curPen);
	painter.drawLine(ptUp_leftLine,ptDown_leftLine);
	painter.drawLine(ptUp_rigthLine,ptDown_rigthLine);
	painter.drawLine(ptLeft_centerLine,ptRight_centerLine);

	QPointF scaleTextPos((ptUp_leftLine.x() + ptUp_rigthLine.x())/ 2,
		(ptUp_leftLine.y() + ptUp_rigthLine.y()) / 2);

	Ogre::String coorInfo = QString::number(realDis,'g',2).toLocal8Bit().constData();
	coorInfo += "米";
	painter.drawText(scaleTextPos,QString(coorInfo.c_str()));


	painter.setPen(oldPen);

}
