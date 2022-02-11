

#include "vrmine/vr_spatialrender/lanewaypiperender/lanewayrenderforbang.h"
#include "vrmine/vr_spatialobject/base/geoline.h"
#include "vrmine/vr_geometry/geometry/line.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_spatialobject/mine/lanwayobject.h"
#include "vrmine/vr_style/style/lanewaystyle.h"

using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Base;
using namespace VirtualMine::Geometry;
using namespace VirtualMine::Style;
using namespace VirtualMine::Mine;


namespace VirtualMine
{
	namespace BaseRender
	{
		CLanewayRenderForBang::CLanewayRenderForBang()
			:mpRenderableObject(NULL)
		{

		}

		CLanewayRenderForBang::~CLanewayRenderForBang()
		{
			this->dispose();
		}

		
		void CLanewayRenderForBang::build()
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
			this->mpRenderableObject = this->ref_mpGeoSceneManager->createManualObject("LanewaySection");

			GeoObjectVector::iterator bItr = this->mGeoObjectVector.begin();
			GeoObjectVector::iterator eItr = this->mGeoObjectVector.end();
			while (bItr != eItr)
			{
				CLaneWayObject* pGeoObj = dynamic_cast<CLaneWayObject*>(*bItr);
				if (pGeoObj)
				{
					this->createLanewayForBang(pGeoObj);
				}
				++bItr;
			}
		}

		void CLanewayRenderForBang::render()
		{
			Ogre::SceneNode* sceneNode = dynamic_cast<Ogre::SceneNode*> (this->getNode());


			if (this->mpNode)
			{
				Ogre::SceneNode* sceneNode = dynamic_cast<Ogre::SceneNode*>(this->mpNode);
				if (sceneNode)
				{
					sceneNode->attachObject(this->mpRenderableObject);
				}
			} 
#if 0
			for (std::vector<CGeoExtentionData*>::iterator ite = this->mDataVector.begin();ite!=this->mDataVector.end();ite++)
			{
				CGeoExtentionData* geoExtentionData = (*ite);
				//CGeoInstanceExtentionData* data = (CGeoInstanceExtentionData*) geoExtentionData; 

				sceneNode->attachObject(geoExtentionData->getExtentionData());
			}
#endif			
		}

		void CLanewayRenderForBang::dispose()
		{
			if (NULL != this->mpRenderableObject)
			{
				/*if (this->mpRenderableObject->getParentNode())
				{
					this->mpRenderableObject->detachFromParent();
				}
				this->ref_mpGeoSceneManager->destroyManualObject(this->mpRenderableObject);
			*/	this->mpRenderableObject = NULL;
			}

			/*for (size_t i = 0 ; i < this->mGeoObjectVector.size(); ++i)
			{
			IGeoObject* pGeoObject = this->mGeoObjectVector.at(i);
			SAFE_DELETE(pGeoObject);
			}
			this->mGeoObjectVector.clear();*/
		}

		void CLanewayRenderForBang::createLanewayForBang(VirtualMine::Mine::CLaneWayObject* pGeoObject)
		{
			int count=(int)(180.0f/10.0f);
			int countCircle=(int)(360.0/17.14f);
			float scale = 5.5;

			CLanewayStyle* pStyle= dynamic_cast<CLanewayStyle*>(pGeoObject->getStyle());	
			if (pStyle->getSectionType() == VirtualMine::Style::Arch)
			{
				Ogre::Real width = pStyle->getWidth()*scale*0.5;
				Ogre::Real height = pStyle->getHeight()*scale;
				int vec3Size = (count+4)*2;
				Ogre::Vector3* points=new Ogre::Vector3[vec3Size];
				Ogre::Vector3* facePoints = new Ogre::Vector3[vec3Size];

				points[0].x=width; 
				points[0].y=0;
				points[0].z=0;

				points[1].x=width;
				points[1].y=-height+scale;
				points[1].z=0;

				points[2].x=-width;
				points[2].y=-height+scale;
				points[2].z=0;

				points[3].x=-width;
				points[3].y=0;
				points[3].z=0;

				Ogre::Vector3 forward = Ogre::Vector3::UNIT_Z;

				for(int i=0;i<count;i++)
				{
					Ogre::Quaternion q;
					q.FromAngleAxis(Ogre::Radian(-10.0f*(i+1)*Ogre::Math::PI/180),forward);
					points[4+i] = q * points[3];
					//points[4+i].y+=height;

				}
				for (int i=0;i<vec3Size/2;i++)
				{
					points[22+i].x = points[i].x;
					points[22+i].y = points[i].y;
					points[22+i].z = points[i].z-height*2;

				}

				for (int i=0;i<vec3Size;i++)
				{
					facePoints[i].x=points[i].x;
					facePoints[i].y=points[i].y;
					facePoints[i].z=points[i].z;

				}

				std::string matName("terraneSiderMaterial");
				Ogre::MaterialPtr material = Ogre::MaterialManager::getSingletonPtr()->getByName(matName,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				if (!material.isNull())
				{
					Ogre::Pass* pass = material->getTechnique(0)->getPass(0);
					pass->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);
					pass->setCullingMode(Ogre::CULL_NONE);
					Ogre::TextureUnitState* state = pass->getTextureUnitState(0);//->createTextureUnitState("fault.png");
					state->setAlphaOperation(Ogre::LBX_MODULATE,Ogre::LBS_TEXTURE,Ogre::LBS_MANUAL,1.0,0.5);
					material->load();
				}
				VirtualMine::SpatialInterface::CGeoExtentionData* siderData = new VirtualMine::SpatialInterface::CGeoExtentionData(this->ref_mpGeoSceneManager);
				siderData->setExtentionData(mpRenderableObject);

				this->mpRenderableObject->begin(matName,Ogre::RenderOperation::OT_TRIANGLE_LIST,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				for (int i = 0; i<vec3Size;i++)
				{
					mpRenderableObject->position(points[i]);
					//lanewayFaceRenderObj->position(facePoints[i]);

					if (i<22)
					{
						if (i == 0)
						{
							mpRenderableObject->textureCoord(0,0);
							//lanewayFaceRenderObj->textureCoord(0,0);
						}
						else if (i == 1)
						{
							mpRenderableObject->textureCoord(0,0.25);
							//lanewayFaceRenderObj->textureCoord(0,0.25);
						}
						else if (i == 2)
						{
							mpRenderableObject->textureCoord(0,0.5);
							//lanewayFaceRenderObj->textureCoord(0,0.5);
						}
						else if (i == 3)
						{
							mpRenderableObject->textureCoord(0,0.75);
							//lanewayFaceRenderObj->textureCoord(0,0.75);
						}
						else if (i>3)
						{
							mpRenderableObject->textureCoord(0,0.75 + (i-3)*0.25/18);
							//lanewayFaceRenderObj->textureCoord(0,1);
						}
					}
					else if(i > 21)
					{
						if (i == 22)
						{
							mpRenderableObject->textureCoord(width,0);
							//lanewayFaceRenderObj->textureCoord(1,0);
						}
						else if (i == 23)
						{
							mpRenderableObject->textureCoord(width,0.25);
							//lanewayFaceRenderObj->textureCoord(1,0.25);
						}
						else if (i == 24)
						{
							mpRenderableObject->textureCoord(width,0.5);
							//lanewayFaceRenderObj->textureCoord(1,0.5);
						}
						else if (i == 25)
						{
							mpRenderableObject->textureCoord(width,0.75);
							//lanewayFaceRenderObj->textureCoord(1,0.75);
						}
						else if (i > 25)
						{
							mpRenderableObject->textureCoord(width,0.75 + (i-25)*0.25/18);
							//lanewayFaceRenderObj->textureCoord(1,1);
						}
					}

				}

				for (int i=0;i<(vec3Size/2-1);i++)
				{
					mpRenderableObject->triangle(i,i+1,i+vec3Size/2);
					mpRenderableObject->triangle(i+1,i+vec3Size/2,i+vec3Size/2+1);

				}

				
				//////////////////////////////////////////////////////////////////////////
				//起始面
				int curIndex = 44;

				for (int i = 0 ;i < (vec3Size/2) ;i++)
				{
					mpRenderableObject->position(points[i]);

				}
				for (int i=0;i < (vec3Size/2-1);i++)
				{
					mpRenderableObject->triangle(curIndex,i+1+curIndex,i+2+curIndex);
					
				}
				//////////////////////////////////////////////////////////////////////////
				//终止面
				curIndex=66;
				for (int i=0;i<vec3Size;i++)
				{
					mpRenderableObject->position(points[i+vec3Size/2]);

				}
				for (int i=0;i < (vec3Size/2-1);i++)
				{
					mpRenderableObject->triangle(curIndex,i+1+curIndex,i+2+curIndex);
					
				}


				/*for (int i=0;i<vec3Size/2-1;i++)
				{
				lanewayFaceRenderObj->triangle(0,i+1,i+2);
				lanewayFaceRenderObj->triangle(22,22+i,23+i);
				}*/
				//VirtualMine::Mine::CLaneWayObject* lanewaySectionObj = new VirtualMine::Mine::CLaneWayObject();
				VirtualMine::Style::CLanewayStyle* lanewaySectionStyle = dynamic_cast<VirtualMine::Style::CLanewayStyle*>(pGeoObject->getStyle());
				lanewaySectionStyle->setSectionType(VirtualMine::Style::Arch);
				lanewaySectionStyle->setWidth(5.4);
				lanewaySectionStyle->setHeight(2.7);


				Ogre::Any sideAny((VirtualMine::Core::CBaseObject*)pGeoObject);
				mpRenderableObject->setUserAny(sideAny);

				mDataVector.push_back(siderData);

				mpRenderableObject->end();
			}

		}

	}
}