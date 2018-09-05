QT += gui
QT += testlib core widgets

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    ../FileHandler.cpp \
    testedittable.cpp

HEADERS += \
    ../FileHandler.h \
    testedittable.h

DISTFILES += \
    TEST_FILE_edit.ini
