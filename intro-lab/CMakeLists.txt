cmake_minimum_required(VERSION 3.22)
project(intro_lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(intro_lab main.cpp)

add_subdirectory(module1)
add_subdirectory(module2)

target_include_directories(intro_lab PRIVATE module1 module2)

target_link_libraries(intro_lab PRIVATE module1_t module2_t)