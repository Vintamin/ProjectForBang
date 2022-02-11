#if !defined(_LANEWAYFEATURE_H)
#define _LANEWAYFEATURE_H

#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/field.h"
#include "vrmine/vr_databaseengine/database/propertyset.h"
#include "vrmine/vr_databaseengine/database_config.h"
#include "vrmine/vr_core/variant.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CLanewayFeature : public VirtualMine::Database::CFeature
		{

		public:

			CLanewayFeature();

			~CLanewayFeature();

			//std::string getName();

		    //void setName(const std::string& name);
		
			void setFieldID(const int& id);

			void setFieldName(const std::string& name);

            void setFieldType(const std::string& type);

			void setFieldWidth(const float& width);

			void setFieldHeight(const float& height);

			void setFieldSectionType(const int& sectionType);

			void setFieldHeightSupportType(const int& supportType);

			void setFieldBlob(Ogre::uchar* blob,int length);

			void setFieldBlob( VirtualMine::Core::CVRDataStream& datastream);

			void setFieldLanewayWindType(const int& lanewayWindType);


			int getFieldID();

			std::string getFieldName();

			std::string getFieldType();

			float getFieldWidth();

			float getFieldHeight();

			int getFieldSectionType();

			int getFieldHeightSupportType();

			void* getFieldGeometryBlob();
		    int getFieldGeometryBlobLength();

			int getFieldLanewayWindType();


		    void addField(VirtualMine::Database::CField& field);



		    VirtualMine::Database::CField getValue(const int& index);

			//CField getValue(const int& index);

			//VirtualMine::Database::CPropertySet* getPropertySet();

			//void setBlob(const VirtualMine::Core::CVRDataStream& datastream);
			//	//void addField(std::string name,std::string type);
			 
			//	void addField(CField field);

			//	VirtualMine::Database::CField getValue(const std::string& fieldName);
			//
			//	VirtualMine::Database::CPropertySet getPropertySet();
			//private:		
			//	VirtualMine::Database::CPropertySet mPropertySet;

		//private:	

			//std::string mName;

			//VirtualMine::Database::CPropertySet* mpPropertySet;

		};
	}
}

#endif //_LANEWAYFEATURE_H