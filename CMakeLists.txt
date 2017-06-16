#main file

cmake_minimum_required(VERSION 3.3)

project(ModernCppCI)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message(STATUS "Enabling C++14")
set(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")

add_subdirectory(main)
add_subdirectory(test)

enable_testing()