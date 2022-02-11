
#include "vrmine/vr_systemui/rayselectedtool.h"
#include "OGRE/OgreSceneQuery.h"
#include "vrmine/vr_core/userdata.h"
using namespace VirtualMine::Core;
using namespace VirtualMine::Scene;

namespace VirtualMine
{
	namespace SystemUI
	{
		CRaySelectedTool::CRaySelectedTool()
			:ref_mpGeoSpatialControl(NULL)
		{
		
		}
		
		CRaySelectedTool::~CRaySelectedTool()
		{
		
		}

		void CRaySelectedTool::setGeoSpatialControl(VirtualMine::Scene::CGeoSpatialControl* ref_pGeoSpatialControl)
		{
			this->ref_mpGeoSpatialControl= ref_pGeoSpatialControl;
		}
		
		void CRaySelectedTool::mouseReleaseEvent(const int& x ,const int& y , const int& button)
		{
			if (button == 1 && !this->mIsMouseDrag)
			{
				Ogre::Vector3 intersectPoint(Ogre::Vector3::ZERO);
				Ogre::RaySceneQueryResultEntry resultObject;
				resultObject.movable = NULL;
				resultObject.worldFragment = NULL;
				resultObject.distance = DBL_MAX;
				this->ref_mpGeoSpatialControl->getGeoSceneManager()->rayQuery(x,y,intersectPoint,resultObject);
				if (this->ref_mpGeoSpatialControl)
				{
					this->ref_mpGeoSpatialControl->afterRayQuery(resultObject);
				}
				//if (resultObject.movable != NULL)
				//{
				//	//resultObject.movable->setUserAny()
				//	
				//	CGeoUserData* pUserData = resultObject.movable->getUserAny().get<CGeoUserData*>();
				//	if (pUserData != NULL)
				//	{
				//		pUserData->setSelected(true);
				//	}
				//}
			}
		}
		
		void CRaySelectedTool::mousePressEvent(const int& x ,const int& y , const int& button)
		{
			CTool::mousePressEvent(x,y,button);
		}
		
		void CRaySelectedTool::mouseDoubleClickEvent(const int& x ,const int& y , const int& button)
		{
			CTool::mouseDoubleClickEvent(x,y,button);
		}
	
		void CRaySelectedTool::mouseMoveEvent(const int& x ,const int& y, const int& button)
		{
			CTool::mouseMoveEvent(x,y,button);
		}
		
		void CRaySelectedTool::wheelEvent(const int& x ,const int& y , const int& delta)
		{
			CTool::wheelEvent(x,y,delta);
		}
		
		void CRaySelectedTool::keyPressEvent(const int& key)
		{
		
		}
		
		bool CRaySelectedTool::handleEvent(VirtualMine::Core::CEvent* evt)
		{
			return CTool::handleEvent(evt);
			/*CEvent::Type type = evt->type();
			switch(type)
			{
			case CEvent::MouseButtonPress:
				{
					break;
				}
			case CEvent::MouseButtonRelease:
				{
					CMouseEvent* pMouseEvent = dynamic_cast<CMouseEvent*>(evt);
					this->mouseReleaseEvent(pMouseEvent->getX(),pMouseEvent->getY(),pMouseEvent->getButton());
					evt->accept();
					break;
				}
			case CEvent::MouseMove:
				{
					break;	
				}
			default:
				break;
			}
			return evt->isAccepted();*/
		}
	
	}
}
