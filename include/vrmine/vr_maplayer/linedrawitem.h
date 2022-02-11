//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ����ά������Ϣ����ϵͳ
//  @ File Name : clinedrawitem.h
//  @ Date : 2015/8/1
//  @ Author : 
//
//



#if !defined(_CLINEDRAWITEM_H)
#define _CLINEDRAWITEM_H

#include "igeometrydrawitem.h"
#include "vrmine/vr_maplayer/shapeitem.h"

namespace VirtualMine
{
	namespace Map
	{
		class VR_MAPLAYER_EXPORT CLineDrawItem : public CShapeItem 
		{
		public:
			CLineDrawItem();
			virtual ~CLineDrawItem();
			virtual bool draw(QPainter& painter,
				const int& viewWidth,const int& viewHeight,
				const QPointF& viewLeftTopPosition,
				const QPointF& viewRightBottomPosition,
				const float& curScale);
			void setType(const int& type);
			int getType();
		private:
			int mType;
		};

		class VR_MAPLAYER_EXPORT CPipeLineDrawItem : public CLineDrawItem 
		{
		public:
			CPipeLineDrawItem();
			virtual ~CPipeLineDrawItem();
		    void setType(const int& type);
			int getType();
		private:
		    int mType;///
		};

	}}
#endif  //_CLINEDRAWITEM_H