using System;

namespace Bai2
{
    class GiaiThua
    {
        static float Factorial(int n)
        {
            float fac = 1;
            for(int i = 1; i <= n; i++)
            {
                fac *= i;
            }    
            return fac;
        }
        static float RecursiveFactorial(int n)
        {
            if (n == 0 || n == 1) return 1;
            return RecursiveFactorial(n - 1) * n;
        }
        static void Main(string[] args)
        {
            int n;
            do
            {
                Console.Write("Nhap n > 0: ");
                n = int.Parse(Console.ReadLine());
            } while (n < 1);
            Console.WriteLine("Giai thua cua {0} la: {1}",5, Factorial(n));
            Console.WriteLine("Giai thua cua {0} duoc tinh bang ham de quy la: {1}", 5, Factorial(n));

        }
    }
}