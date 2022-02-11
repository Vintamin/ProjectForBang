
#include "vrmine/vr_spatialrender/baserender/multipoint.h"
#include "OGRE/OgreBillboard.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_style/style/pointstyle.h"


using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Base;
using namespace VirtualMine::Geometry;
using namespace VirtualMine::Style;


namespace VirtualMine
{
	namespace BaseRender
	{
		CMultiPoint::CMultiPoint()
			:mpRenderableObject(NULL)
		{
		
		}
		
		CMultiPoint::~CMultiPoint()
		{
			this->dispose();
		}

		void CMultiPoint::build()
		{
			if (NULL != this->mpRenderableObject)
			{
				if (this->mpRenderableObject->getParentNode())
				{
					this->mpRenderableObject->detachFromParent();
				}
				this->ref_mpGeoSceneManager->destroyBillboardSet(this->mpRenderableObject);
				this->mpRenderableObject = NULL;
			}
			if (mGeoObjectVector.size() < 1)
				return;
			CPointStyle* pStyle = dynamic_cast<CPointStyle*>(this->mGeoObjectVector.at(0)->getStyle());
			if (NULL == pStyle)
				return ;
			std::string matName("multiPoint");
			if (NULL == this->mpRenderableObject)
			{
				this->mpRenderableObject = ref_mpGeoSceneManager->createBillboardSet();
				this->mpRenderableObject->setAutoUpdate(true);
				this->mpRenderableObject->setUseAccurateFacing(true);
				this->mpRenderableObject->setRenderQueueGroup(95);
				this->mpRenderableObject->setBillboardType(Ogre::BBT_POINT);
				
				bool usePointRender = (pStyle->getPointRenderMode() == CPointStyle::PRM_COLOUR ) ? true : false;
				this->mpRenderableObject->setPointRenderingEnabled(usePointRender);
				this->mpRenderableObject->setQueryFlags(1);
				if (!usePointRender)
				{
					this->mpRenderableObject->setBillboardOrigin(Ogre::BBO_BOTTOM_CENTER);
					this->mpRenderableObject->setBillboardRotationType(Ogre::BBR_TEXCOORD);
				}
				else
				{
					this->mpRenderableObject->setBillboardRotationType(Ogre::BBR_VERTEX);
				}
				//mpRenderableObject = this->ref_mpGeoSceneManager->createManualObject();
				Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().getByName(matName, VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				if (!material.isNull())
				{
					Ogre::Pass* pass = material->getTechnique(0)->getPass(0);
					pass->setLightingEnabled(false);
					pass->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);
					//pass->setSceneBlendingOperation(Ogre::SBO_ADD);
					//pass->setVertexColourTracking(Ogre::TVC_AMBIENT | Ogre::TVC_AMBIENT);
					if (usePointRender)
					{
						pass->setPointMaxSize(pStyle->getSize());
						pass->setPointMinSize(pStyle->getSize());
						pass->setPointSize(pStyle->getSize());
					}
					material->load();
				}
				
				//this->mpRenderableObject->setMaterialName(matName,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			}
			//this->mpRenderableObject->begin(matName,Ogre::RenderOperation::OT_POINT_LIST,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			GeoObjectVector::iterator bItr = this->mGeoObjectVector.begin();
			GeoObjectVector::iterator eItr = this->mGeoObjectVector.end();
			while (bItr != eItr)
			{
				CGeoPoint* pGeoPoint = dynamic_cast<CGeoPoint*>(*bItr);
				if (pGeoPoint)
				{
					CPoint* pPoint = dynamic_cast<CPoint*>(pGeoPoint->getGeometry());
					Ogre::Billboard* pBB = this->mpRenderableObject->createBillboard(Ogre::Vector3(pPoint->getX(),pPoint->getY(),pPoint->getZ()), 
						Ogre::ColourValue(pStyle->getColor()));
					pBB->setDimensions(pStyle->getSize(),pStyle->getSize());
#if 0
					//this->mpRenderableObject->position(pPoint->getX(),pPoint->getY(),pPoint->getZ());
					//this->mpRenderableObject->colour(Ogre::ColourValue(1,1,0,1));
#endif
				}
				++bItr;
			}
			//this->mpRenderableObject->end();
			mpRenderableObject->setMaterialName(matName,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
		}
		
		void CMultiPoint::render()
		{
			if (this->mpNode)
			{
				Ogre::SceneNode* sceneNode = dynamic_cast<Ogre::SceneNode*>(this->mpNode);
				
				if (sceneNode)
				{
					sceneNode->attachObject(this->mpRenderableObject);
				}
			}
		}

		void CMultiPoint::dispose()
		{

			if (NULL != this->mpRenderableObject)
			{
				if (this->mpRenderableObject->getParentNode())
				{
					this->mpRenderableObject->detachFromParent();
				}
				this->ref_mpGeoSceneManager->destroyBillboardSet(this->mpRenderableObject);
				this->mpRenderableObject = NULL;
			}

			for (size_t i = 0 ; i < this->mGeoObjectVector.size(); ++i)
			{
				IGeoObject* pGeoObject = this->mGeoObjectVector.at(i);
				SAFE_DELETE(pGeoObject);
			}
			this->mGeoObjectVector.clear();
		}
	}
}