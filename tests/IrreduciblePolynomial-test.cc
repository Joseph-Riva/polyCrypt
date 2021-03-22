#include <iostream>
#include "IrreduciblePolynomial.h"
#include "gtest/gtest.h"

using namespace std;

TEST (IrreduciblePolynomialConstruct, validField) {
    IrreduciblePolynomial p(4);
    EXPECT_EQ (7, p.value());
}

TEST (IrreduciblePolynomialConstruct, invalidField) {
    try{
        IrreduciblePolynomial p(17);
        FAIL() << "Expected error constructing object with invalid field size";
    }catch(invalid_argument& err){
        EXPECT_EQ(err.what(),std::string("Cannot initialize an Irreducable polynomial with field size: 17"));
    }catch(...){
        FAIL() << "Expected invalid_argument exception, but got something else";
    }
}
