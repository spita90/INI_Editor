set(CMAKE_AUTOMOC ON)
cmake_minimum_required(VERSION 3.10)
project(INI_Editor)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

find_package(Qt5Widgets REQUIRED)

add_executable(INI_Editor
        comment.h
        entry.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        parameter.h
        section.h
        ui_mainwindow.h
        invalidrowexception.h
        ioexception.h)

target_link_libraries(INI_Editor Qt5::Widgets)