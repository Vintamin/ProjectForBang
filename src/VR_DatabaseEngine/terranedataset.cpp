#include "vrmine/vr_databaseengine/database/terranedataset.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace VirtualMine::Database;

CTerraneDataset::CTerraneDataset()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_TERRANE);
}

CTerraneDataset::~CTerraneDataset()
{

}


