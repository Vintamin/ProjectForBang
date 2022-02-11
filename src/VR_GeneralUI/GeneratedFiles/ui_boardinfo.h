/********************************************************************************
** Form generated from reading UI file 'boardinfo.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARDINFO_H
#define UI_BOARDINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoardInfo
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *namewidget;
    QGridLayout *gridLayout_2;
    QLabel *namelab;
    QWidget *infowidget;
    QGridLayout *gridLayout;
    QTextEdit *infotextEdit;

    void setupUi(QWidget *BoardInfo)
    {
        if (BoardInfo->objectName().isEmpty())
            BoardInfo->setObjectName(QString::fromUtf8("BoardInfo"));
        BoardInfo->resize(280, 297);
        BoardInfo->setMinimumSize(QSize(280, 0));
        BoardInfo->setMaximumSize(QSize(291, 16777215));
        BoardInfo->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(BoardInfo);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        namewidget = new QWidget(BoardInfo);
        namewidget->setObjectName(QString::fromUtf8("namewidget"));
        namewidget->setMinimumSize(QSize(280, 30));
        namewidget->setMaximumSize(QSize(280, 30));
        namewidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(namewidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        namelab = new QLabel(namewidget);
        namelab->setObjectName(QString::fromUtf8("namelab"));
        namelab->setStyleSheet(QString::fromUtf8("QLabel#namelab\n"
"{\n"
"	\n"
"	border: 2px solid;\n"
"	border-bottom:0px;\n"
"	border-left-color: rgb(170, 255, 255);\n"
"	border-top-color: rgb(170, 255, 255);\n"
"	border-right-color: rgb(170, 255, 255);\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.18, stop: 0 #8ebbfe, stop: 1 #bcebff);\n"
"min-width: 80px;\n"
"}"));

        gridLayout_2->addWidget(namelab, 0, 0, 1, 1);


        verticalLayout->addWidget(namewidget);

        infowidget = new QWidget(BoardInfo);
        infowidget->setObjectName(QString::fromUtf8("infowidget"));
        infowidget->setMinimumSize(QSize(280, 100));
        infowidget->setMaximumSize(QSize(280, 16777215));
        gridLayout = new QGridLayout(infowidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        infotextEdit = new QTextEdit(infowidget);
        infotextEdit->setObjectName(QString::fromUtf8("infotextEdit"));
        infotextEdit->setMinimumSize(QSize(280, 100));
        infotextEdit->setMaximumSize(QSize(280, 16777215));
        infotextEdit->setStyleSheet(QString::fromUtf8("QTextEdit#infotextEdit\n"
"{\n"
"		\n"
"	border: 2px solid;\n"
"	border-top:0px;\n"
"	border-right:0px;\n"
"	border-left-color: rgb(170, 255, 255);\n"
"	border-bottom-color: rgb(170, 255, 255);\n"
"	background-color: rgb(149, 195, 254);\n"
"	\n"
"}\n"
"QScrollBar:vertical {\n"
"    background: #bae8ff;\n"
"    width: 16px;\n"
"    margin: 16px 0 16px 0;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #9fcfff;\n"
"    min-height: 16px;\n"
"	border-radius: 13px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"    background: #aedfff;\n"
"    height: 16px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    background: #aedfff;\n"
"    height: 16px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar:up-arrow:vertical, QScrollBar:down-arrow:vertical {\n"
"    border: 2px soli"
                        "d #b7e7fd;\n"
"    width: 6px;\n"
"    height: 6px;\n"
"    background: #93bffe;\n"
"}\n"
"\n"
""));

        gridLayout->addWidget(infotextEdit, 0, 0, 1, 1);


        verticalLayout->addWidget(infowidget);


        retranslateUi(BoardInfo);

        QMetaObject::connectSlotsByName(BoardInfo);
    } // setupUi

    void retranslateUi(QWidget *BoardInfo)
    {
        BoardInfo->setWindowTitle(QApplication::translate("BoardInfo", "\345\261\236\346\200\247\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        namelab->setText(QApplication::translate("BoardInfo", "\345\261\236\346\200\247\344\277\241\346\201\257\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BoardInfo: public Ui_BoardInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARDINFO_H
