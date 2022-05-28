using System.Collections;

namespace MatrixLib
{
    public class MatrixRow : IEnumerable<decimal>
    {
        public int Size { get; }

        readonly decimal[] elements;

        public decimal this[int index]
        {
            get => elements[index];
            set => elements[index] = value;
        }

        public MatrixRow(int size)
        {
            if(size <= 0)
                throw new ArgumentOutOfRangeException(nameof(size));

            Size = size;
            elements = new decimal[size];
            Reset();
        }

        public MatrixRow(MatrixColumn column)
        {
            if(column is null)
                throw new ArgumentNullException(nameof(column));

            Size = column.Size;
            elements = new decimal[Size];

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

        public IEnumerator<decimal> GetEnumerator()
        {
            return ((IEnumerable<decimal>)elements).GetEnumerator();
        }

        public static decimal operator *(MatrixRow a, MatrixColumn b)
        {
            if (a.Size != b.Size)
                throw new ArgumentException("Sizes of row and column are not equal.");

            return a.Zip(b, (i, j) => i * j).Sum();
        }
    }
}