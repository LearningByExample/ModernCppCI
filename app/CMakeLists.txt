# Distributed under the MIT License (See accompanying file /LICENSE )

# CMake build : main application

#configure variables
set (APP_NAME "${PROJECT_NAME}App")

#configure directories
set (APP_MODULE_PATH "${PROJECT_SOURCE_DIR}/app")
set (APP_SRC_PATH  "${APP_MODULE_PATH}/src" )

#set includes
include_directories (${LIBRARY_INCLUDE_PATH} ${THIRD_PARTY_INCLUDE_PATH})

#set sources
file (GLOB APP_SOURCE_FILES "${APP_SRC_PATH}/*.cpp")

#set target executable
add_executable (${APP_NAME} ${APP_SOURCE_FILES})

#add the library
target_link_libraries (${APP_NAME} ${LIB_NAME} Threads::Threads)

#test
enable_testing ()
add_subdirectory (test)
