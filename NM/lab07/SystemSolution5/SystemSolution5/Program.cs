using MatrixLib;

Console.Write("Початкове наближення: ");
var numbers = Console.ReadLine().Split().Select(double.Parse).Take(2).ToArray();

var x0 = numbers[0];
var y0 = numbers[1];

var solution = SimpleIteration(x0, y0, out int iters);
Console.WriteLine($"Метод iтерацiї: {solution.Item1:0.000}, {solution.Item2:0.000}; Iтерацiй: {iters}");
var solution2 = NewtonMethod(x0, y0, out int iters2);
Console.WriteLine($"Метод Ньютона: {solution2.Item1:0.000}, {solution2.Item2:0.000}; Iтерацiй: {iters2}");

(double, double) SimpleIteration(double x0, double y0, out int iterations)
{
    double x = x0, y = y0;
    iterations = 0;
    do
    {
        //Зберігаємо попередні значення
        x0 = x;
        y0 = y;
        //Використовуємо ітераційні формули
        x = Math.Sin(y0) / 2 - 0.8;
        y = 0.8 - Math.Cos(x0 + 0.5);
        iterations++;
    } while (Math.Max(Math.Abs(y - y0),Math.Abs(x - x0)) > 0.001); // Допоки не досягнемо заданої точності.

    return (x, y);
}

//Обчислення матриці Якобі
Matrix J(Matrix X)
{
    Matrix res = new(2, 2);
    res[0, 0] = -Math.Sin(X[0, 0] + 0.5);
    res[0, 1] = 1;
    res[1, 0] = -2;
    res[1, 1] = Math.Cos(X[1, 0]);

    return res;
}

//Обчислення значень функції
Matrix F(Matrix X)
{
    Matrix res = new(2, 1);
    res[0, 0] = Math.Cos(X[0, 0] + 0.5) + X[1, 0] - 0.8;
    res[1, 0] = Math.Sin(X[1, 0]) - 2 * X[0, 0] - 1.6;
    return res;
}

(double, double) NewtonMethod(double x0, double y0, out int iterations)
{
    Matrix X = new(2, 1), X_prev;
    X[0,0] = x0;
    X[1, 0] = y0;

    iterations = 0;
    do
    {
        //Зберігаємо попередні значення
        X_prev = X.Clone();
        //Використовуємо ітераційну формулу
        X = X_prev + (-1) * J(X_prev).Inversed() * F(X_prev);
        iterations++;
    } while (Math.Max(Math.Abs(X_prev[0, 0] - X[0, 0]), Math.Abs(X_prev[1, 0] - X[1, 0])) > 0.001); // Допоки не досягнемо заданої точності.

    return (X[0,0], X[1,0]);
}