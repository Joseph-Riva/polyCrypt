#include <iostream>
#include "IrreduciblePolynomial.h"

using namespace std;

int main(){
    IrreduciblePolynomial r(4);
    cout << "created an irreducible polynomial with field size of " << 4 << ": " << r << '\n';
    cout << "polynomial is encoded as value: " << r.value() << '\n';
}

