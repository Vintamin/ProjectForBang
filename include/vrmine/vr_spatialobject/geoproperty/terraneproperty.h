
#if !defined(_TERRANETPROPERTY_H)
#define _TERRANETPROPERTY_H

#include "vrmine/vr_core/coredefine.h"
#include "vrmine/vr_spatialinterface/igeoproperty.h"
#include "vrmine\vr_spatialobject\spatialobject_config.h"


namespace VirtualMine
{
	namespace GeoProperty
	{
		class VR_SPATIALOBJECT_DLL CTerraneProperty : public VirtualMine::SpatialInterface::CGeoProperty
		{
		public:
			CTerraneProperty();
			~CTerraneProperty();
		public:
			VirtualMine::SpatialInterface::IGeoProperty* clone();

			void setName(const std::string& name);
			std::string getName();
			void setRockType(const std::string& rockType);
			std::string getRockType();
			void setProjectID(const int& id);
			int getProjectID();

		private:
			int mProjectID;
			std::string mName;
			std::string mRockType;
		
		};
	}
}

#endif  //_TERRANETPROPERTY_H
