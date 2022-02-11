/********************************************************************************
** Form generated from reading UI file 'layerpropertyDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAYERPROPERTYDLG_H
#define UI_LAYERPROPERTYDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LayerProperty_UI
{
public:
    QLabel *label;
    QTextEdit *textEdit;
    QGroupBox *groupBox;
    QTextEdit *textEdit_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *LayerProperty_UI)
    {
        if (LayerProperty_UI->objectName().isEmpty())
            LayerProperty_UI->setObjectName(QString::fromUtf8("LayerProperty_UI"));
        LayerProperty_UI->resize(353, 457);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/vrmin_logo/bin/Debug/data/Resources/logo/vrmine.png"), QSize(), QIcon::Normal, QIcon::Off);
        LayerProperty_UI->setWindowIcon(icon);
        label = new QLabel(LayerProperty_UI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 54, 12));
        textEdit = new QTextEdit(LayerProperty_UI);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(90, 30, 241, 31));
        groupBox = new QGroupBox(LayerProperty_UI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 80, 331, 261));
        textEdit_2 = new QTextEdit(groupBox);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(13, 20, 311, 231));
        checkBox = new QCheckBox(LayerProperty_UI);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 370, 71, 16));
        checkBox_2 = new QCheckBox(LayerProperty_UI);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(130, 370, 71, 16));
        pushButton = new QPushButton(LayerProperty_UI);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 410, 75, 31));
        pushButton_2 = new QPushButton(LayerProperty_UI);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 410, 75, 31));

        retranslateUi(LayerProperty_UI);

        QMetaObject::connectSlotsByName(LayerProperty_UI);
    } // setupUi

    void retranslateUi(QWidget *LayerProperty_UI)
    {
        LayerProperty_UI->setWindowTitle(QApplication::translate("LayerProperty_UI", "\345\233\276\345\261\202\345\261\236\346\200\247", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LayerProperty_UI", "\345\233\276\345\261\202\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("LayerProperty_UI", "\345\233\276\345\261\202\346\217\217\350\277\260", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("LayerProperty_UI", "\345\217\257\350\247\201\346\200\247", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("LayerProperty_UI", "\345\217\257\351\200\211\346\213\251\346\200\247", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("LayerProperty_UI", "\346\217\220\344\272\244", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("LayerProperty_UI", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LayerProperty_UI: public Ui_LayerProperty_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAYERPROPERTYDLG_H
