cmake_minimum_required(VERSION 3.17)

add_executable(openmp_test
    test.cpp
)
# Flags for OpenMP e.g. `-fopenmp` will automatically be added
# by the imported target `OpenMP::OpenMP_CXX`
target_link_libraries(openmp_test OpenMP::OpenMP_CXX)

add_test(openmp_test openmp_test)

add_library(mylib
  dot.cpp
)
