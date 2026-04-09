# 📐 RealPolynomial — C++ Polynomial Class

A small C++ class for manipulating real polynomials stored with a `std::vector<double>`.

## 🚀 Current Features

- Polynomial representation using `std::vector<double>`
- Printing a polynomial with `printPol()`
- Polynomial evaluation with `evaluate(double x)`
- Polynomial addition with `addPolynomial(RealPolynomial other)`

## 📚 Class Interface

```cpp
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
```

## Representation

The polynomial is stored as a vector of coefficients.

```cpp
std::vector<double> element;
```

With the convention:

\[
P(x) = a_0 + a_1 x + a_2 x^2 + \dots + a_n x^n
\]

Example:

```cpp
// Represents 3 + 2x + 5x^2
{3, 2, 5}
```

## 🛠️ Usage

### Create a Polynomial

```cpp
RealPolynomial p({3, 2, 5});
```

This represents:

\[
P(x) = 3 + 2x + 5x^2
\]

### Print a Polynomial

```cpp
p.printPol();
```

Example output:

```cpp
5x^2 + 2x + 3
```

### Evaluate a Polynomial

```cpp
double value = p.evaluate(2.0);
```

Example:

\[
P(2) = 3 + 2 \cdot 2 + 5 \cdot 2^2 = 27
\]

### Add Two Polynomials

```cpp
RealPolynomial p1({1, 2});
RealPolynomial p2({3, 4, 5});

RealPolynomial* sum = p1.addPolynomial(p2);
sum->printPol();
```

This corresponds to:

\[
(1 + 2x) + (3 + 4x + 5x^2) = 4 + 6x + 5x^2
\]

## 📈 Complexity

| Operation | Complexity |
|----------|------------|
| Printing | O(n) |
| Evaluation | O(n) |
| Addition | O(n) |

## 🎯 Project Goal

This class is part of a polynomial manipulation project in C++, with the aim of progressively adding more advanced algorithms.

## 🔮 Planned Features

- Multiplication with the Karatsuba algorithm
- Extended Euclidean algorithm for polynomials
- Better memory management
- Operator overloading (`+`, `*`, `<<`, etc.)
- Possible switch from raw pointers to safer return types

## ⚠️ Current Notes

- The class currently stores coefficients in a vector.
- Addition currently returns a pointer: `RealPolynomial*`.
- The internal field `n` likely represents the polynomial degree or size.
- The interface is still evolving.

## 🧪 Example

```cpp
RealPolynomial p({2, 1});     // 2 + x
RealPolynomial q({4, 3, 1});  // 4 + 3x + x^2

RealPolynomial* r = p.addPolynomial(q);
r->printPol();

double y = r->evaluate(2.0);
```

## Possible Future Improvements

- Avoid manual memory handling
- Add normalization for trailing zeros
- Support multiplication and division
- Add polynomial derivative and integral
- Add unit tests
