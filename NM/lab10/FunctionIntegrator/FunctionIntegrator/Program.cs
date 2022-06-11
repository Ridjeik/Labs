using FunctionIntegrator.Lib;

decimal f(decimal x)
{
    double xDouble = Convert.ToDouble(x);
    return Convert.ToDecimal((Math.Cosh(xDouble) + 0.3 * Math.Sin(xDouble)) / (Math.Log10(1 + xDouble)));
}


decimal f2(decimal x)
{
    double xDouble = Convert.ToDouble(x);
    return Convert.ToDecimal(Math.Pow(Math.Tanh(xDouble), 1.0/3));
}

decimal f3(decimal x)
{
    double xDouble = Convert.ToDouble(x);
    return Convert.ToDecimal(Math.Log(1+xDouble)/(1+Math.Cos(xDouble)));
}

decimal f4(decimal x)
{
    double xDouble = Convert.ToDouble(x);
    return Convert.ToDecimal(Math.Pow(1 + Math.Tanh(xDouble), -2.3));
}

decimal a = 0M;
decimal b = Convert.ToDecimal(Math.Log(2));
const decimal eps = 0.0001M;

Console.WriteLine($"Метод лiвих прямокутникiв:    {Integrator.LeftRectangles(f2, a, b, out long intervals1, eps):0.0000}; Iнтервалiв: {intervals1}");
Console.WriteLine($"Метод правих прямокутникiв:   {Integrator.RightRectangles(f2, a, b, out long intervals2, eps):0.0000}; Iнтервалiв: {intervals2}");
Console.WriteLine($"Метод середнiх прямокутникiв: {Integrator.CentralRectangles(f2, a, b, out long intervals3, eps):0.0000}; Iнтервалiв: {intervals3}");
Console.WriteLine($"Метод трапецiй:               {Integrator.Trapezoid(f2, a, b, out long intervals4, eps):0.0000}; Iнтервалiв: {intervals4}");
Console.WriteLine($"Метод парабол(Сiмпсона):      {Integrator.Simpson(f2, a, b, out long intervals5, eps):0.0000}; Iнтервалiв: {intervals5}");
