#include "vrmine/vr_plugins/vrdatasourcetreewidget.h"

#include <QtCore/QtPlugin>
#include "vrdatasourcetreewidgetplugin.h"


VRDataSourceTreeWidgetPlugin::VRDataSourceTreeWidgetPlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void VRDataSourceTreeWidgetPlugin::initialize(QDesignerFormEditorInterface */*core*/)
{
	if (initialized)
		return;

	initialized = true;
}

bool VRDataSourceTreeWidgetPlugin::isInitialized() const
{
	return initialized;
}

QWidget *VRDataSourceTreeWidgetPlugin::createWidget(QWidget *parent)
{
	return new VRDataSourceTreeWidget(parent);
}

QString VRDataSourceTreeWidgetPlugin::name() const
{
	return "VR_DataSourceTreeWidget";
}

QString VRDataSourceTreeWidgetPlugin::group() const
{
	return "My Plugins";
}

QIcon VRDataSourceTreeWidgetPlugin::icon() const
{
	return QIcon();
}

QString VRDataSourceTreeWidgetPlugin::toolTip() const
{
	return QString();
}

QString VRDataSourceTreeWidgetPlugin::whatsThis() const
{
	return QString();
}

bool VRDataSourceTreeWidgetPlugin::isContainer() const
{
	return false;
}

QString VRDataSourceTreeWidgetPlugin::domXml() const
{
	return "<widget class=\"VR_DataSourceTreeWidget\" name=\"vR_DataSourceTreeWidget\">\n"
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

QString VRDataSourceTreeWidgetPlugin::includeFile() const
{
	return "vr_datasourcetreewidget.h";
}

Q_EXPORT_PLUGIN2(vr_datasourcetreewidget, VRDataSourceTreeWidgetPlugin)
