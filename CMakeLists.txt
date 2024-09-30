cmake_minimum_required(VERSION 3.5)
project(Test)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Cpp)

add_executable(Testfile test.cpp)
target_link_libraries(Testfile FilterCpp)
target_compile_options(Testfile PUBLIC -Wa,-mbig-obj -O2)