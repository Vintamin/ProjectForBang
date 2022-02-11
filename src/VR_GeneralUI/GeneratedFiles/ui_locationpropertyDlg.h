/********************************************************************************
** Form generated from reading UI file 'locationpropertyDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCATIONPROPERTYDLG_H
#define UI_LOCATIONPROPERTYDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LocationPropertyWidget
{
public:
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *stationIdText;
    QLabel *peopleText;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *cardIdText00;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_4;
    QLabel *cardIdText;
    QLabel *addressText;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QTableWidget *infosTable;

    void setupUi(QWidget *LocationPropertyWidget)
    {
        if (LocationPropertyWidget->objectName().isEmpty())
            LocationPropertyWidget->setObjectName(QString::fromUtf8("LocationPropertyWidget"));
        LocationPropertyWidget->resize(297, 279);
        LocationPropertyWidget->setMinimumSize(QSize(297, 279));
        LocationPropertyWidget->setMaximumSize(QSize(297, 279));
        gridLayout_3 = new QGridLayout(LocationPropertyWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox = new QGroupBox(LocationPropertyWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 70));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(9, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(50, 16777215));

        verticalLayout->addWidget(label);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(50, 16777215));

        verticalLayout->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        stationIdText = new QLabel(groupBox);
        stationIdText->setObjectName(QString::fromUtf8("stationIdText"));

        verticalLayout_2->addWidget(stationIdText);

        peopleText = new QLabel(groupBox);
        peopleText->setObjectName(QString::fromUtf8("peopleText"));

        verticalLayout_2->addWidget(peopleText);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        cardIdText00 = new QLabel(groupBox);
        cardIdText00->setObjectName(QString::fromUtf8("cardIdText00"));

        verticalLayout_3->addWidget(cardIdText00);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(50, 16777215));

        verticalLayout_3->addWidget(label_7);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        cardIdText = new QLabel(groupBox);
        cardIdText->setObjectName(QString::fromUtf8("cardIdText"));

        verticalLayout_4->addWidget(cardIdText);

        addressText = new QLabel(groupBox);
        addressText->setObjectName(QString::fromUtf8("addressText"));

        verticalLayout_4->addWidget(addressText);


        horizontalLayout_2->addLayout(verticalLayout_4);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(LocationPropertyWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        infosTable = new QTableWidget(groupBox_2);
        if (infosTable->columnCount() < 4)
            infosTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        infosTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        infosTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        infosTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        infosTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        infosTable->setObjectName(QString::fromUtf8("infosTable"));
        infosTable->verticalHeader()->setVisible(false);

        gridLayout->addWidget(infosTable, 0, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox_2);


        gridLayout_3->addLayout(verticalLayout_5, 0, 0, 1, 1);


        retranslateUi(LocationPropertyWidget);

        QMetaObject::connectSlotsByName(LocationPropertyWidget);
    } // setupUi

    void retranslateUi(QWidget *LocationPropertyWidget)
    {
        LocationPropertyWidget->setWindowTitle(QApplication::translate("LocationPropertyWidget", "\350\257\273\345\215\241\345\231\250\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("LocationPropertyWidget", "\345\237\272\346\234\254\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LocationPropertyWidget", "\345\210\206\347\253\231\345\217\267", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("LocationPropertyWidget", "\346\200\273\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        stationIdText->setText(QString());
        peopleText->setText(QString());
        cardIdText00->setText(QApplication::translate("LocationPropertyWidget", "\350\256\276\345\244\207\345\217\267", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("LocationPropertyWidget", "\345\256\211\350\243\205\345\234\260\347\202\271", 0, QApplication::UnicodeUTF8));
        cardIdText->setText(QString());
        addressText->setText(QString());
        groupBox_2->setTitle(QApplication::translate("LocationPropertyWidget", "\344\272\272\345\221\230\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = infosTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("LocationPropertyWidget", "\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = infosTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("LocationPropertyWidget", "\345\215\241\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = infosTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("LocationPropertyWidget", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = infosTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("LocationPropertyWidget", "\345\210\260\350\276\276\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LocationPropertyWidget: public Ui_LocationPropertyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCATIONPROPERTYDLG_H
