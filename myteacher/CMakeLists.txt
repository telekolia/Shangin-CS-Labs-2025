cmake_minimum_required(VERSION 3.23)

set(project "myteacher")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES
    myteacher.cpp)

set(${project}_HEADERS
    myteacher.hpp)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
