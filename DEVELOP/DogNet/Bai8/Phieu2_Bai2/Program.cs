namespace Phieu2_Bai2
{
    internal class Program
    {
        private delegate void inout(List<SinhVien> list);
        static void Main(string[] args)
        {
            List<SinhVien> li = new List<SinhVien>();
            inout kq = nhapDS;
            kq += xuatDS;
            kq(li);
        }
        private static void nhapDS(List<SinhVien> list)
        {
            int n;
            do
            {
                Console.Write("\nNhap so luong sinh vien: ");
                n = int.Parse(Console.ReadLine());
            }while (n <= 0);
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine("\n===== NHAP THONG TIN SINH VIEN THU " + (i+1) + " =====");
                SinhVien a = new SinhVien();
                a.nhap();
                list.Add(a);
            }
        }
        private static void xuatDS(List<SinhVien> list)
        {
            if(list.Count > 0)
            {
                Console.WriteLine("\n===== DANH SACH SINH VIEN =====");
                Console.Write("{0,-15} {1,-15}", "Ma SV", "Ho ten");
                foreach (var item in list)
                {
                    item.xuat();
                }
            }else Console.WriteLine("\n===> Danh sach rong!!!");
        }
    }
}