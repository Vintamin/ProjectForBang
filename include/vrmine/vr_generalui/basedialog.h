#ifndef BASEDIALOG_H
#define BASEDIALOG_H

#include <QtGui/QLabel>
#include <QtGui/QPixmap>
#include <QtGui/QDialog>
#include <QtGui/QToolButton>
#include <QtGui/QHBoxLayout>
#include "vrmine/vr_generalui/vr_generaluiconfig.h"

namespace VirtualMine
{
	namespace GeneralUI
	{
		class VRGENERALUI_DLL CUiBaseDialog : public QDialog
		{
			Q_OBJECT

		public:
			enum ImsWindowFlag{
				WindowToolClose		= 0x00000001,
				WindowToolMax		= 0x00000002,
				WindowToolMin		= 0x00000004,
				WindowToolNor		= 0x00000008,
				WindowToolSkin		= 0x00000010,
				WindowToolSet		= 0x00000020,
				WindowToolIcon		= 0x00000040,
			};

			CUiBaseDialog(QWidget *parent = 0);
			virtual ~CUiBaseDialog();

		protected:
			virtual void createTitleBar(QWidget *parent,uint flag,QString title = "");
			virtual void resizeEvent(QResizeEvent *event);
			virtual void mousePressEvent(QMouseEvent *event);
			virtual void mouseMoveEvent(QMouseEvent *event);
			virtual void mouseReleaseEvent(QMouseEvent *event);

			protected slots:	
				virtual void doToolButtonMax();
				virtual void doToolButtonNor();
				virtual void doToolButtonClose();
				virtual void doToolButtonSet(){}
				virtual void doToolButtonSkin(){}
		protected:
			bool		mMoveing;
			QPoint	    mMovePosition;
			QLabel		*mLabelIcon;
			QLabel		*mLabelTitle;
			QToolButton *mToolButtonClose;
			QToolButton *mToolButtonMax;
			QToolButton *mToolButtonMin;
			QToolButton *mToolButtonNor;
			QToolButton *mToolButtonSkin;
			QToolButton *mToolButtonSet;
			QPixmap		*mBroudGroundPixmap;
			QWidget		*mBroudGroundWidget;
		};
	}
}
#endif // BASEDIALOG_H
