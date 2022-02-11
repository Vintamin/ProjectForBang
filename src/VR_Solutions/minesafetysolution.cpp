#include "vrmine\vr_solutions\minesafetysolution.h"
#include "vrmine\vr_geometry\geometry\line.h"
#include "vrmine\vr_geometry\geometry\point.h"
#include "vrmine\vr_spatialobject\base\geoline.h"
#include "vrmine\vr_spatialobject\base\geopoint.h"
#include "vrmine\vr_spatialobject\mine\drillobject.h"
#include "vrmine\vr_geometry\geometry\drillhole.h"
#include "vrmine\vr_spatialobject\geoproperty\drillproperty.h"
#include "vrmine\vr_spatialanalyse\spatialanalyse\spatialmeasuretool.h"
#include "vrmine\vr_core\event.h"
#include "vrmine\vr_style\style\pointstyle.h"
#include "vrmine\vr_spatialinterface\event\eventobject.h"
#include "vrmine\vr_core\geodatatype.h"
#include "vrmine\vr_spatiallayer\drilllayer.h"
#include "vrmine\vr_core\tinyxml\tinyxml.h"
#include "vrmine\vr_spatialobject\mine\drillobject.h"

#include <string>
#include <vector>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>


using namespace VirtualMine::SpatialRender;
using namespace VirtualMine::BaseRender;
using namespace VirtualMine::Base;
using namespace VirtualMine::Geometry;
using namespace VirtualMine::GeoProperty;
using namespace VirtualMine::SpatialAnalyse;
using namespace VirtualMine::Core;
using namespace VirtualMine::Style;
using namespace VirtualMine::SpatialLayer;
using namespace VirtualMine::SpatialInterface;
using namespace VirtualMine::Mine;

namespace VirtualMine
{
	namespace Solution
	{
		class CSelectedTool : public CSpatialMeasureTool
		{
		public:
			CSelectedTool(VirtualMine::Scene::CGeoSpatialControl* ref_pSceneControl)
				:CSpatialMeasureTool(ref_pSceneControl),ref_mpOperator(NULL)
			{

			}
			virtual ~CSelectedTool()
			{

			}
			virtual void mouseReleaseEvent(const int& x ,const int& y , const int& button)
			{
				if (!this->mIsMouseDrag 
					&& button == 1
					&& this->ref_mpOperator->mCanSelectAccident)
				{
					Ogre::Vector3 intersectPoint(Ogre::Vector3::ZERO);
					if (this->ref_mpSceneControl->getGeoSceneManager()->getRayIntersectedPoint(x,y,intersectPoint))
					{
						//intersectPoint.y += 1;
						std::cout << "安全方案" << std::endl;
						std::cout << intersectPoint.x << "*" << intersectPoint.y << "*" << intersectPoint.z << std::endl;
						this->ref_mpOperator->setAccidentPoint(intersectPoint);
						this->ref_mpOperator->flushSolutionToScene();
					}
				}
				CSpatialMeasureTool::mouseReleaseEvent(x,y,button);
			}

			virtual void mousePressEvent(const int& x ,const int& y , const int& button)
			{
				CSpatialMeasureTool::mousePressEvent(x,y,button);
			}

			virtual bool handleEvent(VirtualMine::Core::CEvent* evt)
			{
				return CSpatialMeasureTool::handleEvent(evt);
				//if (NULL == ref_mpOperator)
				//{
				//	return false;
				//}
				//CEvent::Type type = evt->type();
				//switch(type)
				//{
				//case CEvent::MouseButtonRelease:
				//	{
				//		CMouseEvent* pMouseEvent = dynamic_cast<CMouseEvent*>(evt);
				//		this->mouseReleaseEvent(pMouseEvent->getX(),pMouseEvent->getY(),pMouseEvent->getButton());
				//		evt->accept();
				//		break;
				//	}
				//case CEvent::MouseButtonPress:
				//	{
				//		/*CMouseEvent* pMouseEvent = dynamic_cast<CMouseEvent*>(evt);
				//		this->mousePressEvent(pMouseEvent->getX(),pMouseEvent->getY(),pMouseEvent->getButton());*/
				//		break;
				//	}
				//default:
				//	break;
				//}
				//return evt->isAccepted();
			}

		public:
			CMineSafetySolution* ref_mpOperator;
		};

		CDrillingListener::CDrillingListener(CMineSafetySolution* ref_pSolution)
			:ref_mpSolution(ref_pSolution)
		{

		}

		CDrillingListener::~CDrillingListener()
		{

		}

		bool CDrillingListener::frameStarted(const Ogre::FrameEvent& evt)
		{
			if (this->ref_mpSolution)
				return this->ref_mpSolution->frameStarted(evt);
			return true;
		}

		CMineSolution::CMineSolution(const std::string& name)
			:mName(name),ref_mpControl(NULL)
		{

		}

		CMineSolution::~CMineSolution()
		{

		}

		void CMineSolution::setName(const std::string& name)
		{
			this->mName = name;
		}

		std::string CMineSolution::getName()
		{
			return this->mName;
		}

		VirtualMine::Scene::CGeoSpatialControl* CMineSolution::getGeoSpatialControl()
		{
			return this->ref_mpControl;
		}

		void CMineSolution::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pControl)
		{
			this->ref_mpControl = ref_pControl;
		}


		void CMineSolution::fromFile(const std::string& file)
		{

		}

		void CMineSolution::toFile(const std::string& filePath)
		{

		}

		CMineSafetySolution::CMineSafetySolution(const std::string& name)
			:CMineSolution(name),mAccidentPoint(Ogre::Vector3::ZERO),
			mOptimalPoint(Ogre::Vector3::ZERO),mpDrillRenderObject(NULL),
			mpNearerRenderPoints(NULL),mpNearerRenderLines(NULL),
			mIsDrillingState(false),mDrillingProgress(0),
			mTiltRotation(Ogre::Quaternion::ZERO),
			mDrillLength(0),mpSelectedTool(NULL),
			ref_mpGeoScene(NULL),ref_mpDrillLayer(NULL),mNearerPointCount(1),
			mVerticalSurfacePoint(Ogre::Vector3::ZERO),mpDrillListener(NULL),
			mCanSelectAccident(false),mAnalysisRadius(200),mpAnalysisLines(NULL),
			mIsAnalysisState(false),mSamplingDensity(50),mAnalysisProgress(0),
			mSamplingPointCount(20),mpDynamicCircleLine(NULL),mAnalysisOffsetY(2),
			mMaxDrillAngle(10)
		{

		}

		CMineSafetySolution::~CMineSafetySolution()
		{

		}

		void CMineSafetySolution::selectAccidentPoint()
		{
			this->mCanSelectAccident = true;
		}

		void CMineSafetySolution::setAccidentPoint(const Ogre::Vector3& accidentPoint)
		{
			this->mAccidentPoint = accidentPoint;
			Ogre::Vector3 tempPoint = IScene::transformCoor(accidentPoint);
			std::string info("救援点坐标：");
			info += " x:";
			info += Ogre::StringConverter::toString(tempPoint.z,14);
			info += " y:";
			info += Ogre::StringConverter::toString(tempPoint.x,14);
			info += " 高程:";
			info += Ogre::StringConverter::toString(tempPoint.y,10);
			VirtualMine::SpatialInterface::CExportInfoEvent evt;
			evt.setInfo(info);
			CEventDispatcher::setEvent(&evt);
		}

		void CMineSafetySolution::setAnalysisRadius(const Ogre::Real& analysisRadius)
		{
			this->mAnalysisRadius = analysisRadius;
		}

		Ogre::Real CMineSafetySolution::getAnalysisRadius()
		{
			return this->mAnalysisRadius;
		}

		void CMineSafetySolution::analyseOptimalPoint()
		{
			if (this->mVerticalSurfacePoint != Ogre::Vector3::ZERO)
			{
				this->mIsAnalysisState = true;
			}
		}

		Ogre::Vector3& CMineSafetySolution::getAccidentPoint()
		{
			return this->mAccidentPoint;
		}

		void CMineSafetySolution::setOptimalPoint(const Ogre::Vector3& optimalPoint)
		{
			this->mOptimalPoint = optimalPoint;
			this->mCanSelectAccident =false;
		}

		Ogre::Vector3 CMineSafetySolution::getOptimalPoint()
		{
			return this->mOptimalPoint;
		}

		void CMineSafetySolution::addSurfaceNearerPoint(const Ogre::Vector3& nearerPoint)
		{
			//this->mSurfaceNearerPoints.push_back(nearerPoint);	
		}

		Ogre::Vector3 CMineSafetySolution::getSurfaceNearerPoint(const int& index)
		{
			//return this->mSurfaceNearerPoints.at(index);
			return Ogre::Vector3::ZERO;
		}

		int CMineSafetySolution::getSurfaceNearerPointCount()
		{
			return this->mSurfaceNearerDrills.size();
		}

		void CMineSafetySolution::flushSolutionToScene()
		{
			this->renderPoints();
			this->renderNearerLines();
		}

		Ogre::Real CMineSafetySolution::getMaxDrillAngle()
		{
			return this->mMaxDrillAngle;
		}

		void CMineSafetySolution::setMaxDrillAngle(const Ogre::Real& maxDrillAngle)
		{
			this->mMaxDrillAngle = maxDrillAngle;
		}

		void CMineSafetySolution::innerAnalyseOptimalPoint(std::vector<CStatistionInfo>& slopeStatistic)
		{
			if (!slopeStatistic.empty())
			{
				Ogre::Vector3 nearestPoint = Ogre::Vector3::ZERO;
				Ogre::Real curDis(DBL_MAX);
				Ogre::Real standardAngle(this->mMaxDrillAngle);
				std::vector<CStatistionInfo>::iterator bItr = slopeStatistic.begin();
				std::vector<CStatistionInfo>::iterator eItr = slopeStatistic.end();
				while (bItr != eItr)
				{
					if (bItr->Slope < standardAngle)
					{
						Ogre::Real dis = bItr->Point.distance(this->mAccidentPoint);
						if (dis < curDis)
						{
							curDis = dis;
							nearestPoint = bItr->Point;
						}
					}
					++bItr;
				}
				if (abs(curDis - DBL_MAX) > 10)
				{
					this->setOptimalPoint(nearestPoint);
					this->renderPoints();
				}
			}
		}
		
		void CMineSafetySolution::renderNearerLines()
		{
			if (this->mpNearerRenderLines)
			{
				this->mpNearerRenderLines->deRender();
				delete this->mpNearerRenderLines;
				this->mpNearerRenderLines = NULL;
			}
			if (this->mAccidentPoint != Ogre::Vector3::ZERO
				&& this->mVerticalSurfacePoint != Ogre::Vector3::ZERO)
			{
				//构建多线
				if (this->mpNearerRenderLines == NULL)
				{
					this->mpNearerRenderLines = new CMultiLine();
					this->mpNearerRenderLines->setGeoSceneManager(this->ref_mpControl->getGeoSceneManager());
					this->mpNearerRenderLines->setNode(this->ref_mpControl->getGeoSceneManager()->getRootSceneNode()->createChildSceneNode());
				}
				/*GeoObjectMap::iterator bItr = this->mSurfaceNearerDrills.begin();
				GeoObjectMap::iterator eItr = this->mSurfaceNearerDrills.end();
				while (bItr != eItr)
				{
					CPoint* pPoint = dynamic_cast<CPoint*>(bItr->second->getGeometry());
					Ogre::Vector3 surfacePoint(pPoint->getX(),pPoint->getY(),pPoint->getZ());
					CGeoLine* pGeoLine = this->createGeoLine(surfacePoint,mAccidentPoint,Ogre::ColourValue(1,1,0,1));
					if (this->mOptimalPoint == Ogre::Vector3::ZERO)
					{
						this->setOptimalPoint(surfacePoint);
					}
					this->mpNearerRenderLines->addGeoObject(pGeoLine);
					++bItr;
				}*/
				//构建垂直线
				CGeoLine* pGeoVerticalLine = this->createGeoLine(this->mAccidentPoint,this->mVerticalSurfacePoint,Ogre::ColourValue(1,0,0,1));
				this->mpNearerRenderLines->addGeoObject(pGeoVerticalLine);
				this->mpNearerRenderLines->build();
				this->mpNearerRenderLines->render();
			}
			else
			{
				//释放多线
			}
		}

		VirtualMine::Base::CGeoLine* CMineSafetySolution::createGeoLine(CoorVector& points,
			const Ogre::Vector3 terminalPoint,
			const Ogre::ColourValue& color)
		{
			CGeoLine* pGeoLine = new CGeoLine();
			CLine* pGeometry = dynamic_cast<CLine*>(pGeoLine->getGeometry());
			pGeoLine->getStyle()->setColor(color);
			for (size_t i = 0 ; i < points.size(); ++i)
			{
				Ogre::Vector3& point = points.at(i);
				pGeometry->addPoint(point.x,point.y,point.z);
			}
			pGeometry->addPoint(terminalPoint.x,terminalPoint.y,terminalPoint.z);
			return pGeoLine;
		}

		CGeoLine* CMineSafetySolution::createGeoLine(const Ogre::Vector3& p1,
			const Ogre::Vector3& p2,
			const Ogre::ColourValue& color)
		{
			CGeoLine* pGeoLine = new CGeoLine();
			CLine* pGeometry = dynamic_cast<CLine*>(pGeoLine->getGeometry());
			pGeoLine->getStyle()->setColor(color);
			pGeometry->addPoint(p1.x,p1.y,p1.z);
			pGeometry->addPoint(p2.x,p2.y,p2.z);
			return pGeoLine;
		}
		
		void CMineSafetySolution::renderPoints()
		{
			if (this->mpNearerRenderPoints)
			{
				this->mpNearerRenderPoints->deRender();
				delete this->mpNearerRenderPoints;
				this->mpNearerRenderPoints = NULL;
			}
			CoorVector points;
			if (this->mAccidentPoint != Ogre::Vector3::ZERO)
			{
				points.push_back(this->mAccidentPoint);
				if (this->mVerticalSurfacePoint != Ogre::Vector3::ZERO)
				{
					points.push_back(this->mVerticalSurfacePoint);
					if (this->mOptimalPoint != Ogre::Vector3::ZERO)
					{
						points.push_back(this->mOptimalPoint);
					}
				}
#if 0
				GeoObjectMap::iterator bItr = this->mSurfaceNearerDrills.begin();
				GeoObjectMap::iterator eItr = this->mSurfaceNearerDrills.end();
				while (bItr != eItr)
				{
					CPoint* pPoint = dynamic_cast<CPoint*>(bItr->second->getGeometry());
					points.push_back(Ogre::Vector3(pPoint->getX(),pPoint->getY(),pPoint->getZ()));
					++bItr;
				}
#endif
			}
			if (points.size() > 0)
			{
				for (size_t i = 0 ; i < points.size() ; ++i)
				{
					if (this->mpNearerRenderPoints == NULL)
					{
						this->mpNearerRenderPoints = new CMultiPoint();
						this->mpNearerRenderPoints->setGeoSceneManager(this->ref_mpControl->getGeoSceneManager());
						this->mpNearerRenderPoints->setNode(this->ref_mpControl->getGeoSceneManager()->getRootSceneNode()->createChildSceneNode());
					}
					CGeoPoint* pGeoPoint = new CGeoPoint();
					CPointStyle* pStyle = dynamic_cast<CPointStyle*>(pGeoPoint->getStyle());
					pStyle->setPointRenderMode(CPointStyle::PRM_ICON);
					pStyle->setSize(5);
					CPoint* pGeometry = dynamic_cast<CPoint*>(pGeoPoint->getGeometry());
					Ogre::Vector3 point = points.at(i);
					pGeometry->setCoor(point.x,point.y,point.z);
					this->mpNearerRenderPoints->addGeoObject(pGeoPoint);
				}
				if (this->mpNearerRenderPoints)
				{
					this->mpNearerRenderPoints->build();
					this->mpNearerRenderPoints->render();
				}
				else
				{
					//释放点，线
				}
			}
		}
		
		void CMineSafetySolution::drillingToAccident()
		{
			if (this->mpDrillRenderObject)
			{
				delete this->mpDrillRenderObject;
				this->mpDrillRenderObject = NULL;
			}
			if (this->mOptimalPoint != Ogre::Vector3::ZERO)
			{
				Ogre::Real drillLength = this->mOptimalPoint.distance(this->mAccidentPoint);
				if (drillLength > 1)
				{
					if (this->mpDrillRenderObject == NULL)
					{
						this->mpDrillRenderObject = new VirtualMine::SpatialRender::CDrillRenderableObject();
						this->mpDrillRenderObject->setGeoSceneManager(this->ref_mpControl->getGeoSceneManager());
						this->mpDrillRenderObject->setNode(this->ref_mpControl->getGeoSceneManager()->getRootSceneNode()->createChildSceneNode());
					}
					VirtualMine::Mine::CDrillObject* drillObject = new VirtualMine::Mine::CDrillObject();
					VirtualMine::Geometry::CDrillHoleGeometry* drillGeometry = new VirtualMine::Geometry::CDrillHoleGeometry();
					drillGeometry->setX(0);
					drillGeometry->setY(0);
					drillGeometry->setZ(0);
					drillObject->setGeometry(drillGeometry,true);

					VirtualMine::GeoProperty::CDrillProperty* drillProperty = new VirtualMine::GeoProperty::CDrillProperty();
					drillProperty->setName("钻探演示");
					drillProperty->setRadius(5.0f);
					CStratum* stratum = new CStratum();
					stratum->setDepth(1);
					stratum->setDescription("粘土");

					drillProperty->addStratum(stratum);

					drillObject->setGeoProperty(drillProperty,true);

					this->mpDrillRenderObject->addGeoObject(drillObject);

					this->mpDrillRenderObject->build();
					this->mpDrillRenderObject->render();
					std::string matName("dynamicDrillMat");
					Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingletonPtr()->getByName(matName,VirtualMine::Core::VR_MINE_DEFAULT_RESOURCE_GROUP);
					if (!mat.isNull())
					{
						mat->load();
						this->mpDrillRenderObject->setMaterialName(matName);
					}
					//计算针孔数据
					this->mDrillingProgress = 0;
					this->mDrillLength = drillLength;
					Ogre::Vector3 oriDir = Ogre::Vector3::NEGATIVE_UNIT_Y;
					Ogre::Vector3 realDir = this->mAccidentPoint - this->mOptimalPoint;
					realDir.normalise();

					this->mTiltRotation = oriDir.getRotationTo(realDir);
					this->mpDrillRenderObject->getNode()->setOrientation(this->mTiltRotation);
					this->mpDrillRenderObject->getNode()->setPosition(this->mOptimalPoint);
					this->mIsDrillingState = true;
				}
			}
		}
		
		void CMineSafetySolution::stopDrilling()
		{
			this->mDrillingProgress = this->mDrillLength;
			this->mIsDrillingState = false;
		}

		void CMineSafetySolution::drillingAgain()
		{
			this->mDrillingProgress = 0;
			this->mIsDrillingState = true;
		}

		void CMineSafetySolution::continueDrilling()
		{
			this->mIsDrillingState = true;
		}

		void CMineSafetySolution::fromFile(const std::string& file)
		{

			TiXmlDocument doc; 
			bool result = doc.LoadFile(file.c_str(),TIXML_DEFAULT_ENCODING);
			if (!result)
			{
				//return NULL;
			}
			
			TiXmlElement* sceneElement = doc.RootElement();  
			TiXmlAttribute* attributeOfScene = sceneElement->FirstAttribute(); 
			for (; attributeOfScene != NULL ; attributeOfScene = attributeOfScene->Next())
			{
				std::string name = attributeOfScene->Name();
				if (name == "名称")
				{			
					this->setName(attributeOfScene->Value());
				}
            }

			TiXmlElement* layersElement = sceneElement->FirstChildElement("方案参数");
			TiXmlElement* layerElement1 = layersElement->FirstChildElement("井下救援点");
				TiXmlAttribute* attributeOfScene1 = layerElement1->FirstAttribute();
				 std::string name1 = attributeOfScene1->Name();
				 if (name1 == "坐标")
				 {
					 std::string cordinate1 = attributeOfScene1->Value();
					 
				/*	 int firstSpace =  cordinate1.find_first_of(" ");			
					 std::string posX = cordinate1.substr(0,firstSpace);
					
					 int secondSpace = cordinate1.find_last_of(" ");
					 
					 std::string posY = cordinate1.substr(firstSpace+1);

					 std::string posZ = cordinate1.substr(secondSpace+1);
*/
					
					 std::vector<std::string> vStr;
					 boost::split( vStr, cordinate1, boost::is_any_of(" "), boost::token_compress_on );
					 std::string posX1 = vStr.at(0);
					 std::string posY1 = vStr.at(1);
					 std::string posZ1 = vStr.at(2);

					Ogre::Real x =  Ogre::StringConverter::parseReal(posX1);
					Ogre::Real y =  Ogre::StringConverter::parseReal(posY1);
					Ogre::Real z =  Ogre::StringConverter::parseReal(posZ1);
					Ogre::Vector3 DrillingHelpPos(x,y,z);
					this->mAccidentPoint = DrillingHelpPos;

				/*	this->mAccidentPoint = IScene::transformCoor(mAccidentPoint);
					DrillingHelpPos = this->mAccidentPoint - IScene::ReferenceCenter;
				    DrillingHelpPos.z *= IScene::CoefficientOfCoordinateTransform;
				*/	
					this->mAccidentPoint.x = this->mAccidentPoint.x - IScene::ReferenceCenter.x;
					this->mAccidentPoint.y = this->mAccidentPoint.y - IScene::ReferenceCenter.y;
					this->mAccidentPoint.z = this->mAccidentPoint.z - IScene::ReferenceCenter.z;
					this->mAccidentPoint.z *=  IScene::CoefficientOfCoordinateTransform;
					
					//this->setAccidentPoint(DrillingHelpPos);

				 }


			TiXmlElement* layerElement2 = layersElement->FirstChildElement("垂直地表点");
			    TiXmlAttribute* attributeOfScene2 = layerElement2->FirstAttribute();
			    std::string name2 = attributeOfScene2->Name();
			    if (name2 == "坐标")
			    {
			    	std::string cordinate2 = attributeOfScene2->Value();

					std::vector<std::string> vStr;
					boost::split( vStr, cordinate2, boost::is_any_of(" "), boost::token_compress_on );
					std::string posX1 = vStr.at(0);
					std::string posY1 = vStr.at(1);
					std::string posZ1 = vStr.at(2);

					Ogre::Real x =  Ogre::StringConverter::parseReal(posX1);
					Ogre::Real y =  Ogre::StringConverter::parseReal(posY1);
					Ogre::Real z =  Ogre::StringConverter::parseReal(posZ1);
					Ogre::Vector3 VerticlePos(x,y,z);
				
					//垂直地标点没有设置
					this->mVerticalSurfacePoint = VerticlePos;


					this->mVerticalSurfacePoint.x = this->mVerticalSurfacePoint.x - IScene::ReferenceCenter.x;
					this->mVerticalSurfacePoint.y = this->mVerticalSurfacePoint.y - IScene::ReferenceCenter.y;
					this->mVerticalSurfacePoint.z = this->mVerticalSurfacePoint.z - IScene::ReferenceCenter.z;
					this->mVerticalSurfacePoint.z *=  IScene::CoefficientOfCoordinateTransform;

					//this->mVerticalSurfacePoint = IScene::transformCoor(mVerticalSurfacePoint);
					//this->mVerticalSurfacePoint = this->mVerticalSurfacePoint  - IScene::ReferenceCenter;
			    }



			TiXmlElement* layerElement3 = layersElement->FirstChildElement("地面最优钻探点");
			     TiXmlAttribute* attributeOfScene3 = layerElement3->FirstAttribute();
			     std::string name3 = attributeOfScene3->Name();
			     if (name3 == "坐标")
		      	 {
				   std::string cordinate3 = attributeOfScene3->Value();


				   std::vector<std::string> vStr;
				   boost::split( vStr, cordinate3, boost::is_any_of(" "), boost::token_compress_on );
				   std::string posX1 = vStr.at(0);
				   std::string posY1 = vStr.at(1);
				   std::string posZ1 = vStr.at(2);

				   Ogre::Real x =  Ogre::StringConverter::parseReal(posX1);
				   Ogre::Real y =  Ogre::StringConverter::parseReal(posZ1);
				   Ogre::Real z =  Ogre::StringConverter::parseReal(posY1);
				   Ogre::Vector3 zuiYouPos(x,y,z);
				   this->mOptimalPoint = zuiYouPos;

				   this->mOptimalPoint.x = this->mOptimalPoint.x - IScene::ReferenceCenter.x;
				   this->mOptimalPoint.y = this->mOptimalPoint.y - IScene::ReferenceCenter.y;
				   this->mOptimalPoint.z = this->mOptimalPoint.z - IScene::ReferenceCenter.z;
				   this->mOptimalPoint.z *=  IScene::CoefficientOfCoordinateTransform;

				   //this->setOptimalPoint(zuiYouPos);
			     }



			TiXmlElement* layerElement4 = layersElement->FirstChildElement("钻探参数");

			     TiXmlAttribute* attributeOfScene4 = layerElement4->FirstAttribute();

				 CStatistionInfo statistionInfo;
				 for (;attributeOfScene4 != NULL;attributeOfScene4 = attributeOfScene4->Next())
				 {
					 std::string name4 = attributeOfScene4->Name();

					 if (name4 == "孔斜")
					 {
						 std::string kongxie = attributeOfScene4->Value();						 
						 //statistionInfo.Slope = Ogre::StringConverter::parseReal(kongxie);
					 }
					 else if (name4 == "孔深")
					 {
						 std::string kongshen = attributeOfScene4->Value();
						//statistionInfo.Distance = Ogre::StringConverter::parseReal(kongshen);
					 }
					 else if (name4 == "方位角")
					 {
						 std::string fangweijiao = attributeOfScene4->Value();
						//statistionInfo.Point = Ogre::StringConverter::parseReal()
					 }
				 }
				 


				TiXmlElement* layerElement4_1 = layerElement4->FirstChildElement("岩性特征");

				     TiXmlAttribute* attributeOfScene4_1 = layerElement4_1->FirstAttribute();
					 std::string name4_1 = attributeOfScene4_1->Name();
					 if (name4_1 == "半径")
					 {
						 std::string radius = attributeOfScene4_1->Value();
						 Ogre::Real drillingR = Ogre::StringConverter::parseReal(radius);
						// this->setAnalysisRadius(drillingR);

						 if (!this->mSurfaceNearerDrills.empty())
						 {						
							 CDrillObject* pDrillObject = dynamic_cast<CDrillObject*>(this->mSurfaceNearerDrills.begin()->second);
							 if (pDrillObject)
							 {
								 CDrillProperty* pProperty = dynamic_cast<CDrillProperty*>(pDrillObject->getGeoProperty());
							     pProperty->setRadius(drillingR);							
							 }							
						 }					 				
					 }

				  
                TiXmlElement* layerElement4_1_1 = layerElement4_1->FirstChildElement("岩性描述");
				 
				for(;layerElement4_1_1 != NULL; layerElement4_1_1 = layerElement4_1_1->NextSiblingElement())
				{
					TiXmlAttribute* attributeOflayerElement4_1_1 = layerElement4_1_1->FirstAttribute(); 

					CStratum *strum = new CStratum();
					for (; attributeOflayerElement4_1_1 != NULL;  attributeOflayerElement4_1_1 = attributeOflayerElement4_1_1->Next())
					{
						std::string  yangxingName  =  attributeOflayerElement4_1_1->Name();

						if (  yangxingName == "岩性0"||yangxingName == "岩性1" ||yangxingName == "岩性2" ||yangxingName == "岩性3" ||yangxingName == "岩性4"
							||yangxingName == "岩性5" ||yangxingName == "岩性6" ||yangxingName == "岩性7" ||yangxingName == "岩性8" ||yangxingName == "岩性9" 
							||yangxingName == "岩性10" ||yangxingName == "岩性11" ||yangxingName == "岩性12" ||yangxingName == "岩性13" ||yangxingName == "岩性14" 
							||yangxingName == "岩性15" ||yangxingName == "岩性16" ||yangxingName == "岩性17" ||yangxingName == "岩性18" ||yangxingName == "岩性19" 
							||yangxingName == "岩性20" ||yangxingName == "岩性21" ||yangxingName == "岩性22" ||yangxingName == "岩性23" ||yangxingName == "岩性24" 
							||yangxingName == "岩性25" ||yangxingName == "岩性26" ||yangxingName == "岩性27" ||yangxingName == "岩性28" ||yangxingName == "岩性29" 
							||yangxingName == "岩性30" ||yangxingName == "岩性31" ||yangxingName == "岩性32" ||yangxingName == "岩性33" ||yangxingName == "岩性34" 
							||yangxingName == "岩性35" ||yangxingName == "岩性36" ||yangxingName == "岩性37" ||yangxingName == "岩性38" ||yangxingName == "岩性39" 
							||yangxingName == "岩性40" ||yangxingName == "岩性41" ||yangxingName == "岩性42" ||yangxingName == "岩性43" ||yangxingName == "岩性44" 
							||yangxingName == "岩性45" ||yangxingName == "岩性46" ||yangxingName == "岩性47" ||yangxingName == "岩性48" ||yangxingName == "岩性49" )
						{
							std::string yanxing =  attributeOflayerElement4_1_1->Value();
							strum->setDescription(yanxing);
						}
						else if(yangxingName == "深度")
						{
							std::string shengdu = attributeOflayerElement4_1_1->Value();
							strum->setDepth(Ogre::StringConverter::parseReal(shengdu));
						}
					}



					if (!this->mSurfaceNearerDrills.empty())
					{
						CDrillObject* pDrillObject = dynamic_cast<CDrillObject*>(this->mSurfaceNearerDrills.begin()->second);
						if (pDrillObject)
						{
							CDrillProperty* pProperty = dynamic_cast<CDrillProperty*>(pDrillObject->getGeoProperty());																 
							pProperty->addStratum(strum);						
						}
					}


				  }


		}


		void CMineSafetySolution::beginEditingSolution()
		{
			if (this->mpSelectedTool == NULL)
			{
				this->mpSelectedTool = new CSelectedTool(this->ref_mpControl);
				this->mpSelectedTool->ref_mpOperator = this;
			}
			this->ref_mpControl->setCurrentTool(NULL);
			this->ref_mpControl->setCurrentTool(this->mpSelectedTool);
			
			this->reset();

			if (NULL == mpDrillListener)
			{
				this->mpDrillListener = new CDrillingListener(this);
				Ogre::Root::getSingletonPtr()->addFrameListener(mpDrillListener);
			}
		}

		void CMineSafetySolution::setVerticalSurfacePoint(const Ogre::Vector3& accidentPoint)
		{
			this->mVerticalSurfacePoint = accidentPoint;
		}

		 Ogre::Vector3 CMineSafetySolution::getVerticalSurfacePoint()
		 {
			return this->mVerticalSurfacePoint;
		 }


		void CMineSafetySolution::analyseSurfaceNearerPoints()
		{
			if (this->ref_mpControl && this->mSurfaceNearerDrills.empty())
			{
				this->ref_mpGeoScene = dynamic_cast<VirtualMine::Scene::CGeoSpatialScene*>(this->ref_mpControl->getScene());
				if (this->ref_mpDrillLayer == NULL)
				{
					VirtualMine::SpatialInterface::LayerMap& layerMap = this->ref_mpGeoScene->getLayerMap();
					VirtualMine::SpatialInterface::LayerMap::iterator bItr = layerMap.begin();
					VirtualMine::SpatialInterface::LayerMap::iterator eItr = layerMap.end();
					while (bItr != eItr)
					{
						if (bItr->second->getType() == GeoDataType::GDT_DRILL)
						{
							this->ref_mpDrillLayer = dynamic_cast<CDrillLayer*>(bItr->second);
							break;
						}
						++bItr;
					}
				}
				if (this->ref_mpDrillLayer)
				{
					VirtualMine::SpatialInterface::GeoObjectMap curNearerDrillObject ;
					this->mSurfaceNearerDrills.clear();
					this->mVerticalSurfacePoint = mAccidentPoint; 
					/////dem的getHeight 里的参数z不需要乘以-1；
					this->mVerticalSurfacePoint.y = this->ref_mpControl->getHeight(this->mVerticalSurfacePoint.x,this->mVerticalSurfacePoint.z*(-1));
					this->mCanSelectAccident = false;
					this->ref_mpDrillLayer->getNearerGeoObjects(this->mVerticalSurfacePoint,mNearerPointCount,this->mSurfaceNearerDrills);
					this->flushSolutionToScene();
				}
				else
				{
					std::string info("当前没有钻孔图层！");
					VirtualMine::SpatialInterface::CExportInfoEvent evt;
					evt.setInfo(info);
					CEventDispatcher::setEvent(&evt);
				}
			}
		}
		
		void CMineSafetySolution::toFile(const std::string& file)
		{
			TiXmlDocument doc;    
			TiXmlDeclaration* decl = new TiXmlDeclaration("1.0","GB2312", "yes");  

			TiXmlElement* rootNode = new TiXmlElement("救援方案");
			rootNode->SetAttribute("名称",this->mName.c_str());
			{
				TiXmlElement* paramsNode = new TiXmlElement("方案参数");
				{
					TiXmlElement* subNode = new TiXmlElement("井下救援点");
					Ogre::Vector3 realRescuePoint = IScene::transformCoor(mAccidentPoint);

					Ogre::Real accX = realRescuePoint.x;
					Ogre::Real accY = realRescuePoint.y;
					Ogre::Real accZ = realRescuePoint.z;

					std::string accXYZ;
					accXYZ += Ogre::StringConverter::toString(accZ,14) + " ";
					accXYZ += Ogre::StringConverter::toString(accX,14) + " ";
					accXYZ += Ogre::StringConverter::toString(accY) + " ";
					

					subNode->SetAttribute("坐标",accXYZ.c_str());
					paramsNode->LinkEndChild(subNode);



					subNode = new TiXmlElement("垂直地表点");
					Ogre::Vector3 realVerticalPoint = IScene::transformCoor(mVerticalSurfacePoint);

					Ogre::Real vecX = realVerticalPoint.x;
					Ogre::Real vecY = realVerticalPoint.y;
					Ogre::Real vecZ = realVerticalPoint.z;

					std::string vecXYZ;
					vecXYZ += Ogre::StringConverter::toString(vecZ,14) + " ";
					vecXYZ += Ogre::StringConverter::toString(vecX,14) + " ";
					vecXYZ += Ogre::StringConverter::toString(vecY) + " ";
					


					subNode->SetAttribute("坐标",vecXYZ.c_str());
					//subNode->SetAttribute("坐标",Ogre::StringConverter::toString(realVerticalPoint).c_str());
					paramsNode->LinkEndChild(subNode);

					subNode = new TiXmlElement("地面最优钻探点");
					Ogre::Vector3 realOptimalPoint = IScene::transformCoor(mOptimalPoint);

					Ogre::Real optX = realOptimalPoint.x;
					Ogre::Real optY = realOptimalPoint.y;
					Ogre::Real optZ = realOptimalPoint.z; 

					std::string optXYZ;
					optXYZ += Ogre::StringConverter::toString(optZ,14) + " ";
					optXYZ += Ogre::StringConverter::toString(optX,14) + " ";
					optXYZ += Ogre::StringConverter::toString(optY,14) + " ";
					


					subNode->SetAttribute("坐标", optXYZ.c_str());
					paramsNode->LinkEndChild(subNode);

					subNode = new TiXmlElement("钻探参数");
					//孔斜
					Ogre::Real dis = this->mOptimalPoint.distance(this->mAccidentPoint);
					Ogre::Real height = this->mOptimalPoint.y - this->mAccidentPoint.y;
					height = abs(height);
					float slope = asin(height / dis);
					slope = Ogre::Radian(slope).valueDegrees();
					subNode->SetAttribute("孔斜",Ogre::StringConverter::toString(90 - slope).c_str());
					//孔深
					subNode->SetAttribute("孔深",Ogre::StringConverter::toString(dis).c_str());
					//方位角
					Ogre::Vector3 curDir = this->mAccidentPoint - this->mOptimalPoint;
					curDir.y = 0 ;
					Ogre::Vector3 northDir(Ogre::Vector3::NEGATIVE_UNIT_Z);
					Ogre::Real fwAngle = curDir.angleBetween(northDir).valueDegrees();
					subNode->SetAttribute("方位角",Ogre::StringConverter::toString(fwAngle).c_str());
					//最近钻孔的岩性
					if (!this->mSurfaceNearerDrills.empty())
					{
						TiXmlElement* stratunNode = new TiXmlElement("岩性特征");
						CDrillObject* pDrillObject = dynamic_cast<CDrillObject*>(this->mSurfaceNearerDrills.begin()->second);
						if (pDrillObject)
						{
							CDrillProperty* pProperty = dynamic_cast<CDrillProperty*>(pDrillObject->getGeoProperty());
							//stratunNode->SetAttribute("age",Ogre::StringConverter::toString(pProperty->getRadius()).c_str());
							stratunNode->SetAttribute("半径",Ogre::StringConverter::toString(pProperty->getRadius()).c_str());
							for (int i = 0 ; i < pProperty->getStratumCount(); ++i)
							{
								TiXmlElement* stratunDescription = new TiXmlElement("岩性描述");
								std::string name = ("岩性" + Ogre::StringConverter::toString(i)).c_str();
								stratunDescription->SetAttribute(name.c_str(),pProperty->getStratum(i)->getDeccription().c_str());
								stratunDescription->SetAttribute("深度",Ogre::StringConverter::toString(pProperty->getStratum(i)->getDepth()).c_str());
								stratunNode->LinkEndChild(stratunDescription);
							}
						}
						subNode->LinkEndChild(stratunNode);
					}
					paramsNode->LinkEndChild(subNode);

				}


				rootNode->LinkEndChild(paramsNode);
			}
			doc.LinkEndChild(decl);
			doc.LinkEndChild(rootNode);     
			doc.SaveFile(file.c_str()); 
		}

		void CMineSafetySolution::endEditingSolution(const bool& needSave)
		{
			if (this->ref_mpControl && this->mpSelectedTool)
			{
				this->ref_mpControl->setCurrentTool(NULL);
				delete this->mpSelectedTool;
				this->mpSelectedTool = NULL;
			}

			if (mpDrillListener)
			{
				Ogre::Root::getSingletonPtr()->removeFrameListener(mpDrillListener);
				delete mpDrillListener;
				mpDrillListener = NULL;
			}
			this->reset();
			this->stopDrilling();
		}

		bool CMineSafetySolution::frameStarted(const Ogre::FrameEvent& evt)
		{
			if (this->mIsAnalysisState)
			{
				if (this->mAnalysisProgress <= this->mSamplingDensity)
				{
					Ogre::Real angle = (this->mAnalysisProgress / (float)this->mSamplingDensity) * 360;
					Ogre::Vector3 originDir = Ogre::Vector3::NEGATIVE_UNIT_Z;
					//
					Ogre::Quaternion q;
					q.FromAngleAxis(Ogre::Radian(Ogre::Degree(angle)),Ogre::Vector3::UNIT_Y);
					Ogre::Vector3 curDir = q * originDir;
					curDir.normalise();
					Ogre::Vector3 curPoint = this->mVerticalSurfacePoint + curDir * this->mAnalysisRadius;
					curPoint.y = this->ref_mpControl->getHeight(curPoint.x,curPoint.z*(-1));
					curPoint.y += this->mAnalysisOffsetY;
					this->mPreAnalysisPoint = curPoint;
					if (this->mpAnalysisLines == NULL)
					{
						this->mpAnalysisLines = new CMultiLine();
						this->mpAnalysisLines->setGeoSceneManager(this->ref_mpControl->getGeoSceneManager());
						this->mpAnalysisLines->setNode(this->ref_mpControl->getGeoSceneManager()->getRootSceneNode()->createChildSceneNode());
					}
					VirtualMine::Geometry::CLine* pDyanmicLine(NULL);
					if (this->mpDynamicCircleLine == NULL)
					{
						this->mpDynamicCircleLine = new VirtualMine::Base::CGeoLine();
						this->mpDynamicCircleLine->getStyle()->setColor(Ogre::ColourValue(0,0,1,1));
						this->mpAnalysisLines->addGeoObject(this->mpDynamicCircleLine);
						pDyanmicLine = dynamic_cast<VirtualMine::Geometry::CLine*>(this->mpDynamicCircleLine->getGeometry());
						pDyanmicLine->addPoint(this->mPreAnalysisPoint.x,this->mPreAnalysisPoint.y,this->mPreAnalysisPoint.z);
					}
					else
					{
						 pDyanmicLine = dynamic_cast<VirtualMine::Geometry::CLine*>(this->mpDynamicCircleLine->getGeometry());
					}
					pDyanmicLine->addPoint(this->mPreAnalysisPoint.x,this->mPreAnalysisPoint.y,this->mPreAnalysisPoint.z);
					//计算
					CoorVector curAnalysisPoints;
					this->computeStatistic(this->mVerticalSurfacePoint,curDir,
						this->mAnalysisRadius,curAnalysisPoints);
					//当前分析的进度线
					/*CGeoLine* pGeoLine = this->createGeoLine(curPoint,this->mVerticalSurfacePoint,Ogre::ColourValue(1,1,0,1));*/
					CGeoLine* pGeoLine = this->createGeoLine(curAnalysisPoints,curPoint,Ogre::ColourValue(1,1,0,1));
					this->mpAnalysisLines->addGeoObject(pGeoLine);
					this->mpAnalysisLines->build();
					//渲染
					this->mpAnalysisLines->render();
					this->mAnalysisProgress += 1;
				}
				else
				{
					this->innerAnalyseOptimalPoint(mSlopeStatistic);
					this->analyseSurfaceNearerPoints();
					this->mIsAnalysisState = false;
				}
			}
			else if(this->mIsDrillingState)
			{
				if (this->mDrillingProgress < this->mDrillLength)
				{
					this->mpDrillRenderObject->getNode()->setScale(1,this->mDrillingProgress,1);
					Ogre::Real standardTime = 0.003;
					Ogre::Real timeScale = evt.timeSinceLastFrame / standardTime;
					this->mDrillingProgress += 0.05 * timeScale;
				}
				else
				{
					//this->mIsDrillingState = false;
					this->drillingAgain();
				}
			}
			return true;
		}

		void CMineSafetySolution::computeStatistic(const Ogre::Vector3& originPoint,
			const Ogre::Vector3& dir,const Ogre::Real& radius,
			CoorVector& results)
		{
			if (this->mSamplingPointCount > 2)
			{
				for (int i = 0 ; i < this->mSamplingPointCount; ++i)
				{
					Ogre::Real dis = radius * (i / (double)(this->mSamplingPointCount));
					Ogre::Vector3 curPoint = originPoint + dir * dis;
					curPoint.y = this->ref_mpControl->getHeight(curPoint.x,curPoint.z*(-1));
					if (i > 0)
					{
						curPoint.y += this->mAnalysisOffsetY;
					}
					///slope没有管z
					double slope = this->ref_mpControl->getSlope(curPoint.x,curPoint.y,curPoint.z);
					double disToAccident = curPoint.distance(this->mAccidentPoint);
					CStatistionInfo info;
					info.Point = curPoint;
					info.Distance = disToAccident;
					info.Slope = slope;
					this->mSlopeStatistic.push_back(info);
					results.push_back(curPoint);
				}
			}
		}

		void CMineSafetySolution::reset()
		{
			this->mAccidentPoint = ::Ogre::Vector3::ZERO;
			this->mOptimalPoint = ::Ogre::Vector3::ZERO;
			this->mSurfaceNearerDrills.clear();
			this->mCanSelectAccident = false;
			mIsDrillingState = false;;
			mDrillingProgress = 0;
			mDrillLength = 0;
			mTiltRotation = Ogre::Quaternion::ZERO;
			this->mpDynamicCircleLine = NULL;
			this->mAnalysisProgress = 0;
			if (this->mpDrillRenderObject)
			{
				delete this->mpDrillRenderObject;
				this->mpDrillRenderObject = NULL;
			}

			if (this->mpNearerRenderLines)
			{
				delete this->mpNearerRenderLines;
				this->mpNearerRenderLines = NULL;
			}
			if (this->mpAnalysisLines)
			{
				this->mpAnalysisLines->dispose();
				delete this->mpAnalysisLines ;
				this->mpAnalysisLines = NULL;
			}
			if (this->mpNearerRenderPoints)
			{
				delete this->mpNearerRenderPoints;
				this->mpNearerRenderPoints = NULL;
			}

			if (this->mpDrillRenderObject)
			{
				delete this->mpDrillRenderObject;
				this->mpDrillRenderObject = NULL;
			}
		}

		void CMineSafetySolution::setSamplingDensity(const int& samplingDensity)
		{
			this->mSamplingDensity = samplingDensity;
		}

		int CMineSafetySolution::getSamplingDensity()
		{
			return this->mSamplingDensity;
		}

		void CMineSafetySolution::setSamplingPointCount(const int& samplingPointCount)
		{
			this->mSamplingPointCount = samplingPointCount;
		}

		int CMineSafetySolution::getSamplingPointCount()
		{
			return this->mSamplingPointCount;
		}

		void CMineSafetySolution::setAnalysisOffsetY(const Ogre::Real& analysisOffsetY)
		{
			this->mAnalysisOffsetY = analysisOffsetY;
		}

		Ogre::Real CMineSafetySolution::getAnalysisOffsetY()
		{
			return this->mAnalysisOffsetY;
		}
	}
}