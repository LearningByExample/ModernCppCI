#test

include_directories (${PROJECT_SOURCE_DIR}/main/include ${PROJECT_SOURCE_DIR}/test/include)

file(GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/main/src/*.cpp")
file(GLOB HEADER_FILES "${PROJECT_SOURCE_DIR}/main/include/*.hpp")
file(GLOB TEST_SOURCE_FILES "${PROJECT_SOURCE_DIR}/test/src/*.cpp")
file(GLOB TEST_HEADER_FILES "${PROJECT_SOURCE_DIR}/test/include/*.hpp")
set(MAIN_TEST_SOURCE "${PROJECT_SOURCE_DIR}/test/main.cpp")

add_executable(${PROJECT_NAME}Test ${MAIN_TEST_SOURCE} ${SOURCE_FILES} ${HEADER_FILES} ${TEST_SOURCE_FILES} ${TEST_HEADER_FILES})

# Turn on CMake testing capabilities
enable_testing()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/test/cmake.modules/")

include(ParseAndAddCatchTests)
ParseAndAddCatchTests(${PROJECT_NAME}Test)
