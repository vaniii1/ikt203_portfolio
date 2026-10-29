cmake_minimum_required(VERSION 4.1)
project(Task-4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task-4 main.cpp
        data_structures/TStack.cpp
        data_structures/TStack.h
        data_structures/TQueue.cpp
        data_structures/TQueue.h
        GridService.h)
