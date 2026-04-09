# 📐 RealPolynomial — C++ Polynomial Library

A modern C++ implementation for manipulating real polynomials efficiently.

## 🚀 Features

- 📦 Polynomial representation using `std::vector<double>`
- 🖨️ Pretty printing of polynomials
- ⚡ Fast evaluation using Horner's method
- ➕ Polynomial addition
- ✖️ Fast multiplication using Karatsuba algorithm
- 🧠 (Planned) Extended Euclidean algorithm

---

## 📚 Representation

A polynomial is stored as a vector:

```cpp
std::vector<double> coeffs;
```

Where:

P(x) = a0 + a1 x + a2 x^2 + ... + an x^n

Example:

```cpp
// Represents 3 + 2x + 5x²
{3, 2, 5}
```

---

## 🛠️ Usage

### Create a Polynomial

```cpp
RealPolynomial p({3, 2, 5}); // 3 + 2x + 5x²
```

---

### 🖨️ Print

```cpp
p.print(); 
// Output: 5x^2 + 2x + 3
```

---

### ⚡ Evaluate (Horner's Method)

Efficient evaluation in O(n):

```cpp
double result = p.evaluate(2.0);
```

---

### ➕ Addition

```cpp
RealPolynomial p1({1, 2});
RealPolynomial p2({3, 4, 5});

RealPolynomial sum = p1 + p2;
```

---

### ✖️ Multiplication (Karatsuba)

```cpp
RealPolynomial product = p1 * p2;
```

- Faster than naive O(n^2)
- Uses divide & conquer

---

## 🧠 Upcoming Features

### Extended Euclidean Algorithm

- Polynomial GCD computation
- Bézout coefficients

---

## 📈 Complexity

| Operation       | Complexity              |
|----------------|------------------------|
| Evaluation     | O(n)                   |
| Addition       | O(n)                   |
| Multiplication | O(n^log₂3) ≈ O(n^1.585)|

---

## 🎯 Goals

- Clean and efficient implementation
- Educational value (Horner & Karatsuba)
- Extendable toward algebraic structures

---

## 💡 Possible Improvements

- Complex coefficients
- FFT-based multiplication
- Sparse polynomial optimization

---

## 🧪 Example

```cpp
RealPolynomial p({1, 2, 3});   // 1 + 2x + 3x²
RealPolynomial q({4, 5});      // 4 + 5x

auto r = p * q;

r.print();
// Expected: 3x^3 + 22x^2 + 13x + 4
```