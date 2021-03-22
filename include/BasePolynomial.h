#ifndef POLYCRYPT_BASEPOLYNOMIAL_H
#define POLYCRYPT_BASEPOLYNOMIAL_H

#include <iostream>
#include <string>

class BasePolynomial{
    public:
        explicit BasePolynomial(int val);
        virtual ~BasePolynomial() = default;
        int degree() const;
        int value() const;
    protected:
        int val;
        int _degree;

        int calculateDegree(int val) const;
};
std::ostream& operator<<(std::ostream& os, const BasePolynomial& b);

#endif //POLYCRYPT_BASEPOLYNOMIAL_H
