cmake_minimum_required(VERSION 4.1)
project(Task-1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task-1 main.cpp
        TStudent.cpp
        TStudent.h
        TemplateProvider.h
        TDataPack.h
        TStaticArray.h
        GlobalFunctionProvider.cpp
        GlobalFunctionProvider.h
        TDataAggregator.h)
