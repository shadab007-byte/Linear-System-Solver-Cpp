#include "Vector.hpp"
#include "Matrix.hpp"
#include "LinearSystem.hpp"
using namespace std;

int main() {
	// Test vector operations
	Vector v1(3), v2(3);
	v1(1) = 1.0;
	v1(2) = 2.0;
	v1(3) = 3.0;
	v2(1) = 4.0;
	v2(2) = 5.0;
	v2(3) = 6.0;

	cout << "Vector v1: "<<endl;
	v1.Print();

	cout << "Vector v2: "<<endl;
	v2.Print();

	Vector v3 = v1 + v2;
	cout << "v1 + v2: "<<endl;
	v3.Print();

	// Test matrix operations
	Matrix A(4,4);
	A(1, 1) = 1.0; A(1, 2) = 0.0; A(1, 3) = 0.0; A(1,4) = 3;
	A(2, 1) = 0.0; A(2, 2) = 1.0; A(2, 3) = 0.0; A(2,4) = 2;
    A(3, 1) = 0.0; A(3, 2) = 0.0; A(3, 3) = 1.0; A(3,4) = 3;
    A(3, 1) = 5.0; A(4, 2) = 0.0; A(4, 3) = 1.0; A(4,4) = 3;


	cout << "Matrix A: " << endl;
	A.Print();

	double detA = A.CalculateDeterminant();
	cout << "Determinant of A: " << detA << endl;

	// Test Linear System solver Ax = b
	Vector b(4);
	b(1) = 1.0;
	b(2) = 0.0;
	b(3) = 1.0;
    b(4) = 2.0;
	cout<<"Vector b"<<endl;
    b.Print();

	LinearSystem system(A, b);
	Vector solution = system.Solve();

	cout << "Solution to Ax = b is "<<endl;
	solution.Print();

	return 0;
}
