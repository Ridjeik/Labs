using System.Collections;

namespace MatrixLib
{
    public class MatrixRow : IEnumerable<double>
    {
        public int Size { get; }

        readonly double[] elements;

        public double this[int index]
        {
            get => elements[index];
            set => elements[index] = value;
        }

        public MatrixRow(int size)
        {
            if(size <= 0)
                throw new ArgumentOutOfRangeException(nameof(size));

            Size = size;
            elements = new double[size];
            Reset();
        }

        public MatrixRow(MatrixColumn column)
        {
            if(column is null)
                throw new ArgumentNullException(nameof(column));

            Size = column.Size;
            elements = new double[Size];

            for (int i = 0; i < Size; i++)
                this[i] = column[i];
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

        public static double operator *(MatrixRow a, MatrixColumn b)
        {
            if (a.Size != b.Size)
                throw new ArgumentException("Sizes of row and column are not equal.");

            return a.Zip(b, (i, j) => i * j).Sum();
        }
    }
}