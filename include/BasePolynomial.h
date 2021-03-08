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
    private:
        int val;
        int _degree;

        int calculateDegree();
};
std::ostream& operator<<(std::ostream& os, const BasePolynomial& b);

#endif //POLYCRYPT_BASEPOLYNOMIAL_H
