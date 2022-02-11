/********************************************************************************
** Form generated from reading UI file 'safeevacuationroutedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAFEEVACUATIONROUTEDLG_H
#define UI_SAFEEVACUATIONROUTEDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_safeevacuationrouteForm
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *safeevacuationrouteForm)
    {
        if (safeevacuationrouteForm->objectName().isEmpty())
            safeevacuationrouteForm->setObjectName(QString::fromUtf8("safeevacuationrouteForm"));
        safeevacuationrouteForm->resize(530, 260);
        safeevacuationrouteForm->setMinimumSize(QSize(530, 260));
        safeevacuationrouteForm->setMaximumSize(QSize(530, 260));
        groupBox = new QGroupBox(safeevacuationrouteForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 371, 231));
        pushButton = new QPushButton(safeevacuationrouteForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 130, 91, 31));
        pushButton_2 = new QPushButton(safeevacuationrouteForm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 172, 91, 31));
        pushButton_3 = new QPushButton(safeevacuationrouteForm);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(410, 50, 91, 31));
        pushButton_4 = new QPushButton(safeevacuationrouteForm);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(410, 90, 91, 31));

        retranslateUi(safeevacuationrouteForm);

        QMetaObject::connectSlotsByName(safeevacuationrouteForm);
    } // setupUi

    void retranslateUi(QWidget *safeevacuationrouteForm)
    {
        safeevacuationrouteForm->setWindowTitle(QApplication::translate("safeevacuationrouteForm", "\345\256\211\345\205\250\351\201\277\351\232\276\350\267\257\347\272\277", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("safeevacuationrouteForm", "\347\273\230\345\233\276\345\214\272", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("safeevacuationrouteForm", "\347\241\256 \345\256\232", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("safeevacuationrouteForm", "\345\217\226 \346\266\210", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("safeevacuationrouteForm", "\347\273\230\345\210\266\351\201\277\351\232\276\350\267\257\347\272\277", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("safeevacuationrouteForm", "\345\257\274\345\205\245\351\201\277\351\232\276\350\267\257\347\272\277", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class safeevacuationrouteForm: public Ui_safeevacuationrouteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAFEEVACUATIONROUTEDLG_H
