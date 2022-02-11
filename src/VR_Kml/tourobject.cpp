#include "vrmine/vr_kml/tourobject.h"
#include "OGRE/OgreVector3.h"
#include "OGRE/OgreAnimationTrack.h"
#include "vrmine/vr_spatialengine/geoscenecamera.h"
#include "OGRE/OgreTimer.h"
#include <time.h>
#include "vrmine/vr_core/tinyxml/tinyxml.h"

namespace VirtualMine
{
	namespace Kml
	{

		class CTourRecord
		{
		public:
			CTourRecord()
			{

			}
			~CTourRecord()
			{

			}

		public:
			Ogre::Vector3 cameraPosition;
			Ogre::Vector3 cameraDirection;
			Ogre::Quaternion cameraQuaternion;
			Ogre::Real currentTime;
		};

		class CTourRecord_Private
		{
			typedef std::vector<CTourRecord*> TourRecords;
		public:
			CTourRecord_Private()
				:mpCameraListener(NULL),mTourState(TS_NONE),
				mpCameraNode(NULL),mpCameraAnimation(NULL),mpAnimationTrack(NULL),
				mpAnimationState(NULL),ref_mpTourObject(NULL),mpPlayListener(NULL),
				mPlayingRecordIndex(0)
			{
				mTourPath = "";
			}

			~CTourRecord_Private()
			{
				if (this->mpPlayListener)
				{
					Ogre::Root::getSingletonPtr()->removeFrameListener(this->mpPlayListener);
					delete this->mpPlayListener;
					this->mpPlayListener = NULL;
				}
			}

			bool isEmpty()
			{
				return this->mTourRecords.empty();
			}

			void reset()
			{
				if (!this->isEmpty())
				{
					TourRecords::iterator bItr = this->mTourRecords.begin();
					TourRecords::iterator eItr = this->mTourRecords.end();
					while (bItr != eItr)
					{
						delete *bItr;
						++bItr;
					}
					this->mTourRecords.clear();
				}
				this->mTourState = TS_NONE;
				this->mPlayingRecordIndex = 0;
			}

			void startRecord()
			{
				if (this->mpPlayListener == NULL)
				{
					this->mpPlayListener = new CTourPlayListener(this);
					//this->mpPlayListener->ref_mpTourState = this->mpAnimationState;
					Ogre::Root::getSingletonPtr()->addFrameListener(this->mpPlayListener);
				}
				this->reset();
				this->mTourState = TS_RECORD_R;
			}

			void stopRecord()
			{
				this->mTourState = TS_END_R;
			}

			void startPlay()
			{
				if (this->mpPlayListener == NULL)
				{
					this->mpPlayListener = new CTourPlayListener(this);
					Ogre::Root::getSingletonPtr()->addFrameListener(this->mpPlayListener);
				}
				this->mTourState = TS_PLAY_P;
			}

			void pausePlay()
			{
				this->mTourState = TS_PAUSE_P;
			}

			void stopPlay()
			{
				this->mTourState = TS_STOP_P;
				this->mPlayingRecordIndex = 0;
			}

			bool createPlayResource()
			{
				/*if (!this->mTourRecords.empty()
				&& this->ref_mpTourObject
				&& this->mpAnimationState == NULL)
				{
				Ogre::Real totalTime = this->mTourRecords.at(this->mTourRecords.size()-1)->currentTime;
				if (totalTime > 1000)
				{
				Ogre::SceneManager* pSceneManager = this->ref_mpTourObject->ref_mpControl->getGeoSceneManager();
				VirtualMine::SpatialEngine::CGeoSceneCamera* ref_pCamera = 
				this->ref_mpTourObject->ref_mpControl->getGeoSceneManager()->getDefaultCamera();
				ref_pCamera->setAutoTracking(true,pSceneManager->getRootSceneNode()->createChildSceneNode());
				this->mpCameraNode = pSceneManager->getRootSceneNode()->createChildSceneNode();
				this->mpCameraNode->attachObject(ref_pCamera);

				this->mpCameraAnimation = pSceneManager->createAnimation("CameraTourTrack", totalTime / 1000);
				this->mpCameraAnimation->setInterpolationMode(Ogre::Animation::IM_SPLINE);
				this->mpAnimationTrack = this->mpCameraAnimation->createNodeTrack(0,this->mpCameraNode);

				TourRecords::iterator bItr = this->mTourRecords.begin();
				TourRecords::iterator eItr = this->mTourRecords.end();
				while (bItr != eItr)
				{
				Ogre::Real keyTime = (*bItr)->currentTime / 1000;
				Ogre::TransformKeyFrame* pKeyFrame = this->mpAnimationTrack->createNodeKeyFrame(keyTime);
				pKeyFrame->setRotation((*bItr)->cameraQuaternion);
				pKeyFrame->setTranslate((*bItr)->cameraPosition);
				++bItr;
				}
				this->mpAnimationState = pSceneManager->createAnimationState(this->mpCameraAnimation->getName());
				this->mpAnimationState->setEnabled(true);
				this->mpAnimationState->setLoop(false);
				return true;
				}
				}*/
				return false;
			}

			void fromFile(const std::string& path)
			{
				TiXmlDocument doc; 
				bool result = doc.LoadFile(path.c_str(),TIXML_DEFAULT_ENCODING);
				if (!result)
				{
					return ;
				}
				this->mTourPath = path;
				this->reset();

				TiXmlElement* tourElement = doc.RootElement();  
				TiXmlAttribute* attributeOfTour = tourElement->FirstAttribute(); 
				for (; attributeOfTour != NULL ; attributeOfTour = attributeOfTour->Next())
				{
					std::string name = attributeOfTour->Name();
					if (name == "name")
					{
						this->ref_mpTourObject->mName = attributeOfTour->Value();
					}
				}
				TiXmlElement* cameraInfoNode = tourElement->FirstChildElement("cameraInfo");
				if (cameraInfoNode)
				{
					TiXmlElement* moveToElement = cameraInfoNode->FirstChildElement("moveTo");
					for (; moveToElement != NULL ; moveToElement = moveToElement->NextSiblingElement())
					{
						CTourRecord* pTourRecord = NULL;
						TiXmlAttribute* attributeOfMoveTo = moveToElement->FirstAttribute(); 
						for (; attributeOfMoveTo != NULL ; attributeOfMoveTo = attributeOfMoveTo->Next())
						{
							if (pTourRecord == NULL)
							{
								pTourRecord = new CTourRecord();
							}
							std::string name = attributeOfMoveTo->Name();
							if (name == "cameraPos")
							{
								pTourRecord->cameraPosition = Ogre::StringConverter::parseVector3(attributeOfMoveTo->Value());
							}
							else if (name == "cameraDir")
							{
								pTourRecord->cameraDirection = Ogre::StringConverter::parseVector3(attributeOfMoveTo->Value());
							}

						}
						if (pTourRecord)
						{
							this->mTourRecords.push_back(pTourRecord);
							pTourRecord = NULL;
						}
					}
				}
			}

			void toFile(const std::string& path)
			{

				this->mTourPath = path;
				TiXmlDocument doc;    
				TiXmlDeclaration* decl = new TiXmlDeclaration("1.0","GB2312", "yes");  

				TiXmlElement* rootNode = new TiXmlElement("vr_tour");
				rootNode->SetAttribute("name",this->ref_mpTourObject->mName.c_str());

				{
					TiXmlElement* cameraInfo = new TiXmlElement("cameraInfo");
					TourRecords::iterator bitr = this->mTourRecords.begin();
					TourRecords::iterator eitr = this->mTourRecords.end();
					while (bitr != eitr)
					{
						TiXmlElement* moveTo = new TiXmlElement("moveTo");
						moveTo->SetAttribute("cameraPos",Ogre::StringConverter::toString((*bitr)->cameraPosition).c_str());
						moveTo->SetAttribute("cameraDir",Ogre::StringConverter::toString((*bitr)->cameraDirection).c_str());
						cameraInfo->LinkEndChild(moveTo);
						++bitr;
					}
					rootNode->LinkEndChild(cameraInfo);
				}

				doc.LinkEndChild(decl);
				doc.LinkEndChild(rootNode);     
				doc.SaveFile(path.c_str()); 
			}

		public:
			//关于录制
			TourRecords mTourRecords;
			Ogre::Timer mTimer;
			Ogre::Real mStartTime;
			CTourObject* ref_mpTourObject;
			CCameraTourChangedListener* mpCameraListener;
			
			TourState mTourState;
			int mPlayingRecordIndex;

			//关于播放
			Ogre::SceneNode* mpCameraNode;
			Ogre::Animation* mpCameraAnimation;
			Ogre::NodeAnimationTrack* mpAnimationTrack;
			Ogre::AnimationState* mpAnimationState;
			CTourPlayListener* mpPlayListener;
			std::string mTourPath;
		};

		class CCameraTourChangedListener : public VirtualMine::SpatialEngine::CCameraChangedListener
		{
		public:
			CCameraTourChangedListener(CTourObject* ref_pTourObject)
				:ref_mpTourObject(ref_pTourObject)
			{

			}
			~CCameraTourChangedListener()
			{

			}
			void onCameraInfoChanged()
			{
				if (this->ref_mpTourObject->mpPrivate->mTourState != TS_RECORD_R)
				{
					return;
				}

				Ogre::Vector3 cameraPos = this->ref_mpGeoCamera->getRealPosition();
				Ogre::Quaternion cameraQua = this->ref_mpGeoCamera->getRealOrientation();
				
				if (this->ref_mpTourObject->mpPrivate->mTourRecords.empty())
				{
					this->ref_mpTourObject->mpPrivate->mStartTime = GetCurrentTime();//this->ref_mpTourObject->mpPrivate->mTimer.getMillisecondsCPU();
				}
				//else
				//{
				//	//记录的个数
				//	size_t rCount = this->ref_mpTourObject->mpPrivate->mTourRecords.size();
				//	CTourRecord* pLastRecord = this->ref_mpTourObject->mpPrivate->mTourRecords.at(rCount - 1);
				//	pLastRecord->duration = this->ref_mpTourObject->mpPrivate->mTimer.getMillisecondsCPU()
				//		- this->ref_mpTourObject->mpPrivate->mStartTime;
				//}
				CTourRecord* pRecord = new CTourRecord();
				pRecord->cameraPosition = cameraPos;
				pRecord->cameraQuaternion = cameraQua;
				/*pRecord->currentTime = this->ref_mpTourObject->mpPrivate->mTimer.getMillisecondsCPU()
							- this->ref_mpTourObject->mpPrivate->mStartTime;*/
				pRecord->currentTime = GetCurrentTime()
					- this->ref_mpTourObject->mpPrivate->mStartTime;
				this->ref_mpTourObject->mpPrivate->mTourRecords.push_back(pRecord);
			}
		protected:
			CTourObject* ref_mpTourObject;
			
		};

		CTourPlayListener::CTourPlayListener(CTourRecord_Private* ref_pOperator)
			:ref_mpOperator(ref_pOperator)
		{

		}

		CTourPlayListener::~CTourPlayListener()
		{

		}

		bool CTourPlayListener::frameStarted(const Ogre::FrameEvent& evt)
		{
			/*if (this->ref_mpTourState
			&& !this->ref_mpTourState->hasEnded())
			{
			this->ref_mpTourState->addTime(evt.timeSinceLastFrame);
			}*/
			VirtualMine::SpatialEngine::CGeoSceneCamera* pCamera = ref_mpOperator->ref_mpTourObject->ref_mpControl->getGeoSceneCamera();
			if (ref_mpOperator)
			{
				if (ref_mpOperator->mTourState == TS_RECORD_R)
				{
					CTourRecord* pCurRecord = new CTourRecord();
					pCurRecord->cameraDirection = pCamera->getDirection();
					pCurRecord->cameraPosition = pCamera->getPosition();
					ref_mpOperator->mTourRecords.push_back(pCurRecord);
				}
				else if (ref_mpOperator->mTourState == TS_PLAY_P)
				{
					if (ref_mpOperator->mTourRecords.size() > 0
						&& ref_mpOperator->mPlayingRecordIndex < ref_mpOperator->mTourRecords.size())
					{
						CTourRecord* pCurRecord = ref_mpOperator->mTourRecords.at(ref_mpOperator->mPlayingRecordIndex);
						pCamera->setPosition(pCurRecord->cameraPosition);
						pCamera->setDirection(pCurRecord->cameraDirection);
						pCamera->onChanged();
						ref_mpOperator->mPlayingRecordIndex++;
					}
					if (ref_mpOperator->mPlayingRecordIndex >= ref_mpOperator->mTourRecords.size() - 1)
					{
						ref_mpOperator->stopPlay();
					}
				}
			}

			return true;
		}


		CTourObject::CTourObject(VirtualMine::Scene::CGeoSpatialControl* ref_pControl)
			:CKmlObject(ref_pControl)
		{
			this->mpPrivate = new CTourRecord_Private();
			this->mpPrivate->ref_mpTourObject = this;
		}

		CTourObject::~CTourObject()
		{
			delete this->mpPrivate;
			this->mpPrivate = NULL;
		}

		TourState CTourObject::getState()
		{
			return this->mpPrivate->mTourState;
		}

		bool CTourObject::startRecord()
		{
			if (this->ref_mpControl == NULL)
			{
				return false;
			}
			//if (this->mpPrivate->mpCameraListener == NULL)
			//{
			//	this->mpPrivate->mpCameraListener = new CCameraTourChangedListener(this);
			//	this->ref_mpControl->getGeoSceneCamera()->addCameraListener(this->mpPrivate->mpCameraListener);
			//	//强制相机刷新
			//	this->ref_mpControl->getGeoSceneCamera()->onChanged();
			//}
			this->mpPrivate->startRecord();
			return true;
		}

		bool CTourObject::stopRecord()
		{
			this->mpPrivate->stopRecord();
			return true;
		}

		bool CTourObject::startPlay()
		{
			/*bool success = this->mpPrivate->createPlayResource();
			if (success)
			{
				this->mpPrivate->startPlay();
			}
			return success;*/
			this->mpPrivate->startPlay();
			return true;
		}

		bool CTourObject::pausePlay()
		{
			this->mpPrivate->pausePlay();
			return true;
		}

		bool CTourObject::stopPlay()
		{
			this->mpPrivate->stopPlay();
			return true;
		}

		std::string CTourObject::getPath()
		{
			return this->mpPrivate->mTourPath;
		}

		void CTourObject::fromFile(const std::string& path)
		{
			this->mpPrivate->fromFile(path);
		}
		void CTourObject::toFile(const std::string& path)
		{
			this->mpPrivate->toFile(path);
		}

	}}