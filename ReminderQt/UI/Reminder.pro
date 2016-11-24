#-------------------------------------------------
#
# Project created by QtCreator 2016-05-17T21:59:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Reminder
TEMPLATE = app


SOURCES += main.cpp\
        remainderdlg.cpp \
    checkpassword.cpp \
    addentry.cpp \
    ../DataProvider/DataProvider.cpp \
    ../DataProvider/FileProviderImpl.cpp \
    ../DataProvider/DbProviderImpl.cpp

HEADERS  += remainderdlg.h \
    demodata.h \
    checkpassword.h \
    addentry.h \
    ../DataProvider/DataEntry.h \
    ../DataProvider/DataProvider.h \
    ../DataProvider/FileProviderImpl.h \
    ../DataProvider/QtDataProvider.h \
    ../DataProvider/DbProviderImpl.h

FORMS    += remainderdlg.ui \
    checkpassword.ui \
    addentry.ui

DISTFILES += \
    CMakeLists.txt \
    ../DataProvider/data_sample
