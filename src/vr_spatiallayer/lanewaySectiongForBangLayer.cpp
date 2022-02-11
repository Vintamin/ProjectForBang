#include "vrmine/vr_spatiallayer/lanewaySectiongForBangLayer.h"
#include "vrmine/vr_databaseengine/database/ifeature.h"
#include "vrmine/vr_spatialinterface/igeoobject.h"
#include <list>
#include "vrmine/vr_utility/objecttransformer.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_spatialrender/lanewaypiperender/lanewayrenderforbang.h"
#include "bang/lanewaysectionfeature.h"
#include "vrmine/vr_geometry/geometry/laneway.h"
#include "vrmine/vr_style/style/lanewaystyle.h"
#include "vrmine/vr_spatialobject/mine/lanwayobject.h"
#include "string"

using namespace VirtualMine::Database;
using namespace VirtualMine::Base;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::BaseRender;
using namespace VirtualMine::Bang_Database;
using namespace VirtualMine::Geometry;
using namespace VirtualMine::Style;
using namespace VirtualMine::Mine;

namespace VirtualMine
{
    namespace SpatialLayer
    {

		CLaneWaySectionForBangLayer::CLaneWaySectionForBangLayer()
		{
			this->mType = VirtualMine::Core::GeoDataType::GDT_LANEWAYSECTION;
		}

		CLaneWaySectionForBangLayer::~CLaneWaySectionForBangLayer()
		{
		}

		void CLaneWaySectionForBangLayer::update()
		{
		
		}

		void CLaneWaySectionForBangLayer::initialise()
		{
			//assert(this->ref_mpDataSet);
		if (NULL == this->ref_mpDataSet)
				return;
			this->ref_mpGeoSceneManager = this->getScene()->getGeoSceneManager();

			CLanewayRenderForBang* pRenderableObject(NULL);
			int featureCount = this->ref_mpDataSet->getCount();//需要数据库引擎提供接口
			for (int i = 0 ; i < featureCount; ++i)
			{

				IFeature* pFeature = this->ref_mpDataSet->getFeature(i);
				//VirtualMine::SpatialInterface::IGeoObject* pGeoObject = new VirtualMine::Base::CGeoLine();
				//pGeoObject->fromFeature(pFeature);
				CLanewaySectionFeature* lanewaySectionForBangFeature = dynamic_cast<CLanewaySectionFeature*>(pFeature);
				CLaneWayObject* pGeoObject= new CLaneWayObject();
				CLanewayStyle* pStyle = (CLanewayStyle*)(pGeoObject->getStyle());
				pStyle->setWidth(lanewaySectionForBangFeature->getFieldParameter1());
				pStyle->setHeight(lanewaySectionForBangFeature->getFieldParameter2());

				std::string sectionType = lanewaySectionForBangFeature->getFieldType();
				if (sectionType == "半圆拱")
				{
					pStyle->setSectionType(Arch);

				}
				if (sectionType == "梯形")
				{
					pStyle->setSectionType(Trapezoid);

				}
				

				if(NULL == pRenderableObject)
					pRenderableObject = new  CLanewayRenderForBang();
				pRenderableObject->setGeoSceneManager(ref_mpGeoSceneManager);
				pRenderableObject->addGeoObject(pGeoObject);
		
			}
			if (pRenderableObject)
			{
				if(NULL != this->mpRenderableObject)
				{
					this->mpRenderableObject->deRender();
					SAFE_DELETE(this->mpRenderableObject);
				}
				pRenderableObject->setGeoSceneManager(this->ref_mpGeoSceneManager);			
				pRenderableObject->setNode(this->ref_mpGeoSceneManager->createSceneNode());
				pRenderableObject->build();
				this->mpRenderableObject = pRenderableObject;
			}
			CSceneLayer::initialise();
		}

		void CLaneWaySectionForBangLayer::notifyUpdate()
		{
			
		}

        void CLaneWaySectionForBangLayer::setFrameMode(bool isFrameMode)
		{
			//Ogre::MaterialPtr material = Ogre::MaterialManager::getSingletonPtr()->getByName("pureMaterial",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

			//if (!material.isNull())
			//{
			//	Ogre::Pass* pass = material->getTechnique(0)->getPass(0);
			//	pass->setCullingMode(Ogre::CULL_NONE);
			//	pass->setPolygonMode(Ogre::PM_WIREFRAME);
			//	material->load();
			//}

			//if	(this->mpRenderableObject == NULL) return;
			//CPipeLine* pipeRenderObject = dynamic_cast<CPipeLine*>(this->mpRenderableObject);
			//if (pipeRenderObject == NULL)
			//{
			//	return;
			//}
			//int objectCount = pipeRenderObject->getGeoObjectCount();
			//for (int i = 0; i<objectCount; ++i)
			//{
			//	CTerraneObject* terraneObject = dynamic_cast<CTerraneObject*>(terraneRenderObject->getGeoObject(i));
			//	CTerraneProperty* terranePro = dynamic_cast<CTerraneProperty*>(terraneObject->getGeoProperty());
			//	CTerraneStyle* terraneStyle = dynamic_cast<CTerraneStyle*>(terraneObject->getStyle());
			//	//CLaneWayLineGeometry* lanewayGeometry = dynamic_cast<CLaneWayLineGeometry*>(lanewayObject->getGeometry());
			//	//CLanewayStyle* lanewayStyle = dynamic_cast<CLanewayStyle*>(lanewayObject->getStyle());

			//	Ogre::ManualObject* renderObject = this->ref_mpGeoSceneManager->getManualObject(terranePro->getName());
			//	int count = renderObject->getNumSections();
			//	if (isFrameMode)
			//	{
			//		for (int j = 0; j< count; ++j)
			//		{
			//			renderObject->getSection(j)->setMaterialName("pureMaterial");
			//		}
			//	}
			//	else
			//	{
			//		for (int j = 0; j< count; ++j)
			//		{
			//			renderObject->getSection(j)->setMaterialName(terranePro->getName());
			//		}
			//	}

			//}
		
		}
    }
}
