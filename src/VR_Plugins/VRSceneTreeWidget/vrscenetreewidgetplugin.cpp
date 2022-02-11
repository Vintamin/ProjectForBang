#include "vrmine\vr_plugins\vrscenetreewidget.h"

#include <QtCore/QtPlugin>
#include "vrscenetreewidgetplugin.h"


VRSceneTreeWidgetPlugin::VRSceneTreeWidgetPlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void VRSceneTreeWidgetPlugin::initialize(QDesignerFormEditorInterface */*core*/)
{
	if (initialized)
		return;

	initialized = true;
}

bool VRSceneTreeWidgetPlugin::isInitialized() const
{
	return initialized;
}

QWidget *VRSceneTreeWidgetPlugin::createWidget(QWidget *parent)
{
	return new VRSceneTreeWidget(parent);
}

QString VRSceneTreeWidgetPlugin::name() const
{
	return "VRSceneTreeWidget";
}

QString VRSceneTreeWidgetPlugin::group() const
{
	return "My Plugins";
}

QIcon VRSceneTreeWidgetPlugin::icon() const
{
	return QIcon();
}

QString VRSceneTreeWidgetPlugin::toolTip() const
{
	return QString();
}

QString VRSceneTreeWidgetPlugin::whatsThis() const
{
	return QString();
}

bool VRSceneTreeWidgetPlugin::isContainer() const
{
	return false;
}

QString VRSceneTreeWidgetPlugin::domXml() const
{
	return "<widget class=\"VRSceneTreeWidget\" name=\"vRSceneTreeWidget\">\n"
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

QString VRSceneTreeWidgetPlugin::includeFile() const
{
	return "vrscenetreewidget.h";
}

Q_EXPORT_PLUGIN2(vrscenetreewidget, VRSceneTreeWidgetPlugin)
