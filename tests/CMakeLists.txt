

add_executable(test main.cc test.cc)
target_link_libraries(test PUBLIC Polynomial gtest)