/********************************************************************************
** Form generated from reading UI file 'touranalysisdlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOURANALYSISDLG_H
#define UI_TOURANALYSISDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_touranalysis
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *luzhiToutBtn;
    QPushButton *jieshuTourBtn;
    QPushButton *playTourBtn;
    QPushButton *pauseTour;
    QPushButton *stopPlayBtn;
    QPushButton *clearTourBtn;

    void setupUi(QWidget *touranalysis)
    {
        if (touranalysis->objectName().isEmpty())
            touranalysis->setObjectName(QString::fromUtf8("touranalysis"));
        touranalysis->resize(486, 117);
        label = new QLabel(touranalysis);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 80, 54, 12));
        label_2 = new QLabel(touranalysis);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 80, 54, 12));
        label_3 = new QLabel(touranalysis);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 80, 54, 12));
        label_4 = new QLabel(touranalysis);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(330, 80, 54, 12));
        label_5 = new QLabel(touranalysis);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(250, 80, 54, 12));
        label_6 = new QLabel(touranalysis);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(410, 80, 54, 12));
        luzhiToutBtn = new QPushButton(touranalysis);
        luzhiToutBtn->setObjectName(QString::fromUtf8("luzhiToutBtn"));
        luzhiToutBtn->setGeometry(QRect(10, 20, 51, 51));
        luzhiToutBtn->setStyleSheet(QString::fromUtf8("QPushButton#luzhiToutBtn\n"
"{\n"
"	\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"    image: url(:/MyProjectUI/Resources/img/startTour.png)\n"
"	\n"
"	\n"
"}\n"
"QPushButton#luzhiToutBtn:hover	\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"    image: url(:/MyProjectUI/Resources/img/startTour.png)\n"
"	\n"
"	\n"
"}\n"
"QPushButton#luzhiToutBtn:pressed\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"    image: url(:/MyProjectUI/Resources/img/startTour.png)\n"
"	\n"
"	\n"
"}"));
        jieshuTourBtn = new QPushButton(touranalysis);
        jieshuTourBtn->setObjectName(QString::fromUtf8("jieshuTourBtn"));
        jieshuTourBtn->setGeometry(QRect(90, 20, 51, 51));
        jieshuTourBtn->setStyleSheet(QString::fromUtf8("QPushButton#jieshuTourBtn\n"
"{\n"
"	\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/stopRecord.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#jieshuTourBtn:hover\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/stopRecord.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#jieshuTourBtn:pressed\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/stopRecord.png);\n"
"	\n"
"	\n"
"}"));
        playTourBtn = new QPushButton(touranalysis);
        playTourBtn->setObjectName(QString::fromUtf8("playTourBtn"));
        playTourBtn->setGeometry(QRect(170, 20, 51, 51));
        playTourBtn->setStyleSheet(QString::fromUtf8("QPushButton#playTourBtn\n"
"{\n"
"	\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/startPlay.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#playTourBtn:hover	\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/startPlay.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#playTourBtn:pressed\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/startPlay.png);\n"
"	\n"
"	\n"
"}"));
        pauseTour = new QPushButton(touranalysis);
        pauseTour->setObjectName(QString::fromUtf8("pauseTour"));
        pauseTour->setGeometry(QRect(250, 20, 51, 51));
        pauseTour->setStyleSheet(QString::fromUtf8("QPushButton#pauseTour\n"
"{\n"
"	\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/pausePlay.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#pauseTour:hover\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/pausePlay.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#pauseTour:pressed\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/pausePlay.png);\n"
"	\n"
"	\n"
"}"));
        stopPlayBtn = new QPushButton(touranalysis);
        stopPlayBtn->setObjectName(QString::fromUtf8("stopPlayBtn"));
        stopPlayBtn->setGeometry(QRect(330, 20, 51, 51));
        stopPlayBtn->setStyleSheet(QString::fromUtf8("QPushButton#stopPlayBtn\n"
"{\n"
"	\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/stopPlay.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#stopPlayBtn:hover\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/stopPlay.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#stopPlayBtn:pressed\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/stopPlay.png);\n"
"	\n"
"	\n"
"}  "));
        clearTourBtn = new QPushButton(touranalysis);
        clearTourBtn->setObjectName(QString::fromUtf8("clearTourBtn"));
        clearTourBtn->setGeometry(QRect(410, 20, 51, 51));
        clearTourBtn->setStyleSheet(QString::fromUtf8("QPushButton#clearTourBtn\n"
"{\n"
"	\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/clear.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#clearTourBtn:hover	\n"
"{\n"
"	background-color: rgb(188, 255, 250);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/clear.png);\n"
"	\n"
"	\n"
"}\n"
"QPushButton#clearTourBtn:pressed\n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	border: 2px solid #9ea1a4;\n"
"	border-radius: 8px;\n"
"	image: url(:/MyProjectUI/Resources/img/clear.png);\n"
"	\n"
"	\n"
"}"));

        retranslateUi(touranalysis);

        QMetaObject::connectSlotsByName(touranalysis);
    } // setupUi

    void retranslateUi(QWidget *touranalysis)
    {
        touranalysis->setWindowTitle(QApplication::translate("touranalysis", "\346\270\270\350\247\210\345\210\206\346\236\220", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("touranalysis", "\345\275\225\345\210\266\346\270\270\350\247\210", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("touranalysis", "\347\273\223\346\235\237\346\270\270\350\247\210", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("touranalysis", "\346\222\255\346\224\276\346\270\270\350\247\210", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("touranalysis", "\347\273\210\346\255\242\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("touranalysis", "\346\232\202\345\201\234\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("touranalysis", "\346\270\205\351\231\244\346\270\270\350\247\210", 0, QApplication::UnicodeUTF8));
        luzhiToutBtn->setText(QString());
        jieshuTourBtn->setText(QString());
        playTourBtn->setText(QString());
        pauseTour->setText(QString());
        stopPlayBtn->setText(QString());
        clearTourBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class touranalysis: public Ui_touranalysis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOURANALYSISDLG_H
