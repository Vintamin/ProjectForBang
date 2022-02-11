/********************************************************************************
** Form generated from reading UI file 'modelpropertyDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELPROPERTYDLG_H
#define UI_MODELPROPERTYDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelProperty_UI
{
public:
    QLabel *label;
    QTextEdit *modelName;
    QPushButton *handIn;
    QPushButton *cancel;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QDoubleSpinBox *pos_x;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label_13;
    QLabel *label_8;
    QDoubleSpinBox *pos_y;
    QLabel *label_5;
    QLabel *label_2;
    QDoubleSpinBox *pos_z;
    QDoubleSpinBox *rotate_y;
    QDoubleSpinBox *scale_y;
    QLabel *label_4;
    QLabel *label_11;
    QLabel *label_9;
    QDoubleSpinBox *rotate_x;
    QLabel *label_7;
    QLabel *label_12;
    QLabel *label_3;
    QDoubleSpinBox *rotate_z;
    QDoubleSpinBox *scale_z;
    QDoubleSpinBox *scale_x;
    QWidget *tab_2;
    QLabel *label_14;
    QComboBox *modelLib;
    QPushButton *posSelcted;

    void setupUi(QWidget *ModelProperty_UI)
    {
        if (ModelProperty_UI->objectName().isEmpty())
            ModelProperty_UI->setObjectName(QString::fromUtf8("ModelProperty_UI"));
        ModelProperty_UI->resize(388, 417);
        label = new QLabel(ModelProperty_UI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 54, 12));
        modelName = new QTextEdit(ModelProperty_UI);
        modelName->setObjectName(QString::fromUtf8("modelName"));
        modelName->setGeometry(QRect(80, 20, 261, 31));
        handIn = new QPushButton(ModelProperty_UI);
        handIn->setObjectName(QString::fromUtf8("handIn"));
        handIn->setGeometry(QRect(180, 370, 75, 31));
        cancel = new QPushButton(ModelProperty_UI);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(290, 370, 75, 31));
        tabWidget = new QTabWidget(ModelProperty_UI);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 110, 361, 251));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        pos_x = new QDoubleSpinBox(tab_1);
        pos_x->setObjectName(QString::fromUtf8("pos_x"));
        pos_x->setGeometry(QRect(50, 50, 62, 22));
        pos_x->setMinimum(-10000);
        pos_x->setMaximum(10000);
        label_10 = new QLabel(tab_1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(260, 190, 41, 16));
        label_6 = new QLabel(tab_1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(260, 120, 41, 16));
        label_13 = new QLabel(tab_1);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 160, 41, 16));
        label_8 = new QLabel(tab_1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 120, 41, 16));
        pos_y = new QDoubleSpinBox(tab_1);
        pos_y->setObjectName(QString::fromUtf8("pos_y"));
        pos_y->setGeometry(QRect(170, 50, 62, 22));
        pos_y->setMinimum(-10000);
        pos_y->setMaximum(10000);
        label_5 = new QLabel(tab_1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(260, 50, 41, 16));
        label_2 = new QLabel(tab_1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 41, 16));
        pos_z = new QDoubleSpinBox(tab_1);
        pos_z->setObjectName(QString::fromUtf8("pos_z"));
        pos_z->setGeometry(QRect(290, 50, 62, 22));
        pos_z->setMinimum(-10000);
        pos_z->setMaximum(10000);
        rotate_y = new QDoubleSpinBox(tab_1);
        rotate_y->setObjectName(QString::fromUtf8("rotate_y"));
        rotate_y->setGeometry(QRect(170, 120, 62, 22));
        rotate_y->setMinimum(-360);
        rotate_y->setMaximum(360);
        scale_y = new QDoubleSpinBox(tab_1);
        scale_y->setObjectName(QString::fromUtf8("scale_y"));
        scale_y->setGeometry(QRect(170, 190, 62, 22));
        scale_y->setMaximum(1000);
        scale_y->setSingleStep(0.1);
        scale_y->setValue(1);
        label_4 = new QLabel(tab_1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 50, 41, 16));
        label_11 = new QLabel(tab_1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 190, 41, 16));
        label_9 = new QLabel(tab_1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(140, 120, 41, 16));
        rotate_x = new QDoubleSpinBox(tab_1);
        rotate_x->setObjectName(QString::fromUtf8("rotate_x"));
        rotate_x->setGeometry(QRect(50, 120, 62, 22));
        rotate_x->setMinimum(-360);
        rotate_x->setMaximum(360);
        label_7 = new QLabel(tab_1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 90, 41, 16));
        label_12 = new QLabel(tab_1);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(140, 190, 41, 16));
        label_3 = new QLabel(tab_1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 50, 41, 16));
        rotate_z = new QDoubleSpinBox(tab_1);
        rotate_z->setObjectName(QString::fromUtf8("rotate_z"));
        rotate_z->setGeometry(QRect(290, 120, 62, 22));
        rotate_z->setMaximum(360);
        scale_z = new QDoubleSpinBox(tab_1);
        scale_z->setObjectName(QString::fromUtf8("scale_z"));
        scale_z->setGeometry(QRect(290, 190, 62, 22));
        scale_z->setSingleStep(0.1);
        scale_z->setValue(1);
        scale_x = new QDoubleSpinBox(tab_1);
        scale_x->setObjectName(QString::fromUtf8("scale_x"));
        scale_x->setGeometry(QRect(50, 190, 62, 22));
        scale_x->setMaximum(1000);
        scale_x->setSingleStep(0.1);
        scale_x->setValue(1);
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        label_14 = new QLabel(ModelProperty_UI);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 70, 71, 16));
        modelLib = new QComboBox(ModelProperty_UI);
        modelLib->setObjectName(QString::fromUtf8("modelLib"));
        modelLib->setGeometry(QRect(80, 70, 261, 22));
        posSelcted = new QPushButton(ModelProperty_UI);
        posSelcted->setObjectName(QString::fromUtf8("posSelcted"));
        posSelcted->setGeometry(QRect(70, 370, 75, 31));

        retranslateUi(ModelProperty_UI);
        QObject::connect(pos_x, SIGNAL(valueChanged(double)), ModelProperty_UI, SLOT(slotPosXChanged(double)));
        QObject::connect(pos_y, SIGNAL(valueChanged(double)), ModelProperty_UI, SLOT(slotPosYChanged(double)));
        QObject::connect(pos_z, SIGNAL(valueChanged(double)), ModelProperty_UI, SLOT(slotPosZChanged(double)));
        QObject::connect(rotate_x, SIGNAL(valueChanged(double)), ModelProperty_UI, SLOT(slotRoateXChanged(double)));
        QObject::connect(rotate_y, SIGNAL(valueChanged(double)), ModelProperty_UI, SLOT(slotRoateYChanged(double)));
        QObject::connect(rotate_z, SIGNAL(valueChanged(double)), ModelProperty_UI, SLOT(slotRoateZChanged(double)));
        QObject::connect(scale_x, SIGNAL(valueChanged(double)), ModelProperty_UI, SLOT(slotScaleXChanged(double)));
        QObject::connect(scale_y, SIGNAL(valueChanged(double)), ModelProperty_UI, SLOT(slotScaleYChanged(double)));
        QObject::connect(scale_z, SIGNAL(valueChanged(double)), ModelProperty_UI, SLOT(slotScaleZChanged(double)));
        QObject::connect(handIn, SIGNAL(clicked()), ModelProperty_UI, SLOT(slotHandIn()));
        QObject::connect(cancel, SIGNAL(clicked()), ModelProperty_UI, SLOT(slotCancel()));
        QObject::connect(posSelcted, SIGNAL(clicked()), ModelProperty_UI, SLOT(slotPosSelected()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ModelProperty_UI);
    } // setupUi

    void retranslateUi(QWidget *ModelProperty_UI)
    {
        ModelProperty_UI->setWindowTitle(QApplication::translate("ModelProperty_UI", "\346\250\241\345\236\213\345\261\236\346\200\247", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ModelProperty_UI", "\346\250\241\345\236\213\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        modelName->setHtml(QApplication::translate("ModelProperty_UI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\226\260\346\250\241\345\236\213</p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        handIn->setText(QApplication::translate("ModelProperty_UI", "\346\217\220\344\272\244", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("ModelProperty_UI", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ModelProperty_UI", "Z:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ModelProperty_UI", "Z:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("ModelProperty_UI", "\347\274\251\346\224\276", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ModelProperty_UI", "X:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ModelProperty_UI", "Z:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ModelProperty_UI", "\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ModelProperty_UI", "Y:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ModelProperty_UI", "X:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ModelProperty_UI", "Y:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ModelProperty_UI", "\346\227\213\350\275\254", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("ModelProperty_UI", "Y:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ModelProperty_UI", "X:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("ModelProperty_UI", "\347\251\272\351\227\264\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ModelProperty_UI", "\345\261\236\346\200\247\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("ModelProperty_UI", "mesh\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        posSelcted->setText(QApplication::translate("ModelProperty_UI", "\347\274\226\350\276\221\346\250\241\345\236\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ModelProperty_UI: public Ui_ModelProperty_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELPROPERTYDLG_H
