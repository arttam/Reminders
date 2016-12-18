TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

libraryPath =
CONFIG(debug, debug|release):libraryPath = ../../Debug
CONFIG(release, debug|release):libraryPath = ../../Release

INCLUDEPATH += ../filerdp
INCLUDEPATH += ../RDB

QMAKE_RPATHDIR += $ORIGIN
LIBS += -lboost_system -lpthread -L$$libraryPath -lfilerdp -lRDB

SOURCES += main.cpp \
    server.cpp \
    session.cpp

HEADERS += \
    server.h \
    session.h
