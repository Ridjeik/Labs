#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matrix.h"

template<size_t rows, size_t columns>
std::array<double, rows> gaussSolve(Matrix<rows, columns> A)
{
	std::cout << "Метод Гауса: \n";

	//Приводимо до верхнього трикутного вигляду
	A.toUpperTriangle();
	std::cout << "Отож, звели матрицю до верхнього трикутного вигляду: \n" << A << std::endl;

	std::array<double, rows> x;

	for (int i = rows - 1; i >= 0; i--)
	{
		//Беремо вільний член
		double b = A.data[i][columns - 1];
		
		//Вираховуємо суму добутків вже знайдених коренів на відповідні коефіцієнти системи цього рядку
		double delta = 0;
		for (int j = i+1; j < rows; j++)
		{
			delta += A.data[i][j] * x[j];
		}
		//Знаходимо корінь
		x[i] = (b - delta) / A.data[i][i];
	}
	//Повертаємо результат
	return x;
}

template< size_t rows, size_t columns>
std::array<double, rows> LUSolve(Matrix<rows, columns> A)
{
	std::cout << "Метод LU-розкладу: \n";

	std::array<double, rows> B, Y, X;
	for (int i = 0; i < rows; i++)
		//Виділяємо вектор вільних членів системи
		B[i] = A.data[i][columns - 1];

	Matrix<rows, rows> L, U;

	//Робимо розклад на 2 матриці: L та U
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			L.data[i][j] = U.data[i][j] = 0;
		}
		U.data[i][i] = 1;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (i < j)
			{
				double delta = 0;
				for (int k = 0; k < i; k++)
					delta += L.data[i][k] * U.data[k][j];

				U.data[i][j] = (A.data[i][j] - delta)/L.data[i][i];
			}
			else
			{
				double delta = 0;
				for (int k = 0; k < j; k++)
					delta += L.data[i][k] * U.data[k][j];
				L.data[i][j] = A.data[i][j] - delta;
			}
		}
	}
	std::cout << "Розкладемо початкову матрицю коефiцiєнтiв системи на матрицi L та U:\n";
	std::cout << "L:\n" << L << "\nU:\n" << U << std::endl;

	//Вирішуємо системо LY = B 
	for (int i = 0; i < rows; i++)
	{
		double delta = 0;
		for (int m = 0; m < i; m++)
			delta += L.data[i][m] * Y[m];
		Y[i] = (B[i] - delta) / L.data[i][i];
	}

	//Вирішуємо систему UX = Y
	for (int i = rows - 1; i >= 0; i--)
	{
		double delta = 0;
		for (int m = i+1; m < rows; m++)
			delta += U.data[i][m] * X[m];
		X[i] = Y[i] - delta;
	}

	// Повертаємо результат
	return X;
}

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	std::ifstream fin("input.txt");

	Matrix<3, 4> system;
	fin >> system;
	
	std::cout << std::fixed << std::setprecision(3);
	
	std::array<double, 3> gaussSolution = gaussSolve(system);
	std::cout << "Результат методу Гауса: ";
	for (double x : gaussSolution)
		std::cout << x << " ";
	std::cout << '\n' << std::string(80, '=') << std::endl;

	std::array<double, 3> lu = LUSolve(system);
	std::cout << "Результат методу LU-розкладу: ";
	for (double x : lu)
		std::cout << x << " ";
	std::cout << '\n';
}

