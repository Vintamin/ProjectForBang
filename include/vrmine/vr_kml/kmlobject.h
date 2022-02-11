#ifndef CKMLOBJECT_H_
#define CKMLOBJECT_H_
#include "vrmine/vr_kml/kml_config.h"
#include "vrmine/vr_scenecontrol/geospatialcontrol.h"
#include "vrmine/vr_core/baseobject.h"
#include <string>

namespace VirtualMine
{
	namespace Kml
	{
		class VR_KML_DLL CKmlObject : public VirtualMine::Core::CBaseObject
		{
		public:
			CKmlObject(VirtualMine::Scene::CGeoSpatialControl* ref_pControl);
			virtual ~CKmlObject();
			virtual void fromFile(const std::string& path)=0;
			virtual void toFile(const std::string& path)=0;
		protected:
			std::string mName;
			VirtualMine::Scene::CGeoSpatialControl* ref_mpControl;
		};

	}
}


#endif