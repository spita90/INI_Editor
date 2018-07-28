QT += testlib core widgets
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \ 
    testLoadFile.cpp \
    ../FileHandler.cpp

HEADERS += \
    testloadfile.h \
    ../FileHandler.h

DISTFILES += \
    TEST_FILE_input.ini
