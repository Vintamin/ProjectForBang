#include "vr_mapcontrolwidget.h"

#include <QtCore/QtPlugin>
#include "vr_mapcontrolwidgetplugin.h"


VR_MapControlWidgetPlugin::VR_MapControlWidgetPlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void VR_MapControlWidgetPlugin::initialize(QDesignerFormEditorInterface */*core*/)
{
	if (initialized)
		return;

	initialized = true;
}

bool VR_MapControlWidgetPlugin::isInitialized() const
{
	return initialized;
}

QWidget *VR_MapControlWidgetPlugin::createWidget(QWidget *parent)
{
	return new VR_MapControlWidget(parent);
}

QString VR_MapControlWidgetPlugin::name() const
{
	return "VR_MapControlWidget";
}

QString VR_MapControlWidgetPlugin::group() const
{
	return "My Plugins";
}

QIcon VR_MapControlWidgetPlugin::icon() const
{
	return QIcon();
}

QString VR_MapControlWidgetPlugin::toolTip() const
{
	return QString();
}

QString VR_MapControlWidgetPlugin::whatsThis() const
{
	return QString();
}

bool VR_MapControlWidgetPlugin::isContainer() const
{
	return false;
}

QString VR_MapControlWidgetPlugin::domXml() const
{
	return "<widget class=\"VR_MapControlWidget\" name=\"vR_MapControlWidget\">\n"
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

QString VR_MapControlWidgetPlugin::includeFile() const
{
	return "vr_mapcontrolwidget.h";
}

Q_EXPORT_PLUGIN2(vr_mapcontrolwidget, VR_MapControlWidgetPlugin)
