/********************************************************************************
** Form generated from reading UI file 'propertyquerydlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTYQUERYDLG_H
#define UI_PROPERTYQUERYDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *propertyQueryBtn;
    QPushButton *clearQueryBtn;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(224, 116);
        propertyQueryBtn = new QPushButton(Form);
        propertyQueryBtn->setObjectName(QString::fromUtf8("propertyQueryBtn"));
        propertyQueryBtn->setGeometry(QRect(20, 20, 75, 61));
        propertyQueryBtn->setStyleSheet(QString::fromUtf8("QPushButton#propertyQueryBtn\n"
"{\n"
"	\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/selectBy.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#propertyQueryBtn:hover\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/selectBy.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#propertyQueryBtn:pressed\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/selectBy.png);\n"
"	\n"
"	\n"
"}"));
        clearQueryBtn = new QPushButton(Form);
        clearQueryBtn->setObjectName(QString::fromUtf8("clearQueryBtn"));
        clearQueryBtn->setGeometry(QRect(120, 20, 75, 61));
        clearQueryBtn->setStyleSheet(QString::fromUtf8("QPushButton#clearQueryBtn\n"
"{\n"
"	\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/clear.png);\n"
"	\n"
"}\n"
"QPushButton#clearQueryBtn:hover\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/clear.png);\n"
"	\n"
"}\n"
"QPushButton#clearQueryBtn:pressed\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/clear.png);\n"
"	\n"
"}"));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 90, 54, 12));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 90, 54, 12));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "\345\261\236\346\200\247\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        propertyQueryBtn->setText(QString());
        clearQueryBtn->setText(QString());
        label->setText(QApplication::translate("Form", " \345\261\236\346\200\247\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", " \346\270\205\351\231\244\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTYQUERYDLG_H
