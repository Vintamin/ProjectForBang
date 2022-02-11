#if !defined(_WIDGET_H)
#define _WIDGET_H

#include "vrmine\vr_scenecontrol\scenecontrol_config.h"
#include "vrmine\vr_core\baseobject.h"
#include "vrmine\vr_spatialinterface\iwidget.h"


namespace VirtualMine
{
	namespace Scene
	{
		class CWidget_Private;
		class CCompassWidget_Private;
		class CGeoSpatialControl;
		class VR_SCENECONTROL_DLL CWidget : public VirtualMine::SpatialInterface::IWidget
		{
		public:
			CWidget();
			CWidget(CGeoSpatialControl* ref_pSceneControl);
			virtual ~CWidget();
			virtual std::string getName();
			virtual void setName(const std::string& name);
			virtual Ogre::Vector3 getPosition();
			virtual void setPosition(const Ogre::Vector3& position);
			virtual Ogre::Vector3 getSize();
			virtual void setSize(const Ogre::Vector3& size);
			virtual std::string getMaterialName();
			virtual void setMaterialName(const std::string& materialName);
			virtual bool getVisible();
			virtual void setVisible(const bool& value);
			virtual VirtualMine::SpatialInterface::IWidget* getParentWidget();
			virtual void setParentWidget(VirtualMine::SpatialInterface::IWidget* pParentWidget);
			virtual std::vector<VirtualMine::SpatialInterface::IWidget*>& getChildWidget();
			virtual bool addChildWidget(VirtualMine::SpatialInterface::IWidget* pChildWidget);
			virtual bool removeChildWidget(VirtualMine::SpatialInterface::IWidget* pChildWidget);
			virtual void initialise();
			virtual void draw();
			virtual void notifyUpdate();
			virtual bool handleEvent(VirtualMine::Core::CEvent* evt);
			virtual CGeoSpatialControl* getSceneControl();

		private:
			CWidget_Private* mpPrivate;
		};

		class VR_SCENECONTROL_DLL CCompassWidget : public CWidget
		{
		public:
			CCompassWidget(CGeoSpatialControl* ref_pSceneControl);
			virtual ~CCompassWidget();
			void initialise();
			virtual void mouseReleaseEvent(const int& x ,const int& y , const int& button);
			virtual void mousePressEvent(const int& x ,const int& y , const int& button);
			virtual void mouseDoubleClickEvent(const int& x ,const int& y , const int& button);
			virtual void mouseMoveEvent(const int& x ,const int& y, const int& button);
			bool handleEvent(VirtualMine::Core::CEvent* evt);

		private:
			CCompassWidget_Private* mpPrivate;
		};
	}
}
#endif
