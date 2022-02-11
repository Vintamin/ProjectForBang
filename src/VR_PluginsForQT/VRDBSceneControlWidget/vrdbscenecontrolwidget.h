#ifndef VRDBSCENECONTROLWIDGET_H
#define VRDBSCENECONTROLWIDGET_H

//定义插件导出符号
#ifndef QDESIGNER_EXPORT_WIDGETS
#define VRDBCONTORL_DLL_FORQT _declspec(dllimport)
#else
#define VRDBCONTORL_DLL_FORQT _declspec(dllexport)
#endif

#include <QtGui/QTreeWidget>

class VRDBSceneControlWidget : public QTreeWidget
{
	Q_OBJECT

public:
	VRDBSceneControlWidget(QWidget *parent = 0);
	~VRDBSceneControlWidget();
	virtual void paintEvent(QPaintEvent * evt);
};

#endif // VRDBSCENECONTROLWIDGET_H
