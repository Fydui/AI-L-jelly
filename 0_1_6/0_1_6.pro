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
        mainwindow.cpp \
    setform.cpp \
    aboutform.cpp

HEADERS  += mainwindow.h \
    setform.h \
    aboutform.h \
    sqlite3.h \
    sqlite3ext.h

FORMS    += mainwindow.ui \
    setform.ui \
    aboutform.ui

DISTFILES += \
    sqlite3.dll

RESOURCES += \
    resource.qrc \
    resource.qrc

RC_FILE = lico.rc
