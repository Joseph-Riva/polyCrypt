#include "Polynomial.h"
#include <bitset>
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


Polynomial Polynomial::operator%(const IrreduciblePolynomial & other) {

    int cur_val = value();
    const int other_val = other.value();
    
    int cur_degree = degree();
    const int other_degree = other.degree();

    while(cur_degree >= other_degree){
        int degree_diff = cur_degree - other_degree;
        
        cur_val = cur_val ^ (other_val<<degree_diff);

        cur_degree = calculateDegree(cur_val);
    }
    return Polynomial(cur_val, field.field_size);
}

Polynomial Polynomial::operator*(const Polynomial& other){
    int product = 0;
	cout << product << '\n';
    auto other_str = bitset<32>(other.value());	
    for(size_t i = 0; i < other_str.size(); i++){
        cout << other_str[i] << ' ';
    }
	return Polynomial(0, field.field_size);
}
