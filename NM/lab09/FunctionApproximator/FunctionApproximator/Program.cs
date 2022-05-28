using FunctionApproximatorLib;

var textLines = File.ReadAllLines("input.txt");
if (textLines.Any(line => line.Split(" ", StringSplitOptions.RemoveEmptyEntries).Length != 2)) throw new Exception("Вхідні дані не у правильному форматі.");

var xyPairs = textLines.Select(line => line.Split().Select(Convert.ToDecimal)).Select(pair => KeyValuePair.Create(pair.ElementAt(0), pair.ElementAt(1)));

Console.WriteLine($"Лiнiйний полiном: {Approximator.GetAproximated(xyPairs, 1).ToStringInversed()}\n");
Console.WriteLine($"Квадратичний полiном: {Approximator.GetAproximated(xyPairs, 2).ToStringInversed()}\n");
Console.WriteLine($"Кубiчний полiном: {Approximator.GetAproximated(xyPairs, 3).ToStringInversed()}\n");
