# CMake file from Colorado State University cs253 taught by Jack Applin

cmake_minimum_required(VERSION 3.14)
project(polyCrypt)

# C++17 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include directories
include_directories(include/)

# Using -Wall is required:
add_compile_options(-Wall -Wextra -Wpedantic)
 
# Optional super-strict mode:
add_compile_options(-fmessage-length=80 -fno-diagnostics-show-option
    -fstack-protector-all -g -O3 -std=c++17 -Walloc-zero -Walloca
    -Wctor-dtor-privacy -Wduplicated-cond -Wduplicated-branches
    -Werror -Wextra-semi -Wfatal-errors -Winit-self -Wlogical-op
    -Wold-style-cast -Wshadow -Wunused-const-variable=1
    -Wzero-as-null-pointer-constant)
 
add_library(Polynomial src/Polynomial.cc)
add_executable(test tests/test.cc)
target_link_libraries(test Polynomial)
 

