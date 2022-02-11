//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : workingplanefeature.h
//  @ Date : 2014/10/28
//  @ Author : ����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 

#if !defined(_WORKINGPLANEEFEATURE_H)
#define _WORKINGPLANEEFEATURE_H


#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/field.h"
#include "vrmine/vr_databaseengine/database/propertyset.h"
#include "vrmine/vr_databaseengine/database_config.h"
#include "vrmine/vr_core/variant.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CWorkingplaneFeature : public VirtualMine::Database::CFeature
		{

		public:

			CWorkingplaneFeature();

			~CWorkingplaneFeature();

			std::string getName();

			void setName(const std::string& name);

			void setFieldID(const int& id);

			void setFieldName(const std::string& name);

			void setFieldType(const std::string& type);

			void setFieldWidth(const float& width);

			void setFieldHeight(const float& height);

			void setFieldBlob(Ogre::uchar* blob,int length);

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

#endif //_WORKINGPLANEEFEATURE_H