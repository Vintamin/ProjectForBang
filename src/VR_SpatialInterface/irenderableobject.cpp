//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : irenderableobject.cpp
//  @ Date : 2014/7/6
//  @ Author : ʢ����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine\vr_spatialinterface\irenderableobject.h"


namespace VirtualMine
{
	namespace SpatialInterface
	{

		IRenderableObject::IRenderableObject()
			:mName("baseRenderObject"),
			mpNode(NULL),
			mHasRenderToScene(false),
			ref_mpGeoSceneManager(NULL)
		{
		
		}

		IRenderableObject::~IRenderableObject()
		{
		
		}

		void IRenderableObject::build()
		{

		}

		void IRenderableObject::render()
		{

		}

		void IRenderableObject::deRender()
		{

		}

		void IRenderableObject::dispose()
		{

		}
		
		Ogre::String IRenderableObject::getName()
		{
			return this->mName;
		}

		void IRenderableObject::setName(const Ogre::String& name)
		{
			this->mName = name;
		}

		void IRenderableObject::attachToNode(Ogre::Node* pNode)
		{
			assert(pNode);
			if (NULL == pNode)
			{
				return;
			}
			if (NULL != this->mpNode)
			{
				pNode->addChild(this->mpNode);
			}
		}

		void IRenderableObject::setNode(Ogre::Node* node)
		{
			this->mpNode = node;
		}

		Ogre::Node* IRenderableObject::getNode()
		{
			return this->mpNode;
		}

		void IRenderableObject::setGeoSceneManager(Ogre::SceneManager* ref_pGeoSceneManager)
		{
			this->ref_mpGeoSceneManager = ref_pGeoSceneManager;
		}
		
		Ogre::SceneManager* IRenderableObject::getGeoSceneManager()
		{
			return this->ref_mpGeoSceneManager;
		}

	}
}