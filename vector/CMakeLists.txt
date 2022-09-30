cmake_minimum_required(VERSION 3.22)
project(vector_example)

#Убрать при необходимости - выключает copy elision
add_compile_options(-fno-elide-constructors)

set(CMAKE_CXX_STANDARD 14)

add_executable(vector_example vector_test.cpp)

add_subdirectory(vector)

target_include_directories(vector_example PRIVATE vector)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)   
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(vector_example PRIVATE vector_t gtest_main)
