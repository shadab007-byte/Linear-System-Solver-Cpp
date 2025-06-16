# Linear System Solver in C++

This project implements a complete C++ system for solving linear equations of the form:

\[
Ax = b
\]

using **Gaussian Elimination with Partial Pivoting**. The implementation includes custom Matrix and Vector classes with full operator overloading and determinant support.

---

## 🚀 Features

### ✅ Vector Class
- Dynamic memory allocation
- 1-based and 0-based indexing
- Overloaded operators: `+`, `-`, scalar `*`
- p-norm calculation
- Print function

### ✅ Matrix Class
- Dynamic 2D memory
- Operator overloading
- Unary/binary `+` and `-`
- Determinant computation via recursion
- Safe access with 1-based indexing

### ✅ LinearSystem Class
- Solves \( Ax = b \) using Gaussian Elimination
- Includes **partial pivoting** for numerical stability

---

## 🔧 Files

| File            | Description                     |
|-----------------|---------------------------------|
| `Vector.hpp/cpp`| Custom vector class             |
| `Matrix.hpp/cpp`| Matrix class with operations    |
| `LinearSystem.cpp/hpp` | Gaussian Elimination Solver |

---

## 🧪 Example Usage

```cpp
Matrix A(3,3);
// Fill A(i,j)...

Vector b(3);
// Fill b(i)...

LinearSystem system(A, b);
Vector x = system.Solve();
x.Print();
