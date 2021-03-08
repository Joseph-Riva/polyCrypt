//
// Created by jriva on 3/7/21.
//


#include <IrreduciblePolynomial.h>
#include <string>

using namespace std;

IrreduciblePolynomial::IrreduciblePolynomial(int f_num) : BasePolynomial(get_val(f_num)), field_size(f_num) {}

int IrreduciblePolynomial::get_val(int f_size) const {
    try{
        return polynomials.at(f_size);
    }catch(out_of_range& err){
        throw invalid_argument("Cannot initialize an Irreducable polynomial with field size: "s + to_string(f_size));
    }
}

