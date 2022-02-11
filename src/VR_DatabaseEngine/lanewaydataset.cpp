#include "vrmine/vr_databaseengine/database/lanewayfeature.h"
#include "vrmine/vr_databaseengine/database/lanewaydataset.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace VirtualMine::Database;

CLanewayDataset::CLanewayDataset()
{
	this->mType = VirtualMine::Core::GeoDataType::GDT_LANWAY;
	
}

CLanewayDataset::~CLanewayDataset()
{

}

//void CLanewayDataset::addFeature(CLanewayFeature feature)
//{
//	
//}
//
//void CLanewayDataset::destroyFeature(const std::string& featureName)
//{
//	/*vector<CLanewayFeature*>::iterator itr = mpLanewayFeature->begin();
//	while (itr != mpLanewayFeature->end())
//	{
//		if (itr->getName() == featureName )
//		{
//			return *itr;
//		}s
//		itr++;
//	}*/
//}

//IFeature* CCoalLayerDataset::getFeature(int index)
//{
//	CLanewayFeature* lanefeature = this->mpLanewayFeature(index);
//	return lanefeature;
//}

//IFeature* CLanewayDataset::getFeature(const int& id)
//{
//	vector<IFeature*>::iterator itr = mpLanewayFeature->begin();
//	while (itr != mpLanewayFeature->end())
//	{
//		if (itr->getID() == id )
//		{
//			return *itr;
//		}
//		itr++;
//	}
//}
//
//vector<CLanewayFeature*>* CCoalLayerDataset::getLanewayFeature()
//{
//	return this->mpLanewayFeature;
//}
