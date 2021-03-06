//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : line.h
//  @ Date : 2014/8/4
//  @ Author : 朱炜鹏
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_LANEWAY_H)
#define _LANEWAY_H

#include "vrmine/vr_spatialinterface/igeometry.h"
#include "vrmine\vr_geometry\geometry\geometry_config.h"
#include "vrmine/vr_core/coredefine.h"
#include <OGRE/Ogre.h>
#include <string>

namespace VirtualMine
{
	namespace Geometry
	{
		//巷道节点
		class VR_GEOMETRY_DLL CLaneWayNodeGeometry : public VirtualMine::SpatialInterface::CGeometry
		{
		public: 
			CLaneWayNodeGeometry();
			~CLaneWayNodeGeometry();

		public:
			void setName(const Ogre::String& name);
			Ogre::String getName();

			void setPosition(const Ogre::Vector3& position);
			Ogre::Vector3 getPosition();

			void setPreNode(CLaneWayNodeGeometry* preNode);
			CLaneWayNodeGeometry* getPreNode();

			void setNextNode(CLaneWayNodeGeometry* nextNode);
			CLaneWayNodeGeometry* getNextNode();

			void setIsIntersection(bool isIntersection);
			bool getIsIntersection();

			void addLanewayLine(const Ogre::String& lineName);
			std::vector<Ogre::String> getBelongLanewayLine();

			virtual void toStream(VirtualMine::Core::CVRDataStream& datastream);
			virtual void fromStream(VirtualMine::Core::CVRDataStream& datastream);


		private:
			std::string	mName;
			Ogre::Vector3	mPosition;
			CLaneWayNodeGeometry*		mPreNode;
			CLaneWayNodeGeometry*		mNextNode;
			bool			mIsIntersection;
			//kk StringVector换成std::vector<Ogre::String>
			std::vector<Ogre::String>    mBelongLanewayLine;
		};

		//巷道截面
		class VR_GEOMETRY_DLL CLaneWaySection
		{
		public:
			CLaneWaySection();
			~CLaneWaySection();
		public:
			//截面绕Y轴旋转
			void Rotate(Ogre::Radian angle);
			//按指定四维数变换
			void Rotate(Ogre::Quaternion quaternion);
			//截面平移
			void setPosition(Ogre::Vector3 position);
			void setPoints(Ogre::Vector3* points,int pointsCount);

			int getPointsCount();
			Ogre::Vector3* getPoints();
		private:
			Ogre::Vector3*	mPoints;
			int mPointsCount;
		};

		//单条巷道
		class VR_GEOMETRY_DLL CLaneWayLineGeometry : public VirtualMine::SpatialInterface::CGeometry
		{
		public:
			CLaneWayLineGeometry();
			~CLaneWayLineGeometry();
		public:
			void setName(const Ogre::String& name);
			Ogre::String getName();
             
            ////在最后位置加一个节点
			void addNode(CLaneWayNodeGeometry* node); 
            /////在巷道的某一个节点preNode后加一个节点
            void addNode(CLaneWayNodeGeometry* node,CLaneWayNodeGeometry* preNode);

			void deleteNode(CLaneWayNodeGeometry* node);

			//按索引返回节点
			CLaneWayNodeGeometry* getNode(const int& index);

			//按名称返回节点
			CLaneWayNodeGeometry* getNode(const Ogre::String& name);

			IGeometry* clone();

		    int getNodesCount();
			std::vector<CLaneWayNodeGeometry*> getNodes();

			void addSection(CLaneWaySection* section);
			CLaneWaySection* getSection(const int& index);
			int getSectionCount();

			void addFlexSections(std::vector<CLaneWaySection*> flexsections);
			std::vector<CLaneWaySection*> getFlexSections(const int& index);
			int getFlexSectionsCount();

			virtual void toStream(VirtualMine::Core::CVRDataStream& datastream);
			virtual void fromStream(VirtualMine::Core::CVRDataStream& datastream);


		private:
			std::string	mName;
			std::vector<CLaneWayNodeGeometry*>	mNodes;

			std::vector<CLaneWaySection*>  mSections;
			std::vector<std::vector<CLaneWaySection*>>  mFlexSections;
		};

		//巷道交叉节点
		class VR_GEOMETRY_DLL CLaneWayCrossNodeGeometry : public VirtualMine::SpatialInterface::CGeometry
		{
		public:
			CLaneWayCrossNodeGeometry();
			~CLaneWayCrossNodeGeometry();

		public:
			void setCrossNode(CLaneWayNodeGeometry* node);
			CLaneWayNodeGeometry*  getCrossNode();
			void addAdjacentNode(CLaneWayNodeGeometry* node);
			//按索引返回邻接点
			CLaneWayNodeGeometry* getAdjancentNode(const int& index);
			int getAdjancentNodesCount();
			std::vector<CLaneWayNodeGeometry*> getAdjancentNodes();

			void addSection(CLaneWaySection* section);
			CLaneWaySection* getSection(const int& index);
			int getSectionsCount();

			//顺时针排列邻接点
			void clockwiseSortPoints();
		private:
			//若点a大于点b,即点a在点b顺时针方向,返回true,否则返回false
			 bool pointCmp(const Ogre::Vector3 &a,const Ogre::Vector3 &b,const Ogre::Vector3 &center);		
		private:
			CLaneWayNodeGeometry*		mCrossNode;
			std::vector<CLaneWayNodeGeometry*>	 mAdjacentNodes;   //顺时针存储相邻节点
			std::vector<CLaneWaySection*> mSections;
		};
		
		//巷道系统
		class VR_GEOMETRY_DLL CLaneWayGeometry : public VirtualMine::SpatialInterface::CGeometry
		{
		public:
			CLaneWayGeometry();
			~CLaneWayGeometry();
		public:
			void addLanewayLine(CLaneWayLineGeometry* lanewayLine);
			std::vector<CLaneWayLineGeometry*> getLanewayLines();

			void addLanewayIntersection(CLaneWayCrossNodeGeometry* crossNode);
			std::vector<CLaneWayCrossNodeGeometry*> getLanwayIntersection();


			virtual void toStream(VirtualMine::Core::CVRDataStream& datastream);
			virtual void fromStream(VirtualMine::Core::CVRDataStream& datastream);


		private:
			std::string mName;
			std::vector<CLaneWayLineGeometry*> mLanewayLines;
			std::vector<CLaneWayCrossNodeGeometry*> mLanewayIntersections;
		};		
	}
}

#endif  //_LINE_H
