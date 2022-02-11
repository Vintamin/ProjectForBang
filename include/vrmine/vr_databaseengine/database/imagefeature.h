#if !defined(_IMAGEFEATURE_H)
#define _IMAGEFEATURE_H


#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/field.h"
#include "vrmine/vr_databaseengine/database/propertyset.h"
#include "vrmine/vr_databaseengine/database_config.h"
#include "vrmine/vr_core/variant.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CImageFeature : public VirtualMine::Database::CFeature
		{

		public:

			CImageFeature();

			~CImageFeature();

			std::string getName();

			void setName(const std::string& name);

			void setFieldID(const int& id);

			int getFieldID();

			void setFieldName(const std::string& name);

			std::string getFieldName();

			void setFieldType(const std::string& type);

			void setFieldWidth(const float& width);

			void setFieldHeight(const float& height);

			void setFieldBlob(Ogre::uchar* blob,int length);

			Ogre::uchar* getFieldBlob();

			int getFieldBlobLength();

			void setFieldBlob( VirtualMine::Core::CVRDataStream& datastream);

			void addField(VirtualMine::Database::CField& field);

			VirtualMine::Database::CField getValue(const int& index);

			void setFieldMinPosX(const double& pos);
			void setFieldMinPosY(const double& pos);
			void setFieldMinPosZ(const double& pos);
			void setFieldMaxPosX(const double& pos);
			void setFieldMaxPosY(const double& pos);
			void setFieldMaxPosZ(const double& pos);

			double getFieldMinPosX();
			double getFieldMinPosY();
			double getFieldMinPosZ();
			double getFieldMaxPosX();
			double getFieldMaxPosY();
			double getFieldMaxPosZ();


			VirtualMine::Database::CPropertySet* getPropertySet();

			//void setBlob(const VirtualMine::Core::CVRDataStream& datastream);
			//	//void addField(std::string name,std::string type);

			//	void addField(CField field);

			//	VirtualMine::Database::CField getValue(const std::string& fieldName);
			//
			//	VirtualMine::Database::CPropertySet getPropertySet();
			//private:		
			//	VirtualMine::Database::CPropertySet mPropertySet;

		private:	

			std::string mName;

			VirtualMine::Database::CPropertySet* mpPropertySet;

		};
	}
}

#endif //_IMAGEFEATURE_H