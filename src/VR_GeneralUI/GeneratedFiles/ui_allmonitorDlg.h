/********************************************************************************
** Form generated from reading UI file 'allmonitorDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLMONITORDLG_H
#define UI_ALLMONITORDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AllMonitorWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QLabel *timetext;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *simubtn;
    QPushButton *switchbtn;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *AllMonitorWidget)
    {
        if (AllMonitorWidget->objectName().isEmpty())
            AllMonitorWidget->setObjectName(QString::fromUtf8("AllMonitorWidget"));
        AllMonitorWidget->resize(231, 115);
        AllMonitorWidget->setMinimumSize(QSize(231, 115));
        AllMonitorWidget->setMaximumSize(QSize(231, 115));
        gridLayout = new QGridLayout(AllMonitorWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(AllMonitorWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_5->addWidget(label);

        timetext = new QLabel(AllMonitorWidget);
        timetext->setObjectName(QString::fromUtf8("timetext"));

        verticalLayout_5->addWidget(timetext);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        simubtn = new QPushButton(AllMonitorWidget);
        simubtn->setObjectName(QString::fromUtf8("simubtn"));

        verticalLayout->addWidget(simubtn);

        switchbtn = new QPushButton(AllMonitorWidget);
        switchbtn->setObjectName(QString::fromUtf8("switchbtn"));
        switchbtn->setMinimumSize(QSize(75, 23));
        switchbtn->setMaximumSize(QSize(75, 23));

        verticalLayout->addWidget(switchbtn);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(AllMonitorWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(AllMonitorWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(AllMonitorWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(AllMonitorWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_7 = new QLabel(AllMonitorWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_4->addWidget(label_7);

        label_8 = new QLabel(AllMonitorWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);


        retranslateUi(AllMonitorWidget);

        QMetaObject::connectSlotsByName(AllMonitorWidget);
    } // setupUi

    void retranslateUi(QWidget *AllMonitorWidget)
    {
        AllMonitorWidget->setWindowTitle(QApplication::translate("AllMonitorWidget", "\345\256\236\346\227\266\347\233\221\346\265\213\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AllMonitorWidget", "\347\233\221\346\265\213\347\233\221\346\216\247\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        timetext->setText(QApplication::translate("AllMonitorWidget", "00:00:00", 0, QApplication::UnicodeUTF8));
        simubtn->setText(QApplication::translate("AllMonitorWidget", "\346\250\241\346\213\237\351\207\217", 0, QApplication::UnicodeUTF8));
        switchbtn->setText(QApplication::translate("AllMonitorWidget", "\345\274\200\345\205\263\351\207\217", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AllMonitorWidget", "\357\274\21083\344\270\252\357\274\211", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AllMonitorWidget", "\357\274\2101\344\270\252\357\274\211", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AllMonitorWidget", "\346\212\245\350\255\246", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AllMonitorWidget", "\345\205\263", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AllMonitorWidget", "0", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("AllMonitorWidget", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AllMonitorWidget: public Ui_AllMonitorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLMONITORDLG_H
