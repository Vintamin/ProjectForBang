

#include "vrmine\vr_style\style\pipestyle.h"
#include "string"
using namespace std;

namespace VirtualMine
{
	namespace Style
	{
		CPipeLineStyle::CPipeLineStyle()
		{
			
			this->mboomType = "";
			
		}

		CPipeLineStyle::~CPipeLineStyle()
		{

		}

		void CPipeLineStyle::setBoomType( const std::string& type )
		{
			this->mboomType=type;

		}

		void CPipeLineStyle::setBoomID( const int& id )
		{
			this->mboomID=id;

		}

		void CPipeLineStyle::setBoomOrder( const int& order )
		{
			this->mboomOrder=order;

		}

		string CPipeLineStyle::getBoomType()
		{
			return this->mboomType;
		}

		int CPipeLineStyle::getBoomID()
		{
			return this->mboomID;
		}

		int CPipeLineStyle::getBoomOrder()
		{
			return this->mboomOrder;
		}

		void CPipeLineStyle::setStartPositionX( const double& x )
		{
			this->startX=x;
		}

		void CPipeLineStyle::setStartPositionY( const double& y )
		{
			this->startY=y;
		}

		void CPipeLineStyle::setStartPositionZ( const double& z )
		{
			this->startZ=z;
		}

		void CPipeLineStyle::setEndPositionX( const double& x )
		{
			this->endX=x;

		}

		void CPipeLineStyle::setEndPositionY( const double& y )
		{
			this->endY=y;
		}

		void CPipeLineStyle::setEndPositionZ( const double& z )
		{
			this->endZ=z;
		}

		void CPipeLineStyle::setBoomZhuangYaoLength( const double& length )
		{
			this->mboomZhuangYaoLength=length;
		}

		void CPipeLineStyle::setBoomShuiPaoNiLength( const double& length )
		{
			this->mboomShuiPaoNiLength=length;
		}

		void CPipeLineStyle::setBoomFengNiLength( const double& length )
		{
			this->mboomFengNiLength=length;
		}

		double CPipeLineStyle::getStartPositionX()
		{
			return this->startX;
		}

		double CPipeLineStyle::getStartPositionY()
		{
			return this->startY;
		}

		double CPipeLineStyle::getStartPositionZ()
		{
			return this->startZ;
		}

		double CPipeLineStyle::getEndPositionX()
		{
			return this->endX;
		}

		double CPipeLineStyle::getEndPositionY()
		{
			return this->endY;
		}

		double CPipeLineStyle::getEndPositionZ()
		{
			return this->endZ;
		}

		double CPipeLineStyle::getBoomZhuangYaoLength()
		{
			return this->mboomZhuangYaoLength;
		}

		double CPipeLineStyle::getBoomShuiPaoNiLength()
		{
			return this->mboomShuiPaoNiLength;
		}

		double CPipeLineStyle::getBoomFengNiLength()
		{
			return this->mboomFengNiLength;
		}

		void CPipeLineStyle::setBoomProjectID( const int& id )
		{
			this->projectID=id;
		}

		void CPipeLineStyle::setBoomDepth( const double& depth )
		{
			this->mDepth=depth;
		}

		void CPipeLineStyle::setBoomInterval( const double& interval )
		{
			this->mInterval=interval;
		}

		void CPipeLineStyle::setBoomLineOfLeastResistance( const double& lineOfLeastResistance )
		{
			this->mLineOfLeastResistance=lineOfLeastResistance;
		}

		int CPipeLineStyle::getBoomProjectID()
		{
			return this->projectID;
		}

		double CPipeLineStyle::getBoomDepth()
		{
			return this->mDepth;
		}

		double CPipeLineStyle::getBoomInterval()
		{
			return this->mInterval;
		}

		double CPipeLineStyle::getBoomLineOfLeastResistance()
		{
			return this->mLineOfLeastResistance;
		}


		
	}
}
