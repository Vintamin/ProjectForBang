
#include "vrmine/vr_maplayer/shotholelayer.h"
#include "vrmine/vr_core/geodatatype.h"
#include "bang/shotholefeature.h"

#include "vrmine/vr_databaseengine/database/ifeature.h"
#include "vrmine/vr_spatialinterface/igeoobject.h"
#include <list>
#include "vrmine/vr_utility/objecttransformer.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_spatialrender/lanewaypiperender/pipeline.h"
#include "String"
#include "ogre/Ogre.h"
#include "OGRE/OgreStringConverter.h"
#include "qmath.h"
#include "vrmine/vr_style/style/pointstyle.h"

using namespace VirtualMine::Database;
using namespace VirtualMine::Base;
using namespace VirtualMine::BaseRender;
using namespace VirtualMine::Map;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Bang_Database;
class CBoreHole2D;

const double PI=3.1415926;
C2DShotHoleLayerFactory::C2DShotHoleLayerFactory()
{

}

C2DShotHoleLayerFactory::~C2DShotHoleLayerFactory()
{

}

VirtualMine::SpatialInterface::ILayer* C2DShotHoleLayerFactory::createInstance( const std::string& name )
{
	ILayer* pLayer = new C2DShotHoleLayer();
	pLayer->setName(name);
	return pLayer;
}

void C2DShotHoleLayerFactory::destroyInstance( VirtualMine::SpatialInterface::ILayer* pLayer )
{
	SAFE_DELETE(pLayer);
}

std::string C2DShotHoleLayerFactory::getType()
{
	return VirtualMine::Core::GeoDataType::GDT_2DSHOTHOLE;
}

C2DShotHoleLayer::C2DShotHoleLayer()
{
	this->mType = VirtualMine::Core::GeoDataType::GDT_2DSHOTHOLE;
	//kk
	this->setName("shothole");
	box.setNull();
}

C2DShotHoleLayer::~C2DShotHoleLayer()
{

}

//kk获取mAllVector
vector<VirtualMine::Map::CBoreHole2D> C2DShotHoleLayer::getmAllVector()
{
	return this->mAllVector;
}
void C2DShotHoleLayer::initialise()
 {
	initialData();
	holeTypeSort();
	orderTypeSort();
	//kk正视图的炮眼
	drawAllHole();

	//kk左视图
	drawLeftView();
	//kk俯视图
	drawOverView();
	drawMark(mAllVector,Ogre::ColourValue::Blue);
	//kk起爆顺序标记
	drawBoomOrderMark();
	//drawOutFrame();
	//kk起爆顺序
	drawBoomOrder();
}
//计算封孔位置，水泥位置坐标
Ogre::Vector3 C2DShotHoleLayer::getmidCor( Ogre::Vector3 &st,Ogre::Vector3 &ed,double disz )
{
	Ogre::Vector3 p;
	if (ed.z-st.z!=0)
	{
		double scale=disz/(ed.z-st.z);
		double x=scale*(ed.x-st.x)+st.x;
		double y=scale*(ed.y-st.y)+st.y;
		double z=disz;

		
		p.x=x;
		p.y=y;
		p.z=z;
	}
	return p;
}
//绘制点
void C2DShotHoleLayer::drawRenderPoint(VirtualMine::Map::CPoint2D* pPoint,Ogre::ColourValue renderColor,const bool& visible)
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
//绘制内部线
void C2DShotHoleLayer::drawRenderLine(VirtualMine::Map::CLine2D* pLine,Ogre::ColourValue renderColor,const bool& visible  )
{
	CLineDrawItem* pLineItem = (CLineDrawItem*)this->addGeometryItem(IGeometryDrawItem::EGIT_LINE);
	pLineItem->setVisible(visible);
	pLineItem->setName(pLine->getName());
    pLineItem->setType(pLine->getType());
	//设置geometry
	VirtualMine::Geometry::CLine* pGeometry = (VirtualMine::Geometry::CLine*)pLineItem->getGeometry();
	for (int i=0;i<pLine->getCount();++i)
	{
		Ogre::Vector3 pos;
		pos.x	= pLine->getPoint(i).getX();
		pos.y	= pLine->getPoint(i).getY();
		pos.z	= pLine->getPoint(i).getZ();
		pGeometry->addPoint(pos.x,pos.y,pos.z);
		box.merge(pos);
	}

	//设置风格
	VirtualMine::Style::CLineStyle* pStyle = (VirtualMine::Style::CLineStyle*)pLineItem->getStyle();
	pStyle->setWidth(2);
	pStyle->setColor(renderColor);
}
//计算包围盒
void C2DShotHoleLayer::computeBoundingBox()
{
	if (NULL == this->ref_mpDataSet)
		return;

	int featureCount = this->ref_mpDataSet->getCount();//需要数据库引擎提供接口
	for (int i = 0 ; i < featureCount; ++i)
	{
		IFeature* pFeature = this->ref_mpDataSet->getFeature(i);
		CShotHoleFeature* shotholeFeature = dynamic_cast<CShotHoleFeature*>(pFeature);
		Ogre::Vector3 p(shotholeFeature->getFieldPositionX(),
			shotholeFeature->getFieldPositionY(),
			shotholeFeature->getFieldPositionZ());
		this->mBoundingBox.merge(p);

	}
}
//绘制左视图
void VirtualMine::Map::C2DShotHoleLayer::drawLeftView()
{
	//左视图 三段
	if (this->mtypeVector.size() > 0)
	{
		std::map<std::string,std::vector<CBoreHole2D>>::iterator bItr = this->mtypeVector.begin();
		std::map<std::string,std::vector<CBoreHole2D>>::iterator eItr = this->mtypeVector.end();
		double xtranslate=2*(*bItr).second.front().mposEnd.z;
		double xleftfirstCor=(*bItr).second.back().mposStart.x+xtranslate;
		while (bItr != eItr)
		{
			
			Ogre::Vector3 pfront;
			pfront.x	= xleftfirstCor;
			pfront.y	= (*bItr).second.front().mposStart.y;
			pfront.z	= (*bItr).second.front().mposStart.z;

			Ogre::Vector3 pfront2;
			pfront2.x	=xleftfirstCor-(*bItr).second.front().msealCor.z;
			pfront2.y	= (*bItr).second.front().msealCor.y;
			pfront2.z	= (*bItr).second.front().mposEnd.z;

			Ogre::Vector3 pfront3;
			pfront3.x	=xleftfirstCor-(*bItr).second.front().mmudCor.z;
			pfront3.y	= (*bItr).second.front().mmudCor.y;
			pfront3.z	= (*bItr).second.front().mposEnd.z;

			Ogre::Vector3 pfront4;
			pfront4.x	=xleftfirstCor-(*bItr).second.front().mposEnd.z;
			pfront4.y	= (*bItr).second.front().mposEnd.y;
			pfront4.z	= (*bItr).second.front().mposEnd.z;

			//左视图item不要名字
			CLine2D* firstfront=new CLine2D();
			CLine2D* secondfront=new CLine2D();
			CLine2D* thirdfront=new CLine2D();
			std::string frontfirstname="left"+(*bItr).second.front().mboomType.toStdString()+"frontfirstline";
			std::string frontsecondname="left"+(*bItr).second.front().mboomType.toStdString()+"frontsecondline";
			std::string frontthirdname="left"+(*bItr).second.front().mboomType.toStdString()+"frontthirdline";

			firstfront->setLineName(frontfirstname);
			secondfront->setLineName(frontsecondname);
			thirdfront->setLineName(frontthirdname);
			firstfront->setType(0);
			secondfront->setType(0);
			thirdfront->setType(0);
			firstfront->addPoint(pfront.x,pfront.y,pfront.z);
			firstfront->addPoint(pfront2.x,pfront2.y,pfront2.z);
            secondfront->addPoint(pfront2.x,pfront2.y,pfront2.z);
			secondfront->addPoint(pfront3.x,pfront3.y,pfront3.z);
			thirdfront->addPoint(pfront3.x,pfront3.y,pfront3.z);
			thirdfront->addPoint(pfront4.x,pfront4.y,pfront4.z);
			//kk盒子问题入口
			/*Ogre::Vector3 pleftextend;
			pleftextend.x=pfront.x*1.1;
			pleftextend.y=pfront.y*1.1;
			this->mBoundingBox.merge(pleftextend);*/

			
			drawRenderLine(firstfront,Ogre::ColourValue(0.3,0.2,0.1),true);
			drawRenderLine(secondfront,Ogre::ColourValue(0.1,0.8,0.8),true);
			drawRenderLine(thirdfront,Ogre::ColourValue(0.8,0.8,0.1),true);

		
			CLine2D* firstmid=new CLine2D();
			CLine2D* secondmid=new CLine2D();
			CLine2D* thirdmid=new CLine2D();

			int mid=(*bItr).second.size()/2+0.5;
			Ogre::Vector3 pmid;
			pmid.x	= xleftfirstCor;
			pmid.y	= (*bItr).second.at(mid).mposStart.y;
			pmid.z	= (*bItr).second.at(mid).mposStart.z;

			Ogre::Vector3 pmid2;
			pmid2.x	=xleftfirstCor-(*bItr).second.front().msealCor.z;
			pmid2.y	= (*bItr).second.at(mid).msealCor.y;
			pmid2.z	= (*bItr).second.at(mid).mposEnd.z;

			Ogre::Vector3 pmid3;
			pmid3.x	= xleftfirstCor-(*bItr).second.front().mmudCor.z;
			pmid3.y	= (*bItr).second.at(mid).mmudCor.y;
			pmid3.z	= (*bItr).second.at(mid).mmudCor.z;

			Ogre::Vector3 pmid4;
			pmid4.x	=xleftfirstCor-(*bItr).second.front().mposEnd.z;
			pmid4.y	= (*bItr).second.at(mid).mposEnd.y;
			pmid4.z	= (*bItr).second.at(mid).mposEnd.z;


			std::string midfirstname="left"+(*bItr).second.front().mboomType.toStdString()+"midfirstline";
			std::string midsecondname="left"+(*bItr).second.front().mboomType.toStdString()+"midsecondline";
			std::string midthirdname="left"+(*bItr).second.front().mboomType.toStdString()+"midthirdline";
			firstmid->setLineName(midfirstname);
			secondmid->setLineName(midsecondname);
			thirdmid->setLineName(midthirdname);
			firstmid->setType(0);
			secondmid->setType(0);
			thirdmid->setType(0);
			firstmid->addPoint(pmid.x,pmid.y,pmid.z);
			firstmid->addPoint(pmid2.x,pmid2.y,pmid2.z);
			secondmid->addPoint(pmid2.x,pmid2.y,pmid2.z);
			secondmid->addPoint(pmid3.x,pmid3.y,pmid3.z);
			thirdmid->addPoint(pmid3.x,pmid3.y,pmid3.z);
			thirdmid->addPoint(pmid4.x,pmid4.y,pmid4.z);
			this->mBoundingBox.merge(pmid);

			drawRenderLine(firstmid,Ogre::ColourValue(0.3,0.2,0.1),true);
			drawRenderLine(secondmid,Ogre::ColourValue(0.1,0.8,0.8),true);
			drawRenderLine(thirdmid,Ogre::ColourValue(0.8,0.8,0.1),true);

			++bItr;
		}

	}	

}
//绘制俯视图
void VirtualMine::Map::C2DShotHoleLayer::drawOverView()
{	
	//俯视图 三段

	if (this->mtypeVector.size() > 0)
	{
		std::map<std::string,std::vector<CBoreHole2D>>::iterator bItr = this->mtypeVector.begin();
		std::map<std::string,std::vector<CBoreHole2D>>::iterator eItr = this->mtypeVector.end();
		double ytranslate=2*(*bItr).second.front().mposEnd.z;
		double yoverfirstCor=(*bItr).second.back().mposStart.y-ytranslate;
		while (bItr != eItr)
		{
			CLine2D* firstfront=new CLine2D();
			CLine2D* secondfront=new CLine2D();
			CLine2D* thirdfront=new CLine2D();

			Ogre::Vector3 pfront;
			pfront.x	= (*bItr).second.front().mposStart.x;
			pfront.y	= yoverfirstCor;
			pfront.z	= (*bItr).second.front().mposStart.z;

			Ogre::Vector3 pfront2;
			pfront2.x	=(*bItr).second.front().mposStart.x;
			pfront2.y	=yoverfirstCor+(*bItr).second.front().msealCor.z;
			pfront2.z	= (*bItr).second.front().msealCor.z;

			Ogre::Vector3 pfront3;
			pfront3.x	=(*bItr).second.front().mposStart.x;
			pfront3.y	= yoverfirstCor+(*bItr).second.front().mmudCor.z;
			pfront3.z	= (*bItr).second.front().mmudCor.z;

			Ogre::Vector3 pfront4;
			pfront4.x	=(*bItr).second.front().mposStart.x;
			pfront4.y	= yoverfirstCor+(*bItr).second.front().mposEnd.z;
			pfront4.z	= (*bItr).second.front().mposEnd.z;


			std::string frontfirstname="over"+(*bItr).second.front().mboomType.toStdString()+"frontfirstline";
			std::string frontsecondname="over"+(*bItr).second.front().mboomType.toStdString()+"frontsecondline";
			std::string frontthirdname="over"+(*bItr).second.front().mboomType.toStdString()+"frontthirdline";
			firstfront->setLineName(frontfirstname);
			secondfront->setLineName(frontsecondname);
			thirdfront->setLineName(frontthirdname);
			firstfront->setType(0);
			secondfront->setType(0);
			thirdfront->setType(0);
			firstfront->addPoint(pfront.x,pfront.y,pfront.z);
			firstfront->addPoint(pfront2.x,pfront2.y,pfront2.z);
			secondfront->addPoint(pfront2.x,pfront2.y,pfront2.z);
			secondfront->addPoint(pfront3.x,pfront3.y,pfront3.z);
			thirdfront->addPoint(pfront3.x,pfront3.y,pfront3.z);
			thirdfront->addPoint(pfront4.x,pfront4.y,pfront4.z);
			
			//kk盒子问题入口
			/*Ogre::Vector3 poverxtend;
			
			poverxtend.x=pfront.x*1.3;
			poverxtend.y=pfront.y*1.1;
			this->mBoundingBox.merge(poverxtend);*/

			drawRenderLine(firstfront,Ogre::ColourValue(0.3,0.2,0.1),true);
			drawRenderLine(secondfront,Ogre::ColourValue(0.1,0.8,0.8),true);
			drawRenderLine(thirdfront,Ogre::ColourValue(0.8,0.8,0.1),true);

			CLine2D* firstback=new CLine2D();
			CLine2D* secondback=new CLine2D();
			CLine2D* thirdback=new CLine2D();

			Ogre::Vector3 pback;
			pback.x	= (*bItr).second.back().mposStart.x;
			pback.y	= yoverfirstCor;
			pback.z	= (*bItr).second.back().mposStart.z;

			Ogre::Vector3 pback2;
			pback2.x	=(*bItr).second.back().mposStart.x;
			pback2.y	=yoverfirstCor+(*bItr).second.front().msealCor.z;
			pback2.z	= (*bItr).second.back().msealCor.z;

			Ogre::Vector3 pback3;
			pback3.x	=(*bItr).second.back().mposStart.x;
			pback3.y	= yoverfirstCor+(*bItr).second.front().mmudCor.z;
			pback3.z	= (*bItr).second.back().mmudCor.z;

			Ogre::Vector3 pback4;
			pback4.x	=(*bItr).second.back().mposStart.x;
			pback4.y	= yoverfirstCor+(*bItr).second.front().mposEnd.z;
			pback4.z	= (*bItr).second.back().mposEnd.z;

			std::string backfirstname="over"+(*bItr).second.front().mboomType.toStdString()+"backfirstline";
			std::string backsecondname="over"+(*bItr).second.front().mboomType.toStdString()+"backsecondline";
			std::string backthirdname="over"+(*bItr).second.front().mboomType.toStdString()+"backthirdline";
			firstback->setLineName(backfirstname);
			secondback->setLineName(backsecondname);
			thirdback->setLineName(backthirdname);
			firstback->setType(0);
			secondback->setType(0);
			thirdback->setType(0);
			firstback->addPoint(pback.x,pback.y,pback.z);
			firstback->addPoint(pback2.x,pback2.y,pback2.z);
			secondback->addPoint(pback2.x,pback2.y,pback2.z);
			secondback->addPoint(pback3.x,pback3.y,pback3.z);
			thirdback->addPoint(pback3.x,pback3.y,pback3.z);
			thirdback->addPoint(pback4.x,pback4.y,pback4.z);
			
			drawRenderLine(firstback,Ogre::ColourValue(0.3,0.2,0.1),true);
			drawRenderLine(secondback,Ogre::ColourValue(0.1,0.8,0.8),true);
			drawRenderLine(thirdback,Ogre::ColourValue(0.8,0.8,0.1),true);
			++bItr;
		}

	}	


}
//按炮眼类型分类
void VirtualMine::Map::C2DShotHoleLayer::holeTypeSort()
{
	for (int i=0;i<mAllVector.size();++i)
	{
		std::string type = mAllVector.at(i).mboomType.toLocal8Bit().constData();
		this->mtypeVector[type].push_back(mAllVector.at(i));
	}
}
//按起爆顺序分类
void VirtualMine::Map::C2DShotHoleLayer::orderTypeSort()
{
	for (int i=0;i<mAllVector.size();++i)
	{
		int type = mAllVector.at(i).mboomOrder;
		this->mOderVector[type].push_back(mAllVector.at(i));
	}
}
//绘制所有炮眼
void VirtualMine::Map::C2DShotHoleLayer::drawAllHole()
{
	if (this->mtypeVector.size() > 0)
	{
		std::map<std::string,std::vector<CBoreHole2D>>::iterator bItr = this->mtypeVector.begin();
		std::map<std::string,std::vector<CBoreHole2D>>::iterator eItr = this->mtypeVector.end();
	
		int count=this->mtypeVector.size();
		int change=1;
		float index=1.0/count;
		while (bItr != eItr)
		{
			

			std::vector<CBoreHole2D>::iterator sub_bItr = bItr->second.begin();
			std::vector<CBoreHole2D>::iterator sub_eItr = bItr->second.end();
			while (sub_bItr != sub_eItr)
			{
				CPoint2D* point=new CPoint2D();
				point->setID((*sub_bItr).mboomID);
			
			  point->setX((*sub_bItr).mposStart.x) ;
			  point->setY((*sub_bItr).mposStart.y) ;
			  point->setZ((*sub_bItr).mposStart.z) ;							
			  drawRenderPoint(point,Ogre::ColourValue(1.0-index*change/2,0.3+index*change/2,index*change/2,1.0),true);											
			  ++sub_bItr;			
			}
			++bItr;
			++change;
			
		}
			
	}
}
//绘制标注
void VirtualMine::Map::C2DShotHoleLayer::drawMark( std::vector<CBoreHole2D> &poVector,Ogre::ColourValue renderColor )
{

	CTextDrawItem* pTextItem =  ( CTextDrawItem*)this->addGeometryItem(IGeometryDrawItem::EGIT_TEXT);
	//设置geometry
	std::string name="MarkText";
	pTextItem->setVisible(true);
	pTextItem->setName(name);
	pTextItem->setType(0);
	VirtualMine::Geometry::CLine* pGeometry = (VirtualMine::Geometry::CLine*)pTextItem->getGeometry();
	for (int i=0;i<mAllVector.size();i+=3)
	{
		Ogre::Vector3 pos;
		pos.x	= poVector.at(i).mposStart.x;;
		pos.y	= poVector.at(i).mposStart.y;
		pos.z	= 0;
		pGeometry->addPointID(poVector.at(i).mboomID);
		pGeometry->addPoint(pos.x,pos.y,pos.z);
		box.merge(pos);

	}
	//设置风格
	VirtualMine::Style::CLineStyle* pStyle = (VirtualMine::Style::CLineStyle*)pTextItem->getStyle();
	pStyle->setColor(renderColor);
}
//绘制边框
void VirtualMine::Map::C2DShotHoleLayer::drawOutFrame( )
{
	
	CLineDrawItem* pLinetem =  ( CLineDrawItem*)this->addGeometryItem(IGeometryDrawItem::EGIT_LINE);
	//设置geometry
	pLinetem->setName("outFramItem");
	VirtualMine::Geometry::CLine* pGeometry = (VirtualMine::Geometry::CLine*)pLinetem->getGeometry();
	double extent=1.2;
	Ogre::Vector3 p;
	p.x=2.7*extent;
	p.y=0;
	p.z=0;
	pGeometry->addPoint(p.x,p.y,p.z);
	double interval=PI/180;
	int count=1;
	for (int i=0;i<30;++i)
	{
		Ogre::Vector3 pos;
		pos.x=2.7*cos(interval*count)*extent;
		pos.y=2.7*sin(interval*count)*extent;
		pos.z=0;
	    pGeometry->addPoint(pos.x,pos.y,pos.z);
		box.merge(pos);
		count+=6;
	}
	Ogre::Vector3 p2;
	p2.x=-2.7*extent;
	p2.y=-2.7*extent;
	p2.z=0;
	Ogre::Vector3 p3;
	p3.x=2.7*extent;
	p3.y=-2.7*extent;
	p3.z=0;
	pGeometry->addPoint(p2.x,p2.y,p2.z);
	pGeometry->addPoint(p3.x,p3.y,p3.z);
	pGeometry->addPoint(p.x,p.y,p.z);
	box.merge(p2);
	box.merge(p3);
	box.merge(p);
	VirtualMine::Style::CLineStyle* pStyle = (VirtualMine::Style::CLineStyle*)pLinetem->getStyle();
	pStyle->setColor(Ogre::ColourValue::Red);
}
//初始化数据
void VirtualMine::Map::C2DShotHoleLayer::initialData()
{

	if (NULL == this->ref_mpDataSet)
		return;
	int featureCount = this->ref_mpDataSet->getCount();//需要数据库引擎提供接

	//kk先判断是不是mAllVector中是不是有数据，如果有则清空（为了重新渲染）
	vector <CBoreHole2D>().swap(mAllVector);

	for (int i = 0 ; i < featureCount; ++i)
	{
		IFeature* pFeature = this->ref_mpDataSet->getFeature(i);
		VirtualMine::SpatialInterface::IGeoObject* pGeoObject = new VirtualMine::Base::CGeoLine();
		//pGeoObject->fromFeature(pFeature);
		CShotHoleFeature* shotholeFeature = dynamic_cast<CShotHoleFeature*>(pFeature);

		CBoreHole2D p2D;
		//存储ID
		p2D.mboomID=shotholeFeature->getFieldHoleID();
		p2D.mboomType=QString::fromStdString(shotholeFeature->getFieldType()) ;
		p2D.mboomOrder=shotholeFeature->getFieldBangOrder();

		p2D.mdynamitelength=shotholeFeature->getFieldZhuangyaoLength();
		p2D.mmudLength=shotholeFeature->getFieldShuipaoniLength();
		p2D.msealLenght=shotholeFeature->getFieldFengniLength();

		p2D.mposStart.x=shotholeFeature->getFieldPositionX();
		p2D.mposStart.y=shotholeFeature->getFieldPositionY();
		p2D.mposStart.z=shotholeFeature->getFieldPositionZ();

		Ogre::Vector3 p;
		p=p2D.mposStart;

		p2D.mposEnd.x =shotholeFeature->getFieldPositionEndX();
		p2D.mposEnd.y =shotholeFeature->getFieldPositionEndY();
		p2D.mposEnd.z =shotholeFeature->getFieldPositionEndZ();

		mAllVector.push_back(p2D);



	}

#pragma region 计算封孔、水泥坐标
	for (int i=0;i<mAllVector.size();++i)
	{
		Ogre::Vector3 p = getmidCor(mAllVector.at(i).mposStart,mAllVector.at(i).mposEnd,mAllVector.at(i).msealLenght);//msealLenght 是getFieldFengniLength（）
		mAllVector.at(i).msealCor=p;
	}
	for (int i=0;i<mAllVector.size();++i)
	{
		double lenght=mAllVector.at(i).msealLenght+mAllVector.at(i).mmudLength; //msealLenght 是getFieldFengniLength（）；mmudLength是getFieldShuipaoniLength（）
		Ogre::Vector3 p = getmidCor(mAllVector.at(i).mposStart,mAllVector.at(i).mposEnd,lenght);
		mAllVector.at(i).mmudCor=p;
	}
#pragma endregion
}
//绘制起爆顺序
void VirtualMine::Map::C2DShotHoleLayer::drawBoomOrder()
{
		if (this->mOderVector.size() > 0)
		{
			std::map<int,std::vector<CBoreHole2D>>::iterator bItr = this->mOderVector.begin();
			std::map<int,std::vector<CBoreHole2D>>::iterator eItr = this->mOderVector.end();

			int count=this->mOderVector.size();
			int change=1;		
			float index=1.0/count;
			while (bItr != eItr)
			{

				CLine2D* boomorderLine=new CLine2D();
				QString lineName="boomline"+QString::number((*bItr).first,10);
				boomorderLine->setLineName(lineName.toStdString());
				boomorderLine->setType(1);
				std::vector<CBoreHole2D>::iterator sub_bItr = bItr->second.begin();
				std::vector<CBoreHole2D>::iterator sub_eItr = bItr->second.end();
				while (sub_bItr != sub_eItr)
				{
				    Ogre::Vector3 p;
					p.x	= (*sub_bItr).mposStart.x;
					p.y	= (*sub_bItr).mposStart.y;
					p.z	= (*sub_bItr).mposStart.z;				
					boomorderLine->addPoint(p.x,p.y,p.z);			
					++sub_bItr;										 
				   }	
				 drawRenderLine(boomorderLine,Ogre::ColourValue(0.3+index*change/2,index*change/2,1.0-index*change/2,1.0),true);			 
				 ++bItr;
				 ++change;
			}
				

	}	
}

void VirtualMine::Map::C2DShotHoleLayer::drawBoomOrderMark( )
{
	if (this->mOderVector.size() > 0)
	{
		std::map<int,std::vector<CBoreHole2D>>::iterator bItr = this->mOderVector.begin();
		std::map<int,std::vector<CBoreHole2D>>::iterator eItr = this->mOderVector.end();

		int count=this->mOderVector.size();
		int change=1;		
		float index=1.0/count;
		while (bItr != eItr)
		{
			CTextDrawItem* pTextItem =  ( CTextDrawItem*)this->addGeometryItem(IGeometryDrawItem::EGIT_TEXT);		
			CLine2D* boomorderLine=new CLine2D();
			QString lineName="lianxian"+QString::number((*bItr).first,10);
			pTextItem->setName(lineName.toStdString());
		    pTextItem->setType(1);
			VirtualMine::Geometry::CLine* pGeometry = (VirtualMine::Geometry::CLine*)pTextItem->getGeometry();
			std::vector<CBoreHole2D>::iterator sub_bItr = bItr->second.begin();
			std::vector<CBoreHole2D>::iterator sub_eItr = bItr->second.end();
			while (sub_bItr != sub_eItr)
			{
				Ogre::Vector3 p;
				p.x	= (*sub_bItr).mposStart.x;
				p.y	= (*sub_bItr).mposStart.y;
				p.z	= (*sub_bItr).mposStart.z;	

				pGeometry->addPointID((*bItr).first);
				pGeometry->addPoint(p.x+0.2,p.y+0.2,p.z+0.2);
				VirtualMine::Style::CLineStyle* pStyle = (VirtualMine::Style::CLineStyle*)pTextItem->getStyle();
				pStyle->setColor(Ogre::ColourValue(0.3+index*change/2,index*change/2,1.0-index*change/2,1.0));
				++sub_bItr;										 
			}	
			//drawRenderLine(boomorderLine,Ogre::ColourValue(0.3+index*change/2,index*change/2,1.0-index*change/2,1.0),true);			 
			++bItr;
			++change;
		}
	}
	
}

void VirtualMine::Map::C2DShotHoleLayer::drawBoomID()
{
	
}

void VirtualMine::Map::C2DShotHoleLayer::setVisibled(const int& type,const bool& value)
{
	int Geosize = this->mGeometryItems.size(); 	
	if (Geosize == 0)
	{
		return;
	}
	if (type==0)
	{
		for (int i = 0; i < Geosize;i++)
		{
			CPointDrawItem* pPointItem =  dynamic_cast<CPointDrawItem*>(this->mGeometryItems.at(i));
			if (pPointItem)
			{
				pPointItem->setVisible(value);
			}
			CLineDrawItem* pLineItem =  dynamic_cast<CLineDrawItem*>(this->mGeometryItems.at(i));
			if (pLineItem)
			{	
				if ( pLineItem->getType()==type)
				{
					pLineItem->setVisible(value);
				}	     			
			}
			CTextDrawItem* pTextItem =  dynamic_cast<CTextDrawItem*>(this->mGeometryItems.at(i));
			if (pTextItem)
			{ 
				if (pTextItem->getType()==type)
				{
					pTextItem->setVisible(value);
				}
				
			}

		}
	}
	if (type==1)
	{
		for (int i = 0; i < Geosize;i++)
		{
			CLineDrawItem* pLineItem =  dynamic_cast<CLineDrawItem*>(this->mGeometryItems.at(i));
			if (pLineItem)
			{	
				if ( pLineItem->getType()==type)
				{
					pLineItem->setVisible(value);
				}	     			
			}
			CTextDrawItem* pTextItem =  dynamic_cast<CTextDrawItem*>(this->mGeometryItems.at(i));
			if (pTextItem)
			{ 
				if (pTextItem->getType()==type)
				{
					pTextItem->setVisible(value);
				}

			}
		}
	}
	

}

void VirtualMine::Map::C2DShotHoleLayer::setVisibled( const bool& value )
{
	int Geosize = this->mGeometryItems.size(); 	
	if (Geosize == 0)
	{
		return;
	}
	for (int i = 0; i < Geosize;i++)
	{
		CPointDrawItem* pPointItem =  dynamic_cast<CPointDrawItem*>(this->mGeometryItems.at(i));
		if (pPointItem)
		{
			pPointItem->setVisible(value);
		}
		CLineDrawItem* pLineItem =  dynamic_cast<CLineDrawItem*>(this->mGeometryItems.at(i));
		if (pLineItem)
		{				
			pLineItem->setVisible(value);
		     			
		}
		CTextDrawItem* pTextItem =  dynamic_cast<CTextDrawItem*>(this->mGeometryItems.at(i));
		if (pTextItem)
		{ 
			
		pTextItem->setVisible(value);
		
		}

	}
}

VirtualMine::Map::C2DLanewaySectionLayer::C2DLanewaySectionLayer()
{
	this->mType = VirtualMine::Core::GeoDataType::GDT_LANEWAYSECTION;
	//kk
	this->setName("lanewaySection");
}

VirtualMine::Map::C2DLanewaySectionLayer::~C2DLanewaySectionLayer()
{

}

void VirtualMine::Map::C2DLanewaySectionLayer::initialise()
{
	drawOutFrame();
	CLine2D* leftLine=new CLine2D();
	std::string leftLineName="leftLineItem";
	leftLine->setLineName(leftLineName);
	//leftLine->addPoint(7.45,-1.7,0);


	leftLine->addPoint(7.45,0,0);
	leftLine->addPoint(7.45,2.7,0);
	leftLine->addPoint(4.85,2.7,0);
	leftLine->addPoint(4.85,0,0);
	leftLine->addPoint(7.45,0,0);
	leftLine->addPoint(7.45,-1.7,0);
	leftLine->addPoint(4.85,-1.7,0);
	leftLine->addPoint(4.85,0,0);


	CLine2D* overLine=new CLine2D();
	std::string overLineName="overLineItem";
	overLine->setLineName(overLineName);
	overLine->addPoint(-2.7,-6.45,0);
	overLine->addPoint(2.7,-6.45,0);
	overLine->addPoint(2.7,-3.85,0);
	overLine->addPoint(-2.7,-3.85,0);
	overLine->addPoint(-2.7,-6.45,0);

	drawRenderLine(leftLine,Ogre::ColourValue(0.0,1.0,0.0),true);
    drawRenderLine(overLine,Ogre::ColourValue(0.0,1.0,0.0),true);

}

void VirtualMine::Map::C2DLanewaySectionLayer::drawOutFrame()
{
	CLineDrawItem* pLinetem =  ( CLineDrawItem*)this->addGeometryItem(IGeometryDrawItem::EGIT_LINE);
	//设置geometry
	pLinetem->setName("outFramItem");
	VirtualMine::Geometry::CLine* pGeometry = (VirtualMine::Geometry::CLine*)pLinetem->getGeometry();
	double extent=1.0;
	Ogre::Vector3 p;
	p.x=2.7*extent;
	p.y=0;
	p.z=0;
	pGeometry->addPoint(p.x,p.y,p.z);
	double interval=PI/180;
	int count=1;
	for (int i=0;i<30;++i)
	{
		Ogre::Vector3 pos;
		pos.x=2.7*cos(interval*count)*extent;
		pos.y=2.7*sin(interval*count)*extent;
		pos.z=0;
		pGeometry->addPoint(pos.x,pos.y,pos.z);
		mBoundingBox.merge(pos);
		count+=6;
	}
	Ogre::Vector3 p2;
	p2.x=-2.7*extent;
	p2.y=-1.7*extent;
	p2.z=0;
	Ogre::Vector3 p3;
	p3.x=2.7*extent;
	p3.y=-1.7*extent;
	p3.z=0;
	pGeometry->addPoint(p2.x,p2.y,p2.z);
	pGeometry->addPoint(p3.x,p3.y,p3.z);
	pGeometry->addPoint(p.x,p.y,p.z);
	mBoundingBox.merge(p2);
	mBoundingBox.merge(p3);
	mBoundingBox.merge(p);
	VirtualMine::Style::CLineStyle* pStyle = (VirtualMine::Style::CLineStyle*)pLinetem->getStyle();
	pStyle->setWidth(2);
	pStyle->setColor(Ogre::ColourValue::Green);



}

void VirtualMine::Map::C2DLanewaySectionLayer::computeBoundingBox()
{
	//if (NULL == this->ref_mpDataSet)
	//	return;

	//int featureCount = this->ref_mpDataSet->getCount();//需要数据库引擎提供接口
	//for (int i = 0 ; i < featureCount; ++i)
	//{
	//	IFeature* pFeature = this->ref_mpDataSet->getFeature(i);
	//	CShotHoleFeature* shotholeFeature = dynamic_cast<CShotHoleFeature*>(pFeature);
	//	Ogre::Vector3 p(shotholeFeature->getFieldPositionX(),
	//		shotholeFeature->getFieldPositionY(),
	//		shotholeFeature->getFieldPositionZ());
	//	this->mBoundingBox.merge(p);

	//}
}

void VirtualMine::Map::C2DLanewaySectionLayer::drawRenderLine( VirtualMine::Map::CLine2D* pLine,Ogre::ColourValue renderColor,const bool& visible )
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
		box.merge(pos);
	}

	//设置风格
	VirtualMine::Style::CLineStyle* pStyle = (VirtualMine::Style::CLineStyle*)pLineItem->getStyle();
	pStyle->setWidth(2);
	pStyle->setColor(renderColor);
}

void VirtualMine::Map::C2DLanewaySectionLayer::setVisibled( const bool& value )
{
	int Geosize = this->mGeometryItems.size(); 	
	if (Geosize == 0)
	{
		return;
	}
	for (int i = 0; i < Geosize;i++)
	{
		CLineDrawItem* pLineItem =  dynamic_cast<CLineDrawItem*>(this->mGeometryItems.at(i));
		if (pLineItem)
		{				
			pLineItem->setVisible(value);

		}
	}
	
}

VirtualMine::Map::C2DLanewaySectionLayerFacetory::C2DLanewaySectionLayerFacetory()
{

}

VirtualMine::Map::C2DLanewaySectionLayerFacetory::~C2DLanewaySectionLayerFacetory()
{

}

VirtualMine::SpatialInterface::ILayer* VirtualMine::Map::C2DLanewaySectionLayerFacetory::createInstance( const std::string& name )
{
	ILayer* pLayer = new C2DLanewaySectionLayer();
	pLayer->setName(name);
	return pLayer;
}

void VirtualMine::Map::C2DLanewaySectionLayerFacetory::destroyInstance( VirtualMine::SpatialInterface::ILayer* pLayer )
{
	SAFE_DELETE(pLayer);
}

std::string VirtualMine::Map::C2DLanewaySectionLayerFacetory::getType()
{
	return VirtualMine::Core::GeoDataType::GDT_LANEWAYSECTION;
}

VirtualMine::Map::C2DEscapeRouteLayer::C2DEscapeRouteLayer()
{
	this->mType = VirtualMine::Core::GeoDataType::GDT_ESCAPEROUTE;
}

VirtualMine::Map::C2DEscapeRouteLayer::~C2DEscapeRouteLayer()
{

}

void VirtualMine::Map::C2DEscapeRouteLayer::initialise()
{

}
//kk施工进度
VirtualMine::Map::C2DConProgressLayer::C2DConProgressLayer()
{
	this->mType = VirtualMine::Core::GeoDataType::GDT_CONPROGRESS;
}

VirtualMine::Map::C2DConProgressLayer::~C2DConProgressLayer()
{

}

void VirtualMine::Map::C2DConProgressLayer::initialise()
{

}

VirtualMine::Map::C2DEscapeRouteLayerFacetory::C2DEscapeRouteLayerFacetory()
{

}

VirtualMine::Map::C2DEscapeRouteLayerFacetory::~C2DEscapeRouteLayerFacetory()
{

}

VirtualMine::SpatialInterface::ILayer* VirtualMine::Map::C2DEscapeRouteLayerFacetory::createInstance( const std::string& name )
{
	ILayer* pLayer = new C2DEscapeRouteLayer();
	pLayer->setName(name);
	return pLayer;
}

void VirtualMine::Map::C2DEscapeRouteLayerFacetory::destroyInstance( VirtualMine::SpatialInterface::ILayer* pLayer )
{
	SAFE_DELETE(pLayer);
}

std::string VirtualMine::Map::C2DEscapeRouteLayerFacetory::getType()
{
	return VirtualMine::Core::GeoDataType::GDT_ESCAPEROUTE;
}

//kk施工进度
VirtualMine::Map::C2DConProgressLayerFacetory::C2DConProgressLayerFacetory()
{

}

VirtualMine::Map::C2DConProgressLayerFacetory::~C2DConProgressLayerFacetory()
{

}

VirtualMine::SpatialInterface::ILayer* VirtualMine::Map::C2DConProgressLayerFacetory::createInstance( const std::string& name )
{
	ILayer* pLayer = new C2DEscapeRouteLayer();
	pLayer->setName(name);
	return pLayer;
}

void VirtualMine::Map::C2DConProgressLayerFacetory::destroyInstance( VirtualMine::SpatialInterface::ILayer* pLayer )
{
	SAFE_DELETE(pLayer);
}

std::string VirtualMine::Map::C2DConProgressLayerFacetory::getType()
{
	return VirtualMine::Core::GeoDataType::GDT_CONPROGRESS;
}