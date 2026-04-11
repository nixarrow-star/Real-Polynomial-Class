#include "RealPolynomial.h"
#include <iostream>

static constexpr double LIMIT {1e-12};

static void trimVector(std::vector<double>& v)
{
    while (!v.empty() && std::abs(v.back()) < LIMIT)
        v.pop_back();

    if(v.empty())
        v.push_back(0.0);
    
}

static std::vector<double> addVectors(const std::vector<double>& a, 
    const std::vector<double>& b)
{
    size_t n = std::max(a.size(), b.size());
    std::vector<double> result(n, 0.0);

    for(size_t i = 0; i < n; i++)
    {
        if(i < a.size()) result[i] += a[i];
        if(i < b.size()) result[i] += b[i];
    }

    trimVector(result);
    return result;
    
}

static std::vector<double> subVectors(const std::vector<double>& a, 
    const std::vector<double>& b)
{
    size_t n = std::max(a.size(), b.size());
    std::vector<double> result(n, 0.0);

    for(size_t i = 0; i < n; i++)
    {
        if(i < a.size()) result[i] += a[i];
        if(i < b.size()) result[i] -= b[i];
    }

    trimVector(result);
    return result;
    
}

static std::vector<double> multVectorNaiv(const std::vector<double>& a, 
    const std::vector<double>& b)
{
    std::vector<double> result(a.size() + b.size() -1, 0.0);
    for(size_t i = 0; i < a.size(); i++)
    {
        for(size_t j = 0; j < b.size(); j++)
        {
            result[i+j] += a[i]*b[j];
        }
    }

    trimVector(result);
    return result;
}

static std::vector<double> shiftVector(const std::vector<double>& v, size_t k)
{
    if (v.size() == 1 && std::abs(v[0]) < LIMIT)
    {
        std::vector<double> ret(1, 0.0);
        return ret;
    }

    std::vector<double> result(k, 0.0);
    result.insert(result.end(), v.begin(), v.end());
    trimVector(result);
    return result;
}

static std::vector<double> slice(const std::vector<double>& v, size_t start, size_t end)
{
    if (start >= v.size() || start >= end)
    {
        std::vector<double> ret(1, 0.0);
        return ret;
    }

    end = std::min(end, v.size());
    std::vector<double> result(v.begin() + start, v.begin() + end);
    trimVector(result);
    return result;
}

static std::vector<double> multVectorKaratsuba(const std::vector<double>& a, const std::vector<double>& b)
{
    size_t n = std::max(a.size(), b.size());

    if (a.size() <= 32 || b.size() <= 32)
        return multVectorNaiv(a, b);

    size_t m = n / 2;

    std::vector<double> a0 = slice(a, 0, m);
    std::vector<double> a1 = slice(a, m, a.size());
    std::vector<double> b0 = slice(b, 0, m);
    std::vector<double> b1 = slice(b, m, b.size());

    std::vector<double> z0 = multVectorKaratsuba(a0, b0);
    std::vector<double> z2 = multVectorKaratsuba(a1, b1);

    std::vector<double> a0PlusA1 = addVectors(a0, a1);
    std::vector<double> b0PlusB1 = addVectors(b0, b1);

    std::vector<double> z1 = multVectorKaratsuba(a0PlusA1, b0PlusB1);

    std::vector<double> middle = subVectors(subVectors(z1, z0), z2);

    std::vector<double> result = addVectors(
        addVectors(z0, shiftVector(middle, m)),
        shiftVector(z2, 2 * m)
    );

    trimVector(result);
    return result;
}


// ============================== Public Functions ============================

RealPolynomial::RealPolynomial(std::vector<double> coeffs)
{
    trimVector(coeffs);
    this->degree = coeffs.size()-1;
    this->coeffs = coeffs;
}

RealPolynomial::RealPolynomial(const RealPolynomial& other)
{
    std::vector<double> coeffs(other.coeffs.size(), 0.0);
    for(size_t i = 0; i < other.coeffs.size(); i++)
    {
        coeffs[i] = other.coeffs[i];
    }
    this->degree = other.degree;
    this->coeffs = coeffs;
}

RealPolynomial::~RealPolynomial()
{
    this->coeffs.clear();
}

void RealPolynomial::printPol()
{
    if(this->coeffs.size() == 0)
        return;
    
    if(this->degree == 0)
    {
        std::cout << this->coeffs[0] << std::endl;
    }   

    std::cout << this->coeffs.front() << " + ";
    

    for (size_t i = 1; i < this->degree; i++)
    {
        if(this->coeffs.at(i) != 0.0)
        {
            std::cout << this->coeffs.at(i) << " X^" << i << " + ";
        }
    }
    std::cout << this->coeffs.back() << std::endl;
}

double RealPolynomial::evaluate(double x)
{
    if(this->coeffs.size() == 0)
        return 0;

    if(this->degree == 0)
    {
        return this->coeffs.at(0);
    }

    double f = this->coeffs.at(this->coeffs.size()-2) + 
    x*this->coeffs.at(this->coeffs.size()-1);

    for(int i = this->coeffs.size()-3; i >= 0; i--)
    {
        f = this->coeffs.at(i) + x * f;
    }

    return f;
}

bool RealPolynomial::operator==(const RealPolynomial& other)
{
    if(this->degree != other.degree)
        return false;

    for(size_t i = 0; i <= this->degree; i++)
    {
        if(this->coeffs[i] != other.coeffs[i])
            return false;
    }
    return true;
}

RealPolynomial RealPolynomial::operator+(const RealPolynomial& other)
{
    return RealPolynomial(addVectors(this->coeffs, other.coeffs));
}

RealPolynomial RealPolynomial::operator-(const RealPolynomial& other)
{
    return RealPolynomial(subVectors(this->coeffs, other.coeffs));
}

RealPolynomial RealPolynomial::operator*(const RealPolynomial& other)
{
    return RealPolynomial(multVectorKaratsuba(this->coeffs, other.coeffs));
}

// ============================== Getter/Setter ===============================

double RealPolynomial::getCoeff(size_t i)
{
    return this->coeffs[i];
}
void RealPolynomial::setCoeff(size_t i, double coeff)
{
    this->coeffs[i] = coeff;
    if(coeff < LIMIT && (int)i == this->degree)
        trimVector(this->coeffs);
}
