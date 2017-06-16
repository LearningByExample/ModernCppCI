# CMake build : tests

#configure directories
set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/main")
set(SRC_PATH  "${SOURCE_PATH}/src" )
set(INCLUDE_PATH  "${SOURCE_PATH}/include" )

#configure test directories
set(TEST_SOURCE_PATH "${PROJECT_SOURCE_DIR}/test")
set(TEST_SRC_PATH  "${TEST_SOURCE_PATH}/src" )
set(TEST_INCLUDE_PATH  "${TEST_SOURCE_PATH}/include" )

#set includes
include_directories (${INCLUDE_PATH} ${TEST_INCLUDE_PATH})

#set sources
file(GLOB HEADER_FILES "${INCLUDE_PATH}/*.hpp")
file(GLOB SOURCE_FILES "${SRC_PATH}/*.cpp")

#set test sources
file(GLOB TEST_HEADER_FILES "${TEST_INCLUDE_PATH}/*.hpp")
file(GLOB TEST_SOURCE_FILES "${TEST_SRC_PATH}/*.cpp")
set(MAIN_TEST_SOURCE "${TEST_SOURCE_PATH}/main.cpp")

#set target executable
add_executable(${PROJECT_NAME}Test ${MAIN_TEST_SOURCE} ${SOURCE_FILES} ${HEADER_FILES} ${TEST_SOURCE_FILES} ${TEST_HEADER_FILES})

# Turn on CMake testing capabilities
enable_testing()

#config cmake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${TEST_SOURCE_PATH}/cmake.modules/")

#parse catch tests
include(ParseAndAddCatchTests)
ParseAndAddCatchTests(${PROJECT_NAME}Test)
