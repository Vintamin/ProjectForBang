/********************************************************************************
** Form generated from reading UI file 'projectlistDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTLISTDLG_H
#define UI_PROJECTLISTDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectListDlg
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton;

    void setupUi(QWidget *ProjectListDlg)
    {
        if (ProjectListDlg->objectName().isEmpty())
            ProjectListDlg->setObjectName(QString::fromUtf8("ProjectListDlg"));
        ProjectListDlg->resize(306, 68);
        ProjectListDlg->setMinimumSize(QSize(306, 68));
        ProjectListDlg->setMaximumSize(QSize(306, 68));
        gridLayout = new QGridLayout(ProjectListDlg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ProjectListDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(35, 16777215));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(ProjectListDlg);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        pushButton = new QPushButton(ProjectListDlg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(ProjectListDlg);

        QMetaObject::connectSlotsByName(ProjectListDlg);
    } // setupUi

    void retranslateUi(QWidget *ProjectListDlg)
    {
        ProjectListDlg->setWindowTitle(QApplication::translate("ProjectListDlg", "\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ProjectListDlg", "\345\267\245\347\250\213\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ProjectListDlg", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProjectListDlg: public Ui_ProjectListDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTLISTDLG_H
