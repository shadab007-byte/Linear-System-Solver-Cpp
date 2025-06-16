#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF

#include "Vector.hpp"

class Matrix {
private:
    int mNumRows, mNumCols;
    double** mData;

public:
    Matrix(int numRows, int numCols);
    Matrix(const Matrix& otherMatrix);
    ~Matrix();

    int GetNumRows() const;
    int GetNumCols() const;
    double& operator()(int i, int j);

    Matrix& operator=(const Matrix& otherMatrix);
    Matrix operator+() const;
    Matrix operator-() const;
    Matrix operator+(const Matrix& otherMatrix) const;
    Matrix operator-(const Matrix& otherMatrix) const;

    // Determinant method
    double CalculateDeterminant() const;

    // Print method
    void Print() const;
};

#endif
