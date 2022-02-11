/********************************************************************************
** Form generated from reading UI file 'switchpropertyDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWITCHPROPERTYDLG_H
#define UI_SWITCHPROPERTYDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SwitchDlg
{
public:
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *nameLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *typeLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *addressLabel;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLabel *baojingStautsLabel;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLabel *statusLabel;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLabel *baojingLabel;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QLabel *duandianLabel;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QLabel *kuidianLabel;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QLabel *timeLabel;

    void setupUi(QWidget *SwitchDlg)
    {
        if (SwitchDlg->objectName().isEmpty())
            SwitchDlg->setObjectName(QString::fromUtf8("SwitchDlg"));
        SwitchDlg->resize(297, 279);
        SwitchDlg->setMinimumSize(QSize(297, 279));
        SwitchDlg->setMaximumSize(QSize(297, 279));
        gridLayout_4 = new QGridLayout(SwitchDlg);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(SwitchDlg);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 60));
        groupBox->setMaximumSize(QSize(16777215, 100));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(label);

        nameLabel = new QLabel(groupBox);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        horizontalLayout->addWidget(nameLabel);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(label_3);

        typeLabel = new QLabel(groupBox);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));

        horizontalLayout_2->addWidget(typeLabel);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(label_2);

        addressLabel = new QLabel(groupBox);
        addressLabel->setObjectName(QString::fromUtf8("addressLabel"));

        horizontalLayout_3->addWidget(addressLabel);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SwitchDlg);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 178));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(label_7);

        baojingStautsLabel = new QLabel(groupBox_2);
        baojingStautsLabel->setObjectName(QString::fromUtf8("baojingStautsLabel"));

        horizontalLayout_5->addWidget(baojingStautsLabel);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(label_8);

        statusLabel = new QLabel(groupBox_2);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));

        horizontalLayout_6->addWidget(statusLabel);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(label_9);

        baojingLabel = new QLabel(groupBox_2);
        baojingLabel->setObjectName(QString::fromUtf8("baojingLabel"));

        horizontalLayout_7->addWidget(baojingLabel);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(label_10);

        duandianLabel = new QLabel(groupBox_2);
        duandianLabel->setObjectName(QString::fromUtf8("duandianLabel"));

        horizontalLayout_8->addWidget(duandianLabel);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_9->addWidget(label_11);

        kuidianLabel = new QLabel(groupBox_2);
        kuidianLabel->setObjectName(QString::fromUtf8("kuidianLabel"));

        horizontalLayout_9->addWidget(kuidianLabel);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_10->addWidget(label_12);

        timeLabel = new QLabel(groupBox_2);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        horizontalLayout_10->addWidget(timeLabel);


        verticalLayout->addLayout(horizontalLayout_10);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);

        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        kuidianLabel->raise();
        duandianLabel->raise();
        statusLabel->raise();
        baojingLabel->raise();
        baojingStautsLabel->raise();
        groupBox->raise();
        groupBox->raise();
        groupBox->raise();
        timeLabel->raise();

        verticalLayout_2->addWidget(groupBox_2);


        gridLayout_4->addLayout(verticalLayout_2, 0, 0, 1, 1);

        groupBox->raise();
        groupBox_2->raise();
        groupBox->raise();

        retranslateUi(SwitchDlg);

        QMetaObject::connectSlotsByName(SwitchDlg);
    } // setupUi

    void retranslateUi(QWidget *SwitchDlg)
    {
        SwitchDlg->setWindowTitle(QApplication::translate("SwitchDlg", "\345\274\200\345\205\263\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SwitchDlg", "\350\256\276\345\244\207\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SwitchDlg", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("SwitchDlg", "----", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SwitchDlg", "\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        typeLabel->setText(QApplication::translate("SwitchDlg", "----", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SwitchDlg", "\345\234\260\347\202\271", 0, QApplication::UnicodeUTF8));
        addressLabel->setText(QApplication::translate("SwitchDlg", "----", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("SwitchDlg", "\347\233\221\346\265\213\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SwitchDlg", "\346\212\245\350\255\246/\346\226\255\347\224\265\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        baojingStautsLabel->setText(QApplication::translate("SwitchDlg", "----", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SwitchDlg", "\350\256\276\345\244\207\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("SwitchDlg", "----", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SwitchDlg", "\346\212\245\350\255\246\345\217\212\346\227\266\345\210\273", 0, QApplication::UnicodeUTF8));
        baojingLabel->setText(QApplication::translate("SwitchDlg", "----", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("SwitchDlg", "\346\226\255\347\224\265/\345\244\215\347\224\265\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        duandianLabel->setText(QApplication::translate("SwitchDlg", "----", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("SwitchDlg", "\351\246\210\347\224\265\347\212\266\346\200\201\345\217\212\346\227\266\345\210\273", 0, QApplication::UnicodeUTF8));
        kuidianLabel->setText(QApplication::translate("SwitchDlg", "----", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SwitchDlg", "\345\267\245\344\275\234\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        timeLabel->setText(QApplication::translate("SwitchDlg", "----", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SwitchDlg: public Ui_SwitchDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWITCHPROPERTYDLG_H
