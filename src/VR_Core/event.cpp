
#include "vrmine/vr_core/event.h"


namespace VirtualMine
{
	namespace Core
	{
		CEvent::CEvent(const CEvent::Type& type)
			:mType(type),m_accept(false)
		{

		}

		CEvent::CEvent()
			:mType(User),m_accept(false)
		{
		
		}

		CEvent::~CEvent()
		{

		}

		CEvent::Type CEvent::type() const 
		{ 
			return static_cast<CEvent::Type>(mType); 
		}

		void CEvent::setAccepted(bool accepted)
		{
			m_accept = accepted; 
		}

		bool CEvent::isAccepted() const 
		{
			return m_accept; 
		}

		void CEvent::accept() 
		{ 
			m_accept = true; 
		}

		void CEvent::ignore() 
		{
			m_accept = false;
		}

		CEventHandler::CEventHandler()
		{
			CEventDispatcher::registerEventHandler(this);
		}

		CEventHandler::~CEventHandler()
		{
			CEventDispatcher::unRegisterEventHandler(this);
		}

		
		CEventQueue::CEventQueue()
		{
		
		}

		CEventQueue::~CEventQueue()
		{
		
		}

		void CEventQueue::appendEvent(CEvent* evt)
		{
			this->mEvents.push_back(evt);
		}

		void CEventQueue::removeEvent(CEvent* evt)
		{
			for (size_t i = 0 ; i < this->mEvents.size(); ++i)
			{
				if (this->mEvents[i] == evt)
				{
					this->mEvents.erase(this->mEvents.begin() + i);
					return;
				}
			}
		}

		EventVector& CEventQueue::takeEvent()
		{
			return this->mEvents;
		}

		int CMouseEvent::getButton()
		{
			return this->mButton;
		}
		
		int CMouseEvent::getX()
		{
			return this->mX;
		}

		int CMouseEvent::getY()
		{
			return this->mY;
		}

		int CMouseEvent::getDelta()
		{
			return this->mDelta;
		}

		void CMouseEvent::setButton(const int& button)
		{
			this->mButton = button;
		}

		void CMouseEvent::setX(const int& x)
		{
			this->mX = x;
		}

		void CMouseEvent::setY(const int& y)
		{
			this->mY = y;
		}

		void CMouseEvent::setDelta(const int& delta)
		{
			this->mDelta = delta;
		}

		CMouseEvent::CMouseEvent(const Type& type)
			:CEvent(type),mX(0),mY(0),
			mButton(-1),mDelta(0)
		{
		
		}
		
		CMouseEvent::~CMouseEvent()
		{
		
		}

		CKeyEvent::CKeyEvent(const CEvent::Type& type)
			:CEvent(type),mKey(0)
		{
		
		}
		
		CKeyEvent::~CKeyEvent()
		{
		
		}

		void CKeyEvent::setKey(const int& key)
		{
			this->mKey = key;
		}
		
		int CKeyEvent::getKey()
		{
			return this->mKey;
		}


		std::vector<CEventHandler*>* CEventDispatcher::mpEventHandlers(NULL);
		CEventDispatcher::CEventDispatcher()
		{
			
		}

		CEventDispatcher::~CEventDispatcher()
		{

		}

		bool CEventDispatcher::setEvent(CEvent* evt)
		{
			bool success = false;
			if (CEventDispatcher::mpEventHandlers
				&& CEventDispatcher::mpEventHandlers->size() > 0)
			{
				std::cout<<"CEventDispatcher::mpEventHandlers->size()的次数是"<<CEventDispatcher::mpEventHandlers->size()<<std::endl;//6次
				std::vector<CEventHandler*>::iterator bItr = CEventDispatcher::mpEventHandlers->begin();
				std::vector<CEventHandler*>::iterator eItr = CEventDispatcher::mpEventHandlers->end();
				while (bItr != eItr)
				{
             					success |= (*bItr)->handleEvent(evt);
					++bItr;
				}

			}
			return success;
		}

		bool CEventDispatcher::unRegisterEventHandler(CEventHandler* pEventHandler)
		{
			if (CEventDispatcher::mpEventHandlers
				&& CEventDispatcher::mpEventHandlers->size() > 0)
			{
				std::vector<CEventHandler*>::iterator bItr = CEventDispatcher::mpEventHandlers->begin();
				std::vector<CEventHandler*>::iterator eItr = CEventDispatcher::mpEventHandlers->end();
				while (bItr != eItr)
				{
					if (*bItr == pEventHandler)
					{
						CEventDispatcher::mpEventHandlers->erase(bItr);
						return true;
					}
					++bItr;
				}

			}
			return false;
		}

		bool CEventDispatcher::registerEventHandler(CEventHandler* pEventHandler)
		{
			if (CEventDispatcher::mpEventHandlers == NULL)
				CEventDispatcher::mpEventHandlers = new std::vector<CEventHandler*>();

			CEventDispatcher::mpEventHandlers->push_back(pEventHandler);
			return false;
		}

	}
}
