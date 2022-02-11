
#include "vrmine/vr_spatialrender/spatialrender/terranerenderobject.h"
#include "vrmine/vr_arithmetic/arithmetic/geomeshcreatorregister.h"
#include "vrmine/vr_spatialinterface/igeometry.h"
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Arithmetic;
namespace VirtualMine
{
	namespace SpatialRender
	{
		CTerraneRenderableObject::CTerraneRenderableObject()
		{

		}

		CTerraneRenderableObject::~CTerraneRenderableObject()
		{

		}

		void CTerraneRenderableObject::build()
		{
			if (this->mGeoObjectVector.size()<=0) return;
			VirtualMine::SpatialInterface::GeoObjectVector::iterator ite =  this->mGeoObjectVector.begin();
			IGeoObject* firstGeoObject = (*ite);
			IGeoMeshCreator* meshCreator = VirtualMine::Arithmetic::CGeoMeshCreatorRegister::getSingletonPtr()->getGeoMeshCreator(firstGeoObject->getType());

			if (meshCreator == NULL)
			{
				return;
			}
			meshCreator->createData(this->mGeoObjectVector,this->mDataVector);
		}

		void CTerraneRenderableObject::render()
		{
			Ogre::SceneNode* sceneNode = dynamic_cast<Ogre::SceneNode*> (this->getNode());
			
			
			for (std::vector<CGeoExtentionData*>::iterator ite = this->mDataVector.begin();ite!=this->mDataVector.end();ite++)
			{
				CGeoExtentionData* geoExtentionData = (*ite);
				//geoExtentionData->setSceneManager(this->getGeoSceneManager());
				//CGeoInstanceExtentionData* data = (CGeoInstanceExtentionData*) geoExtentionData; 
			
				sceneNode->attachObject(geoExtentionData->getExtentionData());
				sceneNode->setVisible(true);
			}
		}

		void CTerraneRenderableObject::deRender()
		{
			for (std::vector<CGeoExtentionData*>::iterator ite = this->mDataVector.begin();ite!=this->mDataVector.end();ite++)
			{
				CGeoExtentionData* geoExtentionData = (*ite);
				CGeoInstanceExtentionData* data = (CGeoInstanceExtentionData*) geoExtentionData; 

				if (data->getExtentionData()->getParentNode())
				{
					data->getExtentionData()->detachFromParent();
				}
			}
		}
	}
}
