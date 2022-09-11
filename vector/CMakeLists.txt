cmake_minimum_required(VERSION 3.22)
project(vector_example)

set(CMAKE_CXX_STANDARD 14)

add_executable(vector_example main.cpp)

add_subdirectory(vector)

target_include_directories(vector_example PRIVATE vector)
target_link_libraries(vector_example PRIVATE vector_t)
