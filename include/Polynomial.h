#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

#include "BasePolynomial.h"
#include "IrreduciblePolynomial.h"

class Polynomial: public BasePolynomial{
    public:
        explicit Polynomial(int value, int field_size);
        ~Polynomial() override = default;
        const IrreduciblePolynomial& get_field() const;
        Polynomial operator+(const Polynomial&);
        //Polynomial operator%(const IrreduciblePolynomial&);
    private:
        IrreduciblePolynomial field;
};

#endif //POLYNOMIAL_H_INCLUDED