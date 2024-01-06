namespace Phieu2_Bai5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Func<double, double> tinhTienHoaHong = delegate(double soTienBH)
            {
                double pthh = 0;
                if (soTienBH < 1000) pthh = 0;
                else if (soTienBH >= 1000 && soTienBH < 3000) pthh = 0.05;
                else pthh = 0.1;
                return soTienBH * pthh;
            };
            string hoTen;
            double tienBan;
            Console.Write("\nNhap ten nhan vien: ");
            hoTen = Console.ReadLine();
            do
            {
                Console.Write("\nNhap so tien ban: ");
                tienBan = double.Parse(Console.ReadLine());
            } while (tienBan < 0);
            Console.WriteLine("\nSo tien hoa hong nhan duoc: " + tinhTienHoaHong(tienBan));
        }
    }
}