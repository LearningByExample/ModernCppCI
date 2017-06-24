# CMake build : spdlog

#configure directories
set (SPDLOG_MODULE_PATH "${THIRD_PARTY_MODULE_PATH}/spdlog")
set (SPDLOG_INCLUDE_PATH "${SPDLOG_MODULE_PATH}/include")

#export vars
set (SPDLOG_INCLUDE_PATH  ${SPDLOG_INCLUDE_PATH} PARENT_SCOPE)
