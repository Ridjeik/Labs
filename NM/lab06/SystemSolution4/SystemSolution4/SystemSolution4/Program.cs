using MatrixLib;

Matrix HoletskyMethod(Matrix A, Matrix B)
{
    if(A.Determinant() <= 0)
        throw new ArgumentException(nameof(A));
    Matrix X = new(B.RowsCount, 1), Y = new(B.RowsCount, 1);
    Matrix L = new(A.RowsCount, A.ColumnsCount);

    // Шукаємо матрицю L
    for (int i = 0; i < L.RowsCount; i++)
    {
        for (int j = 0; j < L.ColumnsCount; j++)
        {
            if (i == j)
            {
                double s = 0;
                for (int k = 0; k < i; k++)
                {
                    s += L[i, k] * L[i, k];
                }
                L[i, j] = Math.Sqrt(A[i, j] - s);
            }
            else if (j < i)
            {
                double s = 0;
                for (int k = 0; k < j; k++)
                {
                    s += L[i, k] * L[j, k];
                }
                L[i, j] = (1 / L[j, j]) * (A[i, j] - s);
            }
        }
    }

    Console.WriteLine($"Отримуємо матрицю L: \n{L}");
    Console.WriteLine($"Добуток L * L_T: \n{L * L.Transponed()}");

    // Шукаємо вектор-стовпець Y
    for (int i = 0; i < L.RowsCount; i++)
    {
        double s = 0;
        for (int j = 0; j < i; j++)
        {
            s += L[i, j] * Y[j,0];
        }
        Y[i, 0] = (B[i, 0] - s) / L[i, i];
    }

    // Шукаємо вектор-стовпець X
    for (int i = L.RowsCount - 1; i >= 0; i--)
    {
        double s = 0;
        for (int j = i + 1; j < L.ColumnsCount; j++)
        {
            s += L.Transponed()[i, j] * X[j, 0];
        }
        X[i, 0] = (Y[i, 0] - s) / L.Transponed()[i, i];
    }

    //Повертаємо результат
    return X;
}

//Зчитуємо матрицю з файлу
Matrix systemMatrix = Matrix.FromFile("input.txt");
//Розкладаємо розширену матрицю на матрицю коефіцієнтів і стовпець вільних членів
(Matrix A, Matrix B) = systemMatrix;

//Шукаємо нормальну матрицю системи
Matrix N = A.Transponed() * A;

Console.WriteLine($"Нормальна матриця системи: \n{N}");
//Шукаємо новий стовпець вільних членів
Matrix C = A.Transponed() * B;
Console.WriteLine($"Новий стовпець вiльних членiв: \n{C}");

Matrix X = HoletskyMethod(N, C);
Console.WriteLine($"Вiдповiдь: \n{X}");





