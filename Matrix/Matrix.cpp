#include "stdafx.h"
#include "Matrix.h"
#include <iostream>
#include <vector>
#include <cassert>

// The matrix represented with this class are 1-indexed

Matrix::Matrix(int row, int col): m_row(row), m_col(col)
{
	m_data.resize(row);
	for (int i = 0; i < row; i++)
		m_data[i].resize(col);
}

Matrix::~Matrix()
{
}

void Matrix::setValueAt(double value, int r_ind, int c_ind)
{
	assert(r_ind > 0 && r_ind <= m_row && c_ind > 0 && c_ind <= m_col);
	m_data[r_ind-1][c_ind-1] = value;
}

double Matrix::getValueAt(int r_ind, int c_ind) const
{
	assert(r_ind > 0 && r_ind <= m_row && c_ind > 0 && c_ind <= m_col);
	return m_data[r_ind - 1][c_ind - 1];
}

void Matrix::print()
{
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			std::cout << m_data[i][j] << "\t";
		}
		std::cout << std::endl;
	}
		
}

Matrix Matrix::minor(int r_ind, int c_ind) const
{
	Matrix minor{ m_row - 1, m_col - 1 };
	int r{ 1 };
	int c;
	double v;

	for (int i = 1; i <= m_row; i++)
	{
		if (i == r_ind) {
			continue;
		}
		else {
			c = 1;
			for (int j = 1; j <= m_col; j++)
			{
				if (j == c_ind) {
					continue;
				}
				else {
					v = getValueAt(i, j);
					minor.setValueAt(v, r, c);
					c++;
				}
			}
			r++;
		}
	}

	return minor;
}

double Matrix::det() const
{
	assert(m_col == m_row);
	double det{ 0 };

	if (m_row == 2) {
		det = m_data[0][0] * m_data[1][1] - m_data[0][1] * m_data[1][0];
	}
	else {
		Matrix minor;
		int sign;
		for (int i = 1; i <= m_row; i++)
		{
			if (m_data[i-1][0] == 0) {
				continue;
			}
			minor = this->minor(i, 1);
			sign = 2 * (i % 2) - 1; // 1 for odd indices, -1 for even indices
			det += sign * m_data[i-1][0] * minor.det();
		}
	}
	return det;
}

Matrix Matrix::multiply(const Matrix &A, const Matrix &B)
{
	assert(A.m_col == B.m_row);

	Matrix C{ A.m_row, B.m_col };
	double value;
	
	for (int i = 1; i <= A.m_row; i++)
	{
		for (int j = 1; j <= B.m_col; j++)
		{
			value = 0;
			for (int k = 1; k <= A.m_col; k++)
			{
				value += A.getValueAt(i, k) * B.getValueAt(k, j); 
			}
			C.setValueAt(value, i, j);
		}
	}
	return C;
}
