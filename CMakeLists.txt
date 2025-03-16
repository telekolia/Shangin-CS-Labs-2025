cmake_minimum_required(VERSION 3.23)

set(project "lab2")
project("${project}")

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        DataBaseController.cpp
        main.cpp)

add_subdirectory(planet)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

if(ENABLE_DEBUG)
    target_compile_options(${project} PRIVATE -g)
endif()

target_link_libraries(${project} planet)
