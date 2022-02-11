#include "vr_generalui.h"

#include <QtCore/QtPlugin>
#include "vr_generaluiplugin.h"


VR_GeneralUIPlugin::VR_GeneralUIPlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void VR_GeneralUIPlugin::initialize(QDesignerFormEditorInterface */*core*/)
{
	if (initialized)
		return;

	initialized = true;
}

bool VR_GeneralUIPlugin::isInitialized() const
{
	return initialized;
}

QWidget *VR_GeneralUIPlugin::createWidget(QWidget *parent)
{
	return new VR_GeneralUI(parent);
}

QString VR_GeneralUIPlugin::name() const
{
	return "VR_GeneralUI";
}

QString VR_GeneralUIPlugin::group() const
{
	return "My Plugins";
}

QIcon VR_GeneralUIPlugin::icon() const
{
	return QIcon();
}

QString VR_GeneralUIPlugin::toolTip() const
{
	return QString();
}

QString VR_GeneralUIPlugin::whatsThis() const
{
	return QString();
}

bool VR_GeneralUIPlugin::isContainer() const
{
	return false;
}

QString VR_GeneralUIPlugin::domXml() const
{
	return "<widget class=\"VR_GeneralUI\" name=\"vR_GeneralUI\">\n"
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

QString VR_GeneralUIPlugin::includeFile() const
{
	return "vr_generalui.h";
}

Q_EXPORT_PLUGIN2(vr_generalui, VR_GeneralUIPlugin)
