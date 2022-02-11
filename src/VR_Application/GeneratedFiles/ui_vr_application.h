/********************************************************************************
** Form generated from reading UI file 'vr_application.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VR_APPLICATION_H
#define UI_VR_APPLICATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "vr_mapcontrolwidget.h"
#include "vrcontrol.h"

QT_BEGIN_NAMESPACE

class Ui_VR_ApplicationClass
{
public:
    QAction *action;
    QAction *pan_Action;
    QAction *zoomIn_Action;
    QAction *zoomOut;
    QAction *fullScreen_Action;
    QAction *reset_Action;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTreeView *treeView;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    VR_MapControlWidget *vR_MapControlWidget;
    VRControl *vRControl;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VR_ApplicationClass)
    {
        if (VR_ApplicationClass->objectName().isEmpty())
            VR_ApplicationClass->setObjectName(QString::fromUtf8("VR_ApplicationClass"));
        VR_ApplicationClass->resize(704, 488);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VR_ApplicationClass->sizePolicy().hasHeightForWidth());
        VR_ApplicationClass->setSizePolicy(sizePolicy);
        action = new QAction(VR_ApplicationClass);
        action->setObjectName(QString::fromUtf8("action"));
        pan_Action = new QAction(VR_ApplicationClass);
        pan_Action->setObjectName(QString::fromUtf8("pan_Action"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/VR_Application/Resources/pan.png"), QSize(), QIcon::Normal, QIcon::Off);
        pan_Action->setIcon(icon);
        zoomIn_Action = new QAction(VR_ApplicationClass);
        zoomIn_Action->setObjectName(QString::fromUtf8("zoomIn_Action"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/VR_Application/Resources/zoomIn.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        zoomIn_Action->setIcon(icon1);
        zoomOut = new QAction(VR_ApplicationClass);
        zoomOut->setObjectName(QString::fromUtf8("zoomOut"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/VR_Application/Resources/zoomOut.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomOut->setIcon(icon2);
        fullScreen_Action = new QAction(VR_ApplicationClass);
        fullScreen_Action->setObjectName(QString::fromUtf8("fullScreen_Action"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/VR_Application/Resources/fullScreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        fullScreen_Action->setIcon(icon3);
        reset_Action = new QAction(VR_ApplicationClass);
        reset_Action->setObjectName(QString::fromUtf8("reset_Action"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/VR_Application/Resources/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        reset_Action->setIcon(icon4);
        centralWidget = new QWidget(VR_ApplicationClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(treeView);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(tableWidget);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        vR_MapControlWidget = new VR_MapControlWidget(centralWidget);
        vR_MapControlWidget->setObjectName(QString::fromUtf8("vR_MapControlWidget"));

        horizontalLayout->addWidget(vR_MapControlWidget);

        vRControl = new VRControl(centralWidget);
        vRControl->setObjectName(QString::fromUtf8("vRControl"));

        horizontalLayout->addWidget(vRControl);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        VR_ApplicationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VR_ApplicationClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 704, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        VR_ApplicationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VR_ApplicationClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        VR_ApplicationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VR_ApplicationClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        VR_ApplicationClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu_2->addAction(action);
        mainToolBar->addAction(pan_Action);
        mainToolBar->addAction(zoomIn_Action);
        mainToolBar->addAction(zoomOut);
        mainToolBar->addAction(fullScreen_Action);
        mainToolBar->addAction(reset_Action);

        retranslateUi(VR_ApplicationClass);
        QObject::connect(pan_Action, SIGNAL(triggered()), VR_ApplicationClass, SLOT(slotPanMap()));
        QObject::connect(zoomIn_Action, SIGNAL(triggered()), VR_ApplicationClass, SLOT(slotZoomInMap()));
        QObject::connect(zoomOut, SIGNAL(triggered()), VR_ApplicationClass, SLOT(slotZoomOutMap()));
        QObject::connect(fullScreen_Action, SIGNAL(triggered()), VR_ApplicationClass, SLOT(slotFullScreen()));
        QObject::connect(reset_Action, SIGNAL(triggered()), VR_ApplicationClass, SLOT(slotReset()));

        QMetaObject::connectSlotsByName(VR_ApplicationClass);
    } // setupUi

    void retranslateUi(QMainWindow *VR_ApplicationClass)
    {
        VR_ApplicationClass->setWindowTitle(QApplication::translate("VR_ApplicationClass", "\344\272\214\344\270\211\347\273\264\351\232\247\351\201\223\347\210\206\347\240\264\344\277\241\346\201\257\344\273\277\347\234\237\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("VR_ApplicationClass", "\345\205\250\345\261\217", 0, QApplication::UnicodeUTF8));
        pan_Action->setText(QApplication::translate("VR_ApplicationClass", "\346\274\253\346\270\270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pan_Action->setToolTip(QApplication::translate("VR_ApplicationClass", "\346\274\253\346\270\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        zoomIn_Action->setText(QApplication::translate("VR_ApplicationClass", "\346\224\276\345\244\247", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        zoomIn_Action->setToolTip(QApplication::translate("VR_ApplicationClass", "\346\224\276\345\244\247", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        zoomOut->setText(QApplication::translate("VR_ApplicationClass", "\347\274\251\345\260\217", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        zoomOut->setToolTip(QApplication::translate("VR_ApplicationClass", "\347\274\251\345\260\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        fullScreen_Action->setText(QApplication::translate("VR_ApplicationClass", "\345\205\250\345\261\217", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        fullScreen_Action->setToolTip(QApplication::translate("VR_ApplicationClass", "\345\205\250\345\261\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        reset_Action->setText(QApplication::translate("VR_ApplicationClass", "\345\244\215\344\275\215", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        reset_Action->setToolTip(QApplication::translate("VR_ApplicationClass", "\345\244\215\344\275\215", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        menu->setTitle(QApplication::translate("VR_ApplicationClass", "\345\267\245\347\250\213\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("VR_ApplicationClass", "\345\234\272\346\231\257\350\247\206\345\233\276", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VR_ApplicationClass: public Ui_VR_ApplicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VR_APPLICATION_H
