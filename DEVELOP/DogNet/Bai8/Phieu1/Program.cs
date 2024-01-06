namespace Phieu1
{
    internal class Program
    {
        private delegate void HienThiThongBao(string thongBao);
        static void Main(string[] args)
        {
            HienThiThongBao del1 = ThongBaoLoi;
            del1("thieu;");
            HienThiThongBao del2 = GuiThongDiep;
            HienThiThongBao multiDel = del1 + del2;
            HienThiThongBao del3 = CanhBao;
            multiDel += del3;
            multiDel += CanhBao;
            multiDel += CanhBao;
            multiDel -= del2;
            multiDel("ABC");
            Console.WriteLine("\nSU DUNG FUNC");
            Func<int, int, int> del4 = Cong2So;
            Console.WriteLine("\n{0} + {1} = {2}", 3, 5, del4(3, 5));
            Console.WriteLine("\nSU DUNG ACTION");
            Action<double> del5 = XepLoaiHocSinh;
            del5(7.5);
            Console.WriteLine("\nSu dung FUNC va PHUONG THUC VO DANH");
            Func<int, int, int> del8 = delegate (int x, int y) { return x + y; };
            Console.WriteLine("\n{0} + {1} = {2}", 2, 4, del8(2, 4));
            Console.WriteLine("\nSu dung ACTION va BIEU THUC LAMBDA");
            Action<double> del9 = (double diemTB) =>
            {
                if (diemTB >= 8)
                    Console.WriteLine("\nHoc sinh dat loai: Gioi");
                else if (diemTB >= 6.5)
                    Console.WriteLine("\nHoc sinh dat loai: Kha");
                else if (diemTB >= 5)
                    Console.WriteLine("\nHoc sinh dat loai: Trung binh");
                else if (diemTB >= 3.5)
                    Console.WriteLine("\nHoc sinh dat loai: Yeu");
                else Console.WriteLine("\nHoc sinh dat loai: Kem");
            };
            del9(10);

        }
        private static void ThongBaoLoi(string loi)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("\nChuong trinh cua ban co loi bien dich sau: {0}", loi);
            Console.ResetColor();
        }
        private static void GuiThongDiep(string thongDiep)
        {
            Console.WriteLine("\nThong diep da duoc gui cho: {0}", thongDiep);
        }
        private static void CanhBao(string canhBao)
        {
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("\nBan nen dung phien ban {0}", canhBao);
            Console.ResetColor();
        }
        private static int Cong2So(int a, int b)
        {
            return a + b;
        }
        static void XepLoaiHocSinh(double diemTB)
        {
            if (diemTB >= 8)
                Console.WriteLine("\nHoc sinh dat loai: Gioi");
            else if (diemTB >= 6.5)
                Console.WriteLine("\nHoc sinh dat loai: Kha");
            else if (diemTB >= 5)
                Console.WriteLine("\nHoc sinh dat loai: Trung binh");
            else if (diemTB >= 3.5)
                Console.WriteLine("\nHoc sinh dat loai: Yeu");
            else Console.WriteLine("\nHoc sinh dat loai: Kem");
        }
    }
}