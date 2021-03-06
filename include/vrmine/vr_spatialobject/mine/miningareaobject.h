//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : miningareaobject.h
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_MININGAREAOBJECT_H)
#define _MININGAREAOBJECT_H


#include <comdef.h>
#include <GdiPlus.h>
using namespace Gdiplus;
#pragma comment(lib, "gdiplus.lib")

#include "vrmine\vr_spatialobject\spatialobject_config.h"
#include "vrmine\vr_spatialinterface\igeoobject.h"
#include "vrmine\vr_spatialobject\mine\coalseamobject.h"


namespace VirtualMine
{
	namespace Mine
	{
		class VR_SPATIALOBJECT_DLL CMiningAreaObject : public VirtualMine::SpatialInterface::CGeoObject
		{
		public:
			CMiningAreaObject();
			~CMiningAreaObject();
		public:
			VirtualMine::SpatialInterface::IStyle* getStyle();
			VirtualMine::SpatialInterface::IGeometry* getGeometry();
			VirtualMine::SpatialInterface::IGeoProperty* getGeoProperty();

		public:
			void createTexture(CCoalSeamObject* coalobject);

		private:
			int getEncoderClsid(const WCHAR* format, CLSID* pClsid);
		};
	}
}

#endif  //_MININGAREAOBJECT_H
