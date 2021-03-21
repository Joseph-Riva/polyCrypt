#include <iostream>
#include "IrreduciblePolynomial.h"
#include "Polynomial.h"

using namespace std;

int main(){
    IrreduciblePolynomial r(4);
    cout << "created an irreducible polynomial with field size of " << 4 << ": " << r << '\n';
    cout << "polynomial is encoded as value: " << r.value() << '\n';
    cout << "polynomial has degree: " << r.degree() << "\n\n";

    Polynomial p1(0b1000, 4);
    Polynomial p2(0b0100, 4);
    cout << "created a polynomial with a field size of 4 p1: " << p1 << '\n';
    cout << "created a polynomial with a field size of 4 p2: " << p2 << '\n';
    cout << "p1 + p2 = " << p1+p2 << '\n';
}

