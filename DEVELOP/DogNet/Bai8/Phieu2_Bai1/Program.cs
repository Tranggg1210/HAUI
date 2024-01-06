
namespace Phieu2_Bai1
{
    internal class Program
    {
        private delegate double tinhTheoYCDB(float a, float b, char c);
        static void Main(string[] args)
        {
            int choose;
            tinhTheoYCDB kq = tinh;
            do
            {
                float a, b;
                Console.Write("\nNhap so a: ");
                a = float.Parse(Console.ReadLine());
                Console.Write("\nNhap so b: ");
                b = float.Parse(Console.ReadLine());
                Console.WriteLine("=========================================");
                Console.WriteLine("1. Tinh tong");
                Console.WriteLine("2. Tinh hieu");
                Console.WriteLine("3. Tinh tich");
                Console.WriteLine("4. Tinh thuong");
                Console.WriteLine("5. Thoat");
                do
                {
                    Console.Write("Nhap lua chon cua ban: ");
                    choose = int.Parse(Console.ReadLine());
                } while (choose <= 0 || choose > 5);
                switch (choose)
                {
                    case 1:
                        Console.WriteLine("\nTong hai so la: "+ kq(a,b,'+')); break;
                    case 2:
                        Console.WriteLine("\nTong hai so la: " + kq(a, b, '-')); break;
                    case 3:
                        Console.WriteLine("\nTong hai so la: " + kq(a, b, '*')); break;
                    case 4:
                        Console.WriteLine("\nTong hai so la: " + kq(a, b, '/')); break;
                }
            } while (choose != 5);
        }
        private static double tinh(float a, float b, char c)
        {
            switch (c)
            {
                case '+': return a + b;
                case '-': return a - b;
                case '*': return a * b;
                case '/': return a / b;
                default: { Console.WriteLine("==> Lua chon ban nhap, khòn co trong danh sach"); return 0; };
            }    
        }
    }
}