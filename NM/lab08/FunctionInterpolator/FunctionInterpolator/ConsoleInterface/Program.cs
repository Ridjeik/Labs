using PolynomLib;

/*var my_data = new KeyValuePair<decimal, decimal>[]
{
    KeyValuePair.Create(0.115M, 8.68M),
    KeyValuePair.Create(0.120M, 8.29M),
    KeyValuePair.Create(0.125M, 7.96M),
    KeyValuePair.Create(0.130M, 7.65M),
    KeyValuePair.Create(0.135M, 7.36M),
    KeyValuePair.Create(0.140M, 7.10M),
    KeyValuePair.Create(0.145M, 6.85M),
    KeyValuePair.Create(0.150M, 6.62M),
    KeyValuePair.Create(0.165M, 6.40M),
    KeyValuePair.Create(0.170M, 6.20M)
};*/

var my_data = File.ReadAllLines("alina.txt")
    .Select(line => line.Split().Select(Convert.ToDecimal))
    .Select(arr => KeyValuePair.Create(arr.ElementAt(0), arr.ElementAt(1)))
    .ToArray();


Polynom a = Polynom.GetLangrange(my_data);
Console.WriteLine("Полiном Лагранжа: ");
Console.WriteLine(a);

Polynom b = Polynom.GetNewton(my_data);
Console.WriteLine("Полiном Ньютона: ");
Console.WriteLine(b);


Console.WriteLine("Перевiримо, чи значення полiномiв в ключових точках спiвпадають з таблицею: \n");
foreach (var x in my_data.Select(pair => pair.Key))
{
    Console.WriteLine($"{x:0.000} => Лагранж: {a.AtPoint(x):0.000} ; Ньютон: {b.AtPoint(x):0.000}");
}


Console.WriteLine("\n\nЗначення полiномiв в точцi x0 \n");
var x0 = 3.522M;

Console.WriteLine($"{x0:0.000} => Лагранж: {a.AtPoint(x0):0.000} ; Ньютон: {b.AtPoint(x0):0.000}");