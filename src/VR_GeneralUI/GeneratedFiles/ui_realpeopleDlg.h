/********************************************************************************
** Form generated from reading UI file 'realpeopleDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALPEOPLEDLG_H
#define UI_REALPEOPLEDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_realpeoplewidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *peopleCountLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLabel *timeLabel;
    QTableWidget *peopleTableWidget;

    void setupUi(QWidget *realpeoplewidget)
    {
        if (realpeoplewidget->objectName().isEmpty())
            realpeoplewidget->setObjectName(QString::fromUtf8("realpeoplewidget"));
        realpeoplewidget->resize(421, 286);
        realpeoplewidget->setMinimumSize(QSize(421, 286));
        realpeoplewidget->setMaximumSize(QSize(421, 286));
        gridLayout = new QGridLayout(realpeoplewidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(realpeoplewidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(label);

        peopleCountLabel = new QLabel(realpeoplewidget);
        peopleCountLabel->setObjectName(QString::fromUtf8("peopleCountLabel"));

        horizontalLayout->addWidget(peopleCountLabel);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_3 = new QLabel(realpeoplewidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        timeLabel = new QLabel(realpeoplewidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        horizontalLayout_2->addWidget(timeLabel);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);

        peopleTableWidget = new QTableWidget(realpeoplewidget);
        if (peopleTableWidget->columnCount() < 7)
            peopleTableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        peopleTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        peopleTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        peopleTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        peopleTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        peopleTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        peopleTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        peopleTableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        peopleTableWidget->setObjectName(QString::fromUtf8("peopleTableWidget"));
        peopleTableWidget->setFrameShape(QFrame::Box);
        peopleTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        peopleTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        peopleTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        peopleTableWidget->setGridStyle(Qt::SolidLine);
        peopleTableWidget->horizontalHeader()->setVisible(true);
        peopleTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        peopleTableWidget->horizontalHeader()->setDefaultSectionSize(80);
        peopleTableWidget->horizontalHeader()->setMinimumSectionSize(21);
        peopleTableWidget->horizontalHeader()->setStretchLastSection(true);
        peopleTableWidget->verticalHeader()->setVisible(false);
        peopleTableWidget->verticalHeader()->setDefaultSectionSize(30);
        peopleTableWidget->verticalHeader()->setHighlightSections(true);
        peopleTableWidget->verticalHeader()->setMinimumSectionSize(21);
        peopleTableWidget->verticalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(peopleTableWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(realpeoplewidget);

        QMetaObject::connectSlotsByName(realpeoplewidget);
    } // setupUi

    void retranslateUi(QWidget *realpeoplewidget)
    {
        realpeoplewidget->setWindowTitle(QApplication::translate("realpeoplewidget", "\344\272\225\344\270\213\345\256\236\346\227\266\344\272\272\345\221\230", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("realpeoplewidget", "\344\272\225\344\270\213\346\200\273\344\272\272\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        peopleCountLabel->setText(QApplication::translate("realpeoplewidget", "0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("realpeoplewidget", "\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        timeLabel->setText(QApplication::translate("realpeoplewidget", "\342\200\224\342\200\224:\342\200\224\342\200\224", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = peopleTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("realpeoplewidget", "\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = peopleTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("realpeoplewidget", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = peopleTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("realpeoplewidget", "\347\261\273\345\210\253", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = peopleTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("realpeoplewidget", "\350\277\233\345\205\245\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = peopleTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("realpeoplewidget", "\347\246\273\345\274\200\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = peopleTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("realpeoplewidget", "\345\237\272\347\253\231\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = peopleTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("realpeoplewidget", "\345\215\241\345\217\267", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class realpeoplewidget: public Ui_realpeoplewidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALPEOPLEDLG_H
