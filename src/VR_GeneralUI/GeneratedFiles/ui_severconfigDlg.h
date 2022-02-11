/********************************************************************************
** Form generated from reading UI file 'severconfigDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEVERCONFIGDLG_H
#define UI_SEVERCONFIGDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SeverConfigWidget
{
public:
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QComboBox *typeCbb;
    QLineEdit *severtext;
    QLineEdit *usertext;
    QLineEdit *passwordtext;
    QLineEdit *databasetext;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *simutext;
    QLineEdit *switchtext;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *okbtn;
    QPushButton *cancelbtn;

    void setupUi(QWidget *SeverConfigWidget)
    {
        if (SeverConfigWidget->objectName().isEmpty())
            SeverConfigWidget->setObjectName(QString::fromUtf8("SeverConfigWidget"));
        SeverConfigWidget->resize(315, 307);
        SeverConfigWidget->setMinimumSize(QSize(315, 307));
        SeverConfigWidget->setMaximumSize(QSize(315, 307));
        SeverConfigWidget->setWindowOpacity(1);
        SeverConfigWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(SeverConfigWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox = new QGroupBox(SeverConfigWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        typeCbb = new QComboBox(groupBox);
        typeCbb->setObjectName(QString::fromUtf8("typeCbb"));

        verticalLayout_2->addWidget(typeCbb);

        severtext = new QLineEdit(groupBox);
        severtext->setObjectName(QString::fromUtf8("severtext"));

        verticalLayout_2->addWidget(severtext);

        usertext = new QLineEdit(groupBox);
        usertext->setObjectName(QString::fromUtf8("usertext"));

        verticalLayout_2->addWidget(usertext);

        passwordtext = new QLineEdit(groupBox);
        passwordtext->setObjectName(QString::fromUtf8("passwordtext"));
        passwordtext->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(passwordtext);

        databasetext = new QLineEdit(groupBox);
        databasetext->setObjectName(QString::fromUtf8("databasetext"));

        verticalLayout_2->addWidget(databasetext);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SeverConfigWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_3->addWidget(label_7);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        simutext = new QLineEdit(groupBox_2);
        simutext->setObjectName(QString::fromUtf8("simutext"));

        verticalLayout_4->addWidget(simutext);

        switchtext = new QLineEdit(groupBox_2);
        switchtext->setObjectName(QString::fromUtf8("switchtext"));

        verticalLayout_4->addWidget(switchtext);


        horizontalLayout_2->addLayout(verticalLayout_4);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox_2);


        verticalLayout_6->addLayout(verticalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        okbtn = new QPushButton(SeverConfigWidget);
        okbtn->setObjectName(QString::fromUtf8("okbtn"));
        okbtn->setMaximumSize(QSize(66, 16777215));

        horizontalLayout_3->addWidget(okbtn);

        cancelbtn = new QPushButton(SeverConfigWidget);
        cancelbtn->setObjectName(QString::fromUtf8("cancelbtn"));
        cancelbtn->setMaximumSize(QSize(66, 16777215));

        horizontalLayout_3->addWidget(cancelbtn);


        verticalLayout_6->addLayout(horizontalLayout_3);


        gridLayout_3->addLayout(verticalLayout_6, 0, 0, 1, 1);

        QWidget::setTabOrder(typeCbb, severtext);
        QWidget::setTabOrder(severtext, usertext);
        QWidget::setTabOrder(usertext, passwordtext);
        QWidget::setTabOrder(passwordtext, databasetext);
        QWidget::setTabOrder(databasetext, simutext);
        QWidget::setTabOrder(simutext, switchtext);
        QWidget::setTabOrder(switchtext, okbtn);
        QWidget::setTabOrder(okbtn, cancelbtn);

        retranslateUi(SeverConfigWidget);

        QMetaObject::connectSlotsByName(SeverConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *SeverConfigWidget)
    {
        SeverConfigWidget->setWindowTitle(QApplication::translate("SeverConfigWidget", "\350\277\234\347\250\213\346\225\260\346\215\256\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SeverConfigWidget", "\346\225\260\346\215\256\345\272\223\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SeverConfigWidget", "\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SeverConfigWidget", "\346\234\215\345\212\241\345\231\250", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SeverConfigWidget", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SeverConfigWidget", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SeverConfigWidget", "\346\225\260\346\215\256\345\272\223", 0, QApplication::UnicodeUTF8));
        typeCbb->clear();
        typeCbb->insertItems(0, QStringList()
         << QApplication::translate("SeverConfigWidget", "SQL SERVER", 0, QApplication::UnicodeUTF8)
        );
        groupBox_2->setTitle(QApplication::translate("SeverConfigWidget", "\345\256\236\346\227\266\346\225\260\346\215\256\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SeverConfigWidget", "\346\250\241\346\213\237\351\207\217", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SeverConfigWidget", "\345\274\200\345\205\263\351\207\217", 0, QApplication::UnicodeUTF8));
        okbtn->setText(QApplication::translate("SeverConfigWidget", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        cancelbtn->setText(QApplication::translate("SeverConfigWidget", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SeverConfigWidget: public Ui_SeverConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEVERCONFIGDLG_H
