# Distributed under the MIT License (See accompanying file /LICENSE )

# CMake build : third party

#configure directories
set (THIRD_PARTY_MODULE_PATH "${PROJECT_SOURCE_DIR}/third_party")

# -------------------------------------------------------------------------
# catch

#configure directories
set (CATCH_MODULE_PATH "${THIRD_PARTY_MODULE_PATH}/Catch")
set (CATCH_INCLUDE_PATH "${CATCH_MODULE_PATH}/include")
set (CATCH_CUSTOM_MODULES_PATH "${CATCH_MODULE_PATH}/contrib")

# -------------------------------------------------------------------------

add_subdirectory (spdlog)

#set variables
set (THIRD_PARTY_INCLUDE_PATH  ${SPDLOG_INCLUDE_PATH})

#set variables for tests
set (TEST_THIRD_PARTY_INCLUDE_PATH  ${CATCH_INCLUDE_PATH})
set (TEST_THIRD_PARTY_CUSTOM_MODULES_PATH  ${CATCH_CUSTOM_MODULES_PATH})

#export vars
set (THIRD_PARTY_INCLUDE_PATH  ${THIRD_PARTY_INCLUDE_PATH} PARENT_SCOPE)
set (TEST_THIRD_PARTY_INCLUDE_PATH  ${TEST_THIRD_PARTY_INCLUDE_PATH} PARENT_SCOPE)
set (TEST_THIRD_PARTY_CUSTOM_MODULES_PATH  ${TEST_THIRD_PARTY_CUSTOM_MODULES_PATH} PARENT_SCOPE)