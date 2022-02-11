# ifndef _CBASEOBJECT_H
#define _CBASEOBJECT_H

#include "vrmine\vr_core\common_config.h"
#include "OGRE\OgrePrerequisites.h"

namespace VirtualMine
{
	namespace Core
	{
		class VR_CORE_DLL CBaseObject
		{
		public :
			CBaseObject();
			virtual ~CBaseObject();
		};
	}
}
#endif