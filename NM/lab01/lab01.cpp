#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>

double f(double x)
{
    return x*x*x + 3*x*x + 12*x - 3;
}
double d2f(double x)
{
    return 6*x+6;
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

int main()
{
    
    double a,b,eps;
    int iterationsOfDyhotomea = 0, iterationsOfHordes = 0;
    std::cout << std::setprecision(20);
    std::cout << "Enter start value: ";
    std::cin >> a;
    std::cout << "Enter end value: ";
    std::cin >> b;
    std::cout << "Enter precision value: ";
    std::cin >> eps;
    std::cout << "=================================================================" << std::endl << std::endl;

    std::cout << std::setw(15) << "Dyhotomea: " << findDyhotomea(a, b, eps, iterationsOfDyhotomea);
    std::cout << "\t\tIterations: " << iterationsOfDyhotomea << std::endl;
    std::cout << std::setw(15) << "Hordes: " << findHordes(a, b, eps, iterationsOfHordes);
    std::cout << "\t\tIterations: " << iterationsOfHordes << std::endl;
    
    std::cin.ignore(32767, '\n');
    std::cin.get();
}