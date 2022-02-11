#include "vrmine/vr_maplayer/linedrawitem.h"
#include "vrmine/vr_geometry/geometry/line.h"
#include "vrmine/vr_maplayer/line2D.h"
#include "vrmine/vr_style/style/linestyle.h"

using namespace VirtualMine::Style;
using namespace VirtualMine::Geometry;

namespace VirtualMine
{
	namespace Map
	{
		CLineDrawItem::CLineDrawItem()
		{
			this->mpGeometry = new VirtualMine::Geometry::CLine();
			this->mpStyle = new VirtualMine::Style::CLineStyle();
		
		}

		CLineDrawItem::~CLineDrawItem()
		{

		}

		bool CLineDrawItem::draw(QPainter& painter,
			const int& viewWidth,const int& viewHeight,
			const QPointF& viewLeftTopPosition,
			const QPointF& viewRightBottomPosition,
			const float& curScale)
		{
			//cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!触发了CLineDrawItem事件"<<endl;
			bool r = false;
			if (this->getVisible())
			{
				CLine2D* pLine = (CLine2D*)this->mpGeometry;
				painter.setRenderHint(QPainter::Antialiasing,true);
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

					}
					painter.drawPolyline(pQPoints,pLine->getCount());
					painter.setPen(oldPen);
					r = true;
				}
			}
			
			return r;
		}

		void CLineDrawItem::setType( const int& type )
		{
			this->mType=type;
		}

		int CLineDrawItem::getType()
		{
			return this->mType;
		}

		CPipeLineDrawItem::CPipeLineDrawItem()
		{

		}

		CPipeLineDrawItem::~CPipeLineDrawItem()
		{

		}

		void CPipeLineDrawItem::setType( const int& type )
		{
			this->mType = type;
		}

		int CPipeLineDrawItem::getType()
		{
			return this->mType;
		}

	}}