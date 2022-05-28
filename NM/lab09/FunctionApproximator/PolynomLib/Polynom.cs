using System.Text;

namespace PolynomLib
{
    public class Polynom
    {
        private decimal[] Coefs { get; }

        public Polynom()
        {
            Coefs = new decimal[1];
        }

        public Polynom(int size)
        {
            Coefs = new decimal[size];
        }

        public Polynom(decimal[] coefs)
        {
            this.Coefs = coefs;
        }

        public override string ToString()
        {
            StringBuilder builder = new StringBuilder();
            builder.AppendLine();
            for(int i = Coefs.Length - 1; i >= 0; i--)
            {
                if (i == 0) builder.Append((Coefs[i] >= 0 ? "+" : "") + Coefs[i].ToString("0.00"));
                else if (i == 1) builder.Append((Coefs[i] >= 0 ? "+" : "") + Coefs[i].ToString("0.00") + "x");
                else if (i == Coefs.Length - 1) builder.Append(Coefs[i].ToString("0.00") + "x^" + i.ToString());
                else builder.Append((Coefs[i] >= 0 ? "+" : "") + Coefs[i].ToString("0.00") + "x^" + i.ToString());
            }

            return builder.ToString();
        }

        public string ToStringInversed()
        {
            StringBuilder builder = new StringBuilder();
            for(int i = 0; i < Coefs.Length; i++)
            {
                if (i == 0) builder.Append(Coefs[i].ToString("0.00"));
                else if (i == 1) builder.Append((Coefs[i] >= 0 ? "+" : "") + Coefs[i].ToString("0.00") + "x");
                else if (i == Coefs.Length - 1) builder.Append((Coefs[i] >= 0 ? "+" : "") + Coefs[i].ToString("0.00") + "x^" + i.ToString());
                else builder.Append((Coefs[i] >= 0 ? "+" : "") + Coefs[i].ToString("0.00") + "x^" + i.ToString());
            }

            return builder.ToString();
        }

        public static Polynom operator+(Polynom a, Polynom b)
        {
            Polynom result = new Polynom(Math.Max(a.Coefs.Length, b.Coefs.Length));
            for(int i = 0; i < Math.Max(a.Coefs.Length, b.Coefs.Length); i++)
            {
                result.Coefs[i] = a.Coefs.ElementAtOrDefault(i) + b.Coefs.ElementAtOrDefault(i);
            }
            return result;
        }

        public static Polynom operator*(Polynom a, Polynom b)
        {
            Polynom result = new Polynom(a.Coefs.Length + b.Coefs.Length - 1);

            for(int i = 0; i < a.Coefs.Length; i++)
            {
                for(int j = 0; j < b.Coefs.Length; j++)
                {
                    result.Coefs[i + j] += a.Coefs[i] * b.Coefs[j];
                }
            }

            return result;
        }

        public static implicit operator Polynom(decimal num)
        {
            Polynom res = new Polynom(1);
            res.Coefs[0] = num;
            return res;
        }


        public static Polynom GetLangrange(KeyValuePair<decimal, decimal>[] xypairs)
        {
            Polynom res = new Polynom(xypairs.Length);

            for(int i = 0; i < xypairs.Length; i++)
            {

                Polynom L_i = 1; //Поліном-доданок
                for(int j = 0; j < xypairs.Length; j++)
                {
                    if (i == j) continue; // Пропускаємо, якщо номер доданку дорівнює номеру точки
                    Polynom numerator = new Polynom(new decimal[] { -xypairs[j].Key, 1 });
                    decimal denominator = (xypairs[i].Key - xypairs[j].Key);
                    L_i *= numerator * (1M / denominator); 
                }
                res += L_i * xypairs[i].Value;
            }
            //Повертаємо результат
            return res;
        }

        public static Polynom GetNewton(KeyValuePair<decimal, decimal>[] xypairs)
        {
            //Масив-таблиця для зберігання розділених різниць
            decimal[,] diff = new decimal[xypairs.Length, xypairs.Length + 1];

            for(int i = 0; i < xypairs.Length+1; i++)
            {
                for(int j = 0; j < xypairs.Length - i; j++)
                {
                    if (i == 0) diff[j, i] = xypairs[j].Value;
                    else
                    {
                        //Для обчислення різниці i-го порядку використовуємо різницю (i-1)-го порядку
                        decimal num = (diff[j + 1, i - 1] - diff[j, i - 1]);
                        decimal denom = (xypairs[j + i].Key - xypairs[j].Key);
                        diff[j, i] = num / denom;
                    }
                }
            }

            Polynom result = new Polynom();


            for(int i = 0; i < xypairs.Length; i++)
            {
                Polynom P_i = diff[0, i]; //Поліном-доданок
                for (int j = 0; j < i; j++)
                    P_i *= new Polynom(new decimal[] { -xypairs[j].Key, 1 });
                result += P_i;
            }
            //Повертаємо результат
            return result;
        }

        public decimal AtPoint(decimal x)
        {
            decimal result = 0;
            for(int i = 0; i < Coefs.Length; i++)
            {
                result += Coefs[i] * Convert.ToDecimal(Math.Pow(Convert.ToDouble(x), i));
            }
            return result;
        }
    }
}