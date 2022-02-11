/********************************************************************************
** Form generated from reading UI file 'openprojectdlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENPROJECTDLG_H
#define UI_OPENPROJECTDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_openProjectForm
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *IDlineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_2;
    QTableWidget *tableWidget;
    QPushButton *onOKPushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *openProjectForm)
    {
        if (openProjectForm->objectName().isEmpty())
            openProjectForm->setObjectName(QString::fromUtf8("openProjectForm"));
        openProjectForm->resize(583, 375);
        openProjectForm->setMinimumSize(QSize(583, 375));
        openProjectForm->setMaximumSize(QSize(583, 375));
        groupBox = new QGroupBox(openProjectForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 351, 111));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 22, 54, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 50, 54, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 80, 54, 21));
        IDlineEdit = new QLineEdit(groupBox);
        IDlineEdit->setObjectName(QString::fromUtf8("IDlineEdit"));
        IDlineEdit->setGeometry(QRect(80, 20, 113, 20));
        nameLineEdit = new QLineEdit(groupBox);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(80, 50, 113, 20));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(80, 80, 113, 20));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(220, 50, 113, 20));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 20, 75, 23));
        groupBox_2 = new QGroupBox(openProjectForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 140, 561, 181));
        tableWidget = new QTableWidget(groupBox_2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 541, 151));
        onOKPushButton = new QPushButton(openProjectForm);
        onOKPushButton->setObjectName(QString::fromUtf8("onOKPushButton"));
        onOKPushButton->setGeometry(QRect(110, 330, 61, 31));
        pushButton_2 = new QPushButton(openProjectForm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 330, 61, 31));

        retranslateUi(openProjectForm);

        QMetaObject::connectSlotsByName(openProjectForm);
    } // setupUi

    void retranslateUi(QWidget *openProjectForm)
    {
        openProjectForm->setWindowTitle(QApplication::translate("openProjectForm", "\346\211\223\345\274\200\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("openProjectForm", "\346\211\223\345\274\200\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("openProjectForm", "\345\267\245\347\250\213ID", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("openProjectForm", "\345\267\245\347\250\213\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("openProjectForm", "\345\267\267\351\201\223\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        lineEdit_4->setText(QApplication::translate("openProjectForm", "\346\243\200\347\264\242", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("openProjectForm", "\351\200\211\346\213\251\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("openProjectForm", "\345\267\245\347\250\213\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        onOKPushButton->setText(QApplication::translate("openProjectForm", "\347\241\256  \345\256\232", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("openProjectForm", "\345\217\226  \346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class openProjectForm: public Ui_openProjectForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENPROJECTDLG_H
