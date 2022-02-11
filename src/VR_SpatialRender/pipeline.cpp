

#include "vrmine/vr_spatialrender/lanewaypiperender/pipeline.h"
#include "vrmine/vr_spatialobject/base/geoline.h"
#include "vrmine/vr_geometry/geometry/line.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_style/style/linestyle.h"
#include "vrmine/vr_style/style/pipestyle.h"

using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Base;
using namespace VirtualMine::Geometry;
using namespace VirtualMine::Style;

namespace VirtualMine
{
	namespace BaseRender
	{
		CPipeLine::CPipeLine()
			:mpRenderableObject(NULL),mGeneID(0)
		{

		}

		CPipeLine::~CPipeLine()
		{
			this->dispose();
		}

		void CPipeLine::convertGeoLineToRenderData(CShotHoleGeoLine* pGeoLine)
		{
			CLine* pLine = dynamic_cast<CLine*>(pGeoLine->getGeometry());
			size_t pointCount = pLine->getCount();
			if (NULL == pLine || pointCount != 2)
				return ;
			//CLineStyle* pStyle = dynamic_cast<CLineStyle*>(pGeoLine->getStyle());	
			CPipeLineStyle* pStyle = dynamic_cast<CPipeLineStyle*>(pGeoLine->getStyle());
			
			std::string matName("pipelineMat");//pipeline
			Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().getByName(matName, VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			if (!material->isLoaded())
			{
				material->load();
			}

			VirtualMine::SpatialInterface::CGeoExtentionData* data = new VirtualMine::SpatialInterface::CGeoExtentionData(this->ref_mpGeoSceneManager);
			this->mpRenderableObject = this->ref_mpGeoSceneManager->createManualObject(Ogre::StringConverter::toString(mGeneID));
			mGeneID++; 
			Ogre::Any any((VirtualMine::Core::CBaseObject*)pGeoLine);
			this->mpRenderableObject->setUserAny(any);
			data->setExtentionData(this->mpRenderableObject);
			data->setOwnerObject(pGeoLine);
			this->mDataVector.push_back(data);

			this->mpRenderableObject->begin(matName,Ogre::RenderOperation::OT_TRIANGLE_LIST,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			//构建顶点
			CPoint& point1 = pLine->getPoint(0);
			CPoint& point2 = pLine->getPoint(1);
			Ogre::Vector3 pt1(point1.getX(),point1.getY(),point1.getZ());
			Ogre::Vector3 pt2(point2.getX(),point2.getY(),point2.getZ());
			Ogre::Vector3 dir = pt2 - pt1;
			Ogre::Real length = dir.normalise();
			Ogre::Vector3 upDir = Ogre::Vector3::UNIT_Y;
			Ogre::Vector3 verticalDir = upDir.crossProduct(dir);
			verticalDir.normalise();
			
			Ogre::Vector3 beginRotatePt = pt1 + verticalDir * pStyle->getWidth();
			//beginRotatePt绕dir旋转得到周边点坐标
			int pointNum = 50;//kk表示管的圆滑度的，越大越圆滑
			Ogre::Real perAngle = Ogre::Math::TWO_PI / (Ogre::Real)pointNum;
			CoorVector vertices;//共42个点
			for (int i =0; i <= pointNum;++i)
			{
				Ogre::Radian rotateAngle = Ogre::Radian(i * perAngle);
				Ogre::Quaternion q ;
				q.FromAngleAxis(rotateAngle,dir);
				Ogre::Vector3 destDir = q * verticalDir;
				Ogre::Vector3 destPoint = pt1 + destDir * pStyle->getWidth();
				vertices.push_back(destPoint);
			}
			//一共19 * 2个三角面
			int curPointCount = 0;
			////侧面 管的面
			for (int i = 0 ; i < pointNum ; ++i)
			{
				Ogre::Vector3 leftPt = vertices.at(i);
				Ogre::Vector3 rightPt = vertices.at(i+1);

				Ogre::Vector3 nextLeftPt = leftPt + dir * length;
				Ogre::Vector3 nextRightPt = rightPt + dir * length;
				//构建顶点
				//Ogre::Vector3 leftNormal = leftPt-pt1;
				//leftNormal.normalise();
				//Ogre::Vector3 rightNormal = leftNormal;//rightPt-pt1;
				//rightNormal.normalise();
				//计算法线
				Ogre::Vector3 dir1 = dir;
				Ogre::Vector3 dir2 = rightPt - nextLeftPt;
				dir1.normalise();
				dir2.normalise();
				Ogre::Vector3 normal = dir1.crossProduct(dir2);
				normal.normalise();

				this->mpRenderableObject->position(leftPt);
				this->mpRenderableObject->colour(pStyle->getColor());
				this->mpRenderableObject->normal(normal);

				this->mpRenderableObject->position(nextLeftPt);
				this->mpRenderableObject->colour(pStyle->getColor());
				this->mpRenderableObject->normal(normal);

				this->mpRenderableObject->position(rightPt);
				this->mpRenderableObject->colour(pStyle->getColor());
				this->mpRenderableObject->normal(normal);

				this->mpRenderableObject->position(nextRightPt);
				this->mpRenderableObject->colour(pStyle->getColor());
				this->mpRenderableObject->normal(normal);
				
				//构建索引
				this->mpRenderableObject->index(0 +curPointCount);
				this->mpRenderableObject->index(1 +curPointCount);
				this->mpRenderableObject->index(2 +curPointCount);

				this->mpRenderableObject->index(2 +curPointCount);
				this->mpRenderableObject->index(1 +curPointCount);
				this->mpRenderableObject->index(3 +curPointCount);
				curPointCount = curPointCount + 4;
			}
			//kk管的两头
			//起始面
			this->mpRenderableObject->position(pt1);
			this->mpRenderableObject->colour(pStyle->getColor());
			this->mpRenderableObject->normal(-dir);
			for (int i = 0 ; i <= pointNum ; ++i)
			{
				Ogre::Vector3 curPt = vertices.at(i);
				this->mpRenderableObject->position(curPt);
				this->mpRenderableObject->colour(pStyle->getColor());
				this->mpRenderableObject->normal(-dir);

				if (i < pointNum)
				{
					this->mpRenderableObject->index(curPointCount);
					this->mpRenderableObject->index(curPointCount + i + 1);
					this->mpRenderableObject->index(curPointCount + i + 2);
				}
			}
			curPointCount += (pointNum + 2);
			////终止面
			this->mpRenderableObject->position(pt2);
			this->mpRenderableObject->colour(pStyle->getColor());
			this->mpRenderableObject->normal(dir);
			for (int i = 0 ; i <= pointNum ; ++i)
			{
				Ogre::Vector3 pt = vertices.at(i);
				Ogre::Vector3 nextPt = pt + dir * length;
				this->mpRenderableObject->position(nextPt);
				this->mpRenderableObject->colour(pStyle->getColor());
				this->mpRenderableObject->normal(dir);

				if (i < pointNum)
				{
					this->mpRenderableObject->index(curPointCount);
					this->mpRenderableObject->index(curPointCount + i + 1);
					this->mpRenderableObject->index(curPointCount + i + 2);
				}
			}
			this->mpRenderableObject->end();
		}

		void CPipeLine::build()
		{
			if (NULL != this->mpRenderableObject)
			{
				if (this->mpRenderableObject->getParentNode())
				{
					this->mpRenderableObject->detachFromParent();
				}
				this->ref_mpGeoSceneManager->destroyManualObject(this->mpRenderableObject);
				this->mpRenderableObject = NULL;
			}
			if (mGeoObjectVector.size() < 1)
				return;
			//this->mpRenderableObject = this->ref_mpGeoSceneManager->createManualObject();

			//kk  mGeoObjectVector中有261个IGeoObject，因为zhuangyao、shuipaoni、fengni各需要一个IGeoObject，所以87行的数据组成了261个IGeoObject。
			GeoObjectVector::iterator bItr = this->mGeoObjectVector.begin();
			GeoObjectVector::iterator eItr = this->mGeoObjectVector.end();
	
			while (bItr != eItr)
			{
				/*CGeoLine* pGeoLine = dynamic_cast<CGeoLine*>(*bItr);
				if (pGeoLine)
				{
					this->convertGeoLineToRenderData(pGeoLine);
				}
				++bItr;*/
				CShotHoleGeoLine* pGeoLine = dynamic_cast<CShotHoleGeoLine*>(*bItr);
			
				if (pGeoLine)
				{
					this->convertGeoLineToRenderData(pGeoLine);
				}
				++bItr;

			}
			
		}

		void CPipeLine::render()
		{
		
#if 0
			if (this->mpNode)
			{
				Ogre::SceneNode* sceneNode = dynamic_cast<Ogre::SceneNode*>(this->mpNode);
				if (sceneNode)
				{
					sceneNode->attachObject(this->mpRenderableObject);
				}
			} 
#else
			Ogre::SceneNode* sceneNode = dynamic_cast<Ogre::SceneNode*>(this->getNode());
			for (std::vector<CGeoExtentionData*>::iterator ite = this->mDataVector.begin();ite!=this->mDataVector.end();ite++)
			{
				CGeoExtentionData* geoExtentionData = (*ite);
				//CGeoInstanceExtentionData* data = (CGeoInstanceExtentionData*) geoExtentionData; 

				sceneNode->attachObject(geoExtentionData->getExtentionData());
			}

			//kk自己加的代码
			//Scene代码如下：
			//Ogre::ManualObject* cube;
			//cube = ref_mpGeoSceneManager->createManualObject("cube");
			//cube->begin("cubeMaterial");

			//// 顶点
			//cube->position( -20, -20, -120);   //0
			//cube->colour(0.0, 0.0, 0.0);
			//cube->position( 20, -20, -120);    //1
			//cube->colour(1.0, 0.0, 0.0);
			//cube->position( 20, -20, -100);    //2
			//cube->colour(1.0, 0.0, 1.0);
			//cube->position( -20, -20, -100);    //3
			//cube->colour(0.0, 0.0, 1.0);
			//cube->position( -20, 20, -120);    //4
			//cube->colour(0.0, 1.0, 0.0);
			//cube->position( 20, 20, -120);    //5
			//cube->colour(1.0, 1.0, 0.0);
			//cube->position( 20, 20, -100);    //6
			//cube->colour(1.0, 1.0, 1.0);
			//cube->position( -20, 20, -100);    //7
			//cube->colour(0.0, 1.0, 1.0);

			//cube->triangle(0, 2, 1);
			//cube->triangle(0, 2, 3);
			//cube->triangle(3, 4, 0);
			//cube->triangle(3, 7, 4);
			//cube->triangle(4, 7, 6);
			//cube->triangle(4, 6, 5);
			//cube->triangle(5, 2, 1);
			//cube->triangle(5, 6, 2);
			//cube->triangle(0, 4, 1);
			//cube->triangle(5, 1, 4);
			//cube->triangle(3, 6, 7);
			//cube->triangle(3, 2, 6);

			//cube->end();
			//sceneNode->attachObject(cube); 
#endif
			
		}

		void CPipeLine::dispose()
		{
			if (NULL != this->mpRenderableObject)
			{
				/*if (this->mpRenderableObject->getParentNode())
				{
					this->mpRenderableObject->detachFromParent();
				}
				this->ref_mpGeoSceneManager->destroyManualObject(this->mpRenderableObject);*/
				this->mpRenderableObject = NULL;
			}

			/*for (size_t i = 0 ; i < this->mGeoObjectVector.size(); ++i)
			{
			IGeoObject* pGeoObject = this->mGeoObjectVector.at(i);
			SAFE_DELETE(pGeoObject);
			}
			this->mGeoObjectVector.clear();*/
		}

		Ogre::ManualObject* CPipeLine::getRenderableObject()
		{
			return mpRenderableObject;
		}

		void CPipeLine::transferGeoObjectsToGeoDats( VirtualMine::SpatialInterface::GeoObjectVector objVec,std::vector<VirtualMine::SpatialInterface::CGeoExtentionData*>&geoDatas )
		{
			if (objVec.size() == 0)
			{
				return;
			}


			for (size_t num = 0 ; num < objVec.size(); ++num)
			{

				VirtualMine::Base::CShotHoleGeoLine* pShotHoleObject = dynamic_cast<VirtualMine::Base::CShotHoleGeoLine*>(objVec[num]);

				VirtualMine::Style::CPipeLineStyle* pStyle = dynamic_cast<VirtualMine::Style::CPipeLineStyle*>(pShotHoleObject->getStyle());

				VirtualMine::SpatialInterface::CGeoExtentionData* data = new VirtualMine::SpatialInterface::CGeoExtentionData(this->ref_mpGeoSceneManager);
				Ogre::ManualObject* renderObject = this->ref_mpGeoSceneManager->createManualObject(Ogre::StringConverter::toString(num));
				Ogre::Any any((VirtualMine::Core::CBaseObject*)pShotHoleObject);
				renderObject->setUserAny(any);
				data->setExtentionData(renderObject);
				geoDatas.push_back(data);
			}


		}

		

	}
}