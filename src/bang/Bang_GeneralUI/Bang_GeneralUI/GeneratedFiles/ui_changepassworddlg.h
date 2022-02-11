/********************************************************************************
** Form generated from reading UI file 'changepassworddlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORDDLG_H
#define UI_CHANGEPASSWORDDLG_H

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

class Ui_changePasswordForm
{
public:
    QGroupBox *groupBox;
    QLabel *label_4;
    QComboBox *userCategoryCmb;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QComboBox *genderCmb;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *oldPasswordLineEdit;
    QLineEdit *newPasswordLineEdit;
    QLineEdit *confirmNewPasswordLineEdit;
    QPushButton *confirmBtn;
    QPushButton *cancleBtn;

    void setupUi(QWidget *changePasswordForm)
    {
        if (changePasswordForm->objectName().isEmpty())
            changePasswordForm->setObjectName(QString::fromUtf8("changePasswordForm"));
        changePasswordForm->resize(400, 350);
        changePasswordForm->setMinimumSize(QSize(400, 350));
        changePasswordForm->setMaximumSize(QSize(400, 350));
        groupBox = new QGroupBox(changePasswordForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 321, 121));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 20, 71, 21));
        userCategoryCmb = new QComboBox(groupBox);
        userCategoryCmb->setObjectName(QString::fromUtf8("userCategoryCmb"));
        userCategoryCmb->setGeometry(QRect(90, 20, 131, 22));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 50, 51, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 80, 71, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(190, 50, 41, 21));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(60, 50, 101, 20));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(60, 80, 241, 20));
        genderCmb = new QComboBox(groupBox);
        genderCmb->setObjectName(QString::fromUtf8("genderCmb"));
        genderCmb->setGeometry(QRect(230, 50, 51, 20));
        label = new QLabel(changePasswordForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 170, 71, 16));
        label_2 = new QLabel(changePasswordForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 230, 71, 16));
        label_3 = new QLabel(changePasswordForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 200, 71, 16));
        oldPasswordLineEdit = new QLineEdit(changePasswordForm);
        oldPasswordLineEdit->setObjectName(QString::fromUtf8("oldPasswordLineEdit"));
        oldPasswordLineEdit->setGeometry(QRect(180, 170, 113, 20));
        oldPasswordLineEdit->setEchoMode(QLineEdit::Password);
        newPasswordLineEdit = new QLineEdit(changePasswordForm);
        newPasswordLineEdit->setObjectName(QString::fromUtf8("newPasswordLineEdit"));
        newPasswordLineEdit->setGeometry(QRect(180, 200, 113, 20));
        newPasswordLineEdit->setEchoMode(QLineEdit::Password);
        confirmNewPasswordLineEdit = new QLineEdit(changePasswordForm);
        confirmNewPasswordLineEdit->setObjectName(QString::fromUtf8("confirmNewPasswordLineEdit"));
        confirmNewPasswordLineEdit->setGeometry(QRect(180, 230, 113, 20));
        confirmNewPasswordLineEdit->setEchoMode(QLineEdit::Password);
        confirmBtn = new QPushButton(changePasswordForm);
        confirmBtn->setObjectName(QString::fromUtf8("confirmBtn"));
        confirmBtn->setGeometry(QRect(80, 270, 61, 31));
        cancleBtn = new QPushButton(changePasswordForm);
        cancleBtn->setObjectName(QString::fromUtf8("cancleBtn"));
        cancleBtn->setGeometry(QRect(260, 270, 61, 31));

        retranslateUi(changePasswordForm);

        QMetaObject::connectSlotsByName(changePasswordForm);
    } // setupUi

    void retranslateUi(QWidget *changePasswordForm)
    {
        changePasswordForm->setWindowTitle(QApplication::translate("changePasswordForm", "\345\257\206\347\240\201\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("changePasswordForm", "\345\257\206\347\240\201\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("changePasswordForm", "\347\224\250\346\210\267\347\261\273\345\236\213 :", 0, QApplication::UnicodeUTF8));
        userCategoryCmb->clear();
        userCategoryCmb->insertItems(0, QStringList()
         << QApplication::translate("changePasswordForm", "1.\350\256\276\350\256\241\344\272\272\345\221\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("changePasswordForm", "2.\346\226\275\345\267\245\347\256\241\347\220\206\344\272\272\345\221\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("changePasswordForm", "3.\346\231\256\351\200\232\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("changePasswordForm", "\345\247\223\345\220\215 :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("changePasswordForm", "\345\215\225\344\275\215 :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("changePasswordForm", "\346\200\247\345\210\253 :", 0, QApplication::UnicodeUTF8));
        genderCmb->clear();
        genderCmb->insertItems(0, QStringList()
         << QApplication::translate("changePasswordForm", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("changePasswordForm", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("changePasswordForm", "\346\227\247\345\257\206\347\240\201 :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("changePasswordForm", "\345\257\206\347\240\201\347\241\256\350\256\244:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("changePasswordForm", "\346\226\260\345\257\206\347\240\201 :", 0, QApplication::UnicodeUTF8));
        confirmBtn->setText(QApplication::translate("changePasswordForm", "\347\241\256  \345\256\232", 0, QApplication::UnicodeUTF8));
        cancleBtn->setText(QApplication::translate("changePasswordForm", "\345\217\226  \346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class changePasswordForm: public Ui_changePasswordForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORDDLG_H
