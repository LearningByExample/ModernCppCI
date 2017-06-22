# CMake build : global project

cmake_minimum_required (VERSION 3.3)

project (ModernCppCI)

set_property (GLOBAL PROPERTY USE_FOLDERS ON)

message (STATUS "Enabling C++14")
set (CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")

add_subdirectory (third_party)
add_subdirectory (lib)
add_subdirectory (app)

enable_testing ()
