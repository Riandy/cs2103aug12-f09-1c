/********************************************************************************
** Form generated from reading UI file 'standardview.ui'
**
** Created: Sun Oct 21 19:05:47 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STANDARDVIEW_H
#define UI_STANDARDVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>
#include "sframe.h"
#include "slineedit.h"

QT_BEGIN_NAMESPACE

class Ui_StandardView
{
public:
    Sframe *frame;
    QFrame *line;
    QFrame *frame_2;
    SLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *frame_3;
    QLabel *label_7;
    QWidget *tab_2;
    QLabel *label_5;
    QLabel *label_6;
    QTableWidget *tableWidget;
    QFrame *frame_4;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *StandardView)
    {
        if (StandardView->objectName().isEmpty())
            StandardView->setObjectName(QString::fromUtf8("StandardView"));
        StandardView->resize(895, 593);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/bg/calendar.gif"), QSize(), QIcon::Normal, QIcon::Off);
        StandardView->setWindowIcon(icon);
        frame = new Sframe(StandardView);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 811, 571));
        frame->setStyleSheet(QString::fromUtf8("#frame\n"
"{\n"
"	background-image: url(:/bg/scenary.jpg);\n"
"	border-radius: 40px;\n"
"	 border-style: groove;\n"
"     border-width: 4px;\n"
"     border-color:rgb(203, 203, 203); \n"
"\n"
"   \n"
"	\n"
"}"));
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(5, 30, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 40, 811, 531));
        lineEdit = new SLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 60, 701, 31));
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
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(330, 4, 151, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("AR JULIAN"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("#label_2\n"
"{\n"
"	\n"
"}"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(49, 93, 451, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MV Boli"));
        font2.setPointSize(9);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("#label_2\n"
"{\n"
"\n"
"}"));
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        tabWidget = new QTabWidget(frame_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(40, 130, 731, 381));
        tabWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab:first {\n"
"background-color: qlineargradient(spread:pad, x1:0.528, y1:1, x2:0.534091, y2:0, stop:0 rgba(255, 111, 111, 255), stop:0.369318 rgba(225, 0, 0, 255), stop:0.636364 rgba(255, 0, 0, 255), stop:0.977273 rgba(255, 95, 95, 255));\n"
"\n"
"border: 4px; \n"
"border-color: rgb(152, 0, 0);\n"
"border-style:outset;  \n"
"border-top-left-radius: 30px;\n"
"border-top-right-radius: 10px;\n"
"min-width: 364px;\n"
"min-height: 30px;\n"
"}\n"
"\n"
"QTabBar::tab:first:selected, QTabBar::tab:first:hover {\n"
"	background-color: qlineargradient(spread:pad, x1:0.528, y1:1, x2:0.534091, y2:0, stop:0 rgba(255, 104, 104, 255), stop:0.369318 rgba(225, 22, 22, 255), stop:0.636364 rgba(255, 23, 23, 255), stop:0.977273 rgba(255, 99, 99, 255));\n"
"}\n"
"\n"
"QTabBar::tab:last {\n"
"	\n"
"	background-color: qlineargradient(spread:pad, x1:0.528, y1:1, x2:0.534091, y2:0, stop:0 rgba(109, 191, 64, 255), stop:0.369318 rgba(15, 155, 13, 255), stop:0.636364 rgba(12, 151, 22, 255), stop:0.977273 rgba(104, 192, 57, 255))"
                        ";\n"
"border: 4px; \n"
"border-color:  rgb(0, 85, 0);\n"
"border-style:outset;  \n"
"border-top-left-radius: 30px;\n"
"border-top-right-radius: 10px;\n"
"min-width: 364px;\n"
"min-height: 30px;\n"
"}\n"
"\n"
"QTabBar::tab:last:selected, QTabBar::tab:last:hover {\n"
"	background-color: qlineargradient(spread:pad, x1:0.528, y1:1, x2:0.534091, y2:0, stop:0 rgba(132, 191, 100, 255), stop:0.369318 rgba(32, 155, 30, 255), stop:0.636364 rgba(34, 151, 42, 255), stop:0.977273 rgba(137, 192, 107, 255));\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"margin-top: 10px; /* make non-selected tabs look smaller */\n"
"}\n"
"QTabBar::tab:first:selected {\n"
"margin-left: 0px; \n"
"margin-right: -15px;\n"
"}\n"
"\n"
"QTabBar::tab:last:selected {\n"
"margin-left: -15px; \n"
"margin-right: 0px;\n"
"}\n"
"\n"
"QTabBar::tab:only-one {\n"
"margin: 0; /* if there is only one tab, we don't want overlapping margins */\n"
"}"));
        tabWidget->setIconSize(QSize(16, 17));
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        frame_3 = new QFrame(tab);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(0, 0, 728, 331));
        frame_3->setStyleSheet(QString::fromUtf8("#frame_3\n"
"{\n"
"	background-color: rgb(255, 170, 0);\n"
"	 border-style: ridge;\n"
"     border-width: 4px;\n"
"     border-color:  rgb(255, 0, 0);\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(190, 120, 391, 81));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(5, 1, 41, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Palatino Linotype"));
        font3.setPointSize(12);
        label_5->setFont(font3);
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(319, 1, 111, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Palatino Linotype"));
        font4.setPointSize(14);
        label_6->setFont(font4);
        tableWidget = new QTableWidget(tab_2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(3, 30, 721, 297));
        tableWidget->setStyleSheet(QString::fromUtf8("#tableWidget\n"
"{\n"
"	\n"
"	\n"
"	background-color: rgb(222, 255, 190);\n"
"\n"
"}"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setProperty("showDropIndicator", QVariant(false));
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(350);
        tableWidget->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(25);
        frame_4 = new QFrame(tab_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(0, 0, 728, 331));
        frame_4->setStyleSheet(QString::fromUtf8("#frame_4\n"
"{\n"
"	background-color: rgb(170, 255, 127);\n"
"	 border-style: ridge;\n"
"     border-width: 4px;\n"
"     border-color: rgb(170, 170, 0);\n"
"}"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(170, 130, 391, 81));
        tabWidget->addTab(tab_2, QString());
        frame_4->raise();
        label_5->raise();
        label_6->raise();
        tableWidget->raise();
        label_8->raise();
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(-10, -4, 821, 51));
        label_4->setStyleSheet(QString::fromUtf8("#label_4\n"
"{\n"
"	background-image: url(:/bg/testtitle.gif);\n"
"}"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 10, 71, 21));
        label_3->setStyleSheet(QString::fromUtf8("#label_3\n"
"{\n"
"	background-image: url(:/bg/small.gif);\n"
"}"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(724, 10, 20, 20));
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/bg/toSmall.gif"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(757, 10, 20, 20));
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/bg/exit.gif"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setCheckable(false);
        pushButton->setAutoDefault(false);
        pushButton->setDefault(false);
        pushButton->setFlat(false);

        retranslateUi(StandardView);
        QObject::connect(pushButton, SIGNAL(clicked()), StandardView, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StandardView);
    } // setupUi

    void retranslateUi(QWidget *StandardView)
    {
        StandardView->setWindowTitle(QApplication::translate("StandardView", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("StandardView", "Enter your commands here", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lineEdit->setProperty("text", QVariant(QString()));
        label_2->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'AR JULIAN'; font-size:16pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MV BOLI'; font-size:10pt; font-weight:400;\">Sunday 30-09-12</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MV BOLI'; font-size:14pt;\">16:40</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MV Boli'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ffaa00;\">Available Commands: add, delete, mark, unmark, edit and find</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#555500;\">Our greatest glory is not in never falling,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#555500;\"> but in getting up every time we do.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("StandardView", "Event for the day", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Palatino Linotype'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#aa0000;\">S/N</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Palatino Linotype'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#aa0000;\">RESULTS</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("StandardView", "Command Results", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label_3->setText(QString());
        pushButton_2->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StandardView: public Ui_StandardView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STANDARDVIEW_H
