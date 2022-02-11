/********************************************************************************
** Form generated from reading UI file 'spaltialanalysidlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPALTIALANALYSIDLG_H
#define UI_SPALTIALANALYSIDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpatialForm
{
public:
    QPushButton *pointMeasureBtn;
    QPushButton *distanceMeasureBtn;
    QPushButton *clearMeasureBtn;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *SpatialForm)
    {
        if (SpatialForm->objectName().isEmpty())
            SpatialForm->setObjectName(QString::fromUtf8("SpatialForm"));
        SpatialForm->resize(238, 116);
        SpatialForm->setStyleSheet(QString::fromUtf8("background-image: url(:/img/board_background.jpg);"));
        pointMeasureBtn = new QPushButton(SpatialForm);
        pointMeasureBtn->setObjectName(QString::fromUtf8("pointMeasureBtn"));
        pointMeasureBtn->setGeometry(QRect(20, 20, 50, 50));
        pointMeasureBtn->setStyleSheet(QString::fromUtf8("QPushButton#pointMeasureBtn\n"
"{\n"
"	\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/pointMeasure.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#pointMeasureBtn:hover	\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/pointMeasure.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#pointMeasureBtn:pressed\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/pointMeasure.png);\n"
"	\n"
"	\n"
"}"));
        distanceMeasureBtn = new QPushButton(SpatialForm);
        distanceMeasureBtn->setObjectName(QString::fromUtf8("distanceMeasureBtn"));
        distanceMeasureBtn->setGeometry(QRect(90, 20, 50, 50));
        distanceMeasureBtn->setMinimumSize(QSize(50, 50));
        distanceMeasureBtn->setMaximumSize(QSize(50, 50));
        distanceMeasureBtn->setStyleSheet(QString::fromUtf8("QPushButton#distanceMeasureBtn\n"
"{\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;	\n"
"    image: url(:/MyProjectUI/Resources/img/distaceMeasure.png)\n"
"}\n"
"QPushButton#distanceMeasureBtn:hover\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;	\n"
"    image: url(:/MyProjectUI/Resources/img/distaceMeasure.png)\n"
"}\n"
"QPushButton#distanceMeasureBtn:pressed\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;	\n"
"    image: url(:/MyProjectUI/Resources/img/distaceMeasure.png)\n"
"}"));
        clearMeasureBtn = new QPushButton(SpatialForm);
        clearMeasureBtn->setObjectName(QString::fromUtf8("clearMeasureBtn"));
        clearMeasureBtn->setGeometry(QRect(160, 20, 50, 50));
        clearMeasureBtn->setMinimumSize(QSize(50, 50));
        clearMeasureBtn->setMaximumSize(QSize(50, 50));
        clearMeasureBtn->setStyleSheet(QString::fromUtf8("QPushButton#clearMeasureBtn\n"
"{\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/clear.png);\n"
"}\n"
"QPushButton#clearMeasureBtn:hover	\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/clear.png);\n"
"}\n"
"QPushButton#clearMeasureBtn:pressed\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/clear.png);\n"
"}"));
        label = new QLabel(SpatialForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 80, 54, 12));
        label_2 = new QLabel(SpatialForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 80, 54, 12));
        label_3 = new QLabel(SpatialForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 80, 54, 12));

        retranslateUi(SpatialForm);

        QMetaObject::connectSlotsByName(SpatialForm);
    } // setupUi

    void retranslateUi(QWidget *SpatialForm)
    {
        SpatialForm->setWindowTitle(QApplication::translate("SpatialForm", "\347\251\272\351\227\264\345\210\206\346\236\220", 0, QApplication::UnicodeUTF8));
        pointMeasureBtn->setText(QString());
        distanceMeasureBtn->setText(QString());
        clearMeasureBtn->setText(QString());
        label->setText(QApplication::translate("SpatialForm", "\347\202\271\344\275\215\351\207\217\346\265\213", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SpatialForm", "\350\267\235\347\246\273\351\207\217\346\265\213", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SpatialForm", "\346\270\205\351\231\244\351\207\217\346\265\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SpatialForm: public Ui_SpatialForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPALTIALANALYSIDLG_H
