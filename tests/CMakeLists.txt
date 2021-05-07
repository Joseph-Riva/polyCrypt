

add_executable(test main.cc BasePolynomial-test.cc IrreduciblePolynomial-test.cc Polynomial-test.cc)
target_link_libraries(test PUBLIC Polynomial EllipticCurve gtest)

add_executable(speedTest benchmark.cc)
target_link_libraries(speedTest PUBLIC Polynomial EllipticCurve benchmark::benchmark)