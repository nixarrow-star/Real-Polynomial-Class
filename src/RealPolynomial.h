#include <vector>

class RealPolynomial
{
private:
    int n{};
    std::vector<float> element{};
public:
    RealPolynomial(std::vector<float> element);
    ~RealPolynomial();
    void printPol();
    float evaluate(float x);
    RealPolynomial* addPolynomial(RealPolynomial other);
};

