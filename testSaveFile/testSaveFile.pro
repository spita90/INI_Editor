QT += testlib core widgets
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \ 
    testsavefile.cpp \
    ../FileHandler.cpp

HEADERS += \
    testsavefile.h \
    ../FileHandler.h

DISTFILES += \
    TEST_FILE_output.ini
