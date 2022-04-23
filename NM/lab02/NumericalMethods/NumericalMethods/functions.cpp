#include <cmath>

double f(double x)
{
    return x*x*x + 3*x*x + 12*x - 3;
}

double df(double x)
{
    return 3*x*x + 6*x + 12;
}

double d2f(double x)
{
    return 6*x + 6;
}

double phi(double x)
{
    return 3/(x*x + 3*x + 12);
}

double findDyhotomea(double start, double end, double precision, int& iterations)
{
    // Визначаємо, чи корені наявні.
    if(f(start)*f(end) >= 0) throw "No roots!";
    else
    {
        iterations = 0;
        // допоки ми не досягнемо потрібної точності, або, що не варто виключати, випадково потрапимо в корінь...
        while(fabs(start-end) > precision && f(end) != 0)
        {
            double midpoint = (end+start)/2; // Вираховуємо середню точку.

            // Визначаємо, з яким кінцем у неї співпадає знак функції і робимо відповідне присвоєння.
            if(f(start)*f(midpoint) > 0) start = midpoint;
            else end = midpoint;

            iterations++;
        }
        // Повертаємо відповідь
        return end;
    }
}

double findHordes(double start, double end, double precision, int& iterations)
{
    // Перевіряємо наявність коренів
    if(f(start)*f(end) >= 0) throw "No roots!";

    // Обираємо рухомий кінець
    else if(f(start)*d2f(start) > 0) // Рухаємо кінець відрізку
    {
        iterations = 0;
        double end_prev = 0;
        // Допоки різниця попереднього і насупного члену не стане меншою за задану...
        do
        {
            // Зберігаємо попереднє значення кінця відрізку
            end_prev = end;

            // Пересуваємо кінець у точку перетину хорди з віссю абсцис
            end -= f(end)*(end-start)/(f(end)-f(start));

            iterations++;
        } while(fabs(end-end_prev) > precision);
        // Повертаємо відповідь.
        return end;
    }
    else // Рухаємо початок відрізку
    {
        iterations = 0;
        double start_prev = 0;
        // Допоки різниця попереднього і насупного члену не стане меншою за задану...
        do
        {
            // Зберігаємо попереднє значення почтаку відрізку
            start_prev = start;

            // Пересуваємо початок у точку перетину хорди з віссю абсцис
            start -= f(start) * (end-start)/(f(end) - f(start));

            iterations++;
        } while (fabs(start-start_prev) > precision);
        // Повертаємо відповідь.
        return start;
    }
}

double findSimpleIteration(double x0, double precision, int &iterations)
{
    double x_prev = 0;
    double x = x0; // За початкове наближення беремо х0.


    do {
        x_prev = x; // Зберігаємо попереднє значення
        x = phi(x); // Використовуємо рекурентну формулу для отримання наступного наближення
        iterations++;
    } while(fabs(x - x_prev) > precision); // Допоки не досягнемо заданої точності..
    return x; // Повертаємо відповідь
}

double findTangents(double start, double end, double precision, int &iterations)
{
    double x_prev = 0;
    double x = f(start)*d2f(start) > 0 ? start : end; // За початкове наближення обираємо той кінець, де знак функції збігається зі знаком її другої похідної


    do {
        x_prev = x; // Зберігаємо попереднє значення
        x = x - f(x)/df(x); // Використовуємо рекурентну формулу для отримання наступного наближення
        iterations++;
    } while(fabs(x - x_prev) > precision); // Допоки не досягнемо заданої точності..
    return x; // Повертаємо відповідь
}
