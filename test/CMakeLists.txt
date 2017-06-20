# CMake build : tests

#configure variables
set (TEST_APP_NAME "${PROJECT_NAME}Test")

#configure directories
set (TEST_MODULE_PATH "${PROJECT_SOURCE_DIR}/test")

#configure test directories
set (TEST_SRC_PATH  "${TEST_MODULE_PATH}/src" )
set (TEST_INCLUDE_PATH  "${TEST_MODULE_PATH}/include")
set (CUSTOM_MODULES_PATH "${TEST_MODULE_PATH}/cmake.modules/")

#set includes
include_directories (${LIBRARY_INCLUDE_PATH} ${TEST_INCLUDE_PATH})

#set test sources
file (GLOB TEST_HEADER_FILES "${TEST_INCLUDE_PATH}/*.hpp")
file (GLOB TEST_SOURCE_FILES "${TEST_SRC_PATH}/*.cpp")

#set target executable
add_executable (${TEST_APP_NAME} ${TEST_HEADER_FILES} ${TEST_SOURCE_FILES})

#add the library
target_link_libraries (${TEST_APP_NAME} ${LIB_NAME})

# Turn on CMake testing capabilities
enable_testing()

#config cmake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CUSTOM_MODULES_PATH})

#parse catch tests
include (ParseAndAddCatchTests)
ParseAndAddCatchTests (${TEST_APP_NAME})
