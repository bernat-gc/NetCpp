#pragma once

#include <vector>

class Matrix
{
private:
	int m_row;
	int m_col;
	std::vector<std::vector <double>> m_data;

public:
	Matrix(int row = 1, int col = 1);
	~Matrix();

	void setValueAt(double value, int r_ind, int c_ind);

	double getValueAt(int r_ind, int c_ind) const;

	void print();

	Matrix minor(int r_ind, int c_ind) const;

	double det() const;

	static Matrix multiply(const Matrix &A, const Matrix &B);
};

