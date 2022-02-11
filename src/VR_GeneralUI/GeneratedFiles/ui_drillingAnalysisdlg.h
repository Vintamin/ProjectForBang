/********************************************************************************
** Form generated from reading UI file 'drillingAnalysisdlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRILLINGANALYSISDLG_H
#define UI_DRILLINGANALYSISDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_drillAnalysi
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *beginBtn;
    QPushButton *drillingSaveBtn;
    QPushButton *analysisOptPoint;
    QPushButton *verticalPointBtn;
    QPushButton *endAnalysisBtn;
    QPushButton *selectSavePointBtn;

    void setupUi(QWidget *drillAnalysi)
    {
        if (drillAnalysi->objectName().isEmpty())
            drillAnalysi->setObjectName(QString::fromUtf8("drillAnalysi"));
        drillAnalysi->resize(510, 146);
        groupBox = new QGroupBox(drillAnalysi);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 491, 121));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 90, 54, 12));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 90, 54, 12));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 90, 61, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(250, 90, 61, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(330, 90, 54, 12));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(410, 90, 54, 12));
        beginBtn = new QPushButton(groupBox);
        beginBtn->setObjectName(QString::fromUtf8("beginBtn"));
        beginBtn->setGeometry(QRect(10, 29, 51, 51));
        beginBtn->setStyleSheet(QString::fromUtf8("QPushButton#beginBtn\n"
"{\n"
"	\n"
"	\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"    image: url(:/MyProjectUI/Resources/img/solutionEdit.ico);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#beginBtn:hover\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"    image: url(:/MyProjectUI/Resources/img/solutionEdit.ico);\n"
"		\n"
"}\n"
"QPushButton#beginBtn:pressed\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"    image: url(:/MyProjectUI/Resources/img/solutionEdit.ico);\n"
"		\n"
"}"));
        drillingSaveBtn = new QPushButton(groupBox);
        drillingSaveBtn->setObjectName(QString::fromUtf8("drillingSaveBtn"));
        drillingSaveBtn->setGeometry(QRect(330, 29, 51, 51));
        drillingSaveBtn->setStyleSheet(QString::fromUtf8("QPushButton#drillingSaveBtn\n"
"{\n"
"	\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/beginDrilling.png);\n"
"	\n"
"}\n"
"QPushButton#drillingSaveBtn:hover	\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/beginDrilling.png);\n"
"	\n"
"}\n"
"QPushButton#drillingSaveBtn:pressed\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/beginDrilling.png);\n"
"	\n"
"}"));
        analysisOptPoint = new QPushButton(groupBox);
        analysisOptPoint->setObjectName(QString::fromUtf8("analysisOptPoint"));
        analysisOptPoint->setGeometry(QRect(250, 29, 51, 51));
        analysisOptPoint->setStyleSheet(QString::fromUtf8("QPushButton#analysisOptPoint\n"
"{\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/selectOptimalPoint.png);\n"
"	\n"
"}\n"
"QPushButton#analysisOptPoint:hover	\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/selectOptimalPoint.png);\n"
"\n"
"}\n"
"QPushButton#analysisOptPoint:pressed\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/selectOptimalPoint.png);\n"
"	\n"
"}"));
        verticalPointBtn = new QPushButton(groupBox);
        verticalPointBtn->setObjectName(QString::fromUtf8("verticalPointBtn"));
        verticalPointBtn->setGeometry(QRect(170, 29, 51, 51));
        verticalPointBtn->setStyleSheet(QString::fromUtf8("QPushButton#verticalPointBtn\n"
"{\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/coorLocate.png);\n"
"	\n"
"}\n"
"QPushButton#verticalPointBtn:hover	\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/coorLocate.png);\n"
"	\n"
"}\n"
"QPushButton#verticalPointBtn:pressed\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/coorLocate.png);\n"
"	\n"
"}"));
        endAnalysisBtn = new QPushButton(groupBox);
        endAnalysisBtn->setObjectName(QString::fromUtf8("endAnalysisBtn"));
        endAnalysisBtn->setGeometry(QRect(410, 29, 51, 51));
        endAnalysisBtn->setStyleSheet(QString::fromUtf8("QPushButton#endAnalysisBtn\n"
"{\n"
"	\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/clear.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#endAnalysisBtn:hover	\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/clear.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#endAnalysisBtn:pressec\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/clear.png);\n"
"	\n"
"	\n"
"}"));
        selectSavePointBtn = new QPushButton(groupBox);
        selectSavePointBtn->setObjectName(QString::fromUtf8("selectSavePointBtn"));
        selectSavePointBtn->setGeometry(QRect(90, 29, 51, 51));
        selectSavePointBtn->setStyleSheet(QString::fromUtf8("QPushButton#selectSavePointBtn\n"
"{\n"
"	\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	\n"
"	image: url(:/MyProjectUI/Resources/img/seltecrNearerPoints.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#selectSavePointBtn:hover\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/seltecrNearerPoints.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#selectSavePointBtn:pressed\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/seltecrNearerPoints.png);\n"
"	\n"
"	\n"
"}"));

        retranslateUi(drillAnalysi);

        QMetaObject::connectSlotsByName(drillAnalysi);
    } // setupUi

    void retranslateUi(QWidget *drillAnalysi)
    {
        drillAnalysi->setWindowTitle(QApplication::translate("drillAnalysi", "\351\222\273\346\216\242\346\225\221\346\217\264", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("drillAnalysi", "\346\225\221\346\217\264\346\265\201\347\250\213", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("drillAnalysi", "\345\274\200\345\247\213\347\274\226\350\276\221", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("drillAnalysi", "\351\200\211\346\225\221\346\217\264\347\202\271", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("drillAnalysi", "\345\236\202\347\233\264\345\234\260\350\241\250\347\202\271", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("drillAnalysi", "\345\210\206\346\236\220\346\234\200\344\274\230\347\202\271", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("drillAnalysi", "\351\222\273\346\216\242\346\225\221\346\217\264", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("drillAnalysi", "\347\273\223\346\235\237\345\210\206\346\236\220", 0, QApplication::UnicodeUTF8));
        beginBtn->setText(QString());
        drillingSaveBtn->setText(QString());
        analysisOptPoint->setText(QString());
        verticalPointBtn->setText(QString());
        endAnalysisBtn->setText(QString());
        selectSavePointBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class drillAnalysi: public Ui_drillAnalysi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRILLINGANALYSISDLG_H
