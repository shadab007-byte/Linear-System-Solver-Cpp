#include "LinearSystem.hpp"
#include <cmath>
#include <cassert>
#include <algorithm> // Ensure std::swap is included

// Constructor for LinearSystem
LinearSystem::LinearSystem(const Matrix& A, const Vector& b) {
    assert(A.GetNumRows() == A.GetNumCols());  // Ensure A is square
    assert(A.GetNumRows() == b.GetSize());     // Ensure dimensions match

    mSize = A.GetNumRows();
    mpA = new Matrix(A);
    mpb = new Vector(b);
}

// Destructor for LinearSystem
LinearSystem::~LinearSystem() {
    delete mpA;
    delete mpb;
}

// Solve method using Gaussian elimination with partial pivoting
Vector LinearSystem::Solve() {
    Vector m(mSize);
    Vector solution(mSize);

    Matrix& rA = *mpA;
    Vector& rb = *mpb;

    // Forward elimination
    for (int k = 0; k < mSize - 1; ++k) {
        // Pivoting
        double max = 0.0;
        int row = -1;
        for (int i = k; i < mSize; ++i) {
            if (fabs(rA(i+1, k+1)) > max) {
                row = i;
                max = fabs(rA(i+1, k+1));
            }
        }
        assert(row >= 0);

        // Row swap if necessary
        if (row != k) {
            for (int i = 0; i < mSize; ++i) {
                std::swap(rA(k+1, i+1), rA(row+1, i+1)); // Use std::swap
            }
            std::swap(rb(k+1), rb(row+1)); // Use std::swap
        }

        // Eliminate below the pivot
        for (int i = k + 1; i < mSize; ++i) {
            m(i+1) = rA(i+1, k+1) / rA(k+1, k+1);
            for (int j = k; j < mSize; ++j) {
                rA(i+1, j+1) -= rA(k+1, j+1) * m(i+1);
            }
            rb(i+1) -= rb(k+1) * m(i+1);
        }
    }

    // Back substitution
    for (int i = mSize - 1; i >= 0; --i) {
        solution(i+1) = rb(i+1);
        for (int j = i+1; j < mSize; ++j) {
            solution(i+1) -= rA(i+1, j+1) * solution(j+1);
        }
        solution(i+1) /= rA(i+1, i+1);
    }

    return solution;
}
