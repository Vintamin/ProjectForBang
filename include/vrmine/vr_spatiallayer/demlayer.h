//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : cdemlayer.h
//  @ Date : 2014/7/27
//  @ Author : 盛佳良
//
//


#if !defined(_CDEMLAYER_H)
#define _CDEMLAYER_H

#include "vrmine/vr_spatiallayer/scenelayer.h"
#include "vrmine/vr_geometry/geometry/surface.h"

namespace VirtualMine
{
    namespace SpatialLayer
    {
        class VR_SPATIALLAYER_DLL CDemLayer : public CSceneLayer
        {
        public:
			CDemLayer();
			~CDemLayer();
            double getHeight(const double& x,const double& z);
			double getSlope(const double& x,const double& y,const double& z);
			void setDemData(VirtualMine::Geometry::CGrid* ref_pGridData);
			virtual void initialise();
			virtual void draw();
		protected:

			VirtualMine::Geometry::CGrid* mpGridData;
        };
    }
}

#endif  //_CDEMLAYER_H
