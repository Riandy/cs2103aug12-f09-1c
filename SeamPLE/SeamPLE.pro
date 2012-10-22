#-------------------------------------------------
#
# Project created by QtCreator 2012-09-26T07:47:37
#
#-------------------------------------------------

QT       += core gui

TARGET = SeamPLE
TEMPLATE = app

SOURCES += main.cpp\
    Sframe.cpp \
    GuiControl.cpp \
    intellisense.cpp \
    Action.cpp \
    task.cpp \
    seample.cpp \
    scheduler.cpp \
    calender.cpp \
    GuiShortcuts.cpp \
    SeampleView.cpp \
    StandardView.cpp \
    SLineEdit.cpp \
    CommonView.cpp

HEADERS  += \
    Sframe.h \
    GuiControl.h \
    intellisense.h \
    Action.h \
    task.h \
    seample.h \
    scheduler.h \
    calender.h \
    GuiShortcuts.h \
    SeampleView.h \
    StandardView.h \
    SLineEdit.h \
    CommonView.h

FORMS    += \
    SeampleView.ui \
    StandardView.ui

RESOURCES += \
    Resource.qrc

OTHER_FILES +=


CONFIG  += qxt
QXT     += core gui
