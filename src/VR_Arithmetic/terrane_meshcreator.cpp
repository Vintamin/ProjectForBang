
#include "vrmine/vr_arithmetic/arithmetic/terrane_meshcreator.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_spatialobject/mine/terraneobject.h"
#include "vrmine/vr_spatialobject/geoproperty/terraneproperty.h"
#include "vrmine/vr_spatialinterface/parameter.h"
#include "vrmine/vr_geometry/geometry/terrane.h"
#include "vrmine/vr_style/style/terranestyle.h"
#include "vrmine/vr_arithmetic/arithmetic/geometryarithmeticlibrary.h"
#include <OGRE/OgreBlendMode.h>
#include "vrmine/vr_spatialinterface/iscene.h"
#include "vrmine/vr_arithmetic/arithmetic/Delaunaymath.h"

using namespace std;

namespace VirtualMine
{
	namespace Arithmetic
	{
		CTerrane_MeshCreator::CTerrane_MeshCreator()
		{
			this->setType(VirtualMine::Core::GeoDataType::GDT_TERRANE);
		}

		CTerrane_MeshCreator::~CTerrane_MeshCreator()
		{

		}

		void CTerrane_MeshCreator::createData(VirtualMine::SpatialInterface::GeoObjectVector& geoObjectVector,std::vector<VirtualMine::SpatialInterface::CGeoExtentionData*>& geoExtentionDatas)
		{
			if (geoObjectVector.size() == 0)
			{
				return;
			}

			int terraneCount = geoObjectVector.size();
			if (terraneCount < 1)
			{
				return;
			}

			
			std::vector<string> terraneName; //记录岩层的名字

			for (int m = 0;  m < terraneCount;m++)
			{
				//orderTerrane = m;
				//

				VirtualMine::Mine::CTerraneObject* terraneObject = dynamic_cast<VirtualMine::Mine::CTerraneObject*>(geoObjectVector[m]);
				if (terraneObject == NULL)
				{
					return;
				}
				VirtualMine::Geometry::CTerraneGeometry* terraneGeometry = dynamic_cast<VirtualMine::Geometry::CTerraneGeometry*>(terraneObject->getGeometry());
				VirtualMine::GeoProperty::CTerraneProperty* terraneProperty = dynamic_cast<VirtualMine::GeoProperty::CTerraneProperty*>(terraneObject->getGeoProperty());
				VirtualMine::Style::CTerraneStyle* terraneStyle = dynamic_cast<VirtualMine::Style::CTerraneStyle*>(terraneObject->getStyle());

				VirtualMine::SpatialInterface::CGeoExtentionData* data = new VirtualMine::SpatialInterface::CGeoExtentionData();

				string tempName = terraneProperty->getName();
				terraneName.push_back(tempName);

				Ogre::ManualObject* renderObject = this->ref_mpSceneMgr->createManualObject(terraneProperty->getName());
				data->setExtentionData(renderObject);
				data->setOwnerObject(terraneObject);
				data->setSceneManager(this->ref_mpSceneMgr);
				Ogre::Any any((VirtualMine::Core::CBaseObject*)terraneObject);
				renderObject->setUserAny(any);

				geoExtentionDatas.push_back(data);

				std::vector<Ogre::Vector3> coors;
				IntVector indexes;

				if (terraneGeometry!= NULL && terraneProperty!=NULL && terraneStyle !=NULL)
				{
					if (m==0)
					{
						//Ogre::MaterialPtr material = Ogre::MaterialManager::getSingletonPtr()->create("terraneUpMaterial",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
						
						Ogre::MaterialPtr material = Ogre::MaterialManager::getSingletonPtr()->getByName("terraneUpMaterial",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);

						if (!material.isNull())
						{
						Ogre::Pass* pass = material->getTechnique(0)->getPass(0);
						pass->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);
						pass->setCullingMode(Ogre::CULL_NONE);
						
						material->load();
						}

						renderObject->begin("terraneUpMaterial", Ogre::RenderOperation::OT_TRIANGLE_LIST,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);

					}
					else
					{
						Ogre::MaterialPtr material = Ogre::MaterialManager::getSingletonPtr()->getByName("terraneDownMaterial",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);

						if (!material.isNull())
						{
							Ogre::Pass* pass = material->getTechnique(0)->getPass(0);
							pass->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);
							pass->setCullingMode(Ogre::CULL_NONE);
							//Ogre::TextureUnitState* state = pass->createTextureUnitState("fault2.png");
							//state->setAlphaOperation(Ogre::LBX_MODULATE,Ogre::LBS_TEXTURE,Ogre::LBS_MANUAL,1.0,0.5);
							material->load();
						}

						renderObject->begin("terraneDownMaterial", Ogre::RenderOperation::OT_TRIANGLE_LIST,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);

					}

					for (int i = 0;i<terraneGeometry->getCount();i++)
					{
						VirtualMine::Geometry::CPoint point = terraneGeometry->getPoint(i);
						Ogre::Vector3 realPoint = Ogre::Vector3(point.getX(),point.getY(),point.getZ()*(-1));/////ogre的z轴朝向屏幕外
						renderObject->position(realPoint);
						
						Ogre::Vector3 planePoint = realPoint;
						planePoint.y = 0;
						coors.push_back(planePoint);
						tempVec2.push_back(realPoint);
					}

#if 1 记录岩层边界点
					if (tempVec2.size() < 1)
					{
						return;
					}
				

					int tempcount = m*borderNodesCount*borderNodesCount;
					for (int i = 0 ;i < borderNodesCount; i++)
					{
						boderNodes.push_back(tempVec2[i+tempcount]);  //up

					}
					for (int i = 0 ;i < borderNodesCount; i++)
					{
						boderNodes.push_back(tempVec2[(i+1)*borderNodesCount-1+tempcount]);  //right

					}
					for (int i = 0 ;i < borderNodesCount; i++)
					{
						boderNodes.push_back(tempVec2[borderNodesCount*borderNodesCount-1-i+tempcount]);  //down


					}
					for (int i = 0 ;i < borderNodesCount; i++)
					{
						boderNodes.push_back(tempVec2[borderNodesCount*(borderNodesCount-1)-i*borderNodesCount+tempcount]);  //left

					}

#endif				
					////VirtualMine::Arithmetic::CGeometryArithmeticLibrary::createTINData(coors,indexes);

					/*	for (int i = 0;i<indexes.size()/3;i++)
					{
					renderObject->triangle(indexes[3*i],indexes[3*i+1],indexes[3*i+2]);
					}*/


					/*	for (int indexcol = 0; indexcol<borderNodesCount ;indexcol++)
					{
					for(int index = 0; index < borderNodesCount ; index++)
					{
					renderObject->textureCoord(indexcol*(1/(borderNodesCount-1)),index*(1/(borderNodesCount-1)));

					}
					}*/

					/*VirtualMine::Geometry::CPoint upLeftPt;
					VirtualMine::Geometry::CPoint downRightPt;
					terraneGeometry->computeRectangle(upLeftPt,downRightPt);
					float widthTemp = downRightPt.getX() - upLeftPt.getX();
					float heightTemp = downRightPt.getZ() - upLeftPt.getZ();*/
					

					//for (int i = 0;i<terraneGeometry->getCount();i++)
					//{
					//	//renderObject->textureCoord(0.5,0.5);
					//	Ogre::Real u = (tempVec2[i].x-tempVec2[0].x)/widthTemp;
					//	Ogre::Real v = 1-(tempVec2[i].z-tempVec2[0].z)/heightTemp;
					//	renderObject->textureCoord(u,v);
					//}

#if 1
#pragma region 计算法线

					//计算法线
					//  c---d
					//  | \ |  索引 （a,b,c）(b,d,c)
					//  a---b
					//
					if ( m == 0 )  // 第一层岩层
					{
						for (int indexcol = 0; indexcol<borderNodesCount;indexcol++)
						{
							for(int index = 0; index < borderNodesCount; index++)
							{
								if (indexcol == borderNodesCount-1)
								{
									if (index ==  borderNodesCount-1)
									{
										int	a = (indexcol-1)*borderNodesCount+index-1;
										int b = (indexcol-1)*borderNodesCount+index;
										int c = indexcol*borderNodesCount+index-1;
										int d = indexcol*borderNodesCount+index;

										Ogre::Vector3 curPointA(tempVec2[a].x,tempVec2[a].y,tempVec2[a].z);
										Ogre::Vector3 curPointB(tempVec2[b].x,tempVec2[b].y,tempVec2[b].z);
										Ogre::Vector3 curPointC(tempVec2[c].x,tempVec2[c].y,tempVec2[c].z);
										Ogre::Vector3 curPointD(tempVec2[d].x,tempVec2[d].y,tempVec2[d].z);

										Ogre::Vector3 curPointRightVec = curPointC - curPointD;
										Ogre::Vector3 curPointLeftVec = curPointB - curPointD;
										Ogre::Vector3 curPointCrossVec = curPointRightVec.crossProduct(curPointLeftVec);
										curPointCrossVec.normalise();
										renderObject->normal(curPointCrossVec);
										//normalVec.push_back(curPointCrossVec);
									}
									else
									{
										int	a = (indexcol-1)*borderNodesCount+index;
										int b = (indexcol-1)*borderNodesCount+index+1;
										int c = indexcol*borderNodesCount+index;
										int d = indexcol*borderNodesCount+index+1;

										Ogre::Vector3 curPointA(tempVec2[a].x,tempVec2[a].y,tempVec2[a].z);
										Ogre::Vector3 curPointB(tempVec2[b].x,tempVec2[b].y,tempVec2[b].z);
										Ogre::Vector3 curPointC(tempVec2[c].x,tempVec2[c].y,tempVec2[c].z);
										Ogre::Vector3 curPointD(tempVec2[d].x,tempVec2[d].y,tempVec2[d].z);

										Ogre::Vector3 curPointRightVec = curPointA - curPointC;
										Ogre::Vector3 curPointLeftVec = curPointB - curPointC;
										Ogre::Vector3 curPointCrossVec = curPointRightVec.crossProduct(curPointLeftVec);
										curPointCrossVec.normalise();
										renderObject->normal(curPointCrossVec);
										//normalVec.push_back(curPointCrossVec);
									}

								}

								else
								{
									if (index == borderNodesCount-1)
									{
										int	a = indexcol*borderNodesCount+index-1;
										int b = indexcol*borderNodesCount+index;
										int c = (indexcol+1)*borderNodesCount+index-1;
										int d = (indexcol+1)*borderNodesCount+index;

										Ogre::Vector3 curPointA(tempVec2[a].x,tempVec2[a].y,tempVec2[a].z);
										Ogre::Vector3 curPointB(tempVec2[b].x,tempVec2[b].y,tempVec2[b].z);
										Ogre::Vector3 curPointC(tempVec2[c].x,tempVec2[c].y,tempVec2[c].z);
										Ogre::Vector3 curPointD(tempVec2[d].x,tempVec2[d].y,tempVec2[d].z);

										Ogre::Vector3 curPointRightVec = curPointD - curPointB;
										Ogre::Vector3 curPointLeftVec = curPointC - curPointB;
										Ogre::Vector3 curPointCrossVec = curPointRightVec.crossProduct(curPointLeftVec);
										curPointCrossVec.normalise();
										renderObject->normal(curPointCrossVec);
										//normalVec.push_back(curPointCrossVec);
									}
									else
									{
										int	a = indexcol*borderNodesCount+index;
										int b = indexcol*borderNodesCount+index+1;
										int c = (indexcol+1)*borderNodesCount+index;
										int d = (indexcol+1)*borderNodesCount+index+1;

										Ogre::Vector3 curPointA(tempVec2[a].x,tempVec2[a].y,tempVec2[a].z);
										Ogre::Vector3 curPointB(tempVec2[b].x,tempVec2[b].y,tempVec2[b].z);
										Ogre::Vector3 curPointC(tempVec2[c].x,tempVec2[c].y,tempVec2[c].z);
										Ogre::Vector3 curPointD(tempVec2[d].x,tempVec2[d].y,tempVec2[d].z);

										Ogre::Vector3 curPointRightVec = curPointB - curPointA;
										Ogre::Vector3 curPointLeftVec = curPointC - curPointA;
										Ogre::Vector3 curPointCrossVec = curPointRightVec.crossProduct(curPointLeftVec);
										curPointCrossVec.normalise();
										renderObject->normal(curPointCrossVec);
										//normalVec.push_back(curPointCrossVec);
									}


								}

							}

						}
					}

					else if ( m == terraneCount-1)  //最后一层岩层
					{
						for (int indexcol = 0; indexcol<borderNodesCount;indexcol++)
						{
							for(int index = 0; index < borderNodesCount; index++)
							{
								if (indexcol == borderNodesCount-1)
								{
									if (index ==  borderNodesCount-1)
									{
										int	a = (indexcol-1)*borderNodesCount+index-1;
										int b = (indexcol-1)*borderNodesCount+index;
										int c = indexcol*borderNodesCount+index-1;
										int d = indexcol*borderNodesCount+index;

										Ogre::Vector3 curPointA(tempVec2[a].x,tempVec2[a].y,tempVec2[a].z);
										Ogre::Vector3 curPointB(tempVec2[b].x,tempVec2[b].y,tempVec2[b].z);
										Ogre::Vector3 curPointC(tempVec2[c].x,tempVec2[c].y,tempVec2[c].z);
										Ogre::Vector3 curPointD(tempVec2[d].x,tempVec2[d].y,tempVec2[d].z);

										Ogre::Vector3 curPointRightVec = curPointC - curPointD;
										Ogre::Vector3 curPointLeftVec = curPointB - curPointD;
										Ogre::Vector3 curPointCrossVec = curPointLeftVec.crossProduct(curPointRightVec);
										curPointCrossVec.normalise();
										renderObject->normal(curPointCrossVec);
										//normalVec.push_back(curPointCrossVec);
									}
									else
									{
										int	a = (indexcol-1)*borderNodesCount+index;
										int b = (indexcol-1)*borderNodesCount+index+1;
										int c = indexcol*borderNodesCount+index;
										int d = indexcol*borderNodesCount+index+1;

										Ogre::Vector3 curPointA(tempVec2[a].x,tempVec2[a].y,tempVec2[a].z);
										Ogre::Vector3 curPointB(tempVec2[b].x,tempVec2[b].y,tempVec2[b].z);
										Ogre::Vector3 curPointC(tempVec2[c].x,tempVec2[c].y,tempVec2[c].z);
										Ogre::Vector3 curPointD(tempVec2[d].x,tempVec2[d].y,tempVec2[d].z);

										Ogre::Vector3 curPointRightVec = curPointA - curPointC;
										Ogre::Vector3 curPointLeftVec = curPointB - curPointC;
										Ogre::Vector3 curPointCrossVec = curPointLeftVec.crossProduct(curPointRightVec);
										curPointCrossVec.normalise();
										renderObject->normal(curPointCrossVec);
										//normalVec.push_back(curPointCrossVec);
									}

								}

								else
								{
									if (index == borderNodesCount-1)
									{
										int	a = indexcol*borderNodesCount+index-1;
										int b = indexcol*borderNodesCount+index;
										int c = (indexcol+1)*borderNodesCount+index-1;
										int d = (indexcol+1)*borderNodesCount+index;

										Ogre::Vector3 curPointA(tempVec2[a].x,tempVec2[a].y,tempVec2[a].z);
										Ogre::Vector3 curPointB(tempVec2[b].x,tempVec2[b].y,tempVec2[b].z);
										Ogre::Vector3 curPointC(tempVec2[c].x,tempVec2[c].y,tempVec2[c].z);
										Ogre::Vector3 curPointD(tempVec2[d].x,tempVec2[d].y,tempVec2[d].z);

										Ogre::Vector3 curPointRightVec = curPointD - curPointB;
										Ogre::Vector3 curPointLeftVec = curPointC - curPointB;
										Ogre::Vector3 curPointCrossVec = curPointLeftVec.crossProduct(curPointRightVec);
										curPointCrossVec.normalise();
										renderObject->normal(curPointCrossVec);
										//normalVec.push_back(curPointCrossVec);
									}
									else
									{
										int	a = indexcol*borderNodesCount+index;
										int b = indexcol*borderNodesCount+index+1;
										int c = (indexcol+1)*borderNodesCount+index;
										int d = (indexcol+1)*borderNodesCount+index+1;

										Ogre::Vector3 curPointA(tempVec2[a].x,tempVec2[a].y,tempVec2[a].z);
										Ogre::Vector3 curPointB(tempVec2[b].x,tempVec2[b].y,tempVec2[b].z);
										Ogre::Vector3 curPointC(tempVec2[c].x,tempVec2[c].y,tempVec2[c].z);
										Ogre::Vector3 curPointD(tempVec2[d].x,tempVec2[d].y,tempVec2[d].z);

										Ogre::Vector3 curPointRightVec = curPointB - curPointA;
										Ogre::Vector3 curPointLeftVec = curPointC - curPointA;
										Ogre::Vector3 curPointCrossVec = curPointLeftVec.crossProduct(curPointRightVec);
										curPointCrossVec.normalise();
										renderObject->normal(curPointCrossVec);
										//normalVec.push_back(curPointCrossVec);
									}

								}

							}

						}
					}

#pragma endregion 					

#endif

					for (int indexcol = 0; indexcol<borderNodesCount -1;indexcol++)
					{
						for(int index = 0; index < borderNodesCount -1; index++)
						{
						
							renderObject->triangle(indexcol*borderNodesCount+index,indexcol*borderNodesCount+index+1,(indexcol+1)*borderNodesCount+index);
							renderObject->triangle(indexcol*borderNodesCount+index+1, (indexcol+1)*borderNodesCount+index+1,(indexcol+1)*borderNodesCount+index);


						}
					}
					


					renderObject->end();
				}


			}

#if 1 侧面
			Ogre::MaterialPtr sideMaterial = Ogre::MaterialManager::getSingletonPtr()->getByName("terraneSiderMaterial",VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			if (!sideMaterial.isNull())
			{
				Ogre::Pass* pass = sideMaterial->getTechnique(0)->getPass(0);
				pass->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);
				pass->setCullingMode(Ogre::CULL_NONE);
				//Ogre::TextureUnitState* state = pass->createTextureUnitState("fault.png");
				//state->setAlphaOperation(Ogre::LBX_MODULATE,Ogre::LBS_TEXTURE,Ogre::LBS_MANUAL,1.0,0.5);
				sideMaterial->load();
			}


			for (int i = 0; i < terraneCount-1; i++)
			{
				Ogre::ManualObject* siderRenderObject = this->ref_mpSceneMgr->createManualObject(terraneName[i]+"_silder");
				
				siderRenderObject->begin("terraneSiderMaterial",Ogre::RenderOperation::OT_TRIANGLE_LIST,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
				VirtualMine::SpatialInterface::CGeoExtentionData* siderData = new VirtualMine::SpatialInterface::CGeoExtentionData();
				siderData->setExtentionData(siderRenderObject);
				siderData->setSceneManager(this->ref_mpSceneMgr);
				VirtualMine::Mine::CTerraneObject* pSideObject = new VirtualMine::Mine::CTerraneObject();
				//VirtualMine::Geometry::CTerraneGeometry* pTerraneGeometry = dynamic_cast<VirtualMine::Geometry::CTerraneGeometry*>(pSideObject->getGeometry()); 
			    VirtualMine::Style::CTerraneStyle* pTerraneStyle = dynamic_cast<VirtualMine::Style::CTerraneStyle*>(pSideObject->getStyle());
				VirtualMine::GeoProperty::CTerraneProperty* pTerraneProper = dynamic_cast<VirtualMine::GeoProperty::CTerraneProperty*>(pSideObject->getGeoProperty());
				pTerraneProper->setName("砂岩侧面");

				//构建顶点和索引
				int tempTerraneCount = boderNodes.size()/terraneCount; //每层边界点的个数
				for (int n = 0; n <2*tempTerraneCount;n++)
				{
					//Ogre::Vector3 tempVec3 = boderNodes[i+tempTerraneCount*(orderTerrane-1)];
					siderRenderObject->position(boderNodes[n+i*tempTerraneCount]);
					//siderRenderObject->textureCoord(0,n*(1.0/(tempTerraneCount-1)));

				}

				for (int k = 0;k<tempTerraneCount-1;k++)
				{
					siderRenderObject->triangle(k,k+1,tempTerraneCount+k);
					siderRenderObject->triangle(k+1,tempTerraneCount+1+k,tempTerraneCount+k);
				}


				Ogre::Any any2((VirtualMine::Core::CBaseObject*)pSideObject);
				siderRenderObject->setUserAny(any2);
				siderData->setOwnerObject(pSideObject);
				geoExtentionDatas.push_back(siderData);
				siderRenderObject->end();
			}

#endif			


		}

			//	    void CterraneSeam_MeshCreator::createData2(VirtualMine::SpatialInterface::GeoObjectVector& geoObjectVector,std::vector<VirtualMine::SpatialInterface::CGeoExtentionData*>& geoExtentionDatas)
			//		{
			//			if (geoObjectVector.size() == 0)
			//			{
			//				return;
			//			}
			//
			//			int terraneCount = geoObjectVector.size();
			//			if (terraneCount < 1)
			//			{
			//				return;
			//			}
			//
			//			//int orderTerrane; //地层编号
			//			for (int i = 0;  i < terraneCount;i++)
			//			{
			//				//orderTerrane = i; //
			//					VirtualMine::Mine::CterraneSeamObject* terraneObject = dynamic_cast<VirtualMine::Mine::CterraneSeamObject*>(geoObjectVector[i]);
			//			if (terraneObject == NULL)
			//			{
			//				return;
			//			}
			//			VirtualMine::Geometry::CterraneSeamGeometry* terraneGeometry = dynamic_cast<VirtualMine::Geometry::CterraneSeamGeometry*>(terraneObject->getGeometry());
			//			VirtualMine::GeoProperty::CterraneSeamProperty* terraneProperty = dynamic_cast<VirtualMine::GeoProperty::CterraneSeamProperty*>(terraneObject->getGeoProperty());
			//			VirtualMine::Style::CterraneSeamStyle* terraneStyle = dynamic_cast<VirtualMine::Style::CterraneSeamStyle*>(terraneObject->getStyle());
			//
			//			VirtualMine::SpatialInterface::CGeoExtentionData* data = new VirtualMine::SpatialInterface::CGeoExtentionData();
			//			Ogre::ManualObject* renderObject = this->ref_mpSceneMgr->createManualObject(terraneProperty->getName());
			//
			//
			//			Ogre::Any any((VirtualMine::Core::CBaseObject*)terraneObject);
			//			renderObject->setUserAny(any);
			//
			//			data->setExtentionData(renderObject);
			//
			//			geoExtentionDatas.push_back(data);
			//		
			//			//int row = terraneGeometry->getRow();
			//			//int column = terraneGeometry->getCol();
			//
			//			//Ogre::MaterialPtr material = Ogre::MaterialManager::getSingletonPtr()->create(terraneProperty->getName(),VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			//
			//			//if (!material.isNull())
			//			//{
			//			//	Ogre::Pass* pass = material->getTechnique(0)->getPass(0);		
			//			//	pass->setCullingMode(Ogre::CULL_NONE);
			//			//	pass->createTextureUnitState(terraneStyle->getTexture());
			//
			//			//	/*Ogre::Pass* pass2 = material->getTechnique(0)->createPass();
			//			//	pass2->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);
			//			//	pass2->setCullingMode(Ogre::CULL_NONE);
			//			//	Ogre::TextureUnitState* unitestate = new Ogre::TextureUnitState(pass2);
			//			//	pass2->addTextureUnitState(unitestate);*/
			//			//	material->load();
			//			//}
			//
			//			if (terraneGeometry!= NULL && terraneProperty!=NULL && terraneStyle !=NULL)
			//			{
			//				//renderObject->begin(terraneProperty->getName(), Ogre::RenderOperation::OT_TRIANGLE_LIST,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			//
			//				renderObject->begin("terraneMaterial", Ogre::RenderOperation::OT_TRIANGLE_LIST,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			//
			//				VirtualMine::Geometry::CPoint upLeftPt;
			//				VirtualMine::Geometry::CPoint downRightPt;
			//				terraneGeometry->computeRectangle(upLeftPt,downRightPt);
			//				float width = downRightPt.getX() - upLeftPt.getX();
			//				float height = downRightPt.getZ() - upLeftPt.getZ();
			//
			//				std::vector<De_point> depointVector;
			//			
			//				std::vector<De_point> transferVector;
			//				std::vector<De_point> renderVertor;
			//
			//				int count = terraneGeometry->getCount();
			//				for (int i = 0; i < count; i++)
			//				{
			//					VirtualMine::Geometry::CPoint point =	terraneGeometry->getPoint(i);
			//
			//					De_point dePoint;
			//					dePoint.X = point.getX();
			//					dePoint.Y = point.getY();
			//					dePoint.Z = point.getZ();
			//					depointVector.push_back(dePoint);
			//				}
			//
			//				//
			//				//for (int i = 0; i < count; i++)
			//				//{
			//				//	VirtualMine::Geometry::CPoint point =terraneGeometry->getPoint(i);
			//				//	De_point dePoint;
			//				//	dePoint.X = point.getX();
			//				//	dePoint.Y = point.getY();
			//				//	dePoint.Z = point.getZ();
			//				//	depointVector.push_back(dePoint);
			//
			//
			//				//	//获取边界点
			//				//	std::vector<Ogre::Vector3> tempVec;
			//				//	Ogre::Vector3 tempVec3;
			//				//	tempVec3.x = point.getX();
			//				//	tempVec3.y = point.getY();
			//				//	tempVec3.z = point.getZ();
			//
			//				//	tempVec.push_back(tempVec3);
			//
			//				//	for (i = 0 ;i < borderNodesCount; i++)
			//				//	{
			//				//		boderNodes.push_back(tempVec[i]);  //up
			//				//		boderNodes.push_back(tempVec[(i+1)*borderNodesCount-1]);  //right
			//				//		boderNodes.push_back(tempVec[i*borderNodesCount]);  //left
			//				//		boderNodes.push_back(tempVec[borderNodesCount*(borderNodesCount-1)+i]);  //down
			//
			//
			//				//	}
			//
			//				//}
			//
			//				//if (orderTerrane > 0)		
			//				//{
			//				//	Ogre::ManualObject* siderRenderObject = this->ref_mpSceneMgr->createManualObject(terraneProperty->getName());
			//				//	siderRenderObject->begin(terraneProperty->getName()+"_Material",Ogre::RenderOperation::OT_TRIANGLE_LIST,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
			//
			//				//	//构建顶点和索引
			//				//	int tempTerraneCount = boderNodes.size()/terraneCount; //每层边界点的个数
			//				//	for (int i = 0; i < boderNodes.size();i++)
			//				//	{
			//				//		Ogre::Vector3 tempVec3 = boderNodes[i+tempTerraneCount*(orderTerrane-1)];
			//				//		siderRenderObject->position(tempVec3);
			//				//		siderRenderObject->textureCoord(0,i*(1.0/(tempTerraneCount-1)));
			//
			//				//	}
			//				//	for (int j = 1;j < terraneCount+1; j++)
			//				//	{
			//				//		for (int i = 0;i<tempTerraneCount;i++)
			//				//		{
			//				//			siderRenderObject->triangle(i,i+1,tempTerraneCount*j+1+i);
			//				//			siderRenderObject->triangle(i+1,tempTerraneCount*j+1+i,tempTerraneCount*j+2+i);
			//				//		}
			//				//	}
			//
			//				//	siderRenderObject->end();
			//
			//
			//				//}
			//				//
			//
			//			    Tri_Delaunay Tr;
			//				std::map<point_2D,double> mapPoint;
			//
			//				point_2D p2;
			//				point_2D p2_2;
			//
			//
			//				for (int i=0;i<depointVector.size();++i)
			//				{
			//					p2.X = depointVector.at(i).X;
			//					p2.Y = depointVector.at(i).Y;
			//
			//					mapPoint.insert(std::map<point_2D,double>::value_type(p2,depointVector.at(i).Z));							
			//				}
			//
			//				renderVertor = Tr.Triangle_Delaunay(depointVector);
			//
			//				for (int i = 0; i < renderVertor.size(); ++i)
			//				{
			//					double val;
			//					De_point map_p;
			//					p2_2.X = renderVertor.at(i).X;
			//					p2_2.Y = renderVertor.at(i).Y;
			//					std::map<point_2D,double>::iterator ite;
			//					ite=mapPoint.find(p2_2);
			//					if (ite!=mapPoint.end())
			//					{
			//						val = ite->second;
			//					}
			//
			//					map_p.X = p2_2.X;
			//					map_p.Y = p2_2.Y;
			//					map_p.Z = val;
			//					transferVector.push_back(map_p);
			//				}
			//
			//				for (int i = 0; i < transferVector.size(); ++i)
			//				{
			//					//manual_D->position(V2.at(i).x,V2.at(i).y, V2.at(i).z);
			//					renderObject->position(transferVector.at(i).X,transferVector.at(i).Y,transferVector.at(i).Z);
			//				
			//				    renderObject->textureCoord((transferVector.at(i).X-upLeftPt.getX())/width,(transferVector.at(i).Z-upLeftPt.getZ())/height);
			//				}
			//
			//				for (int i=0;i<transferVector.size();i+=3)
			//				{
			//					renderObject->index(i);
			//					renderObject->index(i+1);
			//					renderObject->index(i+2);
			//				}
			//
			//			
			//#if 0
			//				for (int i = 0;i<row;i++)
			//				{
			//					for (int j = 0;j<column;j++)
			//					{
			//						VirtualMine::Geometry::CPoint point = terraneGeometry->getPoint(i,j);
			//						Ogre::Vector3 realPoint = Ogre::Vector3(point.getX(),point.getY(),point.getZ()* VirtualMine::SpatialInterface::IScene::CoefficientOfCoordinateTransform);
			//						renderObject->position(realPoint);
			//						//renderObject->textureCoord((float)i/(float)row,(float)j/(float)column);
			//						renderObject->textureCoord((point.getX()-upLeftPt.getX())/width,(point.getZ()-upLeftPt.getZ())/height);
			//					}			
			//				}
			//
			//				for (int i = 0;i<row-1;i++)
			//				{
			//					for (int j = 0;j<column-1;j++)
			//					{
			//						renderObject->triangle((i*column)+j,(i*column)+j+1,(i+1)*column+j);
			//						renderObject->triangle((i+1)*column+j,i*column+j+1,(i+1)*column+j+1);
			//					}
			//				}
			//
			//
			//#endif
			//				
			//				renderObject->end();
			//			}
			//			
			//			}				
			//		}
			//	

		
	}
	
}