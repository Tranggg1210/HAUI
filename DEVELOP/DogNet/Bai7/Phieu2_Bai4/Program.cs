namespace Phieu2_Bai4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string hoTen;
            double thue;
            Console.Write("\nNhap ho ten nguoi lao dong: ");
            hoTen = Console.ReadLine();
            Console.Write("\nNhap thu nhap: ");
            thue = double.Parse(Console.ReadLine());
            Action<string, double> bai4 = tinhThue;
            bai4(hoTen, thue);
        }
        private static void tinhThue(string hoTen, double thue)
        {
            if(thue <= 5000000)
                Console.WriteLine("\nSo thue ma " + hoTen + " phai nop la: " + (thue*0.05));
            else if(thue > 5000000 && thue <= 10000000)
                Console.WriteLine("\nSo thue ma " + hoTen + " phai nop la: " + (thue * 0.1 - 250000));
            else
                Console.WriteLine("\nSo thue ma " + hoTen + " phai nop la: " + (thue * 0.2 - 750000));
        }
    }
}