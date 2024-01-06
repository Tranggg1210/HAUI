using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phieu2_Bai2
{
    internal class SinhVien
    {
        public string MaSV { get; set; }
        public string HoTen { get; set; }

        public SinhVien()
        {
            
        }

        public SinhVien(string maSv, string hoTen)
        {
            this.MaSV = maSv;
            this.HoTen = hoTen;
        }

        // nhap
        public void nhap()
        {
            Console.Write("\tMa sv: ");
            MaSV = Console.ReadLine();
            Console.Write("\tHo Ten: ");
            HoTen = Console.ReadLine();
        }

        // xuat
        public void xuat()
        {
            Console.Write("\n{0,-15} {1,-15}", MaSV, HoTen);
        }
    }
}
