#include "vrmine/vr_databaseengine/database/dataset.h"

using namespace std;
using namespace VirtualMine::Database;

CDataset::CDataset()
{
	this->mpFeatureList = NULL;
	mName = "";
	this->mType = "";
}

CDataset::~CDataset()
{
	if (mpFeatureList->size() > 0)
	{
		for (int i = 0; i < mpFeatureList->size(); i++)
		{
			delete mpFeatureList->at(i);
			 mpFeatureList->at(i) = NULL;
		}
	}

	if (mpFeatureList)
	{
		delete mpFeatureList;
		mpFeatureList = NULL;
	}
		  
}

//IFeature CDataset::createFeature(const string& featureName)
//{
//	IFeature feature ;
//	return feature;
//}


 void CDataset::addFeature(IFeature* feature)
 {
	 if (NULL == this->mpFeatureList)
	 {
		 this->mpFeatureList = new std::vector<IFeature*>();
	 }
	 this->mpFeatureList->push_back(feature);
 }



void CDataset::destroyFeature(const string& featureName)
{

}

IFeature* CDataset::getFeature(const int& index)
{
	 //return this->mpFeatureList[index];
	if (this->mpFeatureList)	
	    return this->mpFeatureList->at(index);
	else
		return NULL;
}

IFeature* CDataset::getFeature(const std::string& name)
{
	if (this->mpFeatureList)
	{
		int size = this->mpFeatureList->size();
	    for (int i = 0;i < size;i++)
	    {
			std::string featureName = this->mpFeatureList->at(i)->getFieldName();
			if (featureName == name)
			{
				return this->mpFeatureList->at(i);
			}

	    }
		return NULL;
	}
	else
		return NULL;
}

//
//IFeature* CDataset::getFeature(const int& id)
//{
//	/*IFeature* feature = new IFeature(); 
//	return feature;*/
//	vector<IFeature*>::iterator bitr = this->mpFeatureList->begin();
//	vector<IFeature*>::iterator eitr = this->mpFeatureList->end();
//	while (bitr != eitr)
//	{
//		
//		if((*bitr)->getID() == id)
//			return *bitr;
//		bitr++;
//	}
//	return NULL;
//}

vector<IFeature*>* CDataset::getFeatureList()
{ 
	if (this->mpFeatureList)
	{
		return this->mpFeatureList;
	}
	return NULL;
}

string CDataset::getName()
{
	return this->mName;
} 

void CDataset::setName(const string& name)
{
	this->mName = name;
}

int CDataset::getCount()
{
	if (this->mpFeatureList == NULL )
	{
		return 0;
	}
	return this->mpFeatureList->size();  
}

std::string CDataset::getType()
{
	return mType;
}
 void CDataset::setType(const std::string& type)
 {
	 this->mType = type;
 }
