//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : fieldtype.h
//  @ Date : 2014/7/6
//  @ Author : ʢ����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_USERDATA_H)
#define _USERDATA_H

#include "vrmine/vr_core/common_config.h"
#include <vector>


namespace VirtualMine
{
	namespace Core
	{
		class VR_CORE_DLL CUserData           
		{
		public:
			CUserData();
			virtual ~CUserData();
		};

		class VR_CORE_DLL CGeoUserData : public CUserData
		{
		public:
			CGeoUserData();
			virtual ~CGeoUserData();
			void setSelectable(const bool& value);
			bool getSelectable();
			void setSelected(const bool& value);
			bool getSelected();

		protected:
			bool mSelectable;
			bool mSelected;

		};

	}
}


#endif  //_FIELDTYPE_H