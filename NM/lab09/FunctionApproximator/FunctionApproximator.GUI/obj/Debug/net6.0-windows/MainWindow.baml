   M S B A M L   `   `   `  ����S  OFunctionApproximator.GUI, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullC&clr-namespace:FunctionApproximator.GUIFunctionApproximator.GUI  5   	   )    #FunctionApproximator.GUI.MainWindow   5   	   W SPresentationCore, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35U QScottPlot.WPF, Version=4.1.45.0, Culture=neutral, PublicKeyToken=e53b06131e34a3aae aSystem.Windows.Controls.Ribbon, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      5   	   R NSystem.Xaml, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   8local&clr-namespace:FunctionApproximator.GUI     5   	     � Title$  Апроксиматор��5   	   $	��420��6   $
��1395��6+   .��5	      �  � RowDefinitions 5
   
   �� 5      $��* �6   �� 5      $
��Auto �6    � ColumnDefinitions 5   
   �� 5      �� 5      �� 5      .+�5   
     ScottPlot.WpfPlot  -   5        $��
LinearPlot��5        5   
   -   5        $��QuadraticPlot��5      $��1��6'     5   
   -   5        $��	QubicPlot��5      $��2��6#   �� 5   
   -   5         ��Name$ LinearLabel��5      $��1��6%   $��20(�62   $O��IЛінійний апроксимаційний поліном:
 P1(x) =��6@   �� 5   
   -   5        $ QuadraticLabel��5      $��1��6(   $��1��65   $��20(�6E   $W��QКвадратичний апроксимаційний поліном: 
P2(x) =��6S   �� 5   
   -   5        $ 
QubicLabel��5      $��1��6$   $��2��61   $��20(�6A   $N��HКубічний апроксимаційний поліном:
P3(x) =��6O   5      5      