# BasePolynomial

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


## Method Descriptions

#### long long degree() const
This method retrieves the degree of the polynomial given. The degree is the highest order term
it contains.

#### long long value() const
This method returns the value which the polynomial is encoded as.

#### std::ostream& operator<<(std::ostream& os, const BasePolynomial& b)
This prints the polynomial in a human readable format.