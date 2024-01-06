using System;

namespace Bai2
{
    class DanhSach
    {
        static bool Parity(int a)
        {
            if(a%2 == 0) return true;
            else return false;
        }

        static bool IsPrime(int a)
        {
            if (a < 2) return false;
            else
            {
                for(int i = 2; i <= Math.Sqrt(a); i++) {
                    if (a % i == 0) return false;
                }
            }
            return true;
        }
        static void Main(string[] args)
        {
            int n;
            do
            {
                Console.Write("Nhap n > 0: ");
                n = int.Parse(Console.ReadLine());
            } while (n < 1);
            int[] arr = new int[n];
            for(int i = 0; i < n; i++)
            {
                Console.Write("Nhap arr[" + i + "]: ");
                arr[i] = int.Parse(Console.ReadLine());
            }
            Console.WriteLine("\nDanh sach cac so chan trong mang la: ");
            foreach (int i in arr)
                if (Parity(i)) Console.Write(i + "\t");
            Console.WriteLine("\nDanh sach cac so le trong mang la: ");
            foreach (int i in arr)
                if (!Parity(i)) Console.Write(i + "\t");
            Console.WriteLine("\nDanh sach cac so nguyen to trong mang la: ");
            foreach (int i in arr)
                if (IsPrime(i)) Console.Write(i + "\t");
        }
    }
}


