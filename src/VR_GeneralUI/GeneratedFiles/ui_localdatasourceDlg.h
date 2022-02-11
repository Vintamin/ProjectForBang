/********************************************************************************
** Form generated from reading UI file 'localdatasourceDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALDATASOURCEDLG_H
#define UI_LOCALDATASOURCEDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataSourceConfig_UI
{
public:
    QGroupBox *groupBox;
    QPushButton *SelectAct;
    QTextEdit *dataSourcePath;
    QLabel *label;
    QLabel *label_2;
    QComboBox *dataSourceType;
    QPushButton *handIn;
    QPushButton *cancel;

    void setupUi(QWidget *DataSourceConfig_UI)
    {
        if (DataSourceConfig_UI->objectName().isEmpty())
            DataSourceConfig_UI->setObjectName(QString::fromUtf8("DataSourceConfig_UI"));
        DataSourceConfig_UI->resize(512, 214);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/resource/img/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        DataSourceConfig_UI->setWindowIcon(icon);
        groupBox = new QGroupBox(DataSourceConfig_UI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 491, 141));
        SelectAct = new QPushButton(groupBox);
        SelectAct->setObjectName(QString::fromUtf8("SelectAct"));
        SelectAct->setGeometry(QRect(410, 80, 61, 31));
        dataSourcePath = new QTextEdit(groupBox);
        dataSourcePath->setObjectName(QString::fromUtf8("dataSourcePath"));
        dataSourcePath->setGeometry(QRect(90, 80, 311, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 90, 61, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 61, 16));
        dataSourceType = new QComboBox(groupBox);
        dataSourceType->setObjectName(QString::fromUtf8("dataSourceType"));
        dataSourceType->setGeometry(QRect(90, 30, 311, 31));
        handIn = new QPushButton(DataSourceConfig_UI);
        handIn->setObjectName(QString::fromUtf8("handIn"));
        handIn->setGeometry(QRect(300, 170, 71, 31));
        cancel = new QPushButton(DataSourceConfig_UI);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(410, 170, 71, 31));

        retranslateUi(DataSourceConfig_UI);
        QObject::connect(SelectAct, SIGNAL(clicked()), DataSourceConfig_UI, SLOT(slotSelectDataSourcePath()));
        QObject::connect(handIn, SIGNAL(clicked()), DataSourceConfig_UI, SLOT(slotAccept()));
        QObject::connect(cancel, SIGNAL(clicked()), DataSourceConfig_UI, SLOT(slotCancel()));

        QMetaObject::connectSlotsByName(DataSourceConfig_UI);
    } // setupUi

    void retranslateUi(QWidget *DataSourceConfig_UI)
    {
        DataSourceConfig_UI->setWindowTitle(QApplication::translate("DataSourceConfig_UI", "\346\225\260\346\215\256\346\272\220\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DataSourceConfig_UI", "\346\234\254\345\234\260\346\225\260\346\215\256\346\272\220\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        SelectAct->setText(QApplication::translate("DataSourceConfig_UI", "\351\200\211\346\213\251..", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DataSourceConfig_UI", "\346\225\260\346\215\256\346\272\220\350\267\257\345\276\204", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DataSourceConfig_UI", "\346\225\260\346\215\256\346\272\220\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        dataSourceType->clear();
        dataSourceType->insertItems(0, QStringList()
         << QApplication::translate("DataSourceConfig_UI", "GDBT_SQLite", 0, QApplication::UnicodeUTF8)
        );
        handIn->setText(QApplication::translate("DataSourceConfig_UI", "\346\217\220\344\272\244", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("DataSourceConfig_UI", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DataSourceConfig_UI: public Ui_DataSourceConfig_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALDATASOURCEDLG_H
