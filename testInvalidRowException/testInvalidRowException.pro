QT += testlib core widgets
QT += gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    ../FileHandler.cpp \
    testinvalidrowexception.cpp

HEADERS += \
    ../FileHandler.h \
    testinvalidrowexception.h

DISTFILES += \
    TEST_FILE_exception.ini
