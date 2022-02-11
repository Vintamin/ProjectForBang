//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : ctunnelmeshcreator.h
//  @ Date : 2021/11/29
//  @ Author : 李佳康
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_CLANWAYPROMESHCREATOR_H)
#define _CLANWAYPROMESHCREATOR_H

#include "vrmine/vr_spatialinterface/igeomeshcreator.h"
#include "vrmine/vr_geometry/geometry/laneway.h"
#include "vrmine/vr_style/style/lanewaystyle.h"
#include "vrmine/vr_mathenine/mathengine/mathcalculator.h"
#include "vrmine\vr_arithmetic\arithmetic_config.h"
#include <vector>




namespace VirtualMine
{
	namespace Arithmetic
	{
		class VR_ARITHMETIC_DLL CLanewayProgress_MeshCreator : public VirtualMine::SpatialInterface::CGeoMeshCreator
		{
		public: 
			CLanewayProgress_MeshCreator();
			~CLanewayProgress_MeshCreator();
		public:
			void createData(VirtualMine::SpatialInterface::GeoObjectVector& geoObjectVector,std::vector<VirtualMine::SpatialInterface::CGeoExtentionData*>& geoExtentionDatas,std::vector<Ogre::SceneNode*> &mTextNodes);

			void createDataShortPath(VirtualMine::SpatialInterface::GeoObjectVector& geoObjectVector,std::vector<VirtualMine::SpatialInterface::CGeoExtentionData*>& geoExtentionDatas);


		private:
			//从原始数据提取巷道线路
			void createLanewayLineCollection();

			//检索巷道数据，构建巷道交叉节点
			void createIntersectionCollection();

			//创建单个截面 
			VirtualMine::Geometry::CLaneWaySection* createSection(VirtualMine::Style::CLanewayStyle* lanewayStyle);

			VirtualMine::Geometry::CLaneWaySection* createSecionShortPath(Ogre::Vector3 refPoint);

			//构建直线和拐点部分
			void buildLinePart();

			void buildLinePartShortPath(std::vector<Ogre::Vector3> points);

			//kk定义渲染工程进度日期文字的函数
			void  buildTextProgress(const Ogre::String& lineName,Ogre::Vector3 center);
			//kk定义分段创建manuobject的函数
			void buildProgressPart(VirtualMine::Geometry::CLaneWayLineGeometry* line,int start,int end,Ogre::String name,VirtualMine::Style::LanewaySuppoetType type,Ogre::Vector3 textPos,Ogre::String& message);
			
			//kk定义传递过来的mTextNodes
			std::vector<Ogre::SceneNode*> *mBuildTextNodes;

			//构建交叉的截面部分
			void buildIntersectionPart();

			//按名称判断是否添加了交叉点
			bool hasCrossNode(const Ogre::String& name);

			//按巷道名称返回巷道
			VirtualMine::Geometry::CLaneWayLineGeometry* getLanewayLine(const Ogre::String& lineName);

			//计算交叉点截面的偏移
			Ogre::Vector3 getCrossOffsetPos(VirtualMine::Geometry::CLaneWayNodeGeometry* sourcePos,VirtualMine::Geometry::CLaneWayCrossNodeGeometry* crossNode,VirtualMine::Style::CLanewayStyle* lanewayStyle);
		private :	
			std::vector<VirtualMine::Geometry::CLaneWayCrossNodeGeometry*> mLanewayCrossNodes;
			std::vector<VirtualMine::Geometry::CLaneWayLineGeometry*> mLanewayLines;
			VirtualMine::Style::CLanewayStyle* mpStyle;		
		};
	}
}

#endif  //_CLANWAYPROMESHCREATOR_H
