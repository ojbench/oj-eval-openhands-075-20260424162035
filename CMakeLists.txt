
cmake_minimum_required(VERSION 3.10)
project(str_class)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a simple test executable that includes str.hpp
add_executable(code test_main.cpp)

# Set output name to "code" as required
set_target_properties(code PROPERTIES OUTPUT_NAME "code")
