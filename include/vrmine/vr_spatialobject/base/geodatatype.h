//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : geodatatype.h
//  @ Date : 2014/7/6
//  @ Author : ʢ����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_GEODATATYPE_H)
#define _GEODATATYPE_H

#include <string>
#include "vrmine/vr_spatialobject/spatialobject_config.h"

namespace VirtualMine
{
	namespace Base
	{
		class VR_SPATIALOBJECT_DLL GeoDataType
		{
		public:
			static std::string GDT_IMAGE;
			static std::string GDT_DEM;
			static std::string GDT_MODEL;
			static std::string GDT_VECTOR;
			static std::string GDT_LANWAY;
			static std::string GDT_COALSEAM;
			static std::string GDT_FAULT;
			static std::string GDT_DRILL;
			static std::string GDT_MINE;
			static std::string GDT_MININGAREA;
			static std::string GDT_POINT;
			static std::string GDT_LINE;
			static std::string GDT_POLYGON;
		};
	}
}

#endif  //_GEODATATYPE_H