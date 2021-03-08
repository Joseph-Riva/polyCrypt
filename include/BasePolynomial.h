#ifndef POLYCRYPT_BASEPOLYNOMIAL_H
#define POLYCRYPT_BASEPOLYNOMIAL_H

#include <iostream>

class BasePolynomial{
    public:
        BasePolynomial(int degree);
        virtual ~BasePolynomial() = 0;
        int degree() const;
    private:
        int degree;
};
std::ostream& operator<<(ostream& os, const BasePolynomial& b);

#endif //POLYCRYPT_BASEPOLYNOMIAL_H
