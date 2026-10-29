cmake_minimum_required(VERSION 4.1)
project(Task-2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task-2 main.cpp
        TMovie.h
        TMovie.cpp
        list/TMovieNode.cpp
        list/TMovieNode.h
        list/TMovieList.cpp
        list/TMovieList.h
        view/TMovieMenu.cpp
        view/TMovieMenu.h
        controller/TMovieController.cpp
        controller/TMovieController.h
        controller/SearchController.cpp
        controller/SearchController.h)
