#include "vrmine/vr_maplayer/rocklayer2D.h"
#include "vrmine/vr_core/geodatatype.h"
#include "bang/shotholefeature.h"

#include "vrmine/vr_databaseengine/database/ifeature.h"
#include "bang/rocklayerfeature.h"
#include "vrmine/vr_spatialinterface/igeoobject.h"
#include <list>
#include "vrmine/vr_utility/objecttransformer.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_spatialrender/lanewaypiperender/pipeline.h"
#include "String"
#include "ogre/Ogre.h"
#include "OGRE/OgreStringConverter.h"
#include "vrmine/vr_style/style/pointstyle.h"
using namespace VirtualMine::Database;
using namespace VirtualMine::Base;
using namespace VirtualMine::BaseRender;
using namespace VirtualMine::Map;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Bang_Database;

CRockLayer2DFactory::CRockLayer2DFactory()
{

	
}

CRockLayer2DFactory::~CRockLayer2DFactory()
{

}

VirtualMine::SpatialInterface::ILayer* CRockLayer2DFactory::createInstance( const std::string& name )
{
	ILayer* pLayer = new CRockLayer2D();
	pLayer->setName(name);
	return pLayer;
}

void CRockLayer2DFactory::destroyInstance( VirtualMine::SpatialInterface::ILayer* pLayer )
{
	SAFE_DELETE(pLayer);
}

std::string CRockLayer2DFactory::getType()
{
	return VirtualMine::Core::GeoDataType::GDT_2DROCKLAYER;
}

VirtualMine::Map::CRockLayer2D::CRockLayer2D()
{

}

VirtualMine::Map::CRockLayer2D::~CRockLayer2D()
{

}

void VirtualMine::Map::CRockLayer2D::initialise()
{

	/*CLine2D* pSandstone=new CLine2D();
	CLine2D* pLimestone=new CLine2D();
	Ogre::Vector3 p1,p2;
	p1.x=-5.5;
	p1.y=5.2;
	p1.z=0;
	p2.x=5.5;
	p2.y=5.8;
	p2.z=0;
	pSandstone->addPoint(p1.x,p1.y,p1.z);
	pSandstone->addPoint(p2.x,p2.y,p2.z);
	std::string name1="砂岩";
	pSandstone->setLineName(name1);
	drawRenderLine(pSandstone,Ogre::ColourValue::Red,true);

	Ogre::Vector3 p3,p4;
	p3.x=-5.5;
	p3.y=-5.8;
	p3.z=0;
	p4.x=5,5;
	p4.y=-5.2;
	p4.z=0;
	std::string name2="灰岩";
	pLimestone->setLineName(name2);
	pLimestone->addPoint(p3.x,p3.y,p3.z);
	pLimestone->addPoint(p4.x,p4.y,p4.z);
	drawRenderLine(pLimestone,Ogre::ColourValue::Red,true)*/;
}

void VirtualMine::Map::CRockLayer2D::drawRockLayer()
{

}

void VirtualMine::Map::CRockLayer2D::computeBoundingBox()
{
	//if (NULL == this->ref_mpDataSet)
	//	return;

	//int featureCount = this->ref_mpDataSet->getCount();//需要数据库引擎提供接口
	//for (int i = 0 ; i < featureCount; ++i)
	//{
	//	IFeature* pFeature = this->ref_mpDataSet->getFeature(i);
	//	CRockLayerFeature* rocklayerFeature = dynamic_cast<CRockLayerFeature*>(pFeature);
	//	Ogre::Vector3 p(rocklayerFeature->getFieldPositionX(),
	//		rocklayerFeature->getFieldPositionY(),
	//		rocklayerFeature->getFieldPositionZ());
	//	this->mBoundingBox.merge(p);

	//}
}

//绘制点
void CRockLayer2D::drawRenderPoint(VirtualMine::Map::CPoint2D* pPoint,Ogre::ColourValue renderColor,const bool& visible)
{

	CPointDrawItem* pPointItem =  ( CPointDrawItem*)this->addGeometryItem(IGeometryDrawItem::EGIT_POINT);
	pPointItem->setName(QString::number(pPoint->getID(),10).toStdString());
	pPointItem->setVisible(visible);
	//设置geometry
	VirtualMine::Geometry::CPoint* pGeometry = (VirtualMine::Geometry::CPoint*)pPointItem->getGeometry();	
	pGeometry->setX(pPoint->getX());
	pGeometry->setY(pPoint->getY());
	pGeometry->setZ(pPoint->getZ());
	Ogre::Vector3  pos;
	pos.x=pPoint->getX();
	pos.y=pPoint->getY();
	pos.z=pPoint->getZ();
	box.merge(pos);

	//设置风格
	VirtualMine::Style::CPointStyle* pStyle = (VirtualMine::Style::CPointStyle*)pPointItem->getStyle();
	pStyle->setColor(renderColor);
}
//绘制线
void CRockLayer2D::drawRenderLine(VirtualMine::Map::CLine2D* pLine,Ogre::ColourValue renderColor,const bool& visible  )
{
	CLineDrawItem* pLineItem = (CLineDrawItem*)this->addGeometryItem(IGeometryDrawItem::EGIT_LINE);
	pLineItem->setVisible(visible);
	pLineItem->setName(pLine->getName());

	//设置geometry
	VirtualMine::Geometry::CLine* pGeometry = (VirtualMine::Geometry::CLine*)pLineItem->getGeometry();
	for (int i=0;i<pLine->getCount();++i)
	{
		Ogre::Vector3 pos;
		pos.x	= pLine->getPoint(i).getX();
		pos.y	= pLine->getPoint(i).getY();
		pos.z	= pLine->getPoint(i).getZ();
		pGeometry->addPoint(pos.x,pos.y,pos.z);
		mBoundingBox.merge(pos);
	}

	//设置风格
	VirtualMine::Style::CLineStyle* pStyle = (VirtualMine::Style::CLineStyle*)pLineItem->getStyle();
	pStyle->setWidth(4);
	pStyle->setColor(renderColor);
}