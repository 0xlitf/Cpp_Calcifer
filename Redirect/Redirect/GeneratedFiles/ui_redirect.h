/********************************************************************************
** Form generated from reading UI file 'redirect.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDIRECT_H
#define UI_REDIRECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RedirectClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RedirectClass)
    {
        if (RedirectClass->objectName().isEmpty())
            RedirectClass->setObjectName(QStringLiteral("RedirectClass"));
        RedirectClass->resize(600, 400);
        menuBar = new QMenuBar(RedirectClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        RedirectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RedirectClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RedirectClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(RedirectClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        RedirectClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RedirectClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RedirectClass->setStatusBar(statusBar);

        retranslateUi(RedirectClass);

        QMetaObject::connectSlotsByName(RedirectClass);
    } // setupUi

    void retranslateUi(QMainWindow *RedirectClass)
    {
        RedirectClass->setWindowTitle(QApplication::translate("RedirectClass", "Redirect", 0));
    } // retranslateUi

};

namespace Ui {
    class RedirectClass: public Ui_RedirectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDIRECT_H
