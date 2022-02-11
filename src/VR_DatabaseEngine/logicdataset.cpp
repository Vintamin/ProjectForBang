#include "vrmine/vr_databaseengine/database/logicdataset.h"
#include "vrmine/vr_databaseengine/database/logicfeature.h"

using namespace VirtualMine::Database;

CLogicDataset::CLogicDataset()
{
	this->setType("LogicDataset"); 
	this->setName("LogicDataset");
}

CLogicDataset::~CLogicDataset()
{

}

std::string  CLogicDataset::getFeatureTypeByName(std::string featureName)
{
    CLogicFeature* logicFeature = 	dynamic_cast<CLogicFeature*>(this->getFeature(featureName));
	//logicFeature->getFeatureTypeByName(featureName); 

	///有记录返回type，否则为空
	if (logicFeature)
	{
		std::string type = logicFeature->getFieldType();
		return type;
	}
	
	return "";

}

//void CLogicDataset::addFeature(CLogicFeature feature)
//{
//	
//}
//
//void CLogicDataset::destroyFeature(const std::string& featureName)
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