#include <iostream>
#include "SquareMatrix.h"
#include <fstream>
#include <iomanip>

std::vector<double> matrixMethod(const SquareMatrix& A, const std::vector<double>& B)
{
    if (A.matrixSize() != B.size()) throw std::string("Sizes not equal!"); // Перевіряємо на можливість перемножити матрицю і вектор-стовпець
    if(det(A) == 0) throw std::string("Solution can't be found!"); // Перевіряємо на рівність нулю детермінант

    std::vector<double> X(B.size()); // Створюємо вектор для запису відповідей

    SquareMatrix A_inv = A.inversed(); // Знаходимо оберену матрицю.

    std::cout << "Inversed matrix:\n" << A_inv << std::endl;
    X = A_inv * B; // Знаходимо його, як добуток оберненої матриці на вектор-стовпець вільних членів
    return X; // Повертаємо відповідь
}

std::vector<double> kramerMethod(const SquareMatrix& A, const std::vector<double>& B)
{
    if (A.matrixSize() != B.size()) throw std::string("Sizes not equal!"); // Перевіряємо на можливість перемножити матрицю і вектор-стовпець

    double d = det(A); // Знаходимо детермінант початкової матриці
    if (d == 0) throw std::string("Solution can't be found!"); // Перевіряємо на рівність нулю детермінант
    
    std::vector<double> X(B.size()); // Створюємо вектор для запису відповідей

    std::cout << "det(A) = " << d << std::endl;

    for (int i = 0; i < A.matrixSize(); i++)
    {
        double detAi = det(A.withReplacedColumn(i, B)); // Створюємо матрицю Аі з заміненим стовпцем
        X[i] = detAi / d; // Знаходимо і-й корінь як частку детермінанта матриці Аі з заміненим стовпцем на детермінант почтаткової матриці
        std::cout << "det(A" << i + 1 << ") = " << detAi << "; X" << i + 1 << " = " << detAi << "/" << d << " = " << X[i] << std::endl;
    }

    return X; // Повертаємо відповідь
}

int main()
{
    int size;
    std::fstream in("input.txt");

    in >> size;

    SquareMatrix A(size);
    std::vector<double> B(size);

    in >> A >> B;
    std::cout << "A:\n" << A << '\n' << "B:\n" << B << '\n' << std::endl;

    try {
        std::cout << std::setprecision(10);
        std::cout << std::string(60, '=') << std::endl;
        std::cout << "Matrix: " << matrixMethod(A, B) << std::endl;
        std::cout << std::string(60, '=') << std::endl;
        std::cout << "\nKramer: " << kramerMethod(A, B) << std::endl;
    }
    catch (std::string& exception)
    {
        std::cout << "Error: " << exception << std::endl;
    }
}
