#include "vr_application.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VR_Application w;
	w.show();
	return a.exec();
}
