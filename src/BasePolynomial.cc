//
// Created by jriva on 3/7/21.
//

#include <BasePolynomial.h>
#include <string>
#include <bitset>

using namespace std;

int BasePolynomial::degree() const {
    return _degree;
}

int BasePolynomial::value() const {
    return val;
}

BasePolynomial::BasePolynomial(int value): val(value), _degree(calculateDegree()){}


int BasePolynomial::calculateDegree() {
    auto bs = bitset<32>(val);
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

