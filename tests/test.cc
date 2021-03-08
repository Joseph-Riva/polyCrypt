#include <iostream>
#include "Polynomial.h"
#include "gtest/gtest.h"

using namespace std;

TEST (PolynomialTest, addExample) {
    EXPECT_EQ (1, add());
}
