/********************************************************************************
** Form generated from reading UI file 'querycoordination.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYCOORDINATION_H
#define UI_QUERYCOORDINATION_H

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

class Ui_QueryCoordinationForm
{
public:
    QPushButton *queryBtn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEditY;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEditZ;

    void setupUi(QWidget *QueryCoordinationForm)
    {
        if (QueryCoordinationForm->objectName().isEmpty())
            QueryCoordinationForm->setObjectName(QString::fromUtf8("QueryCoordinationForm"));
        QueryCoordinationForm->resize(500, 110);
        queryBtn = new QPushButton(QueryCoordinationForm);
        queryBtn->setObjectName(QString::fromUtf8("queryBtn"));
        queryBtn->setGeometry(QRect(380, 60, 101, 23));
        widget = new QWidget(QueryCoordinationForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 20, 455, 24));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditX = new QLineEdit(widget);
        lineEditX->setObjectName(QString::fromUtf8("lineEditX"));

        horizontalLayout->addWidget(lineEditX);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEditY = new QLineEdit(widget);
        lineEditY->setObjectName(QString::fromUtf8("lineEditY"));

        horizontalLayout_2->addWidget(lineEditY);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEditZ = new QLineEdit(widget);
        lineEditZ->setObjectName(QString::fromUtf8("lineEditZ"));

        horizontalLayout_3->addWidget(lineEditZ);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(QueryCoordinationForm);

        QMetaObject::connectSlotsByName(QueryCoordinationForm);
    } // setupUi

    void retranslateUi(QWidget *QueryCoordinationForm)
    {
        QueryCoordinationForm->setWindowTitle(QApplication::translate("QueryCoordinationForm", "\346\237\245\350\257\242\345\235\220\346\240\207", 0, QApplication::UnicodeUTF8));
        queryBtn->setText(QApplication::translate("QueryCoordinationForm", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QueryCoordinationForm", "X", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QueryCoordinationForm", "Y", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QueryCoordinationForm", "Z", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QueryCoordinationForm: public Ui_QueryCoordinationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYCOORDINATION_H
