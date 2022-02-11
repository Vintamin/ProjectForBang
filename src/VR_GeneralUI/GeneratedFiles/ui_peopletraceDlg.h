/********************************************************************************
** Form generated from reading UI file 'peopletraceDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEOPLETRACEDLG_H
#define UI_PEOPLETRACEDLG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PeopleTraceWidget
{
public:
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QDateEdit *dateEditStart;
    QDateEdit *dateEditEnd;
    QComboBox *departmentCbb;
    QComboBox *nameCbb;
    QVBoxLayout *verticalLayout_3;
    QPushButton *showBtn;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QTableWidget *traceTable;

    void setupUi(QWidget *PeopleTraceWidget)
    {
        if (PeopleTraceWidget->objectName().isEmpty())
            PeopleTraceWidget->setObjectName(QString::fromUtf8("PeopleTraceWidget"));
        PeopleTraceWidget->resize(345, 311);
        PeopleTraceWidget->setMinimumSize(QSize(345, 311));
        PeopleTraceWidget->setMaximumSize(QSize(345, 311));
        gridLayout_3 = new QGridLayout(PeopleTraceWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(PeopleTraceWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(70, 16777215));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(70, 16777215));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(70, 16777215));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(70, 16777215));

        verticalLayout->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        dateEditStart = new QDateEdit(groupBox);
        dateEditStart->setObjectName(QString::fromUtf8("dateEditStart"));
        dateEditStart->setDate(QDate(2013, 8, 7));

        verticalLayout_2->addWidget(dateEditStart);

        dateEditEnd = new QDateEdit(groupBox);
        dateEditEnd->setObjectName(QString::fromUtf8("dateEditEnd"));
        dateEditEnd->setDate(QDate(2013, 8, 8));

        verticalLayout_2->addWidget(dateEditEnd);

        departmentCbb = new QComboBox(groupBox);
        departmentCbb->setObjectName(QString::fromUtf8("departmentCbb"));
        departmentCbb->setMinimumSize(QSize(120, 0));

        verticalLayout_2->addWidget(departmentCbb);

        nameCbb = new QComboBox(groupBox);
        nameCbb->setObjectName(QString::fromUtf8("nameCbb"));

        verticalLayout_2->addWidget(nameCbb);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        showBtn = new QPushButton(groupBox);
        showBtn->setObjectName(QString::fromUtf8("showBtn"));
        showBtn->setMaximumSize(QSize(65, 16777215));

        verticalLayout_3->addWidget(showBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(PeopleTraceWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        traceTable = new QTableWidget(groupBox_2);
        if (traceTable->columnCount() < 3)
            traceTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        traceTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        traceTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        traceTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        traceTable->setObjectName(QString::fromUtf8("traceTable"));
        traceTable->verticalHeader()->setVisible(false);

        gridLayout->addWidget(traceTable, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox_2);


        gridLayout_3->addLayout(verticalLayout_4, 0, 0, 1, 1);

        QWidget::setTabOrder(dateEditStart, dateEditEnd);
        QWidget::setTabOrder(dateEditEnd, departmentCbb);
        QWidget::setTabOrder(departmentCbb, nameCbb);
        QWidget::setTabOrder(nameCbb, showBtn);
        QWidget::setTabOrder(showBtn, traceTable);

        retranslateUi(PeopleTraceWidget);

        QMetaObject::connectSlotsByName(PeopleTraceWidget);
    } // setupUi

    void retranslateUi(QWidget *PeopleTraceWidget)
    {
        PeopleTraceWidget->setWindowTitle(QApplication::translate("PeopleTraceWidget", "\345\216\206\345\217\262\350\275\250\350\277\271\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("PeopleTraceWidget", "\350\265\267\345\247\213\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PeopleTraceWidget", "\347\273\223\346\235\237\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PeopleTraceWidget", "\351\203\250\351\227\250", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PeopleTraceWidget", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        departmentCbb->clear();
        departmentCbb->insertItems(0, QStringList()
         << QApplication::translate("PeopleTraceWidget", "\346\212\275\351\207\207\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\346\234\272\351\207\207\344\272\214\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\345\274\200\346\213\223\344\270\200\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\351\200\232\344\277\256\344\272\214\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\345\256\211\345\205\250\347\224\237\344\272\247\347\256\241\347\220\206\344\272\272\345\221\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\346\225\221\346\212\244", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\351\242\204\346\265\213\347\217\255", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\346\216\230\344\270\200\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\346\235\245\345\256\276", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\351\207\207\344\272\224\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\351\200\232\344\277\256\344\270\200\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\345\274\200\346\213\223\344\272\214\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\346\216\230\344\270\211\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\351\200\232\344\277\256\344\270\211\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\345\274\200\346\213\223\344\270\211\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\345\205\254\345\217\270\351\242\206\345\257\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\346\234\272\351\207\207\344\270\200\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\347\232\256\345\270\246\350\277\220\350\276\223\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\350\277\220\350\276\223\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\347\223\246\346\243\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\346\216\230\344\272\214\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\346\234\272\347\224\265\351\230\237", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PeopleTraceWidget", "\347\273\274\351\207\207\351\230\237", 0, QApplication::UnicodeUTF8)
        );
        showBtn->setText(QApplication::translate("PeopleTraceWidget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("PeopleTraceWidget", "\350\275\250\350\277\271\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = traceTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PeopleTraceWidget", "\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = traceTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PeopleTraceWidget", "\346\265\213\347\202\271\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = traceTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("PeopleTraceWidget", "\345\210\260\350\276\276\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PeopleTraceWidget: public Ui_PeopleTraceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEOPLETRACEDLG_H
