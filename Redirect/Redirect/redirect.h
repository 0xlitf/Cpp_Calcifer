#ifndef REDIRECT_H
#define REDIRECT_H

#include <QtWidgets/QMainWindow>
#include "ui_redirect.h"

class Redirect : public QMainWindow
{
	Q_OBJECT

public:
	Redirect(QWidget *parent = 0);
	~Redirect();

private:
	Ui::RedirectClass ui;
};

#endif // REDIRECT_H
