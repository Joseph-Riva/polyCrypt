#ifndef POLYCRYPT_BASEPOLYNOMIAL_H
#define POLYCRYPT_BASEPOLYNOMIAL_H

#include <iostream>
#include <string>

class BasePolynomial{
    public:
        explicit BasePolynomial(long long val);
        virtual ~BasePolynomial() = default;
        long long degree() const;
        long long value() const;
    protected:
        long long val;
        long long _degree;

        long long calculateDegree(long long val) const;
};
std::ostream& operator<<(std::ostream& os, const BasePolynomial& b);

#endif //POLYCRYPT_BASEPOLYNOMIAL_H
