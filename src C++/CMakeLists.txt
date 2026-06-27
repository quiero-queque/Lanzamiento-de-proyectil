cmake_minimum_required(VERSION 3.19)
project(LanzamientoParabolico LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Charts)

qt_standard_project_setup()

qt_add_executable(LanzamientoParabolico
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.h
    mainwindow.cpp
    funciones.hpp
    funciones.cpp
)

target_link_libraries(LanzamientoParabolico
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Charts
)
