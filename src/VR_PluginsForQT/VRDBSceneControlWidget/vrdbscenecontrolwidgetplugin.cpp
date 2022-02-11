#include "vrdbscenecontrolwidget.h"

#include <QtCore/QtPlugin>
#include "vrdbscenecontrolwidgetplugin.h"


VRDBSceneControlWidgetPlugin::VRDBSceneControlWidgetPlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void VRDBSceneControlWidgetPlugin::initialize(QDesignerFormEditorInterface */*core*/)
{
	if (initialized)
		return;

	initialized = true;
}

bool VRDBSceneControlWidgetPlugin::isInitialized() const
{
	return initialized;
}

QWidget *VRDBSceneControlWidgetPlugin::createWidget(QWidget *parent)
{
	return new VRDBSceneControlWidget(parent);
}

QString VRDBSceneControlWidgetPlugin::name() const
{
	return "VRDBSceneControlWidget";
}

QString VRDBSceneControlWidgetPlugin::group() const
{
	return "My Plugins";
}

QIcon VRDBSceneControlWidgetPlugin::icon() const
{
	return QIcon();
}

QString VRDBSceneControlWidgetPlugin::toolTip() const
{
	return QString();
}

QString VRDBSceneControlWidgetPlugin::whatsThis() const
{
	return QString();
}

bool VRDBSceneControlWidgetPlugin::isContainer() const
{
	return false;
}

QString VRDBSceneControlWidgetPlugin::domXml() const
{
	return "<widget class=\"VRDBSceneControlWidget\" name=\"vRDBSceneControlWidget\">\n"
		" <property name=\"geometry\">\n"
		"  <rect>\n"
		"   <x>0</x>\n"
		"   <y>0</y>\n"
		"   <width>100</width>\n"
		"   <height>100</height>\n"
		"  </rect>\n"
		" </property>\n"
		"</widget>\n";
}

QString VRDBSceneControlWidgetPlugin::includeFile() const
{
	return "vrdbscenecontrolwidget.h";
}

Q_EXPORT_PLUGIN2(vrdbscenecontrolwidget, VRDBSceneControlWidgetPlugin)
