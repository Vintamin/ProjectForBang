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

#include "vrmine/vr_spatialinterface/spatialinterface_config.h"
#include "vrmine\vr_core\event.h"

namespace VirtualMine
{
	namespace SpatialInterface
	{
		class VR_SPATIALINTERFACE_DLL ITool : public VirtualMine::Core::CEventHandler
		{
		public:
			ITool();
			virtual ~ITool();
			virtual void mouseReleaseEvent(const int& x ,const int& y , const int& button);
			virtual void mousePressEvent(const int& x ,const int& y , const int& button);
			virtual void mouseDoubleClickEvent(const int& x ,const int& y , const int& button);
			virtual void mouseMoveEvent(const int& x ,const int& y, const int& button);
			virtual void wheelEvent(const int& x ,const int& y , const int& delta);
			virtual void keyPressEvent(const int& key);
			virtual bool handleEvent(VirtualMine::Core::CEvent* evt);
			virtual void clear();
		};

		class VR_SPATIALINTERFACE_DLL CTool : public VirtualMine::SpatialInterface::ITool
		{
		public:
			CTool();
			virtual ~CTool();
			virtual void mouseReleaseEvent(const int& x ,const int& y , const int& button);
			virtual void mousePressEvent(const int& x ,const int& y , const int& button);
			virtual void mouseDoubleClickEvent(const int& x ,const int& y , const int& button);
			virtual void mouseMoveEvent(const int& x ,const int& y, const int& button);
			virtual bool handleEvent(VirtualMine::Core::CEvent* evt);
		protected:
			bool mIsMouseDown;
			bool mIsMouseDrag;
		};
	}
}

#endif  //_ITOOL_H