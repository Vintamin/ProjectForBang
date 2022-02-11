/********************************************************************************
** Form generated from reading UI file 'createnewsceneDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWSCENEDLG_H
#define UI_CREATENEWSCENEDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateNewScene_UI
{
public:
    QLabel *label;
    QTextEdit *sceneName;
    QGroupBox *groupBox;
    QLabel *label_2;
    QComboBox *coorSysType;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *refereneceX;
    QDoubleSpinBox *refereneceY;
    QDoubleSpinBox *refereneceZ;
    QPushButton *handIn;
    QPushButton *cancel;

    void setupUi(QWidget *CreateNewScene_UI)
    {
        if (CreateNewScene_UI->objectName().isEmpty())
            CreateNewScene_UI->setObjectName(QString::fromUtf8("CreateNewScene_UI"));
        CreateNewScene_UI->resize(332, 323);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/resource/img/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        CreateNewScene_UI->setWindowIcon(icon);
        label = new QLabel(CreateNewScene_UI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 54, 12));
        sceneName = new QTextEdit(CreateNewScene_UI);
        sceneName->setObjectName(QString::fromUtf8("sceneName"));
        sceneName->setGeometry(QRect(80, 30, 221, 31));
        groupBox = new QGroupBox(CreateNewScene_UI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 80, 311, 191));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 54, 12));
        coorSysType = new QComboBox(groupBox);
        coorSysType->setObjectName(QString::fromUtf8("coorSysType"));
        coorSysType->setGeometry(QRect(70, 30, 221, 31));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 80, 81, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(170, 120, 21, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 160, 21, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 120, 21, 16));
        refereneceX = new QDoubleSpinBox(groupBox);
        refereneceX->setObjectName(QString::fromUtf8("refereneceX"));
        refereneceX->setGeometry(QRect(190, 120, 101, 22));
        refereneceX->setMaximum(1e+09);
        refereneceX->setValue(3.75389e+07);
        refereneceY = new QDoubleSpinBox(groupBox);
        refereneceY->setObjectName(QString::fromUtf8("refereneceY"));
        refereneceY->setGeometry(QRect(50, 160, 101, 22));
        refereneceY->setMinimum(-500);
        refereneceY->setMaximum(10000);
        refereneceY->setValue(156.42);
        refereneceZ = new QDoubleSpinBox(groupBox);
        refereneceZ->setObjectName(QString::fromUtf8("refereneceZ"));
        refereneceZ->setGeometry(QRect(50, 120, 101, 22));
        refereneceZ->setMinimum(-500);
        refereneceZ->setMaximum(1e+09);
        refereneceZ->setValue(3.0624e+06);
        handIn = new QPushButton(CreateNewScene_UI);
        handIn->setObjectName(QString::fromUtf8("handIn"));
        handIn->setGeometry(QRect(120, 280, 75, 31));
        cancel = new QPushButton(CreateNewScene_UI);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(230, 280, 75, 31));

        retranslateUi(CreateNewScene_UI);
        QObject::connect(handIn, SIGNAL(clicked()), CreateNewScene_UI, SLOT(slotHandIn()));
        QObject::connect(cancel, SIGNAL(clicked()), CreateNewScene_UI, SLOT(slotCancel()));

        QMetaObject::connectSlotsByName(CreateNewScene_UI);
    } // setupUi

    void retranslateUi(QWidget *CreateNewScene_UI)
    {
        CreateNewScene_UI->setWindowTitle(QApplication::translate("CreateNewScene_UI", "\346\226\260\345\273\272\345\234\272\346\231\257", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateNewScene_UI", "\345\234\272\346\231\257\345\220\215\347\247\260 ", 0, QApplication::UnicodeUTF8));
        sceneName->setHtml(QApplication::translate("CreateNewScene_UI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\226\260\345\234\272\346\231\257</p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CreateNewScene_UI", "\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CreateNewScene_UI", "\345\235\220\346\240\207\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        coorSysType->clear();
        coorSysType->insertItems(0, QStringList()
         << QApplication::translate("CreateNewScene_UI", "Xian1980", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("CreateNewScene_UI", "\345\235\220\346\240\207\345\217\202\350\200\203\344\270\255\345\277\203", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CreateNewScene_UI", "Y:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CreateNewScene_UI", "Z:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CreateNewScene_UI", "X:", 0, QApplication::UnicodeUTF8));
        handIn->setText(QApplication::translate("CreateNewScene_UI", "\346\217\220\344\272\244", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("CreateNewScene_UI", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateNewScene_UI: public Ui_CreateNewScene_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWSCENEDLG_H
