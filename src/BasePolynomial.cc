//
// Created by jriva on 3/7/21.
//

#include <BasePolynomial.h>
#include <string>
#include <bitset>

using namespace std;

long long BasePolynomial::degree() const {
    return _degree;
}

long long BasePolynomial::value() const {
    return val;
}

BasePolynomial::BasePolynomial(long long value): val(value), _degree(calculateDegree(this->val)){}


long long BasePolynomial::calculateDegree(long long value) const{
    auto bs = bitset<32>(value);
    for(int i = bs.size(); i >= 0; i--){
        if(bs[i] == 1){
            return i;
        }
    }
    return 0;
}

ostream& operator<<(ostream& os, const BasePolynomial& b){
    auto bs = bitset<32>(b.value());
    string out;
    for(int i = bs.size(); i >= 0; i--){
        if(bs[i] == 1) {
            out +=  " x^" + to_string(i)  + " +";
        }
    }
    // remove trailing plus
    out.pop_back();
    return os << out;
}

