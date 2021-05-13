class IrreduciblePolynomial: public BasePolynomial{
    friend class Polynomial;
    public:
        explicit IrreduciblePolynomial(long long f_num);
        ~IrreduciblePolynomial() override = default;
    private:
        long long field_size;
        inline static const std::unordered_map<long long, long long> polynomials;
        long long get_val(long long f_size) const;
};


## Data Member

#### field_size
This is the number of elements in the given field which the irreducable polynomial represents.