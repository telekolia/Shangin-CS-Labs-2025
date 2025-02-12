cmake_minimum_required(VERSION 3.23)

set(project "lab1")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES
        main.cpp)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/myteacher)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/mymath)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} mymath myteacher)
