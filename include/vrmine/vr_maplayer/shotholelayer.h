#if !defined(_CSHOTHOLELAYER_H)
#define _CSHOTHOLELAYER_H

#include "vrmine/vr_maplayer/igeometrydrawitem.h"
#include <QtGui/QPixmap>
#include "vrmine/vr_maplayer/map2dlayer.h"
#include "vrmine/vr_maplayer/map.h"
#include "vrmine/vr_maplayer/map2dlayer.h"
#include "vrmine/vr_maplayer/linedrawitem.h"
#include "vrmine/vr_maplayer/pointdrawitem.h"
#include "vrmine/vr_maplayer/textDrawItem.h"
#include "vrmine/vr_maplayer/arcdrawitem.h"
#include "vrmine/vr_maplayer/line2D.h"
#include "vrmine/vr_maplayer/point2D.h"
#include "vrmine/vr_style/style/linestyle.h"
#include "OGRE/OgreAxisAlignedBox.h"

 

namespace VirtualMine
{
	namespace Map
	{
		class CBoreHole2D
		{
		public:
			CBoreHole2D(void)
			{

			};
			~CBoreHole2D(void){

			};
		public:
			QString mboomType;
			int mboomID;
			int mboomOrder;
			Ogre::Vector3 mposStart;
			Ogre::Vector3 mposEnd;
			Ogre::Vector3 mdynamiteCor;
			Ogre::Vector3 mmudCor;
			Ogre::Vector3 msealCor;
			double mdynamitelength;
			double mmudLength;
			double msealLenght;

		};
		class VR_MAPLAYER_EXPORT C2DShotHoleLayerFactory : public VirtualMine::SpatialInterface::CLayerFactory
		{
		public:
			C2DShotHoleLayerFactory();
			virtual ~C2DShotHoleLayerFactory();
			virtual VirtualMine::SpatialInterface::ILayer* createInstance(const std::string& name);
			virtual void destroyInstance(VirtualMine::SpatialInterface::ILayer* pLayer);
			virtual std::string getType();
		};
		class VR_MAPLAYER_EXPORT C2DShotHoleLayer : public  CMap2DLayer
		{
		public:
			C2DShotHoleLayer();
			~C2DShotHoleLayer();
			virtual	void initialise();
	        void setVisibled(const int& type,const bool& value);
			void setVisibled(const bool& value);
			//kk 获取mAllVector
			vector<CBoreHole2D> getmAllVector();
			
		private:
			Ogre::Vector3 getmidCor(Ogre::Vector3 &st,Ogre::Vector3 &ed,double z );//计算封孔位置，水泥位置坐标
			void drawRenderPoint(VirtualMine::Map::CPoint2D* pPoint,Ogre::ColourValue renderColor,const bool& visible);
			void drawRenderLine(VirtualMine::Map::CLine2D* pLine,Ogre::ColourValue renderColor,const bool& visible );
	        void drawMark(std::vector<CBoreHole2D> &poVector,Ogre::ColourValue renderColor);
			void drawOutFrame();
			void drawBoomOrder();
			void drawselectedHole(bool draw,std::vector<std::string>& nodrawtype);
			void drawBoomOrderMark();
	        void drawBoomID();
			void drawAllHole();
	        void holeTypeSort();
			void orderTypeSort();
	        void drawHoleType();
			void drawOrderType();
			void drawLeftView();
			void drawOverView();
			void computeBoundingBox();
			void initialData();


		private:
			
			std::vector<CBoreHole2D> mAllVector;
			std::map<int,std::vector<CBoreHole2D>> mOderVector;
			std::map<std::string,std::vector<CBoreHole2D>> mtypeVector;
			std::string mholetype;
			int  bangOrder;
			
			Ogre::Vector3 mpoBox;

		}; 

		class VR_MAPLAYER_EXPORT C2DLanewaySectionLayer : public  CMap2DLayer
		{
		public:
			C2DLanewaySectionLayer();
			~C2DLanewaySectionLayer();
			virtual	void initialise();
			void drawOutFrame();
			void drawRenderLine(VirtualMine::Map::CLine2D* pLine,Ogre::ColourValue renderColor,const bool& visible );
			void computeBoundingBox();
			void setVisibled(const bool& value);
		}; 
		class VR_MAPLAYER_EXPORT C2DLanewaySectionLayerFacetory :public VirtualMine::SpatialInterface::CLayerFactory
		{
		public:
			C2DLanewaySectionLayerFacetory();
			virtual ~C2DLanewaySectionLayerFacetory();
			virtual VirtualMine::SpatialInterface::ILayer* createInstance(const std::string& name);
			virtual void destroyInstance(VirtualMine::SpatialInterface::ILayer* pLayer);
			virtual std::string getType();
#if 0


		private:
			Ogre::Vector3 getmidCor(Ogre::Vector3 &st,Ogre::Vector3 &ed,double z );//计算封孔位置，水泥位置坐标
			void drawRenderPoint(std::vector<Ogre::Vector3> &poVector,Ogre::ColourValue renderColor);
			void drawRenderLine(std::vector<Ogre::Vector3> &poVector,Ogre::ColourValue renderColor);
			void drawMark(std::vector<CBoreHole2D> &poVector,Ogre::ColourValue renderColor);
			void drawOutFrame();

			void drawAllHole();
			void holeTypeSort();
			void orderTypeSort();
			void drawHoleType();
			void drawOrderType();
			void drawLeftView();
			void drawOverView();
			void computeBoundingBox();
		private:

			std::map<int,std::vector<CBoreHole2D>> mOderVector;
			std::map<std::string,std::vector<CBoreHole2D>> mtypeVector;
			std::string mholetype;
			int  bangOrder;
			std::vector<CBoreHole2D> mAllVector;
			Ogre::Vector3 mpoBox;

#endif



		}; 

		class VR_MAPLAYER_EXPORT C2DEscapeRouteLayer : public  CMap2DLayer
		{
		public:
			C2DEscapeRouteLayer();
			~C2DEscapeRouteLayer();
			virtual	void initialise();
#if 0


		private:
			Ogre::Vector3 getmidCor(Ogre::Vector3 &st,Ogre::Vector3 &ed,double z );//计算封孔位置，水泥位置坐标
			void drawRenderPoint(std::vector<Ogre::Vector3> &poVector,Ogre::ColourValue renderColor);
			void drawRenderLine(std::vector<Ogre::Vector3> &poVector,Ogre::ColourValue renderColor);
			void drawMark(std::vector<CBoreHole2D> &poVector,Ogre::ColourValue renderColor);
			void drawOutFrame();

			void drawAllHole();
			void holeTypeSort();
			void orderTypeSort();
			void drawHoleType();
			void drawOrderType();
			void drawLeftView();
			void drawOverView();
			void computeBoundingBox();
		private:

			std::map<int,std::vector<CBoreHole2D>> mOderVector;
			std::map<std::string,std::vector<CBoreHole2D>> mtypeVector;
			std::string mholetype;
			int  bangOrder;
			std::vector<CBoreHole2D> mAllVector;
			Ogre::Vector3 mpoBox;

#endif



		}; 

		//kk施工进度
		class VR_MAPLAYER_EXPORT C2DConProgressLayer : public  CMap2DLayer
		{
		public:
			C2DConProgressLayer();
			~C2DConProgressLayer();
			virtual	void initialise();
#if 0


		private:
			Ogre::Vector3 getmidCor(Ogre::Vector3 &st,Ogre::Vector3 &ed,double z );//计算封孔位置，水泥位置坐标
			void drawRenderPoint(std::vector<Ogre::Vector3> &poVector,Ogre::ColourValue renderColor);
			void drawRenderLine(std::vector<Ogre::Vector3> &poVector,Ogre::ColourValue renderColor);
			void drawMark(std::vector<CBoreHole2D> &poVector,Ogre::ColourValue renderColor);
			void drawOutFrame();

			void drawAllHole();
			void holeTypeSort();
			void orderTypeSort();
			void drawHoleType();
			void drawOrderType();
			void drawLeftView();
			void drawOverView();
			void computeBoundingBox();
		private:

			std::map<int,std::vector<CBoreHole2D>> mOderVector;
			std::map<std::string,std::vector<CBoreHole2D>> mtypeVector;
			std::string mholetype;
			int  bangOrder;
			std::vector<CBoreHole2D> mAllVector;
			Ogre::Vector3 mpoBox;

#endif



		}; 


		class VR_MAPLAYER_EXPORT C2DEscapeRouteLayerFacetory :public VirtualMine::SpatialInterface::CLayerFactory
		{
		public:
			C2DEscapeRouteLayerFacetory();
			virtual ~C2DEscapeRouteLayerFacetory();
			virtual VirtualMine::SpatialInterface::ILayer* createInstance(const std::string& name);
			virtual void destroyInstance(VirtualMine::SpatialInterface::ILayer* pLayer);
			virtual std::string getType();
#if 0


		private:
			Ogre::Vector3 getmidCor(Ogre::Vector3 &st,Ogre::Vector3 &ed,double z );//计算封孔位置，水泥位置坐标
			void drawRenderPoint(std::vector<Ogre::Vector3> &poVector,Ogre::ColourValue renderColor);
			void drawRenderLine(std::vector<Ogre::Vector3> &poVector,Ogre::ColourValue renderColor);
			void drawMark(std::vector<CBoreHole2D> &poVector,Ogre::ColourValue renderColor);
			void drawOutFrame();

			void drawAllHole();
			void holeTypeSort();
			void orderTypeSort();
			void drawHoleType();
			void drawOrderType();
			void drawLeftView();
			void drawOverView();
			void computeBoundingBox();
		private:

			std::map<int,std::vector<CBoreHole2D>> mOderVector;
			std::map<std::string,std::vector<CBoreHole2D>> mtypeVector;
			std::string mholetype;
			int  bangOrder;
			std::vector<CBoreHole2D> mAllVector;
			Ogre::Vector3 mpoBox;

#endif



		}; 

		//kk施工进度
		class VR_MAPLAYER_EXPORT C2DConProgressLayerFacetory :public VirtualMine::SpatialInterface::CLayerFactory
		{
		public:
			C2DConProgressLayerFacetory();
			virtual ~C2DConProgressLayerFacetory();
			virtual VirtualMine::SpatialInterface::ILayer* createInstance(const std::string& name);
			virtual void destroyInstance(VirtualMine::SpatialInterface::ILayer* pLayer);
			virtual std::string getType();
#if 0


		private:
			Ogre::Vector3 getmidCor(Ogre::Vector3 &st,Ogre::Vector3 &ed,double z );//计算封孔位置，水泥位置坐标
			void drawRenderPoint(std::vector<Ogre::Vector3> &poVector,Ogre::ColourValue renderColor);
			void drawRenderLine(std::vector<Ogre::Vector3> &poVector,Ogre::ColourValue renderColor);
			void drawMark(std::vector<CBoreHole2D> &poVector,Ogre::ColourValue renderColor);
			void drawOutFrame();

			void drawAllHole();
			void holeTypeSort();
			void orderTypeSort();
			void drawHoleType();
			void drawOrderType();
			void drawLeftView();
			void drawOverView();
			void computeBoundingBox();
		private:

			std::map<int,std::vector<CBoreHole2D>> mOderVector;
			std::map<std::string,std::vector<CBoreHole2D>> mtypeVector;
			std::string mholetype;
			int  bangOrder;
			std::vector<CBoreHole2D> mAllVector;
			Ogre::Vector3 mpoBox;

#endif



		}; 

	}
}
#endif  