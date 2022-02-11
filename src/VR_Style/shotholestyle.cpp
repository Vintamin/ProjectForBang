
#include "vrmine\vr_style\style\shotholestyle.h"

namespace VirtualMine
{
	namespace Style
	{
		CShotHoleStyle::CShotHoleStyle()
		{
			

		}

		CShotHoleStyle::~CShotHoleStyle()
		{

		}

		void CShotHoleStyle::setShotHoleColor(const Ogre::ColourValue& color)
		{
			this->mColor = color;
		}

		Ogre::ColourValue CShotHoleStyle::getShotHoleColor()
		{
			return this->mColor;
		}

		void CShotHoleStyle::setTextureName(const std::string& name)
		{
			this->mTextureName = name;
		}

		std::string CShotHoleStyle::getTextureName()
		{
			return this->mTextureName;
		}
	}
}
