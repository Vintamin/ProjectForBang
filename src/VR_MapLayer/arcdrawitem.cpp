#include "vrmine/vr_maplayer/arcdrawitem.h"
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
		CArcDrawItem::CArcDrawItem()
		{
			this->mpGeometry = new VirtualMine::Geometry::CLine();
			this->mpStyle = new VirtualMine::Style::CLineStyle();			
		}

        CArcDrawItem::~CArcDrawItem()
		{

		}
		bool CArcDrawItem::draw(QPainter& painter,
			const int& viewWidth,const int& viewHeight,
			const QPointF& viewLeftTopPosition,
			const QPointF& viewRightBottomPosition,
			const float& curScale)
		{
			bool r = false;
			if (this->getVisible())
			{
				CLine* pLine = (CLine*)this->mpGeometry;
				if (pLine && pLine->getCount() > 1)
				{
					//curScale（每个像素代表的实际长度）
					CLineStyle* pStyle = (CLineStyle*)this->mpStyle;
					QPen pen(QColor(pStyle->getColor().r * 255,
						pStyle->getColor().g * 255,
						pStyle->getColor().b * 255,
						pStyle->getColor().a * 255));
					pen.setWidth(pStyle->getWidth());
					QPen oldPen = painter.pen();
					painter.setPen(pen);
					QPointF* pQPoints = new QPointF[pLine->getCount()];
					for (size_t i = 0; i < pLine->getCount();++i)
					{
						CPoint p = pLine->getPoint(i);
						pQPoints[i] = QPointF(p.getX(),p.getY());
						pQPoints[i] = pQPoints[i] - viewLeftTopPosition;
						pQPoints[i].setY(pQPoints[i].y() * -1);
						pQPoints[i] = pQPoints[i] / curScale;
						//painter.drawLine(pQPoints[0].x(),pQPoints[0].x(),2*pQPoints[0].x(),2*pQPoints[0].x());

					}
					painter.drawArc(pQPoints[0].x(),pQPoints[0].x(),2*pQPoints[0].x(),2*pQPoints[0].x(),0,180);
					painter.setPen(oldPen);
					r = true;
				}
			}

			return r;
		}
	}}