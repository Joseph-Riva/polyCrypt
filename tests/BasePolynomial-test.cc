#include <iostream>
#include "Polynomial.h"
#include "BasePolynomial.h"
#include "gtest/gtest.h"

using namespace std;

TEST (BasePolynomialDegree, zeroDegree) {
    BasePolynomial b(0b0);
    EXPECT_EQ (0, b.degree());
}

TEST (BasePolynomialDegree, positiveDegree) {
    BasePolynomial b1(0b111);
    EXPECT_EQ (2, b1.degree());
    BasePolynomial b2(0b10000);
    EXPECT_EQ (4, b2.degree());
    BasePolynomial b3(0b1);
    EXPECT_EQ (0, b3.degree());
    BasePolynomial b4(0b11);
    EXPECT_EQ (1, b4.degree());
}

TEST (BasePolynomialValue, values){
    BasePolynomial b1(0b111);
    EXPECT_EQ (7, b1.value());
}

TEST (BasePolynomialPrint, values){
    BasePolynomial b1(0b111001);
    cout << b1;
}
