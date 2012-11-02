/********************************************************************************
** Form generated from reading UI file 'standardview.ui'
**
** Created: Fri Nov 2 18:08:09 2012
**      by: Qt User Interface Compiler version 4.8.0
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
#include <QtGui/QWidget>
#include "sframe.h"
#include "slineedit.h"
#include "stimelabel.h"

QT_BEGIN_NAMESPACE

class Ui_StandardView
{
public:
    Sframe *frame;
    QFrame *line;
    QFrame *frame_2;
    SLineEdit *lineEdit;
    STimeLabel *label_2;
    QLabel *label;
    QFrame *frame_3;
    QFrame *frame_14;
    QFrame *frame_4;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_14;
    QLabel *label_11;
    QLabel *label_26;
    QLabel *label_17;
    QLabel *label_19;
    QLabel *label_21;
    QLabel *label_20;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_8;
    QLabel *label_24;
    QLabel *label_18;
    QLabel *label_16;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_15;
    QLabel *label_25;
    QLabel *label_27;
    QLabel *label_6;
    QLabel *label_5;
    QFrame *frame_15;
    QFrame *frame_16;
    QFrame *frame_13;
    QFrame *frame_12;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_32;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_44;
    QLabel *label_43;
    QLabel *label_42;
    QLabel *label_45;
    QLabel *label_46;
    QLabel *label_47;
    QLabel *label_48;
    QLabel *label_49;
    QLabel *label_50;
    QLabel *label_51;
    QLabel *label_52;
    QLabel *label_53;
    QLabel *label_54;
    QLabel *label_55;
    QLabel *label_56;
    QLabel *label_57;
    QLabel *label_58;
    QLabel *label_59;
    QLabel *label_60;
    QLabel *label_62;
    QLabel *label_63;
    QLabel *label_64;
    QLabel *label_29;
    QFrame *frame_5;
    QLabel *label_28;
    QFrame *frame_6;
    QFrame *frame_7;
    QFrame *frame_8;
    QFrame *frame_10;
    QFrame *frame_9;
    QFrame *frame_11;
    QLabel *label_4;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *StandardView)
    {
        if (StandardView->objectName().isEmpty())
            StandardView->setObjectName(QString::fromUtf8("StandardView"));
        StandardView->resize(1580, 1297);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/bg/calendar.gif"), QSize(), QIcon::Normal, QIcon::Off);
        StandardView->setWindowIcon(icon);
        frame = new Sframe(StandardView);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 811, 641));
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
        frame_2->setGeometry(QRect(0, 40, 811, 601));
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
        label_2 = new STimeLabel(frame_2);
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
        label->setGeometry(QRect(49, 93, 701, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MV Boli"));
        font2.setPointSize(9);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("#label_2\n"
"{\n"
"\n"
"}"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(40, 140, 731, 421));
        frame_3->setStyleSheet(QString::fromUtf8("#frame_3\n"
"{\n"
"	\n"
"	background-image: url(:/bg/Background.gif);\n"
"\n"
"\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_14 = new QFrame(frame_3);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setGeometry(QRect(18, 13, 701, 397));
        frame_14->setStyleSheet(QString::fromUtf8(""));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(frame_14);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(11, 62, 681, 281));
        frame_4->setStyleSheet(QString::fromUtf8("#frame_4\n"
"{\n"
"	\n"
"	background-image: url(:/bg/Note layout.gif);\n"
"}"));
        frame_4->setFrameShape(QFrame::Panel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(59, 0, 601, 29));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Simplified Arabic"));
        font3.setPointSize(10);
        label_7->setFont(font3);
        label_7->setStyleSheet(QString::fromUtf8(""));
        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(59, 79, 601, 29));
        label_10->setFont(font3);
        label_10->setStyleSheet(QString::fromUtf8(""));
        label_14 = new QLabel(frame_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(59, 187, 601, 29));
        label_14->setFont(font3);
        label_14->setStyleSheet(QString::fromUtf8(""));
        label_11 = new QLabel(frame_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(59, 106, 601, 29));
        label_11->setFont(font3);
        label_11->setStyleSheet(QString::fromUtf8(""));
        label_26 = new QLabel(frame_4);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(-1, 241, 48, 29));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        label_26->setFont(font4);
        label_26->setStyleSheet(QString::fromUtf8(""));
        label_26->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(frame_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(0, 0, 48, 29));
        label_17->setFont(font4);
        label_17->setStyleSheet(QString::fromUtf8(""));
        label_17->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(frame_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(0, 53, 48, 29));
        label_19->setFont(font4);
        label_19->setStyleSheet(QString::fromUtf8(""));
        label_19->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(frame_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(0, 106, 48, 29));
        label_21->setFont(font4);
        label_21->setStyleSheet(QString::fromUtf8(""));
        label_21->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(frame_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(0, 79, 48, 29));
        label_20->setFont(font4);
        label_20->setStyleSheet(QString::fromUtf8(""));
        label_20->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(frame_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(0, 133, 48, 29));
        label_22->setFont(font4);
        label_22->setStyleSheet(QString::fromUtf8(""));
        label_22->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(frame_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(0, 160, 48, 29));
        label_23->setFont(font4);
        label_23->setStyleSheet(QString::fromUtf8(""));
        label_23->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(59, 27, 601, 29));
        label_8->setFont(font3);
        label_8->setStyleSheet(QString::fromUtf8(""));
        label_24 = new QLabel(frame_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(0, 187, 48, 29));
        label_24->setFont(font4);
        label_24->setStyleSheet(QString::fromUtf8(""));
        label_24->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(frame_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(0, 27, 48, 29));
        label_18->setFont(font4);
        label_18->setStyleSheet(QString::fromUtf8(""));
        label_18->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(frame_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(59, 241, 601, 29));
        label_16->setFont(font3);
        label_16->setStyleSheet(QString::fromUtf8(""));
        label_9 = new QLabel(frame_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(59, 53, 601, 29));
        label_9->setFont(font3);
        label_9->setStyleSheet(QString::fromUtf8(""));
        label_13 = new QLabel(frame_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(59, 160, 601, 29));
        label_13->setFont(font3);
        label_13->setStyleSheet(QString::fromUtf8(""));
        label_12 = new QLabel(frame_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(59, 133, 601, 29));
        label_12->setFont(font3);
        label_12->setStyleSheet(QString::fromUtf8(""));
        label_15 = new QLabel(frame_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(59, 214, 601, 29));
        label_15->setFont(font3);
        label_15->setStyleSheet(QString::fromUtf8(""));
        label_25 = new QLabel(frame_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(0, 214, 48, 29));
        label_25->setFont(font4);
        label_25->setStyleSheet(QString::fromUtf8(""));
        label_25->setAlignment(Qt::AlignCenter);
        label_27 = new QLabel(frame_14);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(267, 349, 171, 42));
        label_27->setStyleSheet(QString::fromUtf8("#label_27\n"
"{\n"
"	background-image: url(:/bg/Torn for num.gif);\n"
"}"));
        label_27->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(frame_14);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 10, 61, 42));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Levenim MT"));
        font5.setPointSize(16);
        label_6->setFont(font5);
        label_6->setStyleSheet(QString::fromUtf8("#label_6\n"
"{\n"
"	background-image: url(:/bg/SN Slip.gif);\n"
"\n"
"\n"
"}"));
        label_5 = new QLabel(frame_14);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(239, 10, 231, 42));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Levenim MT"));
        label_5->setFont(font6);
        label_5->setStyleSheet(QString::fromUtf8("#label_5\n"
"{\n"
"	\n"
"	background-image: url(:/bg/Results Slip.gif);\n"
"\n"
"\n"
"}"));
        frame_15 = new QFrame(frame_14);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setGeometry(QRect(29, 334, 169, 32));
        frame_15->setStyleSheet(QString::fromUtf8("#frame_15\n"
"{\n"
"	\n"
"	background-image: url(:/bg/tape.gif);\n"
"}"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        frame_16 = new QFrame(frame_14);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setGeometry(QRect(600, 40, 56, 30));
        frame_16->setStyleSheet(QString::fromUtf8("#frame_16\n"
"{\n"
"	\n"
"	background-image: url(:/bg/tape_2.gif);\n"
"}"));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        frame_13 = new QFrame(frame_3);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setGeometry(QRect(17, 13, 701, 401));
        frame_13->setStyleSheet(QString::fromUtf8(""));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        frame_12 = new QFrame(frame_13);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setGeometry(QRect(30, 44, 651, 301));
        frame_12->setStyleSheet(QString::fromUtf8("#frame_12\n"
"{\n"
"	background-image: url(:/bg/help_layout.gif);\n"
"\n"
"}"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        label_30 = new QLabel(frame_12);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(62, 89, 111, 91));
        label_30->setFrameShape(QFrame::NoFrame);
        label_30->setFrameShadow(QFrame::Raised);
        label_31 = new QLabel(frame_12);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(48, 202, 111, 91));
        label_31->setFrameShape(QFrame::NoFrame);
        label_31->setFrameShadow(QFrame::Raised);
        label_33 = new QLabel(frame_12);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(63, 162, 35, 23));
        label_33->setStyleSheet(QString::fromUtf8("#label_33\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_34 = new QLabel(frame_12);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(49, 274, 35, 23));
        label_34->setStyleSheet(QString::fromUtf8("#label_34\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_35 = new QLabel(frame_12);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(102, 162, 23, 23));
        label_35->setStyleSheet(QString::fromUtf8("#label_35\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_36 = new QLabel(frame_12);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(88, 274, 23, 23));
        label_36->setStyleSheet(QString::fromUtf8("#label_36\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_37 = new QLabel(frame_12);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(315, 105, 35, 23));
        label_37->setStyleSheet(QString::fromUtf8("#label_37\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_38 = new QLabel(frame_12);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(354, 105, 23, 23));
        label_38->setStyleSheet(QString::fromUtf8("#label_38\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_32 = new QLabel(frame_12);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(314, 55, 111, 71));
        label_32->setFrameShape(QFrame::NoFrame);
        label_32->setFrameShadow(QFrame::Raised);
        label_39 = new QLabel(frame_12);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(181, 34, 111, 71));
        label_39->setFrameShape(QFrame::NoFrame);
        label_39->setFrameShadow(QFrame::Raised);
        label_40 = new QLabel(frame_12);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(181, 84, 35, 23));
        label_40->setStyleSheet(QString::fromUtf8("#label_40\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_41 = new QLabel(frame_12);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(220, 84, 23, 23));
        label_41->setStyleSheet(QString::fromUtf8("#label_41\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_44 = new QLabel(frame_12);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(227, 181, 23, 23));
        label_44->setStyleSheet(QString::fromUtf8("#label_44\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_43 = new QLabel(frame_12);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(188, 181, 35, 23));
        label_43->setStyleSheet(QString::fromUtf8("#label_43\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_42 = new QLabel(frame_12);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(187, 131, 161, 71));
        label_42->setFrameShape(QFrame::NoFrame);
        label_42->setFrameShadow(QFrame::Raised);
        label_45 = new QLabel(frame_12);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(294, 224, 111, 71));
        label_45->setFrameShape(QFrame::NoFrame);
        label_45->setFrameShadow(QFrame::Raised);
        label_46 = new QLabel(frame_12);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(295, 274, 35, 23));
        label_46->setStyleSheet(QString::fromUtf8("#label_46\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_47 = new QLabel(frame_12);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(334, 274, 23, 23));
        label_47->setStyleSheet(QString::fromUtf8("#label_47\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_48 = new QLabel(frame_12);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(169, 223, 111, 71));
        label_48->setFrameShape(QFrame::NoFrame);
        label_48->setFrameShadow(QFrame::Raised);
        label_49 = new QLabel(frame_12);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(170, 273, 35, 23));
        label_49->setStyleSheet(QString::fromUtf8("#label_49\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_50 = new QLabel(frame_12);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(209, 273, 23, 23));
        label_50->setStyleSheet(QString::fromUtf8("#label_50\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_51 = new QLabel(frame_12);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(430, 0, 221, 301));
        label_51->setFrameShape(QFrame::StyledPanel);
        label_51->setFrameShadow(QFrame::Sunken);
        label_51->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_52 = new QLabel(frame_12);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(452, 58, 171, 41));
        label_52->setFrameShape(QFrame::NoFrame);
        label_52->setFrameShadow(QFrame::Raised);
        label_53 = new QLabel(frame_12);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(510, 80, 35, 23));
        label_53->setStyleSheet(QString::fromUtf8("#label_53\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_54 = new QLabel(frame_12);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(550, 80, 23, 23));
        label_54->setStyleSheet(QString::fromUtf8("#label_54\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_55 = new QLabel(frame_12);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(513, 148, 35, 23));
        label_55->setStyleSheet(QString::fromUtf8("#label_55\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_56 = new QLabel(frame_12);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(553, 148, 23, 23));
        label_56->setStyleSheet(QString::fromUtf8("#label_56\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_57 = new QLabel(frame_12);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(431, 125, 221, 41));
        label_57->setFrameShape(QFrame::NoFrame);
        label_57->setFrameShadow(QFrame::Raised);
        label_58 = new QLabel(frame_12);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(552, 274, 23, 23));
        label_58->setStyleSheet(QString::fromUtf8("#label_58\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_59 = new QLabel(frame_12);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(512, 274, 35, 23));
        label_59->setStyleSheet(QString::fromUtf8("#label_59\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_60 = new QLabel(frame_12);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(430, 251, 221, 41));
        label_60->setFrameShape(QFrame::NoFrame);
        label_60->setFrameShadow(QFrame::Raised);
        label_62 = new QLabel(frame_12);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setGeometry(QRect(501, 213, 35, 23));
        label_62->setStyleSheet(QString::fromUtf8("#label_62\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_63 = new QLabel(frame_12);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(436, 189, 221, 41));
        label_63->setFrameShape(QFrame::NoFrame);
        label_63->setFrameShadow(QFrame::Raised);
        label_64 = new QLabel(frame_12);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        label_64->setGeometry(QRect(560, 213, 35, 23));
        label_64->setStyleSheet(QString::fromUtf8("#label_64\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_29 = new QLabel(frame_13);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(40, 34, 151, 102));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Comic Sans MS"));
        label_29->setFont(font7);
        label_29->setStyleSheet(QString::fromUtf8("#label_29\n"
"{\n"
"	\n"
"	background-image: url(:/bg/note_6.gif);\n"
"}"));
        label_29->setAlignment(Qt::AlignCenter);
        frame_12->raise();
        label_29->raise();
        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(17, 13, 701, 401));
        frame_5->setStyleSheet(QString::fromUtf8(""));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label_28 = new QLabel(frame_5);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(250, 10, 181, 51));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Aharoni"));
        font8.setPointSize(16);
        font8.setBold(true);
        font8.setWeight(75);
        label_28->setFont(font8);
        label_28->setStyleSheet(QString::fromUtf8("#label_28\n"
"{\n"
"	\n"
"	background-image: url(:/bg/Today.gif);\n"
"\n"
"}"));
        frame_6 = new QFrame(frame_5);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(470, 20, 161, 168));
        frame_6->setStyleSheet(QString::fromUtf8("background-image: url(:/bg/Note_2.gif);"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        frame_7 = new QFrame(frame_5);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(380, 210, 161, 168));
        frame_7->setStyleSheet(QString::fromUtf8("background-image: url(:/bg/Note_2.gif);"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        frame_8 = new QFrame(frame_5);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(10, 10, 161, 168));
        frame_8->setStyleSheet(QString::fromUtf8("background-image: url(:/bg/Note_2.gif);"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        frame_10 = new QFrame(frame_5);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setGeometry(QRect(20, 190, 140, 119));
        frame_10->setStyleSheet(QString::fromUtf8("background-image: url(:/bg/Note_4.gif);"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        frame_9 = new QFrame(frame_5);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setGeometry(QRect(190, 110, 180, 245));
        frame_9->setStyleSheet(QString::fromUtf8("background-image: url(:/bg/Note_3.gif);"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        frame_11 = new QFrame(frame_5);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setGeometry(QRect(555, 210, 140, 119));
        frame_11->setStyleSheet(QString::fromUtf8("background-image: url(:/bg/Note_4.gif)"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        lineEdit->raise();
        label_2->raise();
        label->raise();
        frame_3->raise();
        frame_5->raise();
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

        QMetaObject::connectSlotsByName(StandardView);
    } // setupUi

    void retranslateUi(QWidget *StandardView)
    {
        StandardView->setWindowTitle(QApplication::translate("StandardView", "Form", 0, QApplication::UnicodeUTF8));
        lineEdit->setProperty("text", QVariant(QString()));
        label_2->setProperty("text", QVariant(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'AR JULIAN'; font-size:16pt; font-weight:600;\"></p></body></html>", 0, QApplication::UnicodeUTF8)));
        label->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MV Boli'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ffaa00;\">Available Commands: add, delete, mark, unmark, edit and find</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_7->setText(QString());
        label_10->setText(QString());
        label_14->setText(QString());
        label_11->setText(QString());
        label_26->setText(QString());
        label_17->setText(QString());
        label_19->setText(QString());
        label_21->setText(QString());
        label_20->setText(QString());
        label_22->setText(QString());
        label_23->setText(QString());
        label_8->setText(QString());
        label_24->setText(QString());
        label_18->setText(QString());
        label_16->setText(QString());
        label_9->setText(QString());
        label_13->setText(QString());
        label_12->setText(QString());
        label_15->setText(QString());
        label_25->setText(QString());
        label_27->setText(QString());
        label_6->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Levenim MT'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#aa0000;\">S/N</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Levenim MT'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; color:#aa0000;\">RESULTS</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">ADD  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"> add [task]</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-lef"
                        "t:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"> [task]</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  CTRL      A     [task]</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">DELETE  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"> del [task]</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-"
                        "left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"> del [event number]</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  CTRL      D    [task]</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_33->setText(QString());
        label_34->setText(QString());
        label_35->setText(QString());
        label_36->setText(QString());
        label_37->setText(QString());
        label_38->setText(QString());
        label_32->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">FIND  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"> find [task]</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-l"
                        "eft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  CTRL      F     [task]</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">DISPLAY COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"> dsp</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0p"
                        "x; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  CTRL      B</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_40->setText(QString());
        label_41->setText(QString());
        label_44->setText(QString());
        label_43->setText(QString());
        label_42->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">EDIT  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"> edit [task] [new details]</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom"
                        ":0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  CTRL      E     [task] [new details]</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">UNDO  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"> undo</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px"
                        "; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  CTRL      1</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_46->setText(QString());
        label_47->setText(QString());
        label_48->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">REDO  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"> redo</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px"
                        "; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  CTRL      2</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_49->setText(QString());
        label_50->setText(QString());
        label_51->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600; color:#550000;\">APPLICATION LEVEL KEYS</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_52->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">SWITCHING USER INTERFACES</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  CTRL      S</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_53->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_54->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_55->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_56->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_57->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">SWITCHING TODAY EVENTS/RESULTS</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  CTRL      W</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_58->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_59->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_60->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">CLEARING INPUT BAR</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  CTRL      L</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_62->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_63->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">SCROLLING RESULTS</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  PgUp    or    PgDn</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_64->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#00007f;\">HELP</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Aharoni'; font-size:16pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt; color:#550000;\">TODAY</span></p></body></html>", 0, QApplication::UnicodeUTF8));
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
