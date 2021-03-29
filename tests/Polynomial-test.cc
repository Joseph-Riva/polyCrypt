#include <iostream>
#include "Polynomial.h"
#include "gtest/gtest.h"

using namespace std;

TEST (PolynomialConstruct, positivedegree) {
    Polynomial p(0b100, 4);
    EXPECT_EQ (2, p.degree());
    EXPECT_EQ (4, p.value());
    EXPECT_EQ(0b111, p.get_field().value());
}
TEST (PolynomialConstruct, invalidField) {
    try{
        Polynomial p(0b100, 5);
        FAIL() << "Expected error constructing object with invalid field size";
    }catch(invalid_argument& err){
        EXPECT_EQ(err.what(),std::string("Cannot initialize an Irreducable polynomial with field size: 5"));
    }catch(...){
        FAIL() << "Expected invalid_argument exception, but got something else";
    }
}

TEST (PolynomialAdd, sameDegree){
    Polynomial p1(0b100, 4);
    Polynomial p2(0b010, 4);
    Polynomial p3 = p1 + p2;
    EXPECT_EQ(0b110, p3.value());
}

TEST (PolynomialAdd, differentField){
    Polynomial p1(0b100, 4);
    Polynomial p2(0b010, 8);
    try{
        p1 + p2;
        FAIL() << "Expected error added polynomials over different fields";
    }catch(runtime_error& err){
        EXPECT_EQ(err.what(),std::string("Cannot add polynomials with different field sizes."));
    }catch(...){
        FAIL() << "Expected runtime_error exception, but got something else";
    }
}

TEST(PolynomialMod, sameField){
    Polynomial p1(0b1111000, 16);
    IrreduciblePolynomial r(16);
    Polynomial result = p1 % r;
    EXPECT_EQ(0b101, result.value());
}

TEST(PolynomialMultiply, sameField){	
    Polynomial p1(0b1000, 16);
    Polynomial p2(0b1111, 16);
    Polynomial p3 = p1*p2;
    EXPECT_EQ(0b101, p3.value());
}

TEST(PolynomialPowMod, sameField){
    Polynomial p1(0b1000, 16);
    Polynomial p3 = p1.pow(2);
    EXPECT_EQ(0b1111,p3.value());
}