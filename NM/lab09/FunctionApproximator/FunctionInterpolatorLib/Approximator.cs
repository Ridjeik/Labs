using MatrixLib;
using PolynomLib;

namespace FunctionApproximatorLib
{
    public static class Approximator
    {
        //Метод для розв'язання СЛАР методом оберненої матриці
        private static Matrix SolveInversedMatrix(Matrix A, Matrix B) => A.Inversed() * B;

        //Метод для пошуку апроксимаційного поліному фіксованого степеня
        public static Polynom GetAproximated(IEnumerable<KeyValuePair<decimal, decimal>> xypairs, int polynomPower)
        {
            //Масив сум x-ів певного степеня
            decimal[] powerSums = new decimal[polynomPower * 2 + 1];
            for (int i = 0; i < polynomPower * 2 + 1; i++)
            {
                //Шукаємо ці суми
                powerSums[i] = xypairs.Select(pair => pair.Key).Sum(x => Convert.ToDecimal(Math.Pow(Convert.ToDouble(x), i)));
            }

            Matrix A = new(polynomPower + 1, polynomPower + 1), B = new(polynomPower + 1, 1);
            for (int i = 0; i < polynomPower + 1; i++)
            {
                for (int j = 0; j < polynomPower + 1; j++)
                {
                    //a_ij = sum (x_i^(i+j))
                    A[i, j] = powerSums[i + j];
                }
                //b_i = sum(y_i * x_i^m)
                B[i, 0] = xypairs.Select(pair => pair.Value * Convert.ToDecimal(Math.Pow(Convert.ToDouble(pair.Key), i))).Sum();
            }

            return new Polynom(SolveInversedMatrix(A, B).ToArray());
        }
    }
}