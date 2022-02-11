/********************************************************************************
** Form generated from reading UI file 'shortCutViewDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTCUTVIEWDLG_H
#define UI_SHORTCUTVIEWDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShortCutView_UI
{
public:
    QGroupBox *groupBox;
    QLabel *label_3;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QPushButton *closeAct;

    void setupUi(QWidget *ShortCutView_UI)
    {
        if (ShortCutView_UI->objectName().isEmpty())
            ShortCutView_UI->setObjectName(QString::fromUtf8("ShortCutView_UI"));
        ShortCutView_UI->resize(431, 211);
        groupBox = new QGroupBox(ShortCutView_UI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 411, 61));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 30, 54, 12));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 30, 241, 16));
        groupBox_2 = new QGroupBox(ShortCutView_UI);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 90, 411, 61));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 30, 54, 12));
        closeAct = new QPushButton(ShortCutView_UI);
        closeAct->setObjectName(QString::fromUtf8("closeAct"));
        closeAct->setGeometry(QRect(320, 170, 75, 23));

        retranslateUi(ShortCutView_UI);
        QObject::connect(closeAct, SIGNAL(clicked()), ShortCutView_UI, SLOT(close()));

        QMetaObject::connectSlotsByName(ShortCutView_UI);
    } // setupUi

    void retranslateUi(QWidget *ShortCutView_UI)
    {
        ShortCutView_UI->setWindowTitle(QApplication::translate("ShortCutView_UI", "\345\277\253\346\215\267\346\226\271\345\274\217\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ShortCutView_UI", "\346\267\271\346\262\241\345\210\206\346\236\220:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ShortCutView_UI", "\345\274\200\345\205\263 / F", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ShortCutView_UI", "\346\260\264\344\275\215\344\270\212\345\215\207 / PgUp    \346\260\264\344\275\215\344\270\213\351\231\215 / PgD", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ShortCutView_UI", "\344\272\225\344\270\213\351\200\232\351\243\216", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ShortCutView_UI", "\345\274\200\345\205\263 / W", 0, QApplication::UnicodeUTF8));
        closeAct->setText(QApplication::translate("ShortCutView_UI", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ShortCutView_UI: public Ui_ShortCutView_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTCUTVIEWDLG_H
