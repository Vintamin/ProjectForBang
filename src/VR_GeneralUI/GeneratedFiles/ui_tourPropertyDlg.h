/********************************************************************************
** Form generated from reading UI file 'tourPropertyDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOURPROPERTYDLG_H
#define UI_TOURPROPERTYDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TourPropertyUI
{
public:
    QGroupBox *groupBox;
    QPushButton *selectPath;
    QLineEdit *tourPath;
    QLabel *label;
    QPushButton *close;
    QPushButton *loadTour;

    void setupUi(QWidget *TourPropertyUI)
    {
        if (TourPropertyUI->objectName().isEmpty())
            TourPropertyUI->setObjectName(QString::fromUtf8("TourPropertyUI"));
        TourPropertyUI->resize(524, 155);
        groupBox = new QGroupBox(TourPropertyUI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 501, 81));
        selectPath = new QPushButton(groupBox);
        selectPath->setObjectName(QString::fromUtf8("selectPath"));
        selectPath->setGeometry(QRect(420, 30, 61, 31));
        tourPath = new QLineEdit(groupBox);
        tourPath->setObjectName(QString::fromUtf8("tourPath"));
        tourPath->setGeometry(QRect(80, 30, 321, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 61, 16));
        close = new QPushButton(TourPropertyUI);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(420, 110, 71, 31));
        loadTour = new QPushButton(TourPropertyUI);
        loadTour->setObjectName(QString::fromUtf8("loadTour"));
        loadTour->setGeometry(QRect(300, 110, 81, 31));
        groupBox->raise();
        loadTour->raise();
        close->raise();
        loadTour->raise();

        retranslateUi(TourPropertyUI);
        QObject::connect(selectPath, SIGNAL(clicked()), TourPropertyUI, SLOT(slotSelectPath()));
        QObject::connect(loadTour, SIGNAL(clicked()), TourPropertyUI, SLOT(slotLoadTour()));
        QObject::connect(close, SIGNAL(clicked()), TourPropertyUI, SLOT(slotClose()));

        QMetaObject::connectSlotsByName(TourPropertyUI);
    } // setupUi

    void retranslateUi(QWidget *TourPropertyUI)
    {
        TourPropertyUI->setWindowTitle(QApplication::translate("TourPropertyUI", "\346\270\270\350\247\210\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        selectPath->setText(QApplication::translate("TourPropertyUI", "\346\265\217\350\247\210..", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TourPropertyUI", "\346\270\270\350\247\210\350\267\257\345\276\204\357\274\232", 0, QApplication::UnicodeUTF8));
        close->setText(QApplication::translate("TourPropertyUI", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        loadTour->setText(QApplication::translate("TourPropertyUI", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TourPropertyUI: public Ui_TourPropertyUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOURPROPERTYDLG_H
