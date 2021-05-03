#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

#include "BasePolynomial.h"
#include "IrreduciblePolynomial.h"

class Polynomial: public BasePolynomial{
    public:
        explicit Polynomial(long long value, long long field_size);
        ~Polynomial() override = default;
        const IrreduciblePolynomial& get_field() const;
        Polynomial operator+(const Polynomial&);
        Polynomial operator%(const IrreduciblePolynomial&);
        Polynomial operator*(const Polynomial&);
        Polynomial inverse();
        Polynomial pow(int power);
    private:
        Polynomial pow_mod(Polynomial base, int exp, IrreduciblePolynomial p, Polynomial b);
        IrreduciblePolynomial field;
};
#endif //POLYNOMIAL_H_INCLUDED
