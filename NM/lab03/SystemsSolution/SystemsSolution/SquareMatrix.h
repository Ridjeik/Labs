#pragma once

#include <iostream>
#include <vector>
class SquareMatrix
{
	double** data;
	int size;
public:
	SquareMatrix(const int size);
	SquareMatrix(const SquareMatrix& other);
	SquareMatrix(SquareMatrix&& other);
	~SquareMatrix();
	
	SquareMatrix withoutRowAndColumn(const int row, const int column) const;
	double minor(const int row, const int column) const;
	double algebraicAddition(const int row, const int column) const;
	SquareMatrix withReplacedColumn(const int column, const std::vector<double>& newColumn) const;
	SquareMatrix T() const;
	SquareMatrix inversed() const;
	int matrixSize() const;
	
	friend double det(const SquareMatrix& matrix);
	
	friend SquareMatrix operator*(const double num, const SquareMatrix& matrix);
	friend SquareMatrix operator*(const SquareMatrix& matrix, const double num);
	friend std::vector<double> operator*(const SquareMatrix& matrix, const std::vector<double>& vector);
	friend std::ostream& operator<<(std::ostream& out, const SquareMatrix& matrix);
	friend std::istream& operator>>(std::istream& in, SquareMatrix& matrix);
};

std::ostream& operator<<(std::ostream& out, const std::vector<double>& vector);
std::istream& operator>>(std::istream& in, std::vector<double>& vector);

