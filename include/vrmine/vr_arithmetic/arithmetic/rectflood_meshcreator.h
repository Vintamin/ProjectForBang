
#if !defined(_RECTFLOOD_MESHCREATOR_H)
#define _RECTFLOOD_MESHCREATOR_H


#include <OGRE/Ogre.h>
#include "vrmine/vr_spatialinterface/igeomeshcreator.h"
#include "OGRE\OgreEntity.h"
#include "vrmine\vr_arithmetic\arithmetic_config.h"


namespace VirtualMine
{
	namespace Arithmetic
	{
		class VR_ARITHMETIC_DLL CRectFlood_MeshCreator : public Ogre::Entity
		{
		public:
			CRectFlood_MeshCreator();
			~CRectFlood_MeshCreator();

			void createRect(Ogre::Vector3 minPoint,Ogre::Vector3 maxPoint);
			void attachRect();
			void detachRect();
			void setSceneManager(Ogre::SceneManager* mpSceneMgr);
			Ogre::SceneManager* getSceneManager();
		    Ogre::ManualObject* getRectFlood();

            Ogre::SceneNode* getRectNode();
			double getRectHeight();
		    void setRectHeight(const double& height);
/*
			bool getVisible();
			void setVisible(bool vis);*/
		private:

			Ogre::ManualObject* rectFlood;
			Ogre::SceneManager* ref_mpSceneMgr;
			Ogre::SceneNode* mpRectNode;
			double mRectHeight;
			bool mIsVisible;
		};
	}
}

#endif 