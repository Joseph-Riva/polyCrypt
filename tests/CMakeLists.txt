

add_executable(test main.cc BasePolynomial-test.cc)
target_link_libraries(test PUBLIC Polynomial gtest)