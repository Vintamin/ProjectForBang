//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : itool.h
//  @ Date : 2014/7/6
//  @ Author : ʢ����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_ITOOL_H)
#define _ITOOL_H

#include "vrmine/vr_systemui/systemui_config.h"
#include "vrmine\vr_core\event.h"

namespace VirtualMine
{
	namespace SystemUI
	{
		class VR_SYSTEMUI_DLL ITool : public VirtualMine::Core::CEventHandler
		{
		public:
			ITool();
			virtual ~ITool();
			void mouseReleaseEvent(const int& x ,const int& y , const int& button);
			void mousePressEvent(const int& x ,const int& y , const int& button);
			void mouseDoubleClickEvent(const int& x ,const int& y , const int& button);
			void mouseMoveEvent(const int& x ,const int& y, const int& button);
			void wheelEvent(const int& x ,const int& y , const int& delta);
			void keyPressEvent(const int& key);
			bool handleEvent(VirtualMine::Core::CEvent* evt);
		};
	}
}

#endif  //_ITOOL_H