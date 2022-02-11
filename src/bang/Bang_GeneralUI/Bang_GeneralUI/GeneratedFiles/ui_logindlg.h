/********************************************************************************
** Form generated from reading UI file 'logindlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginform
{
public:
    QLabel *namelabel;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *userCategoryCmb;
    QLineEdit *userLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginBtn;
    QPushButton *cancleBtn;

    void setupUi(QWidget *loginform)
    {
        if (loginform->objectName().isEmpty())
            loginform->setObjectName(QString::fromUtf8("loginform"));
        loginform->resize(548, 344);
        loginform->setMinimumSize(QSize(390, 300));
        loginform->setStyleSheet(QString::fromUtf8("QLabel#namelabel\n"
"{\n"
"	\n"
"	color: rgb(170, 255, 255);\n"
"	font: 20pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";\n"
"}\n"
"QWidget#loginform\n"
"{\n"
"	\n"
"	border-image: url(:/MyProject_ForBang/icon/\350\203\214\346\231\257.jpg);\n"
"}"));
        namelabel = new QLabel(loginform);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setGeometry(QRect(60, 20, 431, 51));
        namelabel->setIndent(3);
        groupBox = new QGroupBox(loginform);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(120, 90, 291, 171));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 40, 61, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 120, 61, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 80, 61, 16));
        userCategoryCmb = new QComboBox(groupBox);
        userCategoryCmb->setObjectName(QString::fromUtf8("userCategoryCmb"));
        userCategoryCmb->setGeometry(QRect(110, 30, 121, 22));
        userLineEdit = new QLineEdit(groupBox);
        userLineEdit->setObjectName(QString::fromUtf8("userLineEdit"));
        userLineEdit->setGeometry(QRect(110, 80, 121, 20));
        passwordLineEdit = new QLineEdit(groupBox);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(110, 120, 121, 20));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        loginBtn = new QPushButton(loginform);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setGeometry(QRect(150, 280, 71, 31));
        loginBtn->setStyleSheet(QString::fromUtf8("QPushButton#loginBtn\n"
"{\n"
"	\n"
"	background-color: rgb(11, 103, 168);\n"
"}\n"
"QPushButton#loginBtn:hover\n"
"{\n"
"	\n"
"	\n"
"	background-color: rgb(31, 153, 206);\n"
"}"));
        cancleBtn = new QPushButton(loginform);
        cancleBtn->setObjectName(QString::fromUtf8("cancleBtn"));
        cancleBtn->setGeometry(QRect(310, 280, 71, 31));
        cancleBtn->setStyleSheet(QString::fromUtf8("QPushButton#cancleBtn\n"
"{\n"
"	\n"
"	background-color: rgb(11, 103, 168);\n"
"}\n"
"QPushButton#cancleBtn:hover\n"
"{\n"
"	\n"
"	\n"
"	background-color: rgb(31, 153, 206);\n"
"}"));

        retranslateUi(loginform);

        QMetaObject::connectSlotsByName(loginform);
    } // setupUi

    void retranslateUi(QWidget *loginform)
    {
        loginform->setWindowTitle(QApplication::translate("loginform", "\346\231\272\350\203\275\347\237\277\345\261\261\347\210\206\347\240\264\350\256\276\350\256\241\344\270\216\346\226\275\345\267\245\347\256\241\347\220\206\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        namelabel->setText(QApplication::translate("loginform", "\346\231\272\350\203\275\347\237\277\345\261\261\347\210\206\347\240\264\350\256\276\350\256\241\344\270\216\346\226\275\345\267\245\347\256\241\347\220\206\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("loginform", "\347\224\250\346\210\267\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("loginform", "\347\224\250\346\210\267\347\261\273\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("loginform", "\347\224\250\346\210\267\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("loginform", "\347\224\250\346\210\267\345\220\215\347\247\260\357\274\232", 0, QApplication::UnicodeUTF8));
        userCategoryCmb->clear();
        userCategoryCmb->insertItems(0, QStringList()
         << QApplication::translate("loginform", "1.\350\256\276\350\256\241\344\272\272\345\221\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("loginform", "2.\346\226\275\345\267\245\347\256\241\347\220\206\344\272\272\345\221\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("loginform", "3.\346\231\256\351\200\232\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8)
        );
        loginBtn->setText(QApplication::translate("loginform", "\347\231\273  \351\231\206", 0, QApplication::UnicodeUTF8));
        cancleBtn->setText(QApplication::translate("loginform", "\351\200\200  \345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class loginform: public Ui_loginform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
