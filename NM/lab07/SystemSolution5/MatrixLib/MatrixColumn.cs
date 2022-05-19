using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MatrixLib
{
    public class MatrixColumn : IEnumerable<double>
    {
        public int Size { get; }

        readonly double[] elements;

        public double this[int index]
        {
            get => elements[index];
            set => elements[index] = value;
        }

        public MatrixColumn(int size)
        {
            if (size <= 0)
                throw new ArgumentOutOfRangeException(nameof(size));

            Size = size;
            elements = new double[size];
            Reset();
        }

        public MatrixColumn(MatrixRow row)
        {
            if (row is null)
                throw new ArgumentNullException(nameof(row));

            Size = row.Size;
            elements = new double[Size];

            for (int i = 0; i < Size; i++)
                this[i] = row[i];
        }

        public void Reset()
        {
            for (int i = 0; i < Size; i++)
                elements[i] = 0;
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return elements.GetEnumerator();
        }

        public IEnumerator<double> GetEnumerator()
        {
            return ((IEnumerable<double>)elements).GetEnumerator();
        }

        public static Matrix operator *(MatrixColumn a, MatrixRow b )
        {
            if (a.Size != b.Size)
                throw new ArgumentException("Sizes of row and column are not equal.");

            Matrix result = new(a.Size, b.Size);

            for (int i = 0; i < a.Size; i++)
                for (int j = 0; j < b.Size; j++)
                    result[i, j] = a[i] * b[j];

            return result;
        }
    }
}
