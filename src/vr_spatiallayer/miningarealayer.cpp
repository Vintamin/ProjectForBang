//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : CMiningAreaLayer.cpp
//  @ Date : 2014/7/27
//  @ Author : 盛佳良
//
//


#include "vrmine/vr_spatiallayer/miningarealayer.h"
#include "vrmine/vr_databaseengine/database/ifeature.h"
#include "vrmine/vr_spatialinterface/igeoobject.h"
#include "vrmine/vr_spatialrender/spatialrender/minerenderableobject.h"
#include <list>
#include "vrmine/vr_utility/objecttransformer.h"
#include "vrmine/vr_spatialobject/mine/coalseamobject.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace VirtualMine::Database;
using namespace VirtualMine::Base;
using namespace VirtualMine::SpatialRender;
using namespace VirtualMine::SpatialInterface;

namespace VirtualMine
{
    namespace SpatialLayer
    {

		CMiningAreaLayer::CMiningAreaLayer()
		{
			this->mType = VirtualMine::Core::GeoDataType::GDT_MININGAREA;
		}

		CMiningAreaLayer::~CMiningAreaLayer()
		{
		
		}

		void CMiningAreaLayer::update()
		{
		
		}

		void CMiningAreaLayer::initialise()
		{
			////assert(this->ref_mpDataSet);
			//if (NULL == this->ref_mpDataSet)
			//	return;
			//CoalSeamRenderableObject* pRenderableObject(NULL);
			//int featureCount = this->ref_mpDataSet->getCount();//需要数据库引擎提供接口
			//for (int i = 0 ; i < featureCount; ++i)
			//{
			//	IFeature* pFeature = this->ref_mpDataSet->getFeature(i);
			//	VirtualMine::SpatialInterface::IGeoObject* pGeoObject = new VirtualMine::Mine::CCoalSeamObject();
			//	pGeoObject->fromFeature(pFeature);
			//	
			//	if(NULL == pRenderableObject)
			//		pRenderableObject = new  CoalSeamRenderableObject();
			//	pRenderableObject->addGeoObject(pGeoObject);
			//}
			//if (pRenderableObject)
			//{
			//	if(NULL != this->mpRenderableObject)
			//	{
			//		this->mpRenderableObject->deRender();
			//		SAFE_DELETE(this->mpRenderableObject);
			//	}
			//	pRenderableObject->build();
			//	this->mpRenderableObject = pRenderableObject;
			//}
		}

		void CMiningAreaLayer::notifyUpdate()
		{
			
		}

        
    }
}
