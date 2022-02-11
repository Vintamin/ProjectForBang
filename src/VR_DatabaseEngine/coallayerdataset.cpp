#include "vrmine/vr_databaseengine/database/coallayerdataset.h"
#include "vrmine/vr_core/geodatatype.h"
 
using namespace VirtualMine::Database;

CCoalLayerDataset::CCoalLayerDataset()
{
   this->setType(VirtualMine::Core::GeoDataType::GDT_COALSEAM);	 
}

CCoalLayerDataset::~CCoalLayerDataset()
{

}

//CCoalLayerFeature* CCoalLayerDataset::createFeature(const std::string& featureName)
//{
//	CCoalLayerFeature* coalLayerFeature = new CCoalLayerFeature();
//	coalLayerFeature->setName(featureName);
//	return coalLayerFeature;
//
//}
//
//void CCoalLayerDataset::destroyFeature(const std::string& featureName)
//{
//
//}
//
//CCoalLayerFeature* CCoalLayerDataset::getFeature(int index)
//{
//	CCoalLayerFeature* feature = new CCoalLayerFeature();
//	return feature;
//}
//
//CCoalLayerFeature* CCoalLayerDataset::getFeature(const std::string& featureName)
//{
//	CCoalLayerFeature* feature = new CCoalLayerFeature();
//	return feature;
//}

