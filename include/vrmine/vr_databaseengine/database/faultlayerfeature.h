#if !defined(_FAULTLAYERFEATURE_H)
#define _FAULTLAYERFEATURE_H


#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/field.h"
#include "vrmine/vr_databaseengine/database/propertyset.h"
#include "vrmine/vr_databaseengine/database_config.h"
#include "vrmine/vr_core/variant.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CFaultLayerFeature : public VirtualMine::Database::CFeature
		{

		public:

			CFaultLayerFeature();

			~CFaultLayerFeature();

			std::string getName();

			void setName(const std::string& name);

			void setFieldID(const int& id);

			void setFieldName(const std::string& name);

			void setFieldDipAngle(const double& dipAngle);

			void setFieldUpLength(const double& upLength);

			void setFieldDownLength(const double& downLength);

			void setFieldBlob(Ogre::uchar* blob,int length);



			int getFieldID();

			std::string getFieldName();

			double getFieldDipAngle();

			double getFieldUpLength();

			double getFieldDownLength();


			//void getFieldBlob(Ogre::uchar* blob,int length);

			void setFieldBlob( VirtualMine::Core::CVRDataStream& datastream);

			void addField(VirtualMine::Database::CField& field);

			VirtualMine::Database::CField getValue(const int& index); 



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

#endif //_FAULTLAYERFEATURE_H