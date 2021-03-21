#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial(int value, int field_size) : BasePolynomial(value), field(field_size){}

const IrreduciblePolynomial &Polynomial::get_field() const{
    return field;
}

Polynomial Polynomial::operator+(const Polynomial & other) {
    if(this->field.field_size != other.field.field_size){
        throw runtime_error("Cannot add polynomials with different field sizes.");
    }
    int new_val = val ^ other.val;
    return Polynomial(new_val, field.field_size);
}

/*
Polynomial Polynomial::operator%(const IrreduciblePolynomial & other) {

    int cur_val = value();
    Polynomial cur = *this;
    while(degree() >= other.degree()){
        cout << "current remainder: " << cur_val << '\n';
        int degree_diff = other.degree() - degree();
        //int other_val = other.value() << degree_diff;
        //cur +=
    }
    return Polynomial(0, field.field_size);
}
*/

