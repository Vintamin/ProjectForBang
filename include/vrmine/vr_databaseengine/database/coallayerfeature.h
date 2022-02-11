//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : coallayerfeature.h
//  @ Date : 2014/8/6
//  @ Author : 王凯
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 



#if !defined(_COALLAYERFEATURE_H)
#define _COALLAYERFEATURE_H

#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/field.h"
#include "vrmine\vr_databaseengine\database_config.h"
#include "vrmine/vr_databaseengine/database/propertyset.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CCoalLayerFeature : public VirtualMine::Database::CFeature
		{
		public:
			CCoalLayerFeature(); 

			~CCoalLayerFeature();  

			std::string getName();

			void setName(const std::string& name);

			void addField(CField field);

			VirtualMine::Database::CField getValue(const int& index);

            VirtualMine::Database::CPropertySet* getPropertySet();

			void setFieldID(const int& id);

			void setFieldName(const std::string& name);

			void setFieldBlob(Ogre::uchar* blob,int length);

			void setFieldBlob( VirtualMine::Core::CVRDataStream& datastream);

            void setFieldTexture(Ogre::uchar* blob,int length);

			void setFieldTexture( VirtualMine::Core::CVRDataStream& datastream); 


	/*	private:
			
			std::string mName;

			VirtualMine::Database::CPropertySet* mpPropertySet;*/

		};
	}
}

#endif //_COALLAYERFEATURE_H