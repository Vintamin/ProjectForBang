#if !defined(_METADATAFEATURE_H)
#define _METADATAFEATURE_H

#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/field.h"
#include "vrmine/vr_databaseengine/database/propertyset.h"
#include "vrmine/vr_databaseengine/database_config.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CMetadataFeature : public VirtualMine::Database::CFeature
		{
		public:
			CMetadataFeature();

			~CMetadataFeature();

			void setFieldSR(const int& id);

			void setFieldName(const std::string& name);

			void setFieldType(const std::string& type);

			void setFieldminRangeX(const double& rangeX);

			void setFieldminRangeY(const double& rangeY);

			void setFieldminRangeZ(const double& rangeZ);

			void setFieldmaxRangeX(const double& rangeX);

			void setFieldmaxRangeY(const double& rangeY);

			void setFieldmaxRangeZ(const double& rangeZ);



			/*void setFieldID(const int& id,const int& index);

			void setFieldName(const std::string& name,const int& index);

			void setFieldType(const std::string& type,const int& index);*/

			VirtualMine::Database::CPropertySet* getPropertySet();



		private:
			VirtualMine::Database::CPropertySet* mpPropertySet; 
			
		};
	}
}

#endif //_METADATAFEATURE_H