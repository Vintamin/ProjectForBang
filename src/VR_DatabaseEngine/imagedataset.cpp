#include "vrmine/vr_databaseengine/database/imagedataset.h"
#include "vrmine/vr_core/geodatatype.h"
using namespace VirtualMine::Database;

CImageDataset::CImageDataset()
{
   this->setType(VirtualMine::Core::GeoDataType::GDT_IMAGE);
}

CImageDataset::~CImageDataset()
{

}