/********************************************************************************
** Form generated from reading UI file 'queryLanewayByName.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYLANEWAYBYNAME_H
#define UI_QUERYLANEWAYBYNAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_queryLanewayForm
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *queryBtn;
    QSpacerItem *horizontalSpacer;
    QComboBox *queryLanewayCmb;

    void setupUi(QWidget *queryLanewayForm)
    {
        if (queryLanewayForm->objectName().isEmpty())
            queryLanewayForm->setObjectName(QString::fromUtf8("queryLanewayForm"));
        queryLanewayForm->resize(477, 89);
        queryLanewayForm->setMinimumSize(QSize(471, 85));
        widget = new QWidget(queryLanewayForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 20, 393, 54));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(250, 23));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        queryBtn = new QPushButton(widget);
        queryBtn->setObjectName(QString::fromUtf8("queryBtn"));

        gridLayout->addWidget(queryBtn, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        queryLanewayCmb = new QComboBox(widget);
        queryLanewayCmb->setObjectName(QString::fromUtf8("queryLanewayCmb"));
        queryLanewayCmb->setMinimumSize(QSize(250, 23));
        queryLanewayCmb->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(queryLanewayCmb, 1, 1, 1, 1);


        retranslateUi(queryLanewayForm);

        QMetaObject::connectSlotsByName(queryLanewayForm);
    } // setupUi

    void retranslateUi(QWidget *queryLanewayForm)
    {
        queryLanewayForm->setWindowTitle(QApplication::translate("queryLanewayForm", "\346\237\245\350\257\242\345\267\267\351\201\223", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("queryLanewayForm", "\345\267\267\351\201\223\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        queryBtn->setText(QApplication::translate("queryLanewayForm", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class queryLanewayForm: public Ui_queryLanewayForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYLANEWAYBYNAME_H
