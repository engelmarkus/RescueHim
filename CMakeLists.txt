cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_BUILD_TYPE_INIT "Debug")

#set(CMAKE_CXX_COMPILER "/opt/gcc-5/bin/g++")
set(CMAKE_CXX_COMPILER "/opt/llvm/bin/clang++")

project(RescueHim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(src)
add_subdirectory(doc)
add_subdirectory(data)
