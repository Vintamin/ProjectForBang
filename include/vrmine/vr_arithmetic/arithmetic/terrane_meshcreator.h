

#if !defined(_TERRANE_MESHCREATOR_H)
#define _TERRANE_MESHCREATOR_H

#include "vrmine/vr_spatialinterface/igeomeshcreator.h"
#include "vrmine\vr_arithmetic\arithmetic_config.h"
#include <OGRE\Ogre.h>
#include <vector>

#define borderNodesCount 100
//
using namespace std;

namespace VirtualMine
{
	namespace Arithmetic
	{
		class VR_ARITHMETIC_DLL CTerrane_MeshCreator : public VirtualMine::SpatialInterface::CGeoMeshCreator
		{
		public:
			CTerrane_MeshCreator();
			~CTerrane_MeshCreator();
		public:
			void createData(VirtualMine::SpatialInterface::GeoObjectVector& geoObjectVector,std::vector<VirtualMine::SpatialInterface::CGeoExtentionData*>& geoExtentionDatas);

		private:
			std::vector<Ogre::Vector3> boderNodes; //存放所有边界点
			std::vector<Ogre::Vector3> tempVec2;   
			
			std::vector<Ogre::Vector3> normalVec; //法向量
			
			
		};
	}
}

#endif  //_TERRANE_MESHCREATOR_H
