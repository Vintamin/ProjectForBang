#ifndef MYTEST_H
#define MYTEST_H

#include <QWidget>
#include "ui_mytest.h"

class mytest : public QWidget
{
	Q_OBJECT

public:
	mytest(QWidget *parent = 0);
	~mytest();

private:
	Ui::mytest ui;
};

#endif // MYTEST_H
