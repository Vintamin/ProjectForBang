#include "bang/projectdataset.h"
#include "vrmine/vr_core/geodatatype.h"

VirtualMine::Bang_Database::CProjectFileDataset::CProjectFileDataset()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_IMAGE);
}

VirtualMine::Bang_Database::CProjectFileDataset::~CProjectFileDataset()
{

}
