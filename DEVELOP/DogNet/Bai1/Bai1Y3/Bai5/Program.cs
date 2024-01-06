using System;

namespace Bai1Y3
{
    class Bai5
    {
        static void Main(string[] args)
        {
            int n, s1 = 0;
            float s2=0;
            do
            {
                Console.Write("Nhap n > 0: ");
                n = int.Parse(Console.ReadLine());
            } while (n < 1);
            for(int i = 1; i <= n; i++)
            {
                s1 += i;
            }
            for(int i = 1;i <= n; i++)
            {
                s2 += ((float)1 / i);
            }
            Console.WriteLine("Cau a, S = " + s1);
            Console.WriteLine("Cau b, S = " + s2);
        }
    }

}
