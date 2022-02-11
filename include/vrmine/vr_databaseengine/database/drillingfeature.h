#if !defined(_DRILLINGFEATURE_H)
#define _DRILLINGFEATURE_H
 

#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/field.h"
#include "vrmine/vr_databaseengine/database/propertyset.h"
#include "vrmine/vr_databaseengine/database_config.h"


namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CDrillingFeature : public VirtualMine::Database::CFeature
		{

		public:

			CDrillingFeature();

			~CDrillingFeature();

			std::string getName();

			void setName(const std::string& name);

			VirtualMine::Database::CPropertySet* getPropertySet();

			void addField(VirtualMine::Database::CField& field);

			VirtualMine::Database::CField getValue(const int& index);           

			void setFieldID(const int& id);

			void setFieldName(const std::string& name);

			void setFieldPositionX(const double& posX);

			void setFieldPositionY(const double& posY);

			void setFieldPositionZ(const double& posZ); 

			void setFieldBlob(Ogre::uchar* blob,int length);



			int getFieldID();

			std::string getFieldName();

			double getFieldPositionX();

			double getFieldPositionY();

			double getFieldPositionZ(); 

			//double setFieldBlob(Ogre::uchar* blob,int length);

		private:	

			std::string mName;

			VirtualMine::Database::CPropertySet* mpPropertySet;	

		};
	}
}

#endif//_DRILLINGRFEATURE_H