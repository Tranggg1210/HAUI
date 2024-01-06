namespace Phieu2_Bai2
{
    internal class Program
    {
        private delegate void KetQuaHocTap(double diemTB);
        static void Main(string[] args)
        {
            string hoTen;
            double diemTb;
            Console.Write("\nNhap ho ten sinh vien: ");
            hoTen = Console.ReadLine();
            Console.Write("\nDiem trung binh: ");
            diemTb = double.Parse(Console.ReadLine());
            KetQuaHocTap multicast = xeplLoaiHocLuc;
            multicast += TinhKQHocTap;
            multicast(diemTb);

        }
        private static void TinhKQHocTap(double diemTB)
        {
            if (diemTB < 4.0)
                Console.WriteLine("\nDiem: F");
            else if (diemTB >= 4.0 && diemTB < 5.5)
                Console.WriteLine("\nDiem: D");
            else if (diemTB >= 5.5 && diemTB < 7.0)
                Console.WriteLine("\nDiem: C");
            else if (diemTB >= 7.0 && diemTB < 8.5)
                Console.WriteLine("\nDiem: B");
            else
                Console.WriteLine("\nDiem: A");
        }
        private static void xeplLoaiHocLuc(double diemTB)
        {
            if (diemTB < 3.5)
                Console.WriteLine("\nXep loai: Kem");
            else if (diemTB >= 3.5 && diemTB < 5)
                Console.WriteLine("\nXep loai: Yeu");
            else if (diemTB >= 5 && diemTB < 6.5)
                Console.WriteLine("\nxep loai: Trung binh");
            else if (diemTB >= 6.5 && diemTB < 8)
                Console.WriteLine("\nXep loai: Kha");
            else
                Console.WriteLine("\nXep loai: Gioi");
        }
    }
}