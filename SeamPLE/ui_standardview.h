/********************************************************************************
** Form generated from reading UI file 'StandardView.ui'
**
** Created: Mon Nov 12 23:17:12 2012
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
    QFrame *frame_22;
    QFrame *frame_5;
    QLabel *label_28;
    QFrame *frame_6;
    QLabel *label_69;
    QFrame *frame_10;
    QLabel *label_65;
    QLabel *label_71;
    QFrame *frame_9;
    QLabel *label_66;
    QLabel *label_70;
    QFrame *frame_11;
    QLabel *label_61;
    QLabel *label_72;
    QFrame *frame_7;
    QLabel *label_68;
    QFrame *frame_8;
    QLabel *label_67;
    QFrame *frame_23;
    QFrame *frame_18;
    QLabel *label_73;
    QLabel *label_74;
    QFrame *frame_19;
    QLabel *label_107;
    QFrame *frame_20;
    QLabel *label_108;
    QFrame *frame_21;
    QLabel *label_109;
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
    QLabel *label_77;
    QLabel *label_78;
    QLabel *label_79;
    QLabel *label_80;
    QLabel *label_81;
    QLabel *label_82;
    QLabel *label_83;
    QLabel *label_84;
    QLabel *label_85;
    QLabel *label_86;
    QLabel *label_87;
    QLabel *label_88;
    QLabel *label_89;
    QLabel *label_90;
    QLabel *label_91;
    QLabel *label_92;
    QLabel *label_93;
    QLabel *label_94;
    QLabel *label_95;
    QLabel *label_96;
    QLabel *label_97;
    QLabel *label_98;
    QLabel *label_99;
    QLabel *label_100;
    QLabel *label_101;
    QLabel *label_102;
    QLabel *label_103;
    QLabel *label_104;
    QLabel *label_105;
    QLabel *label_106;
    QLabel *label_27;
    QLabel *label_6;
    QLabel *label_5;
    QFrame *frame_15;
    QFrame *frame_16;
    QLabel *label_75;
    QLabel *label_76;
    QFrame *frame_17;
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
    QLabel *label_58;
    QLabel *label_59;
    QLabel *label_60;
    QLabel *label_51;
    QLabel *label_110;
    QLabel *label_111;
    QLabel *label_112;
    QLabel *label_113;
    QLabel *label_114;
    QLabel *label_115;
    QLabel *label_116;
    QLabel *label_117;
    QLabel *label_29;
    QLabel *label_156;
    QFrame *frame_24;
    QFrame *frame_25;
    QLabel *label_64;
    QLabel *label_52;
    QLabel *label_57;
    QLabel *label_63;
    QLabel *label_54;
    QLabel *label_56;
    QLabel *label_53;
    QLabel *label_62;
    QLabel *label_55;
    QLabel *label_129;
    QLabel *label_141;
    QLabel *label_140;
    QLabel *label_146;
    QLabel *label_143;
    QLabel *label_142;
    QLabel *label_147;
    QLabel *label_148;
    QLabel *label_149;
    QLabel *label_150;
    QLabel *label_151;
    QLabel *label_152;
    QLabel *label_153;
    QLabel *label_154;
    QLabel *label_144;
    QLabel *label_155;
    QFrame *frame_26;
    QFrame *frame_27;
    QLabel *label_118;
    QLabel *label_119;
    QLabel *label_120;
    QLabel *label_121;
    QLabel *label_122;
    QLabel *label_123;
    QLabel *label_124;
    QLabel *label_125;
    QLabel *label_126;
    QLabel *label_127;
    QLabel *label_128;
    QLabel *label_145;
    QLabel *label_157;
    QLabel *label_3;
    QLabel *label_130;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *StandardView)
    {
        if (StandardView->objectName().isEmpty())
            StandardView->setObjectName(QString::fromUtf8("StandardView"));
        StandardView->resize(3000, 1722);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/bg/calendar.gif"), QSize(), QIcon::Normal, QIcon::Off);
        StandardView->setWindowIcon(icon);
        frame = new Sframe(StandardView);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 811, 661));
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
        frame_2->setGeometry(QRect(0, 40, 811, 621));
        lineEdit = new SLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 65, 701, 31));
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
        label_2->setGeometry(QRect(280, 4, 231, 56));
        QFont font1;
        font1.setFamily(QString::fromUtf8("AR JULIAN"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("#label_2\n"
"{\n"
"\n"
"}"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(49, 98, 701, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MV Boli"));
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("#label_2\n"
"{\n"
"\n"
"}"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(40, 170, 731, 421));
        frame_3->setStyleSheet(QString::fromUtf8("#frame_3\n"
"{\n"
"	\n"
"	background-image: url(:/bg/Background.gif);\n"
"\n"
"\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_22 = new QFrame(frame_3);
        frame_22->setObjectName(QString::fromUtf8("frame_22"));
        frame_22->setGeometry(QRect(-724, 14, 2181, 397));
        frame_22->setFrameShape(QFrame::StyledPanel);
        frame_22->setFrameShadow(QFrame::Raised);
        frame_5 = new QFrame(frame_22);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(740, 0, 701, 397));
        frame_5->setStyleSheet(QString::fromUtf8(""));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label_28 = new QLabel(frame_5);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(260, 10, 181, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Aharoni"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        label_28->setFont(font3);
        label_28->setStyleSheet(QString::fromUtf8("#label_28\n"
"{\n"
"	\n"
"	background-image: url(:/bg/Today.gif);\n"
"\n"
"}"));
        frame_6 = new QFrame(frame_5);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(530, 10, 161, 168));
        frame_6->setStyleSheet(QString::fromUtf8("#frame_6\n"
"{\n"
"	background-image: url(:/bg/Note_2.gif);\n"
"}"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_69 = new QLabel(frame_6);
        label_69->setObjectName(QString::fromUtf8("label_69"));
        label_69->setGeometry(QRect(10, 30, 138, 131));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Tahoma"));
        font4.setPointSize(9);
        font4.setBold(false);
        font4.setWeight(50);
        label_69->setFont(font4);
        label_69->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        frame_10 = new QFrame(frame_5);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setGeometry(QRect(10, 62, 140, 119));
        frame_10->setStyleSheet(QString::fromUtf8("#frame_10\n"
"{\n"
"	background-image: url(:/bg/Note_4.gif);\n"
"}"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        label_65 = new QLabel(frame_10);
        label_65->setObjectName(QString::fromUtf8("label_65"));
        label_65->setGeometry(QRect(1, 79, 141, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Verdana"));
        font5.setBold(true);
        font5.setWeight(75);
        label_65->setFont(font5);
        label_71 = new QLabel(frame_10);
        label_71->setObjectName(QString::fromUtf8("label_71"));
        label_71->setGeometry(QRect(-1, 15, 141, 91));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Verdana"));
        font6.setPointSize(24);
        font6.setBold(true);
        font6.setWeight(75);
        label_71->setFont(font6);
        label_71->setAlignment(Qt::AlignCenter);
        frame_9 = new QFrame(frame_5);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setGeometry(QRect(170, 120, 180, 245));
        frame_9->setStyleSheet(QString::fromUtf8("#frame_9\n"
"{\n"
"	background-image: url(:/bg/Note_3.gif);\n"
"}"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        label_66 = new QLabel(frame_9);
        label_66->setObjectName(QString::fromUtf8("label_66"));
        label_66->setGeometry(QRect(33, 201, 141, 31));
        QFont font7;
        font7.setFamily(QString::fromUtf8("AR CHRISTY"));
        font7.setBold(false);
        font7.setWeight(50);
        label_66->setFont(font7);
        label_70 = new QLabel(frame_9);
        label_70->setObjectName(QString::fromUtf8("label_70"));
        label_70->setGeometry(QRect(13, 48, 138, 151));
        label_70->setFont(font4);
        label_70->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        frame_11 = new QFrame(frame_5);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setGeometry(QRect(10, 190, 140, 119));
        frame_11->setStyleSheet(QString::fromUtf8("#frame_11\n"
"{\n"
"	background-image: url(:/bg/Note_4.gif)\n"
"}"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        label_61 = new QLabel(frame_11);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(-3, 78, 141, 31));
        label_61->setFont(font5);
        label_72 = new QLabel(frame_11);
        label_72->setObjectName(QString::fromUtf8("label_72"));
        label_72->setGeometry(QRect(-4, 10, 141, 91));
        label_72->setFont(font6);
        label_72->setAlignment(Qt::AlignCenter);
        frame_7 = new QFrame(frame_5);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(430, 220, 161, 168));
        frame_7->setStyleSheet(QString::fromUtf8("#frame_7\n"
"{\n"
"	background-image: url(:/bg/Note_2.gif);\n"
"}"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        label_68 = new QLabel(frame_7);
        label_68->setObjectName(QString::fromUtf8("label_68"));
        label_68->setGeometry(QRect(10, 34, 138, 131));
        label_68->setFont(font4);
        label_68->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        frame_8 = new QFrame(frame_5);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(360, 60, 161, 168));
        frame_8->setStyleSheet(QString::fromUtf8("#frame_8\n"
"{\n"
"	background-image: url(:/bg/Note_2.gif);\n"
"}"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        label_67 = new QLabel(frame_8);
        label_67->setObjectName(QString::fromUtf8("label_67"));
        label_67->setGeometry(QRect(10, 30, 138, 131));
        label_67->setFont(font4);
        label_67->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        frame_23 = new QFrame(frame_22);
        frame_23->setObjectName(QString::fromUtf8("frame_23"));
        frame_23->setGeometry(QRect(1480, -438, 701, 834));
        frame_23->setFrameShape(QFrame::StyledPanel);
        frame_23->setFrameShadow(QFrame::Raised);
        frame_18 = new QFrame(frame_23);
        frame_18->setObjectName(QString::fromUtf8("frame_18"));
        frame_18->setGeometry(QRect(-1, 0, 701, 397));
        frame_18->setFrameShape(QFrame::StyledPanel);
        frame_18->setFrameShadow(QFrame::Raised);
        label_73 = new QLabel(frame_18);
        label_73->setObjectName(QString::fromUtf8("label_73"));
        label_73->setGeometry(QRect(10, 10, 231, 42));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Levenim MT"));
        label_73->setFont(font8);
        label_73->setStyleSheet(QString::fromUtf8("#label_73\n"
"{\n"
"	\n"
"	background-image: url(:/bg/Results Slip.gif);\n"
"\n"
"\n"
"}"));
        label_74 = new QLabel(frame_18);
        label_74->setObjectName(QString::fromUtf8("label_74"));
        label_74->setGeometry(QRect(500, 349, 171, 42));
        label_74->setStyleSheet(QString::fromUtf8("#label_74\n"
"{\n"
"	background-image: url(:/bg/Torn for num.gif);\n"
"}"));
        label_74->setAlignment(Qt::AlignCenter);
        frame_19 = new QFrame(frame_18);
        frame_19->setObjectName(QString::fromUtf8("frame_19"));
        frame_19->setGeometry(QRect(10, 60, 207, 310));
        frame_19->setStyleSheet(QString::fromUtf8("#frame_19\n"
"{\n"
"	\n"
"	background-image: url(:/bg/Expand_note_1.gif);\n"
"}"));
        frame_19->setFrameShape(QFrame::StyledPanel);
        frame_19->setFrameShadow(QFrame::Raised);
        label_107 = new QLabel(frame_19);
        label_107->setObjectName(QString::fromUtf8("label_107"));
        label_107->setGeometry(QRect(24, 43, 161, 251));
        label_107->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        frame_20 = new QFrame(frame_18);
        frame_20->setObjectName(QString::fromUtf8("frame_20"));
        frame_20->setGeometry(QRect(246, 40, 207, 310));
        frame_20->setStyleSheet(QString::fromUtf8("#frame_20\n"
"{\n"
"	background-image: url(:/bg/Expand_note_2.gif);\n"
"}"));
        frame_20->setFrameShape(QFrame::StyledPanel);
        frame_20->setFrameShadow(QFrame::Raised);
        label_108 = new QLabel(frame_20);
        label_108->setObjectName(QString::fromUtf8("label_108"));
        label_108->setGeometry(QRect(25, 42, 161, 251));
        frame_21 = new QFrame(frame_18);
        frame_21->setObjectName(QString::fromUtf8("frame_21"));
        frame_21->setGeometry(QRect(482, 21, 207, 310));
        frame_21->setStyleSheet(QString::fromUtf8("#frame_21\n"
"{\n"
"	background-image: url(:/bg/Expand_note_3.gif);\n"
"}"));
        frame_21->setFrameShape(QFrame::StyledPanel);
        frame_21->setFrameShadow(QFrame::Raised);
        label_109 = new QLabel(frame_21);
        label_109->setObjectName(QString::fromUtf8("label_109"));
        label_109->setGeometry(QRect(21, 35, 171, 261));
        frame_14 = new QFrame(frame_23);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setGeometry(QRect(0, 438, 701, 397));
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
        label_7->setGeometry(QRect(59, 0, 245, 29));
        QFont font9;
        font9.setFamily(QString::fromUtf8("Simplified Arabic"));
        font9.setPointSize(10);
        label_7->setFont(font9);
        label_7->setStyleSheet(QString::fromUtf8(""));
        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(59, 79, 245, 29));
        label_10->setFont(font9);
        label_10->setStyleSheet(QString::fromUtf8(""));
        label_14 = new QLabel(frame_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(59, 187, 245, 29));
        label_14->setFont(font9);
        label_14->setStyleSheet(QString::fromUtf8(""));
        label_11 = new QLabel(frame_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(59, 106, 245, 29));
        label_11->setFont(font9);
        label_11->setStyleSheet(QString::fromUtf8(""));
        label_26 = new QLabel(frame_4);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(-1, 241, 48, 29));
        QFont font10;
        font10.setFamily(QString::fromUtf8("Times New Roman"));
        font10.setPointSize(10);
        font10.setBold(true);
        font10.setWeight(75);
        label_26->setFont(font10);
        label_26->setStyleSheet(QString::fromUtf8(""));
        label_26->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(frame_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(0, 0, 48, 29));
        label_17->setFont(font10);
        label_17->setStyleSheet(QString::fromUtf8(""));
        label_17->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(frame_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(0, 53, 48, 29));
        label_19->setFont(font10);
        label_19->setStyleSheet(QString::fromUtf8(""));
        label_19->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(frame_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(0, 106, 48, 29));
        label_21->setFont(font10);
        label_21->setStyleSheet(QString::fromUtf8(""));
        label_21->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(frame_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(0, 79, 48, 29));
        label_20->setFont(font10);
        label_20->setStyleSheet(QString::fromUtf8(""));
        label_20->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(frame_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(0, 133, 48, 29));
        label_22->setFont(font10);
        label_22->setStyleSheet(QString::fromUtf8(""));
        label_22->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(frame_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(0, 160, 48, 29));
        label_23->setFont(font10);
        label_23->setStyleSheet(QString::fromUtf8(""));
        label_23->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(59, 27, 245, 29));
        label_8->setFont(font9);
        label_8->setStyleSheet(QString::fromUtf8(""));
        label_24 = new QLabel(frame_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(0, 187, 48, 29));
        label_24->setFont(font10);
        label_24->setStyleSheet(QString::fromUtf8(""));
        label_24->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(frame_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(0, 27, 48, 29));
        label_18->setFont(font10);
        label_18->setStyleSheet(QString::fromUtf8(""));
        label_18->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(frame_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(59, 241, 245, 29));
        label_16->setFont(font9);
        label_16->setStyleSheet(QString::fromUtf8(""));
        label_9 = new QLabel(frame_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(59, 53, 245, 29));
        label_9->setFont(font9);
        label_9->setStyleSheet(QString::fromUtf8(""));
        label_13 = new QLabel(frame_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(59, 160, 245, 29));
        label_13->setFont(font9);
        label_13->setStyleSheet(QString::fromUtf8(""));
        label_12 = new QLabel(frame_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(59, 133, 245, 29));
        label_12->setFont(font9);
        label_12->setStyleSheet(QString::fromUtf8(""));
        label_15 = new QLabel(frame_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(59, 214, 245, 29));
        label_15->setFont(font9);
        label_15->setStyleSheet(QString::fromUtf8(""));
        label_25 = new QLabel(frame_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(0, 214, 48, 29));
        label_25->setFont(font10);
        label_25->setStyleSheet(QString::fromUtf8(""));
        label_25->setAlignment(Qt::AlignCenter);
        label_77 = new QLabel(frame_4);
        label_77->setObjectName(QString::fromUtf8("label_77"));
        label_77->setGeometry(QRect(326, 0, 141, 29));
        QFont font11;
        font11.setFamily(QString::fromUtf8("Arial"));
        font11.setPointSize(8);
        font11.setBold(true);
        font11.setWeight(75);
        label_77->setFont(font11);
        label_77->setStyleSheet(QString::fromUtf8(""));
        label_77->setAlignment(Qt::AlignCenter);
        label_78 = new QLabel(frame_4);
        label_78->setObjectName(QString::fromUtf8("label_78"));
        label_78->setGeometry(QRect(326, 27, 141, 29));
        label_78->setFont(font11);
        label_78->setStyleSheet(QString::fromUtf8(""));
        label_78->setAlignment(Qt::AlignCenter);
        label_79 = new QLabel(frame_4);
        label_79->setObjectName(QString::fromUtf8("label_79"));
        label_79->setGeometry(QRect(326, 81, 141, 29));
        label_79->setFont(font11);
        label_79->setStyleSheet(QString::fromUtf8(""));
        label_79->setAlignment(Qt::AlignCenter);
        label_80 = new QLabel(frame_4);
        label_80->setObjectName(QString::fromUtf8("label_80"));
        label_80->setGeometry(QRect(326, 54, 141, 29));
        label_80->setFont(font11);
        label_80->setStyleSheet(QString::fromUtf8(""));
        label_80->setAlignment(Qt::AlignCenter);
        label_81 = new QLabel(frame_4);
        label_81->setObjectName(QString::fromUtf8("label_81"));
        label_81->setGeometry(QRect(326, 136, 141, 29));
        label_81->setFont(font11);
        label_81->setStyleSheet(QString::fromUtf8(""));
        label_81->setAlignment(Qt::AlignCenter);
        label_82 = new QLabel(frame_4);
        label_82->setObjectName(QString::fromUtf8("label_82"));
        label_82->setGeometry(QRect(326, 190, 141, 29));
        label_82->setFont(font11);
        label_82->setStyleSheet(QString::fromUtf8(""));
        label_82->setAlignment(Qt::AlignCenter);
        label_83 = new QLabel(frame_4);
        label_83->setObjectName(QString::fromUtf8("label_83"));
        label_83->setGeometry(QRect(326, 163, 141, 29));
        label_83->setFont(font11);
        label_83->setStyleSheet(QString::fromUtf8(""));
        label_83->setAlignment(Qt::AlignCenter);
        label_84 = new QLabel(frame_4);
        label_84->setObjectName(QString::fromUtf8("label_84"));
        label_84->setGeometry(QRect(326, 109, 141, 29));
        label_84->setFont(font11);
        label_84->setStyleSheet(QString::fromUtf8(""));
        label_84->setAlignment(Qt::AlignCenter);
        label_85 = new QLabel(frame_4);
        label_85->setObjectName(QString::fromUtf8("label_85"));
        label_85->setGeometry(QRect(326, 242, 141, 29));
        label_85->setFont(font11);
        label_85->setStyleSheet(QString::fromUtf8(""));
        label_85->setAlignment(Qt::AlignCenter);
        label_86 = new QLabel(frame_4);
        label_86->setObjectName(QString::fromUtf8("label_86"));
        label_86->setGeometry(QRect(326, 215, 141, 29));
        label_86->setFont(font11);
        label_86->setStyleSheet(QString::fromUtf8(""));
        label_86->setAlignment(Qt::AlignCenter);
        label_87 = new QLabel(frame_4);
        label_87->setObjectName(QString::fromUtf8("label_87"));
        label_87->setGeometry(QRect(477, 110, 141, 29));
        label_87->setFont(font11);
        label_87->setStyleSheet(QString::fromUtf8(""));
        label_87->setAlignment(Qt::AlignCenter);
        label_88 = new QLabel(frame_4);
        label_88->setObjectName(QString::fromUtf8("label_88"));
        label_88->setGeometry(QRect(477, 28, 141, 29));
        label_88->setFont(font11);
        label_88->setStyleSheet(QString::fromUtf8(""));
        label_88->setAlignment(Qt::AlignCenter);
        label_89 = new QLabel(frame_4);
        label_89->setObjectName(QString::fromUtf8("label_89"));
        label_89->setGeometry(QRect(477, 243, 141, 29));
        label_89->setFont(font11);
        label_89->setStyleSheet(QString::fromUtf8(""));
        label_89->setAlignment(Qt::AlignCenter);
        label_90 = new QLabel(frame_4);
        label_90->setObjectName(QString::fromUtf8("label_90"));
        label_90->setGeometry(QRect(477, 82, 141, 29));
        label_90->setFont(font11);
        label_90->setStyleSheet(QString::fromUtf8(""));
        label_90->setAlignment(Qt::AlignCenter);
        label_91 = new QLabel(frame_4);
        label_91->setObjectName(QString::fromUtf8("label_91"));
        label_91->setGeometry(QRect(477, 55, 141, 29));
        label_91->setFont(font11);
        label_91->setStyleSheet(QString::fromUtf8(""));
        label_91->setAlignment(Qt::AlignCenter);
        label_92 = new QLabel(frame_4);
        label_92->setObjectName(QString::fromUtf8("label_92"));
        label_92->setGeometry(QRect(477, 216, 141, 29));
        label_92->setFont(font11);
        label_92->setStyleSheet(QString::fromUtf8(""));
        label_92->setAlignment(Qt::AlignCenter);
        label_93 = new QLabel(frame_4);
        label_93->setObjectName(QString::fromUtf8("label_93"));
        label_93->setGeometry(QRect(477, 137, 141, 29));
        label_93->setFont(font11);
        label_93->setStyleSheet(QString::fromUtf8(""));
        label_93->setAlignment(Qt::AlignCenter);
        label_94 = new QLabel(frame_4);
        label_94->setObjectName(QString::fromUtf8("label_94"));
        label_94->setGeometry(QRect(477, 191, 141, 29));
        label_94->setFont(font11);
        label_94->setStyleSheet(QString::fromUtf8(""));
        label_94->setAlignment(Qt::AlignCenter);
        label_95 = new QLabel(frame_4);
        label_95->setObjectName(QString::fromUtf8("label_95"));
        label_95->setGeometry(QRect(477, 164, 141, 29));
        label_95->setFont(font11);
        label_95->setStyleSheet(QString::fromUtf8(""));
        label_95->setAlignment(Qt::AlignCenter);
        label_96 = new QLabel(frame_4);
        label_96->setObjectName(QString::fromUtf8("label_96"));
        label_96->setGeometry(QRect(477, 1, 141, 29));
        label_96->setFont(font11);
        label_96->setStyleSheet(QString::fromUtf8(""));
        label_96->setAlignment(Qt::AlignCenter);
        label_97 = new QLabel(frame_4);
        label_97->setObjectName(QString::fromUtf8("label_97"));
        label_97->setGeometry(QRect(640, 4, 19, 22));
        label_97->setStyleSheet(QString::fromUtf8("#label_97\n"
"{\n"
"	background-image: url(:/bg/Priority.gif);\n"
"}"));
        label_98 = new QLabel(frame_4);
        label_98->setObjectName(QString::fromUtf8("label_98"));
        label_98->setGeometry(QRect(640, 29, 19, 22));
        label_98->setStyleSheet(QString::fromUtf8("#label_98\n"
"{\n"
"	background-image: url(:/bg/Priority.gif);\n"
"}"));
        label_99 = new QLabel(frame_4);
        label_99->setObjectName(QString::fromUtf8("label_99"));
        label_99->setGeometry(QRect(640, 56, 19, 22));
        label_99->setStyleSheet(QString::fromUtf8("#label_99\n"
"{\n"
"	background-image: url(:/bg/Priority.gif);\n"
"}"));
        label_100 = new QLabel(frame_4);
        label_100->setObjectName(QString::fromUtf8("label_100"));
        label_100->setGeometry(QRect(640, 83, 19, 22));
        label_100->setStyleSheet(QString::fromUtf8("#label_100\n"
"{\n"
"	background-image: url(:/bg/Priority.gif);\n"
"}"));
        label_101 = new QLabel(frame_4);
        label_101->setObjectName(QString::fromUtf8("label_101"));
        label_101->setGeometry(QRect(640, 111, 19, 22));
        label_101->setStyleSheet(QString::fromUtf8("#label_101\n"
"{\n"
"	background-image: url(:/bg/Priority.gif);\n"
"}"));
        label_102 = new QLabel(frame_4);
        label_102->setObjectName(QString::fromUtf8("label_102"));
        label_102->setGeometry(QRect(640, 165, 19, 22));
        label_102->setStyleSheet(QString::fromUtf8("#label_102\n"
"{\n"
"	background-image: url(:/bg/Priority.gif);\n"
"}"));
        label_103 = new QLabel(frame_4);
        label_103->setObjectName(QString::fromUtf8("label_103"));
        label_103->setGeometry(QRect(640, 191, 19, 22));
        label_103->setStyleSheet(QString::fromUtf8("#label_103\n"
"{\n"
"	background-image: url(:/bg/Priority.gif);\n"
"}"));
        label_104 = new QLabel(frame_4);
        label_104->setObjectName(QString::fromUtf8("label_104"));
        label_104->setGeometry(QRect(640, 138, 19, 22));
        label_104->setStyleSheet(QString::fromUtf8("#label_104\n"
"{\n"
"	background-image: url(:/bg/Priority.gif);\n"
"}"));
        label_105 = new QLabel(frame_4);
        label_105->setObjectName(QString::fromUtf8("label_105"));
        label_105->setGeometry(QRect(640, 219, 19, 22));
        label_105->setStyleSheet(QString::fromUtf8("#label_105\n"
"{\n"
"	background-image: url(:/bg/Priority.gif);\n"
"}"));
        label_106 = new QLabel(frame_4);
        label_106->setObjectName(QString::fromUtf8("label_106"));
        label_106->setGeometry(QRect(640, 246, 19, 22));
        label_106->setStyleSheet(QString::fromUtf8("#label_106\n"
"{\n"
"	background-image: url(:/bg/Priority.gif);\n"
"}"));
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
        QFont font12;
        font12.setFamily(QString::fromUtf8("Levenim MT"));
        font12.setPointSize(16);
        label_6->setFont(font12);
        label_6->setStyleSheet(QString::fromUtf8("#label_6\n"
"{\n"
"	background-image: url(:/bg/SN Slip.gif);\n"
"\n"
"\n"
"}"));
        label_5 = new QLabel(frame_14);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(81, 10, 231, 42));
        label_5->setFont(font8);
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
        frame_16->setGeometry(QRect(630, 40, 56, 30));
        frame_16->setStyleSheet(QString::fromUtf8("#frame_16\n"
"{\n"
"	\n"
"	background-image: url(:/bg/tape_2.gif);\n"
"}"));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        label_75 = new QLabel(frame_14);
        label_75->setObjectName(QString::fromUtf8("label_75"));
        label_75->setGeometry(QRect(346, 10, 131, 42));
        label_75->setFont(font8);
        label_75->setStyleSheet(QString::fromUtf8("#label_75\n"
"{	\n"
"	background-image: url(:/bg/Date Slip.gif)\n"
"}"));
        label_76 = new QLabel(frame_14);
        label_76->setObjectName(QString::fromUtf8("label_76"));
        label_76->setGeometry(QRect(493, 10, 131, 42));
        label_76->setFont(font8);
        label_76->setStyleSheet(QString::fromUtf8("#label_76\n"
"{\n"
"	background-image: url(:/bg/Date Slip.gif)\n"
"}"));
        frame_17 = new QFrame(frame_22);
        frame_17->setObjectName(QString::fromUtf8("frame_17"));
        frame_17->setGeometry(QRect(0, 0, 701, 1271));
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);
        frame_13 = new QFrame(frame_17);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setGeometry(QRect(0, 437, 701, 397));
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
        label_30->setGeometry(QRect(177, 14, 111, 91));
        label_30->setFrameShape(QFrame::NoFrame);
        label_30->setFrameShadow(QFrame::Raised);
        label_31 = new QLabel(frame_12);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(49, 176, 111, 121));
        label_31->setFrameShape(QFrame::NoFrame);
        label_31->setFrameShadow(QFrame::Raised);
        label_33 = new QLabel(frame_12);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(189, 87, 35, 23));
        label_33->setStyleSheet(QString::fromUtf8("#label_33\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_34 = new QLabel(frame_12);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(61, 278, 35, 23));
        label_34->setStyleSheet(QString::fromUtf8("#label_34\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_35 = new QLabel(frame_12);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(228, 87, 23, 23));
        label_35->setStyleSheet(QString::fromUtf8("#label_35\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_36 = new QLabel(frame_12);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(100, 278, 23, 23));
        label_36->setStyleSheet(QString::fromUtf8("#label_36\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_37 = new QLabel(frame_12);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(381, 62, 35, 23));
        label_37->setStyleSheet(QString::fromUtf8("#label_37\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_38 = new QLabel(frame_12);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(420, 62, 23, 23));
        label_38->setStyleSheet(QString::fromUtf8("#label_38\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_32 = new QLabel(frame_12);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(370, 14, 111, 91));
        label_32->setFrameShape(QFrame::NoFrame);
        label_32->setFrameShadow(QFrame::Raised);
        label_39 = new QLabel(frame_12);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(517, 10, 111, 71));
        label_39->setFrameShape(QFrame::NoFrame);
        label_39->setFrameShadow(QFrame::Raised);
        label_40 = new QLabel(frame_12);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(528, 60, 35, 23));
        label_40->setStyleSheet(QString::fromUtf8("#label_40\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_41 = new QLabel(frame_12);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(567, 60, 23, 23));
        label_41->setStyleSheet(QString::fromUtf8("#label_41\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_44 = new QLabel(frame_12);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(520, 160, 23, 23));
        label_44->setStyleSheet(QString::fromUtf8("#label_44\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_43 = new QLabel(frame_12);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(481, 160, 35, 23));
        label_43->setStyleSheet(QString::fromUtf8("#label_43\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_42 = new QLabel(frame_12);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(470, 110, 171, 71));
        label_42->setFrameShape(QFrame::NoFrame);
        label_42->setFrameShadow(QFrame::Raised);
        label_45 = new QLabel(frame_12);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(294, 210, 111, 71));
        label_45->setFrameShape(QFrame::NoFrame);
        label_45->setFrameShadow(QFrame::Raised);
        label_46 = new QLabel(frame_12);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(306, 260, 35, 23));
        label_46->setStyleSheet(QString::fromUtf8("#label_46\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_47 = new QLabel(frame_12);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(345, 260, 23, 23));
        label_47->setStyleSheet(QString::fromUtf8("#label_47\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_48 = new QLabel(frame_12);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(186, 209, 111, 71));
        label_48->setFrameShape(QFrame::NoFrame);
        label_48->setFrameShadow(QFrame::Raised);
        label_49 = new QLabel(frame_12);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(197, 259, 35, 23));
        label_49->setStyleSheet(QString::fromUtf8("#label_49\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_50 = new QLabel(frame_12);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(236, 259, 23, 23));
        label_50->setStyleSheet(QString::fromUtf8("#label_50\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_58 = new QLabel(frame_12);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(459, 235, 23, 23));
        label_58->setStyleSheet(QString::fromUtf8("#label_58\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_59 = new QLabel(frame_12);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(419, 235, 35, 23));
        label_59->setStyleSheet(QString::fromUtf8("#label_59\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_60 = new QLabel(frame_12);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(410, 212, 101, 41));
        label_60->setFrameShape(QFrame::NoFrame);
        label_60->setFrameShadow(QFrame::Raised);
        label_51 = new QLabel(frame_12);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(381, 88, 35, 23));
        label_51->setStyleSheet(QString::fromUtf8("#label_51\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_110 = new QLabel(frame_12);
        label_110->setObjectName(QString::fromUtf8("label_110"));
        label_110->setGeometry(QRect(420, 88, 23, 23));
        label_110->setStyleSheet(QString::fromUtf8("#label_110\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_111 = new QLabel(frame_12);
        label_111->setObjectName(QString::fromUtf8("label_111"));
        label_111->setGeometry(QRect(52, 86, 111, 71));
        label_111->setFrameShape(QFrame::NoFrame);
        label_111->setFrameShadow(QFrame::Raised);
        label_112 = new QLabel(frame_12);
        label_112->setObjectName(QString::fromUtf8("label_112"));
        label_112->setGeometry(QRect(63, 136, 35, 23));
        label_112->setStyleSheet(QString::fromUtf8("#label_112\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_113 = new QLabel(frame_12);
        label_113->setObjectName(QString::fromUtf8("label_113"));
        label_113->setGeometry(QRect(102, 136, 23, 23));
        label_113->setStyleSheet(QString::fromUtf8("#label_113\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_114 = new QLabel(frame_12);
        label_114->setObjectName(QString::fromUtf8("label_114"));
        label_114->setGeometry(QRect(579, 260, 23, 23));
        label_114->setStyleSheet(QString::fromUtf8("#label_114\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_115 = new QLabel(frame_12);
        label_115->setObjectName(QString::fromUtf8("label_115"));
        label_115->setGeometry(QRect(528, 210, 111, 71));
        label_115->setFrameShape(QFrame::NoFrame);
        label_115->setFrameShadow(QFrame::Raised);
        label_116 = new QLabel(frame_12);
        label_116->setObjectName(QString::fromUtf8("label_116"));
        label_116->setGeometry(QRect(540, 260, 35, 23));
        label_116->setStyleSheet(QString::fromUtf8("#label_116\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_117 = new QLabel(frame_12);
        label_117->setObjectName(QString::fromUtf8("label_117"));
        label_117->setGeometry(QRect(200, 120, 241, 81));
        label_117->setStyleSheet(QString::fromUtf8("#label_117\n"
"{\n"
"	\n"
"	background-image: url(:/bg/Info_label.gif);\n"
"}"));
        label_33->raise();
        label_34->raise();
        label_35->raise();
        label_36->raise();
        label_37->raise();
        label_38->raise();
        label_40->raise();
        label_41->raise();
        label_44->raise();
        label_43->raise();
        label_46->raise();
        label_47->raise();
        label_49->raise();
        label_50->raise();
        label_58->raise();
        label_59->raise();
        label_39->raise();
        label_48->raise();
        label_30->raise();
        label_42->raise();
        label_60->raise();
        label_31->raise();
        label_45->raise();
        label_51->raise();
        label_110->raise();
        label_32->raise();
        label_112->raise();
        label_113->raise();
        label_111->raise();
        label_114->raise();
        label_116->raise();
        label_115->raise();
        label_117->raise();
        label_29 = new QLabel(frame_13);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(40, 34, 151, 102));
        QFont font13;
        font13.setFamily(QString::fromUtf8("Comic Sans MS"));
        label_29->setFont(font13);
        label_29->setStyleSheet(QString::fromUtf8("#label_29\n"
"{\n"
"	\n"
"	background-image: url(:/bg/note_6.gif);\n"
"}"));
        label_29->setAlignment(Qt::AlignCenter);
        label_156 = new QLabel(frame_13);
        label_156->setObjectName(QString::fromUtf8("label_156"));
        label_156->setGeometry(QRect(472, 350, 190, 41));
        label_156->setStyleSheet(QString::fromUtf8("#label_156\n"
"{\n"
"	background-image: url(:/bg/Next_label.gif);\n"
"}"));
        frame_24 = new QFrame(frame_17);
        frame_24->setObjectName(QString::fromUtf8("frame_24"));
        frame_24->setGeometry(QRect(0, 0, 701, 397));
        frame_24->setStyleSheet(QString::fromUtf8(""));
        frame_24->setFrameShape(QFrame::StyledPanel);
        frame_24->setFrameShadow(QFrame::Raised);
        frame_25 = new QFrame(frame_24);
        frame_25->setObjectName(QString::fromUtf8("frame_25"));
        frame_25->setGeometry(QRect(30, 44, 651, 301));
        frame_25->setStyleSheet(QString::fromUtf8("#frame_25\n"
"{\n"
"	background-image: url(:/bg/help_layout.gif);\n"
"\n"
"}"));
        frame_25->setFrameShape(QFrame::StyledPanel);
        frame_25->setFrameShadow(QFrame::Raised);
        label_64 = new QLabel(frame_25);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        label_64->setGeometry(QRect(377, 131, 35, 23));
        label_64->setStyleSheet(QString::fromUtf8("#label_64\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_52 = new QLabel(frame_25);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(13, 152, 221, 71));
        label_52->setFrameShape(QFrame::NoFrame);
        label_52->setFrameShadow(QFrame::Raised);
        label_57 = new QLabel(frame_25);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(253, 236, 221, 51));
        label_57->setFrameShape(QFrame::NoFrame);
        label_57->setFrameShadow(QFrame::Raised);
        label_63 = new QLabel(frame_25);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(248, 107, 231, 41));
        label_63->setFrameShape(QFrame::NoFrame);
        label_63->setFrameShadow(QFrame::Raised);
        label_54 = new QLabel(frame_25);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(136, 203, 23, 23));
        label_54->setStyleSheet(QString::fromUtf8("#label_54\n"
"{	\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_56 = new QLabel(frame_25);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(370, 272, 35, 23));
        label_56->setStyleSheet(QString::fromUtf8("#label_56\n"
"{	\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_53 = new QLabel(frame_25);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(96, 203, 35, 23));
        label_53->setStyleSheet(QString::fromUtf8("#label_53\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_62 = new QLabel(frame_25);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setGeometry(QRect(318, 131, 35, 23));
        label_62->setStyleSheet(QString::fromUtf8("#label_62\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_55 = new QLabel(frame_25);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(330, 272, 35, 23));
        label_55->setStyleSheet(QString::fromUtf8("#label_55\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_129 = new QLabel(frame_25);
        label_129->setObjectName(QString::fromUtf8("label_129"));
        label_129->setGeometry(QRect(245, 47, 381, 251));
        label_129->setFrameShape(QFrame::StyledPanel);
        label_129->setFrameShadow(QFrame::Plain);
        label_129->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_141 = new QLabel(frame_25);
        label_141->setObjectName(QString::fromUtf8("label_141"));
        label_141->setGeometry(QRect(348, 198, 35, 23));
        label_141->setStyleSheet(QString::fromUtf8("#label_141\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_140 = new QLabel(frame_25);
        label_140->setObjectName(QString::fromUtf8("label_140"));
        label_140->setGeometry(QRect(258, 175, 221, 41));
        label_140->setFrameShape(QFrame::NoFrame);
        label_140->setFrameShadow(QFrame::Raised);
        label_146 = new QLabel(frame_25);
        label_146->setObjectName(QString::fromUtf8("label_146"));
        label_146->setGeometry(QRect(502, 131, 23, 23));
        label_146->setStyleSheet(QString::fromUtf8("#label_146\n"
"{\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_143 = new QLabel(frame_25);
        label_143->setObjectName(QString::fromUtf8("label_143"));
        label_143->setGeometry(QRect(487, 108, 131, 41));
        label_143->setFrameShape(QFrame::NoFrame);
        label_143->setFrameShadow(QFrame::Raised);
        label_142 = new QLabel(frame_25);
        label_142->setObjectName(QString::fromUtf8("label_142"));
        label_142->setGeometry(QRect(548, 131, 35, 23));
        label_142->setStyleSheet(QString::fromUtf8("#label_142\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_147 = new QLabel(frame_25);
        label_147->setObjectName(QString::fromUtf8("label_147"));
        label_147->setGeometry(QRect(588, 131, 23, 23));
        label_147->setStyleSheet(QString::fromUtf8("#label_147\n"
"{\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_148 = new QLabel(frame_25);
        label_148->setObjectName(QString::fromUtf8("label_148"));
        label_148->setGeometry(QRect(488, 167, 131, 41));
        label_148->setFrameShape(QFrame::NoFrame);
        label_148->setFrameShadow(QFrame::Raised);
        label_149 = new QLabel(frame_25);
        label_149->setObjectName(QString::fromUtf8("label_149"));
        label_149->setGeometry(QRect(524, 190, 35, 23));
        label_149->setStyleSheet(QString::fromUtf8("#label_149\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_150 = new QLabel(frame_25);
        label_150->setObjectName(QString::fromUtf8("label_150"));
        label_150->setGeometry(QRect(564, 190, 23, 23));
        label_150->setStyleSheet(QString::fromUtf8("#label_150\n"
"{\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_151 = new QLabel(frame_25);
        label_151->setObjectName(QString::fromUtf8("label_151"));
        label_151->setGeometry(QRect(490, 228, 131, 41));
        label_151->setFrameShape(QFrame::NoFrame);
        label_151->setFrameShadow(QFrame::Raised);
        label_152 = new QLabel(frame_25);
        label_152->setObjectName(QString::fromUtf8("label_152"));
        label_152->setGeometry(QRect(526, 251, 35, 23));
        label_152->setStyleSheet(QString::fromUtf8("#label_152\n"
"{\n"
"	background-image: url(:/bg/Input-Large.gif);\n"
"}"));
        label_153 = new QLabel(frame_25);
        label_153->setObjectName(QString::fromUtf8("label_153"));
        label_153->setGeometry(QRect(566, 251, 23, 23));
        label_153->setStyleSheet(QString::fromUtf8("#label_153\n"
"{\n"
"	background-image: url(:/bg/Input-Small.gif);\n"
"}"));
        label_154 = new QLabel(frame_25);
        label_154->setObjectName(QString::fromUtf8("label_154"));
        label_154->setGeometry(QRect(14, 104, 221, 131));
        label_154->setFrameShape(QFrame::StyledPanel);
        label_154->setFrameShadow(QFrame::Plain);
        label_154->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_154->raise();
        label_129->raise();
        label_64->raise();
        label_54->raise();
        label_56->raise();
        label_53->raise();
        label_62->raise();
        label_55->raise();
        label_57->raise();
        label_52->raise();
        label_63->raise();
        label_141->raise();
        label_140->raise();
        label_146->raise();
        label_142->raise();
        label_147->raise();
        label_143->raise();
        label_149->raise();
        label_150->raise();
        label_148->raise();
        label_152->raise();
        label_153->raise();
        label_151->raise();
        label_144 = new QLabel(frame_24);
        label_144->setObjectName(QString::fromUtf8("label_144"));
        label_144->setGeometry(QRect(40, 34, 151, 102));
        label_144->setFont(font13);
        label_144->setStyleSheet(QString::fromUtf8("#label_144\n"
"{\n"
"	\n"
"	background-image: url(:/bg/note_6.gif);\n"
"}"));
        label_144->setAlignment(Qt::AlignCenter);
        label_155 = new QLabel(frame_24);
        label_155->setObjectName(QString::fromUtf8("label_155"));
        label_155->setGeometry(QRect(474, 350, 190, 41));
        label_155->setStyleSheet(QString::fromUtf8("#label_155\n"
"{\n"
"	background-image: url(:/bg/Next_label.gif);\n"
"}"));
        frame_26 = new QFrame(frame_17);
        frame_26->setObjectName(QString::fromUtf8("frame_26"));
        frame_26->setGeometry(QRect(0, 874, 701, 397));
        frame_26->setStyleSheet(QString::fromUtf8(""));
        frame_26->setFrameShape(QFrame::StyledPanel);
        frame_26->setFrameShadow(QFrame::Raised);
        frame_27 = new QFrame(frame_26);
        frame_27->setObjectName(QString::fromUtf8("frame_27"));
        frame_27->setGeometry(QRect(30, 44, 651, 301));
        frame_27->setStyleSheet(QString::fromUtf8("#frame_27\n"
"{\n"
"	background-image: url(:/bg/help_layout.gif);\n"
"\n"
"}"));
        frame_27->setFrameShape(QFrame::StyledPanel);
        frame_27->setFrameShadow(QFrame::Raised);
        label_118 = new QLabel(frame_27);
        label_118->setObjectName(QString::fromUtf8("label_118"));
        label_118->setGeometry(QRect(415, 212, 101, 41));
        label_118->setFrameShape(QFrame::NoFrame);
        label_118->setFrameShadow(QFrame::Raised);
        label_119 = new QLabel(frame_27);
        label_119->setObjectName(QString::fromUtf8("label_119"));
        label_119->setGeometry(QRect(177, 14, 111, 91));
        label_119->setFrameShape(QFrame::NoFrame);
        label_119->setFrameShadow(QFrame::Raised);
        label_120 = new QLabel(frame_27);
        label_120->setObjectName(QString::fromUtf8("label_120"));
        label_120->setGeometry(QRect(200, 120, 241, 81));
        label_120->setStyleSheet(QString::fromUtf8("#label_120\n"
"{\n"
"	\n"
"	background-image: url(:/bg/Info_label.gif);\n"
"}"));
        label_121 = new QLabel(frame_27);
        label_121->setObjectName(QString::fromUtf8("label_121"));
        label_121->setGeometry(QRect(370, 9, 111, 91));
        label_121->setFrameShape(QFrame::NoFrame);
        label_121->setFrameShadow(QFrame::Raised);
        label_122 = new QLabel(frame_27);
        label_122->setObjectName(QString::fromUtf8("label_122"));
        label_122->setGeometry(QRect(52, 90, 111, 71));
        label_122->setFrameShape(QFrame::NoFrame);
        label_122->setFrameShadow(QFrame::Raised);
        label_123 = new QLabel(frame_27);
        label_123->setObjectName(QString::fromUtf8("label_123"));
        label_123->setGeometry(QRect(49, 154, 121, 121));
        label_123->setFrameShape(QFrame::NoFrame);
        label_123->setFrameShadow(QFrame::Raised);
        label_124 = new QLabel(frame_27);
        label_124->setObjectName(QString::fromUtf8("label_124"));
        label_124->setGeometry(QRect(174, 204, 121, 71));
        label_124->setFrameShape(QFrame::NoFrame);
        label_124->setFrameShadow(QFrame::Raised);
        label_125 = new QLabel(frame_27);
        label_125->setObjectName(QString::fromUtf8("label_125"));
        label_125->setGeometry(QRect(299, 204, 111, 71));
        label_125->setFrameShape(QFrame::NoFrame);
        label_125->setFrameShadow(QFrame::Raised);
        label_126 = new QLabel(frame_27);
        label_126->setObjectName(QString::fromUtf8("label_126"));
        label_126->setGeometry(QRect(533, 197, 111, 71));
        label_126->setFrameShape(QFrame::NoFrame);
        label_126->setFrameShadow(QFrame::Raised);
        label_127 = new QLabel(frame_27);
        label_127->setObjectName(QString::fromUtf8("label_127"));
        label_127->setGeometry(QRect(470, 106, 171, 71));
        label_127->setFrameShape(QFrame::NoFrame);
        label_127->setFrameShadow(QFrame::Raised);
        label_128 = new QLabel(frame_27);
        label_128->setObjectName(QString::fromUtf8("label_128"));
        label_128->setGeometry(QRect(517, 19, 111, 71));
        label_128->setFrameShape(QFrame::NoFrame);
        label_128->setFrameShadow(QFrame::Raised);
        label_145 = new QLabel(frame_26);
        label_145->setObjectName(QString::fromUtf8("label_145"));
        label_145->setGeometry(QRect(40, 34, 151, 102));
        label_145->setFont(font13);
        label_145->setStyleSheet(QString::fromUtf8("#label_145\n"
"{\n"
"	\n"
"	background-image: url(:/bg/note_6.gif);\n"
"}"));
        label_145->setAlignment(Qt::AlignCenter);
        label_157 = new QLabel(frame_26);
        label_157->setObjectName(QString::fromUtf8("label_157"));
        label_157->setGeometry(QRect(474, 351, 190, 41));
        label_157->setStyleSheet(QString::fromUtf8("#label_157\n"
"{\n"
"	background-image: url(:/bg/Next_label.gif);\n"
"}"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(58, 6, 141, 50));
        label_3->setStyleSheet(QString::fromUtf8("#label_3\n"
"{\n"
"	background-image:url(:/bg/inapplogo.gif)\n"
"}"));
        label_130 = new QLabel(frame_2);
        label_130->setObjectName(QString::fromUtf8("label_130"));
        label_130->setGeometry(QRect(749, 6, 46, 48));
        label_130->setStyleSheet(QString::fromUtf8("#label_130\n"
"{\n"
"	background-image: url(:/bg/Help_sign.gif);\n"
"}"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(-10, -4, 821, 51));
        label_4->setStyleSheet(QString::fromUtf8("#label_4\n"
"{\n"
"	background-image: url(:/bg/testtitle.gif);\n"
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
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gill Sans Ultra Bold Condensed'; color:#ffa500;\">Press &quot;F1&quot; to access the help menu</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Aharoni'; font-size:16pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt; color:#550000;\">TODAY</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_69->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Verdana'; font-size:8pt; font-weight:600;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_65->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:8.25pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#aa0000;\">HIGH PRIORITY</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_71->setText(QString());
        label_66->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'AR CHRISTY'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; color:#3f3f3f;\">I need to do this now...</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_70->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Verdana'; font-size:8pt; font-weight:600;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_61->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:8.25pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#555500;\">OUTSTANDING</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#555500;\">EVENTS</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_72->setText(QString());
        label_68->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Verdana'; font-size:8pt; font-weight:600;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_67->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Verdana'; font-size:8pt; font-weight:600;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_73->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Levenim MT'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; color:#aa0000;\">RESULTS</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_74->setText(QString());
        label_107->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_108->setText(QString());
        label_109->setText(QString());
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
        label_77->setText(QString());
        label_78->setText(QString());
        label_79->setText(QString());
        label_80->setText(QString());
        label_81->setText(QString());
        label_82->setText(QString());
        label_83->setText(QString());
        label_84->setText(QString());
        label_85->setText(QString());
        label_86->setText(QString());
        label_87->setText(QString());
        label_88->setText(QString());
        label_89->setText(QString());
        label_90->setText(QString());
        label_91->setText(QString());
        label_92->setText(QString());
        label_93->setText(QString());
        label_94->setText(QString());
        label_95->setText(QString());
        label_96->setText(QString());
        label_97->setText(QString());
        label_98->setText(QString());
        label_99->setText(QString());
        label_100->setText(QString());
        label_101->setText(QString());
        label_102->setText(QString());
        label_103->setText(QString());
        label_104->setText(QString());
        label_105->setText(QString());
        label_106->setText(QString());
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
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; color:#aa0000;\">EVENT NAME</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_75->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Levenim MT'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; color:#aa0000;\">START DATE</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_76->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Levenim MT'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; color:#aa0000;\">END DATE</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">ADD  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- add [task]</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-le"
                        "ft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- [task]</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">-    CTRL      Q     [task]</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">DELETE  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- del [task]</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin"
                        "-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- del [event number]</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- del all</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">-    CTRL      D    [task]</span></p></body></html>", 0, QApplication::UnicodeUTF8));
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
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- find [task]</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-"
                        "left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">-    CTRL      F     [task]</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">-    CTRL      G</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">DISPLAY COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- dsp</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0"
                        "px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">-    CTRL      B</span></p></body></html>", 0, QApplication::UnicodeUTF8));
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
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- edit [task] [new details]</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-botto"
                        "m:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">-    CTRL      E     [task] [new details]</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">UNDO  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- undo</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0p"
                        "x; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">-    CTRL      U</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_46->setText(QString());
        label_47->setText(QString());
        label_48->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">REDO  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- redo</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0p"
                        "x; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">-    CTRL      R</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_49->setText(QString());
        label_50->setText(QString());
        label_58->setText(QString());
        label_59->setText(QString());
        label_60->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">CLEARING INPUT</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">-    CTRL      H</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_51->setText(QString());
        label_110->setText(QString());
        label_111->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">MARK  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- mark</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0p"
                        "x; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">-    CTRL      M</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_112->setText(QString());
        label_113->setText(QString());
        label_114->setText(QString());
        label_115->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">TODAY  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- today</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:"
                        "0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">-    CTRL      T</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_116->setText(QString());
        label_117->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; color:#005500;\">I need to enter the shown fields</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; color:#005500;\">to trigger these commands here</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#00007f;\">HELP</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_156->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">PRESS &quot;TAB&quot;</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_64->setText(QString());
        label_52->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">SWITCHING BETWEEN </span><span style=\" font-size:8pt; font-weight:600; color:#550000;\">STANDARDVIEW</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600; color:#550000;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-"
                        "size:8pt; font-weight:600;\">AND </span><span style=\" font-size:8pt; font-weight:600; color:#55007f;\">SEAMPLEVIEW</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  CTRL      S</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_57->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">SWITCHING TODAY EVENTS/</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">RESULTS TABLE</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-"
                        "bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  CTRL      TAB</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_63->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">SCROLLING RESULTS IN RESULTS TABLE</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  PgUp    or    PgDn</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_54->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_56->setText(QString());
        label_53->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_62->setText(QString());
        label_55->setText(QString());
        label_129->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#00007f;\">STANDARDVIEW INTERFACE</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#00007f;\"> SHORTCUTS</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_141->setText(QString());
        label_140->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">SWITCHING RESULTS INTERFACES</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">TAB</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_146->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_143->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">VIEW HELP INTERFACE</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  F1    or    CTRL      1</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_142->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_147->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_148->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">VIEW TODAY EVENTS</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">CTRL      2</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_149->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_150->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_151->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">VIEW RESULTS TABLE</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">CTRL      3</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_152->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_153->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_154->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#00007f;\">COMMON SHORTCUTS</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_144->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#00007f;\">HELP</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_155->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">PRESS &quot;TAB&quot;</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_118->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">CLEARING INPUT</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- Flush the input bar</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_119->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">ADD  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- add a task to the list </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; marg"
                        "in-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  of tasks within the</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  database</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_120->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; color:#005500;\">I see, so these are what the</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; color:#005500;\">commands do.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_121->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">FIND  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- find a task within</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-r"
                        "ight:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  the database</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_122->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">MARK  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- mark a task as done</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_123->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">DELETE  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- delete a task that was</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; ma"
                        "rgin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  added in before.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_124->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">REDO  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- redo the last command</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margi"
                        "n-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  that was undone</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_125->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">UNDO  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- undo the last</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:"
                        "0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  command entered</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_126->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">TODAY  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- display today's tasks</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_127->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">EDIT  COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- edit a task that is</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-"
                        "right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  in the database</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_128->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">DISPLAY COMMAND</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- display all the tasks</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; mar"
                        "gin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">  in the database</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_145->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#00007f;\">HELP</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_157->setText(QApplication::translate("StandardView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">PRESS &quot;TAB&quot;</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        label_130->setText(QString());
        label_4->setText(QString());
        pushButton_2->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StandardView: public Ui_StandardView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STANDARDVIEW_H
