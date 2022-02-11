#if !defined(_FEATURE_H)
#define _FEATURE_H

#include <string>
#include "vrmine\vr_databaseengine\database_config.h"
#include "vrmine/vr_databaseengine/database/field.h"
#include "vrmine/vr_databaseengine/database/propertyset.h"
#include "vrmine/vr_databaseengine/database/ifeature.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CFeature : public VirtualMine::Database::IFeature
		{
		public:

			CFeature();

			~CFeature();

			//void addField(std::string name,VirtualMine::Core::ValueType type);
			//

		    virtual std::string getName();

			virtual void setName(const std::string& name); 

			virtual std::string getType();

			virtual void setType(const std::string& type);

			virtual void addField(CField* field);
			
			virtual void deleteField(CField* field);

	/*		virtual void setFieldID(const int& id,const int& index);*/

			//virtual void setFieldName(const std::string& name,const int& index);

			//virtual void setFieldWidth(const float& width,const int& index);

			//virtual void setFieldBlob(Ogre::uchar* blob,const int& index);

			virtual void setFieldID(const int& id);

			virtual void setFieldName(const std::string& name);

			virtual void setFieldWidth(const float& width);

			virtual void setFieldBlob(Ogre::uchar* blob,int length); 

			virtual void setFieldTexture(Ogre::uchar* blob,int length);

            virtual void setFieldType(const std::string& type);
   
            virtual void setFieldHeight(const float& height); 

			virtual void setFieldSectionType(const int& sectionType);

			virtual void setFieldHeightSupportType(const int& supportType);

			virtual void setFieldLanewayWindType(const int& lanewayWindType);


			 virtual int getFieldID();  

			virtual std::string getFieldName();

			virtual float getFieldWidth();

			virtual float getFieldHeight();

			virtual Ogre::uchar* getFieldBlob();

			virtual int getFieldBlobLength();

			virtual Ogre::uchar* getFieldTexture();

			virtual std::string getFieldType();

			virtual int getFieldSectionType();

		    virtual int getFieldHeightSupportType();

			virtual int getFieldLanewayWindType();


			//virtual void addField(CField& field);

		    virtual CField getValue(const int& index);

			//CField getValue(const int& index);

			virtual CPropertySet* getPropertySet();

		protected:
			std::string mName;
			std::string mType;
			CPropertySet* mpPropertySet;
		};
	}
}
#endif //_IFEATURE_H