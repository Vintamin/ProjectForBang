/********************************************************************************
** Form generated from reading UI file 'datasetpropertyDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATASETPROPERTYDLG_H
#define UI_DATASETPROPERTYDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataSetProperty_UI
{
public:
    QLabel *label;
    QTextEdit *textEdit;
    QGroupBox *groupBox;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *DataSetProperty_UI)
    {
        if (DataSetProperty_UI->objectName().isEmpty())
            DataSetProperty_UI->setObjectName(QString::fromUtf8("DataSetProperty_UI"));
        DataSetProperty_UI->resize(366, 440);
        label = new QLabel(DataSetProperty_UI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 71, 16));
        textEdit = new QTextEdit(DataSetProperty_UI);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(100, 30, 241, 31));
        groupBox = new QGroupBox(DataSetProperty_UI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 80, 331, 301));
        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 311, 271));
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(4);
        pushButton = new QPushButton(DataSetProperty_UI);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 400, 75, 23));
        pushButton_2 = new QPushButton(DataSetProperty_UI);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 400, 75, 23));

        retranslateUi(DataSetProperty_UI);

        QMetaObject::connectSlotsByName(DataSetProperty_UI);
    } // setupUi

    void retranslateUi(QWidget *DataSetProperty_UI)
    {
        DataSetProperty_UI->setWindowTitle(QApplication::translate("DataSetProperty_UI", "\346\225\260\346\215\256\351\233\206\345\261\236\346\200\247", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DataSetProperty_UI", "\346\225\260\346\215\256\351\233\206\345\220\215\347\247\260 ", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DataSetProperty_UI", "\346\225\260\346\215\256\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DataSetProperty_UI", "\346\217\220\344\272\244 ", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DataSetProperty_UI", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DataSetProperty_UI: public Ui_DataSetProperty_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATASETPROPERTYDLG_H
