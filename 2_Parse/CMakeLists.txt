cmake_minimum_required(VERSION 3.25.0)
project(2_Parse VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# fetch the dependencies needed
include_directories("../Externals")

add_executable(2_Parse main.cpp)
