cmake_minimum_required(VERSION 4.1)
project(Task-5)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task-5 main.cpp
        TBankAccount.cpp
        TBankAccount.h
        list/TLinkedList.cpp
        list/TLinkedList.h
        list/TNode.cpp
        list/TNode.h
        list/ListInit.cpp
        list/ListInit.h
)
