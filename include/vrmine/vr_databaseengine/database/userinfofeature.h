#if !defined(_USERINFOFEATURE_H)
#define _USERINFOFEATURE_H


#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/field.h"
#include "vrmine/vr_databaseengine/database/propertyset.h"
#include "vrmine/vr_databaseengine/database_config.h"
#include "vrmine/vr_core/variant.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CUserInfoFeature : public VirtualMine::Database::CFeature
		{

		public:

			CUserInfoFeature();

			~CUserInfoFeature();

		/*	std::string getName();

			void setName(const std::string& name);


			virtual std::string getType();

			virtual void setType(const std::string& type);*/

		//	virtual void addField(CField* field);

		//	virtual void deleteField(CField* field);

		//	void setFieldID(const int& id);

			

		//	void setFieldType(const std::string& type);

		//	void setFieldWidth(const float& width);

		//	void setFieldHeight(const float& height);

		//	void setFieldBlob(Ogre::uchar* blob,int length);

		//	void setFieldBlob( VirtualMine::Core::CVRDataStream& datastream);

		//	void addField(VirtualMine::Database::CField& field);

		//	VirtualMine::Database::CField getValue(const int& index);

			
			void setFieldName(const std::string& name);

			void setFieldPassword(const std::string& pwd);

			std::string getFieldName();

			std::string getFieldPassword();


			VirtualMine::Database::CPropertySet* getPropertySet();

			//void setBlob(const VirtualMine::Core::CVRDataStream& datastream);
			//	//void addField(std::string name,std::string type);

			//	void addField(CField field);

			//	VirtualMine::Database::CField getValue(const std::string& fieldName);
			//
			//	VirtualMine::Database::CPropertySet getPropertySet();
			//private:		
			//	VirtualMine::Database::CPropertySet mPropertySet;

		

		};
	}
}

#endif //_USERINFOFEATURE_H