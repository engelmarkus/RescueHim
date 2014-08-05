cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_BUILD_TYPE_INIT "Debug")

project(RescueHim)

# g++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")

# clang++
#set(CMAKE_CXX_FLAGS "${CMAKE_CXXFLAGS} -std=c++11 -Wall -Wno-c++98-compat -Wno-system-headers -pedantic -fsanitize=address,undefined,alignment,bool,bounds,enum,null,return,unreachable,vptr")


add_subdirectory(src)
add_subdirectory(doc)
add_subdirectory(data)
