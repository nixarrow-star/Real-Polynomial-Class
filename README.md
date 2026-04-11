# 🚀 RealPolynomial

> A modern C++ implementation of real polynomials with optimized
> multiplication and clean operator overloading.

------------------------------------------------------------------------

## ✨ Overview

`RealPolynomial` is a C++ class designed to represent and manipulate
polynomials with real coefficients.

A polynomial:

P(x) = a0 + a1 x + a2 x\^2 + ... + an x\^n

is internally stored as:

``` cpp
{a0, a1, a2, ..., an}
```

Example:

``` cpp
{3.0, -2.0, 5.0}  // 3 - 2x + 5x^2
```

------------------------------------------------------------------------

## ⚙️ Features

### 🔢 Core Operations

-   Polynomial addition
-   Polynomial subtraction
-   Polynomial multiplication

### ⚡ Optimized Multiplication

-   **Naive multiplication** for small sizes *(n \< 32)*
-   **Karatsuba algorithm** for larger polynomials *(n ≥ 32)*

### 📐 Evaluation

-   Uses **Horner's method** for optimal evaluation:

``` text
O(n) instead of O(n^2)
```

### 🧰 Utility

-   Access coefficients
-   Modify coefficients
-   Pretty printing
-   Equality comparison

------------------------------------------------------------------------

## 🧠 Algorithms Used

### 🔹 Naive Multiplication

-   Complexity: **O(n²)**
-   Used when:

``` text
n < 32
```

### 🔹 Karatsuba Multiplication

-   Complexity: **O(n\^1.585)**
-   Used when:

``` text
n ≥ 32
```

Reduces the number of multiplications from 4 to 3 recursively.

------------------------------------------------------------------------

### 🔹 Horner's Method (Evaluation)

Evaluates:

P(x) = a0 + a1 x + a2 x\^2 + ...

as:

``` text
(...((an)x + an-1)x + ... + a0)
```

👉 Minimizes multiplications and improves numerical stability.

------------------------------------------------------------------------

## 🧩 Class Interface

``` cpp
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
```

------------------------------------------------------------------------

## 🧪 Example Usage

``` cpp
RealPolynomial p({1.0, 2.0, 3.0});   // 1 + 2x + 3x^2
RealPolynomial q({4.0, 5.0});        // 4 + 5x

auto sum  = p + q;
auto diff = p - q;
auto prod = p * q;

p.printPol();
q.printPol();
sum.printPol();
prod.printPol();

std::cout << p.evaluate(2.0) << std::endl;
```

------------------------------------------------------------------------

## 📌 Design Notes

-   Coefficients are stored in **increasing degree order**
-   Index `i` corresponds to coefficient of **x\^i**
-   Internal trimming removes trailing zeros
-   Hybrid multiplication ensures optimal performance

------------------------------------------------------------------------

## 🚧 Upcoming Features

### 🧮 Extended Euclidean Algorithm

-   Polynomial GCD
-   Bézout coefficients
-   Foundation for:
    -   algebra systems
    -   symbolic computation
    -   cryptography

------------------------------------------------------------------------

## 💡 Future Improvements

-   FFT-based multiplication for very large polynomials
-   Rational / integer coefficient support
-   SIMD / low-level optimizations
-   Serialization support

------------------------------------------------------------------------

## 🏁 Conclusion

This project aims to provide a **clean, efficient, and extensible
polynomial library** suitable for:

-   Algorithmic experimentation
-   Compiler / language development
-   Mathematical computing

------------------------------------------------------------------------

🔥 *Built for performance, clarity, and future expansion.*
