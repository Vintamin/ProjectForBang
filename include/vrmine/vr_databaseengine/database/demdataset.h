//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : demdataset.h
//  @ Date : 2014/10/28
//  @ Author : 王凯
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 
#if !defined(_DEMDATASET_H)
#define _DEMDATASET_H


#include "vrmine/vr_databaseengine/database/feature.h"
#include "vrmine/vr_databaseengine/database/dataset.h"
#include "vrmine/vr_databaseengine/database_config.h"

namespace VirtualMine
{
	namespace Database
	{
		class VR_DATABASEENGINE_DLL CDEMDataset : public VirtualMine::Database::CDataset
		{
		public:
			CDEMDataset();

			~CDEMDataset();

			/*CDrillingFeature createFeature(const std::string& featureName);

			void destroyFeature(const std::string& featureName);

			CDrillingFeature* getFeature(int index);

			CDrillingFeature* getFeature(const std::string& featureName);
*/

	/*	private:
			vector<CDrillingFeature*>* mpDrillingFeature;*/

		};
	}
}

#endif//_DEMDATASET_H