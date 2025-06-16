#include <cmath>
#include <iostream>
#include <cassert>
#include "Vector.hpp"
using namespace std;
// Constructor for vector of a given size
Vector::Vector(int size)
{
	assert(size > 0);
	mSize = size;
	mData = new double[mSize];
	for (int i = 0; i < mSize; i++) {
		mData[i] = 0.0;
	}
}

// Copy constructor
Vector::Vector(const Vector& otherVector)
{
	mSize = otherVector.GetSize();
	mData = new double[mSize];
	for (int i = 0; i < mSize; i++) {
		mData[i] = otherVector.mData[i];
	}
}

// Destructor
Vector::~Vector() {
	delete[] mData;
}

// Get size of vector
int Vector::GetSize() const {
	return mSize;
}

// Zero-based indexing
double& Vector::operator[](int i) {
	assert(i >= 0 && i < mSize);
	return mData[i];
}

// Read-only variant of []
double Vector::Read(int i) const {
	assert(i >= 0 && i < mSize);
	return mData[i];
}

// One-based indexing
double& Vector::operator()(int i) {
	assert(i > 0 && i <= mSize);
	return mData[i-1];
}

// Assignment operator
Vector& Vector::operator=(const Vector& otherVector) {
	assert(mSize == otherVector.mSize);
	for (int i = 0; i < mSize; i++) {
		mData[i] = otherVector.mData[i];
	}
	return *this;
}

// Unary + operator
Vector Vector::operator+() const {
	Vector v(mSize);
	for (int i = 0; i < mSize; i++) {
		v[i] = mData[i];
	}
	return v;
}

// Unary - operator
Vector Vector::operator-() const {
	Vector v(mSize);
	for (int i = 0; i < mSize; i++) {
		v[i] = -mData[i];
	}
	return v;
}

// Binary + operator
Vector Vector::operator+(const Vector& v1) const {
	assert(mSize == v1.mSize);
	Vector v(mSize);
	for (int i = 0; i < mSize; i++) {
		v[i] = mData[i] + v1.mData[i];
	}
	return v;
}

// Binary - operator
Vector Vector::operator-(const Vector& v1) const {
	assert(mSize == v1.mSize);
	Vector v(mSize);
	for (int i = 0; i < mSize; i++) {
		v[i] = mData[i] - v1.mData[i];
	}
	return v;
}

// Scalar multiplication
Vector Vector::operator*(double a) const {
	Vector v(mSize);
	for (int i = 0; i < mSize; i++) {
		v[i] = a * mData[i];
	}
	return v;
}

// p-norm calculation
double Vector::CalculateNorm(int p) const {
	double sum = 0.0;
	for (int i = 0; i < mSize; i++) {
		sum += pow(fabs(mData[i]), p);
	}
	return pow(sum, 1.0 / p);
}

// Length function
int length(const Vector& v) {
	return v.mSize;
}
void Vector :: Print() const {
	for (int i = 0; i < mSize; ++i) {
		cout << mData[i] << endl;
	}
	cout << endl;
}
