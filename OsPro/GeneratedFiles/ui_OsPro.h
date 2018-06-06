/********************************************************************************
** Form generated from reading UI file 'OsPro.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSPRO_H
#define UI_OSPRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include "paintwidget.h"

QT_BEGIN_NAMESPACE

class Ui_OsPro
{
public:
    PaintWidget *CentralWidget;

    void setupUi(QMainWindow *OsPro)
    {
        if (OsPro->objectName().isEmpty())
            OsPro->setObjectName(QStringLiteral("OsPro"));
        OsPro->resize(600, 400);
        OsPro->setMinimumSize(QSize(600, 400));
        OsPro->setMaximumSize(QSize(600, 400));
        CentralWidget = new PaintWidget(OsPro);
        CentralWidget->setObjectName(QStringLiteral("CentralWidget"));
        OsPro->setCentralWidget(CentralWidget);

        retranslateUi(OsPro);

        QMetaObject::connectSlotsByName(OsPro);
    } // setupUi

    void retranslateUi(QMainWindow *OsPro)
    {
        OsPro->setWindowTitle(QApplication::translate("OsPro", "OsPro", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OsPro: public Ui_OsPro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSPRO_H
