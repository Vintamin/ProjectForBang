#if !defined(_ROADFEATURE_H)
#define _ROADFEATURE_H

#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/field.h"
#include "vrmine/vr_databaseengine/database/propertyset.h"
#include "vrmine/vr_databaseengine/database_config.h"
#include "vrmine/vr_core/variant.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CRoadFeature : public VirtualMine::Database::CFeature
		{
		public:
			CRoadFeature();

			~CRoadFeature();

			void addField(VirtualMine::Database::CField& field);

			VirtualMine::Database::CField getValue(const int& index);

			void setFieldID(const int& id);

			void setFieldName(const std::string& name);

			void setFieldBlob(Ogre::uchar* blob,int length);


		private:

			VirtualMine::Database::CPropertySet* mpPropertySet;	

		};
	}
}
 
#endif //_ROADFEATURE_H