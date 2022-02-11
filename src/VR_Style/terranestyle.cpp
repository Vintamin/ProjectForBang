
#include "vrmine\vr_style\style\terranestyle.h"

namespace VirtualMine
{
	namespace Style
	{
		CTerraneStyle::CTerraneStyle()
		{
			this->setTexture("coalseam.png");

		}

		CTerraneStyle::~CTerraneStyle()
		{

		}

		void CTerraneStyle::setTexture(const std::string& name)
		{
			this->mTextureName = name;
		}

		std::string CTerraneStyle::getTexture()
		{
			return this->mTextureName;
		}
	}
}
