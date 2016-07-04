#-------------------------------------------------
#
# Project created by QtCreator 2016-06-26T18:54:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 0_1_6
TEMPLATE = app


SOURCES += main.cpp\
    aboutform.cpp \
    setform.cpp \
    mainwindow.cpp

HEADERS  += mainwindow.h \
    aboutform.h \
    setform.h

FORMS    += mainwindow.ui \
    aboutform.ui \
    setform.ui

DISTFILES += \
    sqlite3.dll

RESOURCES += \
    resource.qrc \
    resource.qrc
QT += sql

RC_FILE = lico.rc
