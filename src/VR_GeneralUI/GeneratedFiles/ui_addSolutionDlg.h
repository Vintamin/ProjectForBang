/********************************************************************************
** Form generated from reading UI file 'addSolutionDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSOLUTIONDLG_H
#define UI_ADDSOLUTIONDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addSolutionDlg
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *selectPathButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *openSolutionPathButton;
    QPushButton *closeSolutionButton;

    void setupUi(QWidget *addSolutionDlg)
    {
        if (addSolutionDlg->objectName().isEmpty())
            addSolutionDlg->setObjectName(QString::fromUtf8("addSolutionDlg"));
        addSolutionDlg->resize(409, 154);
        addSolutionDlg->setMaximumSize(QSize(409, 154));
        layoutWidget = new QWidget(addSolutionDlg);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 40, 351, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        selectPathButton = new QPushButton(layoutWidget);
        selectPathButton->setObjectName(QString::fromUtf8("selectPathButton"));

        horizontalLayout->addWidget(selectPathButton);

        layoutWidget1 = new QWidget(addSolutionDlg);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(110, 90, 271, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        openSolutionPathButton = new QPushButton(layoutWidget1);
        openSolutionPathButton->setObjectName(QString::fromUtf8("openSolutionPathButton"));

        horizontalLayout_2->addWidget(openSolutionPathButton);

        closeSolutionButton = new QPushButton(layoutWidget1);
        closeSolutionButton->setObjectName(QString::fromUtf8("closeSolutionButton"));

        horizontalLayout_2->addWidget(closeSolutionButton);


        retranslateUi(addSolutionDlg);

        QMetaObject::connectSlotsByName(addSolutionDlg);
    } // setupUi

    void retranslateUi(QWidget *addSolutionDlg)
    {
        addSolutionDlg->setWindowTitle(QApplication::translate("addSolutionDlg", "\346\225\221\346\217\264\346\226\271\346\241\210\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("addSolutionDlg", "\350\247\243\345\206\263\346\226\271\346\241\210\350\267\257\345\276\204", 0, QApplication::UnicodeUTF8));
        selectPathButton->setText(QApplication::translate("addSolutionDlg", "\346\265\217\350\247\210", 0, QApplication::UnicodeUTF8));
        openSolutionPathButton->setText(QApplication::translate("addSolutionDlg", "\346\230\276\347\244\272\350\247\243\345\206\263\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
        closeSolutionButton->setText(QApplication::translate("addSolutionDlg", "\345\205\263\351\227\255\350\247\243\345\206\263\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class addSolutionDlg: public Ui_addSolutionDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSOLUTIONDLG_H
