using FunctionApproximatorLib;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace FunctionApproximator.GUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            var textLines = File.ReadAllLines("input.txt");
            if (textLines.Any(line => line.Split(" ", StringSplitOptions.RemoveEmptyEntries).Length != 2)) throw new Exception("Вхідні дані не у правильному форматі.");

            var xyPairs = textLines.Select(line => line.Split().Select(Convert.ToDecimal)).Select(pair => KeyValuePair.Create(pair.ElementAt(0), pair.ElementAt(1)));

            PolynomLib.Polynom polynom1 = Approximator.GetAproximated(xyPairs, 1);
            LinearLabel.Content = (LinearLabel.Content as string) + polynom1.ToStringInversed();
            PolynomLib.Polynom polynom2 = Approximator.GetAproximated(xyPairs, 2);
            QuadraticLabel.Content = (QuadraticLabel.Content as string) + polynom2.ToStringInversed();
            PolynomLib.Polynom polynom3 = Approximator.GetAproximated(xyPairs, 3);
            QubicLabel.Content = (QubicLabel.Content as string) + polynom3.ToStringInversed();


            var x = xyPairs.Select(pair => pair.Key).Select(Convert.ToDouble).ToArray();
            var y = xyPairs.Select(pair => pair.Value).Select(Convert.ToDouble).ToArray();

            double[] x1 = new double[1000], x2 = new double[1000], x3 = new double[1000],
                y1 = new double[1000], y2 = new double[1000], y3 = new double[1000];

            LinearPlot.Plot.AddScatterPoints(x, y, label: "Таблично задана функція", markerSize: 10);
            QuadraticPlot.Plot.AddScatterPoints(x, y, label: "Таблично задана функція", markerSize: 10);
            QubicPlot.Plot.AddScatterPoints(x, y, label: "Таблично задана функція", markerSize: 10);

            int index = 0;
            for (double i = x.Min() - 0.1; i < x.Max() + 0.1; i += (x.Max() - x.Min() + 0.2) / 1000)
            {
                x1[index] = x2[index] = x3[index] = i;
                y1[index] = Convert.ToDouble(polynom1.AtPoint(Convert.ToDecimal(i)));
                y2[index] = Convert.ToDouble(polynom2.AtPoint(Convert.ToDecimal(i)));
                y3[index] = Convert.ToDouble(polynom3.AtPoint(Convert.ToDecimal(i)));
                index++;
            }

            LinearPlot.Plot.AddScatterLines(x1, y1, label: "y = P1(x)");
            QuadraticPlot.Plot.AddScatterLines(x2, y2, label: "y = P2(x)");
            QubicPlot.Plot.AddScatterLines(x3, y3, label: "y = P3(x)");

            foreach(var plot in new[] {LinearPlot, QuadraticPlot, QubicPlot})
            {
                plot.Plot.Palette = ScottPlot.Palette.Category10;
                plot.Refresh();
                plot.Plot.Legend();
                plot.Plot.SetAxisLimitsX(x.Min() - 0.1, x.Max() + 0.1);
                plot.Plot.SetAxisLimitsY(y.Min() - 0.1, y.Max() + 0.1);
                plot.Plot.XLabel("X");
                plot.Plot.YLabel("Y");
            }
        }
    }
}
