
#include "vrmine/vr_spatialobject/geoproperty/terraneproperty.h"

namespace VirtualMine
{
	namespace GeoProperty
	{
		CTerraneProperty::CTerraneProperty()
		{

		}

		CTerraneProperty::~CTerraneProperty()
		{

		}

		VirtualMine::SpatialInterface::IGeoProperty* CTerraneProperty::clone()
		{
			return NULL;
		}

		void CTerraneProperty::setName(const std::string& name)
		{
			this->mName = name;
		}

		std::string CTerraneProperty::getName()
		{
			return this->mName;
		}

		void CTerraneProperty::setRockType( const std::string& rockType )
		{
			this->mRockType = rockType;
		}

		std::string CTerraneProperty::getRockType()
		{
			return mRockType;
		}

		void CTerraneProperty::setProjectID(const int& id)
		{
			this->mProjectID = id;
		}

		int CTerraneProperty::getProjectID()
		{
			return mProjectID;
		}

		
	}
}
