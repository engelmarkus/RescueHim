cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_BUILD_TYPE_INIT "Debug")

project(RescueHim)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++14 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++14")

add_subdirectory(src)
add_subdirectory(doc)
add_subdirectory(data)
