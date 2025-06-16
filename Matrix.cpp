#include "Matrix.hpp"
#include <iostream>
#include <cassert>
using namespace std;
// Constructor
Matrix::Matrix(int numRows, int numCols) {
    assert(numRows > 0 && numCols > 0);
    mNumRows = numRows;
    mNumCols = numCols;
    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; i++) {
        mData[i] = new double[mNumCols];
        for (int j = 0; j < mNumCols; j++) {
            mData[i][j] = 0.0;
        }
    }
}

// Copy constructor
Matrix::Matrix(const Matrix& otherMatrix) {
    mNumRows = otherMatrix.mNumRows;
    mNumCols = otherMatrix.mNumCols;
    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; i++) {
        mData[i] = new double[mNumCols];
        for (int j = 0; j < mNumCols; j++) {
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
}

// Destructor
Matrix::~Matrix() {
    for (int i = 0; i < mNumRows; i++) {
        delete[] mData[i];
    }
    delete[] mData;
}

// Get number of rows
int Matrix::GetNumRows() const {
    return mNumRows;
}

// Get number of columns
int Matrix::GetNumCols() const {
    return mNumCols;
}

// One-based indexing
double& Matrix::operator()(int i, int j) {
    assert(i > 0 && i <= mNumRows);
    assert(j > 0 && j <= mNumCols);
    return mData[i-1][j-1];
}

// Assignment operator
Matrix& Matrix::operator=(const Matrix& otherMatrix) {
    assert(mNumRows == otherMatrix.mNumRows && mNumCols == otherMatrix.mNumCols);
    for (int i = 0; i < mNumRows; i++) {
        for (int j = 0; j < mNumCols; j++) {
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
    return *this;
}

// Unary + operator
Matrix Matrix::operator+() const {
     Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; i++) {
        for (int j = 0; j < mNumCols; j++) {
            result.mData[i][j] = +mData[i][j];
        }
    }
    return result;
}

// Unary - operator
Matrix Matrix::operator-() const {
    Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; i++) {
        for (int j = 0; j < mNumCols; j++) {
            result.mData[i][j] = -mData[i][j];
        }
    }
    return result;
}

// Binary + operator
Matrix Matrix::operator+(const Matrix& otherMatrix) const {
    assert(mNumRows == otherMatrix.mNumRows && mNumCols == otherMatrix.mNumCols);
    Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; i++) {
        for (int j = 0; j < mNumCols; j++) {
            result.mData[i][j] = mData[i][j] + otherMatrix.mData[i][j];
        }
    }
    return result;
}

// Binary - operator
Matrix Matrix::operator-(const Matrix& otherMatrix) const {
    assert(mNumRows == otherMatrix.mNumRows && mNumCols == otherMatrix.mNumCols);
    Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; i++) {
        for (int j = 0; j < mNumCols; j++) {
            result.mData[i][j] = mData[i][j] - otherMatrix.mData[i][j];
        }
    }
    return result;
}

// Determinant calculation (only for square matrices)
double Matrix::CalculateDeterminant() const {
    assert(mNumRows == mNumCols);
    
    if (mNumRows == 1) {
        return mData[0][0];
    }
    if (mNumRows == 2) {
        return mData[0][0] * mData[1][1] - mData[0][1] * mData[1][0];
    }
    
    double determinant = 0.0;
    for (int k = 0; k < mNumCols; k++) {
        Matrix subMatrix(mNumRows - 1, mNumCols - 1);
        for (int i = 1; i < mNumRows; i++) {
            int colSub = 0;
            for (int j = 0; j < mNumCols; j++) {
                if (j == k) continue;
                subMatrix(i, colSub + 1) = mData[i][j];
                colSub++;
            }
        }
        determinant += (k % 2 == 0 ? 1 : -1) * mData[0][k] * subMatrix.CalculateDeterminant();
    }
    
    return determinant;
}

// Print matrix
void Matrix::Print() const {
    for (int i = 0; i < mNumRows; i++) {
        for (int j = 0; j < mNumCols; j++) {
            cout << mData[i][j] << " ";
        }
        cout << endl;
    }
}
