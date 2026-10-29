cmake_minimum_required(VERSION 4.1)
project(Task-6)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task-6 main.cpp
        list/ListInit.cpp
        list/TLinkedList.cpp
        list/TNode.cpp
        TBankAccount.cpp
        list/TSort.cpp
        list/TSort.h)
