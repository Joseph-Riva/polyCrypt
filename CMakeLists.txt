cmake_minimum_required(VERSION 3.10)

# set compiler
set(CMAKE_CXX_COMPILER /usr/bin/g++)

project(polyCrypt)
# output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


# include directories
include_directories(include/)

# C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Using -Wall is required:
add_compile_options(-Wall -Wextra -Wpedantic -std=c++17 -g -O3)
 
# Optional super-strict mode:
if(NOT APPLE)
		add_compile_options(-fmessage-length=80 -fno-diagnostics-show-option
			-fstack-protector-all -g -O3 -std=c++17 -Walloc-zero -Walloca
			-Wctor-dtor-privacy -Wduplicated-cond -Wduplicated-branches
			-Werror -Wextra-semi -Wfatal-errors -Winit-self -Wlogical-op
			-Wold-style-cast -Wshadow -Wunused-const-variable=1
			-Wzero-as-null-pointer-constant)
endif(NOT APPLE)

add_executable(main src/main.cc)
add_library(Polynomial src/Polynomial.cc src/BasePolynomial.cc src/IrreduciblePolynomial.cc)
add_library(EllipticCurve src/EllipticCurve.cc)
target_link_libraries(main PUBLIC Polynomial EllipticCurve)

add_executable(crc src/CRC/crc.cc)
target_link_libraries(main PUBLIC Polynomial)

# subdirectories
add_subdirectory(tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

