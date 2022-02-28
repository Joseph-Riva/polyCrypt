#include "Polynomial.h"
#include <bitset>
#include <cmath>

using namespace std;

Polynomial::Polynomial(long long value, long long field_size) : BasePolynomial(value), field(field_size){
    if(this->degree() >= field.degree()){
        this->val = (*this % field).value();
    }
}

Polynomial::Polynomial(long long value, long long polynomial, long long field_size) : BasePolynomial(value), field(polynomial, field_size){
    if(this->degree() >= field.degree()){
        this->val = (*this % field).value();
    }
}

Polynomial::Polynomial(long long value, IrreduciblePolynomial f) : Polynomial(value, f.value(), f.field_size){}
    

const IrreduciblePolynomial &Polynomial::get_field() const{
    return field;
}

Polynomial Polynomial::operator+(const Polynomial & other) {
    if(this->field.field_size != other.field.field_size){
        throw runtime_error("Cannot add polynomials with different field sizes.");
    }
    long long new_val = val ^ other.val;
    return Polynomial(new_val, field.field_size) % field;
}


Polynomial Polynomial::operator%(const IrreduciblePolynomial & other) {

    long long cur_val = value();
    const long long other_val = other.value();
    
    long long cur_degree = degree();
    const long long other_degree = other.degree();

    while(cur_degree >= other_degree){
        long long degree_diff = cur_degree - other_degree;
        
        cur_val = cur_val ^ (other_val<<degree_diff);

        cur_degree = calculateDegree(cur_val);
    }
    return Polynomial(cur_val, field.field_size);
}

Polynomial Polynomial::operator*(const Polynomial& other){
    long long product = 0;
    bitset<64> other_str = bitset<64>(other.value());
	long long other_degree = other.degree();
    for(int i = 0; i <= other_degree; i++){
        if(other_str[other_degree-i] == 1){
			long long shift = other_degree - i;
			long long shifted_val = value() << shift;
			product ^= shifted_val;
		}
    }
	return Polynomial(product, field.field_size) % this->field;
}

Polynomial Polynomial::pow(long long power){
    return pow_mod(*this, power, this->field, Polynomial(0b1, field.field_size));
}

Polynomial Polynomial::inverse(){
    long long order = field.field_size - 1;
    return pow(order-1);
}
Polynomial Polynomial::additiveInverse(){
    /* given polynomial y over a field, F, computes -y mod F*/
    return Polynomial(*this);
}

Polynomial Polynomial::sqrt(){
    long long sqrt_pow = std::pow(2, log2(field.field_size) - 1);
    return pow(sqrt_pow);
}

Polynomial Polynomial::pow_mod(Polynomial base, long long exp, IrreduciblePolynomial p, Polynomial b){
    if(exp==1LL){
        return base*b % p;
    }else if(exp%2==0LL){
        return pow_mod(base*base % p, exp/2, p, b);
    }
    return pow_mod(base*base % p, (exp-1)/2, p, base*b % p);
}
