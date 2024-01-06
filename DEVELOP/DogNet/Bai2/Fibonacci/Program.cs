using System;

namespace Bai2
{
    class Fibonacci
    {
        static void FindFibonacci(int n)
        {
            int[] ArrFibonacci = new int[n];
            ArrFibonacci[0] = 0;
            ArrFibonacci[1] = 1;
            for(int i = 2; i < n; i++)
            {
                ArrFibonacci[i] = ArrFibonacci[i - 1] + ArrFibonacci[i - 2];
            }
            foreach(int i in  ArrFibonacci)
            {
                Console.Write(i + "   ");
            }    
        }

        static int RecursiveFabinacci(int n)
        {
            if(n == 0) return 0;
            else if(n == 1) return 1;
            return RecursiveFabinacci(n - 1) + RecursiveFabinacci(n - 2);
        }
        static void Main(string[] args)
        {
            int n;
            do
            {
                Console.Write("Nhap n > 0: ");
                n = int.Parse(Console.ReadLine());  
            }while (n < 1);
            Console.WriteLine("Day so Fibonacci tuong ung voi {0} la: ", n);
            FindFibonacci(n);
            Console.WriteLine("\nDay so Fibonacci duoc tim bang ham de quy tuong ung voi {0} la: ", n);
            int[] arrFabonacci =  new int[n];
            for(int i = 0; i < n; i++)
            {
                arrFabonacci[i] = RecursiveFabinacci(i);
            } 
            foreach (int i in arrFabonacci) { Console.Write(i + "   "); }
        }
    }
}