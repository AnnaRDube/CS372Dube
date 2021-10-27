cmake_minimum_required(VERSION 2.4)

#set the project name
project(assignment08_2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(../../include)

#add the executable
add_executable(assignment08_2 assignment08_2.cpp)

