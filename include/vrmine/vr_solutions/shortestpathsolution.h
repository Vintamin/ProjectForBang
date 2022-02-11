#ifndef _SHORTESTPATHSOLUTION_H
#define _SHORTESTPATHSOLUTION_H

#include "vrmine\vr_solutions\vr_solutionsconfig.h"
#include "vrmine\vr_core\coredefine.h"
#include "vrmine\vr_scenecontrol\geospatialcontrol.h"
#include "vrmine\vr_spatialrender\spatialrender\lanewayrenderableobject.h"
#include "vrmine\vr_spatialrender\baserender\multipoint.h"
#include "vrmine\vr_spatialrender\baserender\multiline.h"
#include "vrmine\vr_spatiallayer\lanwaylayer.h"
#include "vrmine\vr_scenecontrol\geospatialscene.h"
#include "vrmine\vr_spatialobject\base\geoline.h"


namespace VirtualMine
{
	namespace Solution
	{
		class CLaneSelectedTool;
		class CShortestPathSolution;
		class VR_SOLUTIONS_DLL CStatistionInfo
		{
		public:
			CStatistionInfo()
			{
				Slope = DBL_MAX;
				Distance = DBL_MAX;
				Point = Ogre::Vector3::ZERO;
			}
			~CStatistionInfo()
			{}
		public:

			Ogre::Real Slope;
			Ogre::Real Distance;
			Ogre::Vector3 Point;
		};

		class CLanewayListener : public Ogre::FrameListener
		{
		public:
			CLanewayListener(CShortestPathSolution* ref_pSolution);

			virtual ~CLanewayListener();

			virtual bool frameStarted(const Ogre::FrameEvent& evt);
		protected:
			CShortestPathSolution* ref_mpSolution;
		};

		class VR_SOLUTIONS_DLL CMineSolution
		{
		public:

			CMineSolution(const std::string& name);

			virtual ~CMineSolution();

			virtual void setName(const std::string& name);

			virtual std::string getName();

			virtual VirtualMine::Scene::CGeoSpatialControl* getGeoSpatialControl();

			virtual void setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pControl);

			virtual void toFile(const std::string& filePath);

			virtual void fromFile(const std::string& file);   

		protected:
			std::string mName;
			VirtualMine::Scene::CGeoSpatialControl* ref_mpControl;

		};

		class VR_SOLUTIONS_DLL CShortestPathSolution : public CMineSolution
		{
			friend class CSelectedTool;
		public:

			CShortestPathSolution(const std::string& name);

			virtual ~CShortestPathSolution();

			virtual void setFirstPoint(const Ogre::Vector3& firstPoint);

			virtual void selectAccidentPoint();

			virtual void setSecondPoint(const Ogre::Vector3& secondPoint);

			virtual Ogre::Vector3 getSecondPoint();

			virtual Ogre::Vector3 getFirstPoint();

		


            virtual void beginAnalysisSolution();

			virtual void endAnalysisSolution(const bool& needSave);


			virtual void reset();

			bool frameStarted(const Ogre::FrameEvent& evt);

		
			virtual void toFile(const std::string& file);

			virtual void fromFile(const std::string& file);

		protected:

	
			virtual VirtualMine::Base::CGeoLine* createGeoLine(const Ogre::Vector3& p1,
				const Ogre::Vector3& p2,
				const Ogre::ColourValue& color);

			virtual VirtualMine::Base::CGeoLine* createGeoLine(CoorVector& points,
				const Ogre::Vector3 terminalPoint,
				const Ogre::ColourValue& color);

		
		protected:


	
			VirtualMine::Base::CGeoLine* mpDynamicCircleLine;
	

			Ogre::Vector3 mFirstPoint;
			Ogre::Vector3 mSecondPoint;
			CLanewayListener* mpDrillListener;

			int mNearerPointCount;
			bool mIsDrillingState;
			bool mIsAnalysisState;
			bool mCanSelectAccident;
			Ogre::Real mDrillingProgress;
			Ogre::Real mDrillLength;
			Ogre::Quaternion mTiltRotation;
			VirtualMine::SpatialRender::CLanewayRenderableObject* mpDrillRenderObject;
			VirtualMine::BaseRender::CMultiPoint* mpNearerRenderPoints;
			VirtualMine::BaseRender::CMultiLine* mpNearerRenderLines;
			VirtualMine::BaseRender::CMultiLine* mpAnalysisLines;
			CSelectedTool* mpSelectedTool;
			VirtualMine::Scene::CGeoSpatialScene* ref_mpGeoScene;
			VirtualMine::SpatialLayer::CLanewayLayer* ref_mpDrillLayer;
		};


	}
}
#endif

