/********************************************************************************
** Form generated from reading UI file 'floodanalysisDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLOODANALYSISDLG_H
#define UI_FLOODANALYSISDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FloodAnalysis_UI
{
public:
    QGroupBox *groupBox;
    QCheckBox *useWaterFlow;
    QDoubleSpinBox *waterHeight;
    QLabel *label_2;
    QLabel *label;
    QPushButton *selectWaterColour;
    QCheckBox *showWaterSurface;
    QGroupBox *groupBox_2;
    QTextEdit *floodDescription;
    QPushButton *handIn;
    QPushButton *cancel;

    void setupUi(QWidget *FloodAnalysis_UI)
    {
        if (FloodAnalysis_UI->objectName().isEmpty())
            FloodAnalysis_UI->setObjectName(QString::fromUtf8("FloodAnalysis_UI"));
        FloodAnalysis_UI->resize(370, 401);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/resource/img/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        FloodAnalysis_UI->setWindowIcon(icon);
        groupBox = new QGroupBox(FloodAnalysis_UI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 351, 181));
        useWaterFlow = new QCheckBox(groupBox);
        useWaterFlow->setObjectName(QString::fromUtf8("useWaterFlow"));
        useWaterFlow->setGeometry(QRect(200, 30, 111, 16));
        waterHeight = new QDoubleSpinBox(groupBox);
        waterHeight->setObjectName(QString::fromUtf8("waterHeight"));
        waterHeight->setGeometry(QRect(130, 80, 211, 31));
        waterHeight->setMinimum(-500);
        waterHeight->setMaximum(500);
        waterHeight->setValue(-50);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 140, 121, 16));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 80, 81, 21));
        selectWaterColour = new QPushButton(groupBox);
        selectWaterColour->setObjectName(QString::fromUtf8("selectWaterColour"));
        selectWaterColour->setGeometry(QRect(130, 140, 211, 31));
        QPalette palette;
        QBrush brush(QColor(0, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        selectWaterColour->setPalette(palette);
        selectWaterColour->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 255);"));
        showWaterSurface = new QCheckBox(groupBox);
        showWaterSurface->setObjectName(QString::fromUtf8("showWaterSurface"));
        showWaterSurface->setGeometry(QRect(40, 30, 101, 16));
        groupBox_2 = new QGroupBox(FloodAnalysis_UI);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 200, 351, 141));
        floodDescription = new QTextEdit(groupBox_2);
        floodDescription->setObjectName(QString::fromUtf8("floodDescription"));
        floodDescription->setGeometry(QRect(10, 20, 331, 111));
        handIn = new QPushButton(FloodAnalysis_UI);
        handIn->setObjectName(QString::fromUtf8("handIn"));
        handIn->setGeometry(QRect(170, 360, 71, 31));
        cancel = new QPushButton(FloodAnalysis_UI);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(274, 360, 71, 31));

        retranslateUi(FloodAnalysis_UI);
        QObject::connect(selectWaterColour, SIGNAL(clicked()), FloodAnalysis_UI, SLOT(slotSelectWaterColor()));
        QObject::connect(waterHeight, SIGNAL(valueChanged(double)), FloodAnalysis_UI, SLOT(slotSetWaterHeight(double)));
        QObject::connect(cancel, SIGNAL(clicked()), FloodAnalysis_UI, SLOT(close()));
        QObject::connect(handIn, SIGNAL(clicked()), FloodAnalysis_UI, SLOT(slotHandIn()));
        QObject::connect(showWaterSurface, SIGNAL(clicked(bool)), FloodAnalysis_UI, SLOT(slotShowWaterSurface(bool)));
        QObject::connect(useWaterFlow, SIGNAL(clicked(bool)), FloodAnalysis_UI, SLOT(slotWaterSurfaceEffect(bool)));

        QMetaObject::connectSlotsByName(FloodAnalysis_UI);
    } // setupUi

    void retranslateUi(QWidget *FloodAnalysis_UI)
    {
        FloodAnalysis_UI->setWindowTitle(QApplication::translate("FloodAnalysis_UI", "\345\267\267\351\201\223\346\267\271\346\262\241\345\210\206\346\236\220\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("FloodAnalysis_UI", "\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        useWaterFlow->setText(QApplication::translate("FloodAnalysis_UI", "\346\260\264\351\235\242\346\265\201\345\212\250\346\225\210\346\236\234", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FloodAnalysis_UI", "\350\242\253\346\267\271\346\262\241\345\267\267\351\201\223\346\267\267\345\220\210\351\242\234\350\211\262", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FloodAnalysis_UI", "\344\272\225\344\270\213\346\260\264\351\235\242\351\253\230\345\272\246", 0, QApplication::UnicodeUTF8));
        selectWaterColour->setText(QString());
        showWaterSurface->setText(QApplication::translate("FloodAnalysis_UI", "\346\230\276\347\244\272\346\250\241\346\213\237\346\260\264\351\235\242", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("FloodAnalysis_UI", "\346\267\271\346\262\241\346\217\217\350\277\260", 0, QApplication::UnicodeUTF8));
        handIn->setText(QApplication::translate("FloodAnalysis_UI", "\346\217\220\344\272\244", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("FloodAnalysis_UI", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FloodAnalysis_UI: public Ui_FloodAnalysis_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLOODANALYSISDLG_H
