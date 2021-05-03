#include "Polynomial.h"
#include <bitset>
using namespace std;

Polynomial::Polynomial(int value, int field_size) : BasePolynomial(value), field(field_size){
    //this->val = (*this % field).value();
}

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
    bitset<32> other_str = bitset<32>(other.value());
	int other_degree = other.degree();
    for(int i = 0; i <= other_degree; i++){
        if(other_str[other_degree-i] == 1){
			int shift = other_degree - i;
			int shifted_val = value() << shift;
			product ^= shifted_val;
		}
    }
	return Polynomial(product, field.field_size) % this->field;
}

Polynomial Polynomial::pow(int power){
    return pow_mod(*this, power, this->field, Polynomial(0b1, field.field_size));
}

Polynomial Polynomial::inverse(){
    int order = field.field_size - 1;
    return pow(order-1);
}
Polynomial Polynomial::pow_mod(Polynomial base, int exp, IrreduciblePolynomial p, Polynomial b){
    if(exp==1){
        return base*b % p;
    }else if(exp%2==0){
        return pow_mod(base*base % p, exp/2, p, b);
    }
    return pow_mod(base*base % p, (exp-1)/2, p, base*b % p);
}
