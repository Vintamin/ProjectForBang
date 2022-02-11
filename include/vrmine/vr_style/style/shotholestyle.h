

#if !defined(_SHOTHOLESTYLE_H)
#define _SHOTHOLESTYLE_H

#include "vrmine\vr_style\style_config.h"
#include "vrmine/vr_spatialinterface/istyle.h"

namespace VirtualMine
{
	namespace Style
	{
		class VR_STYLE_DLL CShotHoleStyle : public VirtualMine::SpatialInterface::CStyle
		{
		public:
			CShotHoleStyle();
			~CShotHoleStyle();
		public:
			void setShotHoleColor(const Ogre::ColourValue& color);
			Ogre::ColourValue getShotHoleColor();

			void setTextureName(const std::string& name);
			std::string getTextureName();
		private:
			Ogre::ColourValue mColor;
			std::string mTextureName;

		};
	}
}

#endif  //_SHOTHOLESTYLE_H
