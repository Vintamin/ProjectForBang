

#if !defined(_PROLANEWAYSTYLE_H)
#define _PROLANEWAYSTYLE_H

#include "vrmine\vr_style\style_config.h"
#include "vrmine/vr_spatialinterface/istyle.h"
#include <map>

namespace VirtualMine
{
	namespace Style
	{
		//巷道截面类型
		typedef enum LanewaySectionType
		{
			//拱形
			Arch,  

			//梯形
			Trapezoid, 

			Circle,
		};

		//巷道支护类型
		typedef enum LanewaySuppoetType
		{
			//未知
			Unknown,

			//工字钢
			IBeam,

			//红砖
			Brick,

			//料石
			Ashlar,

			//锚喷
			Anchor,

			//喷浆
			Guniting
		};

		//巷道渲染状态
		typedef enum LanewayStateType
		{
			//普通环境
			LST_NORMAL,

			//淹没环境
			LST_FLOOD,

			//通风环境
			LST_WIND
		};

		//巷道通风类型
		typedef enum LanewayWindType
		{
			//无风
			LWT_NOAIR,

			//进风 正
			LWT_FRESHAIR_FORWARD,

			//进风 反
			LWT_FRESHAIR_REVERSE,

			//回风 正
			LWT_WASTEAIR_FORWARD,

			//回风 反
			LWT_WASTEAIR_REVERSE
		};

		class VR_STYLE_DLL CProLanewayStyle : public VirtualMine::SpatialInterface::CStyle
		{
		public:
			CProLanewayStyle();
			~CProLanewayStyle();

		public:
			void setWidth(const Ogre::Real& width);
			Ogre::Real getWidth();

			void setHeight(const Ogre::Real& height);
			Ogre::Real getHeight();

			void setSmoothFactor(const Ogre::Real& factor);
			Ogre::Real getSmoothFactor();

			void setSectionType(LanewaySectionType sectionType = LanewaySectionType::Arch);
			LanewaySectionType getSectionType();

			void setSupportType(LanewaySuppoetType supportType = LanewaySuppoetType::Unknown);
			LanewaySuppoetType getSupportType();

			void setLanewayStateType(const LanewayStateType& state);
			LanewayStateType getLanewayStateType();

			//static std::string getSupportImg(LanewaySuppoetType supportType = LanewaySuppoetType::Unknown);
			std::string getSupportImg();

			void setWindType(const  LanewayWindType& windType);
			LanewayWindType getWindType();

			std::string toString();
		private:
			Ogre::Real mWidth;
			Ogre::Real mHeight;
			Ogre::Real mSmoothFactor; // 拐点平滑因子
			LanewaySectionType mSectionType;
			LanewaySuppoetType mSupportType;
			LanewayStateType mState;
			LanewayWindType mWindType;

			static std::map<LanewaySuppoetType,std::string> mMapSupportImg;

		private:
			static std::map<LanewaySuppoetType,std::string> createMapSupportImg();

		};
	}
}

#endif  //_LANEWAYSTYLE_H
