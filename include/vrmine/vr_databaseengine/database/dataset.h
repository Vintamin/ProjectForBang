#if !defined(_DATASET_H)
#define _DATASET_H

#include<string>
#include<vector>
#include "vrmine/vr_databaseengine/database_config.h"
#include "vrmine/vr_databaseengine/database/idataset.h"
#include "vrmine/vr_databaseengine/database/feature.h"


namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CDataset : public VirtualMine::Database::IDataset
		{
		public:
			CDataset();

			~CDataset();
	
			//virtual IFeature createFeature(const std::string& featureName);

			virtual void addFeature(IFeature* feature);

			virtual void destroyFeature(const std::string& featureName);

			virtual IFeature* getFeature(const int& index);

            virtual IFeature* getFeature(const std::string& name); 

			virtual std::vector<IFeature*>* getFeatureList();

            virtual std::string getName();

			virtual void setName(const std::string& name);

			virtual std::string getType();

			virtual void setType(const std::string& type);

			virtual int getCount();

		protected: 

			std::vector<IFeature*>* mpFeatureList;

			std::string mName;  

			std::string mType;

			
		};
	}
}

#endif  //_DATASET_H