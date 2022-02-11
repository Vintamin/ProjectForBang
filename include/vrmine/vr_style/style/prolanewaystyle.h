

#if !defined(_PROLANEWAYSTYLE_H)
#define _PROLANEWAYSTYLE_H

#include "vrmine\vr_style\style_config.h"
#include "vrmine/vr_spatialinterface/istyle.h"
#include <map>

namespace VirtualMine
{
	namespace Style
	{
		//�����������
		typedef enum LanewaySectionType
		{
			//����
			Arch,  

			//����
			Trapezoid, 

			Circle,
		};

		//���֧������
		typedef enum LanewaySuppoetType
		{
			//δ֪
			Unknown,

			//���ָ�
			IBeam,

			//��ש
			Brick,

			//��ʯ
			Ashlar,

			//ê��
			Anchor,

			//�罬
			Guniting
		};

		//�����Ⱦ״̬
		typedef enum LanewayStateType
		{
			//��ͨ����
			LST_NORMAL,

			//��û����
			LST_FLOOD,

			//ͨ�绷��
			LST_WIND
		};

		//���ͨ������
		typedef enum LanewayWindType
		{
			//�޷�
			LWT_NOAIR,

			//���� ��
			LWT_FRESHAIR_FORWARD,

			//���� ��
			LWT_FRESHAIR_REVERSE,

			//�ط� ��
			LWT_WASTEAIR_FORWARD,

			//�ط� ��
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
			Ogre::Real mSmoothFactor; // �յ�ƽ������
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
