#include "vrmine/vr_spatiallayer/shotholelayer.h"
#include "vrmine/vr_databaseengine/database/ifeature.h"
#include "vrmine/vr_spatialinterface/igeoobject.h"
#include <list>
#include "vrmine/vr_utility/objecttransformer.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_spatialrender/lanewaypiperender/pipeline.h"
#include "bang/shotholefeature.h"
#include "vrmine/vr_geometry/geometry/line.h"
#include "vrmine/vr_style/style/linestyle.h"
#include "vrmine/vr_spatialengine/geoscenecamera.h"
#include "vrmine/vr_style/style/pipestyle.h"


#include "vrmine\vr_spatialrender\baserender\geomultirenderableobject.h"

using namespace VirtualMine::Database;
using namespace VirtualMine::Base;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::BaseRender;
using namespace VirtualMine::Bang_Database;
using namespace VirtualMine::Geometry;
using namespace VirtualMine::Style;



namespace VirtualMine
{
    namespace SpatialLayer
    {

		CShotHoleLayer::CShotHoleLayer()
		{
			this->mType = VirtualMine::Core::GeoDataType::GDT_SHOTHOLE;
		}

		CShotHoleLayer::~CShotHoleLayer()
		{
		}

		void CShotHoleLayer::update()
		{
		
		}

		void CShotHoleLayer::initialise()
		{
			//assert(this->ref_mpDataSet);
		if (NULL == this->ref_mpDataSet)
				return;
			this->ref_mpGeoSceneManager = this->getScene()->getGeoSceneManager();

			CPipeLine* pRenderableObject(NULL);
			int featureCount = this->ref_mpDataSet->getCount();//需要数据库引擎提供接口
			for (int i = 0 ; i < featureCount; ++i)
			{
				IFeature* pFeature = this->ref_mpDataSet->getFeature(i);
			//	//VirtualMine::SpatialInterface::IGeoObject* pGeoObject = new VirtualMine::Base::CGeoLine();
			//	//pGeoObject->fromFeature(pFeature);
				CShotHoleFeature* shotholeFeature = dynamic_cast<CShotHoleFeature*>(pFeature);
				int boomProID =shotholeFeature->getFieldProjectID();	
				std::string boomType = shotholeFeature->getFieldType();
				int boomID = shotholeFeature->getFieldHoleID();
				int boomOrder = shotholeFeature->getFieldBangOrder();
				double boomDepth = shotholeFeature->getFieldShotHoleDepth();
				double boomSmallResistLine = shotholeFeature->getFieldSmallResistLine();
				double booomInterval = shotholeFeature->getFieldShotHoleInterLength();
				//kk起点
				Ogre::Vector3 startPoint(shotholeFeature->getFieldPositionX(),shotholeFeature->getFieldPositionY(),-shotholeFeature->getFieldPositionZ());
				//kk终点
				Ogre::Vector3 endPoint(shotholeFeature->getFieldPositionEndX(),shotholeFeature->getFieldPositionEndY(),-shotholeFeature->getFieldPositionEndZ());
				float scale = 5;

				startPoint *= scale;
				endPoint *= scale;
				Ogre::Vector3 dir = endPoint - startPoint;
				dir.normalise();

				//kk 定义fengniLine、shuipaoniLine和zhuangyaoLine的长度
				double fengniLenth = shotholeFeature->getFieldFengniLength() * scale;
				double shuipaoniLenth = shotholeFeature->getFieldShuipaoniLength() * scale;
				double zhuangyaoLenth = shotholeFeature->getFieldZhuangyaoLength() * scale;
				if (fengniLenth < 0.001)
				{
					fengniLenth = 0.1 * scale;
				}
				if (shuipaoniLenth < 0.001)
				{
					shuipaoniLenth = 0.1 * scale;
				}
				if (zhuangyaoLenth < 0.001)
				{
					zhuangyaoLenth = 0.1 * scale;
				}

				Ogre::Vector3 fengniPoint = startPoint + fengniLenth*dir;
				Ogre::Vector3 shuipaoniPoint = fengniPoint + shuipaoniLenth*dir;
				Ogre::Vector3 zhuangyaoPoint = shuipaoniPoint + zhuangyaoLenth*dir;

				VirtualMine::SpatialInterface::IGeoObject* pGeoObject1 = new VirtualMine::Base::CShotHoleGeoLine();
				VirtualMine::SpatialInterface::IGeoObject* pGeoObject2 = new VirtualMine::Base::CShotHoleGeoLine();
				VirtualMine::SpatialInterface::IGeoObject* pGeoObject3 = new VirtualMine::Base::CShotHoleGeoLine();

				//CLine* fengniLine =dynamic_cast<CLine*>(pGeoObject1);
				
				CLine* fengniLine = (CLine*)pGeoObject1->getGeometry();
				fengniLine->addPoint(startPoint.x,startPoint.y,startPoint.z);//kk startPoint起点
				fengniLine->addPoint(fengniPoint.x,fengniPoint.y,fengniPoint.z);//kk  fengniPoint终点
				
				
				CLine* shuipaoniLine = (CLine*)pGeoObject2->getGeometry();
				shuipaoniLine->addPoint(fengniPoint.x,fengniPoint.y,fengniPoint.z);//kk fengniPoint起点
				shuipaoniLine->addPoint(shuipaoniPoint.x,shuipaoniPoint.y,shuipaoniPoint.z);//kk shuipaoniPoint终点

			
				CLine* zhuangyaoLine = (CLine*)pGeoObject3->getGeometry();
				zhuangyaoLine->addPoint(shuipaoniPoint.x,shuipaoniPoint.y,shuipaoniPoint.z);//kk shuipaoniPoint起点
				zhuangyaoLine->addPoint(endPoint.x,endPoint.y,endPoint.z);//kk endPoint终点
						
				CPipeLineStyle* fengniStyle = dynamic_cast<CPipeLineStyle*>(pGeoObject1->getStyle());
				CPipeLineStyle* shuipaoniStyle = dynamic_cast<CPipeLineStyle*>(pGeoObject2->getStyle());
				CPipeLineStyle* zhuangyaoStyle = dynamic_cast<CPipeLineStyle*>(pGeoObject3->getStyle());
				

				/*	CPipeLineStyle* fengniStyle = (CPipeLineStyle*)(pGeoObject1->getStyle());
				CPipeLineStyle* shuipaoniStyle = (CPipeLineStyle*)(pGeoObject2->getStyle());
				CPipeLineStyle* zhuangyaoStyle =(CPipeLineStyle*)(pGeoObject3->getStyle());*/

				fengniStyle->setColor(Ogre::ColourValue(0.3,0.2,0.1,1));
				
				//kk原始代码
				fengniStyle->setWidth(0.4);
				//fengniStyle->setWidth(shotholeFeature->getFieldFengniLength());
				fengniStyle->setBoomID(boomID);
				fengniStyle->setBoomOrder(boomOrder);
				std::string tmp = boomType.c_str();
				fengniStyle->setBoomType(tmp);
				fengniStyle->setStartPositionX(shotholeFeature->getFieldPositionX());
				fengniStyle->setStartPositionY(shotholeFeature->getFieldPositionY());
				fengniStyle->setStartPositionZ(shotholeFeature->getFieldPositionZ());
				fengniStyle->setEndPositionX(shotholeFeature->getFieldPositionEndX());
				fengniStyle->setEndPositionY(shotholeFeature->getFieldPositionEndY());
				fengniStyle->setEndPositionZ(shotholeFeature->getFieldPositionEndZ());
				fengniStyle->setBoomFengNiLength(fengniLenth/scale);
				fengniStyle->setBoomShuiPaoNiLength(shuipaoniLenth/scale);
				fengniStyle->setBoomZhuangYaoLength(zhuangyaoLenth/scale);
				fengniStyle->setBoomProjectID(boomProID);
				fengniStyle->setBoomDepth(boomDepth);
				fengniStyle->setBoomInterval(booomInterval);
				fengniStyle->setBoomLineOfLeastResistance(boomSmallResistLine);

				shuipaoniStyle->setColor(Ogre::ColourValue(0.1,0.8,0.8,1));
				//kk原始代码
				shuipaoniStyle->setWidth(0.4);
				//shuipaoniStyle->setWidth(shotholeFeature->getFieldShuipaoniLength);
				shuipaoniStyle->setBoomID(boomID);
				shuipaoniStyle->setBoomOrder(boomOrder);
				shuipaoniStyle->setBoomType(boomType.c_str());
				shuipaoniStyle->setStartPositionX(shotholeFeature->getFieldPositionX());
				shuipaoniStyle->setStartPositionY(shotholeFeature->getFieldPositionY());
				shuipaoniStyle->setStartPositionZ(shotholeFeature->getFieldPositionZ());
				shuipaoniStyle->setEndPositionX(shotholeFeature->getFieldPositionEndX());
				shuipaoniStyle->setEndPositionY(shotholeFeature->getFieldPositionEndY());
				shuipaoniStyle->setEndPositionZ(shotholeFeature->getFieldPositionEndZ());
				shuipaoniStyle->setBoomFengNiLength(fengniLenth/scale);
				shuipaoniStyle->setBoomShuiPaoNiLength(shuipaoniLenth/scale);
				shuipaoniStyle->setBoomZhuangYaoLength(zhuangyaoLenth/scale);
				shuipaoniStyle->setBoomProjectID(boomProID);
				shuipaoniStyle->setBoomDepth(boomDepth);
				shuipaoniStyle->setBoomInterval(booomInterval);
				shuipaoniStyle->setBoomLineOfLeastResistance(boomSmallResistLine);

				zhuangyaoStyle->setColor(Ogre::ColourValue(0.8,0.8,0.1,1));
				//kk原始代码
				zhuangyaoStyle->setWidth(0.4);
				//zhuangyaoStyle->setWidth(shotholeFeature->getFieldZhuangyaoLength());
				zhuangyaoStyle->setBoomID(boomID);
				zhuangyaoStyle->setBoomOrder(boomOrder);
				zhuangyaoStyle->setBoomType(boomType.c_str());
				zhuangyaoStyle->setStartPositionX(shotholeFeature->getFieldPositionX());
				zhuangyaoStyle->setStartPositionY(shotholeFeature->getFieldPositionY());
				zhuangyaoStyle->setStartPositionZ(shotholeFeature->getFieldPositionZ());
				zhuangyaoStyle->setEndPositionX(shotholeFeature->getFieldPositionEndX());
				zhuangyaoStyle->setEndPositionY(shotholeFeature->getFieldPositionEndY());
				zhuangyaoStyle->setEndPositionZ(shotholeFeature->getFieldPositionEndZ());
				zhuangyaoStyle->setBoomFengNiLength(fengniLenth/scale);
				zhuangyaoStyle->setBoomShuiPaoNiLength(shuipaoniLenth/scale);
				zhuangyaoStyle->setBoomZhuangYaoLength(zhuangyaoLenth/scale);
				zhuangyaoStyle->setBoomProjectID(boomProID);
				zhuangyaoStyle->setBoomDepth(boomDepth);
				zhuangyaoStyle->setBoomInterval(booomInterval);
				zhuangyaoStyle->setBoomLineOfLeastResistance(boomSmallResistLine);


				/*pGeoObject1->setGeometry(fengniLine,true);
				pGeoObject2->setGeometry(shuipaoniLine,true);
				pGeoObject3->setGeometry(zhuangyaoLine,true);

				pGeoObject1->setStyle(fengniStyle,true);
				pGeoObject2->setStyle(shuipaoniStyle,true);
				pGeoObject3->setStyle(zhuangyaoStyle,true);*/

				if(NULL == pRenderableObject)
					pRenderableObject = new  CPipeLine();

				pRenderableObject->addGeoObject(pGeoObject1);
				pRenderableObject->addGeoObject(pGeoObject2);
				pRenderableObject->addGeoObject(pGeoObject3);

			}
			if (pRenderableObject)
			{
				//kk源代码
				/*if(NULL != this->mpRenderableObject)
				{
					this->mpRenderableObject->deRender();
					SAFE_DELETE(this->mpRenderableObject);
				}*/
				pRenderableObject->setGeoSceneManager(this->ref_mpGeoSceneManager);
				pRenderableObject->build();
				
				pRenderableObject->setNode(this->ref_mpGeoSceneManager->createSceneNode());
				this->mpRenderableObject = pRenderableObject;
			}
			CSceneLayer::initialise();

#if 1 调整镜头方向
			Ogre::Vector3 pos(0,10,50);
			Ogre::Vector3 dir(-0.016592,-0.324534,-0.94573396);
			static_cast<VirtualMine::SpatialEngine::CGeoSceneCamera*>(this->getGeoSceneManager()->getCamera(VirtualMine::SpatialEngine::CGeoSceneCamera::DEFAULT_CAMERA_NAME))->setPosition(pos);
			static_cast<VirtualMine::SpatialEngine::CGeoSceneCamera*>(this->getGeoSceneManager()->getCamera(VirtualMine::SpatialEngine::CGeoSceneCamera::DEFAULT_CAMERA_NAME))->setDirection(dir);
#endif
		
}

		void CShotHoleLayer::notifyUpdate()
		{
			
		}

        void CShotHoleLayer::setFrameMode(bool isFrameMode)
		{
			//Ogre::MaterialPtr material = Ogre::MaterialManager::getSingletonPtr()->getByName("pureMaterial",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

			//if (!material.isNull())
			//{
			//	Ogre::Pass* pass = material->getTechnique(0)->getPass(0);
			//	pass->setCullingMode(Ogre::CULL_NONE);
			//	pass->setPolygonMode(Ogre::PM_WIREFRAME);
			//	material->load();
			//}

			//if	(this->mpRenderableObject == NULL) return;
			//CPipeLine* pipeRenderObject = dynamic_cast<CPipeLine*>(this->mpRenderableObject);
			//if (pipeRenderObject == NULL)
			//{
			//	return;
			//}
			//int objectCount = pipeRenderObject->getGeoObjectCount();
			//for (int i = 0; i<objectCount; ++i)
			//{
			//	CTerraneObject* terraneObject = dynamic_cast<CTerraneObject*>(terraneRenderObject->getGeoObject(i));
			//	CTerraneProperty* terranePro = dynamic_cast<CTerraneProperty*>(terraneObject->getGeoProperty());
			//	CTerraneStyle* terraneStyle = dynamic_cast<CTerraneStyle*>(terraneObject->getStyle());
			//	//CLaneWayLineGeometry* lanewayGeometry = dynamic_cast<CLaneWayLineGeometry*>(lanewayObject->getGeometry());
			//	//CLanewayStyle* lanewayStyle = dynamic_cast<CLanewayStyle*>(lanewayObject->getStyle());

			//	Ogre::ManualObject* renderObject = this->ref_mpGeoSceneManager->getManualObject(terranePro->getName());
			//	int count = renderObject->getNumSections();
			//	if (isFrameMode)
			//	{
			//		for (int j = 0; j< count; ++j)
			//		{
			//			renderObject->getSection(j)->setMaterialName("pureMaterial");
			//		}
			//	}
			//	else
			//	{
			//		for (int j = 0; j< count; ++j)
			//		{
			//			renderObject->getSection(j)->setMaterialName(terranePro->getName());
			//		}
			//	}

			//}
		
		}

	/*	std::vector<VirtualMine::SpatialInterface::IGeoObject*> CShotHoleLayer::getPipeGeoObjVector()
		{
			return mPipeGeoObjVector;
		}*/

		//kk 装药长度的函数判断
		int CShotHoleLayer::getZhuangyaoList(std::vector<double*> paramArray,double changeData,double oldLength)
		{
			double leavelen = *paramArray[0] - changeData;
			if ( (2*oldLength)/3 <changeData ||changeData<=0)
			{
				cout<<"超过了三分之二或者小于0"<<endl;
				return 0;
			}else
			{
				*paramArray[0]=changeData;
				if (*paramArray[2]+leavelen >(1*oldLength)/3   )//判断封孔加剩余长度大于三分之一
				{
					cout<<"封孔长度大于三分之一"<<endl;
					//再判断如果加到水炮泥加剩余长度是否大于长度的1/3
					if (*paramArray[1] +leavelen >(1*oldLength)/3)
					{
						//多余的加到装药长度和封孔长度
						*paramArray[2] = (1*oldLength)/3;//封孔长度
						*paramArray[0] = oldLength-*paramArray[2]-*paramArray[1];//装药长度重新赋值不按照输入的值来
						return 1;

					}else{
						//水炮泥加剩余长度小于长度的1/3
						*paramArray[1] = *paramArray[1] +leavelen;//加到水炮泥长度上
						return 1;
					}

				}else if(*paramArray[2]+leavelen <(1*oldLength)/5){//判断封孔加剩余长度小于五分之一，直接减小水炮泥的长度
					cout<<"封孔长度小于五分之一"<<endl;
					//封孔长度不变，水炮泥长度等于剩余长度
					*paramArray[1] = oldLength -*paramArray[0]-*paramArray[2];
					return 1;

				}	
				else{ //判断封孔加剩余长度小于三分之一并且大于五分之一
					//加到封孔长度上
					*paramArray[2] = *paramArray[2] +leavelen;
					//水炮泥长度等于剩余长度
					*paramArray[1] = oldLength -*paramArray[0]-*paramArray[2];
					return 1;
				}
			}

		}
		//kk 封孔长度的函数判断
		int CShotHoleLayer::getFengkongList(std::vector<double*> paramArray,double changeData,double oldLength)
		{
			double leavelen = *paramArray[2] - changeData;
			if ( (1*oldLength)/3 <changeData ||changeData<=(1*oldLength)/5)
			{
				cout<<"超过了三分之一或者小于五分之一"<<endl;
				//弹窗提示错误
				return 0;
			}else
			{
				//封孔长度赋值
				*paramArray[2]=changeData;
				if (*paramArray[0]+leavelen >(2*oldLength)/3   )//判断装药加剩余长度大于三分之二
				{
					cout<<"装药长度大于三分之二"<<endl;
					//再判断如果加到水炮泥加剩余长度是否大于长度的1/3
					if (*paramArray[1] +leavelen >(1*oldLength)/3)
					{
						//多余的加到装药长度和封孔长度
						*paramArray[0] = (2*oldLength)/3;//装药长度
						*paramArray[2] = oldLength-*paramArray[0]-*paramArray[1];//封孔长度重新赋值不按照输入的值来
						return 1;

					}else{
						//水炮泥加剩余长度小于长度的1/3
						*paramArray[1] = *paramArray[1] +leavelen;//加到水炮泥长度上
						return 1;
					}

				}else if(*paramArray[0]+leavelen <0){//判断装药加剩余长度小于0，直接减小水炮泥的长度
					cout<<"装药长度小于0"<<endl;
					//装药长度不变，水炮泥长度等于剩余长度
					*paramArray[1] = oldLength -*paramArray[0]-*paramArray[2];
					return 1;

				}	
				else{ //判断装药加剩余长度小于三分之二并且大于0
					//加到装药长度上
					*paramArray[0] = *paramArray[0] +leavelen;
					//水炮泥长度等于剩余长度
					*paramArray[1] = oldLength -*paramArray[0]-*paramArray[2];
					return 1;
				}
			}
		}
		//kk 水炮泥长度的函数判断
		int CShotHoleLayer::getShuipaoniList(std::vector<double*> paramArray,double changeData,double oldLength)
		{
			double leavelen = *paramArray[1] - changeData;

			if ( (1*oldLength)/3 <changeData ||changeData<0)
			{
				cout<<"超过了三分之一或者小于0"<<endl;
				return 0;
			}else
			{
				if (*paramArray[0]+leavelen >(2*oldLength)/3 )//判断装药加剩余长度大于三分之二
				{
					cout<<"装药长度大于三分之二"<<endl;
					//封孔加剩余长度不可能大于长度的1/3,也不可能小于长度的1/5了
					//多余的加到装药长度和封孔长度
					double a = (2*oldLength)/3 - *paramArray[0];//三分之二总长度减去原始装药长度后差
					*paramArray[0] = (2*oldLength)/3;//装药长度等于总长度的2/3

					if (*paramArray[2]+a >(1*oldLength)/3)
					{
						*paramArray[2] = (1*oldLength)/3;//直接装药长度等于三分之二，封孔长度等于三分之一
						*paramArray[1] = 0;//水炮泥此时就设置为0
						return 1;
					}

				}else if(*paramArray[0]+leavelen <0){//判断装药加剩余长度小于0，肯定是加了一个负值(水炮泥长度增加了)
					cout<<"装药长度小于0"<<endl;
					if (*paramArray[2]+leavelen <(1*oldLength)/5 )
					{
						//那么就不修改原始的各个参数的值，直接return
						return 1;
					}
					else{
						*paramArray[2] = *paramArray[2] +leavelen;
						*paramArray[1] = oldLength - *paramArray[2] -*paramArray[0];
						return 1;
					}
				}	
				else{ //判断装药加剩余长度小于三分之二并且大于0

					//直接加到装药长度上,封孔长度不变
					*paramArray[0] = *paramArray[0] +leavelen;
					double b =oldLength - *paramArray[0] -*paramArray[1];//新的封孔长度
					//如果新的封孔长度大于三分之一，不可能小于0
					if (b >(1*oldLength)/3 )
					{
						*paramArray[2] = (1*oldLength)/3;
						*paramArray[1] = oldLength - *paramArray[2] -*paramArray[0];
						return 1;

					}else{//当小于0条件和满足小于1/3和大于0条件时，直接赋值给水炮泥
						*paramArray[1] = oldLength - *paramArray[2] -*paramArray[0];
						return 1;
					}
				}
			}
		}


	}
}
