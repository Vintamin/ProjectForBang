
#include "vrmine/vr_systemui/shortestpathtool.h"
#include "OGRE/OgreSceneQuery.h"
#include "vrmine/vr_core/userdata.h"

#include "vrmine/vr_spatialobject/mine/lanwayobject.h"
#include "vrmine/vr_spatialobject/mine/modelobject.h"
#include "vrmine/vr_style/style/lanewaystyle.h"
#include "vrmine/vr_geometry/geometry/laneway.h"
#include "vrmine/vr_spatiallayer/lanwaylayer.h"
#include "vrmine/vr_spatiallayer/modellayer.h"
#include "vrmine/vr_spatialrender/spatialrender/lanewayrenderableobject.h"
#include "stack"
#include "iostream"
#include "vrmine/vr_geometry/geometry/line.h"

#include "vrmine/vr_geometry/geometry/point.h"
#include "vrmine/vr_spatialobject/base/geopoint.h"
#include "vrmine/vr_style/style/pointstyle.h"


#include <map>
using namespace std;
using namespace VirtualMine::Core;
using namespace VirtualMine::Scene;
using namespace VirtualMine::Mine;
using namespace VirtualMine::Style;
using namespace VirtualMine::Geometry;
using namespace  VirtualMine::SpatialLayer;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::SpatialRender;
using namespace VirtualMine::BaseRender;
using namespace VirtualMine::Base;
using namespace VirtualMine::Geometry;

#ifndef _USE_NEW_METHOD_
#define  _USE_NEW_METHOD_ 1
#endif

namespace VirtualMine
{
	namespace SystemUI
	{
		CShortestPathTool::CShortestPathTool()
			:ref_mpGeoSpatialControl(NULL)
		{
		    intmax = 1000000;
			this->mpShortestPathManual = NULL;
			this->mpRenderPoints = NULL;
		}
		
		CShortestPathTool::~CShortestPathTool()
		{
		
		}
		void CShortestPathTool::initialvector(int vertexnum)
		{
			std::vector<std::vector<double>>().swap(weight);
			std::vector<std::vector<int>>().swap(path);

			weight.resize(vertexnum);//路径权重数组
			path.resize(vertexnum);//保存最短路径数组,记录前继
			for(int i = 0;i < vertexnum;i++){//建立数组
				weight[i].resize(vertexnum,intmax);
				path[i].resize(vertexnum,i);
			}
		}

		void  CShortestPathTool::floyd(int vertexnum)
		{
			for(int k = 0;k < vertexnum;k++)
			{
				for(int i= 0;i < vertexnum;i++)
				{
					for(int j = 0;j < vertexnum;j++)
					{
						if(weight[i][k] + weight[k][j] < weight[i][j])//前面一部分是防止加法溢出
						{weight[i][j] = weight[i][k] + weight[k][j];
						//path[i][j] =j;
						path[i][j]=path[k][j];
						}
					}
				}
			}
		}

		std::vector<int> CShortestPathTool::displaypath(int source,int dest)
		{
			std::vector<int> shortpath;
			//std::cout << "Origin -> Dest   Distance    Path" << std::endl;

			if ( source != dest )   // 节点不是自身
			{
				//std::cout << source << " -> " << dest << "\t\t";
				if ( intmax == weight[source][dest] )    // i -> j 不存在路径
				{
					std::cout << "INFINITE" << "\t\t";


				}
				else
				{
					//std::cout << weight[source][dest] << "\t\t";

					// 由于我们查询最短路径是从后往前插，因此我们把查询得到的节点
					// 压入栈中，最后弹出以顺序输出结果。
					std::stack<int> stackVertices;
					int k = dest;

					do
					{
						k = path[source][k];
						stackVertices.push( k );
					} while ( k != source );
					//////////////////////////////////////////////////////////////////////////

				/*	std::cout << stackVertices.top();
					stackVertices.pop();*/

					unsigned int nLength = stackVertices.size();
					for ( unsigned int nIndex = 0; nIndex < nLength; ++nIndex )
					{
						std::cout << " -> " << stackVertices.top();
						shortpath.push_back(stackVertices.top());
						stackVertices.pop();



					}

					std::cout << " -> " << dest << std::endl;
					shortpath.push_back(dest);
				}
			}

			return shortpath;

		}
		void CShortestPathTool::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl)
		{
			this->ref_mpGeoSpatialControl= ref_pGeoSpatialControl;
		}
		
		void CShortestPathTool::mouseReleaseEvent(const int& x ,const int& y , const int& button)
		{
			if (button == 1 && !this->mIsMouseDrag)
			{
				this->clear();

				Ogre::Vector3 intersectPoint(Ogre::Vector3::ZERO);
				Ogre::RaySceneQueryResultEntry resultObject;
				resultObject.movable = NULL;
				resultObject.worldFragment = NULL;
				resultObject.distance = DBL_MAX;
				this->ref_mpGeoSpatialControl->getGeoSceneManager()->rayQuery(x,y,intersectPoint,resultObject);

			
				

				if (!resultObject.movable)
				{
					return;
				}
				if (resultObject.movable->getUserAny().isEmpty())
				{
					return;
				}	

			 


				VirtualMine::Core::CBaseObject* pUserData = resultObject.movable->getUserAny().get<VirtualMine::Core::CBaseObject*>();
				CLaneWayObject* querylanewayObject = dynamic_cast<CLaneWayObject*>(pUserData);
				
				CLaneWayNodeGeometry* curNode = NULL;
				CLaneWayNodeGeometry* preNode = NULL;
				if (querylanewayObject == NULL)
				{
					return;
				}
				CLaneWayLineGeometry* querylanewayGeometry = dynamic_cast<CLaneWayLineGeometry*>(querylanewayObject->getGeometry());
				int nodeCount0 = querylanewayGeometry->getNodesCount();
				std::string lanelinename = querylanewayGeometry->getName();


		        IRenderableObject* renderobject = dynamic_cast<CLanewayLayer*>(this->ref_mpGeoSpatialControl->getScene()->getLanewayLayer())->getRenderableObject();
				CLanewayRenderableObject* lanewayrenderobject = dynamic_cast<CLanewayRenderableObject*>(renderobject);
				int objectCount = lanewayrenderobject->getGeoObjectCount();
		     	VirtualMine::SpatialInterface::GeoObjectVector geoobjectVec = lanewayrenderobject->getGeoObjectVec();

#if 1

	int maxID(0);
				////遍历节点,找出最大点
				for (int i = 0; i < objectCount; i++)
				{
					CLaneWayObject*  lanewayObject = dynamic_cast<	CLaneWayObject* >(geoobjectVec.at(i));
					CLaneWayLineGeometry* lanewayGeometry = dynamic_cast<CLaneWayLineGeometry*>(lanewayObject->getGeometry());
					int nodeCount =	lanewayGeometry->getNodesCount();


					for (int j = 0; j < nodeCount - 1; j++)
					{
						CLaneWayNodeGeometry* node = lanewayGeometry->getNode(j);
						CLaneWayNodeGeometry* nextNode = lanewayGeometry->getNode(j + 1);

						std::string name1 = node->getName();
						std::string name2 = nextNode->getName();
						int ID1 = Ogre::StringConverter::parseInt(name1);
						int ID2 =  Ogre::StringConverter::parseInt(name2);
							 
						if (ID1 > maxID)
						{
							maxID = ID1;
						}
						if (ID2 > maxID)
						{
							maxID = ID2;
						}

					/*	Ogre::Vector3 pos = node->getPosition();
						Ogre::Vector3 nextPos = nextNode->getPosition();
						double twopointDis = pos.distance(nextPos);
*/

					}


				}


#endif
			

				for (int i = 0; i < objectCount; i++)
				{
					CLaneWayObject*  lanewayObject = dynamic_cast<	CLaneWayObject* >(geoobjectVec.at(i));
					CLaneWayLineGeometry* lanewayGeometry = dynamic_cast<CLaneWayLineGeometry*>(lanewayObject->getGeometry());
					int nodeCount =	lanewayGeometry->getNodesCount();

					
					std::string name = dynamic_cast<CLaneWayLineGeometry* >(lanewayObject->getGeometry())->getName();
				    if (name == lanelinename)
				    {
						/////当前点击的巷道要加入插入点

#if 1
						double competeDis =  dynamic_cast<CLanewayStyle*>(lanewayObject->getStyle())->getHeight() + 0.5 * dynamic_cast<CLanewayStyle*>(lanewayObject->getStyle())->getWidth();

						for (int i = 0; i < nodeCount; i++)
						{
							Ogre::Vector3 pos =  lanewayGeometry->getNode(i)->getPosition();
							double dis = intersectPoint.distance(pos);
						
							bool truefalse = dis < competeDis;
							if (truefalse)
							{

								curNode = lanewayGeometry->getNode(i);
								break;
								//preNode = lanewayGeometry->getNode(i - 1);
								//preNode = lanewayGeometry->getNode(i)->getPreNode();
							}
						}

						if (curNode == NULL)
						{
							curNode = new CLaneWayNodeGeometry();
							curNode->setPosition(intersectPoint);
							
							std::map<double,int>indexDistanceMap;

							double minDis(0);
							for (int i = 0; i < nodeCount; i++)
							{

								Ogre::Vector3 pos =  lanewayGeometry->getNode(i)->getPosition();
								double dis = intersectPoint.distance(pos);

								indexDistanceMap.insert(pair <double, int>( dis,i));

							}
							vector<double> orderVec;
							map<double,int>::iterator ite = indexDistanceMap.begin();
							minDis = ite->first;
							while(ite != indexDistanceMap.end())
							{

								orderVec.push_back(ite->first);
								ite++;
							}

							sort(orderVec.begin(),orderVec.end());

							ite = indexDistanceMap.find(orderVec.at(0));
							int minIndex = ite->second;
							if (minIndex < 1)
							{
							/*	curNode->setPreNode(lanewayGeometry->getNode(0));
								curNode->setNextNode(lanewayGeometry->getNode(1));
								lanewayGeometry->getNode(0)->setNextNode(curNode);
								lanewayGeometry->getNode(1)->setPreNode(curNode);*/
								preNode = lanewayGeometry->getNode(0);

							}
							else if (minIndex == lanewayGeometry->getNodesCount() - 1)
							{
							/*	curNode->setPreNode(lanewayGeometry->getNode(minIndex - 1));
								curNode->setNextNode(lanewayGeometry->getNode(minIndex));
								lanewayGeometry->getNode(minIndex)->setPreNode(curNode);
								lanewayGeometry->getNode(minIndex -1)->setNextNode(curNode);*/
								preNode = lanewayGeometry->getNode(minIndex - 1);
							}
							else
							{
								CLaneWayNodeGeometry* firnode = lanewayGeometry->getNode(minIndex );
								CLaneWayNodeGeometry* secnode = lanewayGeometry->getNode(minIndex + 1);
								Ogre::Vector3 firPoint = firnode->getPosition();
								Ogre::Vector3 secPoint = secnode->getPosition();
								double firDis = curNode->getPosition().distance(firPoint);
								double secDis = curNode->getPosition().distance(secPoint);
								double firPointToSecPoint = firPoint.distance(secPoint);
								if ( secDis > firPointToSecPoint)
								{
								/*	curNode->setPreNode(lanewayGeometry->getNode(minIndex));
									curNode->setNextNode(lanewayGeometry->getNode(minIndex+1));

									lanewayGeometry->getNode(minIndex)->setNextNode(curNode);
									lanewayGeometry->getNode(minIndex + 1)->setPreNode(curNode);*/

									preNode = lanewayGeometry->getNode(minIndex - 1 );

								}
								else
								{
							/*		curNode->setPreNode(lanewayGeometry->getNode(minIndex - 1));
									curNode->setNextNode(lanewayGeometry->getNode(minIndex));

									lanewayGeometry->getNode(minIndex - 1)->setNextNode(curNode);
									lanewayGeometry->getNode(minIndex)->setPreNode(curNode);
									*/
									preNode = lanewayGeometry->getNode(minIndex);
								}
								
							}
							std::string maxName = Ogre::StringConverter::toString(maxID + 1);
							curNode->setName(maxName);

							lanewayGeometry->addNode(curNode,preNode);
						
						}


#endif               

						break;
				    }


			}
#if 1

			    /////初始化数组
				this->initialvector(maxID + 2);
			
			
				////为数组赋值
				for (int i = 0; i < objectCount; i++)
				{
					CLaneWayObject*  lanewayObject = dynamic_cast<	CLaneWayObject* >(geoobjectVec.at(i));
					CLaneWayLineGeometry* lanewayGeometry = dynamic_cast<CLaneWayLineGeometry*>(lanewayObject->getGeometry());
					int nodeCount =	lanewayGeometry->getNodesCount();
					for (int j = 0; j < nodeCount - 1; j++)
					{
						CLaneWayNodeGeometry* node = lanewayGeometry->getNode(j);
						CLaneWayNodeGeometry* nextNode = lanewayGeometry->getNode(j + 1);

						std::string name1 = node->getName();
						if (name1 == "0" || name1 == "522")
						{
							int i = 0;
						}
						std::string name2 = nextNode->getName();
						if (name2 == "0" || name2 == "522")
						{
							int i = 0;
						}
						int ID1 = Ogre::StringConverter::parseInt(name1);
						int ID2 =  Ogre::StringConverter::parseInt(name2);
					
						Ogre::Vector3 pos = node->getPosition();
						Ogre::Vector3 nextPos = nextNode->getPosition();
						double twopointDis = pos.distance(nextPos);

                        /////为数组赋值
						weight[ID1][ID2] = twopointDis;
						weight[ID2][ID1] = twopointDis;

					}


				}
				this->getEscapeHouseID();
				this->floyd(maxID + 2);
			    int idSize = this->mEscapeHouseIDVec.size();
				int shortestpathID = 0;
				if (idSize > 0)
				{
					/////只计算了一个庇护所，若是有多个，可以循环计算当前点到每个庇护所的距离，取最小的；
					shortestpathID = this->mEscapeHouseIDVec.at(0);
				}
				//std::vector<int> shortestpath = this->displaypath(522,252);
              	std::vector<int> shortestpath = this->displaypath(maxID+1,shortestpathID);	
				///计算距离
				double pathDistance(0);
				int patnSize = shortestpath.size();
				if (patnSize > 1)
				{
					for (int i = 0; i < patnSize - 1; i++)
					{
						int firstID = shortestpath.at(i);
						int secondID = shortestpath.at(i+1);
						double dis = weight[firstID][secondID];
						pathDistance += dis;
					}
				}



#endif

#if  1  节点点号

				for (int s = 0; s < objectCount; s++)
				{
					CLaneWayObject*  lanewayObject = dynamic_cast<	CLaneWayObject* >(geoobjectVec.at(s));
					CLaneWayLineGeometry* lanewayGeometry = dynamic_cast<CLaneWayLineGeometry*>(lanewayObject->getGeometry());
					int nodeCount =	lanewayGeometry->getNodesCount();


					for (int m = 0;m < nodeCount; m++)
					{
						CLaneWayNodeGeometry* mNode = lanewayGeometry->getNode(m);
						std::string name0 = mNode->getName();
						int ID0 = Ogre::StringConverter::parseInt(name0);
						mNodeIDMap.insert(map<int,CLaneWayNodeGeometry*>::value_type(ID0,mNode));
						//mNodeIDMap.insert(std::pair<int, CLaneWayNodeGeometry*>(ID0, mNode));
					}
				}

#endif
			
#if 1 画线
				CLine* pRenderLine = new CLine();
				int pathCount =  shortestpath.size();
				for (int i = 0;i < pathCount; i++)
				{
					int nodeID =  shortestpath.at(i);
					map<int,CLaneWayNodeGeometry*>::iterator ite = mNodeIDMap.find(nodeID);

					if(ite != mNodeIDMap.end())
					{
						CLaneWayNodeGeometry* node = ite->second;
						Ogre::Vector3 pos = node->getPosition();
						
						this->mPoints.push_back(Ogre::Vector3(pos.x,pos.y + 9,pos.z));


						pRenderLine->addPoint(pos.x,pos.y,pos.z);

					}
				
				}
			

				
				if (this->mPoints.size() < 1)
				{
					return;
				}
				this->mPoints.at(0).x = intersectPoint.x;
				this->mPoints.at(0).y = intersectPoint.y;
				this->mPoints.at(0).z = intersectPoint.z;

				this->renderPoints();


		        int pointCount = pRenderLine->getCount();

				std::string manualName = "ShortestPath";
				manualName += Ogre::StringConverter::toString(x);

#if 0
				///////每一个矩形一个manualobject
				for (int i = 0 ; i < pointCount - 1; i++)
				{
					CPoint po = pRenderLine->getPoint(i);
					CPoint po2 = pRenderLine->getPoint(i + 1);
					manualName += Ogre::StringConverter::toString(i);
					
					Ogre::ManualObject* arrowObject = this->ref_mpGeoSpatialControl->getGeoSceneManager()->createManualObject(manualName);
					arrowObject->begin("ShortestPathMaterial", Ogre::RenderOperation::OT_TRIANGLE_LIST,VR_MINE_DEFAULT_RESOURCE_GROUP);  
					
					arrowObject->position(po.getX() + 4,po.getY() + 9,po.getZ());	
					arrowObject->textureCoord(0,1);
					arrowObject->position(po.getX() - 4,po.getY() + 9,po.getZ());
					arrowObject->textureCoord(0,0);

					arrowObject->position(po2.getX() + 4,po2.getY() + 9,po2.getZ());	
					arrowObject->textureCoord(1,1);
					arrowObject->position(po2.getX() - 4,po2.getY() + 9,po2.getZ());
					arrowObject->textureCoord(1,0);

					
					arrowObject->triangle(0,1,2);
					arrowObject->triangle(1,3,2);
					arrowObject->end();  



					this->ref_mpGeoSpatialControl->getGeoSceneManager()->getRootSceneNode()->createChildSceneNode(manualName)->attachObject(arrowObject);  

					this->mShortestPathManualVec.push_back(arrowObject);
			
				}

#endif





#if 1 构建巷道模型


				IGeoObject* pGeoObject = new CLaneWayObject();

				CLaneWayLineGeometry* pLineGeometry = new CLaneWayLineGeometry();
				CLanewayStyle* pStyle = new CLanewayStyle();
				pStyle->setHeight(1);
				pStyle->setWidth(1);
				pStyle->setSectionType(LanewaySectionType::Circle);
				//pStyle->setSectionType(LanewaySectionType::Arch);

				for (int i = 0 ; i < pointCount; i++)
				{
					CPoint tmp = pRenderLine->getPoint(i);
					Ogre::Vector3 vec(tmp.getX(),tmp.getY() + 8,tmp.getZ());				
					CLaneWayNodeGeometry* pNode = new CLaneWayNodeGeometry();
					if (i == 0)
					{
						vec.y -= 4;
					}
					pNode->setPosition(vec);
					if (i == 0)
					{
						Ogre::Vector3 firstPoint(intersectPoint.x,intersectPoint.y + 3,intersectPoint.z);
						pNode->setPosition(firstPoint);
					}
                    pLineGeometry->addNode(pNode);					
				}

				if (pLineGeometry->getNodesCount() > 0 && pLineGeometry->getNodesCount() < 3)
				{
					if (pLineGeometry->getNodesCount() > 1)
					{
						CLaneWayNodeGeometry* pNode = pLineGeometry->getNode(0);
						CLaneWayNodeGeometry* pNextNode = pLineGeometry->getNode(1);
						pNextNode->setPreNode(pNode);
						pNode->setNextNode(pNextNode);
					}
				}
				else if (pLineGeometry->getNodesCount() > 2)
				{	
					for (int j = 0; j < pLineGeometry->getNodesCount(); j++)
					{

						if (j == 0)
						{
							CLaneWayNodeGeometry* pNode = pLineGeometry->getNode(0);
							CLaneWayNodeGeometry* pNextNode = pLineGeometry->getNode(1);
							pNextNode->setPreNode(pNode);
							pNode->setNextNode(pNextNode);
						}
						else if (j == pLineGeometry->getNodesCount() - 1)
						{
							CLaneWayNodeGeometry* pNode = pLineGeometry->getNode(j - 1);
							CLaneWayNodeGeometry* pNextNode = pLineGeometry->getNode(j);
							pNextNode->setPreNode(pNode);
							pNode->setNextNode(pNextNode);
						}
						else
						{
							CLaneWayNodeGeometry* pNode = pLineGeometry->getNode(j );
							CLaneWayNodeGeometry* pNextNode = pLineGeometry->getNode(j + 1);
							pNextNode->setPreNode(pNode);
							pNode->setNextNode(pNextNode);

						}
					}

				}

				pGeoObject->setGeometry(pLineGeometry,true);
				pGeoObject->setStyle(pStyle,true);
				CLanewayRenderableObject* pRenderableObject(NULL);
				pRenderableObject = new CLanewayRenderableObject();
				pRenderableObject->addGeoObject(pGeoObject);


				if (pRenderableObject)
				{
					pRenderableObject->build();
					//pRenderableObject->setNode(this->ref_mpGeoSpatialControl->getGeoSceneManager()->createSceneNode());
					
					//pRenderableObject->render();
				

					GeoExtentionDataVector geoDatas;
					pRenderableObject->getGeoExtentionDatas(geoDatas);
					
					int index = 0;
					mpShortestPathManual = NULL; 
					if (geoDatas.size() > 0)
					{
						for (int s = 0; s < geoDatas.size(); s++)
						{
							mpShortestPathManual = geoDatas.at(s)->getExtentionData();
							Ogre::SceneNode* pSceneNode = this->ref_mpGeoSpatialControl->getGeoSceneManager()->getRootSceneNode()->createChildSceneNode(Ogre::StringConverter::toString(s));
							pSceneNode->attachObject(mpShortestPathManual);
						}
						
					}
					
					for (size_t i = 0; i < mpShortestPathManual->getNumSections();++i)
					{
						mpShortestPathManual->setMaterialName(i,"ShortestPathMaterial",
							VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
					}

				}
#endif


#if 0


				Ogre::ManualObject*  pShortestPathManual = this->ref_mpGeoSpatialControl->getGeoSceneManager()->createManualObject(manualName);

						
				pShortestPathManual->begin("ShortestPathMaterial", Ogre::RenderOperation::OT_TRIANGLE_LIST,VR_MINE_DEFAULT_RESOURCE_GROUP);  
			    

				/////矩形
			/*	for (int i = 0 ; i< pointCount; i++)
				{
					CPoint po = pRenderLine->getPoint(i);
					shortestPathManual->position(po.getX() + 7,po.getY(),po.getZ());
					shortestPathManual->position(po.getX() - 7,po.getY(),po.getZ());
					shortestPathManual->position(po.getX() - 7,po.getY() + 9,po.getZ());
					shortestPathManual->position(po.getX() + 7,po.getY() + 9,po.getZ());
				    shortestPathManual->colour(Ogre::ColourValue::Red);
				
				} 
				for (int j = 0 ; j < pointCount - 1 ; j++)
				{   
					int m = j * 4;
				    int n = (j + 1) * 4;
					shortestPathManual->triangle(m,m+3,n);
					shortestPathManual->triangle(m+3,n,n+3);

					shortestPathManual->triangle(m+2,m+3,n+2);
					shortestPathManual->triangle(m+3,n+2,n+3);

					shortestPathManual->triangle(m+2,m+1,n+1);
					shortestPathManual->triangle(m+2,n+1,n+2);

					shortestPathManual->triangle(m,m+1,n);
					shortestPathManual->triangle(m+1,n,n+1);

				}*/
				double allDis(0);

#if !_USE_NEW_METHOD_
				for (int i = 0 ; i< pointCount; i++)
				{
					CPoint tmp = pRenderLine->getPoint(i);
					Ogre::Vector3 vec(tmp.getX(),tmp.getY(),tmp.getZ());
					double dis(0);
					
					if (i < (pointCount-1) )
					{
						CPoint tmp1 = pRenderLine->getPoint(i+1);
						Ogre::Vector3 vec2(tmp1.getX(),tmp1.getY(),tmp1.getZ());
					    allDis += vec.distance(vec2);
					}
				
				}

				for (int i = 0 ; i< pointCount; i++)
				{
					Ogre::Real uX = 0;
					double disUV(0);
					CPoint po = pRenderLine->getPoint(i);
					Ogre::Vector3 vect(po.getX(),po.getY(),po.getZ());
					CPoint po1;
					if (i < (pointCount-1) )
					{
						po1 = pRenderLine->getPoint(i+1);
						Ogre::Vector3 vect2(po1.getX(),po1.getY(),po1.getZ());
						disUV += vect.distance(vect2);
					}
					shortestPathManual->position(po.getX() + 4,po.getY() + 9,po.getZ());
					
					uX = disUV ;/// allDis;

					shortestPathManual->textureCoord(uX,1);
					shortestPathManual->position(po.getX() - 4,po.getY() + 9,po.getZ());
					shortestPathManual->textureCoord(uX,0);
					//shortestPathManual->colour(Ogre::ColourValue::Red);

				} 
#else
				Ogre::Vector3 lastPoint = Ogre::Vector3::UNIT_SCALE;
				for (int i = 0 ; i < pointCount; i++)
				{
					CPoint tmp = pRenderLine->getPoint(i);
					Ogre::Vector3 vec(tmp.getX(),tmp.getY(),tmp.getZ());

					if (i == 0)
					{
						lastPoint = vec;
					}
					else
					{
						CPoint curPoint = pRenderLine->getPoint(i);
						Ogre::Vector3 vec2(curPoint.getX(),curPoint.getY(),curPoint.getZ());
						allDis += lastPoint.distance(vec2);
						lastPoint = vec2;
					}

				}
				double disU(0);
				for (size_t i = 0 ; i < pointCount ; ++i)
				{
					Ogre::Vector3 destDir = Ogre::Vector3::UNIT_SCALE;
					Ogre::Vector3 prePt(Ogre::Vector3::UNIT_SCALE);
					Ogre::Radian halfAngle = Ogre::Radian(Ogre::Math::HALF_PI);
					Ogre::Vector3 curPt(pRenderLine->getPoint(i).getX(),
						pRenderLine->getPoint(i).getY(),
						pRenderLine->getPoint(i).getZ());
					Ogre::Vector3 nextPt(Ogre::Vector3::UNIT_SCALE);
					if (i != 0 && i != pointCount - 1)
					{
						nextPt.x = pRenderLine->getPoint(i + 1).getX();
						nextPt.y = pRenderLine->getPoint(i + 1).getY();
						nextPt.z = pRenderLine->getPoint(i + 1).getZ();

						prePt.x = pRenderLine->getPoint(i - 1).getX();
						prePt.y = pRenderLine->getPoint(i - 1).getY();
						prePt.z = pRenderLine->getPoint(i - 1).getZ();

						Ogre::Vector3 preDir = prePt - curPt;
						Ogre::Vector3 nextDir = nextPt - curPt;
						preDir.normalise();
						nextDir.normalise();
						destDir = preDir + nextDir;
						destDir.normalise();

						halfAngle = preDir.angleBetween(nextDir) / 2;
					}
					else
					{
						if (i == 0)
						{
							nextPt.x = pRenderLine->getPoint(i + 1).getX();
							nextPt.y = pRenderLine->getPoint(i + 1).getY();
							nextPt.z = pRenderLine->getPoint(i + 1).getZ();
							destDir = nextPt - curPt;
							destDir.normalise();
						}
						else if (i == pointCount - 1)
						{
							prePt.x = pRenderLine->getPoint(i - 1).getX();
							prePt.y = pRenderLine->getPoint(i - 1).getY();
							prePt.z = pRenderLine->getPoint(i - 1).getZ();
							destDir = curPt - prePt;
							destDir.normalise();
						}

						//up方向
						Ogre::Vector3 upDir = Ogre::Vector3::UNIT_Y;
						destDir = upDir.crossProduct(destDir);
						destDir.normalise();
					}
					curPt.y += 9;
					Ogre::Vector3 leftPt = curPt + destDir * 4 / Ogre::Math::Sin(halfAngle);
					Ogre::Vector3 rightPt = curPt - destDir * 4 / Ogre::Math::Sin(halfAngle);

					if (i == 0 )
					{
						CPoint nextPoint = pRenderLine->getPoint(i+1);
						Ogre::Vector3 vect(nextPoint.getX(),nextPoint.getY(),nextPoint.getZ());
						lastPoint = vect;
					}
					else 
					{
						CPoint curPoint = pRenderLine->getPoint(i);
						Ogre::Vector3 vect2(curPoint.getX(),curPoint.getY(),curPoint.getZ());
						disU += vect2.distance(lastPoint);
						lastPoint = vect2;
					}

					Ogre::Real u = disU;

					pShortestPathManual->position(leftPt);
					pShortestPathManual->textureCoord(u,0);
					pShortestPathManual->position(rightPt);
					pShortestPathManual->textureCoord(u,1);
				}
#endif

				for (int j = 0 ; j < pointCount - 1 ; j++)
				{   
					int m = 2 * j;
					pShortestPathManual->triangle(m,m + 2,m + 3);
					pShortestPathManual->triangle(m,m + 3,m + 1);
				
				}

							
			    pShortestPathManual->end();  



				this->ref_mpGeoSpatialControl->getGeoSceneManager()->getRootSceneNode()->createChildSceneNode(manualName)->attachObject(pShortestPathManual);  
					





				this->mShortestPathManualVec.push_back(pShortestPathManual);
#endif
				
 			

#endif





#if 1 删除插入节点

				for (int i = 0; i < objectCount; i++)
				{
					CLaneWayObject*  lanewayObject = dynamic_cast<	CLaneWayObject* >(geoobjectVec.at(i));
					CLaneWayLineGeometry* lanewayGeometry = dynamic_cast<CLaneWayLineGeometry*>(lanewayObject->getGeometry());
		
					std::string name = dynamic_cast<CLaneWayLineGeometry* >(lanewayObject->getGeometry())->getName();
					if (name == lanelinename)
					{

						double competeDis =  dynamic_cast<CLanewayStyle*>(lanewayObject->getStyle())->getHeight() + 0.5 * dynamic_cast<CLanewayStyle*>(lanewayObject->getStyle())->getWidth();
						std::string name = Ogre::StringConverter::toString(maxID + 1);
						CLaneWayNodeGeometry* nodeGeo = lanewayGeometry->getNode(name);
						lanewayGeometry->deleteNode(nodeGeo);
						break;

					}



				}


#endif

		

			/*	if (this->ref_mpGeoSpatialControl)
				{
					this->ref_mpGeoSpatialControl->afterRayQuery(resultObject);
				}*/

		
			}
		}
		
		void CShortestPathTool::mousePressEvent(const int& x ,const int& y , const int& button)
		{
			CTool::mousePressEvent(x,y,button);
		}
		
		void CShortestPathTool::mouseDoubleClickEvent(const int& x ,const int& y , const int& button)
		{
			CTool::mouseDoubleClickEvent(x,y,button);
		}
	
		void CShortestPathTool::mouseMoveEvent(const int& x ,const int& y, const int& button)
		{
			CTool::mouseMoveEvent(x,y,button);
		}
		
		void CShortestPathTool::wheelEvent(const int& x ,const int& y , const int& delta)
		{
			CTool::wheelEvent(x,y,delta);
		}
		
		void CShortestPathTool::keyPressEvent(const int& key)
		{
		
		}
		
		bool CShortestPathTool::handleEvent(VirtualMine::Core::CEvent* evt)
		{
			return CTool::handleEvent(evt);
			/*CEvent::Type type = evt->type();
			switch(type)
			{
			case CEvent::MouseButtonPress:
				{
					break;
				}
			case CEvent::MouseButtonRelease:
				{
					CMouseEvent* pMouseEvent = dynamic_cast<CMouseEvent*>(evt);
					this->mouseReleaseEvent(pMouseEvent->getX(),pMouseEvent->getY(),pMouseEvent->getButton());
					evt->accept();
					break;
				}
			case CEvent::MouseMove:
				{
					break;	
				}
			default:
				break;
			}
			return evt->isAccepted();*/
		}

		void CShortestPathTool::createSection( Ogre::Vector3 pos )
		{

		}

		void CShortestPathTool::clear()
		{
			this->mPoints.clear();
			if (this->mpRenderPoints!=NULL)
			{
				this->mpRenderPoints->dispose();
				delete this->mpRenderPoints;
				this->mpRenderPoints = NULL;
			}	

			if (mpShortestPathManual)
			{
				
				Ogre::Node* pNode = mpShortestPathManual->getParentNode();
				if (pNode)
				{
					mpShortestPathManual->detachFromParent();
					pNode->getParent()->removeChild(pNode);
					this->ref_mpGeoSpatialControl->getGeoSceneManager()->destroySceneNode((Ogre::SceneNode*)pNode);
				}
				this->ref_mpGeoSpatialControl->getGeoSceneManager()->destroyManualObject(mpShortestPathManual);
				mpShortestPathManual = NULL;
			}

#if 0


			if (this->mShortestPathManualVec.size() > 0 )
			{
				for (int i = 0; i < this->mShortestPathManualVec.size();i++)
				{
					Ogre::ManualObject* pObj = this->mShortestPathManualVec.at(i);
					Ogre::Node* pNode = pObj->getParentNode();
					if (pNode)
					{
						pObj->detachFromParent();
						pNode->getParent()->removeChild(pNode);
						this->ref_mpGeoSpatialControl->getGeoSceneManager()->destroySceneNode((Ogre::SceneNode*)pNode);
					}
					this->ref_mpGeoSpatialControl->getGeoSceneManager()->destroyManualObject(pObj);
					pObj = NULL;
				}
			}

			this->mShortestPathManualVec.clear();
#endif
			
		 	
		}

		void CShortestPathTool::renderPoints()
		{
			if (this->mPoints.size() > 0)
			{
				if (this->mpRenderPoints == NULL)
				{
					this->mpRenderPoints = new CMultiPoint();
					this->mpRenderPoints->setGeoSceneManager(this->ref_mpGeoSpatialControl->getGeoSceneManager());
				}

				this->mpRenderPoints->dispose();

				for (size_t i = 0 ; i < this->mPoints.size(); ++i)
				{
					Ogre::Vector3& point = this->mPoints.at(i);
					CPoint* pPoint = new CPoint();
					pPoint->setCoor(point.x,point.y,point.z);

					CGeoPoint* geoPoint = new CGeoPoint();
					geoPoint->setGeometry(pPoint,true);
					CPointStyle* pStyle = dynamic_cast<CPointStyle*>(geoPoint->getStyle());
					pStyle->setPointRenderMode(CPointStyle::PRM_ICON);

					this->mpRenderPoints->addGeoObject(geoPoint);
				}
				if (this->mpRenderPoints->getNode() == NULL)
					this->mpRenderPoints->setNode(this->ref_mpGeoSpatialControl->getGeoSceneManager()->getRootSceneNode()->createChildSceneNode());
				this->mpRenderPoints->build();
				this->mpRenderPoints->render();				
			}
		}

		std::vector<int> CShortestPathTool::getEscapeHouseID()
		{
			CModelLayer* pModelLayer = dynamic_cast<CModelLayer*>(this->ref_mpGeoSpatialControl->getScene()->getModelLayer());
			std::vector<Ogre::Entity*> pEntities = pModelLayer->getModelEntities();
			int entitiesSize = pEntities.size();
		    for (int i = 0; i< entitiesSize;i++)
		    {
			  std::string entityName = pEntities.at(i)->getName();
			  VirtualMine::Core::CBaseObject* pUserData = pEntities.at(i)->getUserAny().get<VirtualMine::Core::CBaseObject*>();
			  VirtualMine::Mine::CModelObject* pObject = dynamic_cast<VirtualMine::Mine::CModelObject*>(pUserData);
			  std::string modelName = pObject->getName(); 
			  int modelID = pObject->getID();
			  if (modelName ==  "庇护所")
			  {
				  this->mEscapeHouseIDVec.push_back(modelID);
			  }

		    }
			

			return mEscapeHouseIDVec;
		}


	}
}
