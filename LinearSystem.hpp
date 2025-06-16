#ifndef LINEARSYSTEMHEADERDEF
#define LINEARSYSTEMHEADERDEF

#include "Matrix.hpp"
#include "Vector.hpp"

class LinearSystem 
{
private:
    int mSize; // Size of the linear systema
    Matrix* mpA; // Coefficient matrix
    Vector* mpb; // Right-hand side vector

    // Private copy constructor to prevent copying
    LinearSystem(const LinearSystem& otherLinearSystem) {}

public:
    // Constructor to initialize the system
    LinearSystem(const Matrix& A, const Vector& b);

    // Destructor
    ~LinearSystem();

    // Method for solving the linear system using Gaussian elimination
    Vector Solve();
};

#endif
