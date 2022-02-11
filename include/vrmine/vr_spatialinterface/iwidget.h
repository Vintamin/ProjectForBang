#if !defined(_IWIDGET_H)
#define _IWIDGET_H

#include "vrmine\vr_core\baseobject.h"
#include "vrmine\vr_spatialinterface\spatialinterface_config.h"
#include "vrmine\vr_spatialinterface\itool.h"

namespace VirtualMine
{
	namespace SpatialInterface
	{
		class VR_SPATIALINTERFACE_DLL IWidget : public VirtualMine::SpatialInterface::ITool
		{
		public:
			IWidget();
			virtual ~IWidget();
			virtual std::string getName()=0;
			virtual void setName(const std::string& name)=0;
			virtual Ogre::Vector3 getPosition()=0;
			virtual void setPosition(const Ogre::Vector3& position)=0;
			virtual Ogre::Vector3 getSize()=0;
			virtual void setSize(const Ogre::Vector3& size)=0;
			virtual std::string getMaterialName()=0;
			virtual void setMaterialName(const std::string& materialName)=0;
			virtual bool getVisible()=0;
			virtual void setVisible(const bool& value)=0;
			virtual IWidget* getParentWidget()=0;
			virtual void setParentWidget(IWidget* pParentWidget)=0;
			virtual std::vector<IWidget*>& getChildWidget()=0;
			virtual bool addChildWidget(IWidget* pChildWidget)=0;
			virtual bool removeChildWidget(IWidget* pChildWidget)=0;
			virtual void initialise()=0;
			virtual void draw()=0;
			virtual void notifyUpdate()=0;

		};
	}
}
#endif
