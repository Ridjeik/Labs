
using System.Linq;


namespace FunctionIntegrator.Lib
{
    public static class Integrator
    {
        //Метод лівих прямокутників.
        public static decimal LeftRectangles(Func<decimal, decimal> f, decimal a, decimal b, out long intervals, decimal eps = 0.001M)
        {
            intervals = 2; // Початкова к-ть інтервалів - 2.

            decimal I = 0M, I_prev = 0M, h = 0M;

            do
            {
                h = (b - a) / intervals; // Обчислюємо крок.
                I_prev = I; //Зберігаємо попереднє значення

                List<KeyValuePair<decimal, decimal>> xyPairs = new();

                for (decimal x = a; x < b; x += h)
                    xyPairs.Add(KeyValuePair.Create(x, f(x))); // Додаємо в список нову пару (x, f(x))

                I = xyPairs.Sum(pair => h * pair.Value); // Обчислюємо суму площ прямокутників

                intervals *= 2; // Вдвічі збільшуємо к-ть інтервалів
            } while (Math.Abs(I - I_prev) > eps); // Допоки не досягнемо заданої точності

            return I; // Повертаємо результат
        }
        //Метод правих прямокутників.
        public static decimal RightRectangles(Func<decimal, decimal> f, decimal a, decimal b, out long intervals, decimal eps = 0.001M)
        {
            intervals = 2; // Початкова к-ть інтервалів - 2.

            decimal I = 0M, I_prev = 0M, h = 0M;

            do
            {
                h = (b - a) / intervals;  // Обчислюємо крок.
                I_prev = I; //Зберігаємо попереднє значення

                List<KeyValuePair<decimal, decimal>> xyPairs = new();

                for (decimal x = a + h; x <= b; x += h)
                    xyPairs.Add(KeyValuePair.Create(x, f(x))); // Додаємо в список нову пару (x, f(x))

                I = xyPairs.Sum(pair => h * pair.Value); // Обчислюємо суму площ прямокутників

                intervals *= 2; // Вдвічі збільшуємо к-ть інтервалів
            } while (Math.Abs(I - I_prev) > eps); // Допоки не досягнемо заданої точності

            return I; // Повертаємо результат
        }
        
        public static decimal CentralRectangles(Func<decimal, decimal> f, decimal a, decimal b, out long intervals, decimal eps = 0.001M)
        {
            intervals = 2; // Початкова к-ть інтервалів - 2.

            decimal I = 0M, I_prev = 0M, h = 0M;

            do
            {
                h = (b - a) / intervals; // Обчислюємо крок.
                I_prev = I; //Зберігаємо попереднє значення

                List<KeyValuePair<decimal, decimal>> xyPairs = new();

                for (decimal x = a; x < b; x += h)
                    xyPairs.Add(KeyValuePair.Create(x, f(x + (h/2)))); // Додаємо в список нову пару (x, f(x + h/2))

                I = xyPairs.Sum(pair => h * pair.Value); // Обчислюємо суму площ прямокутників

                intervals *= 2; // Вдвічі збільшуємо к-ть інтервалів
            } while (Math.Abs(I - I_prev) > eps); // Допоки не досягнемо заданої точності

            return I; // Повертаємо результат
        }

        public static decimal Trapezoid(Func<decimal, decimal> f, decimal a, decimal b, out long intervals, decimal eps = 0.001M)
        {
            intervals = 2; // Початкова к-ть інтервалів - 2.

            decimal I = 0M, I_prev = 0M, h = 0M;

            do
            {
                h = (b - a) / intervals; // Обчислюємо крок.
                I_prev = I; //Зберігаємо попереднє значення

                List<KeyValuePair<decimal, decimal>> xyPairs = new();

                for (decimal x = a; x <= b; x += h) 
                    xyPairs.Add(KeyValuePair.Create(x, f(x))); // Додаємо в список нову пару (x, f(x))

                I = xyPairs.Select((pair, i) => (i == 0 || i == xyPairs.Count - 1) ? (pair.Value / 2) : pair.Value).Sum(y => h*y); // Обчислюємо суму площ трапецій

                intervals *= 2; // Вдвічі збільшуємо к-ть інтервалів
            } while (Math.Abs(I - I_prev) > eps); // Допоки не досягнемо заданої точності

            return I; // Повертаємо результат
        }

        public static decimal Simpson(Func<decimal, decimal> f, decimal a, decimal b, out long intervals, decimal eps = 0.001M)
        { 
            intervals = 2; // Початкова к-ть інтервалів - 2.

            decimal I = 0M, I_prev = 0M, h = 0M;

            do
            {
                h = (b - a) / intervals; // Обчислюємо крок.
                I_prev = I; //Зберігаємо попереднє значення

                List<KeyValuePair<decimal, decimal>> xyPairs = new();

                for (decimal x = a; x <= b; x += h)
                    xyPairs.Add(KeyValuePair.Create(x, f(x))); // Додаємо в список нову пару (x, f(x))

                I = xyPairs.Select((pair, i) =>
                    i == 0 || i == xyPairs.Count - 1 ? pair.Value
                        : i % 2 == 0 ? 2 * pair.Value : 4 * pair.Value).Sum(y => (h / 3) * y);

                intervals *= 2; // Вдвічі збільшуємо к-ть інтервалів
            } while (Math.Abs(I - I_prev) > eps); // Допоки не досягнемо заданої точності

            return I; // Повертаємо результат
        }
    }
}