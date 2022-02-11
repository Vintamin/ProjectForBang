#include "vrmine/vr_databaseengine/database/drillingdataset.h"
#include "vrmine/vr_core/geodatatype.h"
using namespace VirtualMine::Database;

CDrillingDataset::CDrillingDataset()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_DRILL);
}
//
//CDrillingFeature* CDrillingDataset::createFeature(const std::string& featureName)
//{
//	CDrillingFeature* drillingFeature = new CDrillingFeature();
//	drillingFeature->setName(featureName);
//	return drillingFeature;
//
//}
//
//void CDrillingDataset::destroyFeature(const std::string& featureName)
//{
//
//}
//
//CDrillingFeature* CDrillingDataset::getFeature(int index)
//{
//
//}
//
//CDrillingFeature* CDrillingDataset::getFeature(const std::string& featureName)
//{
//
//}

