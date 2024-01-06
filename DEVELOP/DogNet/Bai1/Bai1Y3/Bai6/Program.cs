using System;

namespace Bai1Y3
{
    class Bai6
    {
        static void Main(string[] args)
        {
            int a;
            float epsilon;
            do
            {
                Console.Write("Nhap a >= 0: ");
                a = int.Parse(Console.ReadLine());
            } while (a < 0);
            Console.Write("Nhap epsilon: ");
            epsilon = float.Parse(Console.ReadLine());
            double x = 1.0;
            while (true)
            {
                double xn = 0.5 * (x + a / x);
                if (Math.Abs(xn - x) < epsilon)
                {
                    Console.WriteLine("Can bac hai cua {0} là: {1:F2}", a, xn);
                    return;
                }
                x = xn; 
            }
        }
    }

}
