// MatrixTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <vector>

using namespace std;

void test_mult();
void test_minor();
void test_det();
void test_vector(vector<float> v);

int main()
{
	test_mult();
	test_minor();
	test_det();
	
	test_vector(vector<float> { 2.3f, 4, 5, 3.4f });
	
	
	system("pause");

	return 0;
}

void test_mult()
{
	Matrix m = Matrix(2, 2);
	m.setValueAt(0, 1, 1);
	m.setValueAt(1, 1, 2);
	m.setValueAt(1, 2, 1);
	m.setValueAt(0, 2, 2);

	Matrix m2 = Matrix(2, 2);
	m2.setValueAt(1, 1, 1);
	m2.setValueAt(0, 1, 2);
	m2.setValueAt(0, 2, 1);
	m2.setValueAt(-1, 2, 2);

	cout << "Matrix A is\n";
	m.print();
	cout << "\n";

	cout << "Matrix B is\n";
	m2.print();
	cout << "\n";

	Matrix C;

	C = Matrix::multiply(m, m2);
	cout << "The product A x B is\n";
	C.print();
	cout << "\n";

	C = Matrix::multiply(m2, m);
	cout << "The product B x A is\n";
	C.print();
	cout << "\n";

	C = Matrix::multiply(m, m);
	cout << "The product A x A is\n";
	C.print();
	cout << "\n";
}

void test_minor()
{
	Matrix m = Matrix(4, 4);
	
	srand(time(NULL));
	int r_val;

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			r_val = (rand() % 11 );
			m.setValueAt(r_val, i, j);
		}
	}
	cout << "Original matrix:\n";
	m.print();
	cout << "\n";

	Matrix minor = m.minor(2, 3);
	cout << "Minor of position (2, 3):\n";
	minor.print();

	minor = m.minor(1, 4);
	cout << "Minor of position (1, 4):\n";
	minor.print();
}

void test_det()
{
	Matrix m = Matrix(2, 2);
	m.setValueAt(2, 1, 1);
	m.setValueAt(2, 2, 2);
	m.setValueAt(1, 1, 2);
	m.setValueAt(1, 2, 1);

	cout << "Matrix:\n";
	m.print();

	cout << "Det = " << m.det() << endl;

	Matrix m2 = Matrix(3, 3);
	m2.setValueAt(2, 1, 1);
	m2.setValueAt(2, 2, 2);
	m2.setValueAt(2, 3, 3);

	m2.setValueAt(1, 1, 2);
	m2.setValueAt(1, 2, 1);

	cout << "Matrix:\n";
	m2.print();

	cout << "Det = " << m2.det() << endl;

}

void test_vector(vector<float> v)
{
	cout << "The vector has size " << v.size() << endl;
}