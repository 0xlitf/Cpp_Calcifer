#ifndef QTCLIENT_H
#define QTCLIENT_H

#include <QtWidgets/QMainWindow>
#include "ui_qtclient.h"

class QtClient : public QMainWindow
{
	Q_OBJECT

public:
	QtClient(QWidget *parent = 0);
	~QtClient();

private:
	Ui::QtClientClass ui;
};

#endif // QTCLIENT_H
