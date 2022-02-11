

#if !defined(_PIPESTYLE_H)
#define _PIPESTYLE_H

#include "vrmine\vr_style\style_config.h"
#include "vrmine/vr_spatialinterface/istyle.h"
#include "string"
#include "vrmine/vr_style/style/linestyle.h"


namespace VirtualMine
{
	namespace Style
	{
		class VR_STYLE_DLL CPipeLineStyle :  public VirtualMine::Style::CLineStyle
		{
		public:
			CPipeLineStyle();
			virtual ~CPipeLineStyle();
			void setBoomType(const std::string& type);
			void setBoomID(const int& id);
			void setBoomOrder(const int& order);
			void setStartPositionX(const double& x);
			void setStartPositionY(const double& y);
			void setStartPositionZ(const double& z);
			void setEndPositionX(const double& x);
			void setEndPositionY(const double& y);
			void setEndPositionZ(const double& z);
			void setBoomZhuangYaoLength(const double& length);
			void setBoomShuiPaoNiLength(const double& length);
			void setBoomFengNiLength(const double& length);
			void setBoomProjectID(const int& id);
			void setBoomDepth(const double& depth);
			void setBoomInterval(const double& interval);
			void setBoomLineOfLeastResistance(const double& lineOfLeastResistance);			


			std::string getBoomType();
			int getBoomID();
			int getBoomOrder();
			double getStartPositionX();
			double getStartPositionY();
			double getStartPositionZ();
			double getEndPositionX();
			double getEndPositionY();
			double getEndPositionZ();
			double getBoomZhuangYaoLength();
			double getBoomShuiPaoNiLength();
			double getBoomFengNiLength();
			int getBoomProjectID();
			double getBoomDepth();
			double getBoomInterval();
			double getBoomLineOfLeastResistance();
		private:
			std::string mboomType;
			int mboomID;
			int mboomOrder;
			double startX;
			double startY;
			double startZ;
			double endX;
			double endY;
			double endZ;
			double mboomZhuangYaoLength;
			double mboomShuiPaoNiLength;
			double mboomFengNiLength;
			int projectID;
			double mDepth;
			double mInterval;
			double mLineOfLeastResistance;

		};
	}
}

#endif  //_PIPESTYLE_H
