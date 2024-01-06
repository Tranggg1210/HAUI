using System;

namespace Bai2
{
    class HinhChuNhat
    {
        static double Perimeter(float d, float r)
        {
            return ((d + r) * 2);
        }
        static double Area(float d, float r)
        {
            return (d * r);
        }
        static void Main(string[] args)
        {
            float d, r;
            do
            {
                Console.Write("Nhap chieu dai cua hinh chu nhat: ");
                d = float.Parse(Console.ReadLine());
            } while (d < 1);
            do
            {
                Console.Write("Nhap chieu rong cua hinh chu nhat: ");
                r = float.Parse(Console.ReadLine());
            } while (r < 1);

            Console.WriteLine("Chu vi và Dien tich hinh chu nhat la: {0:F2} va {1:F2}", Perimeter(d,r), Area(d,r));
        }
    }
}