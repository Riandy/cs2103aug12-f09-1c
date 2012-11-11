/********************************************************************************
** Form generated from reading UI file 'seampleview.ui'
**
** Created: Sun Nov 11 22:37:29 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEAMPLEVIEW_H
#define UI_SEAMPLEVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>
#include "slineedit.h"
#include "stimelabel.h"

QT_BEGIN_NAMESPACE

class Ui_SeampleView
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QFrame *line;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *frame_2;
    SLineEdit *lineEdit;
    QLabel *label;
    STimeLabel *label_2;
    QLabel *label_130;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *SeampleView)
    {
        if (SeampleView->objectName().isEmpty())
            SeampleView->setObjectName(QString::fromUtf8("SeampleView"));
        SeampleView->setWindowModality(Qt::NonModal);
        SeampleView->setEnabled(true);
        SeampleView->resize(626, 237);
        SeampleView->setCursor(QCursor(Qt::ArrowCursor));
        SeampleView->setContextMenuPolicy(Qt::DefaultContextMenu);
        SeampleView->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/bg/calendar.gif"), QSize(), QIcon::Normal, QIcon::Off);
        SeampleView->setWindowIcon(icon);
        SeampleView->setWindowOpacity(1);
        SeampleView->setLayoutDirection(Qt::LeftToRight);
        SeampleView->setAutoFillBackground(false);
        SeampleView->setStyleSheet(QString::fromUtf8("#centralWidget\n"
"{\n"
"	\n"
"}"));
        SeampleView->setDocumentMode(false);
        SeampleView->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(SeampleView);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(70, 20, 491, 201));
        frame->setStyleSheet(QString::fromUtf8("#frame\n"
"{\n"
"	background-image: url(:/bg/scenary.jpg);\n"
"	 border-style: groove;\n"
"     border-width: 4px;\n"
"     border-color:rgb(203, 203, 203); \n"
"\n"
"   \n"
"	\n"
"}"));
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(5, 30, 481, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(452, 11, 20, 20));
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton\n"
"{\n"
"	border-style: solid;\n"
"	border-radius: 5px;\n"
"	border-width: 3px;\n"
"	border-color: gray;\n"
"}\n"
"#pushButton:hover \n"
"{\n"
"	border-style: outset;\n"
"	border-radius: 5px;\n"
"	border-width:3px;\n"
"	border-color: gray;\n"
"}\n"
"\n"
"#pushButton:pressed \n"
"{\n"
"	border-style: inset;\n"
"	border-radius: 5px;\n"
"	border-width:3px;\n"
"	border-color: gray;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/bg/exit.gif"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setCheckable(false);
        pushButton->setAutoDefault(false);
        pushButton->setDefault(false);
        pushButton->setFlat(false);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 10, 71, 21));
        label_3->setStyleSheet(QString::fromUtf8("#label_3\n"
"{\n"
"	background-image: url(:/bg/small.gif);\n"
"}"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(-5, -8, 491, 51));
        label_4->setStyleSheet(QString::fromUtf8("#label_4\n"
"{\n"
"	background-image: url(:/bg/2nd_testtitle.gif);\n"
"}"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 40, 491, 161));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        lineEdit = new SLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 62, 451, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(12);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("#lineEdit \n"
"{\n"
"	border-radius: 10px;\n"
"	border-style: ridge;\n"
"    border-width: 4px;\n"
"    border-color: rgb(84, 84, 84); \n"
"	\n"
"	\n"
"	background-color: rgb(170, 85, 0);\n"
"}\n"
""));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(21, 94, 451, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("#label_2\n"
"{\n"
"\n"
"}"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        label_2 = new STimeLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(131, 1, 231, 56));
        QFont font2;
        font2.setFamily(QString::fromUtf8("AR JULIAN"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("#label_2\n"
"{\n"
"	\n"
"\n"
"}"));
        label_130 = new QLabel(frame_2);
        label_130->setObjectName(QString::fromUtf8("label_130"));
        label_130->setGeometry(QRect(424, 7, 46, 48));
        label_130->setStyleSheet(QString::fromUtf8("#label_130\n"
"{\n"
"	background-image: url(:/bg/Help_sign.gif);\n"
"}"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(421, 11, 20, 20));
        pushButton_2->setStyleSheet(QString::fromUtf8("#pushButton_2\n"
"{\n"
"	border-style: solid;\n"
"	border-radius: 5px;\n"
"	border-width: 3px;\n"
"	border-color: gray;\n"
"}\n"
"#pushButton_2:hover \n"
"{\n"
"	border-style: outset;\n"
"	border-radius: 5px;\n"
"	border-width:3px;\n"
"	border-color: gray;\n"
"}\n"
"\n"
"#pushButton_2:pressed \n"
"{\n"
"	border-style: inset;\n"
"	border-radius: 5px;\n"
"	border-width:3px;\n"
"	border-color: gray;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/bg/enlarge.gif"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        label_4->raise();
        pushButton->raise();
        label_3->raise();
        line->raise();
        frame_2->raise();
        pushButton_2->raise();
        SeampleView->setCentralWidget(centralWidget);

        retranslateUi(SeampleView);
        QObject::connect(pushButton, SIGNAL(clicked()), SeampleView, SLOT(close()));

        QMetaObject::connectSlotsByName(SeampleView);
    } // setupUi

    void retranslateUi(QMainWindow *SeampleView)
    {
        SeampleView->setWindowTitle(QApplication::translate("SeampleView", "Test", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        lineEdit->setProperty("text", QVariant(QString()));
        label->setText(QApplication::translate("SeampleView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gill Sans Ultra Bold Condensed'; font-size:medium; color:#ffa500;\">Press &quot;F1&quot; to access the help menu</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setProperty("text", QVariant(QApplication::translate("SeampleView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'AR JULIAN'; font-size:16pt; font-weight:600;\"></p></body></html>", 0, QApplication::UnicodeUTF8)));
        label_130->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SeampleView: public Ui_SeampleView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEAMPLEVIEW_H
