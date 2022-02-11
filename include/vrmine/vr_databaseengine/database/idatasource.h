//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : idatasource.h
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#if !defined(_IDATASOURCE_H)
#define _IDATASOURCE_H

#include "vrmine\vr_core\baseobject.h"
#include "vrmine\vr_databaseengine\database_config.h"
#include "vrmine/vr_databaseengine/database/ifeature.h"
#include "vrmine/vr_databaseengine/database/coallayerfeature.h"
//#include "vrmine/vr_databaseengine/database/drillingfeature.h"
//#include "vrmine/vr_databaseengine/database/lanewayfeature.h"
//#include "vrmine/vr_databaseengine/database/roadfeature.h"
#include "vrmine/vr_databaseengine/database/idataset.h"
#include "vrmine/vr_databaseengine/database/idatasourceinfo.h"
#include "vrmine/vr_databaseengine/database/modelfeature.h"


namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL IDataSource //: public VirtualMine::Core::CBaseObject
		{
		public:

			virtual void setName(const std::string& name);

			virtual std::string getName();

			virtual std::string getType();
			
			IDataSource(IDataSourceInfo* pDataSourceInfo);

			virtual ~IDataSource();

			virtual IDataSourceInfo* getDataSourceInfo();

			virtual int createMetaDataset();
		
			virtual int createLogicalDataset();
		
			virtual int createLanewayDataset();
		
			virtual int createCoalLayerDataset();
		
			virtual int createDrillingDataset();
		
			virtual int createRoadDataset();
		

		/*	virtual int insertLanewayFeatureToLanewayDataset(VirtualMine::Database::IFeature lanewayFeature);
		
			virtual int insertCoalLayerFeatureToCoalLayerDataset(VirtualMine::Database::IFeature coalLayerFeature);
			

			virtual int insertDrillingFeatureToDrillingDataset(VirtualMine::Database::IFeature drillingFeature);
		*/


			//virtual int insertRoadFeatureToRoadDataset(VirtualMine::Database::IFeature roadFeature);

			virtual int insertLanewayFeatureToLanewayDataset(VirtualMine::Database::IFeature lanewayFeature);

			virtual int insertCoalLayerFeatureToCoalLayerDataset(VirtualMine::Database::IFeature coalLayerFeature);

			virtual int insertDrillingFeatureToDrillingDataset(VirtualMine::Database::IFeature drillingFeature);

			virtual int insertLogicFeatureToLogicDataset(VirtualMine::Database::IFeature logicfeature);

			virtual int insertImageFeatureToImageDataset(VirtualMine::Database::IFeature imagefeature);

			virtual int insertMetaDataFeatureToMetaDataset(VirtualMine::Database::IFeature metadatafeature);

			virtual int insertFaultLayerFeatureToFaultLayerDataset(VirtualMine::Database::IFeature faultlayerfeature);

			virtual int insertDEMFeatureToDEMDataset(VirtualMine::Database::IFeature demfeature);

			virtual int insertModelFeatureToModelDataset( VirtualMine::Database::IFeature modelfeature);

			virtual int insertModelFeatureToModelDataset( VirtualMine::Database::IFeature* modelfeature,std::string modeldatasetName);
			
			//virtual  void updataModelFeature(VirtualMine::Database::CModelFeature* feature,std::string festurename);
			
			virtual void updataModelFeature(VirtualMine::Database::IFeature* feature,std::string featurename); 

			virtual void updataModelFeature2(VirtualMine::Database::IFeature* feature,std::string featurename,std::string datasetname);

			virtual IDataset* getDataset(const std::string& datasetName);

		    virtual std::vector<IDataset*>* getDatasetSet();

			virtual void getReferenceCenter(double& x,double& y,double& z);

			virtual void setReferenceCenter(const double& x,const double& y,const double& z);

		}; 
	}
}

#endif  //_IDATASOURCE_H
