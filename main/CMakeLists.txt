#app

include_directories ("${PROJECT_SOURCE_DIR}/main/include")

file(GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/main/src/*.cpp")

set(MAIN_SOURCE "${PROJECT_SOURCE_DIR}/main/main.cpp")

add_executable(${PROJECT_NAME}App ${MAIN_SOURCE} ${SOURCE_FILES})