
#include "vrmine/vr_spatialrender/baserender/multiline.h"
#include "vrmine/vr_spatialobject/base/geoline.h"
#include "vrmine/vr_geometry/geometry/line.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_style/style/linestyle.h"

using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Base;
using namespace VirtualMine::Geometry;
using namespace VirtualMine::Style;

namespace VirtualMine
{
	namespace BaseRender
	{
		CMultiLine::CMultiLine()
			:mpRenderableObject(NULL)
		{

		}

		CMultiLine::~CMultiLine()
		{
			this->dispose();
		}

		void CMultiLine::convertGeoLineToRenderData(CGeoLine* pGeoLine)
		{
			CLine* pLine = dynamic_cast<CLine*>(pGeoLine->getGeometry());
			size_t pointCount = pLine->getCount();
			if (NULL == pLine || pointCount == 0)
				return ;
			CLineStyle* pStyle = dynamic_cast<CLineStyle*>(pGeoLine->getStyle());						
			std::string matName("multiLine");
			Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().getByName(matName, VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			if (!material->isLoaded())
			{
				material->setDepthBias(0.001,1);
				material->load();
			}
			this->mpRenderableObject->begin(matName,Ogre::RenderOperation::OT_LINE_LIST,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			//构建顶点
			for (size_t i = 0 ; i < pointCount ; ++i)
			{
				CPoint& point = pLine->getPoint(i);
				this->mpRenderableObject->position(point.getX(),point.getY(),point.getZ());
				this->mpRenderableObject->colour(pStyle->getColor());
			}
			//构建索引
			for (size_t i = 0 ; i < pointCount-1 ; ++i)
			{
				this->mpRenderableObject->index(i);
				this->mpRenderableObject->index(i+1);
			}
		    this->mpRenderableObject->end();
		}

		void CMultiLine::build()
		{
			if (NULL != this->mpRenderableObject)
			{
				if (this->mpRenderableObject->getParentNode())
				{
					this->mpRenderableObject->detachFromParent();
				}
				this->ref_mpGeoSceneManager->destroyManualObject(this->mpRenderableObject);
				this->mpRenderableObject = NULL;
			}
			if (mGeoObjectVector.size() < 1)
				return;
			this->mpRenderableObject = this->ref_mpGeoSceneManager->createManualObject();

			GeoObjectVector::iterator bItr = this->mGeoObjectVector.begin();
			GeoObjectVector::iterator eItr = this->mGeoObjectVector.end();
			while (bItr != eItr)
			{
				CGeoLine* pGeoLine = dynamic_cast<CGeoLine*>(*bItr);
				if (pGeoLine)
				{
					this->convertGeoLineToRenderData(pGeoLine);
				}
				++bItr;
			}
		}

		void CMultiLine::render()
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

		void CMultiLine::dispose()
		{
			if (NULL != this->mpRenderableObject)
			{
				if (this->mpRenderableObject->getParentNode())
				{
					this->mpRenderableObject->detachFromParent();
				}
				this->ref_mpGeoSceneManager->destroyManualObject(this->mpRenderableObject);
				this->mpRenderableObject = NULL;
			}

			/*for (size_t i = 0 ; i < this->mGeoObjectVector.size(); ++i)
			{
			IGeoObject* pGeoObject = this->mGeoObjectVector.at(i);
			SAFE_DELETE(pGeoObject);
			}
			this->mGeoObjectVector.clear();*/
		}
	}
}