#include "vrdbscenetreewidget.h"

#include <QtCore/QtPlugin>
#include "vrdbscenetreewidgetplugin.h"


VRDBSceneTreeWidgetPlugin::VRDBSceneTreeWidgetPlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void VRDBSceneTreeWidgetPlugin::initialize(QDesignerFormEditorInterface */*core*/)
{
	if (initialized)
		return;

	initialized = true;
}

bool VRDBSceneTreeWidgetPlugin::isInitialized() const
{
	return initialized;
}

QWidget *VRDBSceneTreeWidgetPlugin::createWidget(QWidget *parent)
{
	return new VRDBSceneTreeWidget(parent);
}

QString VRDBSceneTreeWidgetPlugin::name() const
{
	return "VRDBSceneTreeWidget";
}

QString VRDBSceneTreeWidgetPlugin::group() const
{
	return "My Plugins";
}

QIcon VRDBSceneTreeWidgetPlugin::icon() const
{
	return QIcon();
}

QString VRDBSceneTreeWidgetPlugin::toolTip() const
{
	return QString();
}

QString VRDBSceneTreeWidgetPlugin::whatsThis() const
{
	return QString();
}

bool VRDBSceneTreeWidgetPlugin::isContainer() const
{
	return false;
}

QString VRDBSceneTreeWidgetPlugin::domXml() const
{
	return "<widget class=\"VRDBSceneTreeWidget\" name=\"vRDBSceneTreeWidget\">\n"
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

QString VRDBSceneTreeWidgetPlugin::includeFile() const
{
	return "vrdbscenetreewidget.h";
}

Q_EXPORT_PLUGIN2(vrdbscenetreewidget, VRDBSceneTreeWidgetPlugin)
