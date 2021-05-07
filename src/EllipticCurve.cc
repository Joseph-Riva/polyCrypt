#include "EllipticCurve.h"
#include "Polynomial.h"
#include <iostream>
#include <set>
#include <memory>

using namespace std;


set<Polynomial, PolynomialComp>& getECPointSet(){
    unique_ptr<set<Polynomial, PolynomialComp>> points(new set<Polynomial, PolynomialComp>());

    Polynomial a(0b10101, 256);
    Polynomial b(0b10111, 256);
    //EC - y^2 = x^2 + a*x + b
    for(long long i = 0; i < 256; i++){
        Polynomial cur(i, 256);
        Polynomial y_2 = cur.pow(2) + a*cur + b;
        Polynomial y = y_2.sqrt();
        points->insert(y);
    }

    return *points; 
}

