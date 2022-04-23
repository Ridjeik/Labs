#include "SquareMatrix.h"
#include <string>

SquareMatrix::SquareMatrix(int size)
{
	this->size = size;
	this->data = new double* [size];
	for (int i = 0; i < size; i++)
	{
		this->data[i] = new double[size];
	}
}

SquareMatrix::SquareMatrix(const SquareMatrix& other) : SquareMatrix(other.size)
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			this->data[i][j] = other.data[i][j];
		}
	}
}

SquareMatrix::SquareMatrix(SquareMatrix&& other)
{
	this->size = other.size;
	this->data = other.data;
	other.data = nullptr;
}

SquareMatrix::~SquareMatrix()
{
	if(this->data)
		for (int i = 0; i < this->size; i++)
		{
			delete[] this->data[i];
		}
	delete[] this->data;
}

SquareMatrix SquareMatrix::withReplacedColumn(const int column, const std::vector<double>& newColumn) const
{
	if (this->size != newColumn.size()) throw std::string("Invalid size of new column!");

	SquareMatrix result(*this);

	for (int i = 0; i < this->size; i++)
	{
		result.data[i][column] = newColumn[i];
	}
	return result;
}

SquareMatrix SquareMatrix::T() const
{
	SquareMatrix result(*this);
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			std::swap(result.data[i][j], result.data[j][i]);
		}
	}
	return result;
}

SquareMatrix SquareMatrix::inversed() const
{
	double d = det(*this);
	if (d == 0) throw std::string("Inversed matrix doesn't exist");
	SquareMatrix result(this->size);
	for (int i = 0; i < result.size; i++)
	{
		for (int j = 0; j < result.size; j++)
		{
			result.data[i][j] = this->algebraicAddition(i, j);
		}
	}
	return (1 / d) * result.T();
}

int SquareMatrix::matrixSize() const
{
	return this->size;
}

SquareMatrix SquareMatrix::withoutRowAndColumn(const int row, const int column) const
{
	if (row > this->size || column > this->size) throw std::string("Invalid parameters!");
	
	SquareMatrix result(this->size - 1);
	for (int i = 0, u = 0; i < this->size; i++)
	{
		if (i == row) continue;
		for (int j = 0, k = 0; j < this->size; j++)
		{
			if (j == column) continue;
			result.data[u][k] = this->data[i][j];
			k++;
		}
		u++;
	}
	return result;
}

double SquareMatrix::minor(const int row, const int column) const
{
	return det(this->withoutRowAndColumn(row, column));
}

double SquareMatrix::algebraicAddition(const int row, const int column) const 
{
	if ((row + column) % 2 == 0) return this->minor(row, column);
	else return -this->minor(row, column);
}

double det(const SquareMatrix& matrix)
{
	if (matrix.size == 1) return matrix.data[0][0];
	
	double res = 0;
	for (int i = 0; i < matrix.size; i++)
	{
		res += matrix.data[0][i] * matrix.algebraicAddition(0, i);
	}
	return res;
}

SquareMatrix operator*(const double num, const SquareMatrix& matrix)
{
	SquareMatrix result(matrix);

	for (int i = 0; i < result.size; i++)
	{
		for (int j = 0; j < result.size; j++)
		{
			result.data[i][j] *= num;
		}
	}
	return result;
}

SquareMatrix operator*(const SquareMatrix& matrix, const double num)
{
	SquareMatrix result(matrix);

	for (int i = 0; i < result.size; i++)
	{
		for (int j = 0; j < result.size; j++)
		{
			result.data[i][j] *= num;
		}
	}
	return result;
}

std::vector<double> operator*(const SquareMatrix& matrix, const std::vector<double>& vector)
{
	if (matrix.size != vector.size()) throw std::string("Not equal sizes!");

	std::vector<double> result(matrix.size, 0);

	for (int i = 0; i < matrix.size; i++)
	{
		for (int j = 0; j < matrix.size; j++)
		{
			result[i] += matrix.data[i][j] * vector[j];
		}
	}
	return result;
}

std::ostream& operator<<(std::ostream& out, const SquareMatrix& matrix)
{
	for (int i = 0; i < matrix.size; i++)
	{
		for (int j = 0; j < matrix.size; j++)
		{
			out << matrix.data[i][j] << " ";
		}
		out << '\n';
	}
	return out;
}

std::istream& operator>>(std::istream& in, SquareMatrix& matrix)
{
	for (int i = 0; i < matrix.size; i++)
	{
		for (int j = 0; j < matrix.size; j++)
		{
			in >> matrix.data[i][j];
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const std::vector<double>& vector)
{
	for (double elem : vector)
	{
		out << elem << " ";
	}
	return out;
}

std::istream& operator>>(std::istream& in, std::vector<double>& vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		in >> vector[i];
	}
	return in;
}
