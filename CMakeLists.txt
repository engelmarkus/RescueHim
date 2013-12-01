cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_BUILD_TYPE_INIT "Debug")

project(RescueHim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXXFLAGS} -std=c++11 -Weffc++ -Wall -Wextra -pedantic")


add_subdirectory(src)
add_subdirectory(doc)
