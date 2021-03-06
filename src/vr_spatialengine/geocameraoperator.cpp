//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : geocameraoperator.cpp
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine\vr_spatialengine\geocameraoperator.h"
#include "vrmine\vr_scenecontrol\geospatialcontrol.h"
#include "OGRE\OgreOverlayManager.h"
#include "OGRE\OgreMaterial.h"
#include "OGRE\OgreMaterialManager.h"
#include "OGRE\OgreResourceGroupManager.h"
#include "OGRE\OgreTexture.h"
#include "OGRE\OgreTextureManager.h"
#include "OGRE\OgreTextureUnitState.h"
#include "OGRE\OgreImage.h"
#include "OGRE\OgreTimer.h"

using namespace VirtualMine::Core;
using namespace Ogre;
using namespace VirtualMine::SpatialInterface;

#define standardAngle 150
#define standardAjustTime 3
#define standardFlyDis 1000
#define maxFlyTime 6
#define minFlyTime 2

namespace VirtualMine
{
	namespace SpatialEngine
	{
		CGeocameraOperator::CGeocameraOperator(
			CGeoSceneManager* ref_pGeoSceneManager,
			CGeoSceneCamera* ref_pCamara)
			:ref_mpGeoSceneManager(ref_pGeoSceneManager),
			ref_mpCamara(ref_pCamara),
			mRotateRatio(5),mElementSize(10),
			mLastIntersectedPos(Ogre::Vector3::ZERO),
			mCurIntersectedPos(Ogre::Vector3::ZERO)//用于滚轮事件
		{
			////初始化关于旋转点显示对象的资源
			//this->mpRotatePointObject = ref_mpGeoSceneManager->createBillboardSet();
			//Ogre::SceneNode* pNode = ref_mpGeoSceneManager->getRootSceneNode()->createChildSceneNode();
			//Ogre::Billboard* pBB = this->mpRotatePointObject->createBillboard(Ogre::Vector3(0,0,0), Ogre::ColourValue(1,0,0,0.5));
			//pBB->setDimensions(3,3);
			////mpRotatePointObject->setQueryFlags(0);
			//Ogre::String matName("Examples/Flare");//Examples/Flare
			//Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().getByName(matName, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
			//if (!material->isLoaded())
			//{
			//	material->load();
			//}
			///*mpRotatePointObject->setAutoUpdate(true);
			//mpRotatePointObject->setUseAccurateFacing(true);
			//mpRotatePointObject->setRenderQueueGroup(95);*/
			//mpRotatePointObject->setBillboardType(Ogre::BBT_POINT);
			//mpRotatePointObject->setMaterialName(matName);
			//pNode->attachObject(mpRotatePointObject);
			//pNode->setVisible(false);
			Ogre::String mousePointLayerObjectName("mousePointLayerObjectName");
			Ogre::String mousePointElementObjectName("mousePointElementObjectName");
			this->mpMousePointLayerObject = OverlayManager::getSingleton().create(mousePointLayerObjectName);
			this->mpMousePointElementObject = (PanelOverlayElement*)(OverlayManager::getSingleton().createOverlayElement("Panel",mousePointElementObjectName));
			this->mpMousePointElementObject->setMetricsMode(GMM_PIXELS);
			this->mpMousePointElementObject->setWidth(mElementSize);
			this->mpMousePointElementObject->setHeight(mElementSize);
			this->mpMousePointElementObject->setLeft(0);
			this->mpMousePointElementObject->setTop(0);
			this->mpMousePointElementObject->setCaption(Ogre::DisplayString("adb"));

			this->mpMousePointLayerObject->add2D(this->mpMousePointElementObject);
			this->mpMousePointLayerObject->hide();

			//
			MaterialPtr matPtr = MaterialManager::getSingletonPtr()->create(mousePointLayerObjectName,Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
			Pass* pass = matPtr->getTechnique(0)->getPass(0);
			pass->setLightingEnabled(false);
			pass->setSceneBlending(SBT_TRANSPARENT_ALPHA);
			Ogre::String texName("mousepointTexture");
			
			Ogre::Image image;
			image.load("mousepoint.png",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
			//image.load("compus.png",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);


			TexturePtr texPtr = TextureManager::getSingletonPtr()->create(texName,Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
			if (!texPtr.isNull())
			{
				texPtr->loadImage(image);
				TextureUnitState* pTexUnit = pass->createTextureUnitState(texName,0);
				pTexUnit->setTextureCoordSet(0); 
			
				pTexUnit->setColourOperation(LBO_REPLACE);
				pTexUnit->setTextureFiltering(FO_LINEAR,FO_LINEAR,FO_LINEAR);
				this->mpMousePointElementObject->setMaterialName(matPtr->getName());
				this->mpMousePointElementObject->setUV(0,0,1,1);
				this->mpMousePointElementObject->setHorizontalAlignment(GHA_LEFT);
				this->mpMousePointElementObject->setVerticalAlignment(GVA_TOP);
			}
			MaterialManager::getSingletonPtr()->remove(matPtr->getHandle());
			//初始化飞行相关
			mIsFlyMode = false;
			mTotalFlyTime = 0;
			mStartTargetPos = Ogre::Vector3::ZERO;
			mDestinationCameraPos = Ogre::Vector3::ZERO;
			mDestinationTargetPos = Ogre::Vector3::ZERO;
			mFlyDistance = 0;
			mAjustDistance = 0;
			mCurFlyPanTime = 0;
			mAjustDirTime = 0;
			mTotalFlyTime = 0;
			mFirstAcceleration = 0;
			mSecondAcceleration = 0;
			mFirstInitialSpeed = 0;
			mSecondInitialSpeed = 0;
			mFirstFlyTime = 0;
			mSecondFlyTime = 0;
		}

		CGeocameraOperator::~CGeocameraOperator()
		{
		
		}

		void CGeocameraOperator::rotateAt(const Ogre::Vector3& rotatePoint,
			const Ogre::Real& yawAngle,
			const Ogre::Real& pitchAngle)
		{
			if (this->ref_mpCamara)
			{
				Ogre::Radian rY = Ogre::Radian(yawAngle);
				Ogre::Radian rP = Ogre::Radian(pitchAngle);

				if (rotatePoint != Ogre::Vector3::ZERO)
				{

					Ogre::Vector3 oriCameraPos = this->ref_mpCamara->getPosition();

					//旋转轴的方向 
					Ogre::Vector3 dir(oriCameraPos- rotatePoint );
					Ogre::Real dis = dir.length();
					dir.normalise();

					//偏航角-变换
					Ogre::Quaternion q ;
					q.FromAngleAxis(rY,Ogre::Vector3::UNIT_Y);

					bool needPitch(true);
					Ogre::Vector3 curDir = this->ref_mpCamara->getDirection();
					float d = 0;
					float l = curDir.length();
					Ogre::Radian angle = Ogre::Math::ACos(curDir.dotProduct(Ogre::Vector3::UNIT_Y) / l);
					if ((angle.valueDegrees() > 175 && rP.valueDegrees() < 0)
						|| (angle.valueDegrees() < 5 && rP.valueDegrees() > 0))
					{
						rP = Ogre::Radian(0);
						needPitch = false;
					}

					//俯仰角-变换
					if (needPitch)
					{
						Ogre::Vector3 lookDir = this->ref_mpCamara->getDirection();
						Ogre::Vector3 rotateAxis = lookDir.crossProduct(Ogre::Vector3::UNIT_Y);
						rotateAxis.normalise();

						Ogre::Quaternion t_q ;
						t_q.FromAngleAxis(rP,rotateAxis);

						//综合考虑偏航与俯仰角的变换 
						q = q * t_q;
					}
					//旋转之后的点坐标
					Ogre::Vector3 afterRotatePoint  = q * dir ;
					afterRotatePoint *= dis;
					afterRotatePoint += rotatePoint;

					ref_mpCamara->setPosition(rotatePoint);
					this->ref_mpCamara->yaw(rY);
					this->ref_mpCamara->pitch(rP);

					this->ref_mpCamara->setPosition(afterRotatePoint);
				}
				else
				{
					this->ref_mpCamara->yaw(rY);
					this->ref_mpCamara->pitch(rP);
				}
				this->ref_mpCamara->onChanged();
			}
		}

		void CGeocameraOperator::pan(const Ogre::Vector3& panVec)
		{
			if (this->ref_mpCamara)
			{
				this->ref_mpCamara->moveRelative(panVec);
				this->ref_mpCamara->onChanged();
			}
		}

		void CGeocameraOperator::zoomAt(const Ogre::Vector3& zoomPoint,const Ogre::Real& zoomDelta)
		{
			if (this->ref_mpCamara)
			{
				if (zoomPoint != Ogre::Vector3::ZERO)
				{
					Ogre::Real moveRatio = 1;

					Ogre::Real curDis = this->ref_mpCamara->getPosition().distance(zoomPoint);
					moveRatio = curDis / this->ref_mpCamara->getStandartZoomDis() ;
#if 0					
					moveRatio = moveRatio > 1 ? moveRatio : 1;
#endif
					Ogre::Vector3 zoomDir = zoomPoint - this->ref_mpCamara->getPosition();
					zoomDir.normalise();
					Ogre::Vector3 newPos = this->ref_mpCamara->getPosition() + zoomDir * moveRatio * zoomDelta / 8;
					this->ref_mpCamara->setPosition(newPos);
				}
				else
				{
					Ogre::Vector3 zoomDir =Ogre::Vector3::ZERO;
					zoomDir.z = -zoomDelta / 8;
					this->ref_mpCamara->moveRelative(zoomDir);
				}
				this->ref_mpCamara->onChanged();
			}
		}

		void CGeocameraOperator::lookAt(const Ogre::Vector3& targetPoint)
		{
			if (this->ref_mpCamara)
			{
				this->ref_mpCamara->lookAt(targetPoint);
			}
		}

		void CGeocameraOperator::resetCamera()
		{
			if (this->ref_mpCamara)
			{
				Ogre::Vector3 initialPosition(Ogre::Vector3::ZERO);
				Ogre::Vector3 initialDirection(Ogre::Vector3::ZERO);
				this->ref_mpCamara->getInitialCameraInfo(initialPosition,initialDirection);

				if (initialPosition != Ogre::Vector3::ZERO)
				{
					this->ref_mpCamara->setPosition(initialPosition);
					this->ref_mpCamara->setDirection(initialDirection);
				}
				else
				{
					this->ref_mpCamara->setPosition(Ogre::Vector3(0,300,400));
					this->ref_mpCamara->lookAt(Ogre::Vector3(0,0,0));
				}
				this->ref_mpCamara->onChanged();
			}
		}

		void CGeocameraOperator::mouseReleaseEvent(const int& x ,const int& y , const int& button)
		{
			this->mLastIntersectedPos = Ogre::Vector3::ZERO;
			this->mLastMousePos = Ogre::Vector3::ZERO;
			this->mCurMousePos = Ogre::Vector3::ZERO;
			if (button == 2)
			{
				this->setRotatePointObjectVisible(false);
			}
		}

		void CGeocameraOperator::mousePressEvent(const int& x ,const int& y , const int& button)
		{
			this->mLastMousePos.x = x;
			this->mLastMousePos.y = y;
			Ogre::Vector3 intersectPoint(Ogre::Vector3::ZERO);
			if (this->ref_mpGeoSceneManager->getRayIntersectedPoint(x,y,intersectPoint))
			{
				this->mLastIntersectedPos = intersectPoint;
				std::cout << "镜头方案" << std::endl;
				std::cout << intersectPoint.x << "*" << intersectPoint.y << "*" << intersectPoint.z << std::endl;
				if (button == 1)
				{
					int idx = 1;
					idx = 0 ;
				}
				else if(button == 2)
				{
					this->mpMousePointElementObject->setTop(y-mElementSize/2);
					this->mpMousePointElementObject->setLeft(x-mElementSize/2);
					this->setRotatePointObjectVisible(true);					
				}
			}			
		}

		void CGeocameraOperator::flyToCurTime(const Ogre::Real& curTime)
		{
#if 0
			if (this->mpFlyState)
			{
				this->mpFlyState->addTime(curTime);
			}
#else
			if (mTotalFlyTime > 0.01)
			{
				Ogre::Real curTimePan = this->mCurFlyPanTime;
				//调整朝向
				if (curTimePan < this->mAjustDirTime)
				{
					Ogre::Vector3 camToDestinationDir = this->mDestinationTargetPos - this->mStartTargetPos;
					camToDestinationDir.normalise();
					Ogre::Real moveRatio = curTimePan / this->mAjustDirTime;
					Ogre::Real moveDis = this->mAjustDistance * moveRatio;
					Ogre::Vector3 curTargetPos = this->mStartTargetPos + camToDestinationDir * moveDis;
					this->ref_mpCamara->lookAt(curTargetPos);
				}
				//飞行过程
				else if (curTimePan < this->mTotalFlyTime)
				{
					Ogre::Vector3 curCamaraPos(Ogre::Vector3::ZERO);
					Ogre::Vector3 camToDestinationDir = this->ref_mpCamara->getDirection();
					camToDestinationDir.normalise();
					//加速过程走过的时间
					Ogre::Real curAccelerationTimePan(0);
					//加速过程走过的时间路程
					Ogre::Real curAccelerationDisPan(0); 
					//第一加速飞行过程
					if (curTimePan < this->mAjustDirTime + this->mFirstFlyTime)
					{
						//加速过程走过的时间
						curAccelerationTimePan = curTimePan - this->mAjustDirTime;
						//加速过程走过的时间路程
						curAccelerationDisPan = this->mFirstInitialSpeed * curAccelerationTimePan + 0.5 * this->mFirstAcceleration * (curAccelerationTimePan * curAccelerationTimePan);
					}
					//第二减速飞行过程
					else if (curTimePan < this->mTotalFlyTime)
					{
						Ogre::Real oriDis = this->mStartCameraPos.distance(this->mDestinationCameraPos);
						Ogre::Real dis = this->ref_mpCamara->getPosition().distance(this->mDestinationCameraPos);
						dis = 0;
						//减速过程走过的时间
						curAccelerationTimePan = curTimePan - this->mAjustDirTime - this->mFirstFlyTime;
						//减速过程走过的时间路程
						curAccelerationDisPan = this->mSecondInitialSpeed * curAccelerationTimePan + 0.5 * this->mSecondAcceleration * (curAccelerationTimePan * curAccelerationTimePan);
						curAccelerationDisPan += this->mFlyDistance / 2;

					}
					curCamaraPos = this->mStartCameraPos + camToDestinationDir * curAccelerationDisPan;
					this->ref_mpCamara->setPosition(curCamaraPos);
				}
				else
				{
					this->mCurFlyPanTime = 0;
					this->mIsFlyMode = false;
				}
			}
			else
			{
				this->mIsFlyMode = false;
				this->mCurFlyPanTime = 0;
			}
#endif
		}

		void CGeocameraOperator::createFlyAnimation(CFlyToEvent* pFlyToEvent)
		{
#if 0
			Ogre::Real dis = this->ref_mpCamara->getPosition().distance(pFlyToEvent->getFlyToPosition());
			this->mTotalFlyTime = dis / 1000;
			
			Ogre::SceneNode* camNode = this->ref_mpGeoSceneManager->getRootSceneNode()->createChildSceneNode();
			camNode->attachObject(this->ref_mpCamara);
			this->ref_mpCamara->setAutoTracking(true,camNode);

			this->mpFlyAnimation = this->ref_mpGeoSceneManager->createAnimation("CameraTrack", this->mTotalFlyTime);
			this->mpFlyAnimation->setInterpolationMode(Ogre::Animation::IM_SPLINE);
			this->mpFlyTrack = this->mpFlyAnimation->createNodeTrack(0, camNode);
			////////////////构建飞行路径
			Ogre::Vector3 startPos = this->ref_mpCamara->getPosition();
			Ogre::Vector3 endPos = pFlyToEvent->getFlyToPosition();
			this->mpFlyTrack->createNodeKeyFrame(0)->setTranslate(startPos);
			this->mpFlyTrack->createNodeKeyFrame(this->mTotalFlyTime)->setTranslate(endPos);
			///////////////////////////////////////////////////////
			this->mpFlyState = this->ref_mpGeoSceneManager->createAnimationState(this->mpFlyAnimation->getName());
			this->mpFlyState->setEnabled(true);
			this->mpFlyState->setLoop(false);
			/*this->ref_mpGeoSceneManager->_applySceneAnimations();*/

#else
			Ogre::Vector3 lookDir = this->ref_mpCamara->getUp().crossProduct(this->ref_mpCamara->getRight());
			lookDir.normalise();
			//计算调整朝向的时间
			Ogre::Vector3 camToTargetDir = this->ref_mpCamara->getDirection().normalisedCopy();
			Ogre::Vector3 camToDestinationDir = pFlyToEvent->getFlyToPosition() - this->ref_mpCamara->getPosition();
			camToDestinationDir.normalise();

			Ogre::Real angle = Ogre::Math::Abs(camToTargetDir.angleBetween(camToDestinationDir).valueDegrees());
			if (angle < 50)
			{
				this->mAjustDirTime = 1.5;
			}
			else
			{
				Ogre::Real angleRatio = angle / standardAngle;
				this->mAjustDirTime = angleRatio * standardAjustTime;
			}
			//计算调整朝向后总的飞行时间
			Ogre::Real dis = this->ref_mpCamara->getPosition().distance(pFlyToEvent->getFlyToPosition());
			//
			this->mStartCameraPos = this->ref_mpCamara->getPosition();
			this->mStartTargetPos = this->ref_mpCamara->getPosition() + camToTargetDir * 500;
			Ogre::Real backDis = 0;//飞行完成后相机位置距离目标点的距离
			if (dis > 100)
			{
				backDis = 40;
			}
			else
			{
				backDis = dis / 2;
			}
			this->mDestinationCameraPos = this->ref_mpCamara->getPosition() + camToDestinationDir * (dis - backDis);

			this->mDestinationTargetPos = pFlyToEvent->getFlyToPosition();

			this->mFlyDistance = this->mStartCameraPos.distance(this->mDestinationCameraPos);
			this->mAjustDistance = this->mStartTargetPos.distance(this->mDestinationTargetPos);
			if (this->mFlyDistance > 1000)
			{
				this->mTotalFlyTime = maxFlyTime;
			}
			else if (this->mFlyDistance > 100)
			{
				this->mTotalFlyTime = (maxFlyTime - minFlyTime) * dis / standardFlyDis + minFlyTime;
			}
			else 
			{
				this->mTotalFlyTime = minFlyTime;
			}
			//第一过程以mTotalFlyTime/2的时间飞行路程为mFlyDistance/2,
			this->mFirstFlyTime = mTotalFlyTime / 2;
			this->mSecondFlyTime = mTotalFlyTime / 2;
			this->mTotalFlyTime += this->mAjustDirTime;
			//做匀加速运动,初始速度为
			mFirstInitialSpeed = 0; 
			//加速度为：
			this->mFirstAcceleration = 2 * (mFlyDistance / 2) / (this->mFirstFlyTime * this->mFirstFlyTime);
			//完成第一飞行过程后的速度(即：第二过程的初始速度)为：
			this->mSecondInitialSpeed = this->mFirstInitialSpeed + this->mFirstAcceleration * this->mFirstFlyTime;
			//第二过程做匀减速运动,加速度为：
			this->mSecondAcceleration = -1 * this->mSecondInitialSpeed * this->mSecondInitialSpeed / (2 * (mFlyDistance / 2));
			
			this->mCurFlyPanTime = 0;
			this->mIsFlyMode = true;
#endif
		}

		void CGeocameraOperator::setRotatePointObjectVisible(const bool& visible)
		{
#if 1
			if (this->mpMousePointElementObject
				&& this->mpMousePointLayerObject)
			{
				if (visible)
				{
					this->mpMousePointLayerObject->show();
				}
				else
				{
					this->mpMousePointLayerObject->hide();
				}
			}
#else
			/*if (this->mpRotatePointObject
				&& this->mpRotatePointObject->getParentNode())
			{
				Ogre::SceneNode* pNode = dynamic_cast<Ogre::SceneNode*>(this->mpRotatePointObject->getParentNode());
				if (pNode)
				{
					pNode->setPosition(this->mLastIntersectedPos);
					if (visible && this->mLastIntersectedPos != Ogre::Vector3::ZERO)
					{
						pNode->setVisible(visible);
					}
					else
					{
						pNode->setVisible(false);
					}
					
				}
			}*/
#endif
		}

		
		void CGeocameraOperator::mouseDoubleClickEvent(const int& x ,const int& y , const int& button)
		{
			
		}
		
		void CGeocameraOperator::mouseMoveEvent(const int& x ,const int& y, const int& button)
		{
			this->mCurMousePos.x = x;
			this->mCurMousePos.y = y;

			if (button == 1)//左键
			{
				//if (this->mLastIntersectedPos != Ogre::Vector3::ZERO)
				//{
				//	Ogre::Vector3 intersectPoint(Ogre::Vector3::ZERO);
				//	if (this->ref_mpGeoSceneManager->getRayIntersectedPoint(x,y,intersectPoint))
				//	{
				//		Ogre::Vector3 panVector = intersectPoint - this->mLastIntersectedPos;
				//		/*panVector.y = panVector.z;
				//		panVector.z = 0;*/
				//		Ogre::Vector3& newPos = this->ref_mpCamara->getPosition() + -1 * panVector;
				//		this->ref_mpCamara->setPosition(newPos);
				//		//this->pan(-1 * panVector);
				//		this->mLastIntersectedPos = intersectPoint;
				//	}
				//}
				//else
				{
#if 0
					//Ogre::Vector3 curPos = this->ref_mpCamara->unProject(this->mCurMousePos.x,this->mCurMousePos.y);
					//Ogre::Vector3 lastPos = this->ref_mpCamara->unProject(this->mLastMousePos.x,this->mLastMousePos.y);

					///*Ogre::Real dltX = curPos.x - lastPos.x;
					//Ogre::Real dltY = curPos.y - lastPos.y;
					//dltX *= -0.3;
					//dltY *= -0.3;
					//this->ref_mpCamara->moveRelative(Ogre::Vector3(dltX ,dltY,0));*/
#else
					Ogre::Real moveRatio = 1;
					if (this->mLastIntersectedPos != Ogre::Vector3::ZERO)
					{
						Ogre::Real curDis = this->ref_mpCamara->getPosition().distance(this->mLastIntersectedPos);
						moveRatio = curDis / this->ref_mpCamara->getStandartMoveDis() ;
					}

					float rX = this->mCurMousePos.x - this->mLastMousePos.x;
					float rY = this->mCurMousePos.y - this->mLastMousePos.y;
					rX *= moveRatio;
					rY *= moveRatio;
					this->ref_mpCamara->moveRelative(Ogre::Vector3(-0.5 * rX,0.5 * rY,0));
					this->ref_mpCamara->onChanged();
#endif
					
				}
			}
			else if (button == 2)//右键
			{
				Ogre::Viewport* pViewPort = ref_mpCamara->getViewport();
				Ogre::int32 width = pViewPort->getActualWidth();
				Ogre::int32 height = pViewPort->getActualHeight();
				Ogre::Real rotateY  = this->mRotateRatio * (float)(this->mCurMousePos.x - this->mLastMousePos.x)/ width;
				Ogre::Real rotateP = this->mRotateRatio * (float)(this->mCurMousePos.y - this->mLastMousePos.y)/ height;

				this->rotateAt(this->mLastIntersectedPos,rotateY,rotateP);
			}
			this->mLastMousePos = this->mCurMousePos;
			mCurIntersectedPos = Ogre::Vector3::ZERO;
			//
		}

		bool CGeocameraOperator::handleEvent(CEvent* evt)
		{
			assert(evt);
			if (NULL == evt)
				return false;
			CFlyToEvent* pFlyToEvent = dynamic_cast<CFlyToEvent*>(evt);
			if (pFlyToEvent)
			{
				this->createFlyAnimation(pFlyToEvent);
				mIsFlyMode = true;
			}
			else if (this->mIsFlyMode)
			{
				CFrameEvent* pFrameEvt = dynamic_cast<CFrameEvent*>(evt);
				if (pFrameEvt)
				{
					Ogre::Real timeSinceLastEvent,timeSinceLastFrame;
					pFrameEvt->getTime(timeSinceLastEvent,timeSinceLastFrame);
					mCurFlyPanTime += timeSinceLastFrame;
					this->flyToCurTime(timeSinceLastFrame);
				}
			}
			
			return false;
		}

		void CGeocameraOperator::keyPressEvent(const int& key)
		{
			switch (key)
			{
			case  82:

				;
			case 32:

				;
			}
		}
		
		void CGeocameraOperator::wheelEvent(const int& x ,const int& y , const int& delta)
		{
			if (this->mCurIntersectedPos == Ogre::Vector3::ZERO)
			{
				this->ref_mpGeoSceneManager->getRayIntersectedPoint(x,y,this->mCurIntersectedPos);
			}
			this->zoomAt(this->mCurIntersectedPos,delta);
		}
	}
}
