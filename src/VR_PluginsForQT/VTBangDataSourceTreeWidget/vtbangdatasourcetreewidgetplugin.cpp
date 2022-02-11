#include "vtbangdatasourcetreewidget.h"

#include <QtCore/QtPlugin>
#include "vtbangdatasourcetreewidgetplugin.h"


VTBangDataSourceTreeWidgetPlugin::VTBangDataSourceTreeWidgetPlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void VTBangDataSourceTreeWidgetPlugin::initialize(QDesignerFormEditorInterface */*core*/)
{
	if (initialized)
		return;

	initialized = true;
}

bool VTBangDataSourceTreeWidgetPlugin::isInitialized() const
{
	return initialized;
}

QWidget *VTBangDataSourceTreeWidgetPlugin::createWidget(QWidget *parent)
{
	return new VTBangDataSourceTreeWidget(parent);
}

QString VTBangDataSourceTreeWidgetPlugin::name() const
{
	return "VTBangDataSourceTreeWidget";
}

QString VTBangDataSourceTreeWidgetPlugin::group() const
{
	return "My Plugins";
}

QIcon VTBangDataSourceTreeWidgetPlugin::icon() const
{
	return QIcon();
}

QString VTBangDataSourceTreeWidgetPlugin::toolTip() const
{
	return QString();
}

QString VTBangDataSourceTreeWidgetPlugin::whatsThis() const
{
	return QString();
}

bool VTBangDataSourceTreeWidgetPlugin::isContainer() const
{
	return false;
}

QString VTBangDataSourceTreeWidgetPlugin::domXml() const
{
	return "<widget class=\"VTBangDataSourceTreeWidget\" name=\"vTBangDataSourceTreeWidget\">\n"
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

QString VTBangDataSourceTreeWidgetPlugin::includeFile() const
{
	return "vtbangdatasourcetreewidget.h";
}

Q_EXPORT_PLUGIN2(vtbangdatasourcetreewidget, VTBangDataSourceTreeWidgetPlugin)
