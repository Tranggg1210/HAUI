using System;


namespace Bai1
{
    class Class1
    {
        static void Main(string[] args)
        {
            /*
             * Viết chương trình nhập vào 2 số nguyên m và n tương ứng với phân số
               m/n. In ra màn hình phân số rút gọn của m/n.
             */
            int m, n;
            Console.Write("Nhap m: ");
            m = int.Parse(Console.ReadLine());
            Console.Write("Nhap n: ");
            n = int.Parse(Console.ReadLine());
            if (n == 0) Console.WriteLine("Loi! Tu so chia 0");
            else
            {
                int k, a = m, b = n;
                while (a * b != 0)
                {
                    if (a > b)
                    {
                        a %= b; // a = a % b
                    }
                    else
                    {
                        b %= a;
                    }
                }
                k = a + b;
                Console.WriteLine("Phan so {0}/{1} sau khi rut gon la: {2}/{3}", m, n, (m / k), (n / k));
            }
        }
    }
}

