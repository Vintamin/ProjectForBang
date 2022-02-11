//#if !defined(_FIELDS_H)
//#define _FIELDS_H
//#include <string>
//#include "vrmine/vr_databaseengine/database/field.h"
//#include "vrmine/vr_databaseengine/database/ifields.h"
//#include "vrmine\vr_databaseengine\database_config.h"
//#include <vector>
//
//namespace VirtualMine
//{
//	namespace Database
//	{
//		class CFields : public VirtualMine::Database::IFields
//		{
//		public:
//			CFields();
//
//			~CFields();
//
//			std::string getName();
//
//			void setName(const std::string& name);
//
//			int getFieldCount();
//
//			int getIndex(CField* field);
//
//			int findField(const std::string& fieldName);
//			//返回字段总数
//			int addField(CField* field);
//			//返回剩余字段总数 
//			int deleteField(const CField* field);
//
//
//		private:
//			std::string mName;
//
//			int mFieldCount;
//
//			std::vector<CField*>* mpFieldList;
//
//
//		};
//	}
//}
//
//#endif //_FIELDS_H