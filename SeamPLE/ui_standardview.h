/********************************************************************************
** Form generated from reading UI file 'standardview.ui'
**
** Created: Thu Oct 11 16:30:56 2012
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
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StandardView
{
public:
    QFrame *frame;
    QFrame *line;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *frame_2;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QWidget *StandardView)
    {
        if (StandardView->objectName().isEmpty())
            StandardView->setObjectName(QString::fromUtf8("StandardView"));
        StandardView->resize(895, 593);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/bg/calendar.gif"), QSize(), QIcon::Normal, QIcon::Off);
        StandardView->setWindowIcon(icon);
        frame = new QFrame(StandardView);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 831, 561));
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
        line->setGeometry(QRect(5, 30, 481, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(440, 10, 20, 20));
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
        label_3->setGeometry(QRect(210, 10, 71, 21));
        label_3->setStyleSheet(QString::fromUtf8("#label_3\n"
"{\n"
"	background-image: url(:/bg/small.gif);\n"
"}"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(-6, -8, 491, 51));
        label_4->setStyleSheet(QString::fromUtf8("#label_4\n"
"{\n"
"	background-image: url(:/bg/testtitle.gif);\n"
"}"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 40, 491, 121));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 60, 401, 31));
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
        label_2->setGeometry(QRect(330, 0, 151, 51));
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
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 10, 20, 20));
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
        icon2.addFile(QString::fromUtf8(":/bg/toSmall.gif"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        label_4->raise();
        pushButton->raise();
        label_3->raise();
        line->raise();
        frame_2->raise();
        pushButton_2->raise();

        retranslateUi(StandardView);
        QObject::connect(pushButton, SIGNAL(clicked()), StandardView, SLOT(close()));

        QMetaObject::connectSlotsByName(StandardView);
    } // setupUi

    void retranslateUi(QWidget *StandardView)
    {
        StandardView->setWindowTitle(QApplication::translate("StandardView", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("StandardView", "Enter your commands here", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lineEdit->setText(QString());
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
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StandardView: public Ui_StandardView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STANDARDVIEW_H
