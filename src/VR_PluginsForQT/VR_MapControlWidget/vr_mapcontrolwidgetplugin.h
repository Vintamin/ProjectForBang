#ifndef VR_MAPCONTROLWIDGETPLUGIN_H
#define VR_MAPCONTROLWIDGETPLUGIN_H

#include <QDesignerCustomWidgetInterface>

class VR_MapControlWidgetPlugin : public QObject, public QDesignerCustomWidgetInterface
{
	Q_OBJECT
	Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
	VR_MapControlWidgetPlugin(QObject *parent = 0);

	bool isContainer() const;
	bool isInitialized() const;
	QIcon icon() const;
	QString domXml() const;
	QString group() const;
	QString includeFile() const;
	QString name() const;
	QString toolTip() const;
	QString whatsThis() const;
	QWidget *createWidget(QWidget *parent);
	void initialize(QDesignerFormEditorInterface *core);

private:
	bool initialized;
};

#endif // VR_MAPCONTROLWIDGETPLUGIN_H
