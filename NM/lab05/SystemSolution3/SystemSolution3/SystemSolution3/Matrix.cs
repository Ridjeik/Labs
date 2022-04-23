using System;
using System.Collections;
using System.Text;

namespace SystemSolution3
{
    internal class Matrix : IEnumerable<double[]>
    {
        private readonly double[][] data;

        public double this[int i, int j]
        {
            get => data[i][j];
            set => data[i][j] = value;
        }

        public double[] this[int index]
        {
            get => data[index];
            set => data[index] = value;
        }

        private int rows;

        public int Rows
        {
            get { return rows; }
            set
            {
                if(value <= 0)
                    throw new ArgumentOutOfRangeException(nameof(value));
                rows = value;
            }
        }

        private int columns;

        public int Columns
        {
            get { return columns; }
            set 
            {
                if(value <= 0)
                    throw new ArgumentOutOfRangeException(nameof(value));
                columns = value;
            }
        }

        public Matrix(int rows, int columns)
        {

            Rows = rows;
            Columns = columns;
            data = new double[rows][];

            for(int i = 0; i < rows; i++)
            {
                data[i] = new double[columns];
            }
        }

        public Matrix(int rows, int columns, string filename)
        {
            if (string.IsNullOrWhiteSpace(filename))
            {
                throw new ArgumentNullException(nameof(filename));
            }

            Rows = rows;
            Columns = columns;
            data = new double[rows][];
            
            using(StreamReader streamReader = new(filename))
            {
                for(int i = 0; i < rows; i++)
                {
                    data[i] = streamReader.ReadLine()?.Split().Take(columns).Select(double.Parse).ToArray() ?? new double[columns];
                }
            }
        }

        public void Deconstruct(out Matrix alpha, out Matrix beta)
        {
            if (Columns != Rows + 1)
                throw new Exception("Not acceptable matrix to decompose!");
            Matrix A = new(Rows, Rows);
            Matrix B = new(Rows, 1);

            for(int i = 0; i < Rows; i++)
            {
                A.data[i] = this.data[i].Take(rows).Select((a, j) => j == i ? 0 : -a / this.data[i][i]).ToArray();
                B[i, 0] = this.data[i].Last() / this.data[i][i];
            }

            alpha = A;
            beta = B;
        }

        public Matrix Transposed()
        {
            Matrix result = new(Columns, Rows);

            for(int i = 0; i < Rows; i++)
            {
                for(int j = 0; j < Columns; j++)
                {
                    result[j, i] = this[i, j];
                }
            }

            return result;
        }

        public bool TestNorms()
        {
            if (Rows != Columns) throw new Exception();

            double firstNorm = this.Select(row => row.Sum(elem => Math.Abs(elem))).Max();
            double secondNorm = this.Transposed().Select(row => row.Sum(elem => Math.Abs(elem))).Max();
            double thirdNorm = Math.Sqrt(this.Sum(row => row.Sum(elem => elem * elem)));

            Console.WriteLine($"Перша норма: {firstNorm:0.000}");
            Console.WriteLine($"Друга норма: {secondNorm:0.000}");
            Console.WriteLine($"Третя норма: {thirdNorm:0.000}");

            if (firstNorm < 1) return true;
            if (secondNorm < 1) return true;
            if (thirdNorm < 1) return true;
            return true;
        }

        public override string ToString()
        {
            StringBuilder result = new StringBuilder();
            foreach(double[] row in this)
            {
                foreach(double elem in row)
                {
                    result.Append(String.Format("{0,8:0.000}", elem));
                }
                result.AppendLine();
            }
            return result.ToString();
        }

        public IEnumerator GetEnumerator()
        {
            return data.GetEnumerator();
        }

        IEnumerator<double[]> IEnumerable<double[]>.GetEnumerator()
        {
            return ((IEnumerable<double[]>)data).GetEnumerator();
        }

        public Matrix Clone()
        {
            Matrix result = new(Rows, Columns);
            for(int i = 0; i < Rows; i++)
            {
                for(int j = 0; j < Columns; j++)
                {
                    result[i, j] = this[i, j];
                }
            }
            return result;
        }

        public static Matrix operator*(Matrix A, Matrix B)
        {
            if (A.Columns != B.Rows)
                throw new ArgumentException();

            Matrix result = new(A.Rows, B.Columns);

            for(int i = 0; i < result.Rows; i++)
            {
                for(int j = 0; j < result.Columns; j++)
                {
                    double sum = 0;
                    for(int k = 0; k < A.Columns; k++)
                    {
                        sum += A[i, k] * B[k, j]; 
                    }
                    result[i, j] = sum;
                }
            }
            return result;
        }

        public static Matrix operator+(Matrix A, Matrix B)
        {
            if (A.Columns != B.Columns || A.Rows != B.Rows)
                throw new ArgumentException();

            Matrix result = new(A.Rows, A.Columns);

            for (int i = 0; i < result.Rows; i++)
            {
                for (int j = 0; j < result.Columns; j++)
                {
                    result[i, j] = A[i, j] + B[i, j];
                }
            }
            return result;
        }

        public double DistanceTo(Matrix other)
        {
            if (!((this.Columns == 1 || this.Rows == 1) && (this.Columns == other.Columns && this.Rows == other.Rows)))
                throw new ArgumentException();

            double sum = 0;
            for(int i = 0; i < Rows; i++)
            {
                for(int j = 0; j < Columns; j++)
                {
                    sum += (this[i, j] - other[i, j]) * (this[i, j] - other[i, j]);
                }
            }
            return Math.Sqrt(sum);
        }
    }
}
