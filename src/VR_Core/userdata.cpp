#include "vrmine/vr_core/userdata.h"


namespace VirtualMine
{
	namespace Core
	{
		
		CUserData::CUserData()
		{
		
		}
		
		CUserData::~CUserData()
		{
		
		}

		CGeoUserData::CGeoUserData()
			:mSelectable(true),mSelected(false)
		{
		
		}

		CGeoUserData::~CGeoUserData()
		{
		
		}

		void CGeoUserData::setSelectable(const bool& value)
		{
			this->mSelectable = value;
		}
		
		bool CGeoUserData::getSelectable()
		{
			return this->mSelectable;
		}
		
		void CGeoUserData::setSelected(const bool& value)
		{
			this->mSelected = value;
		}
		
		bool CGeoUserData::getSelected()
		{
			return this->mSelected;
		}
	}
}
