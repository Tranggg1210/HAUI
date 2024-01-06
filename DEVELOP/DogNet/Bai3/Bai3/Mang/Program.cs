namespace Mang
{
    internal class Program
    {
        public static void Sum(int[] arr, int n) {
            long count = 0;
            for(int i = 0; i < n; i++)
            {
                if (arr[i] %2 != 0)
                {
                    count++;
                    break;
                } 
                    
            }
            if (count == 0) Console.WriteLine("Trong mang vua nhap khong co phan tu nao co gia tri le");
            else
            {
                count = 0;
                for(int i = 0;i < n; i++)
                {
                    if (arr[i] % 2 != 0) count += arr[i];
                }
                Console.WriteLine("Tong cac phan tu le trong mang la: {0}",count);
            }
        }
        static void Main(string[] args)
        {
            try
            {
                int n;
                do
                {
                    Console.Write("Nhap n > 0: ");
                    n = int.Parse(Console.ReadLine());
                } while (n < 1);
                int[] arr = new int[n];
                for (int i = 0; i < n; i++)
                {
                    Console.Write("Nhap arr[{0}] = ", i);
                    arr[i] = int.Parse(Console.ReadLine());
                }
                Sum(arr,n); 
            }catch (FormatException e) {
                Console.BackgroundColor = ConsoleColor.Red;
                Console.WriteLine("Sai dinh dang du lieu hoac chua nhap du lieu");
                Console.ResetColor();
            }

        }
    }
}