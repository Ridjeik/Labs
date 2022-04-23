#pragma once

#include <iostream>
#include <array>
#include <algorithm>

template<size_t rows, size_t columns>
class Matrix
{
	using data_type = std::array<std::array<double, columns>, rows>;

	data_type data;

public:
		
	void selectMainElement(int row)
	{
		//шукаємо рядок, нижче заданого, що має максимальний елемент на заданій позиції.
		auto maxRow = std::max_element(begin() + row, end(),
			[row](const std::array<double, columns>& a, const std::array<double, columns>& b)
			{
				return b[row] > a[row];
			}
		);
		//Якщо цей рядок не є тип самим рядком, переставляємо місцями
		if (maxRow != begin() + row) std::swap(data[row], *maxRow);
	}

	void toUpperTriangle()
	{
		//Беремо і-й рядок
		for (int i = 0; i < rows; i++)
		{
			if (i != rows - 1) std::cout << "Обираємо головний елемент " << i + 1 << "-го стовпця.\n";
			//На кожному кроці шукаємо головний елемент.
			selectMainElement(i);

			if (i != rows - 1) std::cout << *this << std::endl;
			if (i != rows - 1)std::cout << "Вiднiмаємо " << i + 1 << "-й рядок вiд рядкiв пiд ним.\n";
			//Від всіх рядків нижче і-го...
			for (int j = i + 1; j < rows; j++)
			{
				//віднімаємо і-й рядок, помножений на частку головних елементів
				data[j] -= data[i] * (data[j][i] / data[i][i]);
			}

			if (i != rows - 1) std::cout << *this << std::endl;
		}
	}

	template<size_t rows, size_t columns>
	friend std::array<double, rows> gaussSolve(Matrix<rows, columns> A);

	template< size_t rows, size_t columns>
	friend std::array<double, rows> LUSolve(Matrix<rows, columns> A);

	typename data_type::iterator begin() { return data.begin(); }
	typename data_type::iterator end() { return data.end(); }
	typename data_type::const_iterator begin() const { return data.cbegin(); }
	typename data_type::const_iterator end() const { return data.cend(); }
};

template<size_t rows, size_t columns>
std::ostream& operator<<(std::ostream& out, const Matrix<rows, columns>& matrix)
{
	for (const auto& row : matrix)
	{
		for (const auto elem : row)
			out << elem << " ";
		out << '\n';
	}
	return out;
}

template<size_t rows, size_t columns>
std::istream& operator>>(std::istream& in, Matrix<rows, columns>& matrix)
{
	for (auto& row : matrix)
		for (auto& elem : row)
			in >> elem;
	return in;
}

template<size_t size>
std::array<double, size>& operator-=(std::array<double, size>& dest, const std::array<double, size>& operand)
{
	for (int i = 0; i < size; i++)
		dest[i] -= operand[i];

	return dest;
}

template<size_t size>
std::array<double, size> operator*(std::array<double, size> dest, double operand)
{
	for (auto& elem : dest)
		elem *= operand;

	return dest;
}

template<size_t size>
std::array<double, size> operator*(double operand, std::array<double, size> dest )
{
	for (auto& elem : dest)
		elem *= operand;

	return dest;
}