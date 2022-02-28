//
// Created by jriva on 3/7/21.
//


#include <IrreduciblePolynomial.h>
#include <string>

using namespace std;

IrreduciblePolynomial::IrreduciblePolynomial(long long f_num) : BasePolynomial(get_val(f_num)), field_size(f_num) {}

IrreduciblePolynomial::IrreduciblePolynomial(long long polynomial, long long field_num) : BasePolynomial(polynomial), field_size(field_num) {}

long long IrreduciblePolynomial::get_val(long long f_size) const {
    try{
        return polynomials.at(f_size);
    }catch(out_of_range& err){
        throw invalid_argument("Cannot initialize an Irreducable polynomial with field size: "s + to_string(f_size));
    }
}

