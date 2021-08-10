# polyCrypt
## About
Implementing Polynomials over Finite Fields for Cryptography and Beyond. This library aims to allow for relatively fast operations on 
polynomials in Characteristic two over Finite Extension Fields.

Further Documentation can be found in the `documentation` folder in this directory.
## Installation
Please download this repository and then you can execute:
`cmake . && make`
to generate the MakeFile for this project and compile it. While developing you may just run `make` to compile all sources.

**Warning**: This has only been tested on Linux and macOS using the g++ compiler.
## File Structure
```
├── CMakeCache.txt
├── CMakeFiles
├── CMakeLists.txt
├── LICENSE
├── Makefile
├── README.md
├── bin
│   ├── main
│   └── test
├── cmake_install.cmake
├── include
│   ├── BasePolynomial.h
│   ├── IrreduciblePolynomial.h
│   └── Polynomial.h
├── lib
│   ├── CMakeFiles
│   ├── CMakeLists.txt
│   ├── CMakeLists.txt.in
│   ├── libPolynomial.a
│   └── libgtest.a
├── src
│   ├── BasePolynomial.cc
│   ├── IrreduciblePolynomial.cc
│   ├── Polynomial.cc
│   └── main.cc
└── tests
    ├── BasePolynomial-test.cc
    ├── CMakeFiles
    ├── CMakeLists.txt
    ├── IrreduciblePolynomial-test.cc
    ├── Makefile
    ├── Polynomial-test.cc
    ├── cmake_install.cmake
    └── main.cc
```
## Running the Program
all executables that get generated are put in the `bin/` directory. You will find two important ones:
* `./bin/test` - runs the gTest suite for all test files in the `tests/` directory(source is in `tests/main.cc`)
* `./bin/main` - runs an example file(source is in `src/main.cc`)
