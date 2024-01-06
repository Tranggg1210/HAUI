using System;

namespace Cautruc
{
    class Program
    {
        struct HS
        {
            private string HoTen;
            private int Tuoi;
            private bool GioiTinh;

            public void input()
            {
                Console.Write("\tHo ten: ");
                this.HoTen = Console.ReadLine();
                Console.Write("\tTuoi: ");
                this.Tuoi = int.Parse(Console.ReadLine());
                Console.Write("\tGioi tinh (Luu y true la nam va false la nu): ");
                this.GioiTinh = bool.Parse(Console.ReadLine());
            }

            public void output() {
                string gt;
                if (this.GioiTinh) gt = "Nam";
                else gt = "Nu";
                Console.WriteLine("\n{0,-30} {1,-10} {2, -10}", this.HoTen, this.Tuoi, gt);
            }
            public int getTuoi() { 
                return this.Tuoi;
            }
        }
        static void Main(string[] args)
        {
            int n;
            do
            {
                Console.Write("Nhap so luong hoc sinh n > 0: ");
                n = int.Parse(Console.ReadLine());
            } while (n < 1);
            HS[] h = new HS[n];
            for (int i = 0; i < h.Length; i++)
            {
                h[i] = new HS();
            }
            for (int i = 0;i < h.Length;i++)
            {
                Console.WriteLine("\n>>> Nhap thong tin sinh vien thu {0} <<<", i);
                h[i].input();
            }
            int sum = 0;
            Console.WriteLine("\nBANG THONG TIN HOC SINH");
            Console.WriteLine("\n{0,-30} {1,-10} {2, -10}", "Ho va Ten", "Tuoi", "Gioi Tinh");
            for (int i = 0; i < n; i++)
            {
                h[i].output();
                sum += h[i].getTuoi();
            }
            Console.WriteLine("\n{0} {1,5}", "Tong so tuoi cua hoc sinh: ", sum);
        }
    }
}

