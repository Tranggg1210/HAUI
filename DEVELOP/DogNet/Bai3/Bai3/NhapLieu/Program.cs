namespace NhapLieu
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int a;
            Console.Write("Nhap 1 <= n <= 100: ");
            a = int.Parse(Console.ReadLine());
            while (a < 1 || a > 100)
            {
                Console.Write("Nhap 1 <= n <= 100: ");
                a = int.Parse(Console.ReadLine());
            }   
            Console.WriteLine("Gia tri cua bien a vua nhap voi while la: {0}",a);
            // do-while
            int n;
            do
            {
                Console.Write("Nhap 1 <= n <= 100: ");
                n = int.Parse(Console.ReadLine());
            } while (n < 1 || n > 100);
            Console.WriteLine("Gia tri cua bien n vua nhap voi do-while la: {0}", n);
        }
    }
}