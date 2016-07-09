#-------------------------------------------------
#
# Project created by QtCreator 2016-06-26T18:54:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 0_1_6
TEMPLATE = app

CONFIG   -= app_bundle
QT       += core

QT       -= gui


SOURCES += main.cpp\
    aboutform.cpp \
    setform.cpp \
    mainwindow.cpp

HEADERS  += mainwindow.h \
    aboutform.h \
    setform.h \
    sqlite3.h

FORMS    += mainwindow.ui \
    setform.ui \
    aboutform.ui

DISTFILES +=

RESOURCES += \
    resources.qrc

QT += sql

RC_FILE = lico.rc
