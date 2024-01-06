using System;

namespace PhuongThuc
{
    class Program
    {
        public static bool IsPrime(int n)
        {
            if (n < 2) return false;
            else
            {
                for(int i = 2; i <= Math.Sqrt(n); i++)
                {
                    if(n%i == 0) return false;
                }
            } 
                
            return true;
        }
        public static void Main(string[] args)
        {
            int n;
            do
            {
                Console.Write("Nhap vao so luong phan tu cua mang n > 0: ");
                n = int.Parse(Console.ReadLine());
            } while (n < 1);
            int[] arr = new int[n];
            for(int i = 0; i < n; i++)
            {
                Console.Write("Nhap arr[{0}]: ", i);
                arr[i] = int.Parse(Console.ReadLine());
            }   
            for(int i = 0; i < n; i++)
            {
                if (IsPrime(arr[i]))
                    Console.WriteLine("Phan tu thu {0} cua mang co gia tri {1} la so nguyen to", i, arr[i]);
                else
                    Console.WriteLine("Phan tu thu {0} cua mang co gia tri {1} la KHONG PHAI so nguyen to", i, arr[i]);
            }    
        }
    }

}
