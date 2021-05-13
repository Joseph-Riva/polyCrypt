# Polynomial
class Polynomial: public BasePolynomial{
    public:
        explicit Polynomial(long long value, long long field_size);
        ~Polynomial() override = default;
        const IrreduciblePolynomial& get_field() const;
        Polynomial operator+(const Polynomial&);
        Polynomial operator%(const IrreduciblePolynomial&);
        Polynomial operator*(const Polynomial&);
        Polynomial inverse();
        Polynomial sqrt();
        Polynomial additiveInverse();
        Polynomial pow(long long power);
    private:
        Polynomial pow_mod(Polynomial base, long long exp, IrreduciblePolynomial p, Polynomial b);
        IrreduciblePolynomial field;
};
## Constructing a Polynomial
    To create construct the polynomial x+1 in the field with 4 elements:

    `Polynomial p1(0b11, 4);`
## Method descriptions and Usage

#### Polynomial operator+(const Polynomial&)
This method adds two polynomials values modulo the irreducable polynomial contained in the class.

The usage would be something like: 
```
    Polynomial p1(0b1000, 4);
    Polynomial p2(0b0100, 4);
    cout << "p1 + p2 = " << p1+p2 << '\n';
```
#### Polynomial operator%(const IrreduciblePolynomial&)
This method takes current polynomial modulo an irreducable polynomial which is usually the one contained in this class.

The usage would be something like: 
```
    Polynomial p1(0b1111000, 16);
    IrreduciblePolynomial r(16);
    Polynomial result = p1 % r;
    cout << "p1 % r = " << result << '\n';
```
#### Polynomial operator*(const Polynomial&)
This method multiplies two polynomials and reduces them modulo the field they are in.

The usage would be something like:
```
    Polynomial p1(0b1000, 16);
    Polynomial p2(0b1111, 16);
    Polynomial p3 = p1*p2;
    cout << "p1 * p2 = " << p3 << '\n';
```
#### Polynomial inverse()
This method computes the multiplicative inverse of the polynomial which results in a polynomial which when multiplied 
by the current polynomial is equal to 1.

The usage would be something like:
```
    Polynomial p1(0b1000, 16);
    Polynomial p1_inv = p1.inverse();
    cout << "p1 inverse: " << p1_inv << '\n';
    assert((p1*p1_inv).value() == 1)
```
#### Polynomial sqrt()
This method computes the sqrt of the polynomial in the current field.

The usage would be something like:
```
    Polynomial p1(0b1000, 16);
    Polynomial p1_sqrt = p1.sqrt();
    cout << "p1 sqrt: " << p1.sqrt() << '\n';
```
#### Polynomial additiveInverse()
This method computes an additive inverse which when added to the current polynomial is 0 in the current field.

The usage would be something like:
```
    Polynomial p1(0b1000, 16);
    Polynomial p1_addInv = p1.additiveInverse();
    cout << "p1 additive inverse: " << p1.additiveInverse() << '\n';
```
#### Polynomial pow(long long power)
This method computes the current polynomial to the `power` power reduced to the field they are in.
```
    Polynomial p1(0b1000, 16);
    Polynomial p3 = p1.pow(2);
    cout << "p1 squared is: " << p3 << '\n';
```