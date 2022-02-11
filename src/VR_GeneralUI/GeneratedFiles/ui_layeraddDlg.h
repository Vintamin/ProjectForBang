/********************************************************************************
** Form generated from reading UI file 'layeraddDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAYERADDDLG_H
#define UI_LAYERADDDLG_H

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

class Ui_LayerAdd_UI
{
public:
    QGroupBox *groupBox;
    QLabel *label_2;
    QComboBox *releativeDataSet;
    QTextEdit *layerName;
    QLabel *label;
    QPushButton *handIn;
    QPushButton *cancel;
    QComboBox *layerType;
    QLabel *label_3;

    void setupUi(QWidget *LayerAdd_UI)
    {
        if (LayerAdd_UI->objectName().isEmpty())
            LayerAdd_UI->setObjectName(QString::fromUtf8("LayerAdd_UI"));
        LayerAdd_UI->resize(376, 199);
        LayerAdd_UI->setMinimumSize(QSize(376, 199));
        LayerAdd_UI->setMaximumSize(QSize(376, 199));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/resource/img/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        LayerAdd_UI->setWindowIcon(icon);
        groupBox = new QGroupBox(LayerAdd_UI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 361, 131));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 71, 16));
        releativeDataSet = new QComboBox(groupBox);
        releativeDataSet->setObjectName(QString::fromUtf8("releativeDataSet"));
        releativeDataSet->setGeometry(QRect(100, 70, 251, 31));
        layerName = new QTextEdit(groupBox);
        layerName->setObjectName(QString::fromUtf8("layerName"));
        layerName->setGeometry(QRect(100, 20, 251, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 54, 12));
        handIn = new QPushButton(LayerAdd_UI);
        handIn->setObjectName(QString::fromUtf8("handIn"));
        handIn->setGeometry(QRect(210, 160, 75, 31));
        cancel = new QPushButton(LayerAdd_UI);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(300, 160, 75, 31));
        layerType = new QComboBox(LayerAdd_UI);
        layerType->setObjectName(QString::fromUtf8("layerType"));
        layerType->setGeometry(QRect(510, 120, 231, 31));
        label_3 = new QLabel(LayerAdd_UI);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(520, 90, 71, 16));

        retranslateUi(LayerAdd_UI);
        QObject::connect(handIn, SIGNAL(clicked()), LayerAdd_UI, SLOT(slotHandIn()));
        QObject::connect(cancel, SIGNAL(clicked()), LayerAdd_UI, SLOT(slotCancel()));

        QMetaObject::connectSlotsByName(LayerAdd_UI);
    } // setupUi

    void retranslateUi(QWidget *LayerAdd_UI)
    {
        LayerAdd_UI->setWindowTitle(QApplication::translate("LayerAdd_UI", "\346\267\273\345\212\240\345\233\276\345\261\202", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("LayerAdd_UI", "\345\233\276\345\261\202\345\261\236\346\200\247", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LayerAdd_UI", "\345\205\263\350\201\224\346\225\260\346\215\256\351\233\206", 0, QApplication::UnicodeUTF8));
        layerName->setHtml(QApplication::translate("LayerAdd_UI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\226\260\345\233\276\345\261\202</p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LayerAdd_UI", "\345\233\276\345\261\202\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        handIn->setText(QApplication::translate("LayerAdd_UI", "\346\217\220\344\272\244", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("LayerAdd_UI", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        layerType->clear();
        layerType->insertItems(0, QStringList()
         << QApplication::translate("LayerAdd_UI", "\345\275\261\345\203\217", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LayerAdd_UI", "\346\225\260\345\255\227\351\253\230\347\250\213", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LayerAdd_UI", "\345\234\260\350\241\250\345\273\272\347\255\221", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LayerAdd_UI", "\345\267\267\351\201\223", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LayerAdd_UI", "\351\222\273\345\255\224", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LayerAdd_UI", "\347\205\244\345\261\202", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LayerAdd_UI", "\345\256\232\344\275\215\350\256\276\345\244\207", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LayerAdd_UI", "\347\233\221\346\265\213\350\256\276\345\244\207", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LayerAdd_UI", "\345\267\245\344\275\234\351\235\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LayerAdd_UI", "\346\226\255\345\261\202", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("LayerAdd_UI", "\345\233\276\345\261\202\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LayerAdd_UI: public Ui_LayerAdd_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAYERADDDLG_H
