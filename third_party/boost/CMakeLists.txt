set (Boost_USE_STATIC_LIBS        ON) # only find static libs
set (Boost_USE_MULTITHREADED      ON)
set (Boost_USE_STATIC_RUNTIME    OFF)

find_package (Boost COMPONENTS log)

set (Boost_INCLUDE_DIRS  ${Boost_INCLUDE_DIRS} PARENT_SCOPE)
set (Boost_LIBRARIES  ${Boost_LIBRARIES} PARENT_SCOPE)
