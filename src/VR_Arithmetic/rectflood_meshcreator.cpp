#include "vrmine/vr_arithmetic/arithmetic/rectflood_meshcreator.h"
#include "vrmine/vr_core/geodatatype.h"


VirtualMine::Arithmetic::CRectFlood_MeshCreator::CRectFlood_MeshCreator()
{
	/*this->ref_mpSceneMgr = NULL;
	this->mIsVisible = false;
	*/

	
}

VirtualMine::Arithmetic::CRectFlood_MeshCreator::~CRectFlood_MeshCreator()
{

}

 Ogre::SceneNode* VirtualMine::Arithmetic::CRectFlood_MeshCreator::getRectNode()
 {
	 return this->mpRectNode;
 }

void VirtualMine::Arithmetic::CRectFlood_MeshCreator::createRect( Ogre::Vector3 minPoint,Ogre::Vector3 maxPoint )
{
	
	this->mRectHeight = maxPoint.y;
	if (this->ref_mpSceneMgr)
	{
		rectFlood = this->ref_mpSceneMgr->createManualObject("Flood");
		
	}
	

	if(rectFlood == NULL)
	{
		return;
	}
	

	Ogre::String rectFloodMaterial = "rectFloodMaterial";
	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingletonPtr()->getByName(rectFloodMaterial,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);

	rectFlood->begin(rectFloodMaterial,Ogre::RenderOperation::OT_TRIANGLE_LIST,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);

	//第一个三角形
	rectFlood->position(minPoint.x,minPoint.y,minPoint.z);
	rectFlood->textureCoord(0,0);
	rectFlood->position(minPoint.x,minPoint.y,maxPoint.z);
	rectFlood->textureCoord(1,0);
	rectFlood->position(maxPoint.x,minPoint.y,minPoint.z);
	rectFlood->textureCoord(0,1);


	//第二个三角形
	rectFlood->position(minPoint.x,minPoint.y,maxPoint.z);
	rectFlood->textureCoord(1,0);
	rectFlood->position(maxPoint.x,maxPoint.y,maxPoint.z);
	rectFlood->textureCoord(1,1);
	rectFlood->position(maxPoint.x,minPoint.y,minPoint.z);
	rectFlood->textureCoord(0,1);

	rectFlood->end();
}

void VirtualMine::Arithmetic::CRectFlood_MeshCreator::attachRect()
{
	if (ref_mpSceneMgr)
	{
		mpRectNode = this->ref_mpSceneMgr->getRootSceneNode()->createChildSceneNode("rectnode");
		
	     //mpRectNode =  this->ref_mpSceneMgr->createSceneNode("rectNode");

		if (mpRectNode)
		{
			//Ogre::Vector3 pos = mpRectNode->getPosition();
			
			//mpRectNode->setPosition(0,this->mRectHeight,0);
			
			mpRectNode->attachObject(rectFlood);
			//this->mIsVisible = true;
			//rectFlood->setVisible(true);
			
			
		}
	}
	
}

void VirtualMine::Arithmetic::CRectFlood_MeshCreator::setSceneManager( Ogre::SceneManager* mpSceneMgr )
{
	this->ref_mpSceneMgr=mpSceneMgr;
}

Ogre::SceneManager* VirtualMine::Arithmetic::CRectFlood_MeshCreator::getSceneManager()
{
	return ref_mpSceneMgr;
}

Ogre::ManualObject* VirtualMine::Arithmetic::CRectFlood_MeshCreator::getRectFlood()
{
	return this->rectFlood;
}


double VirtualMine::Arithmetic::CRectFlood_MeshCreator::getRectHeight()
{
	return this->mRectHeight;
}

void VirtualMine::Arithmetic::CRectFlood_MeshCreator::setRectHeight(const double& height)
{
	this->mRectHeight = height;
}

//bool VirtualMine::Arithmetic::CRectFlood_MeshCreator::getVisible()
//{
//	return mIsVisible;
//	
//}

//void VirtualMine::Arithmetic::CRectFlood_MeshCreator::setVisible( bool vis )
//{
//	this->mIsVisible = vis;
//	this->rectFlood->setVisible(vis);
//	//if (vis)
//	//{
//	//	this->attachRect();
//
//	//}
//	//else
//	//{
//	//	this->detachRect();
//	//}
//}

void VirtualMine::Arithmetic::CRectFlood_MeshCreator::detachRect()
{
	if (ref_mpSceneMgr)
	{
		
		if (mpRectNode)
		{
			//Ogre::Vector3 pos = mpRectNode->getPosition();

			//mpRectNode->setPosition(0,this->mRectHeight,0);
			mpRectNode->detachObject(rectFlood);
			
			this->mIsVisible = false;
			rectFlood->setVisible(false);
		}
	}
}
