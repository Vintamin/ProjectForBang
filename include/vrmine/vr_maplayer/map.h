//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 二三维爆破信息仿真系统
//  @ File Name : cmap.h
//  @ Date : 2015/8/1
//  @ Author : 
//
//



#if !defined(_CMAP_H)
#define _CMAP_H

#include "vrmine/vr_maplayer/idrawobject.h"
#include "vrmine/vr_maplayer/map2dlayer.h"
#include "vrmine/vr_core/geodatatype.h"

namespace VirtualMine
{
	namespace Map
	{
		class VR_MAPLAYER_EXPORT CMap : public IDrawObject,public ISelectObject,public CVisibleObject
		{
		public:
			CMap();
			virtual ~CMap();
			CMap2DLayer* addLayer(const std::string& type);
			void removeLayer(const std::string& layerName);
			CMap2DLayer* getLayer(const std::string& layerName); 
			std::vector<CMap2DLayer*> getLayers();
			virtual void setBoundingBox(const Ogre::AxisAlignedBox& boundingBox);
			virtual Ogre::AxisAlignedBox& getBoundingBox();
			virtual void computeBoundingBox();
			virtual bool draw(QPainter& painter,
				const int& viewWidth,const int& viewHeight,
				const QPointF& viewLeftTopPosition,
				const QPointF& viewRightBottomPosition,
				const float& curScale);
			virtual QPixmap& getMapImage();
			virtual std::string getName();
			virtual void setName(const std::string& name);
			virtual bool pointSelect(const QPointF& mousePrjPos,const double& tolerance);
		protected:
			std::string mName;
			std::vector<CMap2DLayer*> mLayers;
			Ogre::AxisAlignedBox mBoundingBox;
			QPixmap mMapImage;
		};
	}
}

#endif  //_CMAP_H
