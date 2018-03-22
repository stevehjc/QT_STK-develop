#-------------------------------------------------
#
# Project created by QtCreator 2018-03-22T20:32:07
#
#-------------------------------------------------

QT       += core gui axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_STK
TEMPLATE = app

INCLUDEPATH += CppIncludes

SOURCES += main.cpp\
        QT_STK.cpp \
    stk.cpp \
    QSTKEarth.cpp

HEADERS  += QT_STK.h \
    stk.h \
    QSTKEarth.h

FORMS    += QT_STK.ui
