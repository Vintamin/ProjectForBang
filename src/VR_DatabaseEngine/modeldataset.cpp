#include "vrmine/vr_databaseengine/database/modeldataset.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace VirtualMine::Database;

CModelDataset::CModelDataset()
{
  this->setType(VirtualMine::Core::GeoDataType::GDT_MODEL);
}

CModelDataset::~CModelDataset()
{

}

VirtualMine::Core::DeviceType VirtualMine::Database::CModelDataset::getModelType()
{
	return mModelType;
}

void VirtualMine::Database::CModelDataset::setModelType( VirtualMine::Core::DeviceType type )
{
   this->mModelType = type;	
}
