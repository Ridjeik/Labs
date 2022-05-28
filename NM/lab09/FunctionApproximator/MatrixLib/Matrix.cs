using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MatrixLib
{
    public class Matrix : IEnumerable<decimal>
    {
        public int RowsCount { get; }
        public int ColumnsCount { get; }

        private MatrixRow[] Rows { get; init; }
        private MatrixColumn[] Columns { get; init; }

        public decimal this[int i, int j]
        {
            get { return Rows[i][j]; }
            set { Rows[i][j] = value; Columns[j][i] = value; }
        }

        public Matrix(int rowsCount, int columnsCount)
        {
            if(rowsCount <= 0)
                throw new ArgumentOutOfRangeException(nameof(rowsCount));
            if (columnsCount <= 0)
                throw new ArgumentOutOfRangeException(nameof(columnsCount));

            RowsCount = rowsCount;
            ColumnsCount = columnsCount;

            Rows = new MatrixRow[rowsCount];
            Columns = new MatrixColumn[columnsCount];

            for (int i = 0; i < RowsCount; i++)
                Rows[i] = new(columnsCount);

            for (int i = 0; i < ColumnsCount; i++)
                Columns[i] = new(rowsCount);

        }

        public void Reset()
        {
            foreach (MatrixRow row in Rows)
                row.Reset();
            foreach (MatrixColumn column in Columns)
                column.Reset();
        }


        public Matrix Transponed()
        {
            Matrix result = new(ColumnsCount, RowsCount);

            for (int i = 0; i < RowsCount; i++)
                for (int j = 0; j < ColumnsCount; j++)
                    result[j, i] = this[i, j];

            return result;
        }

        public MatrixRow Row(int index)
        {
            if(index < 0 || index >= RowsCount)
                throw new ArgumentOutOfRangeException(nameof(index));

            return Rows[index];
        }

        public MatrixColumn Column(int index)
        {
            if (index < 0 || index >= RowsCount)
                throw new ArgumentOutOfRangeException(nameof(index));

            return Columns[index];
        }

        public override string ToString()
        {
            int fieldWidth = this.Max(i => ((int)i).ToString().Length) + 5;
            if (this.Any(y => y < 0)) fieldWidth++;
   
            StringBuilder builder = new();
            foreach (var row in Rows)
            {
                foreach (var elem in row)
                {
                    builder.Append(string.Format("{0," + $"{fieldWidth}:0.000" + "} ", elem));
                }
                builder.AppendLine();
            }
            return builder.ToString();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            foreach (var row in Rows)
                foreach (var elem in row)
                    yield return elem;
        }

        IEnumerator<decimal> IEnumerable<decimal>.GetEnumerator()
        {
            foreach (var row in Rows)
                foreach (var elem in row)
                    yield return elem;
        }

        public static Matrix operator*(Matrix a, Matrix b)
        {
            if (a.ColumnsCount != b.RowsCount)
                throw new ArgumentException("Cannot multiply matrices of these sizes.");
            Matrix result = new(a.RowsCount, b.ColumnsCount);

            for (int i = 0; i < result.RowsCount; i++)
                for (int j = 0; j < result.ColumnsCount; j++)
                    result[i, j] = a.Row(i) * b.Column(j);

            return result;
        }

        public static Matrix operator*(Matrix a, decimal b)
        {
            Matrix result = new(a.RowsCount, a.ColumnsCount);

            for (int i = 0; i < result.RowsCount; i++)
                for (int j = 0; j < result.ColumnsCount; j++)
                    result[i, j] = a[i, j] * b;

            return result;
        }

        public static Matrix operator*(decimal a, Matrix b)
        {
            Matrix result = new(b.RowsCount, b.ColumnsCount);

            for (int i = 0; i < result.RowsCount; i++)
                for (int j = 0; j < result.ColumnsCount; j++)
                    result[i, j] = b[i, j] * a;

            return result;
        }

        public static Matrix operator+(Matrix a, Matrix b)
        {
            if (a.ColumnsCount != b.ColumnsCount || a.RowsCount != b.RowsCount)
                throw new ArgumentException("Cannot add matrices of different sizes.");

            Matrix result = new(a.RowsCount, b.ColumnsCount);

            for (int i = 0; i < result.RowsCount; i++)
                for (int j = 0; j < result.ColumnsCount; j++)
                    result[i, j] = a[i, j] + b[i, j];

            return result;
        }

        public void Deconstruct(out Matrix A, out Matrix B)
        {
            A = new Matrix(RowsCount, ColumnsCount - 1);
            B = new Matrix(RowsCount, 1);

            for(int i = 0; i < RowsCount; i++)
            {
                for(int j = 0; j < ColumnsCount; j++)
                {
                    if (j == ColumnsCount - 1)
                        B[i, 0] = this[i, j];
                    else A[i, j] = this[i, j];
                }
            }
        }


        public static Matrix FromFile(string filepath)
        {
            var numbersLines = File.ReadAllLines(filepath).Select(line => line.Split().Select(decimal.Parse).ToArray()).ToArray();
            if(numbersLines.Count() == 0)
                throw new ArgumentException("Invalid file content!");
            var firstLineSize = numbersLines.First().Count();

            if (!numbersLines.Skip(1).All(line => line.Count() == firstLineSize))
                throw new ArgumentException("Invalid file content!");

            Matrix result = new(numbersLines.Length, firstLineSize);

            for(int i = 0; i < result.RowsCount; i++)
            {
                for(int j = 0; j < result.ColumnsCount; j++)
                {
                    result[i, j] = numbersLines[i][j];
                }
            }

            return result;
        }

        public Matrix WithoutRow(int rowToSkip)
        {
            Matrix result = new(RowsCount - 1, ColumnsCount);
            for(int i = 0, u = 0; i < RowsCount; i++)
            {
                if (i == rowToSkip)
                    continue;
                for (int j = 0; j < ColumnsCount; j++)
                    result[u, j] = this[i, j];
                u++;
            }
            return result;
        }
        public Matrix WithoutColumn(int columnToSkip)
        {
            Matrix result = new(RowsCount, ColumnsCount-1);
            for (int i = 0; i < RowsCount; i++)
            {
                for (int j = 0, k = 0; j < ColumnsCount; j++)
                {
                    if (j == columnToSkip) continue;
                    result[i, k] = this[i, j];
                    k++;
                }
            }
            return result;
        }

        public decimal Determinant()
        {
            if (ColumnsCount != RowsCount)
                throw new InvalidOperationException("Cannot find determinant for non-square matrices.");
            if (ColumnsCount == 1)
                return this[0, 0];

            decimal result = 0;

            for (int i = 0; i < ColumnsCount; i++)
            {
                result += Convert.ToDecimal(Math.Pow(-1, i)) * this[0, i] * this.WithoutRow(0).WithoutColumn(i).Determinant(); 
            }

            return result;
        }

        public decimal AlgebraicAddition(int i, int j) => Convert.ToDecimal(Math.Pow(-1, i+j)) * this.WithoutRow(i).WithoutColumn(j).Determinant();

        public Matrix Inversed()
        {
            if (RowsCount != ColumnsCount)
                throw new InvalidOperationException();
            Matrix result = new Matrix(RowsCount, ColumnsCount);

            for(int i = 0; i < RowsCount; i++)
            {
                for(int j = 0; j < ColumnsCount; j++)
                {
                    result[i, j] = this.AlgebraicAddition(i, j);
                }
            }

            return (1/this.Determinant()) * (result.Transponed());
        }

        public Matrix Clone()
        {
            Matrix res = new(RowsCount, ColumnsCount);

            for(int i = 0; i < RowsCount; i++)
            {
                for(var j = 0; j < ColumnsCount; j++)
                {
                    res[i, j] = this[i, j];
                }
            }
            return res;
        }
    }

}
