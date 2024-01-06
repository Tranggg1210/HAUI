using System;

namespace Bai1Y3
{
    class Bai3
    {
        static void Main(string[] args)
        {
            float a, b, c;
            do
            {
                Console.Write("Nhap canh a cua tam giac: ");
                a = float.Parse(Console.ReadLine());
                Console.Write("Nhap canh b cua tam giac: ");
                b = float.Parse(Console.ReadLine());
                Console.Write("Nhap canh c cua tam giac: ");
                c = float.Parse(Console.ReadLine());
            } while (a < 1 || b < 1 || c < 1 || (a+b) <= c || (a+c) <= b || (b+c) <= a);
            float p = (a + b + c) / 2;
            double s = Math.Sqrt(p*(p-a)*(p-b)*(p-c));
            Console.WriteLine("Dien tich tam giac la: {0:F2}", s);
        }
    }
}
