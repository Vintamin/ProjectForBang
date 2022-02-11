//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : layermanager.h
//  @ Date : 2014/7/6
//  @ Author : ʢ����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine\vr_spatialengine\georayscenequery.h"
#include "vrmine\vr_core\coredefine.h"
#include "OGRE\OgreRoot.h"
#include "OGRE\OgreSubMesh.h"
#include "OGRE\OgreRenderOperation.h"
#include <float.h>
#include "OGRE/Threading/OgreThreadDefines.h"
#include "OGRE/OgreManualObject.h"

using namespace Ogre;

namespace VirtualMine
{
	namespace SpatialEngine
	{
		CGeoRaySceneQuery::CGeoRaySceneQuery(Ogre::SceneManager* creator)
			:RaySceneQuery(creator)
		{
			this->mSupportedWorldFragments.insert(SceneQuery::WFT_NONE);
		}

		CGeoRaySceneQuery::~CGeoRaySceneQuery()
		{
		
		}

		void CGeoRaySceneQuery::getSceneMoveableByRay(Ogre::Ray& ray,Ogre::SceneNode* pSceneNode,
				std::vector<Ogre::MovableObject*>& moVector)
		{
			assert(pSceneNode);
			if (NULL == pSceneNode)
			{
				return;
			}
			if (pSceneNode->isInSceneGraph())
			{
				Ogre::SceneNode::ObjectIterator itr = pSceneNode->getAttachedObjectIterator();
				while (itr.hasMoreElements())
				{
					Ogre::MovableObject* mo = itr.getNext();
					//if (mo->getVisible())
					{
						moVector.push_back(mo);
					}
					Ogre::Entity* pEntity = dynamic_cast<Ogre::Entity*>(mo);
					if (pEntity)
					{
						Ogre::Entity::ChildObjectListIterator cItr = pEntity->getAttachedObjectIterator();
						while (cItr.hasMoreElements())
						{
							Ogre::MovableObject* childMo = cItr.getNext();
							if (childMo->getVisible())
							{
								moVector.push_back(childMo);
							}
						}
					}
				}
			}

			//�����ӽڵ�
			Ogre::Node::ChildNodeIterator cNodeItr = pSceneNode->getChildIterator();
			while (cNodeItr.hasMoreElements())
			{
				Ogre::SceneNode* pChildNode = (Ogre::SceneNode*)cNodeItr.getNext();
				this->getSceneMoveableByRay(ray,pChildNode,moVector);
			}
		}

		void CGeoRaySceneQuery::execute(Ogre::RaySceneQueryListener* listener)
		{
#if 1
			//����������������Ⱦ����
			typedef std::vector<Ogre::MovableObject*> MOVector;
			MOVector moveableVector;
			this->getSceneMoveableByRay(this->mRay,
				this->mParentSceneMgr->getRootSceneNode(),
				moveableVector);
			MOVector::iterator bItr = moveableVector.begin();
			MOVector::iterator eItr = moveableVector.end();
			while (bItr != eItr)
			{
				MovableObject* a = *bItr;
				// skip whole group if type doesn't match
				if (!(a->getTypeFlags() & mQueryTypeMask))
				{
					++bItr;
					continue;
				}
				if( (a->getQueryFlags() & mQueryMask) &&
					a->isInScene() && a->getVisible())
				{
					// ������Χ���ж�
					std::pair<bool, Real> boxR =
						mRay.intersects(a->getWorldBoundingBox());

					if (boxR.first)
					{
						std::pair<bool,Ogre::Real> result = std::pair<bool,Ogre::Real>(false,0);
						Ogre::Matrix4 worldMatrix = Ogre::Matrix4::IDENTITY;
						if (NULL != a->getParentNode())
						{
							worldMatrix.makeTransform(a->getParentNode()->_getDerivedPosition(),
								a->getParentNode()->_getDerivedScale(),
								a->getParentNode()->_getDerivedOrientation());
						}
						//ʵ��ѡ��
						if (Ogre::Entity* pEntity = dynamic_cast<Ogre::Entity*>(a))
						{
							result = CGeoRayIntersector::intersect(mRay,pEntity,worldMatrix);
						}
						else if (Ogre::Renderable* pRenderalbe = dynamic_cast<Ogre::Renderable*>(a))
						{
							Ogre::RenderOperation ro;
							pRenderalbe->getRenderOperation(ro);
							result = CGeoRayIntersector::intersect(mRay,ro,worldMatrix);
						}
						else if (Ogre::ManualObject* pManualObject = dynamic_cast<Ogre::ManualObject*>(a))
						{
							for (Ogre::uint32 i = 0 ; i < pManualObject->getNumSections(); ++i)
							{
								Ogre::ManualObject::ManualObjectSection* pSection = pManualObject->getSection(i);
								if (pSection)
								{
									Ogre::RenderOperation ro;
									pSection->getRenderOperation(ro);
									result = CGeoRayIntersector::intersect(mRay,ro,worldMatrix);
									if (result.first)
									{
										if (!listener->queryResult(a, result.second))
											return;
									}
								}
							}
							++bItr;
							continue;
						}
						if (result.first)
						{
							if (!listener->queryResult(a, result.second))
								return;
						}
					}
				}
				++bItr;
			}

#else 
			Root::MovableObjectFactoryIterator factIt = 
				Root::getSingleton().getMovableObjectFactoryIterator();
			while(factIt.hasMoreElements())
			{
				SceneManager::MovableObjectIterator objItA = 
					mParentSceneMgr->getMovableObjectIterator(
					factIt.getNext()->getType());
				while (objItA.hasMoreElements())
				{
					
				}
			}
#endif
		}


		CGeoRayIntersector::CGeoRayIntersector()
		{
		
		}

		CGeoRayIntersector::~CGeoRayIntersector()
		{
		
		}

		std::pair<bool, Ogre::Real> CGeoRayIntersector::intersect(Ogre::Ray& ray,Ogre::RenderOperation& renderOperation,const Ogre::Matrix4& worldMatrix)
		{
			Ogre::Ray curRay(ray);

			Ogre::Real intersectDis = DBL_MAX;
			std::pair<bool,Ogre::Real> resultValue = std::pair<bool,Ogre::Real>(false,DBL_MAX);
			if (renderOperation.vertexData 
				&& renderOperation.indexData)
			{
				switch(renderOperation.operationType)
				{
				case Ogre::RenderOperation::OT_TRIANGLE_LIST:
					{
#if 1
						std::vector<Ogre::Vector3> points;
						std::vector<Ogre::int32> indexes;
						//����buffer
						const Ogre::VertexElement* pPosElement = renderOperation.vertexData->vertexDeclaration->findElementBySemantic(Ogre::VES_POSITION);
						Ogre::HardwareVertexBufferSharedPtr vBufPtr = renderOperation.vertexData->vertexBufferBinding->getBuffer(pPosElement->getSource());
						//Ogre::int32 vertexSize = renderOperation.vertexData->vertexDeclaration->getVertexSize(pPosElement->getSource());
						//////////////////////////////////////////////////////////////////////////
						unsigned char* vertex = static_cast<unsigned char*>(vBufPtr->lock(Ogre::HardwareBuffer::HBL_READ_ONLY));
						float* pReal;
						for( size_t j = 0; j < renderOperation.vertexData->vertexCount; ++j, vertex += vBufPtr->getVertexSize())
						{
							pPosElement->baseVertexPointerToElement(vertex, &pReal);

							Ogre::Vector3 pt(pReal[0], pReal[1], pReal[2]);
							points.push_back(pt);
						}
						//////////////////////////////////////////////////////////////////////////
						//����buffer
						Ogre::HardwareIndexBufferSharedPtr iBufPtr = renderOperation.indexData->indexBuffer;
						Ogre::HardwareIndexBuffer::IndexType indexType = iBufPtr->getType();
						Ogre::uint32 indexSize = iBufPtr->getIndexSize();
						void* pIBufData = iBufPtr->lock(renderOperation.indexData->indexStart * indexSize,
							renderOperation.indexData->indexCount * indexSize,
							Ogre::HardwareBuffer::HBL_READ_ONLY);

						Ogre::uint16* pIndexData16(NULL);
						Ogre::uint32* pIndexData32(NULL);
						if (indexType == HardwareIndexBuffer::IT_16BIT)
						{
							pIndexData16 = static_cast<Ogre::uint16*>(pIBufData);
						}
						else if (indexType == HardwareIndexBuffer::IT_32BIT)
						{
							pIndexData32 = static_cast<Ogre::uint32*>(pIBufData);
						}
						Ogre::Vector3 v1,v2,v3;
						Ogre::Real x,y,z;
						for (Ogre::uint32 i = 0 ; i < renderOperation.indexData->indexCount ; i+=3)
						{
							Ogre::uint32 index1,index2,index3;
							if (NULL != pIndexData16)
							{
								index1 = pIndexData16[i];
								index2 = pIndexData16[i+1];
								index3 = pIndexData16[i+2];
							}
							else if (NULL != pIndexData32)
							{
								index1 = pIndexData32[i];
								index2 = pIndexData32[i+1];
								index3 = pIndexData32[i+2];
							}
							v1 = points[index1];
							v2 = points[index2];
							v3 = points[index3];

							std::pair<bool,Ogre::Real> result = Ogre::Math::intersects(
								curRay,
								worldMatrix * v1,
								worldMatrix * v2,
								worldMatrix * v3,true,true);
							if (result.first && result.second < intersectDis)
							{
								intersectDis = result.second;
								resultValue.first = true;
								resultValue.second = intersectDis;
							}
						}
						points.clear();
						vBufPtr->unlock();
						iBufPtr->unlock();
#else
						//����buffer
						const Ogre::VertexElement* pPosElement = renderOperation.vertexData->vertexDeclaration->findElementBySemantic(Ogre::VES_POSITION);
						Ogre::HardwareVertexBufferSharedPtr vBufPtr = renderOperation.vertexData->vertexBufferBinding->getBuffer(pPosElement->getSource());
						Ogre::int32 vertexSize = renderOperation.vertexData->vertexDeclaration->getVertexSize(pPosElement->getSource());
						//Ogre::Real* pVBufData /*= (Ogre::Real*)vBufPtr->lock(ro.vertexData->vertexStart * vertexSize,
						//	ro.vertexData->vertexCount * vertexSize,
						//	Ogre::HardwareBuffer::HBL_READ_ONLY)*/;
						//////////////////////////////////////////////////////////////////////////
						unsigned char* vertex = static_cast<unsigned char*>(vBufPtr->lock(Ogre::HardwareBuffer::HBL_READ_ONLY));
						float* pReal;
						std::vector<Ogre::Vector3> points;
						for( size_t j = 0; j < renderOperation.vertexData->vertexCount; ++j, vertex += vBufPtr->getVertexSize())
						{
							pPosElement->baseVertexPointerToElement(vertex, &pReal);

							Ogre::Vector3 pt(pReal[0], pReal[1], pReal[2]);
							points.push_back(pt);
						}
						//////////////////////////////////////////////////////////////////////////

						/*Ogre::uint32 offset = pPosElement->getOffset();
						Ogre::uint32 vertexSkip = vertexSize;*/

						//����buffer
						Ogre::HardwareIndexBufferSharedPtr iBufPtr = renderOperation.indexData->indexBuffer;
						Ogre::HardwareIndexBuffer::IndexType indexType = iBufPtr->getType();
						Ogre::uint32 indexSize = iBufPtr->getIndexSize();
						void* pIBufData = iBufPtr->lock(renderOperation.indexData->indexStart * indexSize,
							renderOperation.indexData->indexCount * indexSize,
							Ogre::HardwareBuffer::HBL_READ_ONLY);

						//void* pVB = new Ogre::uchar[ro.vertexData->vertexCount * vertexSize];
						void* pIB = new Ogre::uint16[renderOperation.indexData->indexCount * indexSize];
						//memcpy(pVB,pVBufData,ro.vertexData->vertexCount * vertexSize);
						memcpy(pIB,pIBufData,renderOperation.indexData->indexCount * indexSize);
						//pVBufData = static_cast<Ogre::Real*>(pVB);
						pIBufData = pIB;
						vBufPtr->unlock();
						iBufPtr->unlock();
						Ogre::uint16* pIndexData16(NULL);
						Ogre::uint32* pIndexData32(NULL);
						if (indexType == HardwareIndexBuffer::IT_16BIT)
						{
							pIndexData16 = static_cast<Ogre::uint16*>(pIBufData);
						}
						else if (indexType == HardwareIndexBuffer::IT_32BIT)
						{
							pIndexData32 = static_cast<Ogre::uint32*>(pIBufData);
						}
						Ogre::Vector3 v1,v2,v3;
						Ogre::Real x,y,z;
						for (Ogre::uint32 i = 0 ; i < renderOperation.indexData->indexCount ; i+=3)
						{
							Ogre::uint32 index1,index2,index3;
							if (NULL != pIndexData16)
							{
								index1 = pIndexData16[i];
								index2 = pIndexData16[i+1];
								index3 = pIndexData16[i+2];
							}
							else if (NULL != pIndexData32)
							{
								index1 = pIndexData32[i];
								index2 = pIndexData32[i+1];
								index3 = pIndexData32[i+2];
							}
							////��һ����������
							//Ogre::Real* pPosData = pVBufData + index1 * vertexSkip + offset;
							//x = *pPosData++;
							//y = *pPosData++;
							//z = *pPosData++;
							//v1 = Ogre::Vector3(x,y,z);

							////�ڶ�����������
							//pPosData = pVBufData + index2 * vertexSkip + offset;
							//x = *pPosData++;
							//y = *pPosData++;
							//z = *pPosData++;
							//v2 = Ogre::Vector3(x,y,z);

							////��������������
							//pPosData = pVBufData + index3 * vertexSkip + offset;
							//x = *pPosData++;
							//y = *pPosData++;
							//z = *pPosData++;
							//v3 = Ogre::Vector3(x,y,z);
							v1 = points[index1];
							v2 = points[index2];
							v3 = points[index3];

							std::pair<bool,Ogre::Real> result = Ogre::Math::intersects(
								curRay,
								worldMatrix * v1,
								worldMatrix * v2,
								worldMatrix * v3,true,true);
							if (result.first && result.second < intersectDis)
							{
								intersectDis = result.second;
								resultValue.first = true;
								resultValue.second = intersectDis;
							}
						}
						delete pIB;
						points.clear();
#endif

					}
				}
			}
			return resultValue;
		}

		std::pair<bool, Ogre::Real> CGeoRayIntersector::intersect(Ogre::Ray& ray,Ogre::SubEntity* pSubEntity,const Ogre::Matrix4& worldMatrix)
		{
			assert(pSubEntity);
			if (NULL == pSubEntity)
				return std::pair<bool,Ogre::Real>(false,0);

			Ogre::SubMesh* pSubMesh = pSubEntity->getSubMesh();
			Ogre::RenderOperation ro;
			pSubMesh->_getRenderOperation(ro);
			return CGeoRayIntersector::intersect(ray,ro,worldMatrix);
		}

		std::pair<bool, Ogre::Real> CGeoRayIntersector::intersect(Ogre::Ray& ray,Ogre::Entity* pEntity,const Ogre::Matrix4& worldMatrix)
		{
			assert(pEntity);
			if (NULL == pEntity)
				return std::pair<bool,Ogre::Real>(false,0);

			RealVector rv;
			unsigned int numOfSubEntity = pEntity->getNumSubEntities();
			for (unsigned int i = 0 ; i < numOfSubEntity ; ++i)
			{
				Ogre::SubEntity* pSubEntity = pEntity->getSubEntity(i);
				std::pair<bool,Ogre::Real> r = CGeoRayIntersector::intersect(ray,pSubEntity,worldMatrix);
				if (r.first)
				{
					rv.push_back(r.second);
				}
			}
			std::sort(rv.begin(),rv.end());
			if (rv.size() > Ogre::uint32(0))
			{
				return std::pair<bool,Ogre::Real>(true,*rv.begin());
			}
			else
			{
				return std::pair<bool,Ogre::Real>(false,0);
			}
		}
	}
}
