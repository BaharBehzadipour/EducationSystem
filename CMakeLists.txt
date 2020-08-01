cmake_minimum_required(VERSION 3.15)
project(TA_19)

set(CMAKE_CXX_STANDARD 14)

add_executable(TA_19 main.cpp Model/Student.cpp Model/Student.h Model/Professor.cpp Model/Professor.h Model/Course.cpp Model/Course.h Model/Person.cpp Model/Person.h Controller/Controller.cpp Controller/Controller.h View/View.cpp View/View.h View/Menus/Menu.cpp View/Menus/Menu.h View/Menus/InternalMenu.cpp View/Menus/InternalMenu.h View/Menus/LeafMenu.cpp View/Menus/LeafMenu.h View/Menus/CommandsFromFileMenu.cpp View/Menus/CommandsFromFileMenu.h Model/DoubleMajorStudent.cpp Model/DoubleMajorStudent.h)