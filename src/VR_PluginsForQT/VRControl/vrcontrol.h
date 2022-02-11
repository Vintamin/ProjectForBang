#ifndef VRCONTROL_H
#define VRCONTROL_H


//定义插件导出符号
#ifndef QDESIGNER_EXPORT_WIDGETS
#define VRCONTORL_DLL_FORQT _declspec(dllimport)
#else
#define VRCONTORL_DLL_FORQT _declspec(dllexport)
#endif

#include <QtGui/QWidget>



class VRCONTORL_DLL_FORQT VRControl : public QWidget
{
	Q_OBJECT

public:
	VRControl(QWidget *parent = 0);
	~VRControl();
	virtual void paintEvent(QPaintEvent * evt);

};

#endif // VRCONTROL_H
