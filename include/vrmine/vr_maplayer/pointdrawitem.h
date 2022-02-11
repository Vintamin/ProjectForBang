//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 二三维爆破信息仿真系统
//  @ File Name : cpointdrawitem.h
//  @ Date : 2015/8/1
//  @ Author : 
//
//

#if !defined(_CPOINTDRAWITEM_H)
#define _CPOINTDRAWITEM_H

#include "igeometrydrawitem.h"
#include "vrmine/vr_maplayer/shapeitem.h"

namespace VirtualMine
{
	namespace Map
	{
		class VR_MAPLAYER_EXPORT CPointDrawItem : public CShapeItem {
			
			public:
				CPointDrawItem();
				virtual ~CPointDrawItem();
				bool CPointDrawItem::pointSelect(const QPointF& mousePrjPos,const double& tolerance);
				virtual bool draw(QPainter& painter,
					const int& viewWidth,const int& viewHeight,
					const QPointF& viewLeftTopPosition,
					const QPointF& viewRightBottomPosition,
					const float& curScale);
		};
	}}
#endif  //_CPOINTDRAWITEM_H
