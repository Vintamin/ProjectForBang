//#include "vrmine/vr_sqlitedatabase/sqlitedatabase/sqlite3.h"  
#include "vrmine/vr_databaseengine/database/database.h"

using namespace std;
using namespace VirtualMine::Database;


CDatabase::CDatabase(IDataSourceInfo* pDataSourceInfo)
	:IDataSource(pDataSourceInfo),ref_mpDataSourceInfo(pDataSourceInfo)
{
	this->mpDatasetSet = NULL;
	this->mName = pDataSourceInfo->getUri();
}



CDatabase::~CDatabase()
{
	delete this->mpDatasetSet;
	mpDatasetSet = NULL;

	//delete this->ref_mpDataSourceInfo;
	//this->ref_mpDataSourceInfo = NULL;
}

IDataSourceInfo* CDatabase::getDataSourceInfo()
{
	return this->ref_mpDataSourceInfo;
}


IDataset* CDatabase::getDataset(const std::string& datasetName)
 {
	 if (this->mpDatasetSet != NULL)
	 {

		 if (this->mpDatasetSet->size() > 0)
		 {
			 for (int i = 0; i < this->mpDatasetSet->size(); i++ )
			 {
				 IDataset* dataset = this->mpDatasetSet->at(i);
				 if (dataset->getName() == datasetName)
				 {
					 return dataset;
				 }

			 }
		 }
	 }
 }

std::vector<IDataset*>* CDatabase::getDatasetSet()
{
	return this->mpDatasetSet;
}

void CDatabase::setName(const string& name)
{
	this->mName = name;
}

std::string CDatabase::getName()
{
	return this->mName;
}

std::string CDatabase::getType()
{
	return this->mType;
}

int CDatabase::getID()
{
	return this->mID;
}

 int CDatabase::createMetadataDataset()
 {
	 return -1;
 }


 int CDatabase::createLogicDataset()
 {
	  return -1;
 }

int CDatabase::createLanewayDataset()
{
	 return -1;
}
int CDatabase::createLevelLanewayDataset()
{
	return -1;
}

 int CDatabase::createCoalLayerDataset()
 {
	  return -1;
 }


int CDatabase::createDrillingDataset()
{
	 return -1;
}

 int CDatabase::createBigLanewayDataset()
{
	 return -1;
}

 int CDatabase::createFaultLayerDataset()
{
	 return -1;
}

 int CDatabase::createDEMDataset()
{
	 return -1;
}

int CDatabase::createImageDataset()
{
	 return -1;
}




int CDatabase::insertLanewayFeatureToLanewayDataset(VirtualMine::Database::IFeature lanewayFeature)
{
	 return -1;
}

int CDatabase::insertCoalLayerFeatureToCoalLayerDataset(VirtualMine::Database::IFeature coalLayerFeature)
{
	 return -1;
}


int CDatabase::insertDrillingFeatureToDrillingDataset(VirtualMine::Database::IFeature drillingFeature)
{
	 return -1;
}


int CDatabase::insertLogicFeatureToLogicDataset(VirtualMine::Database::IFeature logicfeature)
{
	return -1;
}

//int insertCoalLayerToCoalLayerDataset(VirtualMine::Database::IFeature coallayerfeature);

int CDatabase::insertImageFeatureToImageDataset(VirtualMine::Database::IFeature imagefeature)
{
	return -1;
}

int CDatabase::insertMetaDataFeatureToMetaDataset(VirtualMine::Database::IFeature metadatafeature)
{
	return -1;
}

//int insertDrillingFeatureToDrillingDataset(VirtualMine::Database::CDrillingFeature drillingfeature);

int CDatabase::insertFaultLayerFeatureToFaultLayerDataset(VirtualMine::Database::IFeature faultlayerfeature)
{
	return -1;
}

int CDatabase::insertDEMFeatureToDEMDataset(VirtualMine::Database::IFeature demfeature)
{
	return -1;
}

 int CDatabase::insertModelFeatureToModelDataset( VirtualMine::Database::IFeature modelfeature)
{
    return -1;
}

 int CDatabase::insertModelFeatureToModelDataset( VirtualMine::Database::IFeature* modelfeature,std::string modeldatasetName)
{
	return -1;
}

 void CDatabase::updataModelFeature(VirtualMine::Database::IFeature* feature,std::string featurename)
 {

 }

 void CDatabase::updataModelFeature2(VirtualMine::Database::IFeature* feature,std::string featurename,std::string datasetname)
 {

 }


//void CDatabase::getReferenceCenter(double& x,double& y,double& z)
// {
//	 double* xx = this->mReferenceCenterX;
//	 double* yy = this->mReferenceCenterY;
//	 double* zz = this->mReferenceCenterZ; 
//	 x = *xx;
//	 y = *yy;
//	 z = *zz;
// }
//
//void CDatabase::setReferenceCenter(const double& x,const double& y,const double& z)
// {
//	 double xx = x;
//	 double yy = y;
//	 double zz = z;
//	 this->mReferenceCenterX = &xx;
//     this->mReferenceCenterY = &yy;
//	 this->mReferenceCenterZ = &zz;
//
//	 
// }