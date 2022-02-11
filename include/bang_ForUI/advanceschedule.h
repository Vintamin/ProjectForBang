#ifndef ADVANCESCHEDULE_H
#define ADVANCESCHEDULE_H

#include <QDialog>
#include "bang_configui.h"

namespace Ui
{
	class advanceScheduleForm;
}

namespace Bang
{
	class BANG_VRGENERALUI_DLL CAdvanceSchedule : public QDialog
	{
		Q_OBJECT

	public:
		CAdvanceSchedule(QWidget *parent = 0, Qt::WFlags flags = 0);
		~CAdvanceSchedule();
	private:
		Ui::advanceScheduleForm* ui;

	};
}


#endif // ADVANCESCHEDULE_H
