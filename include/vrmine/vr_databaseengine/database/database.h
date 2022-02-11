#if !defined(_DATABASE_H)
#define _DATABASE_H

#include <string>
#include "vrmine/vr_databaseengine/database/idatasource.h"
#include "vrmine/vr_databaseengine/database/databaseinfo.h"
#include "vrmine/vr_databaseengine/database_config.h"

#include "vrmine/vr_databaseengine/database/modelfeature.h"
//
//#include "ogre/Ogre.h"
//#include "ogre/OgreVector3.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CDatabase : public IDataSource
		{
		public:

			CDatabase(IDataSourceInfo* pDataSourceInfo);

			~CDatabase();
			
			void setName(const std::string& name);

			std::string getName();

			std::string getType();

			int getID();

			virtual int createMetadataDataset();
	
			virtual int createLanewayDataset();

			virtual int createLevelLanewayDataset();

			virtual int createCoalLayerDataset();

			virtual int createDrillingDataset();
				
			virtual int createLogicDataset();			

			virtual int createBigLanewayDataset();
	
			virtual int createFaultLayerDataset();

			virtual int createDEMDataset();

			virtual int createImageDataset();




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

			
			//virtual void updataModelFeature(VirtualMine::Database::CModelFeature* feature,std::string festurename);

			virtual void updataModelFeature(VirtualMine::Database::IFeature* feature,std::string featurename);


			virtual void updataModelFeature2(VirtualMine::Database::IFeature* feature,std::string featurename,std::string datasetname);



			//virtual int 
			
			virtual IDataset* getDataset(const std::string& datasetName);

			virtual std::vector<IDataset*>* getDatasetSet();

			IDataSourceInfo* getDataSourceInfo();

		/*	void getReferenceCenter(double& x,double& y,double& z);

			void setReferenceCenter(const double& x,const double& y,const double& z);*/

		private:

			std::string mName;

			int mID;

			std::string mType;

			IDataSourceInfo* ref_mpDataSourceInfo;

			/*	double* mReferenceCenterX;

			double* mReferenceCenterY;

			double* mReferenceCenterZ;*/


		protected:

			std::vector<IDataset*>* mpDatasetSet;

		};
	}
}

#endif  //_DATABASE_H