#include <iostream>
#include <cmath>
#include "IrreduciblePolynomial.h"
#include "EllipticCurve.h"
#include "Polynomial.h"

using namespace std;

void polyAdd(){
    Polynomial p1(0b1000, 4);
    Polynomial p2(0b0100, 4);
    cout << "created a polynomial with a field size of 4 p1: " << p1 << '\n';
    cout << "created a polynomial with a field size of 4 p2: " << p2 << '\n';
    cout << "p1 + p2 = " << p1+p2 << '\n';
}
void polyMult(){
    Polynomial p1(0b1000, 16);
    Polynomial p2(0b1111, 16);
    cout << "created a polynomial with a field size of 16 p1: " << p1 << '\n';
    cout << "created a polynomial with a field size of 16 p2: " << p2 << '\n';
    Polynomial p3 = p1*p2;
    cout << "p1 * p2 = " << p3 << '\n';
}

void polyMod(){
    Polynomial p1(0b1111000, 16);
    cout << "created a polynomial with a field size of 16 p1: " << p1 << '\n';
    IrreduciblePolynomial r(16);
    cout << "created an Irreducable Polynomial with a field size of 16: " << r << '\n';
    Polynomial result = p1 % r;
    cout << "p1 % r = " << result << '\n';
    
}
void polyPow(){
    Polynomial p1(0b1000, 16);
    cout << "created a polynomial with a field size of 16 p1: " << p1 << '\n';
    IrreduciblePolynomial r(16);
    cout << "created an Irreducable Polynomial with a field size of 16: " << r << '\n';
    Polynomial result = p1.pow(2);
    cout << "p1^2 = " << result << '\n';
}

void polyInverse(){
    Polynomial p1(0b1000, pow(2, 30));
    Polynomial result = p1.inverse();
    cout << "p1 inverse: " << result << '\n';
}

void ecPrint(){
    getECPointSet();
}

int main(){
    IrreduciblePolynomial r(4);
    cout << "created an irreducible polynomial with field size of " << 4 << ": " << r << '\n';
    cout << "polynomial is encoded as value: " << r.value() << '\n';
    cout << "polynomial has degree: " << r.degree() << "\n\n";

    polyAdd();
    cout << '\n';
    polyMult();
    cout << '\n';
    polyMod();
    cout << '\n';
    polyPow();
    cout << '\n';
    polyInverse();
    cout << '\n';
    ecPrint();
}

