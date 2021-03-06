//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : coallayerfeature.h
//  @ Date : 2015/7/30
//  @ Author : 王凯
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 



#if !defined(_CONPROGRESSFEATURE_H)
#define _CONPROGRESSFEATURE_H

#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/field.h"
#include "bang/rocklayerconfig.h"
#include "vrmine/vr_databaseengine/database/propertyset.h"

namespace VirtualMine
{
	namespace Bang_Database
	{   
		class VR_BANG_DATABASEENGINE_DLL CConProgressFeature : public VirtualMine::Database::CFeature
		{
		public:
			CConProgressFeature(); 

			~CConProgressFeature();  

			void setFieldProjectID(const int& id);
			int getFieldProjectID();

			void setFieldPointID(const int& id);
			int getFieldPointID();


			void setFieldPositionX(const double& posX);

			void setFieldPositionY(const double& posY);

			void setFieldPositionZ(const double& posZ); 

			double getFieldPositionX();

			double getFieldPositionY();

			double getFieldPositionZ(); 

		};
	}
}

#endif //