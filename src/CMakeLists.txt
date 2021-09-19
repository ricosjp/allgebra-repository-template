cmake_minimum_required(VERSION 3.17)

add_executable(test
    test.cpp
)
target_link_libraries(test OpenMP::OpenMP_CXX)