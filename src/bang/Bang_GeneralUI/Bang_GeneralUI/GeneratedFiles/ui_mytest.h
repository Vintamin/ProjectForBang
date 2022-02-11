/********************************************************************************
** Form generated from reading UI file 'mytest.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTEST_H
#define UI_MYTEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mytest
{
public:
    QPushButton *pushButton;
    QToolButton *toolButton;

    void setupUi(QWidget *mytest)
    {
        if (mytest->objectName().isEmpty())
            mytest->setObjectName(QString::fromUtf8("mytest"));
        mytest->resize(828, 447);
        pushButton = new QPushButton(mytest);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 150, 93, 28));
        toolButton = new QToolButton(mytest);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(220, 260, 47, 21));

        retranslateUi(mytest);

        QMetaObject::connectSlotsByName(mytest);
    } // setupUi

    void retranslateUi(QWidget *mytest)
    {
        mytest->setWindowTitle(QApplication::translate("mytest", "mytest", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("mytest", "PushButton", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("mytest", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mytest: public Ui_mytest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTEST_H
