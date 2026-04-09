#include <vector>

class RealPolynomial
{
private:
    int n{};
    std::vector<double> element{};
public:
    RealPolynomial(std::vector<double> element);
    ~RealPolynomial();
    void printPol();
    double evaluate(double x);
    RealPolynomial* addPolynomial(RealPolynomial other);
};

