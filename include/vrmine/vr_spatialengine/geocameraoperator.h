//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : geocameraoperator.h
//  @ Date : 2014/7/6
//  @ Author : ʢ����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_GEOCAMERAOPERATOR_H)
#define _GEOCAMERAOPERATOR_H

#include "vrmine\vr_spatialengine\geoscenecamera.h"
#include "vrmine\vr_spatialengine\geoscenemanager.h"
#include "OGRE\OgreVector3.h"
#include "vrmine\vr_core\event.h"
#include "OGRE\OgreOverlay.h"
#include "OGRE\OgrePanelOverlayElement.h"
#include "vrmine\vr_spatialinterface\event\eventobject.h"
#include "OGRE\OgreSceneNode.h"
#include "OGRE\OgreAnimation.h"

namespace VirtualMine
{
	namespace SpatialEngine
	{
		class CGeoSpatialControl;

		class VR_SPATIALENGINE_DLL CGeocameraOperator : public VirtualMine::Core::CEventHandler
		{
		public:

			CGeocameraOperator(CGeoSceneManager* ref_pGeoSceneManager,
				CGeoSceneCamera* ref_pCamara);
			~CGeocameraOperator();

			void rotateAt(const Ogre::Vector3& rotatePoint,
				const Ogre::Real& yawAngle,
				const Ogre::Real& pitchAngle);
			void lookAt(const Ogre::Vector3& targetPoint);
			void resetCamera();
			void pan(const Ogre::Vector3& panVec);
			void zoomAt(const Ogre::Vector3& zoomPoint,const Ogre::Real& zoomDelta);
			//ui����
			void mouseReleaseEvent(const int& x ,const int& y , const int& button);
			void mousePressEvent(const int& x ,const int& y , const int& button);
			void mouseDoubleClickEvent(const int& x ,const int& y , const int& button);
			void mouseMoveEvent(const int& x ,const int& y, const int& button);
			void wheelEvent(const int& x ,const int& y , const int& delta);
			void keyPressEvent(const int& key);
			bool handleEvent(VirtualMine::Core::CEvent* evt);

		protected:
			void setRotatePointObjectVisible(const bool& visible);
			void createFlyAnimation(VirtualMine::SpatialInterface::CFlyToEvent* pFlyToEvent);
			void flyToCurTime(const Ogre::Real& curTime);
		private:
			CGeoSceneCamera* ref_mpCamara;
			CGeoSceneManager* ref_mpGeoSceneManager;
			Ogre::Vector3 mLastMousePos;
			Ogre::Vector3 mCurMousePos;
			Ogre::Vector3 mLastIntersectedPos;
			Ogre::Vector3 mCurIntersectedPos;
			float mRotateRatio;

			//�����ת��UI��ʾ
			Ogre::BillboardSet* mpRotatePointObject;
			Ogre::Overlay* mpMousePointLayerObject;
			Ogre::PanelOverlayElement* mpMousePointElementObject;
			int mElementSize;
			//���ڷ���
			bool mIsFlyMode;
			Ogre::Vector3 mStartCameraPos;
			Ogre::Vector3 mStartTargetPos;
			Ogre::Vector3 mDestinationCameraPos;
			Ogre::Vector3 mDestinationTargetPos;
			Ogre::Real mFlyDistance;
			Ogre::Real mAjustDistance;
			Ogre::Real mCurFlyPanTime;//�����¼��ĵ�ǰ�߹���ʱ��
			Ogre::Real mAjustDirTime;//������������ʱ��
			Ogre::Real mTotalFlyTime;//����������ܵķ���ʱ��
			Ogre::Real mFirstAcceleration;//��һ���̵��ȼ��ٶ�
			Ogre::Real mSecondAcceleration;//�ڶ����̵��ȼ��ٶ�
			Ogre::Real mFirstInitialSpeed;//��һ���̵ĳ�ʼ�ٶ�
			Ogre::Real mSecondInitialSpeed;//�ڶ����̵ĳ�ʼ�ٶ�
			Ogre::Real mFirstFlyTime;//��һ���̵ķ��е�ʱ��
			Ogre::Real mSecondFlyTime;//�ڶ����̵ķ��е�ʱ��

		};
	}
}
#endif  //_GEOCAMERAOPERATOR_H