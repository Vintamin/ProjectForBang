#include "vrmine\vr_spatialengine\geoscenecamera.h"
#include "OGRE\OgreMatrix4.h"

using namespace Ogre;

namespace VirtualMine
{
	namespace SpatialEngine
	{
		const Ogre::String CGeoSceneCamera::DEFAULT_CAMERA_NAME("DEFAULT_CAMERA_NAME");
		CGeoSceneCamera::CGeoSceneCamera(const Ogre::String& name, Ogre::SceneManager* sm)
			:Ogre::Camera(name,sm),mStandartMoveDis(376),mStandartZoomDis(376)
		{
			this->mInitialDirection = Ogre::Vector3::ZERO;
			this->mInitialPosition = Ogre::Vector3::ZERO;
		}

		void CGeoSceneCamera::setStandartMoveDis(const Ogre::Real& standartMoveDis)
		{
			this->mStandartMoveDis = standartMoveDis;
		}

		void CGeoSceneCamera::setInitialCameraInfo(const Ogre::Vector3 initialPosition,
			const Ogre::Vector3 initialDirection)
		{
			this->mInitialDirection = initialDirection;
			this->mInitialPosition = initialPosition;
			this->setPosition(this->mInitialPosition);
			this->setDirection(this->mInitialDirection);
			this->onChanged();
		}

		void CGeoSceneCamera::addCameraListener(CCameraChangedListener* ref_pListener)
		{
			ref_pListener->setGeoCamera(this);
			this->mCameraChangedListeners.push_back(ref_pListener);
		}
		
		void CGeoSceneCamera::removeCameraListener(CCameraChangedListener* ref_pListener)
		{
			if (this->mCameraChangedListeners.size() > 0)
			{
				std::vector<CCameraChangedListener*>::iterator bItr = this->mCameraChangedListeners.begin();
				std::vector<CCameraChangedListener*>::iterator eItr = this->mCameraChangedListeners.end();
				while (bItr != eItr)
				{
					if (*bItr == ref_pListener)
					{
						this->mCameraChangedListeners.erase(bItr);
						break;
					}
					++bItr;
				}
			}			
		}

		void CGeoSceneCamera::onChanged()
		{
			if (this->mCameraChangedListeners.size() > 0)
			{
				std::vector<CCameraChangedListener*>::iterator bItr = this->mCameraChangedListeners.begin();
				std::vector<CCameraChangedListener*>::iterator eItr = this->mCameraChangedListeners.end();
				while (bItr != eItr)
				{
					if (*bItr)
					{
						(*bItr)->onCameraInfoChanged();
					}
					++bItr;
				}
			}
		}

		void CGeoSceneCamera::getInitialCameraInfo(Ogre::Vector3& initialPosition,
			Ogre::Vector3& initialDirection)
		{
			initialDirection = this->mInitialDirection;
			initialPosition = this->mInitialPosition;
		}
		
		Ogre::Real CGeoSceneCamera::getStandartMoveDis()
		{
			return this->mStandartMoveDis;
		}
		
		void CGeoSceneCamera::setStandartZoomDis(const Ogre::Real& standartZoomDis)
		{
			this->mStandartZoomDis = standartZoomDis;
		}
		
		Ogre::Real CGeoSceneCamera::getStandartZoomDis()
		{
			return this->mStandartZoomDis;
		}

		CGeoSceneCamera::~CGeoSceneCamera(void)
		{		

		}

		Ogre::Vector3 CGeoSceneCamera::unProject(const int& x,const int& y)
		{
			Matrix4 inverseVP = (getProjectionMatrix() * getViewMatrix(true)).inverse();
			Real screenX = x;
			Real screenY = y;
#if OGRE_NO_VIEWPORT_ORIENTATIONMODE == 0
			// We need to convert screen point to our oriented viewport (temp solution)
			Real tX = screenX; 
			Real a = this->mOrientationMode * Math::HALF_PI;
			screenX = Math::Cos(a) * (tX-0.5f) + Math::Sin(a) * (screenY-0.5f) + 0.5f;
			screenY = Math::Sin(a) * (tX-0.5f) + Math::Cos(a) * (screenY-0.5f) + 0.5f;
			if ((int)this->mOrientationMode & 1) 
				screenY = 1.f - screenY;
#endif

			Real nx = (2.0f * screenX) - 1.0f;
			Real ny = 1.0f - (2.0f * screenY);
			Vector3 nearPoint(nx, ny, -1.f);
			// Get  origin on near plane in world space
			Vector3 origin = inverseVP * nearPoint;
			
			return origin;			
		}

		Ogre::Ray CGeoSceneCamera::getRayFromScreenXY(const int& x,const int& y)
		{
			Matrix4 inverseVP = (getProjectionMatrix() * getViewMatrix(true)).inverse();
			Real screenX = x;
			Real screenY = y;
#if OGRE_NO_VIEWPORT_ORIENTATIONMODE == 0
			// We need to convert screen point to our oriented viewport (temp solution)
			Real tX = screenX; 
			Real a = this->mOrientationMode * Math::HALF_PI;
			screenX = Math::Cos(a) * (tX-0.5f) + Math::Sin(a) * (screenY-0.5f) + 0.5f;
			screenY = Math::Sin(a) * (tX-0.5f) + Math::Cos(a) * (screenY-0.5f) + 0.5f;
			if ((int)this->mOrientationMode & 1) 
				screenY = 1.f - screenY;
#endif

			Real nx = (2.0f * screenX) - 1.0f;
			Real ny = 1.0f - (2.0f * screenY);
			Vector3 nearPoint(nx, ny, -1.f);
			// Use midPoint rather than far point to avoid issues with infinite projection
			Vector3 midPoint (nx, ny,  0.0f);

			// Get ray origin and ray target on near plane in world space
			Vector3 rayOrigin, rayTarget;

			rayOrigin = inverseVP * nearPoint;
			rayTarget = inverseVP * midPoint;

			Vector3 rayDirection = rayTarget - rayOrigin;
			rayDirection.normalise();
			Ray outRay;
			outRay.setOrigin(rayOrigin);
			outRay.setDirection(rayDirection);
			return outRay;
		}
	}
}