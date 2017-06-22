# CMake build : main application test

#configure variables
set (APP_NAME "${PROJECT_NAME}App")
set (TEST_NAME "${APP_NAME}Test")

enable_testing ()
add_test (NAME ${TEST_NAME} COMMAND ${APP_NAME} )
set_tests_properties (${TEST_NAME} PROPERTIES PASS_REGULAR_EXPRESSION "1 \\+ 2 \\* 5 \\- 1 \\/ 4 = 3")
