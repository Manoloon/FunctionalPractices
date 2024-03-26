cmake_minimum_required(VERSION 3.25.0)
project(3_LongestEdgeOfPoly VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
    add_compile_options(-Wall -Wextra -Wpedantic -Wshadow)
endif()

include_directories("../Externals")

add_executable(3_LongestEdgeOfPoly main.cpp)
