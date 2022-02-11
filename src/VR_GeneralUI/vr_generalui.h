#ifndef VR_GENERALUI_H
#define VR_GENERALUI_H

#include <QtGui/QWidget>
#include "vrmine\vr_generalui\vr_generaluiconfig.h"

class VRGENERALUI_DLL VR_GeneralUI : public QWidget
{
	Q_OBJECT

public:
	VR_GeneralUI(QWidget *parent = 0);
	~VR_GeneralUI();

};
#endif // VR_GENERALUI_H
