

add_executable(testPoly main.cc BasePolynomial-test.cc IrreduciblePolynomial-test.cc Polynomial-test.cc)
target_link_libraries(testPoly PUBLIC Polynomial EllipticCurve gtest)

add_executable(speedTest benchmark.cc)
target_link_libraries(speedTest PUBLIC Polynomial EllipticCurve benchmark::benchmark)