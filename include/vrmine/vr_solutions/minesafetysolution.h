#ifndef _MINESAFESOLUTION_H
#define _MINESAFESOLUTION_H

#include "vrmine\vr_solutions\vr_solutionsconfig.h"
#include "vrmine\vr_core\coredefine.h"
#include "vrmine\vr_scenecontrol\geospatialcontrol.h"
#include "vrmine\vr_spatialrender\spatialrender\drillrenderableobject.h"
#include "vrmine\vr_spatialrender\baserender\multipoint.h"
#include "vrmine\vr_spatialrender\baserender\multiline.h"
#include "vrmine\vr_spatiallayer\drilllayer.h"
#include "vrmine\vr_scenecontrol\geospatialscene.h"
#include "vrmine\vr_spatialobject\base\geoline.h"


namespace VirtualMine
{
	namespace Solution
	{
		class CSelectedTool;
		class CMineSafetySolution;
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

		class CDrillingListener : public Ogre::FrameListener
		{
		public:
			CDrillingListener(CMineSafetySolution* ref_pSolution);

			virtual ~CDrillingListener();

			virtual bool frameStarted(const Ogre::FrameEvent& evt);
		protected:
			CMineSafetySolution* ref_mpSolution;
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

		class VR_SOLUTIONS_DLL CMineSafetySolution : public CMineSolution
		{
			friend class CSelectedTool;
		public:

			CMineSafetySolution(const std::string& name);

			virtual ~CMineSafetySolution();

			virtual void setAccidentPoint(const Ogre::Vector3& accidentPoint);

			virtual void selectAccidentPoint();

			virtual void setVerticalSurfacePoint(const Ogre::Vector3& accidentPoint);

			virtual  Ogre::Vector3 getVerticalSurfacePoint();

			virtual Ogre::Vector3& getAccidentPoint();

			virtual void analyseOptimalPoint();

			virtual void setOptimalPoint(const Ogre::Vector3& optimalPoint);

			virtual Ogre::Vector3 getOptimalPoint();

			virtual void addSurfaceNearerPoint(const Ogre::Vector3& nearerPoint);

			virtual Ogre::Vector3 getSurfaceNearerPoint(const int& index);

			virtual int getSurfaceNearerPointCount();

			virtual void flushSolutionToScene();

			virtual void drillingToAccident();

			virtual void stopDrilling();

			virtual void continueDrilling();

			virtual void drillingAgain();

			virtual void beginEditingSolution();

			virtual void endEditingSolution(const bool& needSave);

			virtual void analyseSurfaceNearerPoints();

			virtual void reset();

			bool frameStarted(const Ogre::FrameEvent& evt);

			virtual void setAnalysisRadius(const Ogre::Real& analysisRadius);

			virtual Ogre::Real getAnalysisRadius();

			virtual void setSamplingDensity(const int& samplingDensity);

			virtual int getSamplingDensity();

			virtual void setSamplingPointCount(const int& samplingPointCount);

			virtual int getSamplingPointCount();

			virtual void setAnalysisOffsetY(const Ogre::Real& analysisOffsetY);

			virtual Ogre::Real getAnalysisOffsetY();

			virtual Ogre::Real getMaxDrillAngle();

			virtual void setMaxDrillAngle(const Ogre::Real& maxDrillAngle);

			virtual void toFile(const std::string& file);
 
            virtual void fromFile(const std::string& file);

		protected:

			virtual void innerAnalyseOptimalPoint(std::vector<CStatistionInfo>& slopeStatistic);

			virtual void renderNearerLines();

			virtual void renderPoints();

			virtual VirtualMine::Base::CGeoLine* createGeoLine(const Ogre::Vector3& p1,
				const Ogre::Vector3& p2,
				const Ogre::ColourValue& color);

			virtual VirtualMine::Base::CGeoLine* createGeoLine(CoorVector& points,
				const Ogre::Vector3 terminalPoint,
				const Ogre::ColourValue& color);

			virtual void computeStatistic(const Ogre::Vector3& originPoint,
				const Ogre::Vector3& dir,const Ogre::Real& radius,
				CoorVector& results);

		protected:
			Ogre::Real mAnalysisRadius;
			std::vector<CStatistionInfo> mSlopeStatistic;
			int mSamplingDensity;
			int mSamplingPointCount;//每个方向的采样点个数
			float mAnalysisOffsetY;
			Ogre::Real mMaxDrillAngle;
			VirtualMine::Base::CGeoLine* mpDynamicCircleLine;
			Ogre::Vector3 mPreAnalysisPoint;
			int mAnalysisProgress;
			Ogre::Vector3 mAccidentPoint;
			Ogre::Vector3 mOptimalPoint;
			CDrillingListener* mpDrillListener;
			Ogre::Vector3 mVerticalSurfacePoint;
			VirtualMine::SpatialInterface::GeoObjectMap mSurfaceNearerDrills;
			int mNearerPointCount;
			bool mIsDrillingState;
			bool mIsAnalysisState;
			bool mCanSelectAccident;
			Ogre::Real mDrillingProgress;
			Ogre::Real mDrillLength;
			Ogre::Quaternion mTiltRotation;
			VirtualMine::SpatialRender::CDrillRenderableObject* mpDrillRenderObject;
			VirtualMine::BaseRender::CMultiPoint* mpNearerRenderPoints;
			VirtualMine::BaseRender::CMultiLine* mpNearerRenderLines;
			VirtualMine::BaseRender::CMultiLine* mpAnalysisLines;
			CSelectedTool* mpSelectedTool;
			VirtualMine::Scene::CGeoSpatialScene* ref_mpGeoScene;
			VirtualMine::SpatialLayer::CDrillLayer* ref_mpDrillLayer;
		};

		class CLanewayListener;
	}
}
#endif

