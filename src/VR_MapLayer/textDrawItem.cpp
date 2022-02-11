#include "vrmine/vr_maplayer/pointdrawitem.h"
#include "vrmine/vr_geometry/geometry/point.h"
#include "vrmine/vr_style/style/pointstyle.h"
#include "vrmine/vr_maplayer/linedrawitem.h"
#include "vrmine/vr_geometry/geometry/line.h"
#include "vrmine/vr_style/style/linestyle.h"
#include "vrmine/vr_maplayer/textDrawItem.h"
using namespace VirtualMine::Style;
using namespace VirtualMine::Geometry;

namespace VirtualMine
{
	namespace Map
	{
		CTextDrawItem::CTextDrawItem()
		{
			this->mpGeometry = new VirtualMine::Geometry::CLine();
			this->mpStyle = new VirtualMine::Style::CLineStyle();

		}

		CTextDrawItem::~CTextDrawItem()
		{

		}

		bool CTextDrawItem::draw(QPainter& painter,
			const int& viewWidth,const int& viewHeight,
			const QPointF& viewLeftTopPosition,
			const QPointF& viewRightBottomPosition,
			const float& curScale)
		{
			bool r = false;
			if (this->getVisible())
		{
			CLine* pLine = (CLine*)this->mpGeometry;
			painter.setRenderHint(QPainter::Antialiasing,true);
			if (pLine && pLine->getCount() > 1)
			{
				//pLine->
				//curScale（每个像素代表的实际长度）
				CLineStyle* pStyle = (CLineStyle*)this->mpStyle;
				QPen pen(QColor(pStyle->getColor().r * 255,
					pStyle->getColor().g * 255,
					pStyle->getColor().b * 255,
					pStyle->getColor().a * 255),10,Qt::SolidLine,Qt::RoundCap);
				//pen.setWidth(pStyle->getWidth());
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
					//painter.drawPoint(pQPoints[i]);
				}
				for (size_t i=0;i<pLine->getCount();++i)
			{
					QPointF* f = new QPointF[1];
					CPoint p = pLine->getPoint(i);
					f[0]= QPointF(p.getX(),p.getY());
					f[0] = f[0]- viewLeftTopPosition;
					f[0].setY(f[0].y() * -1);
					f[0] = f[0] / curScale;

					if (p.getX()>0)
					{
						QRect rect(f[0].rx()+15,f[0].ry()-15,15,15);
					
						QFont font("Arial",11);
						painter.setFont(font);
					   	int text=pLine->getPointID(i);
						
							QString mark=QString::number(text,10);
							//painter.setPen(QPen(QColor(0,0,255,255)));
							painter.drawText(rect,Qt::AlignHCenter | Qt::AlignTop,mark);	
						
						
					}else if(p.getX()<0){
						QRect rect(f[0].rx()-30,f[0].ry()-15,15,15);
					
						QFont font("Arial",11);
						painter.setFont(font);
						int text=pLine->getPointID(i);
							QString mark=QString::number(text,10);												
							painter.drawText(rect,Qt::AlignHCenter | Qt::AlignTop,mark);					
					}else{
						QRect rect(f[0].rx()-15,f[0].ry()-15,15,15);

						QFont font("Arial",11);
						painter.setFont(font);
						int text=pLine->getPointID(i);
						QString mark=QString::number(text,10);												
						painter.drawText(rect,Qt::AlignHCenter | Qt::AlignTop,mark);	
					}
					
				}
				painter.setPen(oldPen);
				r = true;
			 }
			}
			return r;
		}

		void CTextDrawItem::setType( const int& type )
		{
			this->mtype=type;
		}

		int CTextDrawItem::getType()
		{
			return this->mtype;
		}

	}}