cmake_minimum_required(VERSION 3.22)
project(prisoners)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(strategies)

add_executable(prisoners main.cpp StrategyFactory.cpp StrategyFactory.h)

target_include_directories(prisoners PUBLIC strategies)

target_link_libraries(prisoners PUBLIC strategies)

