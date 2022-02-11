#include "vrcontrol.h"

#include <QtCore/QtPlugin>
#include "vrcontrolplugin.h"


VRControlPlugin::VRControlPlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void VRControlPlugin::initialize(QDesignerFormEditorInterface */*core*/)
{
	if (initialized)
		return;

	initialized = true;
}

bool VRControlPlugin::isInitialized() const
{
	return initialized;
}

QWidget *VRControlPlugin::createWidget(QWidget *parent)
{
	return new VRControl(parent);
}

QString VRControlPlugin::name() const
{
	return "VRControl";
}

QString VRControlPlugin::group() const
{
	return "My Plugins";
}

QIcon VRControlPlugin::icon() const
{
	return QIcon();
}

QString VRControlPlugin::toolTip() const
{
	return QString();
}

QString VRControlPlugin::whatsThis() const
{
	return QString();
}

bool VRControlPlugin::isContainer() const
{
	return false;
}

QString VRControlPlugin::domXml() const
{
	return "<widget class=\"VRControl\" name=\"vRControl\">\n"
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

QString VRControlPlugin::includeFile() const
{
	return "vrcontrol.h";
}

Q_EXPORT_PLUGIN2(vrcontrol, VRControlPlugin)
