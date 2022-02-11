
#include "vrmine/vr_spatiallayer/faultlayer.h"
#include "vrmine/vr_databaseengine/database/ifeature.h"
#include "vrmine/vr_spatialinterface/igeoobject.h"
#include "vrmine/vr_spatialrender/spatialrender/faultrenderableobject.h"
#include <list>
#include "vrmine/vr_utility/objecttransformer.h"
#include "vrmine/vr_spatialobject/mine/faultobject.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_style/style/faultstyle.h"
#include "vrmine/vr_geometry/geometry/fault.h"
#include "OGRE/Ogre.h"
#include "vrmine/vr_spatialrender/baserender/moveabletext.h"
#include "vrmine/vr_arithmetic/arithmetic/fault_meshcreator.h"


using namespace VirtualMine::Database;
using namespace VirtualMine::Base;
using namespace VirtualMine::SpatialRender;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Style;
using namespace VirtualMine::Mine;
using namespace VirtualMine::Geometry;

namespace VirtualMine
{
	namespace SpatialLayer
	{
		CFaultLayer::CFaultLayer()
		{
			this->mType=VirtualMine::Core::GeoDataType::GDT_FAULT;
		}

		CFaultLayer::~CFaultLayer()
		{

		}

		void CFaultLayer::initialise()
		{
			if (NULL==this->ref_mpDataSet)
				return;

			this->ref_mpGeoSceneManager=this->getScene()->getGeoSceneManager();
			CFaultRenderableObject* pRenderableObject(NULL);

			int featureCount =this->ref_mpDataSet->getCount(); //需要数据库引擎提供接口
			for (int i=0;i<featureCount;++i)
			{
				IFeature* pFeature =this->ref_mpDataSet->getFeature(i);
				VirtualMine::SpatialInterface::IGeoObject* pGeoObject= new VirtualMine::Mine::CFaultObject();
				pGeoObject->fromFeature(pFeature);


				if(NULL == pRenderableObject)
					pRenderableObject = new  CFaultRenderableObject();
				pRenderableObject->addGeoObject(pGeoObject);
			}
			if (pRenderableObject)
			{
				if(NULL != this->mpRenderableObject)
				{
					this->mpRenderableObject->deRender();
					SAFE_DELETE(this->mpRenderableObject);
				}

				pRenderableObject->setNode(this->ref_mpGeoSceneManager->createSceneNode());
				pRenderableObject->setGeoSceneManager(this->ref_mpGeoSceneManager);
				pRenderableObject->build();

				


				this->mpRenderableObject = pRenderableObject;
			}
			CSceneLayer::initialise();

		}

		void CFaultLayer::notifyUpdate()
		{
			CSceneLayer::notifyUpdate();
		}

		void CFaultLayer::setStyle( VirtualMine::SpatialInterface::IStyle* pStyle )
		{

		}

		void CFaultLayer::setFrameMode( bool isFrameMode )
		{

		}

	}
}