#include <vector>

class RealPolynomial
{
private:
    int degree{};
    std::vector<double> coeffs{};
public:

    RealPolynomial(std::vector<double> coeffs);
    RealPolynomial(const RealPolynomial& other);
    ~RealPolynomial();

    void printPol();
    double evaluate(double x);

    bool operator==(const RealPolynomial& other);
    RealPolynomial operator+(const RealPolynomial& other);
    RealPolynomial operator-(const RealPolynomial& other);
    RealPolynomial operator*(const RealPolynomial& other);

    double getCoeff(size_t i);
    void setCoeff(size_t i, double coeff);
};

