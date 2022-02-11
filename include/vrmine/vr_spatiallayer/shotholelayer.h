#if !defined(_CShotHoleLayer_H)
#define _CShotHoleLayer_H

#include "vrmine/vr_spatiallayer/scenelayer.h"
#include <Ogre/Ogre.h>
#include "string"

using namespace std;

namespace VirtualMine
{
	namespace SpatialLayer
	{

		class VR_SPATIALLAYER_DLL CShotHoleLayer : public CSceneLayer
		{
		public:
			CShotHoleLayer();
			virtual ~CShotHoleLayer();
			virtual void initialise();
			virtual void notifyUpdate();
			//virtual void setStyle(VirtualMine::SpatialInterface::IStyle* pStyle);
			virtual void setFrameMode(bool isFrameMode);
			virtual void update();
			//kk װҩ���ȵĺ����ж�
			int getZhuangyaoList(std::vector<double*> paramArray,double changeData,double oldLength);
			//kk ��׳��ȵĺ����ж�
			int getFengkongList(std::vector<double*> paramArray,double changeData,double oldLength);
			//kk ˮ���೤�ȵĺ����ж�
			int getShuipaoniList(std::vector<double*> paramArray,double changeData,double oldLength);

		};

	}
}


#endif  //_CShotHoleLayer_H