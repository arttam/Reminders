TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../filerdp

libraryPath =
CONFIG(debug, debug|release):libraryPath = ../../Debug/filerdp
CONFIG(release, debug|release):libraryPath = ../../Release/filerdp

#LIBS += -L../Reminders/Debug/filerdp -lfilerdp
LIBS += -L$$libraryPath -lfilerdp

SOURCES += \
    main.cpp
