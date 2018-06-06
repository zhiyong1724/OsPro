#include "OsPro.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	OsPro w;
	w.show();
	return a.exec();
}
