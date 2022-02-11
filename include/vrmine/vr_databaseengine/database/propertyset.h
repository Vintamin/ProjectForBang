#if !defined(_PROPERTYSET_H)
#define _PROPERTYSET_H

#include <string>
#include <vector>
#include "vrmine\vr_databaseengine\database_config.h"
#include "vrmine/vr_databaseengine/database/ipropertyset.h"
#include "vrmine/vr_databaseengine/database/field.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CPropertySet : public VirtualMine::Database::IPropertySet
		{
		public:

			CPropertySet();

			~CPropertySet();

			int getCount();

			std::vector<VirtualMine::Database::CField> getFields();			

			VirtualMine::Database::CField getValue(const int& index);

			VirtualMine::Database::CField getValue(const std::string& fieldName);
		
			void setValue(const VirtualMine::Database::CField& field,const int& index);

			void insertFields(const VirtualMine::Database::CField& field);

			void setFieldID(const int& id);

        	void setField(const CField& field,const int& id);
		private:
			std::vector<VirtualMine::Database::CField> mPropertySet; 
			   
		};
	}
}

#endif //_PROPERTYSET_H