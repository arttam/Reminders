TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

libraryPath =
CONFIG(debug, debug|release):libraryPath = ../../Debug/filerdp
CONFIG(release, debug|release):libraryPath = ../../Release/filerdp

INCLUDEPATH += ../filerdp
LIBS += -lboost_system -lpthread -L$$libraryPath -lfilerdp

SOURCES += main.cpp \
    server.cpp \
    session.cpp

HEADERS += \
    server.h \
    session.h
