/********************************************************************************
** Form generated from reading UI file 'registerdlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDLG_H
#define UI_REGISTERDLG_H

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

class Ui_registerForm
{
public:
    QPushButton *okButton;
    QPushButton *cancelButton;
    QGroupBox *groupBox;
    QLineEdit *usrLineEdit;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *pwdLineEdit;
    QLabel *label_3;
    QLineEdit *pwdLineEdit_confirm;

    void setupUi(QWidget *registerForm)
    {
        if (registerForm->objectName().isEmpty())
            registerForm->setObjectName(QString::fromUtf8("registerForm"));
        registerForm->resize(497, 421);
        registerForm->setMinimumSize(QSize(497, 421));
        registerForm->setMaximumSize(QSize(497, 421));
        registerForm->setStyleSheet(QString::fromUtf8("QWidget#registerForm\n"
"{\n"
"	\n"
"	background-image: url(:/login_image/Resources/login/register.jpg);\n"
"}"));
        okButton = new QPushButton(registerForm);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(120, 290, 111, 41));
        okButton->setStyleSheet(QString::fromUtf8("QPushButton#okButton\n"
"{\n"
"	\n"
"	\n"
"	\n"
"	border-image: url(:/login_image/Resources/login/register_confirm.jpg);\n"
"}"));
        cancelButton = new QPushButton(registerForm);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(280, 290, 111, 41));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton#cancelButton\n"
"{\n"
"\n"
"	\n"
"	\n"
"	border-image: url(:/login_image/Resources/login/register_cancel.jpg);\n"
"	\n"
"}"));
        groupBox = new QGroupBox(registerForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(100, 110, 311, 171));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        usrLineEdit = new QLineEdit(groupBox);
        usrLineEdit->setObjectName(QString::fromUtf8("usrLineEdit"));
        usrLineEdit->setGeometry(QRect(90, 27, 191, 31));
        usrLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{ \n"
"	border: 0px;\n"
"	background : (0x00,0xff,0x00,0x00);\n"
"	\n"
"}"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 67, 54, 41));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 27, 48, 31));
        pwdLineEdit = new QLineEdit(groupBox);
        pwdLineEdit->setObjectName(QString::fromUtf8("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(90, 70, 191, 31));
        pwdLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{ \n"
"	border: 0px;\n"
"	background : (0x00,0xff,0x00,0x00);\n"
"}"));
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 110, 54, 41));
        pwdLineEdit_confirm = new QLineEdit(groupBox);
        pwdLineEdit_confirm->setObjectName(QString::fromUtf8("pwdLineEdit_confirm"));
        pwdLineEdit_confirm->setGeometry(QRect(90, 110, 191, 31));
        pwdLineEdit_confirm->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{ \n"
"	border: 0px;\n"
"	background : (0x00,0xff,0x00,0x00);\n"
"}"));
        pwdLineEdit_confirm->setEchoMode(QLineEdit::Password);

        retranslateUi(registerForm);

        QMetaObject::connectSlotsByName(registerForm);
    } // setupUi

    void retranslateUi(QWidget *registerForm)
    {
        registerForm->setWindowTitle(QApplication::translate("registerForm", "\347\224\250\346\210\267\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        okButton->setText(QString());
        cancelButton->setText(QString());
        groupBox->setTitle(QString());
#ifndef QT_NO_STATUSTIP
        usrLineEdit->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        usrLineEdit->setText(QString());
        usrLineEdit->setPlaceholderText(QApplication::translate("registerForm", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("registerForm", "\345\257\206  \347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("registerForm", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        pwdLineEdit->setPlaceholderText(QApplication::translate("registerForm", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("registerForm", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        pwdLineEdit_confirm->setPlaceholderText(QApplication::translate("registerForm", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class registerForm: public Ui_registerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDLG_H
