using SystemSolution3;

static Matrix YakobiMethod(Matrix alpha, Matrix beta, out int iterations)
{
    iterations = 0;
    //Початкове наближення - матриця бета
    Matrix X = beta.Clone();
    Matrix X_prev = new Matrix(X.Rows, X.Columns);

    do
    {
        //Зберігаємо попереднє наближення 
        X_prev = X.Clone();
        //Використовуємо рекурентну формулу
        X = alpha * X + beta;
        iterations++;
    } while (X.DistanceTo(X_prev) > 1e-3); // Допоки не досягнемо потрібної точності

    //Повертаємо результат
    return X;
}

static Matrix ZeidelMethod(Matrix alpha, Matrix beta, out int iterations)
{
    iterations = 0;
    //Початкове наближення - матриця бета
    Matrix X = beta.Clone();
    Matrix X_prev = new Matrix(X.Rows, X.Columns);

    do
    {
        //Зберігаємо попереднє наближення 
        X_prev = X.Clone();
        //Обчислюємо Xi
        for (int i = 0; i < X.Rows; i++)
        {
            double sum = 0;
            // використовуючи вже обчислені члени поточного наближення
            for (int k = 0; k < i; k++)
            {
                sum += X[k, 0] * alpha[i, k];
            }
            //і ще не обчислені на даній ітерації члени з попереднього наближення
            for (int j = i+1; j < X.Rows; j++)
            {
                sum += X_prev[j, 0] * alpha[i, j];
            }
            X[i, 0] = sum + beta[i,0];
        }
        iterations++;

    } while (X.DistanceTo(X_prev) > 1e-3); // Допоки не досягнемо потрібної точності

    //Повертаємо результат
    return X;
}

Matrix matrix = new(4, 5, "System.txt");
(Matrix alpha, Matrix beta) = matrix;

Console.WriteLine("Початкова матриця:\n");
Console.WriteLine(matrix);
Console.WriteLine("Альфа:\n");
Console.WriteLine(alpha);
Console.WriteLine("Бета:\n");
Console.WriteLine(beta);

if (alpha.TestNorms())
{
    Console.WriteLine();
    int yakobiIter = 0, zeidelIter = 0;
    Matrix X_Yakobi = YakobiMethod(alpha, beta, out yakobiIter);
    Matrix X_Zeidel = ZeidelMethod(alpha, beta, out zeidelIter);

    Console.WriteLine($"Результат методу Якобi: {X_Yakobi.Transposed()} Iтерацiй: {yakobiIter}");
    Console.WriteLine($"Результат методу Зейделя: {X_Zeidel.Transposed()} Iтерацiй: {zeidelIter}");
}
else
{
    Console.WriteLine("Всi норми матрицi більшi за 1.");
}
