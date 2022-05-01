double f(double x, double y, double z) => 23*x*x - 16*x*y - 6*x*z - 22*x + 12*y*y + 2*y*z - 40*y + 58*z*z - 16*z + 173;
double dfdx(double x, double y, double z) => 46 * x - 16 * y - 6 * z - 22;
double dfdy(double x, double y, double z) => -16*x + 24*y + 2*z - 40;
double dfdz(double x, double y, double z) => -6 * x + 2 * y + 116 * z - 16;
Vector grad(double x, double y, double z) => new Vector(
            dfdx(x, y, z),
            dfdy(x, y, z),
            dfdz(x, y, z)
        );

const double step = 0.01;
Point A = new(0, 0, 0), A_prev;
do
{
    A_prev = (A.Clone() as Point)!;
    double x = A.X;
    double y = A.Y;
    double z = A.Z;

    A = A_prev.MovedBy(-grad(x,y,z) * step);
    Console.WriteLine(A);
} while (A.DistanceTo(A_prev) > 1e-4);

class Point : ICloneable
{
    public double X { get; set; }
    public double Y { get; set; }
    public double Z { get; set; }

    public Point(double x, double y, double z)
    {
        X = x;
        Y = y;
        Z = z;
    }

    public override string ToString()
    {
        return $"({X:0.0000}, {Y:0.0000}, {Z:0.0000})";
    }

    public Point MovedBy(Vector vector)
    {
        Point result = new(X, Y, Z);
        result.X += vector.X;
        result.Y += vector.Y;
        result.Z += vector.Z;
        return result;
    }

    public object Clone()
    {
        return MemberwiseClone();
    }

    public double DistanceTo(Point other)
    {
        return Math.Sqrt(
                Math.Pow(this.X - other.X, 2) +
                Math.Pow(this.Y - other.Y, 2) +
                Math.Pow(this.Z - other.Z, 2));
    }
}
public class Vector
{
    public double X { get; set; }
    public double Y { get; set; }
    public double Z { get; set; }

    public Vector(double x, double y, double z)
    {
        X = x;
        Y = y;
        Z = z;
    }

    public static Vector operator-(Vector a)
    {
        return new Vector(-a.X, -a.Y, -a.Z);
    }

    public static Vector operator*(double a, Vector b)
    {
        return new Vector(a * b.X, a * b.Y, a * b.Z);
    }

    public static Vector operator *(Vector a, double b)
    {
        return new Vector(b * a.X, b * a.Y, b * a.Z);
    }
}