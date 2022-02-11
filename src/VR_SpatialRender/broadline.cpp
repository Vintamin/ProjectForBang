#include "vrmine/vr_spatialrender/baserender/broadline.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_spatialengine/geoscenemanager.h"
#include "vrmine/vr_spatialengine/geoscenecamera.h"
#include "OGRE/OgreRoot.h"


using namespace VirtualMine::Geometry;
using namespace VirtualMine::SpatialInterface;

namespace VirtualMine
{
	namespace BaseRender
	{


		CBroadLineListener::CBroadLineListener(CBroadLine* ref_pBroadLine)
			:ref_mpBroadLine(ref_pBroadLine)
		{

		}

		CBroadLineListener::~CBroadLineListener()
		{

		}

		bool CBroadLineListener::frameStarted(const Ogre::FrameEvent& evt)
		{
			if (ref_mpBroadLine)
			{
				Ogre::ManualObject* pObject = ref_mpBroadLine->mpRenderObject;
				Ogre::Node* pNode = pObject->getParentNode();

				VirtualMine::SpatialEngine::CGeoSceneManager* pSceneManager = dynamic_cast<VirtualMine::SpatialEngine::CGeoSceneManager*>(this->ref_mpBroadLine->ref_mpGeoSceneManager);
				VirtualMine::SpatialEngine::CGeoSceneCamera* pCamera = pSceneManager->getDefaultCamera();
				Ogre::Vector3 dir = -1 * pCamera->getDirection();
				dir.normalise();

				Ogre::Vector3 v1(0,0,0);
				Ogre::Vector3 v2(500,0,0);
				Ogre::Vector3 dir_1 = v1 - pCamera->getPosition();
				Ogre::Vector3 dir_2 = v2 - pCamera->getPosition();
				dir_1.normalise();
				dir_2.normalise();
				Ogre::Vector3 crossDir = dir_1.crossProduct(dir_2);
				crossDir.normalise();

				Ogre::Vector3 verticalDir = crossDir.crossProduct(Ogre::Vector3::UNIT_X);
				verticalDir.normalise();

				Ogre::Radian angle = verticalDir.angleBetween(Ogre::Vector3::UNIT_Z);
				Ogre::Vector3 axis = v2 - v1;//Ogre::Vector3::UNIT_X;
				axis.normalise();
				Ogre::Quaternion q;
				q.FromAngleAxis(-angle,axis);

				pNode->setOrientation(q);

				Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingletonPtr()->getByName("broadline_test",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				if (!mat.isNull())
				{
					Ogre::GpuProgramParametersSharedPtr gpSp = mat->getTechnique(0)->getPass(0)->getFragmentProgramParameters();
					float timeLost = this->mTimer.getMillisecondsCPU();
					//gpSp->setNamedConstant("timelost",timeLost);
				}

			}
			return true;
		}

		CBroadLine::CBroadLine()
			:IRenderableObject(),mpLineData(NULL),
			mWidth(4),mpRenderObject(NULL)
		{
			CBroadLineListener* pListener = new CBroadLineListener(this);
			Ogre::Root::getSingletonPtr()->addFrameListener(pListener);
		}


		CBroadLine::~CBroadLine()
		{
			if (this->mpLineData)
			{
				delete this->mpLineData;
				this->mpLineData = NULL;
			}
		}

		void CBroadLine::addPoint(VirtualMine::Geometry::CPoint& point)
		{
			if (this->mpLineData == NULL)
			{
				this->mpLineData = new VirtualMine::Geometry::CLine();
			}
			this->mpLineData->addPoint(point);
		}
		
		void CBroadLine::flushToScene()
		{
			if (this->ref_mpGeoSceneManager == NULL
				|| this->mpLineData == NULL
				|| this->mpLineData->getCount() < 2)
			{
				return;
			}
			std::string matName("broadline_test");
			Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().getByName(matName, VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			if (!material->isLoaded())
			{
				Ogre::Pass* pass0 = material->getTechnique(0)->getPass(0);
				
				material->load();
			}

			if (this->mpRenderObject == NULL)
			{
				this->mpRenderObject = this->ref_mpGeoSceneManager->createManualObject();
			}

			//写入顶点
			mpRenderObject->begin(matName,
				Ogre::RenderOperation::OT_TRIANGLE_LIST,
				VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			Ogre::Vector3 dir = Ogre::Vector3(500,500,0) - Ogre::Vector3(0,0,0);
			dir.normalise();
			dir = dir.crossProduct(Ogre::Vector3::UNIT_Z);
			dir.normalise();

			Ogre::Real u,v;
			CPoint firstPoint = this->mpLineData->getPoint(0);
			Ogre::Real standDis = 30;
			Ogre::Vector3 lastPoint(firstPoint.getX(),firstPoint.getY(),firstPoint.getZ());
			//下
			for (size_t i = 0; i < this->mpLineData->getCount(); ++i)
			{
				CPoint& p = this->mpLineData->getPoint(i);
				mpRenderObject->position(p.getX(),p.getY(),p.getZ());
				mpRenderObject->colour(Ogre::ColourValue(1,1,1,1));

				//
				Ogre::Vector3 curPoint(p.getX(),p.getY(),p.getZ());
				Ogre::Real length = curPoint.distance(lastPoint);
				u = length / standDis;
				v = 0;
				mpRenderObject->textureCoord(u,v);
			}

			//上
			for (size_t i = 0; i < this->mpLineData->getCount(); ++i)
			{
				CPoint& p = this->mpLineData->getPoint(i);
				Ogre::Vector3 pos(p.getX(),p.getY(),p.getZ());
				pos = pos + dir * 10;
				mpRenderObject->position(pos);
				mpRenderObject->colour(Ogre::ColourValue(1,1,1,1));

				Ogre::Vector3 curPoint(p.getX(),p.getY(),p.getZ());
				Ogre::Real length = curPoint.distance(lastPoint);
				u = length / standDis;
				v = 1;
				mpRenderObject->textureCoord(u,v);
			}
			int totalRow = 1;
			int totalCol = this->mpLineData->getCount();
			//写入索引
			for (int row = 0 ; row < totalRow; ++row)
			{
				for (int col = 0 ; col < totalCol - 1; ++col)
				{
					int index_0_0 = row *  totalCol + col;
					int index_0_1 = (row + 1) *  totalCol + col;
					int index_0_2 = row *  totalCol + col + 1;

					int index_1_0 = row *  totalCol + col + 1;
					int index_1_1 = (row + 1) *  totalCol + col;
					int index_1_2 = (row + 1) *  totalCol + col + 1;

					this->mpRenderObject->index(index_0_0);
					this->mpRenderObject->index(index_0_1);
					this->mpRenderObject->index(index_0_2);

					this->mpRenderObject->index(index_1_0);
					this->mpRenderObject->index(index_1_1);
					this->mpRenderObject->index(index_1_2);
				}
			}

			mpRenderObject->end();
#if 0
			//侧方
			//matName = "broadline_test_1";
			material = Ogre::MaterialManager::getSingleton().getByName(matName, VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			if (!material->isLoaded())
			{
				material->load();
			}
			//写入顶点
			mpRenderObject->begin(matName,
				Ogre::RenderOperation::OT_TRIANGLE_LIST,
				VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);

			firstPoint = this->mpLineData->getPoint(0);
			lastPoint = Ogre::Vector3(firstPoint.getX(),firstPoint.getY(),firstPoint.getZ());
			//下
			for (size_t i = 0; i < this->mpLineData->getCount(); ++i)
			{
				CPoint& p = this->mpLineData->getPoint(i);
				mpRenderObject->position(p.getX(),p.getY()+5,p.getZ()-5);
				mpRenderObject->colour(Ogre::ColourValue(1,1,1,1));

				//
				Ogre::Vector3 curPoint(p.getX(),p.getY(),p.getZ());
				Ogre::Real length = curPoint.distance(lastPoint);
				u = length / standDis;
				v = 0;
				mpRenderObject->textureCoord(u,v);
			}

			//上
			for (size_t i = 0; i < this->mpLineData->getCount(); ++i)
			{
				CPoint& p = this->mpLineData->getPoint(i);
				mpRenderObject->position(p.getX(),p.getY() + 5,p.getZ()+5);
				mpRenderObject->colour(Ogre::ColourValue(1,1,1,1));

				Ogre::Vector3 curPoint(p.getX(),p.getY(),p.getZ());
				Ogre::Real length = curPoint.distance(lastPoint);
				u = length / standDis;
				v = 1;
				mpRenderObject->textureCoord(u,v);
			}
			totalRow = 1;
			totalCol = this->mpLineData->getCount();
			//写入索引
			for (int row = 0 ; row < totalRow; ++row)
			{
				for (int col = 0 ; col < totalCol - 1; ++col)
				{
					int index_0_0 = row *  totalCol + col;
					int index_0_1 = (row + 1) *  totalCol + col;
					int index_0_2 = row *  totalCol + col + 1;

					int index_1_0 = row *  totalCol + col + 1;
					int index_1_1 = (row + 1) *  totalCol + col;
					int index_1_2 = (row + 1) *  totalCol + col + 1;

					this->mpRenderObject->index(index_0_0);
					this->mpRenderObject->index(index_0_1);
					this->mpRenderObject->index(index_0_2);

					this->mpRenderObject->index(index_1_0);
					this->mpRenderObject->index(index_1_1);
					this->mpRenderObject->index(index_1_2);
				}
			}

			mpRenderObject->end();
#endif

			if (this->ref_mpGeoSceneManager)
			{
				this->ref_mpGeoSceneManager->getRootSceneNode()->createChildSceneNode()->attachObject(this->mpRenderObject);
			}
		}

	}}