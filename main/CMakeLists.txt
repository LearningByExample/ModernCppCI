# CMake build : main application

#configure directories
set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/main")
set(SRC_PATH  "${SOURCE_PATH}/src" )
set(INCLUDE_PATH  "${SOURCE_PATH}/include" )

#set includes
include_directories (${INCLUDE_PATH})

#set sources
file(GLOB HEADER_FILES "${INCLUDE_PATH}/*.hpp")
file(GLOB SOURCE_FILES "${SRC_PATH}/*.cpp")
set(MAIN_SOURCE "${SOURCE_PATH}/main.cpp")

#set target executable
add_executable(${PROJECT_NAME}App ${MAIN_SOURCE} ${SOURCE_FILES} ${HEADER_FILES})