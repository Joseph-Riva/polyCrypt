#include "EllipticCurve.h"
#include "Polynomial.h"
#include <iostream>
#include <set>
#include <memory>

using namespace std;


set<Polynomial, PolynomialComp>& getECPointSet(){
    unique_ptr<set<Polynomial, PolynomialComp>> points = make_unique<set<Polynomial, PolynomialComp>>();

    Polynomial a(0b10101, 256);
    Polynomial b(0b10111, 256);
    //EC - y^2 = x^2 + a*x + b
    cout << "Get elliptic curve elements in F_256" << '\n';
    cout << "working with elliptic curve: " << "y^2 = X^2 + " << a << "* X + " << b << "mod" << IrreduciblePolynomial(256) << "where X is an element of the Finite Field" << '\n';

    for(long long i = 0; i < 256; i++){
        Polynomial cur(i, 256);
        Polynomial y_2 = cur.pow(2) + a*cur + b;
        Polynomial y = y_2.sqrt();
        points->insert(y);
    }

    return *points; 
}


void getAllECPoints(long long field_size){

    Polynomial a(0b10101, field_size);
    Polynomial b(0b10111, field_size);
    //EC - y^2 = x^2 + a*x + b

    for(long long i = 0; i < field_size; i++){
        Polynomial cur(i, field_size);
        Polynomial y_2 = cur.pow(2) + a*cur + b;
        Polynomial y = y_2.sqrt();
    } 
}

