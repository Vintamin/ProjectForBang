

#if !defined(_EMBRASUREPROPERTY_H)
#define _EMBRASUREPROPERTY_H

#include "vrmine/vr_core/coredefine.h"
#include "vrmine/vr_spatialinterface/igeoproperty.h"
#include "bang_render_config.h"
#include "vrmine\vr_core\variant.h"

namespace BangRender
{
	namespace ObjectProperty
	{
		
		class BANG_RENDER_DLL CEmbrasureProperty : public VirtualMine::SpatialInterface::CGeoProperty
		{
		public:
			CEmbrasureProperty();
			~CEmbrasureProperty();

		public:
			VirtualMine::SpatialInterface::IGeoProperty* clone();

			void setName(const std::string& name);
			std::string getName();

			void setRadius(float radius);
			float getRadius();
						

		private:
			std::string mName;
			float mRadius;
			
		};
	}
}

#endif  //_EMBRASUREPROPERTY_H
