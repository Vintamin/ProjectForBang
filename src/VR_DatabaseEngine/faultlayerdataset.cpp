#include "vrmine/vr_databaseengine/database/faultlayerdataset.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace VirtualMine::Database;

CFaultLayerDataset::CFaultLayerDataset()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_FAULT);
}

CFaultLayerDataset::~CFaultLayerDataset()
{

}


