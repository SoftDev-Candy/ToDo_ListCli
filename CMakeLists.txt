cmake_minimum_required(VERSION 3.16)
project(CLIToDoList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

add_executable(CLIToDoList src/main.cpp
               include/taskdata.h
        src/taskdata.cpp
        src/command.cpp
        include/command.h
        src/repository.cpp
        include/repository.h)

target_include_directories(CLIToDoList PRIVATE ${CMAKE_SOURCE_DIR}/include)