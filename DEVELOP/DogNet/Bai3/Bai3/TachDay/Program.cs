using System.Text.RegularExpressions;

namespace TachDay
{
    internal class Program
    {
        public static int[] TachDay(string str)
        {
            string[] arrNumber = str.Trim().Split(" ");
            int[] arr = new int[arrNumber.Length];
            for (int i = 0; i < arrNumber.Length; i++)
            {
                arr[i] = int.Parse(arrNumber[i]);
            }
            return arr;
        }

        public static void TachMang(int[] arr)
        {
            int count = 0;
            foreach (int i in arr)
            {
                if (i % 2 == 0)
                {
                    count++;
                }
            }
            if (count == 0)
            {
                Console.WriteLine("\nTrong mang so nguyen khong co phan tu nao la so chan.");
                Console.WriteLine("\nDay so le trong mang so nguyen la: ");
                foreach (int i in arr)
                {
                    Console.Write(i + "\t");
                }
            }
            else if (count == arr.Length)
            {
                Console.WriteLine("\nDay so chan trong mang so nguyen la: ");
                foreach (int i in arr)
                {
                    Console.Write(i + "\t");
                }
                Console.WriteLine("\nTrong mang so nguyen khong co phan tu nao la so le.");
            }
            else
            {
                Console.WriteLine("\nDay so chan trong mang so nguyen la: ");
                foreach (int i in arr)
                {
                    if (i % 2 == 0)
                    {
                        Console.Write(i + "\t");
                    }
                }
                Console.WriteLine("\nDay so le trong mang so nguyen la: ");
                foreach (int i in arr)
                {
                    if (i % 2 != 0)
                    {
                        Console.Write(i + "\t");
                    }
                }
            }
        }
        static void Main(string[] args)
        {
            string strNumbers;
            Regex rg = new Regex(@"^(-?\d+\s?)+$");
            do
            {
                Console.Write("Nhap vao chuoi so nguyen theo thu tu bat ky: ");
                strNumbers = Console.ReadLine();
            }while (rg.IsMatch(strNumbers) == false || strNumbers == null);
            int[] arr = TachDay(strNumbers);
            Console.WriteLine("\nMang sau khi tach chuoi la: ");
            foreach (int i in arr)
            {
                Console.Write(i + "\t");
            }
            TachMang(arr);
        }
    }
}