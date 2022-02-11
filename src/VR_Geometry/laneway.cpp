//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : cylinder.cpp
//  @ Date : 2014/8/4
//  @ Author : 朱炜鹏
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine/vr_geometry/geometry/laneway.h"
#include "vrmine/vr_mathenine/mathengine/mathcalculator.h"
#include <string>
#include "vrmine/vr_spatialinterface/iscene.h"
#include <algorithm>

using namespace std;
using namespace VirtualMine::SpatialInterface;

namespace VirtualMine
{
	namespace Geometry
	{
		#pragma region 巷道节点实现
		CLaneWayNodeGeometry::CLaneWayNodeGeometry()
		{
			this->mName = Ogre::String("");
			mPosition = Ogre::Vector3::ZERO;
			mPreNode = NULL;
			mNextNode = NULL;
			mIsIntersection = false;
		}

		CLaneWayNodeGeometry::~CLaneWayNodeGeometry()
		{
			if (this->mPreNode!= NULL)
			{
				delete this->mPreNode;
				this->mPreNode = NULL;
			}
			
			if (this->mNextNode != NULL)
			{
				delete this->mNextNode;
				this->mNextNode = NULL;
			}
		}

		void CLaneWayNodeGeometry::setName(const Ogre::String& name)
		{
			this->mName = name;
		}

		Ogre::String CLaneWayNodeGeometry::getName()
		{
			return this->mName;
		}

		void CLaneWayNodeGeometry::setPosition(const Ogre::Vector3& position)
		{
			this->mPosition = position;
		}

		Ogre::Vector3 CLaneWayNodeGeometry::getPosition()
		{
			return this->mPosition;
		}

		void CLaneWayNodeGeometry::setPreNode(CLaneWayNodeGeometry* preNode)
		{
			this->mPreNode = preNode;
		}

		CLaneWayNodeGeometry* CLaneWayNodeGeometry::getPreNode()
		{

			return this->mPreNode;
		}

		void CLaneWayNodeGeometry::setNextNode(CLaneWayNodeGeometry* nextNode)
		{
			this->mNextNode = nextNode;
		}

		CLaneWayNodeGeometry* CLaneWayNodeGeometry::getNextNode()
		{
			return this->mNextNode;
		}

		void CLaneWayNodeGeometry::setIsIntersection(bool isIntersection)
		{
			this->mIsIntersection = isIntersection;
		}

		bool CLaneWayNodeGeometry::getIsIntersection()
		{
			return this->mIsIntersection;
		}

		void CLaneWayNodeGeometry::addLanewayLine(const Ogre::String& lineName)
		{
			this->mBelongLanewayLine.push_back(lineName);
		}

		StringVector CLaneWayNodeGeometry::getBelongLanewayLine()
		{
			return this->mBelongLanewayLine;
		}



		void CLaneWayNodeGeometry::toStream(VirtualMine::Core::CVRDataStream& datastream)
		{
			datastream.wirteString(this->mName);

			datastream.wirteReal(this->mPosition.x);
			datastream.wirteReal(this->mPosition.y);
			datastream.wirteReal(this->mPosition.z);


			/////交叉点信息

			datastream.wirteBool(this->mIsIntersection);
			datastream.wirteInt32(mBelongLanewayLine.size());
			for (int i = 0; i < mBelongLanewayLine.size();i++)
			{
				datastream.wirteString(mBelongLanewayLine[i]);
			}
		}

		void CLaneWayNodeGeometry::fromStream(VirtualMine::Core::CVRDataStream& datastream)
		{ 
			std::string s;
			datastream.readString(s);
			this->mName = s;

	/*		for (int i =0 ; s[i] != '\0';i++ )
			{
				string tmp;
				char c;
				c = s[i];
				tmp = c;
				this->mName.append(tmp);

			}
	*/
			int len = this->mName.length();


			datastream.readReal(this->mPosition.x);
			datastream.readReal(this->mPosition.y);
			datastream.readReal(this->mPosition.z);
	
			this->mPosition.x = this->mPosition.x - IScene::ReferenceCenter.x;
			this->mPosition.z = this->mPosition.z - IScene::ReferenceCenter.z;
			this->mPosition.y = this->mPosition.y - IScene::ReferenceCenter.y;
			this->mPosition.z *= IScene::CoefficientOfCoordinateTransform;

			datastream.readBool(this->mIsIntersection);
			int length(0);
			datastream.readInt32(length);
		
			////可以直接赋值？
			for(int i = 0; i < length; i++)
			{
			std::string belong;
			datastream.readString(belong);
			//////不是空格,通过条件语句判断
			//
	//		string tr = belong;
	//		string tre ;
	//		//	
	//			for (int i =0 ; belong[i] != '\0';i++ )
	//			{
	//				string tmp;
	//			char c;
	//			c = belong[i];
	//			tmp = c;
	//			tre.append(tmp);

	//			}

	//		//	if (tr == tre)
	//		//	{
	//		//		int i = 100;
	//		//	}





	///*			char *p = new char[belong.size()+1];
	//			strcpy(p,belong.c_str());
	//		
	//		    printf("result = %s\n",belong);
	//			printf("result = %s\n",p);
	//			int begin = 0,second = 0;
	//			begin = belong.find(" ",begin); 
	//			belong.find("?",begin);
	//			belong.find("",begin);
	//			belong.find("\0",begin);
	//			belong.find("/0",begin);
	//			belong.find("\t",begin);
	//			
	//		    belong.find('\0',begin);
	//			belong.find('0',begin);
	//			belong.find('/0',begin);
	//			belong.find(' ',begin);
	//			belong.find('?',begin);
	//			belong.find('/t',begin);*/


				mBelongLanewayLine.push_back(belong);
			}

		}
#pragma endregion 

		#pragma region 巷道截面实现
		CLaneWaySection::CLaneWaySection():mPoints(NULL)
		{

		}

		CLaneWaySection::~CLaneWaySection()
		{
			delete mPoints;
			mPoints = NULL;
		}

		void CLaneWaySection::setPoints(Ogre::Vector3* points,int pointsCount)
		{
			this->mPoints = points;
			this->mPointsCount = pointsCount;
		}

		int CLaneWaySection::getPointsCount()
		{
			return this->mPointsCount;
		}

		Ogre::Vector3* CLaneWaySection::getPoints()
		{
			return this->mPoints;
		}

		//截面绕Y轴旋转
		void CLaneWaySection::Rotate(Ogre::Radian angle)
		{
			Ogre::Quaternion q;
			q.FromAngleAxis(angle,Ogre::Vector3::UNIT_Y);

			for (int i = 0 ; i< mPointsCount;i++)
			{
				mPoints[i] = q * mPoints[i];
			}
		}

		//按指定四维数变换
		void CLaneWaySection::Rotate(Ogre::Quaternion quaternion)
		{
			for (int i = 0 ; i< mPointsCount;i++)
			{
				mPoints[i] = quaternion * mPoints[i];
			}
		}

		//截面平移
		void CLaneWaySection::setPosition(Ogre::Vector3 position)
		{
			for (int i = 0 ; i< mPointsCount;i++)
			{
				mPoints[i] += position;

			}
		}
#pragma endregion 

		#pragma region 单条巷道实现

		CLaneWayLineGeometry::CLaneWayLineGeometry()
		{
			this->mName = Ogre::String("");
		}

		CLaneWayLineGeometry::~CLaneWayLineGeometry()
		{
			if (this->mNodes.size()>0)
			{
				for (std::vector<CLaneWayNodeGeometry *>::iterator ite = this->mNodes.begin(); ite != this->mNodes.end(); ++ite) 
				{
					if (NULL != *ite) 
					{
						delete *ite; 
						*ite = NULL;
					}
				}				
				this->mNodes.clear();
			}
			
			if (this->mSections.size()>0)
			{
				for (std::vector<CLaneWaySection *>::iterator ite = this->mSections.begin(); ite != this->mSections.end(); ++ite) 
				{
					if (NULL != *ite) 
					{
						delete *ite; 
						*ite = NULL;
					}
				}				
				this->mSections.clear();
			}

			if (mFlexSections.size()>0)
			{
				for (std::vector<std::vector<CLaneWaySection*>>::iterator ite = this->mFlexSections.begin(); ite != this->mFlexSections.end(); ++ite) 
				{
					std::vector<CLaneWaySection*> sections = (*ite);
					if (sections.size()>0)
					{
						std::vector<CLaneWaySection*>::iterator itrBegin = sections.begin();
						std::vector<CLaneWaySection*>::iterator itrEnd = sections.end();
						while (itrBegin != itrEnd)
						{
							delete (*itrBegin);
							(*itrBegin) = NULL;
						}
						sections.clear();
					}
				}				
				this->mSections.clear();
			}

		}

		void CLaneWayLineGeometry::setName(const Ogre::String& name)
		{
			this->mName = name;
		}

		Ogre::String CLaneWayLineGeometry::getName()
		{
			return this->mName;
		}

		IGeometry* CLaneWayLineGeometry::clone()
		{
			return NULL;
		}

		void CLaneWayLineGeometry::addNode(CLaneWayNodeGeometry* node)
		{
			int nodesCount = this->mNodes.size();
			if (nodesCount > 0)
			{
				node->setPreNode(this->getNode(nodesCount-1));
				this->getNode(nodesCount-1)->setNextNode(node);
			}
			this->mNodes.push_back(node);
		}

		 /////在巷道的某一个节点preNode后加一个节点
		void CLaneWayLineGeometry::addNode( CLaneWayNodeGeometry* node,CLaneWayNodeGeometry* preNode )
		{

			if (node && preNode && preNode->getNextNode())
			{
				node->setNextNode(preNode->getNextNode());
				node->getNextNode()->setPreNode(node);
			}
			if (preNode && node)
			{
				preNode->setNextNode(node);
				node->setPreNode(preNode);
			}
		
			int nodesCount = this->mNodes.size();
			int preNodeIndex(0);
			std::vector<CLaneWayNodeGeometry*>::iterator itr = mNodes.begin();
			while(itr != mNodes.end())
			{

				if ( *itr == preNode)
				{
					//preNodeIndex = ;
					mNodes.insert(itr + 1,node);
					
					break;

				}
				

				itr++;
			}

			//for (int i = 0; i < nodesCount; i++)
			//{
			//	if (mNodes.at(i) == preNode)
			//	{
			//		preNodeIndex = i; 

			//	   //this->mNodes.insert(i,1,node);
		 //  
			//	}
			//	
			//}
	
		}



		CLaneWayNodeGeometry* CLaneWayLineGeometry::getNode(const int& index)
		{
			CLaneWayNodeGeometry* node = this->mNodes[index];
			return node;
		}

		CLaneWayNodeGeometry* CLaneWayLineGeometry::getNode(const Ogre::String& name)
		{
			for (std::vector<CLaneWayNodeGeometry*>::iterator ite = this->mNodes.begin();ite!=this->mNodes.end();ite++)
			{
				CLaneWayNodeGeometry* node = (*ite);
				if (node->getName() == name)
				{
					return node;
				}
			}
		}

		int CLaneWayLineGeometry::getNodesCount()
		{
			return this->mNodes.size();
		}

		std::vector<CLaneWayNodeGeometry*> CLaneWayLineGeometry::getNodes()
		{
			return this->mNodes;
		}

		void CLaneWayLineGeometry::addSection(CLaneWaySection* section)
		{
			this->mSections.push_back(section);
		}

		CLaneWaySection* CLaneWayLineGeometry::getSection(const int& index)
		{
			if (index < this->mSections.size())
			{
				return (CLaneWaySection*)this->mSections[index];
			}
			return NULL;
		}

		int CLaneWayLineGeometry::getSectionCount()
		{
			return this->mSections.size();
		}

		void CLaneWayLineGeometry::addFlexSections(std::vector<CLaneWaySection*> flexSections)
		{
			this->mFlexSections.push_back(flexSections);
		}

		std::vector<CLaneWaySection*> CLaneWayLineGeometry::getFlexSections(const int& index)
		{
			return this->mFlexSections[index];
		}

		int CLaneWayLineGeometry::getFlexSectionsCount()
		{
			return this->mFlexSections.size();
		}

		void CLaneWayLineGeometry::toStream(VirtualMine::Core::CVRDataStream& datastream)
		{ 
			int count = mNodes.size();
			datastream.wirteInt32(count);
			for (int i = 0; i < mNodes.size(); i++)
			{
				mNodes[i]->toStream(datastream);
			}
		}


		void CLaneWayLineGeometry::fromStream(VirtualMine::Core::CVRDataStream& datastream)
		{
			datastream.reseek(0); 
			int length(0);
			datastream.readInt32(length);
			for (int i = 0; i < length; i++)
			{
				CLaneWayNodeGeometry* pLaneWayGeometry  = new CLaneWayNodeGeometry();
					
				pLaneWayGeometry->fromStream(datastream);
				this->addNode(pLaneWayGeometry);
				//this->mNodes.push_back(pLaneWayGeometry);

			}

		}

		void CLaneWayLineGeometry::deleteNode( CLaneWayNodeGeometry* node )
		{
			int nodesCount = this->mNodes.size();
			
			CLaneWayNodeGeometry* preNode = NULL;
			CLaneWayNodeGeometry* nextNode = NULL;

			preNode = node->getPreNode();
			nextNode = node->getNextNode();

			if (preNode)
			{
				preNode->setNextNode(nextNode);
			}
			if (nextNode)
			{
				nextNode->setPreNode(preNode);
			}

			std::vector<CLaneWayNodeGeometry*>::iterator itr = mNodes.begin();
		
			while(itr != mNodes.end())
			{

				if ( *itr == node)
				{

					mNodes.erase(itr);
				    
				

					break;

				}


				itr++;
			}
		}

#pragma endregion 

		#pragma region 巷道交叉点实现
		CLaneWayCrossNodeGeometry::CLaneWayCrossNodeGeometry()
		{
			this->mCrossNode = NULL;
		}

		CLaneWayCrossNodeGeometry::~CLaneWayCrossNodeGeometry()
		{
			if (this->mCrossNode != NULL)
			{
				delete this->mCrossNode;
				this->mCrossNode =NULL;
			}

			if (mAdjacentNodes.size() > 0)
			{
				std::vector<CLaneWayNodeGeometry*>::iterator itr = mAdjacentNodes.begin();
				std::vector<CLaneWayNodeGeometry*>::iterator itrEnd = mAdjacentNodes.end();
				while (itr != itrEnd)
				{
					delete (*itr);
					(*itr) = NULL;
				}
				mAdjacentNodes.clear();
			}

			if (mSections.size()>0)
			{
				std::vector<CLaneWaySection*>::iterator itr = mSections.begin();
				std::vector<CLaneWaySection*>::iterator itrEnd = mSections.end();
				while(itr != itrEnd)
				{
					delete (*itr);
					(*itr)  = NULL;
				}
				mSections.clear();
			}
		}

		void CLaneWayCrossNodeGeometry::setCrossNode(CLaneWayNodeGeometry* node)
		{
			this->mCrossNode = node;
		}

		CLaneWayNodeGeometry* CLaneWayCrossNodeGeometry::getCrossNode()
		{
			return this->mCrossNode;
		}

		void CLaneWayCrossNodeGeometry::addAdjacentNode(CLaneWayNodeGeometry* node)
		{
			this->mAdjacentNodes.push_back(node);
		}

		CLaneWayNodeGeometry* CLaneWayCrossNodeGeometry::getAdjancentNode(const int& index)
		{
			if (index < this->mAdjacentNodes.size())
			{
				return (CLaneWayNodeGeometry*)this->mAdjacentNodes[index];
			}
			return NULL;
		}

		int CLaneWayCrossNodeGeometry::getAdjancentNodesCount()
		{
			return this->mAdjacentNodes.size();
		}

		std::vector<CLaneWayNodeGeometry*> CLaneWayCrossNodeGeometry::getAdjancentNodes()
		{
			return this->mAdjacentNodes;
		}

		void CLaneWayCrossNodeGeometry::addSection(CLaneWaySection* section)
		{
			this->mSections.push_back(section);
		}

		CLaneWaySection*  CLaneWayCrossNodeGeometry::getSection(const int& index)
		{
			if (index < this->mSections.size())
			{
				return (CLaneWaySection*)this->mSections[index];
			}
			return NULL;
		}

		int  CLaneWayCrossNodeGeometry::getSectionsCount()
		{
			return this->mSections.size();
		}

		bool CLaneWayCrossNodeGeometry::pointCmp(const Ogre::Vector3 &a,const Ogre::Vector3 &b,const Ogre::Vector3 &center)
		{
			if (a.x >= 0 && b.x < 0)
				return true;
			if (a.x == 0 && b.x == 0)
				return a.z > b.z;
			//向量OA和向量OB的叉积
			int det = (a.x - center.x) * (b.z - center.z) - (b.x - center.x) * (a.z - center.z);
			if (det < 0)
				return false;
			if (det > 0)
				return true;
			//向量OA和向量OB共线，以距离判断大小
			int d1 = (a.x - center.x) * (a.x - center.x) + (a.z - center.y) * (a.z - center.y);
			int d2 = (b.x - center.x) * (b.x - center.x) + (b.z - center.y) * (b.z - center.y);
			return d1 > d2;		
		}



		void CLaneWayCrossNodeGeometry::clockwiseSortPoints()
		{
			if (this->mAdjacentNodes.size() == 0)
			{
				return;
			}
			Ogre::Vector3 forward = Ogre::Vector3(0,0,1);
			Ogre::Vector3 tempdir = Ogre::Vector3(0,0,1);
			Ogre::Vector3 dir = Ogre::Vector3(0,0,1);
			std::vector<CLaneWayNodeGeometry*> tempNodes;
			for(int i = 0;i < this->mAdjacentNodes.size();i++)
			{
				CLaneWayNodeGeometry* node = mAdjacentNodes[i];
				tempNodes.push_back(node);
			}
			this->mAdjacentNodes.clear();
			float minX = ((CLaneWayNodeGeometry*)tempNodes[0])->getPosition().x;
			int index = 0;
			for (int i = 0;i<tempNodes.size();i++)
			{
				if (minX > ((CLaneWayNodeGeometry*)tempNodes[i])->getPosition().x)
				{
					minX = ((CLaneWayNodeGeometry*)tempNodes[i])->getPosition().x;
					index = i;
				}
			}
			this->mAdjacentNodes.push_back(tempNodes[index]);

			CLaneWayNodeGeometry* maxAngleNode = this->mAdjacentNodes[0];
			while (this->mAdjacentNodes.size() < tempNodes.size())
			{			
				float maxAngle = -10.0f;
				CLaneWayNodeGeometry* node1 = maxAngleNode;
				for(int j = 0;j < tempNodes.size();j++)
				{			
					Ogre::Vector3 pos1 = node1->getPosition();
					pos1.y = 0;
					CLaneWayNodeGeometry* node2 = tempNodes[j];
					bool hasProcess = false;
					for (int k = 0;k<this->mAdjacentNodes.size();k++)
					{
						CLaneWayNodeGeometry* tempNode = this->mAdjacentNodes[k];
						if (node2->getName() == tempNode->getName())
						{
							hasProcess = true;
							break;
						}
					}
					if (hasProcess)
					{
						continue;
					}
					Ogre::Vector3 pos2 = node2->getPosition();
					pos2.y = 0;
					Ogre::Vector3 dir = pos2 - pos1;

					float angle = VirtualMine::MathEngine::CMathCalculator::CalculateAngleOfTwoVector(forward,dir);
					if (angle>maxAngle)
					{
						maxAngle = angle;
						maxAngleNode = node2;
						tempdir = (-1)*dir;
					}					
				}
				forward = tempdir;
				this->mAdjacentNodes.push_back(maxAngleNode);		
			}
		}

		//void CLaneWayCrossNodeGeometry::clockwiseSortPoints()
		//{
		//	//计算重心
		//	  Ogre::Vector3 center;
		//	  Ogre::Real x = 0,z = 0;

		//	 center = this->mCrossNode->getPosition();
		//	
		//	 //冒泡排序
		//		for(int i = 0;i < this->mAdjacentNodes.size() - 1;i++)
		//		{
		//			for (int j = 0;j < this->mAdjacentNodes.size() - i - 1;j++)
		//				{
		//					CLaneWayNodeGeometry* node1 = mAdjacentNodes[j];
		//					CLaneWayNodeGeometry* node2 = mAdjacentNodes[j+1];
		//					if (pointCmp(node1->getPosition(),node2->getPosition(),center))
		//					{
		//						std::swap(node1,node2);
		//					}
		//				}
		//		}
		//}
#pragma endregion 

		#pragma region 巷道系统实现
		CLaneWayGeometry::CLaneWayGeometry()
		{

		}

		CLaneWayGeometry::~CLaneWayGeometry()
		{
			if (mLanewayLines.size()>0)
			{
				std::vector<CLaneWayLineGeometry*>::iterator itr = mLanewayLines.begin();
				std::vector<CLaneWayLineGeometry*>::iterator itrEnd = mLanewayLines.end();
				while (itr != itrEnd)
				{
					delete (*itr);
					(*itr) = NULL;
				}
				mLanewayLines.clear();
			}

			if (mLanewayIntersections.size()>0)
			{
				std::vector<CLaneWayCrossNodeGeometry*>::iterator itr = mLanewayIntersections.begin();
				std::vector<CLaneWayCrossNodeGeometry*>::iterator itrEnd = mLanewayIntersections.end();
				while (itr != itrEnd)
				{
					delete (*itr);
					(*itr) = NULL;
				}
				mLanewayIntersections.clear();
			}
		}

		void CLaneWayGeometry::addLanewayLine(CLaneWayLineGeometry* lanewayLine)
		{
			this->mLanewayLines.push_back(lanewayLine);
		}

		std::vector<CLaneWayLineGeometry*> CLaneWayGeometry::getLanewayLines()
		{
			return this->mLanewayLines;
		}

		void CLaneWayGeometry::addLanewayIntersection(CLaneWayCrossNodeGeometry* crossNode)
		{
			this->mLanewayIntersections.push_back(crossNode);
		}

		std::vector<CLaneWayCrossNodeGeometry*> CLaneWayGeometry::getLanwayIntersection()
		{
			return this->mLanewayIntersections;
		}

		void CLaneWayGeometry::toStream(VirtualMine::Core::CVRDataStream& datastream)
		{
			datastream.wirteInt32(this->mLanewayLines.size());
			for ( int i = 0; i < this->mLanewayLines.size(); i++)
			{
				mLanewayLines[i] = new CLaneWayLineGeometry();
				mLanewayLines[i]->toStream(datastream);
			}
		} 


		void CLaneWayGeometry::fromStream(VirtualMine::Core::CVRDataStream& datastream)
		{
			int length(0);
			datastream.readInt32(length);
			for (int i = 0; i < length; i++)
			{
				mLanewayLines[i]->fromStream(datastream);
			}
		}

#pragma endregion 
	}
}
