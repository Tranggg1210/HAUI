using System;

namespace Bai2
{
    class Mang
    {

        static int FindMin(int[] nums)
        {
            int min = nums[0];
            foreach (int item in nums)
            {
                 if(min > item) min = item;               
            }
            return min;
        }
        static int FindMax(int[] nums)
        {
            int max = nums[0];
            foreach (int item in nums)
            {
                if (max < item) max = item;
            }
            return max;
        }
        static int Sum(int[] nums)
        {
            int sum = 0;
            foreach (int x in nums)
            {
                sum += x;
            }
            return sum;
        }
        static void Main(string[] args)
        {
            int n;
            int[] arr;
            do
            {
                Console.Write("Nhap n > 0: ");
                n = int.Parse(Console.ReadLine());
            } while (n < 1);
            arr = new int[n];
            for(int i = 0; i < n; i++)
            {
                Console.Write("Nhap a[{0}]: ", i);
                arr[i] = int.Parse(Console.ReadLine());
            }
            Console.WriteLine("So lon nhat trong mang la: " + FindMax(arr));
            Console.WriteLine("So nho nhat trong mang la: " + FindMin(arr));
            Console.WriteLine("Tong cac so trong mang la: " + Sum(arr));
        }
    }
}
