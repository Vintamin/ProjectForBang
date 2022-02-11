//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : minerenderableobject.cpp
//  @ Date : 2014/8/6
//  @ Author :朱炜鹏
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine/vr_spatialrender/spatialrender/minerenderableobject.h"
#include "vrmine/vr_arithmetic/arithmetic/geomeshcreatorregister.h"
#include "vrmine/vr_spatialinterface/igeometry.h"
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Arithmetic;
namespace VirtualMine
{
	namespace SpatialRender
	{
		CMineRenderableObject::CMineRenderableObject()
		{

		}

		CMineRenderableObject::~CMineRenderableObject()
		{

		}

		void CMineRenderableObject::build()
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

		void CMineRenderableObject::render()
		{
			Ogre::SceneNode* sceneNode = dynamic_cast<Ogre::SceneNode*> (this->getNode());
			for (std::vector<CGeoExtentionData*>::iterator ite = this->mDataVector.begin();ite!=this->mDataVector.end();ite++)
			{
				CGeoExtentionData* geoExtentionData = (*ite);

				sceneNode->createChildSceneNode()->attachObject(geoExtentionData->getExtentionData());
			}
		}

		void CMineRenderableObject::deRender()
		{

		}
	}
}
