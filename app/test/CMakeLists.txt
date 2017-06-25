# Distributed under the MIT License (See accompanying file /LICENSE )

# CMake build : main application test

#configure variables
set (APP_NAME "${PROJECT_NAME}App")
set (TEST_NAME "${APP_NAME}Test")

enable_testing ()
add_test (NAME ${TEST_NAME} COMMAND ${APP_NAME} )
