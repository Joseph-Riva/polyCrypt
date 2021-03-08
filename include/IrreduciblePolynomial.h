//
// Created by jriva on 3/7/21.
//

#ifndef POLYCRYPT_IRREDUCIBLEPOLYNOMIAL_H
#define POLYCRYPT_IRREDUCIBLEPOLYNOMIAL_H

#include "BasePolynomial.h"
#include <unordered_map>

class IrreduciblePolynomial: public BasePolynomial{
    public:
        explicit IrreduciblePolynomial(int f_num);
        ~IrreduciblePolynomial() override = default;
    private:
        int field_size;
        inline static const std::unordered_map<int, int> polynomials = {
                {4,    0b111},        //x^2 + x + 1
                {8,    0b1101},       //x^3 + x^2 + 1
                {16,   0b11001},      //x^4 + x^3 + 1
                {32,   0b100101},     //x^5 + x^2 + 1
                {64,   0b1100001},    //x^6 + x^5 + 1
                {128,  0b11000001},   //x^7 + x^6 + 1
                {256,  0b100011101},  //x^8 + x^4 + x^3 + x^2 + 1
                {512,  0b1000010001}, //x^9 + x^4 + 1
                {1024, 0b10000001001} //x^10 + x^3 + 1
        };
        int get_val(int f_size) const;
};
#endif //POLYCRYPT_IRREDUCIBLEPOLYNOMIAL_H
