//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : modelproperty.h
//  @ Date : 2014/8/6
//  @ Author : �����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_MODELPROPERTY_H)
#define _MODELPROPERTY_H

#include "vrmine/vr_core/coredefine.h"
#include "vrmine/vr_spatialinterface/igeoproperty.h"
#include "vrmine\vr_spatialobject\spatialobject_config.h"
#include "vrmine\vr_core\geodatatype.h"
#include "vrmine\vr_core\variant.h"

namespace VirtualMine
{
	namespace GeoProperty
	{
		class VR_SPATIALOBJECT_DLL CModelProperty : public VirtualMine::SpatialInterface::CGeoProperty
		{
		public:
			CModelProperty();
			~CModelProperty();
		public:
			VirtualMine::SpatialInterface::IGeoProperty* clone();

			virtual void setMeshName(const std::string& meshName);
			virtual std::string getMeshName();

			virtual void setDeviceType(VirtualMine::Core::DeviceType devicetype = VirtualMine::Core::DeviceType::DT_UNKNOWN);
			virtual VirtualMine::Core::DeviceType getDeviceType();

	    	virtual	void toStream(VirtualMine::Core::CVRDataStream& datastream);
		    virtual	void fromStream(VirtualMine::Core::CVRDataStream& datastream);

		protected:
			std::string mMeshName;
			VirtualMine::Core::DeviceType mDeviceType;
		};
	}
}

#endif  //_MODELPROPERTY_H