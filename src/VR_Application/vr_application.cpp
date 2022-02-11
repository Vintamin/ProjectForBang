#include "vr_application.h"
#include "vrmine/vr_maplayer/map.h"
#include "vrmine/vr_maplayer/map2dlayer.h"
#include "vrmine/vr_maplayer/linedrawitem.h"
#include "vrmine/vr_geometry/geometry/line.h"
#include "vrmine/vr_style/style/linestyle.h"

using namespace VirtualMine::Map;

VR_Application::VR_Application(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
}

VR_Application::~VR_Application()
{

}

void VR_Application::slotPanMap()
{
	this->ui.vR_MapControlWidget->setCurMapOperateType(MOT_PAN);
}
	
void VR_Application::slotZoomInMap()
{
	this->ui.vR_MapControlWidget->setCurMapOperateType(MOT_ZOOMIN);
}
	
void VR_Application::slotZoomOutMap()
{
	this->ui.vR_MapControlWidget->setCurMapOperateType(MOT_ZOOMOUT);
}

void VR_Application::slotFullScreen()
{
	CMap* pMap = this->ui.vR_MapControlWidget->addMap();
	pMap->setName("testXiAn80Map");
	CMap2DLayer* pLayer = pMap->addLayer(EMLT_COMPLEX);
	Ogre::AxisAlignedBox box;
	box.setNull();
	int interval = 100;
	Ogre::Vector3 referenceCenter(37536529,3060630,213);
	for (int i = 0; i < 3; ++i)
	{
		CLineDrawItem* pLineItem = (CLineDrawItem*)pLayer->addGeometryItem(IGeometryDrawItem::EGIT_LINE);
		//设置geometry
		VirtualMine::Geometry::CLine* pGeometry = (VirtualMine::Geometry::CLine*)pLineItem->getGeometry();
		Ogre::Vector3 pos1(37536529.76 - referenceCenter.x,
			3060630.151 + i * interval - referenceCenter.y,
			213.2470276);
		pGeometry->addPoint(pos1.x,pos1.y,pos1.z);
		Ogre::Vector3 pos2(37536629.76 - referenceCenter.x,
			3060530.151 + i * interval - referenceCenter.y,
			213.2470276);
		pGeometry->addPoint(pos2.x,pos2.y,pos2.z);
		Ogre::Vector3 pos3(37536829.76- referenceCenter.x,
			3060730.151 + i * interval- referenceCenter.y,213.2470276);
		pGeometry->addPoint(pos3.x,pos3.y,pos3.z);
		box.merge(pos1);
		box.merge(pos2);
		box.merge(pos3);
		//设置风格
		VirtualMine::Style::CLineStyle* pStyle = (VirtualMine::Style::CLineStyle*)pLineItem->getStyle();
		pStyle->setWidth((i + 1) * 2);
		if (i == 0)
		{
			pStyle->setColor(Ogre::ColourValue::Red);
		}
		else if (i == 1)
		{
			pStyle->setColor(Ogre::ColourValue::Green);
		}
		else 
		{
			pStyle->setColor(Ogre::ColourValue::Blue);
		}
	}
	this->ui.vR_MapControlWidget->setBoundingBox(box);
	this->ui.vR_MapControlWidget->updateBounds();
	//全图显示
	this->ui.vR_MapControlWidget->refresh();
}

void VR_Application::slotReset()
{
	this->ui.vR_MapControlWidget->setCurMapOperateType(MOT_NONE);
}
