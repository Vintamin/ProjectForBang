#if !defined(_FIELD_H)
#define _FIELD_H

#include <string>
#include "vrmine/vr_databaseengine/database/ifield.h"
#include "vrmine\vr_databaseengine\database_config.h"
#include "vrmine\vr_core\valuetype.h"
#include "vrmine\vr_core\variant.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CField : public VirtualMine::Database::IField
		{
		public:

			CField();

			CField(std::string name,VirtualMine::Core::ValueType type);

			~CField(); 

			std::string getName();

			void setName(const std::string& name);

			VirtualMine::Core::ValueType getType();

			void setType(const VirtualMine::Core::ValueType& type);

			int getSize();

			void setSize(const int& size);

			VirtualMine::Core::CVariant getVarient();

			void setVarient(const VirtualMine::Core::CVariant& vareint);

		private:

			std::string mName;

			VirtualMine::Core::ValueType mType;

			int mSize; 

			VirtualMine::Core::CVariant mVarient;
		};
	}
}

#endif //_FIELD_H