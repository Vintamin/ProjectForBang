/********************************************************************************
** Form generated from reading UI file 'globalMonitorDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLOBALMONITORDLG_H
#define UI_GLOBALMONITORDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_globalMonitorWidget
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *globalMonitorWidget)
    {
        if (globalMonitorWidget->objectName().isEmpty())
            globalMonitorWidget->setObjectName(QString::fromUtf8("globalMonitorWidget"));
        globalMonitorWidget->resize(347, 241);
        pushButton = new QPushButton(globalMonitorWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 130, 75, 23));

        retranslateUi(globalMonitorWidget);
        QObject::connect(pushButton, SIGNAL(clicked()), globalMonitorWidget, SLOT(slottest()));

        QMetaObject::connectSlotsByName(globalMonitorWidget);
    } // setupUi

    void retranslateUi(QWidget *globalMonitorWidget)
    {
        globalMonitorWidget->setWindowTitle(QApplication::translate("globalMonitorWidget", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("globalMonitorWidget", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class globalMonitorWidget: public Ui_globalMonitorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLOBALMONITORDLG_H
