cmake_minimum_required(VERSION 3.5)
project(Reminder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp addentry.cpp checkpassword.cpp editentry.cpp remainderdlg.cpp Debug/moc_addentry.cpp Debug/moc_checkpassword.cpp Debug/moc_editentry.cpp Debug/moc_remainderdlg.cpp Debug/ui_addentry.h Debug/ui_checkpassword.h Debug/ui_editentry.h Debug/ui_remainderdlg.h)

# Qt5 stuff
set(Qt5_DIR /usr/lib/cmaker/Qt5)
set(Qt5_COMPONENTS Core Widgets Gui)
find_package(Qt5 REQUIRED COMPONENTS ${Qt5_COMPONENTS})

add_executable(Reminder ${SOURCE_FILES})

qt5_use_modules(Reminder Core Widgets Gui)
