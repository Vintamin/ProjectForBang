
#if !defined(_TERRANESTYLE_H)
#define _TERRANESTYLE_H

#include "vrmine\vr_style\style_config.h"
#include "vrmine/vr_spatialinterface/istyle.h"

namespace VirtualMine
{
	namespace Style
	{
		class VR_STYLE_DLL CTerraneStyle : public VirtualMine::SpatialInterface::CStyle
		{
		public:
			CTerraneStyle();
			~CTerraneStyle();
		public:
			void setTexture(const std::string& name);
			std::string getTexture();
			
		private:
			//Ogre::ColourValue mColor;
			std::string mTextureName;
		
		};
	}
}

#endif  //_TERRANESTYLE_H
