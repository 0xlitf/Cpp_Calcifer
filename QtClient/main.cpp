#include "qtclient.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtClient w;
	w.show();
	QMessageBox::warning(NULL, QString("QMessageBox"), QString("err"));
	return a.exec();
}
