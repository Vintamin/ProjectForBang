#ifndef VR_DATASOURCETREEWIDGET_H
#define VR_DATASOURCETREEWIDGET_H

//定义插件导出符号
#ifndef QDESIGNER_EXPORT_WIDGETS
#define VRDATASOURCECONTORL_DLL_FORQT _declspec(dllimport)
#else
#define VRDATASOURCECONTORL_DLL_FORQT _declspec(dllexport)
#endif

#include <QtGui/QWidget>

class VRDATASOURCECONTORL_DLL_FORQT VRDataSourceTreeWidget : public QWidget
{
	Q_OBJECT

public:
	VRDataSourceTreeWidget(QWidget *parent = 0);
	~VRDataSourceTreeWidget();
	virtual void paintEvent(QPaintEvent * evt);

};

#endif // VR_DATASOURCETREEWIDGET_H
