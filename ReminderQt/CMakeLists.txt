cmake_minimum_required(VERSION 3.5)
project(Reminder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DataProvider/QtDataProvider.h DataProvider/DataEntry.h DataProvider/DataEntry.cpp DataProvider/DataProvider.cpp DataProvider/DataProvider.h DataProvider/FileProviderImpl.cpp DataProvider/FileProviderImpl.h DataProvider/ISTLProvider.h DataProvider/DbProviderImpl.cpp DataProvider/DbProviderImpl.h DataProvider/ISTLProvider.cpp)
# Additional source folders
set(UI_FILES UI/addentry.cpp UI/checkpassword.cpp UI/remainderdlg.cpp)
set(QT_UI_FILES Qt/moc_addentry.cpp Qt/moc_checkpassword.cpp Qt/moc_remainderdlg.cpp Qt/ui_addentry.h Qt/ui_checkpassword.h Qt/ui_editentry.h Qt/ui_remainderdlg.h)

# Qt5 stuff
set(Qt5_DIR /usr/lib/cmaker/Qt5)
set(Qt5_COMPONENTS Core Widgets Gui)
find_package(Qt5 REQUIRED COMPONENTS ${Qt5_COMPONENTS})

add_executable(Reminder ${SOURCE_FILES} ${UI_FILES} ${QT_UI_FILES})

# Qt5 linker modules
qt5_use_modules(Reminder ${Qt5_COMPONENTS})


