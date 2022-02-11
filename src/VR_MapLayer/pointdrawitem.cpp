#include "vrmine/vr_maplayer/pointdrawitem.h"
#include "vrmine/vr_geometry/geometry/point.h"
#include "vrmine/vr_style/style/pointstyle.h"
#include "vrmine/vr_maplayer/linedrawitem.h"
#include "vrmine/vr_geometry/geometry/line.h"
#include "vrmine/vr_style/style/linestyle.h"

using namespace VirtualMine::Style;
using namespace VirtualMine::Geometry;

namespace VirtualMine
{
	namespace Map
	{
		CPointDrawItem::CPointDrawItem()
		{
			this->mpGeometry = new VirtualMine::Geometry::CPoint();
			this->mpStyle = new VirtualMine::Style::CPointStyle();

		}

		CPointDrawItem::~CPointDrawItem()
		{

		}


		bool CPointDrawItem::pointSelect(const QPointF& mousePrjPos,const double& tolerance)
		{
#if 0
			bool r = false;
			if (this->getVisible())
			{
				CLine* pLine = (CLine*)this->mpGeometry;
				if (pLine && pLine->getCount() > 1)
				{
					Ogre::Vector2 mousePos(mousePrjPos.x(),mousePrjPos.y());
					for (int i = 0; i < pLine->getCount(); ++i)
					{
						Ogre::Vector2 ptPos(pLine->getPoint(i).getX(),
							pLine->getPoint(i).getY());
						double dis = mousePos.distance(ptPos);
						if (dis <= tolerance)
						{
							CHighLightEvent evt;
							evt.setDrawObject(this);
							break;
						}
					}
				}
			}

			return r;
#endif

			bool r = false;
			if (this->getVisible())
			{
				CPoint* pPoint = (CPoint*)this->mpGeometry;			
				if (pPoint)
				{
					Ogre::Vector2 mousePos(mousePrjPos.x(),mousePrjPos.y());			
						Ogre::Vector2 ptPos(pPoint->getX(),pPoint->getY());
						double dis = mousePos.distance(ptPos);
						if (dis <= tolerance)
						{
							CHighLightEvent evt;
							evt.setDrawObject(this);		
						}
				}
			
			}

			return r;

		}


		bool CPointDrawItem::draw(QPainter& painter,
			const int& viewWidth,const int& viewHeight,
			const QPointF& viewLeftTopPosition,
			const QPointF& viewRightBottomPosition,
			const float& curScale)
		{
			bool r = false;
			if (this->getVisible())
			{
				CPoint* pPoint = (CPoint*)this->mpGeometry;
				painter.setRenderHint(QPainter::Antialiasing,true);//反走样函数
				if (pPoint )
				{
					//curScale（每个像素代表的实际长度）
					CPointStyle* pStyle = (CPointStyle*)this->mpStyle;
					QPen pen(QColor(pStyle->getColor().r * 255,
						pStyle->getColor().g * 255,
						pStyle->getColor().b * 255,
						pStyle->getColor().a * 255),10,Qt::SolidLine,Qt::RoundCap);
					//pen.setWidth(pStyle->getWidth());
					QPen oldPen = painter.pen();
					painter.setPen(pen);
					QPointF pQPoints;
					pQPoints=QPointF(pPoint->getX(),pPoint->getY());
					pQPoints=pQPoints-viewLeftTopPosition;
					pQPoints.setY(pQPoints.ry()*(-1));
					pQPoints=pQPoints/curScale;				
					painter.drawPoint(pQPoints);
					painter.setPen(oldPen);
					r = true;
				}
			}
			return r;
		}

	}}