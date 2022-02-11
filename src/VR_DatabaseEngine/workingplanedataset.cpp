#include "vrmine/vr_databaseengine/database/workingplanedataset.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace VirtualMine::Database;

CWorkingplaneDataset::CWorkingplaneDataset()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_WORKINGPLANE); 
}

CWorkingplaneDataset::~CWorkingplaneDataset()
{

}