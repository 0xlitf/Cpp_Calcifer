/********************************************************************************
** Form generated from reading UI file 'qtclient.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCLIENT_H
#define UI_QTCLIENT_H

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

class Ui_QtClientClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtClientClass)
    {
        if (QtClientClass->objectName().isEmpty())
            QtClientClass->setObjectName(QStringLiteral("QtClientClass"));
        QtClientClass->resize(600, 400);
        menuBar = new QMenuBar(QtClientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtClientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtClientClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtClientClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtClientClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtClientClass->setStatusBar(statusBar);

        retranslateUi(QtClientClass);

        QMetaObject::connectSlotsByName(QtClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtClientClass)
    {
        QtClientClass->setWindowTitle(QApplication::translate("QtClientClass", "QtClient", 0));
    } // retranslateUi

};

namespace Ui {
    class QtClientClass: public Ui_QtClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCLIENT_H
