#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF
#include <iostream>

class Vector
{
private:
	double* mData; // data stored in vector
	int mSize; // size of vector
public:
	Vector(const Vector& otherVector); // copy constructor
	Vector(int size);                  // one arg constructor
	~Vector();                         // destructor

	int GetSize() const;

	double& operator[](int i);         // zero-based indexing
	double Read(int i) const;          // read-only zero-based indexing
	double& operator()(int i);         // one-based indexing

	Vector& operator=(const Vector& otherVector); // assignment
	Vector operator+() const;                     // unary +
	Vector operator-() const;                     // unary -
	Vector operator+(const Vector& v1) const;     // binary +
	Vector operator-(const Vector& v1) const;     // binary -

	// scalar multiplication
	Vector operator*(double a) const;

	// p-norm method
	double CalculateNorm(int p=2) const;

	// declare length function as a friend
	friend int length(const Vector& v);

	// Print method for vectors
	void Print() const;

};
#endif
