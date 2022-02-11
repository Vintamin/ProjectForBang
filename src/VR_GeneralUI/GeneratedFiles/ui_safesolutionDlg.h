/********************************************************************************
** Form generated from reading UI file 'safesolutionDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAFESOLUTIONDLG_H
#define UI_SAFESOLUTIONDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SafeSolution_UI
{
public:
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *labelddd;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *analysisRadius;
    QLabel *label_6;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *verticalOffset;
    QLabel *label_12;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *optimalAngle;
    QLabel *label_13;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *analysisDensity;
    QLabel *label_15;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_5;
    QDoubleSpinBox *analysisPointCount;
    QLabel *label_14;
    QLabel *label;
    QTextEdit *solutionName;
    QPushButton *handIn;
    QPushButton *cacel;

    void setupUi(QWidget *SafeSolution_UI)
    {
        if (SafeSolution_UI->objectName().isEmpty())
            SafeSolution_UI->setObjectName(QString::fromUtf8("SafeSolution_UI"));
        SafeSolution_UI->resize(502, 269);
        groupBox = new QGroupBox(SafeSolution_UI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 431, 171));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 91, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 40, 61, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(240, 80, 61, 41));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 80, 101, 41));
        labelddd = new QLabel(groupBox);
        labelddd->setObjectName(QString::fromUtf8("labelddd"));
        labelddd->setGeometry(QRect(10, 130, 71, 41));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(110, 40, 101, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        analysisRadius = new QDoubleSpinBox(widget);
        analysisRadius->setObjectName(QString::fromUtf8("analysisRadius"));
        analysisRadius->setMaximum(10000);
        analysisRadius->setValue(10);

        horizontalLayout->addWidget(analysisRadius);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(110, 90, 101, 22));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalOffset = new QDoubleSpinBox(widget1);
        verticalOffset->setObjectName(QString::fromUtf8("verticalOffset"));
        verticalOffset->setValue(2);

        horizontalLayout_2->addWidget(verticalOffset);

        label_12 = new QLabel(widget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_2->addWidget(label_12);

        widget2 = new QWidget(groupBox);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(110, 140, 101, 22));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        optimalAngle = new QDoubleSpinBox(widget2);
        optimalAngle->setObjectName(QString::fromUtf8("optimalAngle"));
        optimalAngle->setValue(10);

        horizontalLayout_3->addWidget(optimalAngle);

        label_13 = new QLabel(widget2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_3->addWidget(label_13);

        widget3 = new QWidget(groupBox);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(320, 40, 80, 22));
        horizontalLayout_4 = new QHBoxLayout(widget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        analysisDensity = new QDoubleSpinBox(widget3);
        analysisDensity->setObjectName(QString::fromUtf8("analysisDensity"));
        analysisDensity->setMaximum(200);
        analysisDensity->setValue(60);

        horizontalLayout_4->addWidget(analysisDensity);

        label_15 = new QLabel(widget3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_4->addWidget(label_15);

        widget4 = new QWidget(groupBox);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->setGeometry(QRect(320, 90, 81, 22));
        horizontalLayout_5 = new QHBoxLayout(widget4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        analysisPointCount = new QDoubleSpinBox(widget4);
        analysisPointCount->setObjectName(QString::fromUtf8("analysisPointCount"));
        analysisPointCount->setValue(20);

        horizontalLayout_5->addWidget(analysisPointCount);

        label_14 = new QLabel(widget4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_5->addWidget(label_14);

        label = new QLabel(SafeSolution_UI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 54, 12));
        solutionName = new QTextEdit(SafeSolution_UI);
        solutionName->setObjectName(QString::fromUtf8("solutionName"));
        solutionName->setGeometry(QRect(90, 10, 351, 31));
        handIn = new QPushButton(SafeSolution_UI);
        handIn->setObjectName(QString::fromUtf8("handIn"));
        handIn->setGeometry(QRect(250, 230, 75, 31));
        cacel = new QPushButton(SafeSolution_UI);
        cacel->setObjectName(QString::fromUtf8("cacel"));
        cacel->setGeometry(QRect(360, 230, 75, 31));

        retranslateUi(SafeSolution_UI);
        QObject::connect(handIn, SIGNAL(clicked()), SafeSolution_UI, SLOT(slotHandIn()));
        QObject::connect(cacel, SIGNAL(clicked()), SafeSolution_UI, SLOT(slotCancel()));

        QMetaObject::connectSlotsByName(SafeSolution_UI);
    } // setupUi

    void retranslateUi(QWidget *SafeSolution_UI)
    {
        SafeSolution_UI->setWindowTitle(QApplication::translate("SafeSolution_UI", "\346\225\221\346\217\264\346\226\271\346\241\210\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SafeSolution_UI", "\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SafeSolution_UI", "\346\234\200\344\274\230\347\202\271\345\210\206\346\236\220\345\215\212\345\276\204", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SafeSolution_UI", "\345\210\206\346\236\220\345\257\206\345\272\246", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SafeSolution_UI", "\346\257\217\344\270\252\346\226\271\345\220\221\347\232\204\n"
"\345\210\206\346\236\220\347\202\271\344\270\252\346\225\260", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SafeSolution_UI", "\351\207\207\346\240\267\347\202\271\347\232\204\345\236\202\347\233\264\345\201\217\347\247\273", 0, QApplication::UnicodeUTF8));
        labelddd->setText(QApplication::translate("SafeSolution_UI", "\345\235\241\345\272\246\351\230\210\345\200\274", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SafeSolution_UI", "\347\261\263", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SafeSolution_UI", "\347\261\263", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("SafeSolution_UI", "\345\272\246", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("SafeSolution_UI", "\344\270\252", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("SafeSolution_UI", "\344\270\252", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SafeSolution_UI", "\346\226\271\346\241\210\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        handIn->setText(QApplication::translate("SafeSolution_UI", "\346\217\220\344\272\244", 0, QApplication::UnicodeUTF8));
        cacel->setText(QApplication::translate("SafeSolution_UI", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SafeSolution_UI: public Ui_SafeSolution_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAFESOLUTIONDLG_H
