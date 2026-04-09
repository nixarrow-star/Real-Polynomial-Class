#include "RealPolynomial.h"
#include <iostream>

RealPolynomial::RealPolynomial(std::vector<double> element)
{
    this->n = element.size();
    this->element = element;
}

RealPolynomial::~RealPolynomial()
{
    this->element.clear();
}

void RealPolynomial::printPol()
{
    if(this->n == 0)
        return;

    std::cout << this->element.front() << " + ";
    

    for (size_t i = 1; i < this->n; i++)
    {
        if(element.at(i) != 0.0)
        {
            std::cout << this->element.at(i) << " X^" << i << " + ";
        }
    }
    std::cout << std::endl;
}

double RealPolynomial::evaluate(double x)
{
    if(this->n == 1)
    {
        return this->element.at(0);
    }

    double f = this->element.at(this->n-2) + x*this->element.at(this->n-1);

    for(int i = n-3; i >= 0; i--)
    {
        f = this->element.at(i) + x * f;
    }

    return f;
}

RealPolynomial* RealPolynomial::addPolynomial(RealPolynomial other)
{
    int max = this->n > other.n ? this->n : other.n;

    std::vector<double> new_vec{};
    for(int i = 0; i < max; i++)
    {
        if(i < this->n && i < other.n)
        {
            new_vec.push_back(this->element.at(i) + other.element.at(i));
        }
        else if(i < this->n && i >= other.n) 
        {
            new_vec.push_back(this->element.at(i));
        }
        else if (i >= this->n && i < other.n)
        {
            new_vec.push_back(other.element.at(i));
        }
    }

    return new RealPolynomial(new_vec);

}
