/********************************************************************************
** Form generated from reading UI file 'loadvideo.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADVIDEO_H
#define UI_LOADVIDEO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <phonon/seekslider.h>
#include <phonon/volumeslider.h>

QT_BEGIN_NAMESPACE

class Ui_LoadVideo
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *videoLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    Phonon::SeekSlider *videoSeekSlider;
    QHBoxLayout *horizontalLayout;
    Phonon::VolumeSlider *volumeSlider;
    QSpacerItem *horizontalSpacer;
    QPushButton *openOrPauseButton;
    QPushButton *quitButton;

    void setupUi(QWidget *LoadVideo)
    {
        if (LoadVideo->objectName().isEmpty())
            LoadVideo->setObjectName(QString::fromUtf8("LoadVideo"));
        LoadVideo->resize(774, 499);
        gridLayout = new QGridLayout(LoadVideo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        videoLayout = new QVBoxLayout();
        videoLayout->setObjectName(QString::fromUtf8("videoLayout"));
        widget = new QWidget(LoadVideo);
        widget->setObjectName(QString::fromUtf8("widget"));

        videoLayout->addWidget(widget);


        gridLayout->addLayout(videoLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        videoSeekSlider = new Phonon::SeekSlider(LoadVideo);
        videoSeekSlider->setObjectName(QString::fromUtf8("videoSeekSlider"));

        verticalLayout->addWidget(videoSeekSlider);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        volumeSlider = new Phonon::VolumeSlider(LoadVideo);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));

        horizontalLayout->addWidget(volumeSlider);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        openOrPauseButton = new QPushButton(LoadVideo);
        openOrPauseButton->setObjectName(QString::fromUtf8("openOrPauseButton"));
        openOrPauseButton->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(openOrPauseButton);

        quitButton = new QPushButton(LoadVideo);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(quitButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        retranslateUi(LoadVideo);

        QMetaObject::connectSlotsByName(LoadVideo);
    } // setupUi

    void retranslateUi(QWidget *LoadVideo)
    {
        LoadVideo->setWindowTitle(QApplication::translate("LoadVideo", "Form", 0, QApplication::UnicodeUTF8));
        openOrPauseButton->setText(QApplication::translate("LoadVideo", "\346\222\255\346\224\276/\346\232\202\345\201\234", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("LoadVideo", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoadVideo: public Ui_LoadVideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADVIDEO_H
