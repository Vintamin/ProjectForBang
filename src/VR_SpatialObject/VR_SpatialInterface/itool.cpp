
#include "vrmine/vr_spatialinterface/itool.h"
using namespace VirtualMine::Core;

namespace VirtualMine
{
	namespace SpatialInterface
	{
		ITool::ITool()
		{
		
		}
		
		ITool::~ITool()
		{
		
		}
		
		void ITool::mouseReleaseEvent(const int& x ,const int& y , const int& button)
		{
		
		}
		
		void ITool::mousePressEvent(const int& x ,const int& y , const int& button)
		{
		
		}
		
		void ITool::mouseDoubleClickEvent(const int& x ,const int& y , const int& button)
		{
		
		}
	
		void ITool::mouseMoveEvent(const int& x ,const int& y, const int& button)
		{
		
		}
		
		void ITool::wheelEvent(const int& x ,const int& y , const int& delta)
		{
		
		}
		
		void ITool::keyPressEvent(const int& key)
		{
		
		}
		
		bool ITool::handleEvent(VirtualMine::Core::CEvent* evt)
		{
			evt->accept();
			return true;
		}


		void ITool::clear()
		{

		}

		CTool::CTool()
		{
			this->mIsMouseDown = false;
			this->mIsMouseDrag = false;
		}

		CTool::~CTool()
		{

		}
		void CTool::mouseReleaseEvent(const int& x ,const int& y , const int& button)
		{
			this->mIsMouseDown = false;
			this->mIsMouseDrag = false;
		}

		void CTool::mousePressEvent(const int& x ,const int& y , const int& button)
		{
			this->mIsMouseDown = true;
			this->mIsMouseDrag = false;
		}
		void CTool::mouseDoubleClickEvent(const int& x ,const int& y , const int& button)
		{
			this->mIsMouseDown = false;
			this->mIsMouseDrag = false;
		}

		void CTool::mouseMoveEvent(const int& x ,const int& y, const int& button)
		{
			if (this->mIsMouseDown)
			{
				this->mIsMouseDrag = true;
			}
			else
			{
				this->mIsMouseDrag = false;
			}
		}
	
		bool CTool::handleEvent(VirtualMine::Core::CEvent* evt)
		{
			CEvent::Type type = evt->type();
			switch(type)
			{
			case CEvent::MouseButtonPress:
				{
					CMouseEvent* pMouseEvent = dynamic_cast<CMouseEvent*>(evt);
					this->mousePressEvent(pMouseEvent->getX(),pMouseEvent->getY(),pMouseEvent->getButton());
					evt->accept();
					break;
				}
			case CEvent::MouseMove:
				{
					CMouseEvent* pMouseEvent = dynamic_cast<CMouseEvent*>(evt);
					this->mouseMoveEvent(pMouseEvent->getX(),pMouseEvent->getY(),pMouseEvent->getButton());
					evt->accept();
					break;	
				}
			case CEvent::MouseButtonRelease:
				{
					CMouseEvent* pMouseEvent = dynamic_cast<CMouseEvent*>(evt);
					this->mouseReleaseEvent(pMouseEvent->getX(),pMouseEvent->getY(),pMouseEvent->getButton());
					break;
				}
			default:
				break;
			}
			return evt->isAccepted();
		}

		
	}
}
